#pragma once

#include <ntddk.h>
#include <WinDef.h>

extern DWORD g_dwNtoskrnlImageBase;
extern DWORD g_dwNtoskrnlImageSize;

//////////////////////////////////////////////////////////////////////////
// GetModuleInfo
// lpModuleName        [IN OPTION]: ģ����, ΪNULLʱΪntoskrnl.exe
// pulImageBaseAddress [OUT]:       ģ���ַ
// pulImageSize        [OUT]:       ģ���С
// Return:                          �Ƿ��ȡģ����Ϣ�ɹ�
BOOL GetModuleInfo(char* lpModuleName, ULONG* pulImageBaseAddress, ULONG* pulImageSize);

//////////////////////////////////////////////////////////////////////////
// EATHook
// ulImageBase      [IN]:        �����ַ
// lpastrExportName [IN]:        ������
// ulHookFunc       [IN OPTION]: �����ַ
// pulOrgFuncRVA    [OUT]:       ��������Ե�ַ
// Return:                       ���������Ե�ַ
ULONG EATHook(ULONG ulImageBase, ANSI_STRING* lpastrExportName, ULONG ulHookFunc, ULONG* pulOrgFuncRVA);

//////////////////////////////////////////////////////////////////////////
// GetNtoskrnlExportNameAddress
// pastrExportName [IN]:  ������
// pdwRVA          [OUT]: ��������Ե�ַ
// Return:                ���������Ե�ַ
DWORD GetNtoskrnlExportNameAddress(ANSI_STRING* pastrExportName, DWORD* pdwRVA);
