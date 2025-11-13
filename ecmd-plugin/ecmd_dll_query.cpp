#include <ecmdDataBuffer.H>
#include <ecmdDllCapi.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>

#include <cstdint>
#include <iostream>

uint32_t dllLooperInit(ecmdChipTarget&, ecmdLoopType_t, ecmdLooperData&,
                       ecmdLoopMode_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllConfigLooperInit(ecmdChipTarget&, ecmdLoopType_t, ecmdLooperData&)
{
    return ECMD_SUCCESS;
}

uint32_t dllExistLooperInit(ecmdChipTarget&, ecmdLoopType_t, ecmdLooperData&)
{
    return ECMD_SUCCESS;
}

uint32_t dllLooperNext(ecmdChipTarget&, ecmdLooperData&, ecmdLoopMode_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllConfigLooperNext(ecmdChipTarget&, ecmdLooperData&)
{
    return ECMD_SUCCESS;
}

uint32_t dllExistLooperNext(ecmdChipTarget&, ecmdLooperData&)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryConfig(const ecmdChipTarget&, ecmdQueryData&,
                        ecmdQueryDetail_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryExist(const ecmdChipTarget&, ecmdQueryData&, ecmdQueryDetail_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryConfigSelected(ecmdChipTarget&, ecmdQueryData&, ecmdLoopType_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryExistSelected(ecmdChipTarget&, ecmdQueryData&, ecmdLoopType_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllRelatedTargets(const ecmdChipTarget&, const std::string,
                           std::list<ecmdChipTarget>&, const ecmdLoopMode_t)
{
    return ECMD_SUCCESS;
}

bool dllQueryVersionGreater(const char*)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryScom(const ecmdChipTarget&, std::list<ecmdScomData>&, uint64_t,
                      ecmdQueryDetail_t)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryFileLocation(const ecmdChipTarget&, ecmdFileType_t,
                              std::list<ecmdFileLocation>&, std::string&)
{
    return ECMD_SUCCESS;
}

bool dllQueryTargetConfigured(const ecmdChipTarget&, const ecmdQueryData*)
{
    return ECMD_SUCCESS;
}

bool dllQueryTargetExist(const ecmdChipTarget&, ecmdQueryData*)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryConnectedTargets(const ecmdChipTarget&, const char*,
                                  std::list<ecmdConnectionData>&)
{
    return ECMD_SUCCESS;
}

uint32_t dllGetChipData(const ecmdChipTarget&, ecmdChipData&)
{
    return ECMD_SUCCESS;
}

uint32_t dllQueryMode(const ecmdChipTarget&, std::string&, std::string&)
{
    return ECMD_SUCCESS;
}
