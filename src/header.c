/*
 *  File: header.c
 *
 *  drumlogue unit header definition
 *
 */

#include "unit_drumlogue.h"

#ifndef PROJECT_DEV_ID
 #define PROJECT_DEV_ID (0x0U)
#endif

#ifndef PROJECT_UNIT_ID
 #define PROJECT_UNIT_ID (0x0U)
#endif

const __unit_header drumlogue_unit_header_t unit_header = {
  .common = {
    .header_size = sizeof(unit_header_t),
    .target = UNIT_TARGET_PLATFORM | k_unit_module_delfx,
    .api = UNIT_API_VERSION,
    .dev_id = PROJECT_DEV_ID,
    .unit_id = PROJECT_UNIT_ID,
    .version = 0x00010000U,
    .name = "EQVU",
    .num_params = 20,
    .params = {
        // Format:
        // min, max, center, default, type, frac. bits, frac. mode, <reserved>, name
        // Page 1
        // Page 1
        {-12, 12, 0, 0, k_unit_param_type_none, 0, 0, 0, {"INPUT"}},
        {0, 10, 0, 0, k_unit_param_type_none, 0, 0, 0, {"DRY"}},
        {0, 10, 10, 10, k_unit_param_type_none, 0, 0, 0, {"WET"}},
        {-20, 20, 0, 0, k_unit_param_type_none, 0, 0, 0, {"OUTPUT"}},
        // Page 2
        {30, 90, 50, 50, k_unit_param_type_none, 0, 0, 0, {"HzLF"}},
        {0, 100, 100, 100, k_unit_param_type_strings, 10, 1, 0, {"QLF"}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {-9, 9, 0, 0, k_unit_param_type_none, 0, 0, 0, {"dBLF"}},
        // Page 3
        {100, 1100, 350, 350, k_unit_param_type_none, 0, 0, 0, {"HzLMF"}},
        {0, 100, 0, 0, k_unit_param_type_strings, 10, 1, 0, {"QLMF2"}},
        {0, 100, 25, 25, k_unit_param_type_strings, 10, 1, 0, {"QLMF2"}},
        {-18, 18, 0, 0, k_unit_param_type_none, 0, 0, 0, {"dBLMF"}},
        // Page 4
        {400, 9000, 3000, 3000, k_unit_param_type_none, 0, 0, 0, {"HzHMF"}},
        {0, 100, 0, 0, k_unit_param_type_strings, 10, 1, 0, {"QHMF2"}},
        {0, 100, 25, 25, k_unit_param_type_strings, 10, 1, 0, {"QHMF2"}},
        {-18, 18, 0, 0, k_unit_param_type_none, 0, 0, 0, {"dBHMF"}},
        // Page 5
        {8000, 20000, 12000, 12000, k_unit_param_type_none, 0, 0, 0, {"HzHF"}},
        {0, 100, 100, 100, k_unit_param_type_strings, 10, 1, 0, {"QHF"}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {-9, 9, 0, 0, k_unit_param_type_none, 0, 0, 0, {"dBHF"}},
        // Page 6
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}},
        {0, 0, 0, 0, k_unit_param_type_none, 0, 0, 0, {""}}},
  }
};