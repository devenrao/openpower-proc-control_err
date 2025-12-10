#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>
#include <unistd.h>
extern "C"
{
#include <libpdbg.h>
}

#include <phosphor-logging/lg2.hpp>

extern "C"
{
uint32_t dllInitDll()
{
    const char* dtbPath = getenv("PDBG_DTB");
    if (!dtbPath)
    {
        lg2::error("Failed to get PDBG_DTB env variable");
        return ECMD_FAILURE;
    }
    if (!std::filesystem::exists(dtbPath) ||
        !std::filesystem::is_regular_file(dtbPath))
    {
        lg2::error("Invalid PDBG_DTB path {PATH}", "PATH", dtbPath);
        return ECMD_FAILURE;
    }
    const char* ecmdExe = getenv("ECMD_EXE");
    if (!ecmdExe)
    {
        lg2::error("Failed to get ECMD_EXE env variable");
        return ECMD_FAILURE;
    }
    if (!std::filesystem::exists(ecmdExe) ||
        !std::filesystem::is_regular_file(ecmdExe))
    {
        lg2::error("Invalid ECMD_EXE path {PATH}", "PATH", ecmdExe);
        return ECMD_FAILURE;
    }

    pdbg_targets_init(NULL);
    return ECMD_SUCCESS;
}

uint32_t dllFreeDll()
{
    return ECMD_SUCCESS;
}
uint32_t dllLoadDll(const char*, uint32_t)
{
    return dllInitDll();
}

uint32_t dllUnloadDll()
{
    return dllFreeDll();
}

void dllOutputError(const char* str)
{
    lg2::error("{STR}", "STR", str);
}

void dllOutputWarning(const char* str)
{
    lg2::warning("{STR}", "STR", str);
}

uint32_t dllDelay(uint32_t, uint32_t msDelay)
{
    uint32_t rc = usleep(msDelay * 1000);
    if (rc != 0)
    {
        lg2::error("dllDelay usleep failed");
    }
    return rc;
}
//---------------------------------------------------------------------
// optional methods the plugin can choose to add implementation
//---------------------------------------------------------------------
void dllOutput(const char* str)
{
    lg2::warning("{STR}", "STR", str);
}

uint32_t dllGetGlobalVar(ecmdGlobalVarType_t)
{
    return ECMD_SUCCESS;
}
uint32_t dllQueryDllInfo(ecmdDllInfo&)
{
    return ECMD_SUCCESS;
}

uint32_t dllCheckDllVersion(const char*)
{
    return ECMD_SUCCESS;
}

bool dllQueryVersionGreater(const char*)
{
    return false;
}

std::string dllGetCurrentCmdline()
{
    return {};
}

void dllSetCurrentCmdline(int, [[maybe_unused]] char* argv[]) {}

uint32_t dllSetGlobalVar(ecmdGlobalVarType_t, uint32_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllCommonCommandArgs(int*, [[maybe_unused]] char** argv[])
{
    return ECMD_SUCCESS;
}
} // extern "C"
