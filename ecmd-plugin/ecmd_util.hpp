#pragma once
extern "C"
{
#include <libpdbg.h>
}
namespace ecmd_util
{
struct pdbg_target* get_fsi_target(uint32_t pos);

bool isChassisOn();

int startAttnHandler();

// Trigger obmcutil hostrebootoff->chassison->wait for chassison()
int istepPowerOn();

// Set host state to running
int setHostStateToRunning();
} // namespace ecmd_util
