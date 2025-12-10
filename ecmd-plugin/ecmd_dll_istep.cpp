#include <ecmdDataBuffer.H>
#include <ecmdReturnCodes.H>
#include <ecmdStructs.H>
#include <ecmd_util.hpp>
#include <istep_table.hpp>
#include <phosphor-logging/lg2.hpp>

#if 0
constexpr openpower::ipl::Domain domainFrom(istep_table::IStepDestination d)
{
    using Dest = istep_table::IStepDestination;
    using Dom = openpower::ipl::Domain;

    switch (d)
    {
        case Dest::EDBG_ISTEP_BMC:
            return Dom::BMC;
        case Dest::EDBG_ISTEP_SBE:
            return Dom::SPPE;
        case Dest::EDBG_ISTEP_HOST:
            return Dom::HB;
        default:
            return Dom::NOOP;
    }
}
#endif
constexpr uint16_t ISTEP_HOST_RUNNING_MAJOR = 6;
constexpr uint16_t ISTEP_HOST_RUNNING_MINOR = 4;

uint32_t executeIstep(uint16_t /*major*/, uint16_t /*minorStart*/, uint16_t /*minorEnd*/)
{
    uint32_t rc = ECMD_SUCCESS;
#if 0    
    lg2::info(
        "executeIstep major={MAJOR} minorstart={MINOR_START} minorend={MINOR_END} ",
        "MAJOR", major, "MINOR_START", minorStart, "MINOR_END", minorEnd);
    using namespace istep_table;
    uint32_t rc = ECMD_SUCCESS;

    if (minorStart > minorEnd)
    {
        lg2::error("Invalid istep range: minor start {START}> minor end {END}",
                   "START", minorStart, "END", minorEnd);
        return ECMD_INVALID_ARGS;
    }

    // If istep is 0 then, run chassis on and other workaround steps before
    // kick off ipl_run_major_minor() in loop
    if (major == 0)
    {
        /* istep power on */
        rc = ecmd_util::istepPowerOn();
        if (!rc)
        {
            // Set IPL mode to interactive
            rc = iplInit(HOSTBOOT_MODE);
            if (rc)
            {
                lg2::error("Unable to set IPL in interactive mode");
                return rc;
            }
        }
        else
        {
            lg2::error("FAIL: istepPowerOn");
            return rc;
        }
    } // major ==0
    // loop through each isteps
    for (uint16_t minor = minorStart; minor <= minorEnd; minor++)
    {
        auto istepNameOpt = istep_table::getStepName(major, minor);
        if (!istepNameOpt)
        {
            lg2::error("Invalid istep major={MAJOR} minor={MINOR}", "MAJOR",
                       major, "MINOR", minor);
            continue;
        }
        IStepDestination destination = getDestination(major, minor);

        // This istep is NOOP
        if (destination == IStepDestination::EDBG_ISTEP_NOOP)
        {
            lg2::info("Requested istep {STEP} is noop", "STEP", *istepNameOpt);
        }
        else
        {
            //openpower::ipl::Domain domain = domainFrom(destination);
            //openpower::ipl::executeIstep(major, minor, domain);
            if (!rc)
            {
                // TODO: check if this is valid in phal-next
                if (major == ISTEP_HOST_RUNNING_MAJOR &&
                    minor == ISTEP_HOST_RUNNING_MINOR)
                {
                    // if the istep reaches 6.4 then, set the Host state to
                    // running!
                    rc = ecmd_util::setHostStateToRunning();
                    if (rc)
                    {
                        lg2::error("FAIL: failed to set host state");
                        return rc;
                    }
                }
                lg2::info("PASS: istep {STEP}", "STEP", *istepNameOpt);
            }
            else
            {
                lg2::error("FAIL: istep check Error {STEP}", "STEP",
                           *istepNameOpt);
                return rc;
            }
        }
    } // end for
#endif
    return rc;
}
extern "C"
{
uint32_t dllIStepsByNumber(const ecmdDataBuffer& isteps)
{
    using namespace istep_table;

    static_assert(EDBG_LAST_ISTEP_NUM >= EDBG_FIRST_ISTEP_NUM,
                  "Invalid istep range");

    const uint32_t rangeLen = EDBG_LAST_ISTEP_NUM - EDBG_FIRST_ISTEP_NUM + 1;

    // Count active isteps
    const uint32_t numActive =
        isteps.getNumBitsSet(EDBG_FIRST_ISTEP_NUM, rangeLen);

    if (numActive == 0)
    {
        lg2::error("No Steps selected in range {FIRST} to {LAST}", "FIRST",
                   EDBG_FIRST_ISTEP_NUM, "LAST", EDBG_LAST_ISTEP_NUM);
        return ECMD_INVALID_ARGS;
    }

    lg2::info("Number of active iStep bits = {COUNT}", "COUNT", numActive);

    uint32_t remaining = numActive;
    uint32_t rc = ECMD_SUCCESS;

    // Iterate only until we find all active bits
    for (uint16_t step = EDBG_FIRST_ISTEP_NUM;
         step <= EDBG_LAST_ISTEP_NUM && remaining > 0 && rc == ECMD_SUCCESS;
         ++step)
    {
        if (!isteps.isBitSet(step))
            continue;

        --remaining; // We will process this istep

        // Validate that this istep exists in the IPL table
        if (!isValid(step))
        {
            lg2::error("Requested iStep Number {STEP} is invalid", "STEP",
                       step);
            continue;
        }

        // Resolve minor numbers
        const uint16_t indexBegin = getPosFirstMinorNumber(step);
        const uint16_t minorStart = getIStepMinorNumber(indexBegin);

        const uint16_t indexEnd = getPosLastMinorNumber(step);
        const uint16_t minorEnd = getIStepMinorNumber(indexEnd);

        // Execute
        rc = executeIstep(step, minorStart, minorEnd);
        if (rc != ECMD_SUCCESS)
        {
            lg2::error("Error executing iStep {STEP}", "STEP", step);
            break;
        }
    }

    return rc;
}

uint32_t dllIStepsByName(std::string stepName)
{
    lg2::warning("dllIStepsByName name {STEP} not implemented", "STEP",
                 stepName);
    return ECMD_SUCCESS;
}

uint32_t dllIStepsByNameMultiple(std::list<std::string>)
{
    lg2::warning("dllIStepsByNameMultiple not implemented");
    return ECMD_SUCCESS;
}

uint32_t dllIStepsByNameRange(std::string begin, std::string end)
{
    // TODO: Refer to edbgEcmdDll.C and add relevant code here
    lg2::info("dllIStepsByNameRange {BEGIN} to {END}", "BEGIN", begin, "END",
              end);
    lg2::warning("dllIStepsByNameRange not implemented");
    return ECMD_FUNCTION_NOT_SUPPORTED;
}
} // extern "C"
