#include <ecmd/ecmdDllCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>

#include <phosphor-logging/lg2.hpp>

#include <cstdint>

uint32_t dllQueryConfig(const ecmdChipTarget&, ecmdQueryData&,
                        ecmdQueryDetail_t)
{
    // TODO: add implementation from edbgEcmdDll.C
    lg2::error("dllQueryConfig is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllQueryExist(const ecmdChipTarget&, ecmdQueryData&, ecmdQueryDetail_t)
{
    // TODO: add implementation from edbgEcmdDll.C
    lg2::error("dllQueryExist is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllRelatedTargets(const ecmdChipTarget&, const std::string,
                           std::list<ecmdChipTarget>&, const ecmdLoopMode_t)
{
    lg2::error("dllRelatedTargets is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}
uint32_t dllQueryFileLocation(const ecmdChipTarget&, ecmdFileType_t,
                              std::list<ecmdFileLocation>&, std::string&)
{
    // TODO: check and implement the method from edbgEcmdDll.C
    return ECMD_SUCCESS;
}

uint32_t dllQueryConnectedTargets(const ecmdChipTarget&, const char*,
                                  std::list<ecmdConnectionData>&)
{
    lg2::error("dllQueryConnectedTargets is not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}

uint32_t dllGetChipData(const ecmdChipTarget&, ecmdChipData&)
{
    // TODO: get implementation from edbgEcmdDll.C and add
    // relevant portions here
    lg2::error("dllGetChipData is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllQueryMode(const ecmdChipTarget&, std::string&, std::string&)
{
    lg2::error("dllQueryMode is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllQueryScom(const ecmdChipTarget&, std::list<ecmdScomData>&, uint64_t,
                      ecmdQueryDetail_t)
{
    lg2::error("dllQueryScom is not implemented");
    return ECMD_SUCCESS;
}
