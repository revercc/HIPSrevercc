#include "Filter_ZwReadFile.h"

NTSTATUS NTAPI Filter_ZwReadFile(
	IN HANDLE           FileHandle,
	IN HANDLE           Event OPTIONAL,
	IN PIO_APC_ROUTINE  ApcRoutine OPTIONAL,
	IN PVOID            ApcContext OPTIONAL,
	OUT        PIO_STATUS_BLOCK IoStatusBlock,
	OUT          PVOID            Buffer,
	IN           ULONG            Length,
	IN PLARGE_INTEGER   ByteOffset OPTIONAL,
	IN PULONG           Key OPTIONAL)
{
	NTSTATUS Result, OutResult;

	PULONG   FuncTable[16] = { 0 };
	PULONG   ArgTable[16] = { 0 };
	ULONG    RetNumber = NULL;
	PVOID    pArgArray = &FileHandle;//参数数组，指向栈中属于本函数的所有参数

	NTSTATUS(NTAPI * ZwReadFilePtr)(HANDLE, HANDLE, PIO_APC_ROUTINE, PVOID, PIO_STATUS_BLOCK, PVOID, ULONG, PLARGE_INTEGER, PULONG);
	//原始函数执行前检查
	Result = HookProtect_DoFake(ZwReadFile_FilterIndex, pArgArray, FuncTable, ArgTable, &RetNumber, &OutResult);
	if (Result)
	{
		//获取原始函数地址
		ZwReadFilePtr = g_FilterFun_table->OldFunc[ZwReadFile_FilterIndex];

		//调用原始函数
		Result = ZwReadFilePtr(FileHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, Buffer, Length, ByteOffset, Key);
		if (NT_SUCCESS(Result))
		{
			//原始函数执行后检查
			Result = HookPort_ForRunFuncTable(ZwReadFile_FilterIndex, pArgArray, Result, FuncTable, ArgTable, RetNumber);
		}
	}
	else
	{
		Result = OutResult;
	}
	return Result;

}