// dllmain.cpp : Defines the entry point for the DLL application.
//By Eternal Yoshi with thanks to Gneiss, anotak, & n3.
#include "pch.h"
#include "utils\addr.h"
#include "utils/MemoryMgr.h"
#include "utils/Trampoline.h"
#include "utils/Patterns.h"
#include <commdlg.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include "utils/umvc3utils.h"

using namespace Memory::VP;

#define longlong  long long
#define ulonglong  unsigned long long
#define undefined8  long long*
#define undefined7  long long
#define undefined2  int
typedef unsigned __int64 QWORD;
typedef int(*code)(longlong* param_1);
typedef int(*codenoarg)();
typedef void(*method)(void);
#define undefined int
#define undefined4 int
#define CONCAT71(a,b) (a<<32 | b)
#define backupsize 10000//100000
#define prebackup 0 //100000
HANDLE hProcess = 0;
uintptr_t moduleBase = 0x140000000;
uint64_t FUN_14027D483 = 0x14027D483;
uint64_t FUN_14027D534 = 0x14027D534;
uint64_t FUN_14027D548 = 0x14027D548;
uint64_t FUN_14027D528 = 0x14027D528;
uint64_t FUN_14027D520 = 0x14027D520;
uint64_t FUN_140004A30 = 0x140004A30;
uint64_t GetsGameUI = 0x140001AC0;
uint64_t LoadMainMenuResources = 0x1402BDD60;
uint64_t getsPad = 0x140001B00;
uint64_t GetCharacterValue = 0x140004AD0;
//uint64_t FUN_1402C0B00 = 0x1402C0B00;
uint64_t FUN_140226670 = 0x140226670;
uint64_t FUN_1402796F0 = 0x1402796F0;
uint64_t FUN_140222AC0 = 0x140222AC0;
uint64_t FUN_1404D7C60 = 0x1404D7C60;
uint64_t FUN_14027CFB0 = 0x14027CFB0;
uint64_t FUN_14027C9E0 = 0x14027C9E0;
uint64_t FUN_14027CB80 = 0x14027CB80;
uint64_t FUN_14027CF90 = 0x14027CF90;
uint64_t FUN_14050EE60 = 0x14050EE60;
uint64_t FUN_14050EE40 = 0x14050EE40;
//uint64_t FUN_1402D46B0 = 0x1402D46B0;
uint64_t GetsMvC3Manager = 0x140001AF0;
uint64_t FUN_140204070 = 0x140204070;
uint64_t FUN_1402D3420 = 0x1402D3420;
uint64_t FUN_14000BC10 = 0x14000BC10;
uint64_t FUN_140001B50 = 0x140001B50;
uint64_t FUN_14000BFD0 = 0x14000BFD0;
uint64_t FUN_14000BF40 = 0x14000BF40;
uint64_t FUN_1402C2980 = 0x1402C2980;
uint64_t FUN_1402D3680 = 0x1402D3680;
uint64_t FUN_1402B9BB0 = 0x1402B9BB0;
uint64_t FUN_1402CE750 = 0x1402CE750;
uint64_t FUN_1402C2620 = 0x1402C2620;
uint64_t FUN_14020CBA0 = 0x14020CBA0;
uint64_t FUN_1402D63E0 = 0x1402D63E0;
uint64_t FUN_14024CDB0 = 0x14024CDB0;
uint64_t Three_atexit = 0x1409A1564;
uint64_t FUN_1402D4970 = 0x1402D4970;
uint64_t FUN_1402D3810 = 0x1402D3810;
uint64_t FUN_1400542A0 = 0x1400542A0;
uint64_t FUN_1402D4120 = 0x1402D4120;
uint64_t FUN_14001DA70 = 0x14001DA70;
uint64_t FUN_1402D5A20 = 0x1402D5A20;
uint64_t FUN_1402D6340 = 0x1402D6340;
uint64_t FUN_140A51F70 = 0x140A51F70;
uint64_t FUN_140251C00 = 0x140251C00;
uint64_t FUN_1403F6C90 = 0x1403F6C90;
uint64_t FUN_1402D3980 = 0x1402D3980;
uint64_t FUN_14050F550 = 0x14050F550;
uint64_t FUN_140003160 = 0x140003160;
uint64_t FUN_14051A6B0 = 0x14051A6B0;
uint64_t LoadGlobalAsset = 0x14025AD30;
uint64_t FUN_140001AE0 = 0x140001AE0;
uint64_t FUN_140006AB0 = 0x140006AB0;
uint64_t get_sAgentSession = 0x1400046E0;
uint64_t GetsGameConfig = 0x140001AB0;
uint64_t ThreeMemset = 0x1409A16C0;
uint64_t DWORD_140B16ED0 = 0x140B16ED0;
uint64_t DWORD_140A6A420 = 0x140A6A420;
uint64_t DWORD_140A6E5C8 = 0x140A6E5C8;
uint64_t DWORD_140A6A42C = 0x140A6A42C;
uint64_t FUN_14050D5A0 = 0x14050D5A0;
uint64_t DWORD_140CB88A8 = 0x140CB88A8;
uint64_t DWORD_140CB88B4 = 0x140CB88B4;
uint64_t qword_140E17830 = 0x140E17830;
uint64_t qword_140B04190 = 0x140B04190;
uint64_t FUN_140001B40 = 0x140001B40;
uint64_t uUiAnmSprite_TypeInfo = 0x140D53CF8;
uint64_t uUiAnmSpriteFont_TypeInfo = 0x140D53D88;
uint64_t OriginalCharacterListArray = 0x140B148F0;
uint64_t rScheduler_Thing = 0x140e17830;
uint64_t NameAV = 0x140B17270;
uint64_t NameAW = 0x140B17280;
uint64_t NameAX = 0x140B17290;
uint64_t NameAY = 0x140B172A8;
uint64_t aPageKeyL1 = 0x140B172C0;
uint64_t aPageKeyR1 = 0x140B172D0;
uint64_t aModename = 0x140B172E0;
uint64_t uBattleUiCommandList_vftable = 0x140B16DE0;
uint64_t uBattleUiCommandList_TypeInfo = 0x140A1BAA0;
uint64_t FUN_140004530 = 0x140004530;
uint64_t FUN_1402D4760 = 0x1402D4760;
uint64_t FUN_1400047C0 = 0x1400047C0;
uint64_t FUN_14050F3C0 = 0x14050F3C0;
uint64_t uMenuSubBase_GetFields = 0x1403F6EC0;
uint64_t aMrno1 = 0x140B16EE8;
uint64_t MtProperty__createU32 = 0x14000BB50;
uint64_t FUN_14000BF60 = 0x14000BF60;
uint64_t aMbnaruhodo = 0x140B16EF0;
uint64_t MtProperty__createBool = 0x140010A20;
uint64_t aMpagenaruhodo = 0x140B16F00;
uint64_t MtProperty__createS32 = 0x14000BB10;
uint64_t aMindexnaruhodo = 0x140B16F10;
uint64_t MtObject__isEnableInstance = 0x14014D5D0;

uint64_t GUI_AllocMemoryForObject_Offset = 0x14050d720;

uint64_t GetUIContext_Offset = 0x140001B10;

uint64_t GUI_CreateObjectInstance_Offset = 0x14050D5F0;

uint64_t GUIInstance_AttachResource_Offset = 0x14050F3C0;

uint64_t FUN_14050f550_Offset = 0x14050f550;

uint64_t UI_AddChildToScene_Offset = 0x14051A6B0;

uint64_t GetSomeGlobalPointer_Offset = 0x140003160;

//Resource_ReleaseRef
uint64_t Resource_ReleaseRef_Offset = 0x14050D5A0;

//Widget_IsValidState
uint64_t CheckWidgetValidity = 0x140001B80;

//FUN_1401f8a70
uint64_t FUN_1401f8a70_Offset = 0x1401f8a70;

//FUN_14050ED20
uint64_t FUN_14050ED20_Offset = 0x14050ED20;

//FUN_1402B3390
uint64_t FUN_1402B3390_Offset = 0x1402B3390;

//FUN_140211EA0
uint64_t FUN_140211EA0_Offset = 0x140211EA0;




//The original function whose assembly has been ported.
__attribute__((naked)) void OLD_1402177B0()//0x1402177B0
{
	_asm
	{

		mov[rsp + 0x10], rbx
		mov[rsp + 0x18], rsi
		push rdi
		sub rsp, 0x20
		mov rdi, rcx
		mov ecx, [rcx + 0x7C]
		test ecx, ecx
		je LOC_140217982
		dec ecx
		je LOC_140217828
		dec ecx
		jne LOC_140217ADB
		mov rcx, [rdi + 0x60]
		xor ebx, ebx
		test rcx, rcx
		je LOC_1402177F1
		call CheckWidgetValidity
		test al, al
		jne LOC_1402177F1
		mov[rdi + 0x60], rbx

		LOC_1402177F1 :

		mov rsi, [rdi + 0x60]
			test rsi, rsi
			je LOC_140217813
			mov rcx, rsi
			call CheckWidgetValidity
			test al, al
			je LOC_140217813

			mov rax, [rsi]
			mov rcx, rsi
			call qword ptr[rax + 0x78]
			mov[rdi + 0x60], rbx

			LOC_140217813 :

		mov eax, 0x00000001
			mov rbx, [rsp + 0x38]
			mov rsi, [rsp + 0x40]
			add rsp, 0x20
			pop rdi
			ret

			LOC_140217828 :

		mov rcx, [rdi + 0x60]
			test rcx, rcx
			je LOC_1402178F2
			call FUN_1401f8a70_Offset
			cmp eax, 0x02
			jbe LOC_1402178F2
			call GetsMvC3Manager
			mov edx, 0x00000001
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000002
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000006
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000008
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000009
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000A
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000B
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000C
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000D
			mov rcx, rax
			call LoadMainMenuResources

			LOC_1402178F2 :

		mov rsi, [rdi + 0x60]
			test rsi, rsi
			je LOC_140217AD4
			mov rcx, rsi
			call FUN_1401f8a70_Offset
			mov rcx, rsi
			lea ebx, [rax + 0x02]
			call FUN_14050ED20_Offset
			cmp ebx, eax
			jae LOC_140217AD4
			mov rcx, [rdi + 0x60]
			call FUN_1401f8a70_Offset
			cmp eax, 0x0000008C
			jb LOC_140217ADB
			xor ebx, ebx


			LOC_140217930 :

		mov[rsp + 0x30], rbp
			mov esi, ebx
			call getsPad
			mov rbp, rax
			nop

			LOC_140217940 :

		mov edx, esi
			mov rcx, rbp
			call FUN_140211EA0_Offset
			inc esi
			or ebx, eax
			cmp esi, 0x04
			jb LOC_140217940
			mov dl, 0x01
			mov rcx, rbp
			call FUN_1402B3390_Offset
			mov rbp, [rsp + 0x30]
			or eax, ebx
			test eax, 0x0000F008
			jne LOC_140217AD4


			LOC__14021796F :

		or eax, 0xFFFFFFFF
			mov rbx, [rsp + 0x38]
			mov rsi, [rsp + 0x40]
			add rsp, 0x20
			pop rdi
			ret

			LOC_140217982 :

		call GetUIContext_Offset
			mov r8, qword_140B04190
			mov rdx, qword_140E17830
			mov r10, [rax]
			mov r9d, 0x00000001
			mov rcx, rax
			call qword ptr[r10 + 0x60]
			mov rsi, rax
			test rax, rax
			je LOC_140217A25
			mov edx, 0x00000010
			lea ecx, [rdx + 0x68]
			call GUI_AllocMemoryForObject_Offset
			test rax, rax
			je LOC_1402179CC
			mov rcx, rax
			call GUI_CreateObjectInstance_Offset
			mov rbx, rax
			jmp LOC_1402179CE

			LOC_1402179CC :

		xor ebx, ebx

			LOC_1402179CE :

		mov[rdi + 0x60], rbx
			test rbx, rbx
			je LOC_140217A03
			mov rdx, rsi
			mov rcx, rbx
			call GUIInstance_AttachResource_Offset
			mov rcx, [rdi + 0x60]
			xor edx, edx
			call FUN_14050f550_Offset
			call FUN_140003160
			mov r8, [rdi + 0x60]
			mov rcx, rax
			xor r9d, r9d
			xor edx, edx
			call FUN_14051A6B0

			LOC_140217A03 :

		mov rcx, rsi
			call Resource_ReleaseRef_Offset
			mov dword ptr[rdi + 0x7C], 0x00000001
			or eax, 0xFFFFFFFF
			mov rbx, [rsp + 0x38]
			mov rsi, [rsp + 0x40]
			add rsp, 0x20
			pop rdi
			ret

			LOC_140217A25 :

		//Loads the Menu and Boot Arcs.
		call GetsMvC3Manager
			mov edx, 0x00000001
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000002
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000006
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000008
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x00000009
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000A
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000B
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000C
			mov rcx, rax
			call LoadGlobalAsset
			call GetsMvC3Manager
			mov edx, 0x0000000D
			mov rcx, rax
			call LoadGlobalAsset
			call GetsGameUI
			mov rcx, rax
			call LoadMainMenuResources

			LOC_140217AD4 :

		mov dword ptr[rdi + 0x7C], 0x00000002

			LOC_140217ADB :

			mov rbx, [rsp + 0x38]
			mov rsi, [rsp + 0x40]
			or eax, 0xFFFFFFFF
			add rsp, 0x20
			pop rdi
			ret




	}
}

//the modified version. Meant to get the game to load the essential boot and menu files, and cut to intro.
__attribute__((naked)) void FUN_1402177B0()//0x1402177B0
{
	_asm
	{

		mov[rsp + 0x10], rbx
		mov[rsp + 0x18], rsi
		push rdi
		sub rsp, 0x20
		mov rdi, rcx
		mov ecx, [rcx + 0x7C]
		call GetUIContext_Offset
		mov r8, qword_140B04190
		mov rdx, qword_140E17830
		mov r10, [rax]
		mov r9d, 0x00000001
		mov rcx, rax
		call qword ptr[r10 + 0x60]
		mov rsi, rax

		mov edx, 0x00000010
		lea ecx, [rdx + 0x68]
		call GUI_AllocMemoryForObject_Offset

		mov rcx, rax
		call GUI_CreateObjectInstance_Offset
		mov rbx, rax

		mov[rdi + 0x60], rbx

		mov rdx, rsi
		mov rcx, rbx
		call GUIInstance_AttachResource_Offset
		mov rcx, [rdi + 0x60]
		xor edx, edx
		call FUN_14050f550_Offset
		call FUN_140003160
		mov r8, [rdi + 0x60]
		mov rcx, rax
		xor r9d, r9d
		xor edx, edx
		call FUN_14051A6B0

		mov rcx, rsi
		call Resource_ReleaseRef_Offset
		mov dword ptr[rdi + 0x7C], 0x00000001
		or eax, 0xFFFFFFFF

		call GetsMvC3Manager
		mov edx, 0x00000001
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x00000002
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x00000006
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x00000008
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x00000009
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x0000000A
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x0000000B
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x0000000C
		mov rcx, rax
		call LoadGlobalAsset
		call GetsMvC3Manager
		mov edx, 0x0000000D
		mov rcx, rax
		call LoadMainMenuResources


		mov rbx, [rsp + 0x38]
		mov rsi, [rsp + 0x40]
		add rsp, 0x20
		pop rdi
		mov eax, 2
		ret

	}
}

//Checks the version of the game.
bool CheckGame()
{
	char* gameName = (char*)(_addr(0x140B12D10));

	if (strcmp(gameName, "umvc3") == 0)
	{
		return true;
	}
	else
	{
		MessageBoxA(0, "Sorry!\nThis only supports the most recent(or the version released from April 2017 onward) Steam Executable of Ultimate Marvel vs Capcom 3.", 0, MB_ICONINFORMATION);
		return false;
	}
}

void OnInitializeHook()
{
	Trampoline* tramp = Trampoline::MakeTrampoline(GetModuleHandle(nullptr));
	InjectHook(_addr(0x140217763), tramp->Jump(FUN_1402177B0), HookType::Call);
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		if (CheckGame())
		{
			CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)OnInitializeHook, hMod, 0, nullptr);
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

