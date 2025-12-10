#include <ecmdStructs.H>
extern "C"
{
//---------------------------------------------------------------------
// optional methods the plugin can choose to add implementation
//---------------------------------------------------------------------
bool dllIsRingCacheEnabled(const ecmdChipTarget&)
{
    return false;
}
}
