#include <errno.h>

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <climits>
#include <cstring>
#include <cstdio>

#include "unit_drumlogue.h"

#include "Heavy_EQVU.h"

#ifndef HV_MSGPOOLSIZE
 #define HV_MSGPOOLSIZE 1
#endif
#ifndef HV_INPUTQSIZE
 #define HV_INPUTQSIZE 1
#endif
#ifndef HV_OUTPUTQSIZE
 #define HV_OUTPUTQSIZE 0
#endif
static HeavyContextInterface* hvContext;

typedef enum {
    // if platform name in [loguesdkv1, nts1mkii, nts3kaoss]
    // endif
    k_user_unit_param_id1,
    k_user_unit_param_id2,
    k_user_unit_param_id3,
    k_user_unit_param_id4,
    k_user_unit_param_id5,
    k_user_unit_param_id6,
    k_user_unit_param_id7,
    k_user_unit_param_id8,
    k_user_unit_param_id9,
    k_user_unit_param_id10,
    k_user_unit_param_id11,
    k_user_unit_param_id12,
    k_user_unit_param_id13,
    k_user_unit_param_id14,
    k_user_unit_param_id15,
    k_user_unit_param_id16,
    k_user_unit_param_id17,
    k_user_unit_param_id18,
    k_user_unit_param_id19,
    k_user_unit_param_id20,
    k_user_unit_param_id21,
    k_user_unit_param_id22,
    k_user_unit_param_id23,
    k_user_unit_param_id24,
    k_num_user_unit_param_id
} user_unit_param_id_t;

static unit_runtime_desc_t s_desc;
static int32_t params[k_num_user_unit_param_id];
static int32_t _1_INPUT;
static int32_t _2_DRY;
static int32_t _3_WET;
static int32_t _4_OUTPUT;
static int32_t _5_HzLF;
static float _6_QLF_f;
static int32_t _8_dBLF;
static int32_t _9_HzLMF;
static float _10_QLMF2_f;
static float _11_QLMF2_f;
static int32_t _12_dBLMF;
static int32_t _13_HzHMF;
static float _14_QHMF2_f;
static float _15_QHMF2_f;
static int32_t _16_dBHMF;
static int32_t _17_HzHF;
static float _18_QHF_f;
static int32_t _20_dBHF;
static bool param_dirty[20];
#ifdef PRINTHOOK
// This is only for debugging purposes
#define PRINTBUFSIZE 20
static char printBuf[PRINTBUFSIZE][32];
static int32_t printBufIndex = 0;

static void printHook(HeavyContextInterface *c, const char *printName, const char *str, const HvMessage *m) {
    strncpy(printBuf[printBufIndex], str, 32);
    printBufIndex = (printBufIndex + 1) % PRINTBUFSIZE;
}
/*
  the printBuf[] can be used in unit_get_param_str_value().
  use [print] object in the patch or
  use printHook() like below to print your C variable
  {
      char s[32];
      std::snprintf(s, 32, "%d", your_variable);
      printHook(hvContext, "", s, NULL);
  }
 */
#endif

__unit_callback int8_t unit_init(const unit_runtime_desc_t * desc)
{
    _1_INPUT = 0;
    params[k_user_unit_param_id1] = _1_INPUT;
    param_dirty[k_user_unit_param_id1] = true;
    _2_DRY = 0;
    params[k_user_unit_param_id2] = _2_DRY;
    param_dirty[k_user_unit_param_id2] = true;
    _3_WET = 10;
    params[k_user_unit_param_id3] = _3_WET;
    param_dirty[k_user_unit_param_id3] = true;
    _4_OUTPUT = 0;
    params[k_user_unit_param_id4] = _4_OUTPUT;
    param_dirty[k_user_unit_param_id4] = true;
    _5_HzLF = 50;
    params[k_user_unit_param_id5] = _5_HzLF;
    param_dirty[k_user_unit_param_id5] = true;
    _6_QLF_f = 0.707;
    params[k_user_unit_param_id6] = 100;
    param_dirty[k_user_unit_param_id6] = true;
    _8_dBLF = 0;
    params[k_user_unit_param_id8] = _8_dBLF;
    param_dirty[k_user_unit_param_id8] = true;
    _9_HzLMF = 350;
    params[k_user_unit_param_id9] = _9_HzLMF;
    param_dirty[k_user_unit_param_id9] = true;
    _10_QLMF2_f = 0.707;
    params[k_user_unit_param_id10] = 0;
    param_dirty[k_user_unit_param_id10] = true;
    _11_QLMF2_f = 0.707;
    params[k_user_unit_param_id11] = 25;
    param_dirty[k_user_unit_param_id11] = true;
    _12_dBLMF = 0;
    params[k_user_unit_param_id12] = _12_dBLMF;
    param_dirty[k_user_unit_param_id12] = true;
    _13_HzHMF = 3000;
    params[k_user_unit_param_id13] = _13_HzHMF;
    param_dirty[k_user_unit_param_id13] = true;
    _14_QHMF2_f = 0.707;
    params[k_user_unit_param_id14] = 0;
    param_dirty[k_user_unit_param_id14] = true;
    _15_QHMF2_f = 0.707;
    params[k_user_unit_param_id15] = 25;
    param_dirty[k_user_unit_param_id15] = true;
    _16_dBHMF = 0;
    params[k_user_unit_param_id16] = _16_dBHMF;
    param_dirty[k_user_unit_param_id16] = true;
    _17_HzHF = 12000;
    params[k_user_unit_param_id17] = _17_HzHF;
    param_dirty[k_user_unit_param_id17] = true;
    _18_QHF_f = 0.707;
    params[k_user_unit_param_id18] = 100;
    param_dirty[k_user_unit_param_id18] = true;
    _20_dBHF = 0;
    params[k_user_unit_param_id20] = _20_dBHF;
    param_dirty[k_user_unit_param_id20] = true;

    if (!desc)
      return k_unit_err_undef;

    if (desc->target != unit_header.common.target)
      return k_unit_err_target;

    if (!UNIT_API_IS_COMPAT(desc->api))
      return k_unit_err_api_version;

    if (desc->samplerate != 48000)
      return k_unit_err_samplerate;

    if (desc->input_channels != 2 || desc->output_channels < 2)
      return k_unit_err_geometry;

#ifdef RENDER_HALF
    hvContext = hv_EQVU_new_with_options(24000, HV_MSGPOOLSIZE, HV_INPUTQSIZE, HV_OUTPUTQSIZE);
#else
    hvContext = hv_EQVU_new_with_options(48000, HV_MSGPOOLSIZE, HV_INPUTQSIZE, HV_OUTPUTQSIZE);
#endif

    s_desc = *desc;

    return k_unit_err_none;
}

__unit_callback void unit_render(const float * in, float * out, uint32_t frames)
{
#ifdef RENDER_HALF
    float buffer[frames];
    static float last_buf_l = 0.f;
    static float last_buf_r = 0.f;
    float * __restrict p = buffer;
    float * __restrict y = out;
    const float * y_e = y + 2 * frames;
#endif

    if (param_dirty[k_user_unit_param_id1]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__1_INPUT, _1_INPUT)) {
            param_dirty[k_user_unit_param_id1] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id2]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__2_DRY, _2_DRY)) {
            param_dirty[k_user_unit_param_id2] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id3]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__3_WET, _3_WET)) {
            param_dirty[k_user_unit_param_id3] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id4]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__4_OUTPUT, _4_OUTPUT)) {
            param_dirty[k_user_unit_param_id4] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id5]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__5_HZLF, _5_HzLF)) {
            param_dirty[k_user_unit_param_id5] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id6]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__6_QLF_F, _6_QLF_f)) {
            param_dirty[k_user_unit_param_id6] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id8]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__8_DBLF, _8_dBLF)) {
            param_dirty[k_user_unit_param_id8] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id9]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__9_HZLMF, _9_HzLMF)) {
            param_dirty[k_user_unit_param_id9] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id10]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__10_QLMF2_F, _10_QLMF2_f)) {
            param_dirty[k_user_unit_param_id10] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id11]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__11_QLMF2_F, _11_QLMF2_f)) {
            param_dirty[k_user_unit_param_id11] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id12]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__12_DBLMF, _12_dBLMF)) {
            param_dirty[k_user_unit_param_id12] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id13]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__13_HZHMF, _13_HzHMF)) {
            param_dirty[k_user_unit_param_id13] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id14]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__14_QHMF2_F, _14_QHMF2_f)) {
            param_dirty[k_user_unit_param_id14] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id15]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__15_QHMF2_F, _15_QHMF2_f)) {
            param_dirty[k_user_unit_param_id15] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id16]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__16_DBHMF, _16_dBHMF)) {
            param_dirty[k_user_unit_param_id16] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id17]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__17_HZHF, _17_HzHF)) {
            param_dirty[k_user_unit_param_id17] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id18]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__18_QHF_F, _18_QHF_f)) {
            param_dirty[k_user_unit_param_id18] = false;
        }
    }
    if (param_dirty[k_user_unit_param_id20]) {
        if (hv_sendFloatToReceiver(hvContext, HV_EQVU_PARAM_IN__20_DBHF, _20_dBHF)) {
            param_dirty[k_user_unit_param_id20] = false;
        }
    }
#ifdef RENDER_HALF
    hv_processInlineInterleaved(hvContext, (float *) in, buffer, frames >> 1);
    for(int i = 0; y!= y_e; i++) {
        if (i & 1) {
            last_buf_l = *p++;
            last_buf_r = *p++;
            *(y++) = last_buf_l;
            *(y++) = last_buf_r;
        } else {
            *(y++) = (*p + last_buf_l) * 0.5;
            *(y++) = (*p + last_buf_r) * 0.5;
        }
    }
#else
    hv_processInlineInterleaved(hvContext, (float *) in, out, frames);
#endif
}

__unit_callback void unit_set_param_value(uint8_t id, int32_t value)
{

    params[id] = value;
    param_dirty[id] = true;
    switch(id){
    case k_user_unit_param_id1:
        _1_INPUT = value;
        break;
    case k_user_unit_param_id2:
        _2_DRY = value;
        break;
    case k_user_unit_param_id3:
        _3_WET = value;
        break;
    case k_user_unit_param_id4:
        _4_OUTPUT = value;
        break;
    case k_user_unit_param_id5:
        _5_HzLF = value;
        break;
    case k_user_unit_param_id6:
        _6_QLF_f = 0.1 + value * 0.00607;
        break;
    case k_user_unit_param_id8:
        _8_dBLF = value;
        break;
    case k_user_unit_param_id9:
        _9_HzLMF = value;
        break;
    case k_user_unit_param_id10:
        _10_QLMF2_f = 0.707 + value * 0.12293;
        break;
    case k_user_unit_param_id11:
        _11_QLMF2_f = 0.107 + value * 0.024;
        break;
    case k_user_unit_param_id12:
        _12_dBLMF = value;
        break;
    case k_user_unit_param_id13:
        _13_HzHMF = value;
        break;
    case k_user_unit_param_id14:
        _14_QHMF2_f = 0.707 + value * 0.12293;
        break;
    case k_user_unit_param_id15:
        _15_QHMF2_f = 0.107 + value * 0.024;
        break;
    case k_user_unit_param_id16:
        _16_dBHMF = value;
        break;
    case k_user_unit_param_id17:
        _17_HzHF = value;
        break;
    case k_user_unit_param_id18:
        _18_QHF_f = 0.1 + value * 0.00607;
        break;
    case k_user_unit_param_id20:
        _20_dBHF = value;
        break;
    default:
      break;
    }
}

__unit_callback int32_t unit_get_param_value(uint8_t id) {
    return params[id];
}



__unit_callback void unit_teardown() {
}

__unit_callback void unit_reset() {
}

__unit_callback void unit_resume() {
}

__unit_callback void unit_suspend() {
}

static void format_number(char *p_str, size_t len, float f, const char *format) {
    char formatstr[8];

    std::snprintf(p_str, len, "%.3f", f);
    char *p = p_str + strlen(p_str) - 1;
    while (p > p_str && *p == '0') {
        p--;
    }
    if (*p == '.') {
        p--;
    }
    std::strncpy(formatstr, (format ? format : ""), 8); // allow null format
    std::strncpy(++p, formatstr, 8);
}

static const char *formatstr(uint8_t type) {
    switch(type) {
    case k_unit_param_type_percent:
        return "%";
    case k_unit_param_type_db:
        return "db";
    case k_unit_param_type_cents:
        return "C";
    case k_unit_param_type_hertz:
        return "Hz";
    case k_unit_param_type_khertz:
        return "kHz";
    case k_unit_param_type_msec:
        return "ms";
    case k_unit_param_type_sec:
        return "s";
    default:
        break;
    }
    return nullptr;
}

__unit_callback const char * unit_get_param_str_value(uint8_t id, int32_t value \
) {
    static char param_str[32];

    switch(id) {
    case k_user_unit_param_id6: {
        float fvalue = 0.1 + value * (0.707 - 0.1) / 100;
        format_number(param_str, sizeof(param_str), fvalue, formatstr(k_unit_param_type_none));
        return param_str;
        break;
    }
    case k_user_unit_param_id10: {
        float fvalue = 0.707 + value * (13.0 - 0.707) / 100;
        format_number(param_str, sizeof(param_str), fvalue, formatstr(k_unit_param_type_none));
        return param_str;
        break;
    }
    case k_user_unit_param_id11: {
        float fvalue = 0.107 + value * (2.507 - 0.107) / 100;
        format_number(param_str, sizeof(param_str), fvalue, formatstr(k_unit_param_type_none));
        return param_str;
        break;
    }
    case k_user_unit_param_id14: {
        float fvalue = 0.707 + value * (13.0 - 0.707) / 100;
        format_number(param_str, sizeof(param_str), fvalue, formatstr(k_unit_param_type_none));
        return param_str;
        break;
    }
    case k_user_unit_param_id15: {
        float fvalue = 0.107 + value * (2.507 - 0.107) / 100;
        format_number(param_str, sizeof(param_str), fvalue, formatstr(k_unit_param_type_none));
        return param_str;
        break;
    }
    case k_user_unit_param_id18: {
        float fvalue = 0.1 + value * (0.707 - 0.1) / 100;
        format_number(param_str, sizeof(param_str), fvalue, formatstr(k_unit_param_type_none));
        return param_str;
        break;
    }
#ifdef PRINTHOOK
// edit the case number and change the variable type in the corresponding
// parameter entry in header.c to:
// k_unit_param_type_strings
    case k_user_unit_param_id_for_debug: {
        int index = (value + PRINTBUFSIZE - printBufIndex) % PRINTBUFSIZE;
        return printBuf[index];
        break;
    }
#endif
    default:
        break;
    }
    return nullptr;
}

__unit_callback void unit_set_tempo(uint32_t tempo) {
}

