#include <ecmd/ecmdDllCapi.H>
#include <ecmdDataBuffer.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>

#include <phosphor-logging/lg2.hpp>

#include <cstdint>

uint32_t dllEnableRingCache(const ecmdChipTarget&)
{
    lg2::error("dllEnableRingCache is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllDisableRingCache(const ecmdChipTarget&)
{
    lg2::error("dllDisableRingCache is not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllFlushRingCache(const ecmdChipTarget&)
{
    lg2::error("dllFlushRingCache is not implemented");
    return ECMD_SUCCESS;
}

bool dllIsRingCacheEnabled(const ecmdChipTarget&)
{
    return true;
}
