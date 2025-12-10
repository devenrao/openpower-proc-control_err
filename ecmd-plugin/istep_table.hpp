#pragma once

//--------------------------------------------------------------------
// Includes
//--------------------------------------------------------------------
#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <optional>
#include <ranges>
#include <string>
namespace istep_table
{
// ---------------------------------------------------------------------
// Strongly-typed destination enum
// ---------------------------------------------------------------------
enum class IStepDestination : std::uint8_t
{
    EDBG_ISTEP_HOST = 0x0, // IStep is executed by host
    EDBG_ISTEP_SBE,        // IStep is executed by Self Boot Engine
    EDBG_ISTEP_BMC,        // IStep is executed by BMC
    EDBG_ISTEP_NOOP,       // This istep is NOOP
    EDBG_ISTEP_INVALID_DESTINATION
};

// ---------------------------------------------------------------------
// IPL Step structure
// ---------------------------------------------------------------------
struct IStep
{
    std::uint16_t major{};
    std::uint16_t minor{};
    std::string_view name{};
    IStepDestination dest{};
};

/****************************************************************************/
/* !!! --- THIS LIST MUST BE IN ORDER THAT THEY'RE CALLED IN AN IPL --- !!! */
/****************************************************************************/

/****************************************************************************/
/* NOTE: The istep is executed by the self boot engine/the host code/       */
/*       the attached bmc depending upon the destination type.              */
/*       Options:                                                           */
/*       EDBG_ISTEP_HOST - The istep is performed by the host               */
/*       EDBG_ISTEP_SBE  - The istep is performed by the self boot engine   */
/*       EDBG_ISTEP_BMC  - The istep is performed by the BMC                */
/*       EDBG_ISTEP_NOOP - The istep is No OP                               */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/* Warning : The following constants are defined based on the values of this*/
/*           table. Any changes to this table requires examination of the   */
/*           values assigned to these constants.                            */
/*                                                                          */
/*       EDBG_FIRST_ISTEP_NUM   = 0                                         */
/*       EDBG_LAST_ISTEP_NUM    = 21                                        */
/*       EDBG_INVALID_ISTEP_NUM = 0xFFFF                                    */
/*       EDBG_INVALID_POSITION  = 0xFFFF                                    */
/****************************************************************************/
// major | minor |                          istep name   | destination   |
// number| number|                                       | |
using IStepDestination::EDBG_ISTEP_BMC;
using IStepDestination::EDBG_ISTEP_HOST;
using IStepDestination::EDBG_ISTEP_NOOP;
using IStepDestination::EDBG_ISTEP_SBE;
inline constexpr auto ISteps = std::to_array<IStep>({
    {0, 1, "pre_cfam_reset", EDBG_ISTEP_NOOP},
    {0, 2, "cfam_reset", EDBG_ISTEP_NOOP},
    {0, 3, "poweron", EDBG_ISTEP_NOOP},
    {0, 4, "startipl", EDBG_ISTEP_NOOP},
    {0, 5, "disable_attns", EDBG_ISTEP_NOOP},
    {0, 6, "updatehwmodel", EDBG_ISTEP_BMC},
    {0, 7, "smp_topology", EDBG_ISTEP_NOOP},
    {0, 8, "boot_optimization_check", EDBG_ISTEP_NOOP},
    {0, 9, "set_ref_clock", EDBG_ISTEP_BMC},
    {0, 10, "clock_test", EDBG_ISTEP_NOOP},
    {0, 11, "hb_config_update", EDBG_ISTEP_NOOP},
    {0, 12, "ph_sppe_config_update", EDBG_ISTEP_BMC},
    {0, 13, "cbs_start", EDBG_ISTEP_BMC},
    {0, 14, "startPRD", EDBG_ISTEP_NOOP},
    {0, 15, "proc_attn_listen", EDBG_ISTEP_NOOP},
    {1, 1, "ph_enable_seeprom", EDBG_ISTEP_NOOP},
    {1, 2, "ph_tp_chiplet_reset", EDBG_ISTEP_NOOP},
    {1, 3, "ph_tp_pll_initf", EDBG_ISTEP_NOOP},
    {1, 4, "ph_tp_pll_setup", EDBG_ISTEP_NOOP},
    {1, 5, "ph_pib_repr_initf", EDBG_ISTEP_NOOP},
    {1, 6, "ph_pib_arrayinit", EDBG_ISTEP_NOOP},
    {1, 7, "ph_pib_arrayinit_cleanup", EDBG_ISTEP_NOOP},
    {1, 8, "ph_pib_lbist", EDBG_ISTEP_NOOP},
    {1, 9, "ph_pib_startclocks", EDBG_ISTEP_NOOP},
    {1, 10, "ph_sppe_boot", EDBG_ISTEP_NOOP},
    {1, 11, "ph_sppe_check_for_ready", EDBG_ISTEP_BMC},
    {1, 12, "ph_sppe_update", EDBG_ISTEP_NOOP},
    {1, 13, "ph_sppe_attr_override", EDBG_ISTEP_NOOP},
    {1, 14, "ph_sppe_attr_setup", EDBG_ISTEP_SBE},
    {1, 15, "ph_rcs_setup", EDBG_ISTEP_SBE},
    {1, 16, "ph_sppe_load_ring_pak", EDBG_ISTEP_SBE},
    {1, 17, "ph_tp_repr_initf", EDBG_ISTEP_SBE},
    {1, 18, "ph_tp_arrayinit", EDBG_ISTEP_SBE},
    {1, 19, "ph_tp_arrayinit_cleanup", EDBG_ISTEP_SBE},
    {1, 20, "ph_tp_initf", EDBG_ISTEP_SBE},
    {1, 21, "ph_tp_startclocks", EDBG_ISTEP_SBE},
    {1, 22, "ph_tp_init", EDBG_ISTEP_SBE},
    {2, 1, "ph_fsi_init", EDBG_ISTEP_SBE},
    {2, 2, "pc_fsi_config", EDBG_ISTEP_SBE},
    {2, 3, "pc_cbs_start", EDBG_ISTEP_SBE},
    {2, 4, "pc_tp_chiplet_reset", EDBG_ISTEP_SBE},
    {2, 5, "pc_tp_repr_initf", EDBG_ISTEP_SBE},
    {2, 6, "ph_sppe_unload_ring_pak", EDBG_ISTEP_SBE},
    {2, 7, "pc_tp_arrayinit_start", EDBG_ISTEP_SBE},
    {2, 8, "pc_tp_arrayinit_poll", EDBG_ISTEP_SBE},
    {2, 9, "pc_tp_arrayinit_cleanup", EDBG_ISTEP_SBE},
    {2, 10, "pc_tp_lbist", EDBG_ISTEP_SBE},
    {2, 11, "pc_pib_startclocks", EDBG_ISTEP_SBE},
    {2, 12, "ph_pc_sbe_load_code_pak", EDBG_ISTEP_SBE},
    {2, 13, "pc_sbe_config_update", EDBG_ISTEP_SBE},
    {2, 14, "ph_pc_sbe_start", EDBG_ISTEP_SBE},
    {2, 15, "ph_pc_sbe_check_for_ready", EDBG_ISTEP_SBE},
    {2, 16, "ph_pc_sbe_attr_setup", EDBG_ISTEP_SBE},
    {2, 17, "ph_pc_sbe_attr_override", EDBG_ISTEP_SBE},
    {2, 18, "ph_pc_sbe_load_ring_pak", EDBG_ISTEP_SBE},
    {2, 19, "pc_pll_initf", EDBG_ISTEP_SBE},
    {2, 20, "pc_pll_setup", EDBG_ISTEP_SBE},
    {2, 21, "pc_tp_initf", EDBG_ISTEP_SBE},
    {2, 22, "pc_tp_startclocks", EDBG_ISTEP_SBE},
    {2, 23, "pc_tp_init", EDBG_ISTEP_SBE},
    {3, 1, "ph_pc_chiplet_clk_config", EDBG_ISTEP_SBE},
    {3, 2, "ph_chiplet_deskew", EDBG_ISTEP_SBE},
    {3, 3, "ph_pc_chiplet_reset", EDBG_ISTEP_SBE},
    {3, 4, "ph_pc_chiplet_unused_psave", EDBG_ISTEP_SBE},
    {3, 5, "ph_pc_chiplet_pll_initf", EDBG_ISTEP_SBE},
    {3, 6, "ph_pc_chiplet_pll_setup", EDBG_ISTEP_SBE},
    {3, 7, "ph_pc_load_bist_pak", EDBG_ISTEP_SBE},
    {3, 8, "ph_pc_bist_repr_initf", EDBG_ISTEP_SBE},
    {3, 9, "ph_pc_abist", EDBG_ISTEP_SBE},
    {3, 10, "ph_pc_lbist", EDBG_ISTEP_SBE},
    {3, 11, "ph_pc_unload_bist_pak", EDBG_ISTEP_SBE},
    {3, 12, "ph_pc_chiplet_repr_initf", EDBG_ISTEP_SBE},
    {3, 13, "ph_pc_chiplet_arrayinit", EDBG_ISTEP_SBE},
    {3, 14, "ph_pc_chiplet_initf", EDBG_ISTEP_SBE},
    {3, 15, "ph_sbe_unload_ring_pak", EDBG_ISTEP_SBE},
    {3, 16, "ph_pc_chiplet_init", EDBG_ISTEP_SBE},
    {3, 17, "ph_pc_chiplet_startclocks", EDBG_ISTEP_SBE},
    {3, 18, "ph_pc_chiplet_fir_init", EDBG_ISTEP_SBE},
    {3, 19, "ph_pc_chiplet_vmeas_init", EDBG_ISTEP_SBE},
    {3, 20, "ph_pc_chiplet_skewadj_setup", EDBG_ISTEP_SBE},
    {3, 21, "ph_pc_nest_enable_io", EDBG_ISTEP_SBE},
    {3, 22, "ph_pc_chiplet_scominit", EDBG_ISTEP_SBE},
    {3, 23, "ph_pc_rng_init", EDBG_ISTEP_SBE},
    {3, 24, "ph_pc_chiplet_undo_force_on", EDBG_ISTEP_SBE},
    {4, 1, "ph_voltage_adjust", EDBG_ISTEP_SBE},
    {4, 2, "ph_pc_hss_ppe_load", EDBG_ISTEP_SBE},
    {4, 3, "ph_pc_hss_ppe_start", EDBG_ISTEP_SBE},
    {4, 4, "ph_pc_hss_bist_poll", EDBG_ISTEP_SBE},
    {4, 5, "ph_hss_init_start", EDBG_ISTEP_SBE},
    {4, 6, "ph_hss_init_poll", EDBG_ISTEP_SBE},
    {4, 7, "pc_tbus_hss_init_start", EDBG_ISTEP_SBE},
    {4, 8, "pc_tbus_hss_init_poll", EDBG_ISTEP_SBE},
    {4, 9, "ph_pc_tbus_link_setup", EDBG_ISTEP_SBE},
    {4, 10, "ph_pc_tbus_link_phy_train", EDBG_ISTEP_SBE},
    {4, 11, "ph_pc_tbus_link_phy_train_poll", EDBG_ISTEP_SBE},
    {4, 12, "ph_pc_tbus_link_ttl_train", EDBG_ISTEP_SBE},
    {4, 13, "ph_pc_tbus_link_ttl_train_poll", EDBG_ISTEP_SBE},
    {4, 14, "ph_island_powerbus_init", EDBG_ISTEP_SBE},
    {4, 15, "ph_boot_pcie_scominit", EDBG_ISTEP_SBE},
    {4, 16, "ph_boot_pcie_config", EDBG_ISTEP_SBE},
    {4, 17, "ph_boot_phb_init", EDBG_ISTEP_SBE},
    {4, 18, "ph_boot_pcie_bmc_detect_n_config", EDBG_ISTEP_SBE},
    {5, 1, "ph_smp_tx_zcal", EDBG_ISTEP_SBE},
    {5, 2, "ph_smp_tx_tdr", EDBG_ISTEP_SBE},
    {5, 3, "ph_smp_link_pretrain", EDBG_ISTEP_SBE},
    {5, 4, "ph_smp_link_setup", EDBG_ISTEP_SBE},
    {5, 5, "ph_smp_link_train", EDBG_ISTEP_SBE},
    {5, 6, "ph_smp_link_train_poll", EDBG_ISTEP_SBE},
    {5, 7, "ph_paxo_link_posttrain", EDBG_ISTEP_SBE},
    {5, 8, "ph_validate_smp_security", EDBG_ISTEP_SBE},
    {5, 9, "ph_smp_iovalid", EDBG_ISTEP_SBE},
    {5, 10, "ph_prep_secondary_smp_init", EDBG_ISTEP_SBE},
    {5, 11, "ph_smp_init", EDBG_ISTEP_SBE},
    {6, 1, "ph_select_boot_compute_chips", EDBG_ISTEP_SBE},
    {6, 2, "pc_select_ex_cache", EDBG_ISTEP_SBE},
    {6, 3, "pc_hcd_cache_poweron", EDBG_ISTEP_SBE},
    {6, 4, "pc_hcd_cache_reset", EDBG_ISTEP_SBE},
    {6, 5, "pc_hcd_cache_rtg_initf", EDBG_ISTEP_SBE},
    {6, 6, "pc_hcd_cache_arrayinit", EDBG_ISTEP_SBE},
    {6, 7, "pc_hcd_cache_initf", EDBG_ISTEP_SBE},
    {6, 8, "pc_hcd_cache_startclocks", EDBG_ISTEP_SBE},
    {6, 9, "pc_hcd_cache_scominit", EDBG_ISTEP_SBE},
    {6, 10, "pc_hcd_cache_scom_customize", EDBG_ISTEP_SBE},
    {6, 11, "pc_select_ex_core", EDBG_ISTEP_SBE},
    {6, 12, "pc_hcd_core_poweron", EDBG_ISTEP_SBE},
    {6, 13, "pc_hcd_core_reset", EDBG_ISTEP_SBE},
    {6, 14, "pc_hcd_core_rtg_initf", EDBG_ISTEP_SBE},
    {6, 15, "pc_hcd_core_arrayinit", EDBG_ISTEP_SBE},
    {6, 16, "pc_hcd_core_initf", EDBG_ISTEP_SBE},
    {6, 17, "pc_sbe_unload_ring_pak", EDBG_ISTEP_SBE},
    {6, 18, "pc_hcd_core_startclocks", EDBG_ISTEP_SBE},
    {6, 19, "pc_hcd_core_resonant_clocks", EDBG_ISTEP_SBE},
    {6, 20, "pc_hcd_core_scominit", EDBG_ISTEP_SBE},
    {6, 21, "pc_hcd_core_scom_customize", EDBG_ISTEP_SBE},
    {7, 1, "ph_load_host", EDBG_ISTEP_SBE},
    {7, 2, "pc_core_spr_setup", EDBG_ISTEP_SBE},
    {7, 3, "pc_runn_ipl", EDBG_ISTEP_SBE},
    {7, 4, "pc_runn_prep", EDBG_ISTEP_SBE},
    {7, 5, "pc_instruct_start", EDBG_ISTEP_SBE},
    {8, 1, "host_start_secondary_threads", EDBG_ISTEP_HOST},
    {8, 2, "host_prep_for_ipl", EDBG_ISTEP_HOST},
    {8, 3, "host_discover_targets", EDBG_ISTEP_HOST},
    {8, 4, "host_gard", EDBG_ISTEP_HOST},
    {8, 5, "host_secure_check", EDBG_ISTEP_HOST},
    {9, 1, "host_mss_attr_cleanup", EDBG_ISTEP_HOST},
    {9, 2, "mss_volt", EDBG_ISTEP_HOST},
    {9, 3, "mss_freq", EDBG_ISTEP_HOST},
    {9, 4, "mss_eff_config", EDBG_ISTEP_HOST},
    {9, 5, "mss_plug_rules", EDBG_ISTEP_HOST},
    {9, 6, "mss_eff_config_thermal", EDBG_ISTEP_HOST},
    {9, 7, "mss_eff_grouping", EDBG_ISTEP_HOST},
    {9, 8, "host_config_check", EDBG_ISTEP_HOST},
    {10, 1, "ph_pt_chiplet_scominit", EDBG_ISTEP_HOST},
    {10, 2, "host_pcie_config", EDBG_ISTEP_HOST},
    {10, 3, "ph_pcie_eff_config", EDBG_ISTEP_HOST},
    {10, 4, "ph_pcie_pec_config", EDBG_ISTEP_HOST},
    {10, 5, "ph_pcie_sba_init", EDBG_ISTEP_HOST},
    {10, 6, "ph_southbus_init", EDBG_ISTEP_HOST},
    {10, 7, "ph_pcie_phb_init", EDBG_ISTEP_HOST},
    {11, 1, "host_set_mem_volt", EDBG_ISTEP_HOST},
    {11, 2, "host_ocmb_enable", EDBG_ISTEP_HOST},
    {11, 3, "host_ocmb_pmic_cleanup", EDBG_ISTEP_HOST},
    {11, 4, "ocmb_check_pervasive", EDBG_ISTEP_HOST},
    {11, 5, "ocmb_config_update", EDBG_ISTEP_HOST},
    {11, 6, "ocmb_cbs_start", EDBG_ISTEP_HOST},
    {12, 1, "ody_tp_chiplet_reset", EDBG_ISTEP_HOST},
    {12, 2, "ody_tp_pll_initf", EDBG_ISTEP_HOST},
    {12, 3, "ody_tp_pll_setup", EDBG_ISTEP_HOST},
    {12, 4, "ody_pib_arrayinit", EDBG_ISTEP_HOST},
    {12, 5, "ody_pib_arrayinit_cleanup", EDBG_ISTEP_HOST},
    {12, 6, "ody_pib_startclocks", EDBG_ISTEP_HOST},
    {12, 7, "ocmb_sppe_check_for_ready", EDBG_ISTEP_HOST},
    {12, 8, "ocmb_i2c_code_update", EDBG_ISTEP_HOST},
    {12, 9, "ody_sppe_attr_setup", EDBG_ISTEP_HOST},
    {12, 10, "ody_tp_repr_initf", EDBG_ISTEP_HOST},
    {12, 11, "ody_tp_arrayinit", EDBG_ISTEP_HOST},
    {12, 12, "ody_tp_arrayinit_cleanup", EDBG_ISTEP_HOST},
    {12, 13, "ody_tp_initf", EDBG_ISTEP_HOST},
    {12, 14, "ody_tp_startclocks", EDBG_ISTEP_HOST},
    {12, 15, "ody_tp_init", EDBG_ISTEP_HOST},
    {12, 16, "ody_chiplet_clk_config", EDBG_ISTEP_HOST},
    {12, 17, "ody_chiplet_reset", EDBG_ISTEP_HOST},
    {12, 18, "ody_chiplet_unused_psave", EDBG_ISTEP_HOST},
    {12, 19, "ody_bist_repr_initf", EDBG_ISTEP_HOST},
    {12, 20, "ody_abist", EDBG_ISTEP_HOST},
    {12, 21, "ody_lbist", EDBG_ISTEP_HOST},
    {12, 22, "ody_chiplet_repr_initf", EDBG_ISTEP_HOST},
    {12, 23, "ody_chiplet_arrayinit", EDBG_ISTEP_HOST},
    {12, 24, "ody_chiplet_initf", EDBG_ISTEP_HOST},
    {12, 25, "ody_chiplet_init", EDBG_ISTEP_HOST},
    {12, 26, "ody_chiplet_startclocks", EDBG_ISTEP_HOST},
    {12, 27, "ody_chiplet_fir_init", EDBG_ISTEP_HOST},
    {12, 28, "ody_nest_enable_io", EDBG_ISTEP_HOST},
    {13, 1, "mss_getecid", EDBG_ISTEP_HOST},
    {13, 2, "ph_init_mem_encryption", EDBG_ISTEP_HOST},
    {13, 3, "omi_attr_update", EDBG_ISTEP_HOST},
    {13, 4, "ph_omi_scominit", EDBG_ISTEP_HOST},
    {13, 5, "ph_omi_setup_bars", EDBG_ISTEP_HOST},
    {13, 6, "ocmb_omi_hss_ppe_load", EDBG_ISTEP_HOST},
    {13, 7, "ocmb_omi_hss_config", EDBG_ISTEP_HOST},
    {13, 8, "ocmb_omi_hss_ppe_start", EDBG_ISTEP_HOST},
    {13, 9, "ocmb_omi_hss_bist_init", EDBG_ISTEP_HOST},
    {13, 10, "ocmb_omi_hss_bist_start", EDBG_ISTEP_HOST},
    {13, 11, "ocmb_omi_hss_bist_poll", EDBG_ISTEP_HOST},
    {13, 12, "ocmb_omi_hss_bist_cleanup", EDBG_ISTEP_HOST},
    {13, 13, "ocmb_omi_hss_init", EDBG_ISTEP_HOST},
    {13, 14, "ocmb_omi_hss_dccal_start", EDBG_ISTEP_HOST},
    {13, 15, "ocmb_omi_hss_dccal_poll", EDBG_ISTEP_HOST},
    {13, 16, "ph_omi_tx_zcal", EDBG_ISTEP_HOST},
    {13, 17, "ocmb_omi_tx_zcal", EDBG_ISTEP_HOST},
    {13, 18, "omi_tx_tdr", EDBG_ISTEP_HOST},
    {13, 19, "ocmb_omi_link_setup", EDBG_ISTEP_HOST},
    {13, 20, "ph_omi_link_setup", EDBG_ISTEP_HOST},
    {13, 21, "omi_link_train", EDBG_ISTEP_HOST},
    {13, 22, "omi_link_train_poll", EDBG_ISTEP_HOST},
    {13, 23, "host_attnlisten_ocmb", EDBG_ISTEP_HOST},
    {13, 24, "ocmb_tl_omi_init", EDBG_ISTEP_HOST},
    {13, 25, "host_tl_omi_init", EDBG_ISTEP_HOST},
    {13, 26, "ocmb_init_firs", EDBG_ISTEP_HOST},
    {13, 27, "update_omi_firmware", EDBG_ISTEP_HOST},
    {14, 1, "ddr_attr_update", EDBG_ISTEP_HOST},
    {14, 2, "mss_scominit", EDBG_ISTEP_HOST},
    {14, 3, "mss_ddrphyinit", EDBG_ISTEP_HOST},
    {14, 4, "mss_align_refresh", EDBG_ISTEP_HOST},
    {14, 5, "ocmb_load_i_d_mem", EDBG_ISTEP_HOST},
    {14, 6, "mss_ocmb_draminit", EDBG_ISTEP_HOST},
    {14, 7, "mss_host_draminit", EDBG_ISTEP_HOST},
    {14, 8, "mss_phy_init_engine", EDBG_ISTEP_HOST},
    {14, 9, "mss_draminit_mc", EDBG_ISTEP_HOST},
    {14, 10, "mss_ocmb_fetch_attr_data", EDBG_ISTEP_HOST},
    {14, 11, "mss_enable_ecc", EDBG_ISTEP_HOST},
    {15, 1, "mss_memdiag", EDBG_ISTEP_HOST},
    {15, 2, "mss_thermal_init", EDBG_ISTEP_HOST},
    {15, 3, "mss_throttle_sync", EDBG_ISTEP_HOST},
    {15, 4, "ph_setup_mmio_bars", EDBG_ISTEP_HOST},
    {15, 5, "host_secure_rng", EDBG_ISTEP_HOST},
    {15, 6, "host_secure_ocmb", EDBG_ISTEP_HOST},
    {15, 7, "host_enable_memory_encryption", EDBG_ISTEP_HOST},
    {15, 8, "host_zero_mem_with_encryption", EDBG_ISTEP_HOST},
    {15, 9, "host_exit_cache_contained", EDBG_ISTEP_HOST},
    {15, 10, "host_mpipl_service", EDBG_ISTEP_HOST},
    {16, 1, "host_build_homer_image", EDBG_ISTEP_HOST},
    {16, 2, "host_set_homer_bar", EDBG_ISTEP_HOST},
    {16, 3, "host_start_stop_engine", EDBG_ISTEP_HOST},
    {16, 4, "host_establish_ec_chiplet", EDBG_ISTEP_HOST},
    {17, 1, "host_activate_boot_core", EDBG_ISTEP_HOST},
    {17, 2, "host_activate_secondary_cores", EDBG_ISTEP_HOST},
    {18, 1, "ph_tod_setup", EDBG_ISTEP_HOST},
    {18, 2, "ps_pt_tod_init", EDBG_ISTEP_HOST},
    {18, 3, "mss_scrub", EDBG_ISTEP_HOST},
    {18, 4, "host_ipl_complete", EDBG_ISTEP_HOST},
    {18, 5, "proc_load_exerciser_avp", EDBG_ISTEP_NOOP},
    {18, 6, "proc_setup_user_context", EDBG_ISTEP_NOOP},
    {19, 1, "no_op", EDBG_ISTEP_NOOP},
    {20, 1, "host_load_payload", EDBG_ISTEP_HOST},
    {20, 2, "build_host_data_structs", EDBG_ISTEP_HOST},
    {21, 1, "host_runtime_pm_setup", EDBG_ISTEP_HOST},
    {21, 2, "host_start_payload", EDBG_ISTEP_HOST},
}); // end - array initialization

constexpr std::uint16_t EDBG_FIRST_ISTEP_NUM = 0;
constexpr std::uint16_t EDBG_LAST_ISTEP_NUM = 21;
constexpr std::uint16_t EDBG_INVALID_POSITION = 0xFFFF;
constexpr std::uint16_t EDBG_NUMBER_OF_ISTEPS = ISteps.size();
constexpr std::uint16_t EDBG_INVALID_ISTEP_NUM = 0xFFFF;

constexpr std::optional<std::string_view> getStepName(uint16_t major,
                                                      uint16_t minor)
{
    auto it = std::ranges::find_if(ISteps, [=](auto& s) {
        return s.major == major && s.minor == minor;
    });
    if (it != ISteps.end())
    {
        return it->name;
    }
    return std::nullopt;
}

constexpr bool isValid(uint8_t majorNum)
{
    return std::ranges::any_of(ISteps, [=](auto& s) {
        return s.major == majorNum;
    });
}

constexpr bool isValid(std::string_view name)
{
    return std::ranges::any_of(ISteps, [=](auto& s) { return s.name == name; });
}

constexpr IStepDestination getDestination(uint16_t majorNum, uint16_t minorNum)
{
    if (auto it = std::ranges::find_if(ISteps,
                                       [=](const IStep& step) {
                                           return step.major == majorNum &&
                                                  step.minor == minorNum;
                                       });
        it != ISteps.end())
    {
        return it->dest;
    }

    return IStepDestination::EDBG_ISTEP_INVALID_DESTINATION;
}
// ---------------------------------------------------------------------
// Get the position (index) of the last minor number for a given major
// ---------------------------------------------------------------------
constexpr std::uint16_t getPosLastMinorNumber(std::uint16_t majorNum)
{
    if (majorNum > EDBG_LAST_ISTEP_NUM)
    {
        return EDBG_INVALID_POSITION;
    }

    std::uint16_t position = EDBG_INVALID_POSITION;

    for (std::uint16_t row = 0; row < EDBG_NUMBER_OF_ISTEPS; ++row)
    {
        if (ISteps[row].major == majorNum)
        {
            // If this is the last row or next row has a greater major number,
            // current row marks the last minor number for this major.
            if ((row + 1 == EDBG_NUMBER_OF_ISTEPS) ||
                (ISteps[row + 1].major > majorNum))
            {
                position = row;
                break;
            }
        }
    }

    return position;
}

// ---------------------------------------------------------------------
// Get the position (index) of the first minor number for a given major
// ---------------------------------------------------------------------
constexpr std::uint16_t getPosFirstMinorNumber(std::uint16_t majorNum)
{
    if (majorNum > EDBG_LAST_ISTEP_NUM)
    {
        return EDBG_INVALID_POSITION;
    }

    for (std::uint16_t row = 0; row < EDBG_NUMBER_OF_ISTEPS; ++row)
    {
        if (ISteps[row].major == majorNum)
        {
            return row;
        }
    }

    return EDBG_INVALID_POSITION;
}

// ---------------------------------------------------------------------
// Get the major and minor number for the given istep name
// ---------------------------------------------------------------------
constexpr bool getIStepNumber(const std::string& istepName, uint16_t& major,
                              uint16_t& minor)
{
    using namespace istep_table;

    major = EDBG_INVALID_ISTEP_NUM;
    minor = EDBG_INVALID_ISTEP_NUM;

    for (const auto& step : ISteps)
    {
        if (istepName == step.name)
        {
            major = step.major;
            minor = step.minor;
            return true;
        }
    }
    return false;
}
// ---------------------------------------------------------------------
// Get the position (index) of the istep name
// ---------------------------------------------------------------------
constexpr std::uint16_t getPosition(std::string_view istepName)
{
    for (std::uint16_t row = 0; row < EDBG_NUMBER_OF_ISTEPS; ++row)
    {
        if (ISteps[row].name == istepName)
        {
            return row;
        }
    }
    return EDBG_INVALID_POSITION;
}

// ---------------------------------------------------------------------
// Get the minor number for a given istep table position
// ---------------------------------------------------------------------
constexpr std::uint16_t getIStepMinorNumber(std::uint16_t position)
{
    if (position < EDBG_NUMBER_OF_ISTEPS)
    {
        return ISteps[position].minor;
    }

    return EDBG_INVALID_ISTEP_NUM;
}
} // namespace istep_table
