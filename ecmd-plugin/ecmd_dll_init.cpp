#include <ecmd/ecmdDllCapi.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>
extern "C"
{
#include <libpdbg.h>
}
#include <phosphor-logging/lg2.hpp>

constexpr std::string_view envVar = "ECMD_DLL_FILE";

//----------------------------------------------
// functions invoked from ecmdClientCapiFunc.C
//----------------------------------------------

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

void dllPushCommandArgs()
{
    lg2::error("dllPushCommandArgs is not implemented");
}

void dllPopCommandArgs()
{
    lg2::error("dllPopCommandArgs is not implemented");
}

uint32_t dllSyncPluginState(const ecmdChipTarget&)
{
    lg2::error("dllSyncPluginState is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllChipCleanup(const ecmdChipTarget&, uint32_t)
{
    lg2::error("dllChipCleanup is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllGetConfiguration(const ecmdChipTarget&, std::string,
                             ecmdConfigValid_t&, std::string&, uint32_t&)
{
    lg2::error("dllGetConfiguration is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllGetConfigurationComplex(const ecmdChipTarget&, std::string,
                                    ecmdConfigData&)
{
    lg2::error("dllGetConfigurationComplex is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllSetConfiguration(const ecmdChipTarget&, std::string,
                             ecmdConfigValid_t, std::string, uint32_t)
{
    lg2::error("dllSetConfiguration is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllSetConfigurationComplex(const ecmdChipTarget&, std::string,
                                    ecmdConfigData)
{
    lg2::error("dllSetConfigurationComplex is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllDeconfigureTarget(const ecmdChipTarget&)
{
    lg2::error("dllDeconfigureTarget is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllConfigureTarget(const ecmdChipTarget&)
{
    lg2::error("dllConfigureTarget is not implemented");
    return ECMD_SUCCESS;
}

/* Dll Common unload function */
uint32_t dllUnloadDll()
{
    return dllFreeDll();
}

uint32_t dllSetConfigurationComplexHidden(const ecmdChipTarget&, std::string,
                                          ecmdConfigData, uint32_t)
{
    lg2::error("dllSetConfigurationComplexHidden is not implemented");
    return ECMD_SUCCESS;
}

/* Dll Specific unload function - deallocates variables/object models */
uint32_t dllFreeDll()
{
    lg2::error("dllFreeDll is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllCheckDllVersion(const char*)
{
    lg2::error("dllCheckDllVersion is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllCommonCommandArgs([[maybe_unused]] int* argc,
                              [[maybe_unused]] char** argv[])
{
    lg2::error("dllCommonCommandArgs is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllSpecificCommandArgs([[maybe_unused]] int* io_argc,
                                [[maybe_unused]] char** io_argv[])
{
    lg2::error("dllSpecificCommandArgs is not implemented");
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

uint32_t dllGetGlobalVar(ecmdGlobalVarType_t)
{
    lg2::error("dllGetGlobalVar is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllSetGlobalVar(ecmdGlobalVarType_t, uint32_t)
{
    lg2::error("dllSetGlobalVar is not implemented");
    return ECMD_SUCCESS;
}

void dllSetTraceMode(ecmdTraceType_t, bool)
{
    lg2::error("dllSetTraceMode is not implemented");
}

bool dllQueryTraceMode(ecmdTraceType_t)
{
    lg2::error("dllQueryTraceMode is not implemented");
    return true;
}

uint32_t dllDelay(uint32_t, uint32_t)
{
    lg2::error("dllDelay is not implemented");
    return ECMD_SUCCESS;
}

std::string dllGetCurrentCmdline()
{
    lg2::error("dllGetCurrentCmdline is not implemented");
    return {};
}

void dllSetCurrentCmdline([[maybe_unused]] int argc,
                          [[maybe_unused]] char* argv[])
{
    lg2::error("dllSetCurrentCmdline is not implemented");
}
