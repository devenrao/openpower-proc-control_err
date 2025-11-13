#include <ecmdDataBuffer.H>
#include <ecmdDllCapi.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>

#include <ecmd_util.hpp>
extern "C"
{
#include <libpdbg.h>
}
#include <phosphor-logging/lg2.hpp>

#include <cstdint>
uint32_t dllGetCfamRegister(const ecmdChipTarget& target, uint32_t address,
                            ecmdDataBuffer& ecmdData)
{
    lg2::info("address {ADDR} ", "ADDR", lg2::hex, address);
    auto fsiTarget = ecmd_util::get_fsi_target(target.pos);
    if (!fsiTarget)
    {
        lg2::error("Failed to find fsi target {POS} ", "POS", target.pos);
        return ECMD_FAILURE;
    }

    if (pdbg_target_probe(fsiTarget) != PDBG_TARGET_ENABLED)
    {
        lg2::error("Fsi Target not configured");
        return ECMD_FAILURE;
    }

    uint32_t data;
    int rc = fsi_read(fsiTarget, address, &data);
    if (rc)
    {
        lg2::error("Failed in fsi_read");
        return rc;
    }
    ecmdData.setBitLength(32);
    ecmdData.setWord(0, data);
    return ECMD_SUCCESS;
}

uint32_t dllPutCfamRegister(const ecmdChipTarget& target, uint32_t address,
                            const ecmdDataBuffer& data)
{
    lg2::info("putcfam address {ADDR} ", "ADDR", lg2::hex, address);
    auto fsiTarget = ecmd_util::get_fsi_target(target.pos);
    if (!fsiTarget)
    {
        lg2::error("Failed to find fsi target {POS} ", "POS", target.pos);
        return ECMD_FAILURE;
    }

    if (pdbg_target_probe(fsiTarget) != PDBG_TARGET_ENABLED)
    {
        lg2::error("Fsi Target not configured");
        return ECMD_FAILURE;
    }

    int rc = fsi_write(fsiTarget, address, data.getWord(0));
    if (rc)
    {
        lg2::error("Failed in fsi_write");
        return rc;
    }
    return ECMD_SUCCESS;
}
