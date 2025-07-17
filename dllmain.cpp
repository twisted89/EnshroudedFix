#include <Windows.h>
#include "MinHook.h"
#include <iostream>
#include <chrono>

using namespace std::literals;

#pragma region proxy
#ifdef _WIN64
#define DLLPATH "\\\\.\\GLOBALROOT\\SystemRoot\\System32\\dbghelp.dll"
#else
#define DLLPATH "\\\\.\\GLOBALROOT\\SystemRoot\\SysWOW64\\dbghelp.dll"
#endif // _WIN64

#pragma comment(linker, "/EXPORT:DbgHelpCreateUserDump=" DLLPATH ".DbgHelpCreateUserDump")
#pragma comment(linker, "/EXPORT:DbgHelpCreateUserDumpW=" DLLPATH ".DbgHelpCreateUserDumpW")
#pragma comment(linker, "/EXPORT:EnumDirTree=" DLLPATH ".EnumDirTree")
#pragma comment(linker, "/EXPORT:EnumDirTreeW=" DLLPATH ".EnumDirTreeW")
#pragma comment(linker, "/EXPORT:EnumerateLoadedModules=" DLLPATH ".EnumerateLoadedModules")
#pragma comment(linker, "/EXPORT:EnumerateLoadedModules64=" DLLPATH ".EnumerateLoadedModules64")
#pragma comment(linker, "/EXPORT:EnumerateLoadedModulesEx=" DLLPATH ".EnumerateLoadedModulesEx")
#pragma comment(linker, "/EXPORT:EnumerateLoadedModulesExW=" DLLPATH ".EnumerateLoadedModulesExW")
#pragma comment(linker, "/EXPORT:EnumerateLoadedModulesW64=" DLLPATH ".EnumerateLoadedModulesW64")
#pragma comment(linker, "/EXPORT:ExtensionApiVersion=" DLLPATH ".ExtensionApiVersion")
#pragma comment(linker, "/EXPORT:FindDebugInfoFile=" DLLPATH ".FindDebugInfoFile")
#pragma comment(linker, "/EXPORT:FindDebugInfoFileEx=" DLLPATH ".FindDebugInfoFileEx")
#pragma comment(linker, "/EXPORT:FindDebugInfoFileExW=" DLLPATH ".FindDebugInfoFileExW")
#pragma comment(linker, "/EXPORT:FindExecutableImage=" DLLPATH ".FindExecutableImage")
#pragma comment(linker, "/EXPORT:FindExecutableImageEx=" DLLPATH ".FindExecutableImageEx")
#pragma comment(linker, "/EXPORT:FindExecutableImageExW=" DLLPATH ".FindExecutableImageExW")
#pragma comment(linker, "/EXPORT:FindFileInPath=" DLLPATH ".FindFileInPath")
#pragma comment(linker, "/EXPORT:FindFileInSearchPath=" DLLPATH ".FindFileInSearchPath")
#pragma comment(linker, "/EXPORT:GetSymLoadError=" DLLPATH ".GetSymLoadError")
#pragma comment(linker, "/EXPORT:GetTimestampForLoadedLibrary=" DLLPATH ".GetTimestampForLoadedLibrary")
#pragma comment(linker, "/EXPORT:ImageDirectoryEntryToData=" DLLPATH ".ImageDirectoryEntryToData")
#pragma comment(linker, "/EXPORT:ImageDirectoryEntryToDataEx=" DLLPATH ".ImageDirectoryEntryToDataEx")
#pragma comment(linker, "/EXPORT:ImageNtHeader=" DLLPATH ".ImageNtHeader")
#pragma comment(linker, "/EXPORT:ImageRvaToSection=" DLLPATH ".ImageRvaToSection")
#pragma comment(linker, "/EXPORT:ImageRvaToVa=" DLLPATH ".ImageRvaToVa")
#pragma comment(linker, "/EXPORT:ImagehlpApiVersion=" DLLPATH ".ImagehlpApiVersion")
#pragma comment(linker, "/EXPORT:ImagehlpApiVersionEx=" DLLPATH ".ImagehlpApiVersionEx")
#pragma comment(linker, "/EXPORT:MakeSureDirectoryPathExists=" DLLPATH ".MakeSureDirectoryPathExists")
#pragma comment(linker, "/EXPORT:MiniDumpReadDumpStream=" DLLPATH ".MiniDumpReadDumpStream")
#pragma comment(linker, "/EXPORT:MiniDumpWriteDump=" DLLPATH ".MiniDumpWriteDump")
#pragma comment(linker, "/EXPORT:RangeMapAddPeImageSections=" DLLPATH ".RangeMapAddPeImageSections")
#pragma comment(linker, "/EXPORT:RangeMapCreate=" DLLPATH ".RangeMapCreate")
#pragma comment(linker, "/EXPORT:RangeMapFree=" DLLPATH ".RangeMapFree")
#pragma comment(linker, "/EXPORT:RangeMapRead=" DLLPATH ".RangeMapRead")
#pragma comment(linker, "/EXPORT:RangeMapRemove=" DLLPATH ".RangeMapRemove")
#pragma comment(linker, "/EXPORT:RangeMapWrite=" DLLPATH ".RangeMapWrite")
#pragma comment(linker, "/EXPORT:RemoveInvalidModuleList=" DLLPATH ".RemoveInvalidModuleList")
#pragma comment(linker, "/EXPORT:ReportSymbolLoadSummary=" DLLPATH ".ReportSymbolLoadSummary")
#pragma comment(linker, "/EXPORT:SearchTreeForFile=" DLLPATH ".SearchTreeForFile")
#pragma comment(linker, "/EXPORT:SearchTreeForFileW=" DLLPATH ".SearchTreeForFileW")
#pragma comment(linker, "/EXPORT:SetCheckUserInterruptShared=" DLLPATH ".SetCheckUserInterruptShared")
#pragma comment(linker, "/EXPORT:SetSymLoadError=" DLLPATH ".SetSymLoadError")
#pragma comment(linker, "/EXPORT:StackWalk=" DLLPATH ".StackWalk")
#pragma comment(linker, "/EXPORT:StackWalk2=" DLLPATH ".StackWalk2")
#pragma comment(linker, "/EXPORT:StackWalk64=" DLLPATH ".StackWalk64")
#pragma comment(linker, "/EXPORT:StackWalkEx=" DLLPATH ".StackWalkEx")
#pragma comment(linker, "/EXPORT:SymAddSourceStream=" DLLPATH ".SymAddSourceStream")
#pragma comment(linker, "/EXPORT:SymAddSourceStreamA=" DLLPATH ".SymAddSourceStreamA")
#pragma comment(linker, "/EXPORT:SymAddSourceStreamW=" DLLPATH ".SymAddSourceStreamW")
#pragma comment(linker, "/EXPORT:SymAddSymbol=" DLLPATH ".SymAddSymbol")
#pragma comment(linker, "/EXPORT:SymAddSymbolW=" DLLPATH ".SymAddSymbolW")
#pragma comment(linker, "/EXPORT:SymAddrIncludeInlineTrace=" DLLPATH ".SymAddrIncludeInlineTrace")
#pragma comment(linker, "/EXPORT:SymAllocDiaString=" DLLPATH ".SymAllocDiaString")
#pragma comment(linker, "/EXPORT:SymCleanup=" DLLPATH ".SymCleanup")
#pragma comment(linker, "/EXPORT:SymCompareInlineTrace=" DLLPATH ".SymCompareInlineTrace")
#pragma comment(linker, "/EXPORT:SymDeleteSymbol=" DLLPATH ".SymDeleteSymbol")
#pragma comment(linker, "/EXPORT:SymDeleteSymbolW=" DLLPATH ".SymDeleteSymbolW")
#pragma comment(linker, "/EXPORT:SymEnumLines=" DLLPATH ".SymEnumLines")
#pragma comment(linker, "/EXPORT:SymEnumLinesW=" DLLPATH ".SymEnumLinesW")
#pragma comment(linker, "/EXPORT:SymEnumProcesses=" DLLPATH ".SymEnumProcesses")
#pragma comment(linker, "/EXPORT:SymEnumSourceFileTokens=" DLLPATH ".SymEnumSourceFileTokens")
#pragma comment(linker, "/EXPORT:SymEnumSourceFiles=" DLLPATH ".SymEnumSourceFiles")
#pragma comment(linker, "/EXPORT:SymEnumSourceFilesW=" DLLPATH ".SymEnumSourceFilesW")
#pragma comment(linker, "/EXPORT:SymEnumSourceLines=" DLLPATH ".SymEnumSourceLines")
#pragma comment(linker, "/EXPORT:SymEnumSourceLinesW=" DLLPATH ".SymEnumSourceLinesW")
#pragma comment(linker, "/EXPORT:SymEnumSym=" DLLPATH ".SymEnumSym")
#pragma comment(linker, "/EXPORT:SymEnumSymbols=" DLLPATH ".SymEnumSymbols")
#pragma comment(linker, "/EXPORT:SymEnumSymbolsEx=" DLLPATH ".SymEnumSymbolsEx")
#pragma comment(linker, "/EXPORT:SymEnumSymbolsExW=" DLLPATH ".SymEnumSymbolsExW")
#pragma comment(linker, "/EXPORT:SymEnumSymbolsForAddr=" DLLPATH ".SymEnumSymbolsForAddr")
#pragma comment(linker, "/EXPORT:SymEnumSymbolsForAddrW=" DLLPATH ".SymEnumSymbolsForAddrW")
#pragma comment(linker, "/EXPORT:SymEnumSymbolsW=" DLLPATH ".SymEnumSymbolsW")
#pragma comment(linker, "/EXPORT:SymEnumTypes=" DLLPATH ".SymEnumTypes")
#pragma comment(linker, "/EXPORT:SymEnumTypesByName=" DLLPATH ".SymEnumTypesByName")
#pragma comment(linker, "/EXPORT:SymEnumTypesByNameW=" DLLPATH ".SymEnumTypesByNameW")
#pragma comment(linker, "/EXPORT:SymEnumTypesW=" DLLPATH ".SymEnumTypesW")
#pragma comment(linker, "/EXPORT:SymEnumerateModules=" DLLPATH ".SymEnumerateModules")
#pragma comment(linker, "/EXPORT:SymEnumerateModules64=" DLLPATH ".SymEnumerateModules64")
#pragma comment(linker, "/EXPORT:SymEnumerateModulesW64=" DLLPATH ".SymEnumerateModulesW64")
#pragma comment(linker, "/EXPORT:SymEnumerateSymbols=" DLLPATH ".SymEnumerateSymbols")
#pragma comment(linker, "/EXPORT:SymEnumerateSymbols64=" DLLPATH ".SymEnumerateSymbols64")
#pragma comment(linker, "/EXPORT:SymEnumerateSymbolsW=" DLLPATH ".SymEnumerateSymbolsW")
#pragma comment(linker, "/EXPORT:SymEnumerateSymbolsW64=" DLLPATH ".SymEnumerateSymbolsW64")
#pragma comment(linker, "/EXPORT:SymFindDebugInfoFile=" DLLPATH ".SymFindDebugInfoFile")
#pragma comment(linker, "/EXPORT:SymFindDebugInfoFileW=" DLLPATH ".SymFindDebugInfoFileW")
#pragma comment(linker, "/EXPORT:SymFindExecutableImage=" DLLPATH ".SymFindExecutableImage")
#pragma comment(linker, "/EXPORT:SymFindExecutableImageW=" DLLPATH ".SymFindExecutableImageW")
#pragma comment(linker, "/EXPORT:SymFindFileInPath=" DLLPATH ".SymFindFileInPath")
#pragma comment(linker, "/EXPORT:SymFindFileInPathW=" DLLPATH ".SymFindFileInPathW")
#pragma comment(linker, "/EXPORT:SymFreeDiaString=" DLLPATH ".SymFreeDiaString")
#pragma comment(linker, "/EXPORT:SymFromAddr=" DLLPATH ".SymFromAddr")
#pragma comment(linker, "/EXPORT:SymFromAddrW=" DLLPATH ".SymFromAddrW")
#pragma comment(linker, "/EXPORT:SymFromIndex=" DLLPATH ".SymFromIndex")
#pragma comment(linker, "/EXPORT:SymFromIndexW=" DLLPATH ".SymFromIndexW")
#pragma comment(linker, "/EXPORT:SymFromInlineContext=" DLLPATH ".SymFromInlineContext")
#pragma comment(linker, "/EXPORT:SymFromInlineContextW=" DLLPATH ".SymFromInlineContextW")
#pragma comment(linker, "/EXPORT:SymFromName=" DLLPATH ".SymFromName")
#pragma comment(linker, "/EXPORT:SymFromNameW=" DLLPATH ".SymFromNameW")
#pragma comment(linker, "/EXPORT:SymFromToken=" DLLPATH ".SymFromToken")
#pragma comment(linker, "/EXPORT:SymFromTokenW=" DLLPATH ".SymFromTokenW")
#pragma comment(linker, "/EXPORT:SymFunctionTableAccess=" DLLPATH ".SymFunctionTableAccess")
#pragma comment(linker, "/EXPORT:SymFunctionTableAccess64=" DLLPATH ".SymFunctionTableAccess64")
#pragma comment(linker, "/EXPORT:SymFunctionTableAccess64AccessRoutines=" DLLPATH ".SymFunctionTableAccess64AccessRoutines")
#pragma comment(linker, "/EXPORT:SymGetDiaSession=" DLLPATH ".SymGetDiaSession")
#pragma comment(linker, "/EXPORT:SymGetDiaSource=" DLLPATH ".SymGetDiaSource")
#pragma comment(linker, "/EXPORT:SymGetExtendedOption=" DLLPATH ".SymGetExtendedOption")
#pragma comment(linker, "/EXPORT:SymGetFileLineOffsets64=" DLLPATH ".SymGetFileLineOffsets64")
#pragma comment(linker, "/EXPORT:SymGetHomeDirectory=" DLLPATH ".SymGetHomeDirectory")
#pragma comment(linker, "/EXPORT:SymGetHomeDirectoryW=" DLLPATH ".SymGetHomeDirectoryW")
#pragma comment(linker, "/EXPORT:SymGetLineFromAddr=" DLLPATH ".SymGetLineFromAddr")
#pragma comment(linker, "/EXPORT:SymGetLineFromAddr64=" DLLPATH ".SymGetLineFromAddr64")
#pragma comment(linker, "/EXPORT:SymGetLineFromAddrEx=" DLLPATH ".SymGetLineFromAddrEx")
#pragma comment(linker, "/EXPORT:SymGetLineFromAddrW64=" DLLPATH ".SymGetLineFromAddrW64")
#pragma comment(linker, "/EXPORT:SymGetLineFromInlineContext=" DLLPATH ".SymGetLineFromInlineContext")
#pragma comment(linker, "/EXPORT:SymGetLineFromInlineContextW=" DLLPATH ".SymGetLineFromInlineContextW")
#pragma comment(linker, "/EXPORT:SymGetLineFromName=" DLLPATH ".SymGetLineFromName")
#pragma comment(linker, "/EXPORT:SymGetLineFromName64=" DLLPATH ".SymGetLineFromName64")
#pragma comment(linker, "/EXPORT:SymGetLineFromNameEx=" DLLPATH ".SymGetLineFromNameEx")
#pragma comment(linker, "/EXPORT:SymGetLineFromNameW64=" DLLPATH ".SymGetLineFromNameW64")
#pragma comment(linker, "/EXPORT:SymGetLineNext=" DLLPATH ".SymGetLineNext")
#pragma comment(linker, "/EXPORT:SymGetLineNext64=" DLLPATH ".SymGetLineNext64")
#pragma comment(linker, "/EXPORT:SymGetLineNextEx=" DLLPATH ".SymGetLineNextEx")
#pragma comment(linker, "/EXPORT:SymGetLineNextW64=" DLLPATH ".SymGetLineNextW64")
#pragma comment(linker, "/EXPORT:SymGetLinePrev=" DLLPATH ".SymGetLinePrev")
#pragma comment(linker, "/EXPORT:SymGetLinePrev64=" DLLPATH ".SymGetLinePrev64")
#pragma comment(linker, "/EXPORT:SymGetLinePrevEx=" DLLPATH ".SymGetLinePrevEx")
#pragma comment(linker, "/EXPORT:SymGetLinePrevW64=" DLLPATH ".SymGetLinePrevW64")
#pragma comment(linker, "/EXPORT:SymGetModuleBase=" DLLPATH ".SymGetModuleBase")
#pragma comment(linker, "/EXPORT:SymGetModuleBase64=" DLLPATH ".SymGetModuleBase64")
#pragma comment(linker, "/EXPORT:SymGetModuleInfo=" DLLPATH ".SymGetModuleInfo")
#pragma comment(linker, "/EXPORT:SymGetModuleInfo64=" DLLPATH ".SymGetModuleInfo64")
#pragma comment(linker, "/EXPORT:SymGetModuleInfoW=" DLLPATH ".SymGetModuleInfoW")
#pragma comment(linker, "/EXPORT:SymGetModuleInfoW64=" DLLPATH ".SymGetModuleInfoW64")
#pragma comment(linker, "/EXPORT:SymGetOmapBlockBase=" DLLPATH ".SymGetOmapBlockBase")
#pragma comment(linker, "/EXPORT:SymGetOmaps=" DLLPATH ".SymGetOmaps")
#pragma comment(linker, "/EXPORT:SymGetOptions=" DLLPATH ".SymGetOptions")
#pragma comment(linker, "/EXPORT:SymGetParentWindow=" DLLPATH ".SymGetParentWindow")
#pragma comment(linker, "/EXPORT:SymGetScope=" DLLPATH ".SymGetScope")
#pragma comment(linker, "/EXPORT:SymGetScopeW=" DLLPATH ".SymGetScopeW")
#pragma comment(linker, "/EXPORT:SymGetSearchPath=" DLLPATH ".SymGetSearchPath")
#pragma comment(linker, "/EXPORT:SymGetSearchPathW=" DLLPATH ".SymGetSearchPathW")
#pragma comment(linker, "/EXPORT:SymGetSourceFile=" DLLPATH ".SymGetSourceFile")
#pragma comment(linker, "/EXPORT:SymGetSourceFileChecksum=" DLLPATH ".SymGetSourceFileChecksum")
#pragma comment(linker, "/EXPORT:SymGetSourceFileChecksumW=" DLLPATH ".SymGetSourceFileChecksumW")
#pragma comment(linker, "/EXPORT:SymGetSourceFileFromToken=" DLLPATH ".SymGetSourceFileFromToken")
#pragma comment(linker, "/EXPORT:SymGetSourceFileFromTokenByTokenName=" DLLPATH ".SymGetSourceFileFromTokenByTokenName")
#pragma comment(linker, "/EXPORT:SymGetSourceFileFromTokenByTokenNameW=" DLLPATH ".SymGetSourceFileFromTokenByTokenNameW")
#pragma comment(linker, "/EXPORT:SymGetSourceFileFromTokenW=" DLLPATH ".SymGetSourceFileFromTokenW")
#pragma comment(linker, "/EXPORT:SymGetSourceFileToken=" DLLPATH ".SymGetSourceFileToken")
#pragma comment(linker, "/EXPORT:SymGetSourceFileTokenByTokenName=" DLLPATH ".SymGetSourceFileTokenByTokenName")
#pragma comment(linker, "/EXPORT:SymGetSourceFileTokenByTokenNameW=" DLLPATH ".SymGetSourceFileTokenByTokenNameW")
#pragma comment(linker, "/EXPORT:SymGetSourceFileTokenW=" DLLPATH ".SymGetSourceFileTokenW")
#pragma comment(linker, "/EXPORT:SymGetSourceFileW=" DLLPATH ".SymGetSourceFileW")
#pragma comment(linker, "/EXPORT:SymGetSourceVarFromToken=" DLLPATH ".SymGetSourceVarFromToken")
#pragma comment(linker, "/EXPORT:SymGetSourceVarFromTokenW=" DLLPATH ".SymGetSourceVarFromTokenW")
#pragma comment(linker, "/EXPORT:SymGetSymFromAddr=" DLLPATH ".SymGetSymFromAddr")
#pragma comment(linker, "/EXPORT:SymGetSymFromAddr64=" DLLPATH ".SymGetSymFromAddr64")
#pragma comment(linker, "/EXPORT:SymGetSymFromName=" DLLPATH ".SymGetSymFromName")
#pragma comment(linker, "/EXPORT:SymGetSymFromName64=" DLLPATH ".SymGetSymFromName64")
#pragma comment(linker, "/EXPORT:SymGetSymNext=" DLLPATH ".SymGetSymNext")
#pragma comment(linker, "/EXPORT:SymGetSymNext64=" DLLPATH ".SymGetSymNext64")
#pragma comment(linker, "/EXPORT:SymGetSymPrev=" DLLPATH ".SymGetSymPrev")
#pragma comment(linker, "/EXPORT:SymGetSymPrev64=" DLLPATH ".SymGetSymPrev64")
#pragma comment(linker, "/EXPORT:SymGetSymbolFile=" DLLPATH ".SymGetSymbolFile")
#pragma comment(linker, "/EXPORT:SymGetSymbolFileW=" DLLPATH ".SymGetSymbolFileW")
#pragma comment(linker, "/EXPORT:SymGetTypeFromName=" DLLPATH ".SymGetTypeFromName")
#pragma comment(linker, "/EXPORT:SymGetTypeFromNameW=" DLLPATH ".SymGetTypeFromNameW")
#pragma comment(linker, "/EXPORT:SymGetTypeInfo=" DLLPATH ".SymGetTypeInfo")
#pragma comment(linker, "/EXPORT:SymGetTypeInfoEx=" DLLPATH ".SymGetTypeInfoEx")
#pragma comment(linker, "/EXPORT:SymGetUnwindInfo=" DLLPATH ".SymGetUnwindInfo")
#pragma comment(linker, "/EXPORT:SymInitialize=" DLLPATH ".SymInitialize")
#pragma comment(linker, "/EXPORT:SymInitializeW=" DLLPATH ".SymInitializeW")
#pragma comment(linker, "/EXPORT:SymLoadModule=" DLLPATH ".SymLoadModule")
#pragma comment(linker, "/EXPORT:SymLoadModule64=" DLLPATH ".SymLoadModule64")
#pragma comment(linker, "/EXPORT:SymLoadModuleEx=" DLLPATH ".SymLoadModuleEx")
#pragma comment(linker, "/EXPORT:SymLoadModuleExW=" DLLPATH ".SymLoadModuleExW")
#pragma comment(linker, "/EXPORT:SymMatchFileName=" DLLPATH ".SymMatchFileName")
#pragma comment(linker, "/EXPORT:SymMatchFileNameW=" DLLPATH ".SymMatchFileNameW")
#pragma comment(linker, "/EXPORT:SymMatchString=" DLLPATH ".SymMatchString")
#pragma comment(linker, "/EXPORT:SymMatchStringA=" DLLPATH ".SymMatchStringA")
#pragma comment(linker, "/EXPORT:SymMatchStringW=" DLLPATH ".SymMatchStringW")
#pragma comment(linker, "/EXPORT:SymNext=" DLLPATH ".SymNext")
#pragma comment(linker, "/EXPORT:SymNextW=" DLLPATH ".SymNextW")
#pragma comment(linker, "/EXPORT:SymPrev=" DLLPATH ".SymPrev")
#pragma comment(linker, "/EXPORT:SymPrevW=" DLLPATH ".SymPrevW")
#pragma comment(linker, "/EXPORT:SymQueryInlineTrace=" DLLPATH ".SymQueryInlineTrace")
#pragma comment(linker, "/EXPORT:SymRefreshModuleList=" DLLPATH ".SymRefreshModuleList")
#pragma comment(linker, "/EXPORT:SymRegisterCallback=" DLLPATH ".SymRegisterCallback")
#pragma comment(linker, "/EXPORT:SymRegisterCallback64=" DLLPATH ".SymRegisterCallback64")
#pragma comment(linker, "/EXPORT:SymRegisterCallbackW64=" DLLPATH ".SymRegisterCallbackW64")
#pragma comment(linker, "/EXPORT:SymRegisterFunctionEntryCallback=" DLLPATH ".SymRegisterFunctionEntryCallback")
#pragma comment(linker, "/EXPORT:SymRegisterFunctionEntryCallback64=" DLLPATH ".SymRegisterFunctionEntryCallback64")
#pragma comment(linker, "/EXPORT:SymRegisterGetSourcePathPartCallback=" DLLPATH ".SymRegisterGetSourcePathPartCallback")
#pragma comment(linker, "/EXPORT:SymRegisterSourceFileUrlListCallback=" DLLPATH ".SymRegisterSourceFileUrlListCallback")
#pragma comment(linker, "/EXPORT:SymSearch=" DLLPATH ".SymSearch")
#pragma comment(linker, "/EXPORT:SymSearchW=" DLLPATH ".SymSearchW")
#pragma comment(linker, "/EXPORT:SymSetContext=" DLLPATH ".SymSetContext")
#pragma comment(linker, "/EXPORT:SymSetDiaSession=" DLLPATH ".SymSetDiaSession")
#pragma comment(linker, "/EXPORT:SymSetExtendedOption=" DLLPATH ".SymSetExtendedOption")
#pragma comment(linker, "/EXPORT:SymSetHomeDirectory=" DLLPATH ".SymSetHomeDirectory")
#pragma comment(linker, "/EXPORT:SymSetHomeDirectoryW=" DLLPATH ".SymSetHomeDirectoryW")
#pragma comment(linker, "/EXPORT:SymSetOptions=" DLLPATH ".SymSetOptions")
#pragma comment(linker, "/EXPORT:SymSetParentWindow=" DLLPATH ".SymSetParentWindow")
#pragma comment(linker, "/EXPORT:SymSetScopeFromAddr=" DLLPATH ".SymSetScopeFromAddr")
#pragma comment(linker, "/EXPORT:SymSetScopeFromIndex=" DLLPATH ".SymSetScopeFromIndex")
#pragma comment(linker, "/EXPORT:SymSetScopeFromInlineContext=" DLLPATH ".SymSetScopeFromInlineContext")
#pragma comment(linker, "/EXPORT:SymSetSearchPath=" DLLPATH ".SymSetSearchPath")
#pragma comment(linker, "/EXPORT:SymSetSearchPathW=" DLLPATH ".SymSetSearchPathW")
#pragma comment(linker, "/EXPORT:SymSetServiceManager=" DLLPATH ".SymSetServiceManager")
#pragma comment(linker, "/EXPORT:SymSrvDeltaName=" DLLPATH ".SymSrvDeltaName")
#pragma comment(linker, "/EXPORT:SymSrvDeltaNameW=" DLLPATH ".SymSrvDeltaNameW")
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexInfo=" DLLPATH ".SymSrvGetFileIndexInfo")
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexInfoW=" DLLPATH ".SymSrvGetFileIndexInfoW")
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexString=" DLLPATH ".SymSrvGetFileIndexString")
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexStringW=" DLLPATH ".SymSrvGetFileIndexStringW")
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexes=" DLLPATH ".SymSrvGetFileIndexes")
#pragma comment(linker, "/EXPORT:SymSrvGetFileIndexesW=" DLLPATH ".SymSrvGetFileIndexesW")
#pragma comment(linker, "/EXPORT:SymSrvGetSupplement=" DLLPATH ".SymSrvGetSupplement")
#pragma comment(linker, "/EXPORT:SymSrvGetSupplementW=" DLLPATH ".SymSrvGetSupplementW")
#pragma comment(linker, "/EXPORT:SymSrvIsStore=" DLLPATH ".SymSrvIsStore")
#pragma comment(linker, "/EXPORT:SymSrvIsStoreW=" DLLPATH ".SymSrvIsStoreW")
#pragma comment(linker, "/EXPORT:SymSrvStoreFile=" DLLPATH ".SymSrvStoreFile")
#pragma comment(linker, "/EXPORT:SymSrvStoreFileW=" DLLPATH ".SymSrvStoreFileW")
#pragma comment(linker, "/EXPORT:SymSrvStoreSupplement=" DLLPATH ".SymSrvStoreSupplement")
#pragma comment(linker, "/EXPORT:SymSrvStoreSupplementW=" DLLPATH ".SymSrvStoreSupplementW")
#pragma comment(linker, "/EXPORT:SymUnDName=" DLLPATH ".SymUnDName")
#pragma comment(linker, "/EXPORT:SymUnDName64=" DLLPATH ".SymUnDName64")
#pragma comment(linker, "/EXPORT:SymUnloadModule=" DLLPATH ".SymUnloadModule")
#pragma comment(linker, "/EXPORT:SymUnloadModule64=" DLLPATH ".SymUnloadModule64")
#pragma comment(linker, "/EXPORT:UnDecorateSymbolName=" DLLPATH ".UnDecorateSymbolName")
#pragma comment(linker, "/EXPORT:UnDecorateSymbolNameW=" DLLPATH ".UnDecorateSymbolNameW")
#pragma comment(linker, "/EXPORT:WinDbgExtensionDllInit=" DLLPATH ".WinDbgExtensionDllInit")
#pragma comment(linker, "/EXPORT:__EFN_DumpImage=" DLLPATH "._EFN_DumpImage")
#pragma comment(linker, "/EXPORT:block=" DLLPATH ".block")
#pragma comment(linker, "/EXPORT:chksym=" DLLPATH ".chksym")
#pragma comment(linker, "/EXPORT:dbghelp=" DLLPATH ".dbghelp")
#pragma comment(linker, "/EXPORT:dh=" DLLPATH ".dh")
#pragma comment(linker, "/EXPORT:fptr=" DLLPATH ".fptr")
#pragma comment(linker, "/EXPORT:homedir=" DLLPATH ".homedir")
#pragma comment(linker, "/EXPORT:inlinedbg=" DLLPATH ".inlinedbg")
#pragma comment(linker, "/EXPORT:itoldyouso=" DLLPATH ".itoldyouso")
#pragma comment(linker, "/EXPORT:lmi=" DLLPATH ".lmi")
#pragma comment(linker, "/EXPORT:lminfo=" DLLPATH ".lminfo")
#pragma comment(linker, "/EXPORT:lmsourcesinfo=" DLLPATH ".lmsourcesinfo")
#pragma comment(linker, "/EXPORT:omap=" DLLPATH ".omap")
#pragma comment(linker, "/EXPORT:optdbgdump=" DLLPATH ".optdbgdump")
#pragma comment(linker, "/EXPORT:optdbgdumpaddr=" DLLPATH ".optdbgdumpaddr")
#pragma comment(linker, "/EXPORT:srcfiles=" DLLPATH ".srcfiles")
#pragma comment(linker, "/EXPORT:stack_force_ebp=" DLLPATH ".stack_force_ebp")
#pragma comment(linker, "/EXPORT:stackdbg=" DLLPATH ".stackdbg")
#pragma comment(linker, "/EXPORT:sym=" DLLPATH ".sym")
#pragma comment(linker, "/EXPORT:vc7fpo=" DLLPATH ".vc7fpo")
#pragma comment(linker, "/EXPORT:__proxy1101=" DLLPATH ".#1101,@1101,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1102=" DLLPATH ".#1102,@1102,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1103=" DLLPATH ".#1103,@1103,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1104=" DLLPATH ".#1104,@1104,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1105=" DLLPATH ".#1105,@1105,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1106=" DLLPATH ".#1106,@1106,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1107=" DLLPATH ".#1107,@1107,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1108=" DLLPATH ".#1108,@1108,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1109=" DLLPATH ".#1109,@1109,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1110=" DLLPATH ".#1110,@1110,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1115=" DLLPATH ".#1115,@1115,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1116=" DLLPATH ".#1116,@1116,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1117=" DLLPATH ".#1117,@1117,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1118=" DLLPATH ".#1118,@1118,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1119=" DLLPATH ".#1119,@1119,NONAME")
#pragma comment(linker, "/EXPORT:__proxy1120=" DLLPATH ".#1120,@1120,NONAME")
#pragma endregion

template <typename T>
inline MH_STATUS MH_CreateHookEx(LPVOID pTarget, LPVOID pDetour, T** ppOriginal)
{
	return MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
}

template <typename T>
inline MH_STATUS MH_CreateHookApiEx(
	LPCWSTR pszModule, LPCSTR pszProcName, LPVOID pDetour, T** ppOriginal)
{
	return MH_CreateHookApi(
		pszModule, pszProcName, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
}

class win32_high_precision_timer {
public:
	win32_high_precision_timer() {
		// Use CREATE_WAITABLE_TIMER_HIGH_RESOLUTION if supported (Windows 10 1809+)
		timer = CreateWaitableTimerEx(nullptr, nullptr, CREATE_WAITABLE_TIMER_HIGH_RESOLUTION, TIMER_ALL_ACCESS);
		if (!timer) {
			timer = CreateWaitableTimerEx(nullptr, nullptr, 0, TIMER_ALL_ACCESS);
			if (!timer) {
				printf("Unable to create high_precision_timer, CreateWaitableTimerEx() failed: %d", GetLastError());
			}
		}
	}

	~win32_high_precision_timer() {
		if (timer) {
			CloseHandle(timer);
		}
	}

	void sleep_for(const std::chrono::nanoseconds& duration) {
		if (!timer) {
			printf("Attempting high_precision_timer::sleep_for() with uninitialized timer");
			return;
		}
		if (duration < 0s) {
			printf("Attempting high_precision_timer::sleep_for() with negative duration");
			return;
		}
		if (duration > 5s) {
			printf("Attempting high_precision_timer::sleep_for() with unexpectedly large duration (>5s)");
			return;
		}

		LARGE_INTEGER due_time;
		due_time.QuadPart = duration.count() / -100;
		SetWaitableTimer(timer, &due_time, 0, nullptr, nullptr, false);
		WaitForSingleObject(timer, INFINITE);
	}

	operator bool() {
		return timer != NULL;
	}

private:
	HANDLE timer = NULL;
};

typedef DWORD(WINAPI* WaitForMultipleObjectsEx_Def)(DWORD  nCount, const HANDLE* lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable);
WaitForMultipleObjectsEx_Def fpWaitForMultipleObjectsEx = nullptr;

typedef DWORD(WINAPI* WaitForSingleObjectEx_Def)(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable);
WaitForSingleObjectEx_Def fpWaitForSingleObjectEx = nullptr;


constexpr auto frameTime = std::chrono::duration<int64_t, std::ratio<1, 30>>(1);
thread_local auto lastUpdate = std::chrono::high_resolution_clock::now();

static DWORD WINAPI WaitForMultipleObjectsEx_hook(DWORD nCount, const HANDLE* lpHandles, BOOL bWaitAll, DWORD dwMilliseconds, BOOL bAlertable)
{
	auto result = fpWaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, 0, bAlertable);
	
	auto now = std::chrono::high_resolution_clock::now();
	if (now - lastUpdate < frameTime)
	{
		win32_high_precision_timer timer;
		timer.sleep_for(now - lastUpdate);
		//printf("Slept for: %.2lf ms\n", ((std::chrono::high_resolution_clock::now() - now).count() / 1e9) * 1e3);
	}
	lastUpdate = now;
	
	return result;
}

static DWORD WINAPI WaitForSingleObjectEx_hook(HANDLE hHandle, DWORD dwMilliseconds, BOOL bAlertable)
{
	return fpWaitForSingleObjectEx(hHandle, dwMilliseconds == 0 ? 100 : dwMilliseconds, bAlertable);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
    {
		printf("Enshrouded Fix loaded!\n");

		// Initialize MinHook.
		MH_STATUS status = MH_Initialize();

		if (status != MH_OK)
		{
			printf("MH Init failed: %s\n", MH_StatusToString(status));
			return false;
		}

		status = MH_CreateHookApiEx(L"Kernel32.dll", "WaitForMultipleObjectsEx", (LPVOID)&WaitForMultipleObjectsEx_hook, &fpWaitForMultipleObjectsEx);
		if (status != MH_OK)
		{
			printf("WaitForMultipleObjectsEx Hook failed: %s\n", MH_StatusToString(status));
		}

		status = MH_CreateHookApiEx(L"Kernel32.dll", "WaitForSingleObjectEx", (LPVOID)&WaitForSingleObjectEx_hook, &fpWaitForSingleObjectEx);
		if (status != MH_OK)
		{
			printf("WaitForSingleObjectEx Hook failed: %s\n", MH_StatusToString(status));
		}

		status = MH_EnableHook(MH_ALL_HOOKS);
		if (status != MH_OK) {
			printf("Hook activation failed: %s\n", MH_StatusToString(status));
			return false;
		}
		else
			printf("Hooks successful!\n");
        break;
    }
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
