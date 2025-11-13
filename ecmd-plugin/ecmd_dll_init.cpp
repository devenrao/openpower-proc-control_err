#include <ecmdDllCapi.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>
extern "C"
{
#include <libpdbg.h>
}
#include <phosphor-logging/lg2.hpp>

constexpr std::string_view envVar = "ECMD_DLL_FILE";

/* Dll Common load function - verifies version */
uint32_t dllLoadDll(const char*, uint32_t)
{
    return dllInitDll();
}
/* Dll Specific load function - used by Cronus/GFW to init variables/object
 * models */
uint32_t dllInitDll()
{
    const char* dtbPath = getenv("PDBG_DTB");
    if (!dtbPath)
    {
        lg2::error("Failed to get PDBG_DTB env variable");
        return -1;
    }
    const char* dllFile = getenv("ECMD_DLL_FILE");
    if (!dllFile)
    {
        lg2::error("Failed to get  ECMD_DLL_FILE env variable");
        return -1;
    }

    const char* ecmdExe = getenv("ECMD_EXE");
    if (!ecmdExe)
    {
        lg2::error("Failed to get ECMD_EXE env variable");
        return -1;
    }

    pdbg_targets_init(NULL);
    return ECMD_SUCCESS;
}

/* Dll Common unload function */
uint32_t dllUnloadDll()
{
    return dllFreeDll();
}

/* Dll Specific unload function - deallocates variables/object models */
uint32_t dllFreeDll()
{
    return ECMD_SUCCESS;
}

/* Dll version check function */
uint32_t dllCheckDllVersion(const char*)
{
    return ECMD_SUCCESS;
}

/* Dll Common Command Line Args Function */
uint32_t dllCommonCommandArgs(int*, char**)
{
    return ECMD_SUCCESS;
}

/* Dll Specific Command Line Args Function */
uint32_t dllSpecificCommandArgs(int*, char**)
{
    return ECMD_SUCCESS;
}

/* Dll Specific Return Codes */
std::string dllSpecificParseReturnCode(uint32_t)
{
    return {};
}

void dllLoadDllRecovery(std::string, uint32_t&) {}

uint32_t dllQueryDllInfo(ecmdDllInfo&)
{
    return ECMD_SUCCESS;
}

std::string dllParseReturnCode(uint32_t)
{
    return {};
}

std::string dllLastError()
{
    return {};
}

void dllOutputError(const char*) {}

void dllOutputWarning(const char*) {}

void dllOutput(const char*) {}

uint32_t dllGetGlobalVar(ecmdGlobalVarType_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllSetGlobalVar(ecmdGlobalVarType_t, uint32_t)
{
    return ECMD_SUCCESS;
}

void dllSetTraceMode(ecmdTraceType_t, bool) {}

bool dllQueryTraceMode(ecmdTraceType_t)
{
    return true;
}

uint32_t dllDelay(uint32_t, uint32_t)
{
    return ECMD_SUCCESS;
}

std::string dllGetCurrentCmdline()
{
    return {};
}

void dllSetCurrentCmdline(int, char*) {}
