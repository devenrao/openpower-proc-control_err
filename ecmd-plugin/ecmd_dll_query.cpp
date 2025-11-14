#include <ecmd/ecmdDllCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>

#include <phosphor-logging/lg2.hpp>

#include <cstdint>

uint32_t dllLooperInit(ecmdChipTarget&, ecmdLoopType_t, ecmdLooperData&,
                       ecmdLoopMode_t)
{
    lg2::error("dllLooperInit is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllConfigLooperInit(ecmdChipTarget&, ecmdLoopType_t, ecmdLooperData&)
{
    lg2::error("dllConfigLooperInit is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllExistLooperInit(ecmdChipTarget&, ecmdLoopType_t, ecmdLooperData&)
{
    lg2::error("dllExistLooperInit is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllLooperNext(ecmdChipTarget&, ecmdLooperData&, ecmdLoopMode_t)
{
    lg2::error("dllLooperNext is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllConfigLooperNext(ecmdChipTarget&, ecmdLooperData&)
{
    lg2::error("dllConfigLooperNext is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllExistLooperNext(ecmdChipTarget&, ecmdLooperData&)
{
    lg2::error("dllExistLooperNext is not implemented");
    return ECMD_SUCCESS;
}
bool dllQueryVersionGreater(const char*)
{
    lg2::error("dllQueryVersionGreater is not implemented");
    return ECMD_SUCCESS;
}
uint32_t dllQueryConfig(const ecmdChipTarget&, ecmdQueryData&,
                        ecmdQueryDetail_t)
{
    lg2::error("dllQueryConfig is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllQueryExist(const ecmdChipTarget&, ecmdQueryData&, ecmdQueryDetail_t)
{
    lg2::error("dllQueryExist is not implemented");
    return ECMD_SUCCESS;
}
uint32_t dllQueryConfigSelected(ecmdChipTarget&, ecmdQueryData&, ecmdLoopType_t)
{
    lg2::error("dllQueryConfigSelected is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllQueryExistSelected(ecmdChipTarget&, ecmdQueryData&, ecmdLoopType_t)
{
    lg2::error("dllQueryExistSelected is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllRelatedTargets(const ecmdChipTarget&, const std::string,
                           std::list<ecmdChipTarget>&, const ecmdLoopMode_t)
{
    lg2::error("dllRelatedTargets is not implemented");
    return ECMD_SUCCESS;
}
uint32_t dllQueryFileLocation(const ecmdChipTarget&, ecmdFileType_t,
                              std::list<ecmdFileLocation>&, std::string&)
{
    lg2::error("dllQueryFileLocation is not implemented");
    return ECMD_SUCCESS;
}

bool dllQueryTargetConfigured(const ecmdChipTarget&, const ecmdQueryData*)
{
    lg2::error("dllQueryTargetConfigured is not implemented");
    return true;
}

bool dllQueryTargetExist(const ecmdChipTarget&, const ecmdQueryData*)
{
    lg2::error("dllQueryTargetExist is not implemented");
    return true;
}

uint32_t dllQueryConnectedTargets(const ecmdChipTarget&, const char*,
                                  std::list<ecmdConnectionData>&)
{
    lg2::error("dllQueryConnectedTargets is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllGetChipData(const ecmdChipTarget&, ecmdChipData&)
{
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
