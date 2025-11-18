#include <ecmdDllCapi.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>
extern "C"
{
#include <libpdbg.h>
}
#include <unistd.h>

#include <phosphor-logging/lg2.hpp>


uint32_t dllLoadDll(const char* version, uint32_t)
{
    lg2::info("dllLoadDll version {VER}", "VER", version);
    return dllInitDll();
}

uint32_t dllUnloadDll()
{
    lg2::info("dllUnloadDll ");
    return dllFreeDll();
}

uint32_t dllInitDll()
{
    lg2::info("dllInitDll ");
    const char* dtbPath = getenv("PDBG_DTB");
    if (!dtbPath)
    {
        lg2::error("Failed to get PDBG_DTB env variable");
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

uint32_t dllCheckDllVersion(const char*)
{
    lg2::error("dllCheckDllVersion is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}
uint32_t dllSyncPluginState(const ecmdChipTarget&)
{
    lg2::error("dllSyncPluginState is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllChipCleanup(const ecmdChipTarget&, uint32_t)
{
    lg2::error("dllChipCleanup is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllGetConfiguration(const ecmdChipTarget&, std::string,
                             ecmdConfigValid_t&, std::string&, uint32_t&)
{
    lg2::error("dllGetConfiguration is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllGetConfigurationComplex(const ecmdChipTarget&, std::string,
                                    ecmdConfigData&)
{
    lg2::error("dllGetConfigurationComplex is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllSetConfiguration(const ecmdChipTarget&, std::string,
                             ecmdConfigValid_t, std::string, uint32_t)
{
    lg2::error("dllSetConfiguration is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllSetConfigurationComplex(const ecmdChipTarget&, std::string,
                                    ecmdConfigData)
{
    lg2::error("dllSetConfigurationComplex is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllDeconfigureTarget(const ecmdChipTarget&)
{
    lg2::error("dllDeconfigureTarget is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllConfigureTarget(const ecmdChipTarget&)
{
    lg2::error("dllConfigureTarget is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllSetConfigurationComplexHidden(const ecmdChipTarget&, std::string,
                                          ecmdConfigData, uint32_t)
{
    lg2::error("dllSetConfigurationComplexHidden is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllFreeDll()
{
    lg2::error("dllFreeDll is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllSpecificCommandArgs([[maybe_unused]] int* io_argc,
                                [[maybe_unused]] char** io_argv[])
{
    return ECMD_SUCCESS;
}

std::string dllSpecificParseReturnCode(uint32_t)
{
    lg2::error("dllSpecificParseReturnCode is not implemented");
    return {};
}

void dllLoadDllRecovery(std::string, uint32_t&)
{
    lg2::error("dllLoadDllRecovery is not implemented");
}
uint32_t dllQueryDllInfo(ecmdDllInfo&)
{
    lg2::error("dllQueryDllInfo is not implemented");
    return ECMD_SUCCESS;
}

void dllOutputError(const char* err)
{
    lg2::error("error {ERR}", "ERR", err);
}

void dllOutputWarning(const char* err)
{
    lg2::warning("warning {ERR}", "ERR", err);
}

void dllOutput(const char* msg)
{
    lg2::info("msg {MSG}", "MSG", msg);
}

void dllSetTraceMode(ecmdTraceType_t, bool)
{
    lg2::error("dllSetTraceMode is not implemented");
}

bool dllQueryTraceMode(ecmdTraceType_t)
{
    lg2::error("dllQueryTraceMode is not implemented");
    return false;
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

std::string dllLastError()
{
    lg2::error("dllLastError is not implemented");
    return {};
}
