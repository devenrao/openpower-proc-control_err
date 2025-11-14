#include <ecmd/ecmdDllCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>

#include <phosphor-logging/lg2.hpp>

#include <cstdint>

uint32_t dllGetScom(const ecmdChipTarget&, uint64_t, ecmdDataBuffer&)
{
    lg2::error("dllGetScom is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllPutScom(const ecmdChipTarget&, uint64_t, const ecmdDataBuffer&)
{
    lg2::error("dllPutScom is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllPutScomUnderMask(const ecmdChipTarget&, uint64_t,
                             const ecmdDataBuffer&, const ecmdDataBuffer&)
{
    lg2::error("dllPutScomUnderMask is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllDoScomMultiple(const ecmdChipTarget&, std::list<ecmdScomEntry>&)
{
    lg2::error("dllDoScomMultiple is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllCreateChipUnitScomAddress(const ecmdChipTarget&, uint64_t,
                                      uint64_t&)
{
    lg2::error("dllCreateChipUnitScomAddress is not implemented");
    return ECMD_SUCCESS;
}
