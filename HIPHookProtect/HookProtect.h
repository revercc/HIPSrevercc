#pragma once
#include "defstruct.h"
#include "Fake_CreateProcessNotifyRoutine.h"
#include "Fake_ZwCreateFile.h"
#include "Fake_ZwDeleteFile.h"
#include "Fake_ZwDeleteKey.h"
#include "Fake_ZwDeviceIoControlFile.h"
#include "Fake_ZwOpenFile.h"
#include "Fake_ZwOpenKey.h"
#include "Fake_ZwOpenKeyEx.h"
#include "Fake_ZwOpenProcess.h"
#include "Fake_ZwReadFile.h"
#include "Fake_ZwSetInformationFile.h"
#include "Fake_ZwTerminateProcess.h"
#include "Fake_ZwWriteFile.h"
#include "Filter_CreateProcessNotifyRoutine.h"
#include "Filter_ZwCreateFile.h"
#include "Filter_ZwDeleteFile.h"
#include "Filter_ZwDeleteKey.h"
#include "Filter_ZwDeviceIoControlFile.h"
#include "Filter_ZwOpenKey.h"
#include "Filter_ZwOpenKeyEx.h"
#include "Filter_ZwOpenProcess.h"
#include "Filter_ZwOpenFile.h"
#include "Filter_ZwReadFile.h"
#include "Filter_ZwSetInformationFile.h"
#include "Filter_ZwTerminateProcess.h"
#include "Filter_ZwWriteFile.h"
#include "CurrencyFunc.h"
#include "Ssdt.h"
#include "WhiteRegditList.h"
#include "WhiteFileList.h"
#include "WhiteProcessList.h"
#include "Command.h"

PDEVICE_OBJECT Global_HookProtectDeviceObject;


#define	HookProtect_DeviceName	L"\\Device\\HIPHookProtect"
#define	HookProtect_LinkName		L"\\DosDevices\\HIPHookProtect"