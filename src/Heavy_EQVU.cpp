/**
 * Copyright (c) 2026 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_EQVU.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_EQVU *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_EQVU_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_EQVU));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_EQVU(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_EQVU_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_EQVU));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_EQVU(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_EQVU_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_EQVU();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_EQVU::Heavy_EQVU(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sLine_init(&sLine_07i2LSrB);
  numBytes += sLine_init(&sLine_B9aSsYUg);
  numBytes += sLine_init(&sLine_TBFHImbf);
  numBytes += sLine_init(&sLine_RmoWLgur);
  numBytes += sLine_init(&sLine_i2DcOZR4);
  numBytes += sBiquad_init(&sBiquad_s_0sK5s8YV);
  numBytes += sLine_init(&sLine_pWftslqy);
  numBytes += sLine_init(&sLine_XV0zhI7q);
  numBytes += sLine_init(&sLine_2E0um0D6);
  numBytes += sLine_init(&sLine_Gjkvrkzc);
  numBytes += sLine_init(&sLine_ChLD7RUV);
  numBytes += sBiquad_init(&sBiquad_s_lUrlw0s4);
  numBytes += sLine_init(&sLine_Q0OuA4w6);
  numBytes += sLine_init(&sLine_9wCbqQsf);
  numBytes += sLine_init(&sLine_ajwFzW5o);
  numBytes += sLine_init(&sLine_Js6prR57);
  numBytes += sLine_init(&sLine_WLr4bZdA);
  numBytes += sBiquad_init(&sBiquad_s_t4TIwFUX);
  numBytes += sLine_init(&sLine_Tsd4yQYt);
  numBytes += sLine_init(&sLine_VNH5c4Lc);
  numBytes += sLine_init(&sLine_Hu6BovKt);
  numBytes += sLine_init(&sLine_ULEoEQYL);
  numBytes += sLine_init(&sLine_8HprGu87);
  numBytes += sBiquad_init(&sBiquad_s_VZKUzHJi);
  numBytes += sLine_init(&sLine_SmX8RxTU);
  numBytes += sLine_init(&sLine_QF0fweuu);
  numBytes += sLine_init(&sLine_VYMCtIzC);
  numBytes += sLine_init(&sLine_NzEar4Sy);
  numBytes += sLine_init(&sLine_bsCYE9U2);
  numBytes += sBiquad_init(&sBiquad_s_jdi2ACUP);
  numBytes += sLine_init(&sLine_dqvRdwkB);
  numBytes += sLine_init(&sLine_9jjU45KP);
  numBytes += sLine_init(&sLine_XO4nZ9nT);
  numBytes += sLine_init(&sLine_JzpBomMY);
  numBytes += sLine_init(&sLine_MfLY8jSv);
  numBytes += sBiquad_init(&sBiquad_s_xhf849N3);
  numBytes += sLine_init(&sLine_Jzo9ZoBX);
  numBytes += sLine_init(&sLine_312HIS1r);
  numBytes += sLine_init(&sLine_uwQtnLZr);
  numBytes += sLine_init(&sLine_dlYb6O0Y);
  numBytes += sLine_init(&sLine_9Y0TLkNS);
  numBytes += sBiquad_init(&sBiquad_s_XDpsTOw4);
  numBytes += sLine_init(&sLine_5RuuDxwH);
  numBytes += sLine_init(&sLine_qcQlh37Y);
  numBytes += sLine_init(&sLine_9bKSPuhR);
  numBytes += sLine_init(&sLine_o8GQ3X0N);
  numBytes += sLine_init(&sLine_gIFdyY3a);
  numBytes += sBiquad_init(&sBiquad_s_OZ1pbjAn);
  numBytes += cVar_init_f(&cVar_lQiHyA23, 0.0f);
  numBytes += cVar_init_f(&cVar_wlNqMSS0, 0.0f);
  numBytes += cVar_init_f(&cVar_b9GoW53K, 0.0f);
  numBytes += cVar_init_f(&cVar_vnz76X2m, 0.0f);
  numBytes += cVar_init_f(&cVar_KksTsWGQ, 0.0f);
  numBytes += cVar_init_f(&cVar_hLJkrFBj, 0.0f);
  numBytes += cVar_init_f(&cVar_3PKKi0fn, 0.0f);
  numBytes += cVar_init_f(&cVar_xzQRx44A, 0.0f);
  numBytes += cVar_init_f(&cVar_SbTpAWOI, 0.0f);
  numBytes += cVar_init_f(&cVar_mhNfs6Ok, 0.0f);
  numBytes += cVar_init_f(&cVar_1i2jjkhP, 0.0f);
  numBytes += cVar_init_f(&cVar_775QCHe0, 0.0f);
  numBytes += cVar_init_f(&cVar_3rYVtvhw, 0.0f);
  numBytes += cExpr_init(&cExpr_cQ0aQp8C, &Heavy_EQVU::cExpr_cQ0aQp8C_evaluate);
  numBytes += sVarf_init(&sVarf_i1L9GUcR, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LpSaxQvy, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_FAqrC730, 0.0f);
  numBytes += cExpr_init(&cExpr_zMVqFJ7E, &Heavy_EQVU::cExpr_zMVqFJ7E_evaluate);
  numBytes += sVarf_init(&sVarf_JYf7ganH, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_lKEbVOPI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_Tu0Iupx2, 0.0f);
  numBytes += cVar_init_f(&cVar_RITjtKXj, 0.0f);
  numBytes += cVar_init_f(&cVar_0eSExtj4, 0.0f);
  numBytes += cVar_init_f(&cVar_2WhDFwrE, 0.0f);
  numBytes += cVar_init_f(&cVar_uEyZjZdS, 0.0f);
  numBytes += cVar_init_f(&cVar_f1VExZYb, 0.0f);
  numBytes += cBinop_init(&cBinop_vkxTA1vw, 1.0f); // __pow
  numBytes += cIf_init(&cIf_QtfdxqR6, false);
  numBytes += cBinop_init(&cBinop_PrJAUV80, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_aJwL7Hz3, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0CSbIDf5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HZghZ6PH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_zWITyrhA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ilwWKYwx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sObXt1gV, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_plg3Fchv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Ql7xtS1c, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3UNOPy5b, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Sf73Fhxn, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_DAlKzpX6, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_aPspS9Nk, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_T7yg2LWD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KW3qZBiA, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_2N8h3Rjx, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tinRPBQL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_wbgqITD3, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_4X4TuGKu, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sqdvvwd4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_me8yjv1n, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2su89cIt, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4CEcfvbK, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_qHw5z0sC, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_tlvVFg0c, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_4dZ0z7jV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_desAePrT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2XTUUy7h, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_GbjVDcoY, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_FIph4gBx, 0.0f);
  numBytes += cVar_init_f(&cVar_zxk6crO2, 0.0f);
  numBytes += cVar_init_f(&cVar_pxaFLBkr, 0.0f);
  numBytes += cVar_init_f(&cVar_bMhzyBEs, 0.0f);
  numBytes += cBinop_init(&cBinop_7eGu9Tkq, 1.0f); // __pow
  numBytes += cIf_init(&cIf_rZ2s1i1a, false);
  numBytes += cBinop_init(&cBinop_4SsFkDGc, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nHxOFFlS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wrixMDYm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ScixiduJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_U4mIpSIl, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_u4BGljtq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Z01FQcEM, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_kHedcZsJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_jY1zeAJP, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_IZbQiRuD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JmMOPkbB, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_RKXXXoUs, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_KFY8ocMj, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_mfaepOzG, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_O23q1gZw, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_aD7rZgSR, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RR2zzGSm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_WpNTuziH, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_pKsMjciU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JaRBnFfN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_BHmWAETm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RyS309MK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rLFGEzuI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_HC38VeWQ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_yYHqBjct, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_80Vo8q50, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_EDR4iksm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hEDYJZBG, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_N2RRgtB0, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_FgG3kXoa, 0.0f);
  numBytes += cVar_init_f(&cVar_ifTeqTKC, 0.0f);
  numBytes += cVar_init_f(&cVar_N4RgWesM, 0.0f);
  numBytes += cVar_init_f(&cVar_5CSAM909, 0.0f);
  numBytes += cBinop_init(&cBinop_VAhgAhMP, 1.0f); // __pow
  numBytes += cIf_init(&cIf_6igvv9s5, false);
  numBytes += cBinop_init(&cBinop_wF0cNdNd, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_LohmcciK, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_FmjKRXuf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yCIJwZlS, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_IpeeDuNR, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Ei1BKubA, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nfU78vGf, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_g8Oedr9r, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_CIzUXlm6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Gm6LdMZJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nFxIN4pe, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_ZjJjqqXg, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_5iLhl0aE, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_JZuL7JNh, 0.0f);
  numBytes += cVar_init_f(&cVar_Yzw3qUPi, 0.0f);
  numBytes += cVar_init_f(&cVar_HUyJTvUy, 0.0f);
  numBytes += cVar_init_f(&cVar_X9yLqaPs, 0.0f);
  numBytes += cBinop_init(&cBinop_XuLL6Pqf, 1.0f); // __pow
  numBytes += cIf_init(&cIf_BfmVAjJo, false);
  numBytes += cBinop_init(&cBinop_6hSTVR1C, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_poJ6crPg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gDIgeeTO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_p9WkTM90, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qRgefdjC, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Sl6X4063, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_uZTlBfN3, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_6XUPApFz, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_282J31Bh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_sypZmdR4, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_CfxnBY0N, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_FdHjBklj, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_L1cxdLQ7, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_c8oijmh5, 0.0f);
  numBytes += cVar_init_f(&cVar_ODlgcnSi, 0.0f);
  numBytes += cVar_init_f(&cVar_k60gT1g6, 0.0f);
  numBytes += cVar_init_f(&cVar_ID7lTvNB, 0.0f);
  numBytes += cBinop_init(&cBinop_8gisnOax, 1.0f); // __pow
  numBytes += cIf_init(&cIf_brp4xAbm, false);
  numBytes += cBinop_init(&cBinop_0hcAj6ej, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_nJz2NH6Y, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gJ0xHWZ2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_rBzQ4UVb, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_1kU05QDa, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Lmq0IexL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_TzDkalyP, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_wF1xj8F3, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_sTEijqvf, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_z3v5XmsL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_0NAHS5rG, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Eu4y6L1X, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_pQc5RPRI, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_Ie87y4sx, 0.0f);
  numBytes += cVar_init_f(&cVar_yFRteV1H, 0.0f);
  numBytes += cVar_init_f(&cVar_yRl3brxX, 0.0f);
  numBytes += cVar_init_f(&cVar_dFXOpnjv, 0.0f);
  numBytes += cBinop_init(&cBinop_nRQiRX59, 1.0f); // __pow
  numBytes += cIf_init(&cIf_FaYe0fWf, false);
  numBytes += cBinop_init(&cBinop_QSxPZBnF, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_O79db6vu, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_V59hPvtY, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Jq8K51ut, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_tQcPHpUM, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VwqSwGHU, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3Qi8as6b, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_a1R4gMFR, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Ja8edl1H, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Ktyfh8NJ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DyTgeiMq, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_6BeQ8pw9, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_LSf21Dhc, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_UWn17TPf, 0.0f);
  numBytes += cVar_init_f(&cVar_3CNyzwxI, 0.0f);
  numBytes += cVar_init_f(&cVar_h4AeYOq5, 0.0f);
  numBytes += cVar_init_f(&cVar_AP3bOOXW, 0.0f);
  numBytes += cBinop_init(&cBinop_gczueJs3, 1.0f); // __pow
  numBytes += cIf_init(&cIf_Z8uzZ9k2, false);
  numBytes += cBinop_init(&cBinop_KBMUfp4W, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6nTkdUyu, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HbARb3Fi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_lQ4MNKqQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5sHsOlKh, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_6qieZ5cQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KLzI3GeU, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_0xoVagKz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2OVnXJo7, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_eb5r1OBH, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_a43fyanO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_gTiGT0RL, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_A7jZ25tF, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_jFlOPpoT, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3Bij3Zc1, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_SGD09RoN, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_1yPExRa8, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_adsWdYMC, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_utmeSQSZ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_eetHBewC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_oYSfJxXs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qspjI28f, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_v2Rxa0rE, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_cZFB24z6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ivUA4HDV, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Oehz3O34, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_obhYkSlr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_THkebxqm, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_ytVkKniE, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_NxG0dFJy, 0.0f);
  numBytes += cVar_init_f(&cVar_2WtLGqXN, 0.0f);
  numBytes += cVar_init_f(&cVar_H6pXUSEH, 0.0f);
  numBytes += cVar_init_f(&cVar_Mq0sbrTF, 0.0f);
  numBytes += cBinop_init(&cBinop_frBTuPU3, 1.0f); // __pow
  numBytes += cIf_init(&cIf_ckyP8MQb, false);
  numBytes += cBinop_init(&cBinop_3JLckPAI, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_7pek8NyC, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_2SSDTxHV, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_uSnypcHv, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_KZXyFqGG, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_l4sn48w8, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_RBaDdYnt, 0.0f); // __pow
  numBytes += cBinop_init(&cBinop_WrHubdO6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Y8PmFptR, 44100.0f); // __div
  numBytes += cBinop_init(&cBinop_Op0ojnV9, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hSfmvPuB, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_H5Qv41uo, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_u6arm1bp, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_YZeKtUXr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Ky3XolkD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_X1YsNFwQ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Aibpv7CU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_veDSBcoi, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_EFygSdUD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_3s7rWiOr, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_tTstG7vn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_7kCrOOZd, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_GyWGf9kf, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_n6npjMPp, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BEp2RdKC, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_bKdxlcP5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_VZNNY3am, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_knTyJoBI, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_OXBfFWM0, 0.0f); // __sub
  numBytes += sVarf_init(&sVarf_Y3eudSD9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_0qkkezjA, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_98v21Rs3, &Heavy_EQVU::cExpr_98v21Rs3_evaluate);
  numBytes += sVarf_init(&sVarf_uT7nzCwS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_hmLz1YKm, 0.0f, 0.0f, false);
  numBytes += cExpr_init(&cExpr_rxXtxhsK, &Heavy_EQVU::cExpr_rxXtxhsK_evaluate);
  numBytes += cVar_init_f(&cVar_BiXRtzvn, 0.0f);
  numBytes += cVar_init_f(&cVar_wyyRsJ0s, 0.0f);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_EQVU::~Heavy_EQVU() {
  cExpr_free(&cExpr_cQ0aQp8C);
  cExpr_free(&cExpr_zMVqFJ7E);
  cExpr_free(&cExpr_98v21Rs3);
  cExpr_free(&cExpr_rxXtxhsK);
}

HvTable *Heavy_EQVU::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_EQVU::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x6C094A05: { // 1001-wsin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_4deXkcYD_sendMessage);
      break;
    }
    case 0x1D24AC9F: { // _10_QLMF2_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Tm5VYnRQ_sendMessage);
      break;
    }
    case 0x7194B67C: { // _11_QLMF2_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_h4clFQA3_sendMessage);
      break;
    }
    case 0xB8C98687: { // _12_dBLMF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qZb1J4hd_sendMessage);
      break;
    }
    case 0x8451A779: { // _13_HzHMF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_F3DTW6YK_sendMessage);
      break;
    }
    case 0x1D1507D4: { // _14_QHMF2_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_e8MQOPeJ_sendMessage);
      break;
    }
    case 0xF6147049: { // _15_QHMF2_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_x3rcJta4_sendMessage);
      break;
    }
    case 0x6D8F80F2: { // _16_dBHMF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NgqcEoA0_sendMessage);
      break;
    }
    case 0xE9051A9D: { // _17_HzHF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Ou68a73T_sendMessage);
      break;
    }
    case 0xBFFB11FC: { // _18_QHF_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zbH72BFA_sendMessage);
      break;
    }
    case 0x5A63170A: { // _1_INPUT
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dvULlMn8_sendMessage);
      break;
    }
    case 0x5E915D93: { // _20_dBHF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_AohqoJ6d_sendMessage);
      break;
    }
    case 0x49127601: { // _2_DRY
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bIEZRauY_sendMessage);
      break;
    }
    case 0x685033DE: { // _3_WET
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xNoCCLj4_sendMessage);
      break;
    }
    case 0xAC813ECB: { // _4_OUTPUT
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Cyj5dK4W_sendMessage);
      break;
    }
    case 0x158602FD: { // _5_HzLF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_w9NHXTKI_sendMessage);
      break;
    }
    case 0xCC4785E3: { // _6_QLF_f
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_M5wJrTIH_sendMessage);
      break;
    }
    case 0x9D2964A6: { // _8_dBLF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_pkwarQFB_sendMessage);
      break;
    }
    case 0xCD86A9DF: { // _9_HzLMF
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_YP2lyKct_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6yyh0n9W_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_EQVU::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "_10_QLMF2_f";
        info->hash = 0x1D24AC9F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.707f;
        info->maxVal = 13.0f;
        info->defaultVal = 0.707f;
        break;
      }
      case 1: {
        info->name = "_11_QLMF2_f";
        info->hash = 0x7194B67C;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.107f;
        info->maxVal = 2.507f;
        info->defaultVal = 0.707f;
        break;
      }
      case 2: {
        info->name = "_12_dBLMF";
        info->hash = 0xB8C98687;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -18.0f;
        info->maxVal = 18.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 3: {
        info->name = "_13_HzHMF";
        info->hash = 0x8451A779;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 400.0f;
        info->maxVal = 9000.0f;
        info->defaultVal = 3000.0f;
        break;
      }
      case 4: {
        info->name = "_14_QHMF2_f";
        info->hash = 0x1D1507D4;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.707f;
        info->maxVal = 13.0f;
        info->defaultVal = 0.707f;
        break;
      }
      case 5: {
        info->name = "_15_QHMF2_f";
        info->hash = 0xF6147049;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.107f;
        info->maxVal = 2.507f;
        info->defaultVal = 0.707f;
        break;
      }
      case 6: {
        info->name = "_16_dBHMF";
        info->hash = 0x6D8F80F2;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -18.0f;
        info->maxVal = 18.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 7: {
        info->name = "_17_HzHF";
        info->hash = 0xE9051A9D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 8000.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 12000.0f;
        break;
      }
      case 8: {
        info->name = "_18_QHF_f";
        info->hash = 0xBFFB11FC;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.1f;
        info->maxVal = 0.707f;
        info->defaultVal = 0.707f;
        break;
      }
      case 9: {
        info->name = "_1_INPUT";
        info->hash = 0x5A63170A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -12.0f;
        info->maxVal = 12.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 10: {
        info->name = "_20_dBHF";
        info->hash = 0x5E915D93;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -9.0f;
        info->maxVal = 9.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 11: {
        info->name = "_2_DRY";
        info->hash = 0x49127601;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 10.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 12: {
        info->name = "_3_WET";
        info->hash = 0x685033DE;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 10.0f;
        info->defaultVal = 10.0f;
        break;
      }
      case 13: {
        info->name = "_4_OUTPUT";
        info->hash = 0xAC813ECB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -20.0f;
        info->maxVal = 20.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 14: {
        info->name = "_5_HzLF";
        info->hash = 0x158602FD;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 30.0f;
        info->maxVal = 90.0f;
        info->defaultVal = 50.0f;
        break;
      }
      case 15: {
        info->name = "_6_QLF_f";
        info->hash = 0xCC4785E3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.1f;
        info->maxVal = 0.707f;
        info->defaultVal = 0.707f;
        break;
      }
      case 16: {
        info->name = "_8_dBLF";
        info->hash = 0x9D2964A6;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = -9.0f;
        info->maxVal = 9.0f;
        info->defaultVal = 0.0f;
        break;
      }
      case 17: {
        info->name = "_9_HzLMF";
        info->hash = 0xCD86A9DF;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 100.0f;
        info->maxVal = 1100.0f;
        info->defaultVal = 350.0f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 18;
}



/*
 * Send Function Implementations
 */


void Heavy_EQVU::cVar_lQiHyA23_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b7pstZIx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6dn99hz0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NWpE52Qx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wVp4P5Nh_sendMessage);
}

void Heavy_EQVU::cVar_wlNqMSS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_qxUUODeg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_VrN68o8o_sendMessage);
}

void Heavy_EQVU::cVar_b9GoW53K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_23o9Qi6k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2xYLdkg9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GiWZ4wCW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KYm2z3dm_sendMessage);
}

void Heavy_EQVU::cVar_vnz76X2m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZOwEFvRM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ELXbVrXX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5gOWHd06_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mtXpsTNH_sendMessage);
}

void Heavy_EQVU::cVar_KksTsWGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_w0kN6Cck_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_78thvVSs_sendMessage);
}

void Heavy_EQVU::cVar_hLJkrFBj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fKfiPTpc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lUAa8UrT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GM2AnbLR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_n9hSroge_sendMessage);
}

void Heavy_EQVU::cVar_3PKKi0fn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nimJgXfX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2112cEWb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qLdzd0Hd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fxH0p5Io_sendMessage);
}

void Heavy_EQVU::cVar_xzQRx44A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_mLCQDoNs_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_9N4wpUgw_sendMessage);
}

void Heavy_EQVU::cVar_SbTpAWOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rQUVlPdh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5lUwiYZt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ywdnzvUe_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QCT9PNqr_sendMessage);
}

void Heavy_EQVU::cVar_mhNfs6Ok_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QgI4mafY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t6e6wlaM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_P1dOS3Gi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fRpYA4gz_sendMessage);
}

void Heavy_EQVU::cVar_1i2jjkhP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_hAQiTNEg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 2.0f, 0, m, &cBinop_hU0sEGhs_sendMessage);
}

void Heavy_EQVU::cVar_775QCHe0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KAjFlDAa_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_C3CbVvjO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8Fk50s3S_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hW2IA5gj_sendMessage);
}

void Heavy_EQVU::cVar_3rYVtvhw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_cQ0aQp8C, 0, m, &cExpr_cQ0aQp8C_sendMessage);
}

void Heavy_EQVU::cExpr_cQ0aQp8C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_i1L9GUcR, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_LpSaxQvy, m);
}

float Heavy_EQVU::cExpr_cQ0aQp8C_evaluate(const float* args) {
  	return hv_pow_f(10 , ((float)(args[0])) / 20);
}

void Heavy_EQVU::cVar_FAqrC730_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_zMVqFJ7E, 0, m, &cExpr_zMVqFJ7E_sendMessage);
}

void Heavy_EQVU::cExpr_zMVqFJ7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_JYf7ganH, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_lKEbVOPI, m);
}

float Heavy_EQVU::cExpr_zMVqFJ7E_evaluate(const float* args) {
  	return hv_pow_f(10 , ((float)(args[0])) / 20);
}

void Heavy_EQVU::cVar_Tu0Iupx2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_rxXtxhsK, 0, m, &cExpr_rxXtxhsK_sendMessage);
}

void Heavy_EQVU::cVar_RITjtKXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cExpr_onMessage(_c, &Context(_c)->cExpr_98v21Rs3, 0, m, &cExpr_98v21Rs3_sendMessage);
}

void Heavy_EQVU::cUnop_fWZL8vaq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UqgSX8kf_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_PrJAUV80, HV_BINOP_MULTIPLY, 0, m, &cBinop_PrJAUV80_sendMessage);
}

void Heavy_EQVU::cUnop_TKQa67Kz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tWY0BoLw_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ql7xtS1c, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ql7xtS1c_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aPspS9Nk, HV_BINOP_MULTIPLY, 0, m, &cBinop_aPspS9Nk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2N8h3Rjx, HV_BINOP_MULTIPLY, 0, m, &cBinop_2N8h3Rjx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_me8yjv1n, HV_BINOP_MULTIPLY, 0, m, &cBinop_me8yjv1n_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2su89cIt, HV_BINOP_MULTIPLY, 0, m, &cBinop_2su89cIt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_desAePrT, HV_BINOP_MULTIPLY, 0, m, &cBinop_desAePrT_sendMessage);
}

void Heavy_EQVU::cBinop_nLvxRDmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_wjCQm375_sendMessage);
}

void Heavy_EQVU::cBinop_wjCQm375_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4dZ0z7jV, HV_BINOP_MULTIPLY, 0, m, &cBinop_4dZ0z7jV_sendMessage);
}

void Heavy_EQVU::cVar_0eSExtj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_of7PWHAs_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_cwWtp1dr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_wewq79IS_sendMessage);
}

void Heavy_EQVU::cBinop_wewq79IS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_EfZswWII_sendMessage);
}

void Heavy_EQVU::cVar_2WhDFwrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5T97BWJ0_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_nLvxRDmx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TxtzoXZR_sendMessage);
}

void Heavy_EQVU::cVar_uEyZjZdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_DtMkVFVe_sendMessage);
}

void Heavy_EQVU::cVar_f1VExZYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_cwWtp1dr_sendMessage);
}

void Heavy_EQVU::cUnop_TcuDpVJL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_d69PxkQq_sendMessage);
}

void Heavy_EQVU::cMsg_Ugrl9lXk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_eDu2g7Ve_sendMessage);
}

void Heavy_EQVU::cSystem_eDu2g7Ve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tlvVFg0c, HV_BINOP_DIVIDE, 1, m, &cBinop_tlvVFg0c_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dtkN3hGj_sendMessage);
}

void Heavy_EQVU::cUnop_dwgycLuO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_Kxj7d0q0_sendMessage);
}

void Heavy_EQVU::cBinop_OfR0YmnP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WhDFwrE, 0, m, &cVar_2WhDFwrE_sendMessage);
}

void Heavy_EQVU::cBinop_46avDZc6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_cDeXmKlv_sendMessage);
}

void Heavy_EQVU::cBinop_cDeXmKlv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vkxTA1vw, HV_BINOP_POW, 1, m, &cBinop_vkxTA1vw_sendMessage);
  cMsg_23RoivWl_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_vkxTA1vw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_OfR0YmnP_sendMessage);
}

void Heavy_EQVU::cMsg_23RoivWl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vkxTA1vw, HV_BINOP_POW, 0, m, &cBinop_vkxTA1vw_sendMessage);
}

void Heavy_EQVU::cIf_QtfdxqR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_2C6JFA1x_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_Dowv8aGi_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_EUyaYwBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_7w7J2Mgn_sendMessage);
}

void Heavy_EQVU::cBinop_Dowv8aGi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_EUyaYwBF_sendMessage);
}

void Heavy_EQVU::cBinop_7w7J2Mgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_i2m98DZz_sendMessage);
}

void Heavy_EQVU::cBinop_i2m98DZz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_46avDZc6_sendMessage);
}

void Heavy_EQVU::cCast_NWpE52Qx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_JuVrNLCh_sendMessage);
}

void Heavy_EQVU::cCast_wVp4P5Nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QtfdxqR6, 0, m, &cIf_QtfdxqR6_sendMessage);
}

void Heavy_EQVU::cBinop_JuVrNLCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_QtfdxqR6, 1, m, &cIf_QtfdxqR6_sendMessage);
}

void Heavy_EQVU::cMsg_2C6JFA1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_46avDZc6_sendMessage);
}

void Heavy_EQVU::cBinop_DtMkVFVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_tjl0qmqa_sendMessage);
}

void Heavy_EQVU::cBinop_tjl0qmqa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mLHfNvqz_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_SNMNCcI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_hY8yuLUp_sendMessage);
}

void Heavy_EQVU::cBinop_hY8yuLUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mTYb7XCA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JYaHcJp3_sendMessage);
}

void Heavy_EQVU::cMsg_uxiIeYv7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_i2DcOZR4, 0, m, NULL);
}

void Heavy_EQVU::cMsg_g7BHoJjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_RmoWLgur, 0, m, NULL);
}

void Heavy_EQVU::cMsg_1uq5JLfL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_TBFHImbf, 0, m, NULL);
}

void Heavy_EQVU::cMsg_5BOdVxeK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_B9aSsYUg, 0, m, NULL);
}

void Heavy_EQVU::cMsg_54p5mizK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_07i2LSrB, 0, m, NULL);
}

void Heavy_EQVU::cCast_v13xxQ0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_fWZL8vaq_sendMessage);
}

void Heavy_EQVU::cCast_IFgkOsTJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_TKQa67Kz_sendMessage);
}

void Heavy_EQVU::cSend_UqgSX8kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_tWY0BoLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_UoGLJDo2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_mLHfNvqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_l0sOBCaG_sendMessage);
}

void Heavy_EQVU::cBinop_l0sOBCaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PrJAUV80, HV_BINOP_MULTIPLY, 1, m, &cBinop_PrJAUV80_sendMessage);
}

void Heavy_EQVU::cBinop_PrJAUV80_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_hp7hn7q4_sendMessage);
}

void Heavy_EQVU::cBinop_hp7hn7q4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FBJPI08O_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_a63UEKiC_sendMessage);
}

void Heavy_EQVU::cMsg_of7PWHAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4s2Lx7Hy_sendMessage);
}

void Heavy_EQVU::cBinop_4s2Lx7Hy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_H6sfaIpz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xYG5HZIq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_smNQcrsh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Z8AFuoxC_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Gg3VZ8GZ_sendMessage);
}

void Heavy_EQVU::cBinop_aJwL7Hz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_54p5mizK_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_0CSbIDf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5BOdVxeK_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_HZghZ6PH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_1uq5JLfL_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_zWITyrhA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g7BHoJjJ_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_ilwWKYwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uxiIeYv7_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_mTYb7XCA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uEyZjZdS, 1, m, &cVar_uEyZjZdS_sendMessage);
}

void Heavy_EQVU::cCast_JYaHcJp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WhDFwrE, 0, m, &cVar_2WhDFwrE_sendMessage);
}

void Heavy_EQVU::cCast_5T97BWJ0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uEyZjZdS, 0, m, &cVar_uEyZjZdS_sendMessage);
}

void Heavy_EQVU::cCast_TxtzoXZR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0eSExtj4, 0, m, &cVar_0eSExtj4_sendMessage);
}

void Heavy_EQVU::cSend_ZO68glPM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_EfZswWII_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DulOejbA_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l1JVQRjH_sendMessage);
}

void Heavy_EQVU::cCast_l1JVQRjH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lSsWt51m_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_DulOejbA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sObXt1gV, HV_BINOP_POW, 1, m, &cBinop_sObXt1gV_sendMessage);
}

void Heavy_EQVU::cMsg_lSsWt51m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sObXt1gV, HV_BINOP_POW, 0, m, &cBinop_sObXt1gV_sendMessage);
}

void Heavy_EQVU::cBinop_sObXt1gV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kERamzTh_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WdgUV1L7_sendMessage);
}

void Heavy_EQVU::cCast_GiWZ4wCW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f1VExZYb, 0, m, &cVar_f1VExZYb_sendMessage);
}

void Heavy_EQVU::cCast_KYm2z3dm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WhDFwrE, 0, m, &cVar_2WhDFwrE_sendMessage);
}

void Heavy_EQVU::cCast_QStn3lzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WhDFwrE, 0, m, &cVar_2WhDFwrE_sendMessage);
}

void Heavy_EQVU::cCast_UqTk4k0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_f1VExZYb, 0, m, &cVar_f1VExZYb_sendMessage);
}

void Heavy_EQVU::cBinop_d69PxkQq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_plg3Fchv, HV_BINOP_MULTIPLY, 1, m, &cBinop_plg3Fchv_sendMessage);
}

void Heavy_EQVU::cBinop_plg3Fchv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_YlyF3cIE_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DAlKzpX6, HV_BINOP_ADD, 1, m, &cBinop_DAlKzpX6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wbgqITD3, HV_BINOP_SUBTRACT, 1, m, &cBinop_wbgqITD3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qHw5z0sC, HV_BINOP_SUBTRACT, 1, m, &cBinop_qHw5z0sC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GbjVDcoY, HV_BINOP_ADD, 1, m, &cBinop_GbjVDcoY_sendMessage);
}

void Heavy_EQVU::cCast_a63UEKiC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_plg3Fchv, HV_BINOP_MULTIPLY, 0, m, &cBinop_plg3Fchv_sendMessage);
}

void Heavy_EQVU::cCast_FBJPI08O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_UoGLJDo2_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_smNQcrsh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HZghZ6PH, HV_BINOP_MULTIPLY, 0, m, &cBinop_HZghZ6PH_sendMessage);
}

void Heavy_EQVU::cCast_Gg3VZ8GZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aJwL7Hz3, HV_BINOP_MULTIPLY, 0, m, &cBinop_aJwL7Hz3_sendMessage);
}

void Heavy_EQVU::cCast_Z8AFuoxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0CSbIDf5, HV_BINOP_MULTIPLY, 0, m, &cBinop_0CSbIDf5_sendMessage);
}

void Heavy_EQVU::cCast_xYG5HZIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zWITyrhA, HV_BINOP_MULTIPLY, 0, m, &cBinop_zWITyrhA_sendMessage);
}

void Heavy_EQVU::cCast_H6sfaIpz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ilwWKYwx, HV_BINOP_MULTIPLY, 0, m, &cBinop_ilwWKYwx_sendMessage);
}

void Heavy_EQVU::cCast_WdgUV1L7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_TcuDpVJL_sendMessage);
}

void Heavy_EQVU::cCast_kERamzTh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ZO68glPM_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZVvsPmLW_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yFAi8t4q_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y9xfnjix_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ESHmzcrt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OXpI2jBm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ijQKzFD9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_McdBM3RU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5L4GD9AJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S1BLcJA1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BYl9Hat0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FGT5gphX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9OkcfKr4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_c5M8uOTf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yDJ1S4kn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GHxC3J9C_sendMessage);
}

void Heavy_EQVU::cSend_YlyF3cIE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_oATprLkM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_XDJQswtr_sendMessage);
}

void Heavy_EQVU::cBinop_Ql7xtS1c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sf73Fhxn, HV_BINOP_ADD, 0, m, &cBinop_Sf73Fhxn_sendMessage);
}

void Heavy_EQVU::cBinop_QRsHaF4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sf73Fhxn, HV_BINOP_ADD, 1, m, &cBinop_Sf73Fhxn_sendMessage);
}

void Heavy_EQVU::cCast_y9xfnjix_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_oATprLkM_sendMessage);
}

void Heavy_EQVU::cCast_yFAi8t4q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QRsHaF4d_sendMessage);
}

void Heavy_EQVU::cCast_ZVvsPmLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3UNOPy5b, HV_BINOP_MULTIPLY, 1, m, &cBinop_3UNOPy5b_sendMessage);
}

void Heavy_EQVU::cBinop_3UNOPy5b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aJwL7Hz3, HV_BINOP_MULTIPLY, 1, m, &cBinop_aJwL7Hz3_sendMessage);
}

void Heavy_EQVU::cBinop_Sf73Fhxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DAlKzpX6, HV_BINOP_ADD, 0, m, &cBinop_DAlKzpX6_sendMessage);
}

void Heavy_EQVU::cBinop_XDJQswtr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ql7xtS1c, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ql7xtS1c_sendMessage);
}

void Heavy_EQVU::cBinop_DAlKzpX6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3UNOPy5b, HV_BINOP_MULTIPLY, 0, m, &cBinop_3UNOPy5b_sendMessage);
}

void Heavy_EQVU::cBinop_dV58SpsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KW3qZBiA, HV_BINOP_ADD, 1, m, &cBinop_KW3qZBiA_sendMessage);
}

void Heavy_EQVU::cBinop_rm2ytTSw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_UslNLnyt_sendMessage);
}

void Heavy_EQVU::cBinop_aPspS9Nk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KW3qZBiA, HV_BINOP_ADD, 0, m, &cBinop_KW3qZBiA_sendMessage);
}

void Heavy_EQVU::cCast_ijQKzFD9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rm2ytTSw_sendMessage);
}

void Heavy_EQVU::cCast_ESHmzcrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_BMQloVSc_sendMessage);
}

void Heavy_EQVU::cCast_OXpI2jBm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dV58SpsJ_sendMessage);
}

void Heavy_EQVU::cBinop_BMQloVSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T7yg2LWD, HV_BINOP_MULTIPLY, 1, m, &cBinop_T7yg2LWD_sendMessage);
}

void Heavy_EQVU::cBinop_T7yg2LWD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0CSbIDf5, HV_BINOP_MULTIPLY, 1, m, &cBinop_0CSbIDf5_sendMessage);
}

void Heavy_EQVU::cBinop_KW3qZBiA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T7yg2LWD, HV_BINOP_MULTIPLY, 0, m, &cBinop_T7yg2LWD_sendMessage);
}

void Heavy_EQVU::cBinop_UslNLnyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aPspS9Nk, HV_BINOP_MULTIPLY, 1, m, &cBinop_aPspS9Nk_sendMessage);
}

void Heavy_EQVU::cBinop_Jcue77Vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3KCIj8qT_sendMessage);
}

void Heavy_EQVU::cBinop_2N8h3Rjx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tinRPBQL, HV_BINOP_ADD, 0, m, &cBinop_tinRPBQL_sendMessage);
}

void Heavy_EQVU::cBinop_tinRPBQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wbgqITD3, HV_BINOP_SUBTRACT, 0, m, &cBinop_wbgqITD3_sendMessage);
}

void Heavy_EQVU::cBinop_0TlMZEf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tinRPBQL, HV_BINOP_ADD, 1, m, &cBinop_tinRPBQL_sendMessage);
}

void Heavy_EQVU::cBinop_wbgqITD3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4X4TuGKu, HV_BINOP_MULTIPLY, 0, m, &cBinop_4X4TuGKu_sendMessage);
}

void Heavy_EQVU::cCast_S1BLcJA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Jcue77Vu_sendMessage);
}

void Heavy_EQVU::cCast_McdBM3RU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4X4TuGKu, HV_BINOP_MULTIPLY, 1, m, &cBinop_4X4TuGKu_sendMessage);
}

void Heavy_EQVU::cCast_5L4GD9AJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_0TlMZEf8_sendMessage);
}

void Heavy_EQVU::cBinop_4X4TuGKu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HZghZ6PH, HV_BINOP_MULTIPLY, 1, m, &cBinop_HZghZ6PH_sendMessage);
}

void Heavy_EQVU::cBinop_3KCIj8qT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2N8h3Rjx, HV_BINOP_MULTIPLY, 1, m, &cBinop_2N8h3Rjx_sendMessage);
}

void Heavy_EQVU::cBinop_yQ3dB7cW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sqdvvwd4, HV_BINOP_ADD, 1, m, &cBinop_sqdvvwd4_sendMessage);
}

void Heavy_EQVU::cBinop_sqdvvwd4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_zeOCrbMk_sendMessage);
}

void Heavy_EQVU::cBinop_JEMWmTPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_me8yjv1n, HV_BINOP_MULTIPLY, 1, m, &cBinop_me8yjv1n_sendMessage);
}

void Heavy_EQVU::cBinop_me8yjv1n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sqdvvwd4, HV_BINOP_ADD, 0, m, &cBinop_sqdvvwd4_sendMessage);
}

void Heavy_EQVU::cCast_FGT5gphX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JEMWmTPC_sendMessage);
}

void Heavy_EQVU::cCast_BYl9Hat0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_yQ3dB7cW_sendMessage);
}

void Heavy_EQVU::cBinop_zeOCrbMk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zWITyrhA, HV_BINOP_MULTIPLY, 1, m, &cBinop_zWITyrhA_sendMessage);
}

void Heavy_EQVU::cBinop_MdVXnQkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2su89cIt, HV_BINOP_MULTIPLY, 1, m, &cBinop_2su89cIt_sendMessage);
}

void Heavy_EQVU::cBinop_2su89cIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4CEcfvbK, HV_BINOP_ADD, 0, m, &cBinop_4CEcfvbK_sendMessage);
}

void Heavy_EQVU::cBinop_4CEcfvbK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qHw5z0sC, HV_BINOP_SUBTRACT, 0, m, &cBinop_qHw5z0sC_sendMessage);
}

void Heavy_EQVU::cBinop_pNZgUjOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4CEcfvbK, HV_BINOP_ADD, 1, m, &cBinop_4CEcfvbK_sendMessage);
}

void Heavy_EQVU::cCast_c5M8uOTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_MdVXnQkl_sendMessage);
}

void Heavy_EQVU::cCast_9OkcfKr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_pNZgUjOq_sendMessage);
}

void Heavy_EQVU::cBinop_qHw5z0sC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ilwWKYwx, HV_BINOP_MULTIPLY, 1, m, &cBinop_ilwWKYwx_sendMessage);
}

void Heavy_EQVU::cMsg_eKwhbE2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_dwgycLuO_sendMessage);
}

void Heavy_EQVU::cBinop_Kxj7d0q0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tlvVFg0c, HV_BINOP_DIVIDE, 0, m, &cBinop_tlvVFg0c_sendMessage);
}

void Heavy_EQVU::cCast_dtkN3hGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eKwhbE2c_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_tlvVFg0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4dZ0z7jV, HV_BINOP_MULTIPLY, 1, m, &cBinop_4dZ0z7jV_sendMessage);
}

void Heavy_EQVU::cBinop_4dZ0z7jV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_v13xxQ0n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IFgkOsTJ_sendMessage);
}

void Heavy_EQVU::cBinop_uuVnwIzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_desAePrT, HV_BINOP_MULTIPLY, 1, m, &cBinop_desAePrT_sendMessage);
}

void Heavy_EQVU::cBinop_desAePrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2XTUUy7h, HV_BINOP_ADD, 0, m, &cBinop_2XTUUy7h_sendMessage);
}

void Heavy_EQVU::cBinop_2XTUUy7h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GbjVDcoY, HV_BINOP_ADD, 0, m, &cBinop_GbjVDcoY_sendMessage);
}

void Heavy_EQVU::cBinop_y70X4QWz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2XTUUy7h, HV_BINOP_ADD, 1, m, &cBinop_2XTUUy7h_sendMessage);
}

void Heavy_EQVU::cCast_yDJ1S4kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_y70X4QWz_sendMessage);
}

void Heavy_EQVU::cCast_GHxC3J9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_uuVnwIzc_sendMessage);
}

void Heavy_EQVU::cBinop_GbjVDcoY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0eSExtj4, 1, m, &cVar_0eSExtj4_sendMessage);
}

void Heavy_EQVU::cBinop_VrN68o8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_1J2e7T51_sendMessage);
}

void Heavy_EQVU::cBinop_1J2e7T51_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_SNMNCcI8_sendMessage);
}

void Heavy_EQVU::cUnop_0H4S8LW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MbvFMXBG_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4SsFkDGc, HV_BINOP_MULTIPLY, 0, m, &cBinop_4SsFkDGc_sendMessage);
}

void Heavy_EQVU::cUnop_n0lFIPJp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_x4iJE9q3_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jY1zeAJP, HV_BINOP_MULTIPLY, 0, m, &cBinop_jY1zeAJP_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KFY8ocMj, HV_BINOP_MULTIPLY, 0, m, &cBinop_KFY8ocMj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aD7rZgSR, HV_BINOP_MULTIPLY, 0, m, &cBinop_aD7rZgSR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHmWAETm, HV_BINOP_MULTIPLY, 0, m, &cBinop_BHmWAETm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RyS309MK, HV_BINOP_MULTIPLY, 0, m, &cBinop_RyS309MK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_EDR4iksm, HV_BINOP_MULTIPLY, 0, m, &cBinop_EDR4iksm_sendMessage);
}

void Heavy_EQVU::cBinop_6FXAVNnc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_iog9kdCC_sendMessage);
}

void Heavy_EQVU::cBinop_iog9kdCC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_80Vo8q50, HV_BINOP_MULTIPLY, 0, m, &cBinop_80Vo8q50_sendMessage);
}

void Heavy_EQVU::cVar_FIph4gBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6Fi7SefK_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_O7TIHxmp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_edjeKjJw_sendMessage);
}

void Heavy_EQVU::cBinop_edjeKjJw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_xNOPDntU_sendMessage);
}

void Heavy_EQVU::cVar_zxk6crO2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bkiaJuLR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_6FXAVNnc_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_euCo19C5_sendMessage);
}

void Heavy_EQVU::cVar_pxaFLBkr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_XBdX6Zqy_sendMessage);
}

void Heavy_EQVU::cVar_bMhzyBEs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_O7TIHxmp_sendMessage);
}

void Heavy_EQVU::cUnop_TtbP38Mv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_9gvxGmw6_sendMessage);
}

void Heavy_EQVU::cMsg_qwQolJZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NoednZ1W_sendMessage);
}

void Heavy_EQVU::cSystem_NoednZ1W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yYHqBjct, HV_BINOP_DIVIDE, 1, m, &cBinop_yYHqBjct_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2w4CSioB_sendMessage);
}

void Heavy_EQVU::cUnop_EfRmmrm3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_UczR0R9N_sendMessage);
}

void Heavy_EQVU::cBinop_Jq4mhG8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zxk6crO2, 0, m, &cVar_zxk6crO2_sendMessage);
}

void Heavy_EQVU::cBinop_OsfIhXGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_79ACbZ1P_sendMessage);
}

void Heavy_EQVU::cBinop_79ACbZ1P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7eGu9Tkq, HV_BINOP_POW, 1, m, &cBinop_7eGu9Tkq_sendMessage);
  cMsg_R2TCNA92_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_7eGu9Tkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_Jq4mhG8V_sendMessage);
}

void Heavy_EQVU::cMsg_R2TCNA92_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7eGu9Tkq, HV_BINOP_POW, 0, m, &cBinop_7eGu9Tkq_sendMessage);
}

void Heavy_EQVU::cIf_rZ2s1i1a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ethonP8z_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_fvuPONKf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_zBOQ9Qqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_8XHabtNZ_sendMessage);
}

void Heavy_EQVU::cBinop_fvuPONKf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_zBOQ9Qqz_sendMessage);
}

void Heavy_EQVU::cBinop_8XHabtNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_uKlntWVk_sendMessage);
}

void Heavy_EQVU::cBinop_uKlntWVk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OsfIhXGG_sendMessage);
}

void Heavy_EQVU::cCast_6dn99hz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rZ2s1i1a, 0, m, &cIf_rZ2s1i1a_sendMessage);
}

void Heavy_EQVU::cCast_b7pstZIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ijskt4uY_sendMessage);
}

void Heavy_EQVU::cBinop_ijskt4uY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rZ2s1i1a, 1, m, &cIf_rZ2s1i1a_sendMessage);
}

void Heavy_EQVU::cMsg_ethonP8z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_OsfIhXGG_sendMessage);
}

void Heavy_EQVU::cBinop_tMmUpL2P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_dLd6GhBw_sendMessage);
}

void Heavy_EQVU::cBinop_dLd6GhBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_G1NXUriJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vwei1PoO_sendMessage);
}

void Heavy_EQVU::cBinop_XBdX6Zqy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_FXHSQOpI_sendMessage);
}

void Heavy_EQVU::cBinop_FXHSQOpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6f6RtdSz_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_Xj83JWpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ChLD7RUV, 0, m, NULL);
}

void Heavy_EQVU::cMsg_2CYHR0uD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Gjkvrkzc, 0, m, NULL);
}

void Heavy_EQVU::cMsg_cfe3I3MT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_2E0um0D6, 0, m, NULL);
}

void Heavy_EQVU::cMsg_j6k2TsaE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XV0zhI7q, 0, m, NULL);
}

void Heavy_EQVU::cMsg_dTfhFtrk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_pWftslqy, 0, m, NULL);
}

void Heavy_EQVU::cCast_TsZ2SfKP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_0H4S8LW8_sendMessage);
}

void Heavy_EQVU::cCast_6moYwaCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_n0lFIPJp_sendMessage);
}

void Heavy_EQVU::cSend_MbvFMXBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_x4iJE9q3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_jdqUQuqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_6f6RtdSz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_FZsr2Tyh_sendMessage);
}

void Heavy_EQVU::cBinop_FZsr2Tyh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4SsFkDGc, HV_BINOP_MULTIPLY, 1, m, &cBinop_4SsFkDGc_sendMessage);
}

void Heavy_EQVU::cBinop_4SsFkDGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_qt6ZTcMV_sendMessage);
}

void Heavy_EQVU::cBinop_qt6ZTcMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0t4bnFY8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QnSc3kdn_sendMessage);
}

void Heavy_EQVU::cMsg_6Fi7SefK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_xbeyyQgX_sendMessage);
}

void Heavy_EQVU::cBinop_xbeyyQgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7uHvJXbw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2w4lGvdy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8a3KeLE7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mJeyrRZ3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6999NOuh_sendMessage);
}

void Heavy_EQVU::cBinop_nHxOFFlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dTfhFtrk_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_wrixMDYm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j6k2TsaE_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_ScixiduJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cfe3I3MT_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_U4mIpSIl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2CYHR0uD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_u4BGljtq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Xj83JWpI_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_G1NXUriJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pxaFLBkr, 1, m, &cVar_pxaFLBkr_sendMessage);
}

void Heavy_EQVU::cCast_vwei1PoO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zxk6crO2, 0, m, &cVar_zxk6crO2_sendMessage);
}

void Heavy_EQVU::cCast_euCo19C5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FIph4gBx, 0, m, &cVar_FIph4gBx_sendMessage);
}

void Heavy_EQVU::cCast_bkiaJuLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pxaFLBkr, 0, m, &cVar_pxaFLBkr_sendMessage);
}

void Heavy_EQVU::cSend_QVEvEpbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_xNOPDntU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_bNDcZ5sk_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pnsls0ug_sendMessage);
}

void Heavy_EQVU::cCast_Pnsls0ug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vVodnf8n_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_bNDcZ5sk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z01FQcEM, HV_BINOP_POW, 1, m, &cBinop_Z01FQcEM_sendMessage);
}

void Heavy_EQVU::cMsg_vVodnf8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z01FQcEM, HV_BINOP_POW, 0, m, &cBinop_Z01FQcEM_sendMessage);
}

void Heavy_EQVU::cBinop_Z01FQcEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_z5nBo3Fl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wPj0X34H_sendMessage);
}

void Heavy_EQVU::cCast_23o9Qi6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bMhzyBEs, 0, m, &cVar_bMhzyBEs_sendMessage);
}

void Heavy_EQVU::cCast_2xYLdkg9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zxk6crO2, 0, m, &cVar_zxk6crO2_sendMessage);
}

void Heavy_EQVU::cCast_UQTjTR8P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bMhzyBEs, 0, m, &cVar_bMhzyBEs_sendMessage);
}

void Heavy_EQVU::cCast_eH6sDJ9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_zxk6crO2, 0, m, &cVar_zxk6crO2_sendMessage);
}

void Heavy_EQVU::cBinop_9gvxGmw6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kHedcZsJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_kHedcZsJ_sendMessage);
}

void Heavy_EQVU::cBinop_kHedcZsJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SAgkVFZM_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RKXXXoUs, HV_BINOP_ADD, 1, m, &cBinop_RKXXXoUs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpNTuziH, HV_BINOP_SUBTRACT, 1, m, &cBinop_WpNTuziH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HC38VeWQ, HV_BINOP_SUBTRACT, 1, m, &cBinop_HC38VeWQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_N2RRgtB0, HV_BINOP_ADD, 1, m, &cBinop_N2RRgtB0_sendMessage);
}

void Heavy_EQVU::cCast_QnSc3kdn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kHedcZsJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_kHedcZsJ_sendMessage);
}

void Heavy_EQVU::cCast_0t4bnFY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_jdqUQuqd_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_2w4lGvdy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U4mIpSIl, HV_BINOP_MULTIPLY, 0, m, &cBinop_U4mIpSIl_sendMessage);
}

void Heavy_EQVU::cCast_8a3KeLE7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ScixiduJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_ScixiduJ_sendMessage);
}

void Heavy_EQVU::cCast_6999NOuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nHxOFFlS, HV_BINOP_MULTIPLY, 0, m, &cBinop_nHxOFFlS_sendMessage);
}

void Heavy_EQVU::cCast_mJeyrRZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wrixMDYm, HV_BINOP_MULTIPLY, 0, m, &cBinop_wrixMDYm_sendMessage);
}

void Heavy_EQVU::cCast_7uHvJXbw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u4BGljtq, HV_BINOP_MULTIPLY, 0, m, &cBinop_u4BGljtq_sendMessage);
}

void Heavy_EQVU::cCast_wPj0X34H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_TtbP38Mv_sendMessage);
}

void Heavy_EQVU::cCast_z5nBo3Fl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_QVEvEpbB_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZgNqrLr9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EbJi2JRt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8yVDPnGE_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ImsjBDX8_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DKI85smq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Lkiyw1ls_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KVOrlnON_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8LTGkodp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UBFZ9y33_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Av6zQ7zp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kyHPcewt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AKhPGN2f_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RzsPj5sO_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YmQSpElS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_01pq0KY8_sendMessage);
}

void Heavy_EQVU::cSend_SAgkVFZM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_pZ98lLf3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ZCdt6io8_sendMessage);
}

void Heavy_EQVU::cBinop_jY1zeAJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JmMOPkbB, HV_BINOP_ADD, 0, m, &cBinop_JmMOPkbB_sendMessage);
}

void Heavy_EQVU::cBinop_bzfyqEzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JmMOPkbB, HV_BINOP_ADD, 1, m, &cBinop_JmMOPkbB_sendMessage);
}

void Heavy_EQVU::cCast_ZgNqrLr9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IZbQiRuD, HV_BINOP_MULTIPLY, 1, m, &cBinop_IZbQiRuD_sendMessage);
}

void Heavy_EQVU::cCast_8yVDPnGE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_pZ98lLf3_sendMessage);
}

void Heavy_EQVU::cCast_EbJi2JRt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_bzfyqEzz_sendMessage);
}

void Heavy_EQVU::cBinop_IZbQiRuD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nHxOFFlS, HV_BINOP_MULTIPLY, 1, m, &cBinop_nHxOFFlS_sendMessage);
}

void Heavy_EQVU::cBinop_JmMOPkbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RKXXXoUs, HV_BINOP_ADD, 0, m, &cBinop_RKXXXoUs_sendMessage);
}

void Heavy_EQVU::cBinop_ZCdt6io8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jY1zeAJP, HV_BINOP_MULTIPLY, 1, m, &cBinop_jY1zeAJP_sendMessage);
}

void Heavy_EQVU::cBinop_RKXXXoUs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IZbQiRuD, HV_BINOP_MULTIPLY, 0, m, &cBinop_IZbQiRuD_sendMessage);
}

void Heavy_EQVU::cBinop_LVX8Y6hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O23q1gZw, HV_BINOP_ADD, 1, m, &cBinop_O23q1gZw_sendMessage);
}

void Heavy_EQVU::cBinop_XM3TaZN8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JeXS639K_sendMessage);
}

void Heavy_EQVU::cBinop_KFY8ocMj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O23q1gZw, HV_BINOP_ADD, 0, m, &cBinop_O23q1gZw_sendMessage);
}

void Heavy_EQVU::cCast_Lkiyw1ls_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_XM3TaZN8_sendMessage);
}

void Heavy_EQVU::cCast_ImsjBDX8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_f82IipMY_sendMessage);
}

void Heavy_EQVU::cCast_DKI85smq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_LVX8Y6hd_sendMessage);
}

void Heavy_EQVU::cBinop_f82IipMY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfaepOzG, HV_BINOP_MULTIPLY, 1, m, &cBinop_mfaepOzG_sendMessage);
}

void Heavy_EQVU::cBinop_mfaepOzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wrixMDYm, HV_BINOP_MULTIPLY, 1, m, &cBinop_wrixMDYm_sendMessage);
}

void Heavy_EQVU::cBinop_O23q1gZw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfaepOzG, HV_BINOP_MULTIPLY, 0, m, &cBinop_mfaepOzG_sendMessage);
}

void Heavy_EQVU::cBinop_JeXS639K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KFY8ocMj, HV_BINOP_MULTIPLY, 1, m, &cBinop_KFY8ocMj_sendMessage);
}

void Heavy_EQVU::cBinop_JRjjxCiG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BzW2bRih_sendMessage);
}

void Heavy_EQVU::cBinop_aD7rZgSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RR2zzGSm, HV_BINOP_ADD, 0, m, &cBinop_RR2zzGSm_sendMessage);
}

void Heavy_EQVU::cBinop_RR2zzGSm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WpNTuziH, HV_BINOP_SUBTRACT, 0, m, &cBinop_WpNTuziH_sendMessage);
}

void Heavy_EQVU::cBinop_tpem1ayw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RR2zzGSm, HV_BINOP_ADD, 1, m, &cBinop_RR2zzGSm_sendMessage);
}

void Heavy_EQVU::cBinop_WpNTuziH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pKsMjciU, HV_BINOP_MULTIPLY, 0, m, &cBinop_pKsMjciU_sendMessage);
}

void Heavy_EQVU::cCast_8LTGkodp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_tpem1ayw_sendMessage);
}

void Heavy_EQVU::cCast_KVOrlnON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pKsMjciU, HV_BINOP_MULTIPLY, 1, m, &cBinop_pKsMjciU_sendMessage);
}

void Heavy_EQVU::cCast_UBFZ9y33_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JRjjxCiG_sendMessage);
}

void Heavy_EQVU::cBinop_pKsMjciU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ScixiduJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_ScixiduJ_sendMessage);
}

void Heavy_EQVU::cBinop_BzW2bRih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aD7rZgSR, HV_BINOP_MULTIPLY, 1, m, &cBinop_aD7rZgSR_sendMessage);
}

void Heavy_EQVU::cBinop_B1xayM9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JaRBnFfN, HV_BINOP_ADD, 1, m, &cBinop_JaRBnFfN_sendMessage);
}

void Heavy_EQVU::cBinop_JaRBnFfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_pzyAwVj0_sendMessage);
}

void Heavy_EQVU::cBinop_xmRspK9b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BHmWAETm, HV_BINOP_MULTIPLY, 1, m, &cBinop_BHmWAETm_sendMessage);
}

void Heavy_EQVU::cBinop_BHmWAETm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JaRBnFfN, HV_BINOP_ADD, 0, m, &cBinop_JaRBnFfN_sendMessage);
}

void Heavy_EQVU::cCast_Av6zQ7zp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_B1xayM9q_sendMessage);
}

void Heavy_EQVU::cCast_kyHPcewt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_xmRspK9b_sendMessage);
}

void Heavy_EQVU::cBinop_pzyAwVj0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U4mIpSIl, HV_BINOP_MULTIPLY, 1, m, &cBinop_U4mIpSIl_sendMessage);
}

void Heavy_EQVU::cBinop_eGqrmD0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RyS309MK, HV_BINOP_MULTIPLY, 1, m, &cBinop_RyS309MK_sendMessage);
}

void Heavy_EQVU::cBinop_RyS309MK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rLFGEzuI, HV_BINOP_ADD, 0, m, &cBinop_rLFGEzuI_sendMessage);
}

void Heavy_EQVU::cBinop_rLFGEzuI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HC38VeWQ, HV_BINOP_SUBTRACT, 0, m, &cBinop_HC38VeWQ_sendMessage);
}

void Heavy_EQVU::cBinop_6qhmFu6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rLFGEzuI, HV_BINOP_ADD, 1, m, &cBinop_rLFGEzuI_sendMessage);
}

void Heavy_EQVU::cCast_RzsPj5sO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_eGqrmD0o_sendMessage);
}

void Heavy_EQVU::cCast_AKhPGN2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6qhmFu6i_sendMessage);
}

void Heavy_EQVU::cBinop_HC38VeWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u4BGljtq, HV_BINOP_MULTIPLY, 1, m, &cBinop_u4BGljtq_sendMessage);
}

void Heavy_EQVU::cMsg_0f9I24gF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_EfRmmrm3_sendMessage);
}

void Heavy_EQVU::cBinop_UczR0R9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yYHqBjct, HV_BINOP_DIVIDE, 0, m, &cBinop_yYHqBjct_sendMessage);
}

void Heavy_EQVU::cCast_2w4CSioB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0f9I24gF_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_yYHqBjct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_80Vo8q50, HV_BINOP_MULTIPLY, 1, m, &cBinop_80Vo8q50_sendMessage);
}

void Heavy_EQVU::cBinop_80Vo8q50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TsZ2SfKP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6moYwaCz_sendMessage);
}

void Heavy_EQVU::cBinop_6sKCyg7Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EDR4iksm, HV_BINOP_MULTIPLY, 1, m, &cBinop_EDR4iksm_sendMessage);
}

void Heavy_EQVU::cBinop_EDR4iksm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hEDYJZBG, HV_BINOP_ADD, 0, m, &cBinop_hEDYJZBG_sendMessage);
}

void Heavy_EQVU::cBinop_hEDYJZBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_N2RRgtB0, HV_BINOP_ADD, 0, m, &cBinop_N2RRgtB0_sendMessage);
}

void Heavy_EQVU::cBinop_JsjjkSoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hEDYJZBG, HV_BINOP_ADD, 1, m, &cBinop_hEDYJZBG_sendMessage);
}

void Heavy_EQVU::cCast_YmQSpElS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_JsjjkSoN_sendMessage);
}

void Heavy_EQVU::cCast_01pq0KY8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6sKCyg7Q_sendMessage);
}

void Heavy_EQVU::cBinop_N2RRgtB0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FIph4gBx, 1, m, &cVar_FIph4gBx_sendMessage);
}

void Heavy_EQVU::cBinop_qxUUODeg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_ll9bOor1_sendMessage);
}

void Heavy_EQVU::cBinop_ll9bOor1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_tMmUpL2P_sendMessage);
}

void Heavy_EQVU::cUnop_ClK1z4BP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8CitqZPX_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cUnop_M4yrTsmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cXKFsDjj_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_dQ7MVtTp_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_tnmm4TH6_sendMessage);
}

void Heavy_EQVU::cBinop_TuDd5XNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_Dp2kqmki_sendMessage);
}

void Heavy_EQVU::cBinop_Dp2kqmki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5iLhl0aE, HV_BINOP_MULTIPLY, 0, m, &cBinop_5iLhl0aE_sendMessage);
}

void Heavy_EQVU::cVar_FgG3kXoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KCz9KnlZ_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_YcxQJBGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_EEb8JckX_sendMessage);
}

void Heavy_EQVU::cBinop_EEb8JckX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_e5d3b9MG_sendMessage);
}

void Heavy_EQVU::cVar_ifTeqTKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DOXbNzek_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_TuDd5XNG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pHWBZCg8_sendMessage);
}

void Heavy_EQVU::cVar_N4RgWesM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_w0cTJX53_sendMessage);
}

void Heavy_EQVU::cVar_5CSAM909_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_YcxQJBGB_sendMessage);
}

void Heavy_EQVU::cMsg_spCKR7Zf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hsJAXLEe_sendMessage);
}

void Heavy_EQVU::cSystem_hsJAXLEe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjJjqqXg, HV_BINOP_DIVIDE, 1, m, &cBinop_ZjJjqqXg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m6sAs4v9_sendMessage);
}

void Heavy_EQVU::cUnop_xWsFGT2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_l3LAi5lc_sendMessage);
}

void Heavy_EQVU::cBinop_CVuUkkNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ifTeqTKC, 0, m, &cVar_ifTeqTKC_sendMessage);
}

void Heavy_EQVU::cBinop_d97eQTbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_ZcJd6G2V_sendMessage);
}

void Heavy_EQVU::cBinop_ZcJd6G2V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VAhgAhMP, HV_BINOP_POW, 1, m, &cBinop_VAhgAhMP_sendMessage);
  cMsg_64KYttEy_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_VAhgAhMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_CVuUkkNH_sendMessage);
}

void Heavy_EQVU::cMsg_64KYttEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VAhgAhMP, HV_BINOP_POW, 0, m, &cBinop_VAhgAhMP_sendMessage);
}

void Heavy_EQVU::cIf_6igvv9s5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_7Oqur2gu_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_eYVhRcXh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_76udS67U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_mi9Nq0GF_sendMessage);
}

void Heavy_EQVU::cBinop_eYVhRcXh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_76udS67U_sendMessage);
}

void Heavy_EQVU::cBinop_mi9Nq0GF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_pwd7wB4a_sendMessage);
}

void Heavy_EQVU::cBinop_pwd7wB4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_d97eQTbI_sendMessage);
}

void Heavy_EQVU::cCast_ELXbVrXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6igvv9s5, 0, m, &cIf_6igvv9s5_sendMessage);
}

void Heavy_EQVU::cCast_ZOwEFvRM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_oTsblOKt_sendMessage);
}

void Heavy_EQVU::cBinop_oTsblOKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6igvv9s5, 1, m, &cIf_6igvv9s5_sendMessage);
}

void Heavy_EQVU::cMsg_7Oqur2gu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_d97eQTbI_sendMessage);
}

void Heavy_EQVU::cBinop_w0cTJX53_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_xR5fMt1x_sendMessage);
}

void Heavy_EQVU::cBinop_xR5fMt1x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LW2AViDX_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_bmpZNyPw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_w3GfqUgv_sendMessage);
}

void Heavy_EQVU::cBinop_w3GfqUgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_g9gOhAt3_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wrcF2IYN_sendMessage);
}

void Heavy_EQVU::cMsg_vU7KdVF3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Tsd4yQYt, 0, m, NULL);
}

void Heavy_EQVU::cMsg_cipmBpWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VNH5c4Lc, 0, m, NULL);
}

void Heavy_EQVU::cMsg_qGSn9jrQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Hu6BovKt, 0, m, NULL);
}

void Heavy_EQVU::cMsg_z5mSYtgT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ULEoEQYL, 0, m, NULL);
}

void Heavy_EQVU::cMsg_a6TKtMf4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_8HprGu87, 0, m, NULL);
}

void Heavy_EQVU::cCast_KQdBoITr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_ClK1z4BP_sendMessage);
}

void Heavy_EQVU::cCast_CnBeh90B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_M4yrTsmg_sendMessage);
}

void Heavy_EQVU::cSend_8CitqZPX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_cXKFsDjj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_BAku3VKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_LW2AViDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_PZCGAcwL_sendMessage);
}

void Heavy_EQVU::cBinop_PZCGAcwL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wF0cNdNd, HV_BINOP_MULTIPLY, 1, m, &cBinop_wF0cNdNd_sendMessage);
}

void Heavy_EQVU::cBinop_wF0cNdNd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_WoCKNC4d_sendMessage);
}

void Heavy_EQVU::cBinop_WoCKNC4d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_BAku3VKK_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g8Oedr9r, HV_BINOP_DIVIDE, 0, m, &cBinop_g8Oedr9r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CIzUXlm6, HV_BINOP_MULTIPLY, 0, m, &cBinop_CIzUXlm6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gm6LdMZJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gm6LdMZJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nFxIN4pe, HV_BINOP_DIVIDE, 0, m, &cBinop_nFxIN4pe_sendMessage);
}

void Heavy_EQVU::cMsg_KCz9KnlZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_sGlKdzj3_sendMessage);
}

void Heavy_EQVU::cBinop_sGlKdzj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EGpIHQDM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qJ0XQyzl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fphJ6WUv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CCJ367dp_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sa0WO3Ne_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7Rer0yIU_sendMessage);
}

void Heavy_EQVU::cBinop_LohmcciK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vU7KdVF3_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_FmjKRXuf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cipmBpWw_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_yCIJwZlS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qGSn9jrQ_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_IpeeDuNR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_z5mSYtgT_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_Ei1BKubA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_a6TKtMf4_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_g9gOhAt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N4RgWesM, 1, m, &cVar_N4RgWesM_sendMessage);
}

void Heavy_EQVU::cCast_wrcF2IYN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ifTeqTKC, 0, m, &cVar_ifTeqTKC_sendMessage);
}

void Heavy_EQVU::cCast_CCJ367dp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yCIJwZlS, HV_BINOP_MULTIPLY, 0, m, &cBinop_yCIJwZlS_sendMessage);
}

void Heavy_EQVU::cCast_sa0WO3Ne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FmjKRXuf, HV_BINOP_MULTIPLY, 0, m, &cBinop_FmjKRXuf_sendMessage);
}

void Heavy_EQVU::cCast_EGpIHQDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cCast_qJ0XQyzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ei1BKubA, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ei1BKubA_sendMessage);
}

void Heavy_EQVU::cCast_fphJ6WUv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IpeeDuNR, HV_BINOP_MULTIPLY, 0, m, &cBinop_IpeeDuNR_sendMessage);
}

void Heavy_EQVU::cCast_7Rer0yIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LohmcciK, HV_BINOP_MULTIPLY, 0, m, &cBinop_LohmcciK_sendMessage);
}

void Heavy_EQVU::cCast_DOXbNzek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_N4RgWesM, 0, m, &cVar_N4RgWesM_sendMessage);
}

void Heavy_EQVU::cCast_pHWBZCg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FgG3kXoa, 0, m, &cVar_FgG3kXoa_sendMessage);
}

void Heavy_EQVU::cSend_JkRBqo9K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_e5d3b9MG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dqcN04EP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AUKNIDpM_sendMessage);
}

void Heavy_EQVU::cCast_AUKNIDpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D9FscjJE_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_dqcN04EP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nfU78vGf, HV_BINOP_POW, 1, m, &cBinop_nfU78vGf_sendMessage);
}

void Heavy_EQVU::cMsg_D9FscjJE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nfU78vGf, HV_BINOP_POW, 0, m, &cBinop_nfU78vGf_sendMessage);
}

void Heavy_EQVU::cBinop_nfU78vGf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JkRBqo9K_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_g8Oedr9r, HV_BINOP_DIVIDE, 1, m, &cBinop_g8Oedr9r_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CIzUXlm6, HV_BINOP_MULTIPLY, 1, m, &cBinop_CIzUXlm6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gm6LdMZJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Gm6LdMZJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nFxIN4pe, HV_BINOP_DIVIDE, 1, m, &cBinop_nFxIN4pe_sendMessage);
}

void Heavy_EQVU::cCast_fKfiPTpc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5CSAM909, 0, m, &cVar_5CSAM909_sendMessage);
}

void Heavy_EQVU::cCast_lUAa8UrT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ifTeqTKC, 0, m, &cVar_ifTeqTKC_sendMessage);
}

void Heavy_EQVU::cCast_5uLyfTFU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ifTeqTKC, 0, m, &cVar_ifTeqTKC_sendMessage);
}

void Heavy_EQVU::cCast_yuADsjqK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5CSAM909, 0, m, &cVar_5CSAM909_sendMessage);
}

void Heavy_EQVU::cBinop_8HFdWlOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FgG3kXoa, 1, m, &cVar_FgG3kXoa_sendMessage);
}

void Heavy_EQVU::cBinop_g8Oedr9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_8HFdWlOr_sendMessage);
}

void Heavy_EQVU::cBinop_CIzUXlm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_GvsQb2sq_sendMessage);
}

void Heavy_EQVU::cBinop_GvsQb2sq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LohmcciK, HV_BINOP_MULTIPLY, 1, m, &cBinop_LohmcciK_sendMessage);
}

void Heavy_EQVU::cBinop_dQ7MVtTp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FmjKRXuf, HV_BINOP_MULTIPLY, 1, m, &cBinop_FmjKRXuf_sendMessage);
}

void Heavy_EQVU::cBinop_Gm6LdMZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WlHyGLsP_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_WlHyGLsP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_QpRy8rsb_sendMessage);
}

void Heavy_EQVU::cBinop_QpRy8rsb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yCIJwZlS, HV_BINOP_MULTIPLY, 1, m, &cBinop_yCIJwZlS_sendMessage);
}

void Heavy_EQVU::cBinop_tnmm4TH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IpeeDuNR, HV_BINOP_MULTIPLY, 1, m, &cBinop_IpeeDuNR_sendMessage);
}

void Heavy_EQVU::cBinop_nFxIN4pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fsb5khCb_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_fsb5khCb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_ikiFigTs_sendMessage);
}

void Heavy_EQVU::cBinop_ikiFigTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ei1BKubA, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ei1BKubA_sendMessage);
}

void Heavy_EQVU::cMsg_Rzr7ZEsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_xWsFGT2y_sendMessage);
}

void Heavy_EQVU::cBinop_l3LAi5lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZjJjqqXg, HV_BINOP_DIVIDE, 0, m, &cBinop_ZjJjqqXg_sendMessage);
}

void Heavy_EQVU::cCast_m6sAs4v9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Rzr7ZEsn_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_ZjJjqqXg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5iLhl0aE, HV_BINOP_MULTIPLY, 1, m, &cBinop_5iLhl0aE_sendMessage);
}

void Heavy_EQVU::cBinop_5iLhl0aE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KQdBoITr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CnBeh90B_sendMessage);
}

void Heavy_EQVU::cBinop_78thvVSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_Riq3tATg_sendMessage);
}

void Heavy_EQVU::cBinop_Riq3tATg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_bmpZNyPw_sendMessage);
}

void Heavy_EQVU::cUnop_oN0aNbR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_74dCBaiL_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cUnop_7TZS6Svl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_G8SQy3qm_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_sZ8PVho7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_5qhLoGAE_sendMessage);
}

void Heavy_EQVU::cBinop_tlZU6nWW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_1mG9nVeG_sendMessage);
}

void Heavy_EQVU::cBinop_1mG9nVeG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L1cxdLQ7, HV_BINOP_MULTIPLY, 0, m, &cBinop_L1cxdLQ7_sendMessage);
}

void Heavy_EQVU::cVar_JZuL7JNh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3OzzdCMC_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_jY1CBlW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_riTpFOqV_sendMessage);
}

void Heavy_EQVU::cBinop_riTpFOqV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_FJNHv1xN_sendMessage);
}

void Heavy_EQVU::cVar_Yzw3qUPi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Te7nZBRQ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_tlZU6nWW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1L1t8J8i_sendMessage);
}

void Heavy_EQVU::cVar_HUyJTvUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_TAaZ1yvK_sendMessage);
}

void Heavy_EQVU::cVar_X9yLqaPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_jY1CBlW6_sendMessage);
}

void Heavy_EQVU::cMsg_a5u23spx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_e68U04br_sendMessage);
}

void Heavy_EQVU::cSystem_e68U04br_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FdHjBklj, HV_BINOP_DIVIDE, 1, m, &cBinop_FdHjBklj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cYVStyJg_sendMessage);
}

void Heavy_EQVU::cUnop_wzGFygnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_dM34NR7H_sendMessage);
}

void Heavy_EQVU::cBinop_vTmPgNmO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yzw3qUPi, 0, m, &cVar_Yzw3qUPi_sendMessage);
}

void Heavy_EQVU::cBinop_AFd5ATFK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_0jFsPfHJ_sendMessage);
}

void Heavy_EQVU::cBinop_0jFsPfHJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XuLL6Pqf, HV_BINOP_POW, 1, m, &cBinop_XuLL6Pqf_sendMessage);
  cMsg_sXULuEzu_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_XuLL6Pqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_vTmPgNmO_sendMessage);
}

void Heavy_EQVU::cMsg_sXULuEzu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_XuLL6Pqf, HV_BINOP_POW, 0, m, &cBinop_XuLL6Pqf_sendMessage);
}

void Heavy_EQVU::cIf_BfmVAjJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_oCc1CQaG_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_5QJQ0HQH_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_ZWnl180a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_NOyxfcgr_sendMessage);
}

void Heavy_EQVU::cBinop_5QJQ0HQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_ZWnl180a_sendMessage);
}

void Heavy_EQVU::cBinop_NOyxfcgr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_bW4OeTyO_sendMessage);
}

void Heavy_EQVU::cBinop_bW4OeTyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_AFd5ATFK_sendMessage);
}

void Heavy_EQVU::cCast_mtXpsTNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BfmVAjJo, 0, m, &cIf_BfmVAjJo_sendMessage);
}

void Heavy_EQVU::cCast_5gOWHd06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_uJ0G982E_sendMessage);
}

void Heavy_EQVU::cBinop_uJ0G982E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_BfmVAjJo, 1, m, &cIf_BfmVAjJo_sendMessage);
}

void Heavy_EQVU::cMsg_oCc1CQaG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_AFd5ATFK_sendMessage);
}

void Heavy_EQVU::cBinop_qvzoOFQB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Di2qUwww_sendMessage);
}

void Heavy_EQVU::cBinop_Di2qUwww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xTNnFY3l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_syUDUuHF_sendMessage);
}

void Heavy_EQVU::cBinop_TAaZ1yvK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_RCo0HNIX_sendMessage);
}

void Heavy_EQVU::cBinop_RCo0HNIX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LrbmqkGQ_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_eIrhzf3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Q0OuA4w6, 0, m, NULL);
}

void Heavy_EQVU::cMsg_RGfjBDNQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9wCbqQsf, 0, m, NULL);
}

void Heavy_EQVU::cMsg_qHjxPM5W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ajwFzW5o, 0, m, NULL);
}

void Heavy_EQVU::cMsg_zJ2a5rsk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Js6prR57, 0, m, NULL);
}

void Heavy_EQVU::cMsg_5pAZ4xYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_WLr4bZdA, 0, m, NULL);
}

void Heavy_EQVU::cCast_iX6ABeJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_oN0aNbR2_sendMessage);
}

void Heavy_EQVU::cCast_nlaVAru1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_7TZS6Svl_sendMessage);
}

void Heavy_EQVU::cSend_74dCBaiL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_G8SQy3qm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_wTAV9Geo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_LrbmqkGQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_dkRKpQ0E_sendMessage);
}

void Heavy_EQVU::cBinop_dkRKpQ0E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6hSTVR1C, HV_BINOP_MULTIPLY, 1, m, &cBinop_6hSTVR1C_sendMessage);
}

void Heavy_EQVU::cBinop_6hSTVR1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_gev8qXqf_sendMessage);
}

void Heavy_EQVU::cBinop_gev8qXqf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_wTAV9Geo_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XUPApFz, HV_BINOP_DIVIDE, 0, m, &cBinop_6XUPApFz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_282J31Bh, HV_BINOP_MULTIPLY, 0, m, &cBinop_282J31Bh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sypZmdR4, HV_BINOP_MULTIPLY, 0, m, &cBinop_sypZmdR4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CfxnBY0N, HV_BINOP_DIVIDE, 0, m, &cBinop_CfxnBY0N_sendMessage);
}

void Heavy_EQVU::cMsg_3OzzdCMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_SvBIgvnW_sendMessage);
}

void Heavy_EQVU::cBinop_SvBIgvnW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LyfnXFyA_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OPWVzYMt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_D6ER79jn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kNdaFnYB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EBa0PlDR_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BXGDJRxv_sendMessage);
}

void Heavy_EQVU::cBinop_poJ6crPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eIrhzf3w_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_gDIgeeTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RGfjBDNQ_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_p9WkTM90_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qHjxPM5W_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_qRgefdjC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zJ2a5rsk_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_Sl6X4063_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5pAZ4xYi_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_syUDUuHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yzw3qUPi, 0, m, &cVar_Yzw3qUPi_sendMessage);
}

void Heavy_EQVU::cCast_xTNnFY3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HUyJTvUy, 1, m, &cVar_HUyJTvUy_sendMessage);
}

void Heavy_EQVU::cCast_LyfnXFyA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cCast_OPWVzYMt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sl6X4063, HV_BINOP_MULTIPLY, 0, m, &cBinop_Sl6X4063_sendMessage);
}

void Heavy_EQVU::cCast_D6ER79jn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qRgefdjC, HV_BINOP_MULTIPLY, 0, m, &cBinop_qRgefdjC_sendMessage);
}

void Heavy_EQVU::cCast_kNdaFnYB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p9WkTM90, HV_BINOP_MULTIPLY, 0, m, &cBinop_p9WkTM90_sendMessage);
}

void Heavy_EQVU::cCast_EBa0PlDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gDIgeeTO, HV_BINOP_MULTIPLY, 0, m, &cBinop_gDIgeeTO_sendMessage);
}

void Heavy_EQVU::cCast_BXGDJRxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poJ6crPg, HV_BINOP_MULTIPLY, 0, m, &cBinop_poJ6crPg_sendMessage);
}

void Heavy_EQVU::cCast_Te7nZBRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HUyJTvUy, 0, m, &cVar_HUyJTvUy_sendMessage);
}

void Heavy_EQVU::cCast_1L1t8J8i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JZuL7JNh, 0, m, &cVar_JZuL7JNh_sendMessage);
}

void Heavy_EQVU::cSend_TS6vrgTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_FJNHv1xN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3GwVy4IY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bxZmGQp6_sendMessage);
}

void Heavy_EQVU::cCast_bxZmGQp6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R3I3Nwij_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_3GwVy4IY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZTlBfN3, HV_BINOP_POW, 1, m, &cBinop_uZTlBfN3_sendMessage);
}

void Heavy_EQVU::cMsg_R3I3Nwij_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_uZTlBfN3, HV_BINOP_POW, 0, m, &cBinop_uZTlBfN3_sendMessage);
}

void Heavy_EQVU::cBinop_uZTlBfN3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_TS6vrgTw_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6XUPApFz, HV_BINOP_DIVIDE, 1, m, &cBinop_6XUPApFz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_282J31Bh, HV_BINOP_MULTIPLY, 1, m, &cBinop_282J31Bh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sypZmdR4, HV_BINOP_MULTIPLY, 1, m, &cBinop_sypZmdR4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_CfxnBY0N, HV_BINOP_DIVIDE, 1, m, &cBinop_CfxnBY0N_sendMessage);
}

void Heavy_EQVU::cCast_n9hSroge_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yzw3qUPi, 0, m, &cVar_Yzw3qUPi_sendMessage);
}

void Heavy_EQVU::cCast_GM2AnbLR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X9yLqaPs, 0, m, &cVar_X9yLqaPs_sendMessage);
}

void Heavy_EQVU::cCast_l7ay5DTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_X9yLqaPs, 0, m, &cVar_X9yLqaPs_sendMessage);
}

void Heavy_EQVU::cCast_7DRvWloW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yzw3qUPi, 0, m, &cVar_Yzw3qUPi_sendMessage);
}

void Heavy_EQVU::cBinop_Ly9TgFGe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JZuL7JNh, 1, m, &cVar_JZuL7JNh_sendMessage);
}

void Heavy_EQVU::cBinop_6XUPApFz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ly9TgFGe_sendMessage);
}

void Heavy_EQVU::cBinop_282J31Bh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_1H5oSXm6_sendMessage);
}

void Heavy_EQVU::cBinop_1H5oSXm6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_poJ6crPg, HV_BINOP_MULTIPLY, 1, m, &cBinop_poJ6crPg_sendMessage);
}

void Heavy_EQVU::cBinop_sZ8PVho7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gDIgeeTO, HV_BINOP_MULTIPLY, 1, m, &cBinop_gDIgeeTO_sendMessage);
}

void Heavy_EQVU::cBinop_sypZmdR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mvpgFuIy_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_mvpgFuIy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_aYhZyGsn_sendMessage);
}

void Heavy_EQVU::cBinop_aYhZyGsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p9WkTM90, HV_BINOP_MULTIPLY, 1, m, &cBinop_p9WkTM90_sendMessage);
}

void Heavy_EQVU::cBinop_5qhLoGAE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qRgefdjC, HV_BINOP_MULTIPLY, 1, m, &cBinop_qRgefdjC_sendMessage);
}

void Heavy_EQVU::cBinop_CfxnBY0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4q1fQFIk_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_4q1fQFIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_8Xgmk3FM_sendMessage);
}

void Heavy_EQVU::cBinop_8Xgmk3FM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Sl6X4063, HV_BINOP_MULTIPLY, 1, m, &cBinop_Sl6X4063_sendMessage);
}

void Heavy_EQVU::cMsg_Y4KjAS8w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_wzGFygnz_sendMessage);
}

void Heavy_EQVU::cBinop_dM34NR7H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FdHjBklj, HV_BINOP_DIVIDE, 0, m, &cBinop_FdHjBklj_sendMessage);
}

void Heavy_EQVU::cCast_cYVStyJg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y4KjAS8w_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_FdHjBklj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_L1cxdLQ7, HV_BINOP_MULTIPLY, 1, m, &cBinop_L1cxdLQ7_sendMessage);
}

void Heavy_EQVU::cBinop_L1cxdLQ7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iX6ABeJ5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nlaVAru1_sendMessage);
}

void Heavy_EQVU::cBinop_w0kN6Cck_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_na5F2YZJ_sendMessage);
}

void Heavy_EQVU::cBinop_na5F2YZJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_qvzoOFQB_sendMessage);
}

void Heavy_EQVU::cUnop_RM9fZsVW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_tAyQBk96_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cUnop_gKx89BjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_hpSRd7uy_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_Hm67ZKuc_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_sQmqFyqb_sendMessage);
}

void Heavy_EQVU::cBinop_UY4lnU9c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_A4wGsoLi_sendMessage);
}

void Heavy_EQVU::cBinop_A4wGsoLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQc5RPRI, HV_BINOP_MULTIPLY, 0, m, &cBinop_pQc5RPRI_sendMessage);
}

void Heavy_EQVU::cVar_c8oijmh5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lU918Rbp_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_A9UAA8n9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_4cRd4GAs_sendMessage);
}

void Heavy_EQVU::cBinop_4cRd4GAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_CagWVAGc_sendMessage);
}

void Heavy_EQVU::cVar_ODlgcnSi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uwVCAMiq_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_UY4lnU9c_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nG6pAUNp_sendMessage);
}

void Heavy_EQVU::cVar_k60gT1g6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_nFFShHYL_sendMessage);
}

void Heavy_EQVU::cVar_ID7lTvNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_A9UAA8n9_sendMessage);
}

void Heavy_EQVU::cMsg_IF4r9iGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_A55BgAPC_sendMessage);
}

void Heavy_EQVU::cSystem_A55BgAPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eu4y6L1X, HV_BINOP_DIVIDE, 1, m, &cBinop_Eu4y6L1X_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iBYUiybf_sendMessage);
}

void Heavy_EQVU::cUnop_gHbqTsPh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_NSyX2tSk_sendMessage);
}

void Heavy_EQVU::cBinop_OQD5fw50_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ODlgcnSi, 0, m, &cVar_ODlgcnSi_sendMessage);
}

void Heavy_EQVU::cBinop_QtMHMwax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_TvrDHz1G_sendMessage);
}

void Heavy_EQVU::cBinop_TvrDHz1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8gisnOax, HV_BINOP_POW, 1, m, &cBinop_8gisnOax_sendMessage);
  cMsg_4uZpbQjk_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_8gisnOax_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_OQD5fw50_sendMessage);
}

void Heavy_EQVU::cMsg_4uZpbQjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8gisnOax, HV_BINOP_POW, 0, m, &cBinop_8gisnOax_sendMessage);
}

void Heavy_EQVU::cIf_brp4xAbm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_AGAP9d5p_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_bg1APYmS_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_aaLB3IUd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_F8g6o4xA_sendMessage);
}

void Heavy_EQVU::cBinop_bg1APYmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_aaLB3IUd_sendMessage);
}

void Heavy_EQVU::cBinop_F8g6o4xA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_zgvPS8Kl_sendMessage);
}

void Heavy_EQVU::cBinop_zgvPS8Kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_QtMHMwax_sendMessage);
}

void Heavy_EQVU::cCast_2112cEWb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_brp4xAbm, 0, m, &cIf_brp4xAbm_sendMessage);
}

void Heavy_EQVU::cCast_nimJgXfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_NbhMmJdS_sendMessage);
}

void Heavy_EQVU::cBinop_NbhMmJdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_brp4xAbm, 1, m, &cIf_brp4xAbm_sendMessage);
}

void Heavy_EQVU::cMsg_AGAP9d5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_QtMHMwax_sendMessage);
}

void Heavy_EQVU::cBinop_3cwF5I6i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_VNf5UkBM_sendMessage);
}

void Heavy_EQVU::cBinop_VNf5UkBM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jHo5ER6B_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rWXKpiVd_sendMessage);
}

void Heavy_EQVU::cBinop_nFFShHYL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_x90vEWAa_sendMessage);
}

void Heavy_EQVU::cBinop_x90vEWAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JOksr8i1_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_PRoClrVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dqvRdwkB, 0, m, NULL);
}

void Heavy_EQVU::cMsg_u3u3Fjt1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9jjU45KP, 0, m, NULL);
}

void Heavy_EQVU::cMsg_2HKgmGJ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_XO4nZ9nT, 0, m, NULL);
}

void Heavy_EQVU::cMsg_6mw9JqNY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_JzpBomMY, 0, m, NULL);
}

void Heavy_EQVU::cMsg_YXgnq8wY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_MfLY8jSv, 0, m, NULL);
}

void Heavy_EQVU::cCast_6y7vnJh2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_RM9fZsVW_sendMessage);
}

void Heavy_EQVU::cCast_UqoZYur6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_gKx89BjN_sendMessage);
}

void Heavy_EQVU::cSend_tAyQBk96_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_hpSRd7uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_8og2WXrI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_JOksr8i1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_MFI81ioq_sendMessage);
}

void Heavy_EQVU::cBinop_MFI81ioq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0hcAj6ej, HV_BINOP_MULTIPLY, 1, m, &cBinop_0hcAj6ej_sendMessage);
}

void Heavy_EQVU::cBinop_0hcAj6ej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_7wHsqvQx_sendMessage);
}

void Heavy_EQVU::cBinop_7wHsqvQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_8og2WXrI_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wF1xj8F3, HV_BINOP_DIVIDE, 0, m, &cBinop_wF1xj8F3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sTEijqvf, HV_BINOP_MULTIPLY, 0, m, &cBinop_sTEijqvf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_z3v5XmsL, HV_BINOP_MULTIPLY, 0, m, &cBinop_z3v5XmsL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0NAHS5rG, HV_BINOP_DIVIDE, 0, m, &cBinop_0NAHS5rG_sendMessage);
}

void Heavy_EQVU::cMsg_lU918Rbp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_wc9YMSVV_sendMessage);
}

void Heavy_EQVU::cBinop_wc9YMSVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0cEuYbUt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uW4uhfPs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8cABsINx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_29jiH7ac_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kOIvjY3L_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_k74Uczpq_sendMessage);
}

void Heavy_EQVU::cBinop_nJz2NH6Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PRoClrVb_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_gJ0xHWZ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u3u3Fjt1_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_rBzQ4UVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2HKgmGJ1_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_1kU05QDa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6mw9JqNY_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_Lmq0IexL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YXgnq8wY_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_jHo5ER6B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k60gT1g6, 1, m, &cVar_k60gT1g6_sendMessage);
}

void Heavy_EQVU::cCast_rWXKpiVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ODlgcnSi, 0, m, &cVar_ODlgcnSi_sendMessage);
}

void Heavy_EQVU::cCast_kOIvjY3L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gJ0xHWZ2, HV_BINOP_MULTIPLY, 0, m, &cBinop_gJ0xHWZ2_sendMessage);
}

void Heavy_EQVU::cCast_0cEuYbUt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cCast_29jiH7ac_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rBzQ4UVb, HV_BINOP_MULTIPLY, 0, m, &cBinop_rBzQ4UVb_sendMessage);
}

void Heavy_EQVU::cCast_8cABsINx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1kU05QDa, HV_BINOP_MULTIPLY, 0, m, &cBinop_1kU05QDa_sendMessage);
}

void Heavy_EQVU::cCast_uW4uhfPs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lmq0IexL, HV_BINOP_MULTIPLY, 0, m, &cBinop_Lmq0IexL_sendMessage);
}

void Heavy_EQVU::cCast_k74Uczpq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nJz2NH6Y, HV_BINOP_MULTIPLY, 0, m, &cBinop_nJz2NH6Y_sendMessage);
}

void Heavy_EQVU::cCast_uwVCAMiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_k60gT1g6, 0, m, &cVar_k60gT1g6_sendMessage);
}

void Heavy_EQVU::cCast_nG6pAUNp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c8oijmh5, 0, m, &cVar_c8oijmh5_sendMessage);
}

void Heavy_EQVU::cSend_ssDU5JJc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_CagWVAGc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pxCVYbLf_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YIPcfsaI_sendMessage);
}

void Heavy_EQVU::cCast_YIPcfsaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JAdK5JkK_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_pxCVYbLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzDkalyP, HV_BINOP_POW, 1, m, &cBinop_TzDkalyP_sendMessage);
}

void Heavy_EQVU::cMsg_JAdK5JkK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_TzDkalyP, HV_BINOP_POW, 0, m, &cBinop_TzDkalyP_sendMessage);
}

void Heavy_EQVU::cBinop_TzDkalyP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ssDU5JJc_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wF1xj8F3, HV_BINOP_DIVIDE, 1, m, &cBinop_wF1xj8F3_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sTEijqvf, HV_BINOP_MULTIPLY, 1, m, &cBinop_sTEijqvf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_z3v5XmsL, HV_BINOP_MULTIPLY, 1, m, &cBinop_z3v5XmsL_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0NAHS5rG, HV_BINOP_DIVIDE, 1, m, &cBinop_0NAHS5rG_sendMessage);
}

void Heavy_EQVU::cCast_QCT9PNqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ODlgcnSi, 0, m, &cVar_ODlgcnSi_sendMessage);
}

void Heavy_EQVU::cCast_ywdnzvUe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ID7lTvNB, 0, m, &cVar_ID7lTvNB_sendMessage);
}

void Heavy_EQVU::cCast_L7hAZbx0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ID7lTvNB, 0, m, &cVar_ID7lTvNB_sendMessage);
}

void Heavy_EQVU::cCast_FV5745Qh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ODlgcnSi, 0, m, &cVar_ODlgcnSi_sendMessage);
}

void Heavy_EQVU::cBinop_QWxI9GVe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_c8oijmh5, 1, m, &cVar_c8oijmh5_sendMessage);
}

void Heavy_EQVU::cBinop_wF1xj8F3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_QWxI9GVe_sendMessage);
}

void Heavy_EQVU::cBinop_sTEijqvf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_PLQfAk7o_sendMessage);
}

void Heavy_EQVU::cBinop_PLQfAk7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nJz2NH6Y, HV_BINOP_MULTIPLY, 1, m, &cBinop_nJz2NH6Y_sendMessage);
}

void Heavy_EQVU::cBinop_Hm67ZKuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gJ0xHWZ2, HV_BINOP_MULTIPLY, 1, m, &cBinop_gJ0xHWZ2_sendMessage);
}

void Heavy_EQVU::cBinop_z3v5XmsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6RqZlTkD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_6RqZlTkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_x8DcN1Mf_sendMessage);
}

void Heavy_EQVU::cBinop_x8DcN1Mf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rBzQ4UVb, HV_BINOP_MULTIPLY, 1, m, &cBinop_rBzQ4UVb_sendMessage);
}

void Heavy_EQVU::cBinop_sQmqFyqb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1kU05QDa, HV_BINOP_MULTIPLY, 1, m, &cBinop_1kU05QDa_sendMessage);
}

void Heavy_EQVU::cBinop_0NAHS5rG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SexiKVHU_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_SexiKVHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_FKLhnvtz_sendMessage);
}

void Heavy_EQVU::cBinop_FKLhnvtz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Lmq0IexL, HV_BINOP_MULTIPLY, 1, m, &cBinop_Lmq0IexL_sendMessage);
}

void Heavy_EQVU::cMsg_AzUq834e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_gHbqTsPh_sendMessage);
}

void Heavy_EQVU::cBinop_NSyX2tSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Eu4y6L1X, HV_BINOP_DIVIDE, 0, m, &cBinop_Eu4y6L1X_sendMessage);
}

void Heavy_EQVU::cCast_iBYUiybf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AzUq834e_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_Eu4y6L1X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pQc5RPRI, HV_BINOP_MULTIPLY, 1, m, &cBinop_pQc5RPRI_sendMessage);
}

void Heavy_EQVU::cBinop_pQc5RPRI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6y7vnJh2_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UqoZYur6_sendMessage);
}

void Heavy_EQVU::cBinop_9N4wpUgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_UnzY1XCY_sendMessage);
}

void Heavy_EQVU::cBinop_UnzY1XCY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_3cwF5I6i_sendMessage);
}

void Heavy_EQVU::cUnop_Vzb51ut6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_V9xBrEmt_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cUnop_xPF8zlXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Rw0Ay6jr_sendMessage(_c, 0, m);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_k2XNqXU9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_vkJCgqTj_sendMessage);
}

void Heavy_EQVU::cBinop_vrvbzwld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_ysrsw1XL_sendMessage);
}

void Heavy_EQVU::cBinop_ysrsw1XL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LSf21Dhc, HV_BINOP_MULTIPLY, 0, m, &cBinop_LSf21Dhc_sendMessage);
}

void Heavy_EQVU::cVar_Ie87y4sx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Y9mmc8t6_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_NTxwNXJo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_Q6Ao1asr_sendMessage);
}

void Heavy_EQVU::cBinop_Q6Ao1asr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_LBB0lYyW_sendMessage);
}

void Heavy_EQVU::cVar_yFRteV1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PWH47XjR_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_vrvbzwld_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_P2tFVGiB_sendMessage);
}

void Heavy_EQVU::cVar_yRl3brxX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_wsXe46FP_sendMessage);
}

void Heavy_EQVU::cVar_dFXOpnjv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_NTxwNXJo_sendMessage);
}

void Heavy_EQVU::cMsg_gey0zGWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_cNZPBDY0_sendMessage);
}

void Heavy_EQVU::cSystem_cNZPBDY0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6BeQ8pw9, HV_BINOP_DIVIDE, 1, m, &cBinop_6BeQ8pw9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ds3HuPdg_sendMessage);
}

void Heavy_EQVU::cUnop_kAtYE4A1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_fnMBL1rY_sendMessage);
}

void Heavy_EQVU::cBinop_jdEuwIUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yFRteV1H, 0, m, &cVar_yFRteV1H_sendMessage);
}

void Heavy_EQVU::cBinop_nXDrttpD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_HFaxYqaP_sendMessage);
}

void Heavy_EQVU::cBinop_HFaxYqaP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nRQiRX59, HV_BINOP_POW, 1, m, &cBinop_nRQiRX59_sendMessage);
  cMsg_3pj3rcv9_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_nRQiRX59_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_jdEuwIUm_sendMessage);
}

void Heavy_EQVU::cMsg_3pj3rcv9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_nRQiRX59, HV_BINOP_POW, 0, m, &cBinop_nRQiRX59_sendMessage);
}

void Heavy_EQVU::cIf_FaYe0fWf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_VvXQscmo_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_EH7HywkV_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_jg2zBAHY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_7Efp3z6M_sendMessage);
}

void Heavy_EQVU::cBinop_EH7HywkV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_jg2zBAHY_sendMessage);
}

void Heavy_EQVU::cBinop_7Efp3z6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_UVXLZ2Ux_sendMessage);
}

void Heavy_EQVU::cBinop_UVXLZ2Ux_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_nXDrttpD_sendMessage);
}

void Heavy_EQVU::cCast_fxH0p5Io_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FaYe0fWf, 0, m, &cIf_FaYe0fWf_sendMessage);
}

void Heavy_EQVU::cCast_qLdzd0Hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_zqMGrfQD_sendMessage);
}

void Heavy_EQVU::cBinop_zqMGrfQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FaYe0fWf, 1, m, &cIf_FaYe0fWf_sendMessage);
}

void Heavy_EQVU::cMsg_VvXQscmo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_nXDrttpD_sendMessage);
}

void Heavy_EQVU::cBinop_wsXe46FP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_1Br6d1AO_sendMessage);
}

void Heavy_EQVU::cBinop_1Br6d1AO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_m4LThO29_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_dmeEgFAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_uSXzwdxQ_sendMessage);
}

void Heavy_EQVU::cBinop_uSXzwdxQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FwKmdVMG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AqIvnEDq_sendMessage);
}

void Heavy_EQVU::cMsg_XwgtBgSI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_SmX8RxTU, 0, m, NULL);
}

void Heavy_EQVU::cMsg_uT6fyCRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_QF0fweuu, 0, m, NULL);
}

void Heavy_EQVU::cMsg_YQc7Gjx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_VYMCtIzC, 0, m, NULL);
}

void Heavy_EQVU::cMsg_uyoEdBL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_NzEar4Sy, 0, m, NULL);
}

void Heavy_EQVU::cMsg_JmDnUNCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_bsCYE9U2, 0, m, NULL);
}

void Heavy_EQVU::cCast_Y1sT6DsH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_xPF8zlXU_sendMessage);
}

void Heavy_EQVU::cCast_EIhuSpas_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_Vzb51ut6_sendMessage);
}

void Heavy_EQVU::cSend_V9xBrEmt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_Rw0Ay6jr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_oeKyAdWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_m4LThO29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_gCdLmmq3_sendMessage);
}

void Heavy_EQVU::cBinop_gCdLmmq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QSxPZBnF, HV_BINOP_MULTIPLY, 1, m, &cBinop_QSxPZBnF_sendMessage);
}

void Heavy_EQVU::cBinop_QSxPZBnF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_N3YQ5wBZ_sendMessage);
}

void Heavy_EQVU::cBinop_N3YQ5wBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_oeKyAdWI_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a1R4gMFR, HV_BINOP_DIVIDE, 0, m, &cBinop_a1R4gMFR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ja8edl1H, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ja8edl1H_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ktyfh8NJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ktyfh8NJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DyTgeiMq, HV_BINOP_DIVIDE, 0, m, &cBinop_DyTgeiMq_sendMessage);
}

void Heavy_EQVU::cMsg_Y9mmc8t6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_4kUj0oFy_sendMessage);
}

void Heavy_EQVU::cBinop_4kUj0oFy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iBm9BUqQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_PoCKW8EY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SWLSQPqY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IgyZM0Kl_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5eHPY6hi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BOkKDwss_sendMessage);
}

void Heavy_EQVU::cBinop_O79db6vu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XwgtBgSI_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_V59hPvtY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uT6fyCRb_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_Jq8K51ut_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YQc7Gjx9_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_tQcPHpUM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_uyoEdBL6_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_VwqSwGHU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JmDnUNCG_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_AqIvnEDq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yFRteV1H, 0, m, &cVar_yFRteV1H_sendMessage);
}

void Heavy_EQVU::cCast_FwKmdVMG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yRl3brxX, 1, m, &cVar_yRl3brxX_sendMessage);
}

void Heavy_EQVU::cCast_SWLSQPqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tQcPHpUM, HV_BINOP_MULTIPLY, 0, m, &cBinop_tQcPHpUM_sendMessage);
}

void Heavy_EQVU::cCast_BOkKDwss_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O79db6vu, HV_BINOP_MULTIPLY, 0, m, &cBinop_O79db6vu_sendMessage);
}

void Heavy_EQVU::cCast_IgyZM0Kl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jq8K51ut, HV_BINOP_MULTIPLY, 0, m, &cBinop_Jq8K51ut_sendMessage);
}

void Heavy_EQVU::cCast_PoCKW8EY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VwqSwGHU, HV_BINOP_MULTIPLY, 0, m, &cBinop_VwqSwGHU_sendMessage);
}

void Heavy_EQVU::cCast_5eHPY6hi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V59hPvtY, HV_BINOP_MULTIPLY, 0, m, &cBinop_V59hPvtY_sendMessage);
}

void Heavy_EQVU::cCast_iBm9BUqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cCast_P2tFVGiB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ie87y4sx, 0, m, &cVar_Ie87y4sx_sendMessage);
}

void Heavy_EQVU::cCast_PWH47XjR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yRl3brxX, 0, m, &cVar_yRl3brxX_sendMessage);
}

void Heavy_EQVU::cSend_9uLUwrPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_LBB0lYyW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VmlnwG6b_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H7QehBR4_sendMessage);
}

void Heavy_EQVU::cCast_H7QehBR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EWIRMDMP_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_VmlnwG6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Qi8as6b, HV_BINOP_POW, 1, m, &cBinop_3Qi8as6b_sendMessage);
}

void Heavy_EQVU::cMsg_EWIRMDMP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Qi8as6b, HV_BINOP_POW, 0, m, &cBinop_3Qi8as6b_sendMessage);
}

void Heavy_EQVU::cBinop_3Qi8as6b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9uLUwrPf_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a1R4gMFR, HV_BINOP_DIVIDE, 1, m, &cBinop_a1R4gMFR_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ja8edl1H, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ja8edl1H_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ktyfh8NJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ktyfh8NJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_DyTgeiMq, HV_BINOP_DIVIDE, 1, m, &cBinop_DyTgeiMq_sendMessage);
}

void Heavy_EQVU::cCast_rQUVlPdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dFXOpnjv, 0, m, &cVar_dFXOpnjv_sendMessage);
}

void Heavy_EQVU::cCast_5lUwiYZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yFRteV1H, 0, m, &cVar_yFRteV1H_sendMessage);
}

void Heavy_EQVU::cCast_XFI4JJUX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dFXOpnjv, 0, m, &cVar_dFXOpnjv_sendMessage);
}

void Heavy_EQVU::cCast_RG2Bq9iF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yFRteV1H, 0, m, &cVar_yFRteV1H_sendMessage);
}

void Heavy_EQVU::cBinop_r5beVYJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Ie87y4sx, 1, m, &cVar_Ie87y4sx_sendMessage);
}

void Heavy_EQVU::cBinop_a1R4gMFR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_r5beVYJU_sendMessage);
}

void Heavy_EQVU::cBinop_Ja8edl1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_DpG5K5pq_sendMessage);
}

void Heavy_EQVU::cBinop_DpG5K5pq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_O79db6vu, HV_BINOP_MULTIPLY, 1, m, &cBinop_O79db6vu_sendMessage);
}

void Heavy_EQVU::cBinop_k2XNqXU9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V59hPvtY, HV_BINOP_MULTIPLY, 1, m, &cBinop_V59hPvtY_sendMessage);
}

void Heavy_EQVU::cBinop_Ktyfh8NJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_VBqVe1Mm_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_VBqVe1Mm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_b9Ia4Sly_sendMessage);
}

void Heavy_EQVU::cBinop_b9Ia4Sly_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jq8K51ut, HV_BINOP_MULTIPLY, 1, m, &cBinop_Jq8K51ut_sendMessage);
}

void Heavy_EQVU::cBinop_vkJCgqTj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tQcPHpUM, HV_BINOP_MULTIPLY, 1, m, &cBinop_tQcPHpUM_sendMessage);
}

void Heavy_EQVU::cBinop_DyTgeiMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YHvByy6v_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_YHvByy6v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_WS8YFfSB_sendMessage);
}

void Heavy_EQVU::cBinop_WS8YFfSB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VwqSwGHU, HV_BINOP_MULTIPLY, 1, m, &cBinop_VwqSwGHU_sendMessage);
}

void Heavy_EQVU::cMsg_IRGNYAqd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_kAtYE4A1_sendMessage);
}

void Heavy_EQVU::cBinop_fnMBL1rY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6BeQ8pw9, HV_BINOP_DIVIDE, 0, m, &cBinop_6BeQ8pw9_sendMessage);
}

void Heavy_EQVU::cCast_ds3HuPdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IRGNYAqd_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_6BeQ8pw9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LSf21Dhc, HV_BINOP_MULTIPLY, 1, m, &cBinop_LSf21Dhc_sendMessage);
}

void Heavy_EQVU::cBinop_LSf21Dhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_EIhuSpas_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Y1sT6DsH_sendMessage);
}

void Heavy_EQVU::cBinop_mLCQDoNs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_VxY9eExH_sendMessage);
}

void Heavy_EQVU::cBinop_VxY9eExH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_dmeEgFAr_sendMessage);
}

void Heavy_EQVU::cUnop_EpWVEU0S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_mM6bPtO3_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KBMUfp4W, HV_BINOP_MULTIPLY, 0, m, &cBinop_KBMUfp4W_sendMessage);
}

void Heavy_EQVU::cUnop_eW1oVMIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7qWHZLYc_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_a43fyanO, HV_BINOP_MULTIPLY, 0, m, &cBinop_a43fyanO_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jFlOPpoT, HV_BINOP_MULTIPLY, 0, m, &cBinop_jFlOPpoT_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_adsWdYMC, HV_BINOP_MULTIPLY, 0, m, &cBinop_adsWdYMC_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oYSfJxXs, HV_BINOP_MULTIPLY, 0, m, &cBinop_oYSfJxXs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oehz3O34, HV_BINOP_MULTIPLY, 0, m, &cBinop_Oehz3O34_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_obhYkSlr, HV_BINOP_MULTIPLY, 0, m, &cBinop_obhYkSlr_sendMessage);
}

void Heavy_EQVU::cBinop_uL3pqwpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_c6bThHYs_sendMessage);
}

void Heavy_EQVU::cBinop_c6bThHYs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eb5r1OBH, HV_BINOP_MULTIPLY, 0, m, &cBinop_eb5r1OBH_sendMessage);
}

void Heavy_EQVU::cVar_UWn17TPf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7JxHY7Dv_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_81Jehnme_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_TfAuDqGT_sendMessage);
}

void Heavy_EQVU::cBinop_TfAuDqGT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_gcPTKJkX_sendMessage);
}

void Heavy_EQVU::cVar_3CNyzwxI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tmprAF52_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_uL3pqwpM_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z841HPvU_sendMessage);
}

void Heavy_EQVU::cVar_h4AeYOq5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Qumdr5PZ_sendMessage);
}

void Heavy_EQVU::cVar_AP3bOOXW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_81Jehnme_sendMessage);
}

void Heavy_EQVU::cUnop_L4JVUMkf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_qs22KhWw_sendMessage);
}

void Heavy_EQVU::cMsg_WFLmZRRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_4zPGb1aQ_sendMessage);
}

void Heavy_EQVU::cSystem_4zPGb1aQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2OVnXJo7, HV_BINOP_DIVIDE, 1, m, &cBinop_2OVnXJo7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H5aqbkG3_sendMessage);
}

void Heavy_EQVU::cUnop_mjXPYpdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_OjGZhkkP_sendMessage);
}

void Heavy_EQVU::cBinop_zfyy1mOn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3CNyzwxI, 0, m, &cVar_3CNyzwxI_sendMessage);
}

void Heavy_EQVU::cBinop_HbujLcB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_1eJIPoyv_sendMessage);
}

void Heavy_EQVU::cBinop_1eJIPoyv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gczueJs3, HV_BINOP_POW, 1, m, &cBinop_gczueJs3_sendMessage);
  cMsg_9FTCphag_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_gczueJs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_zfyy1mOn_sendMessage);
}

void Heavy_EQVU::cMsg_9FTCphag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gczueJs3, HV_BINOP_POW, 0, m, &cBinop_gczueJs3_sendMessage);
}

void Heavy_EQVU::cIf_Z8uzZ9k2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_bllm1xiS_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_RbF9UlCN_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_uqIsOiRV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_3lCTKBXP_sendMessage);
}

void Heavy_EQVU::cBinop_RbF9UlCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_uqIsOiRV_sendMessage);
}

void Heavy_EQVU::cBinop_3lCTKBXP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_m5gDtDmi_sendMessage);
}

void Heavy_EQVU::cBinop_m5gDtDmi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HbujLcB2_sendMessage);
}

void Heavy_EQVU::cCast_QgI4mafY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_zImFJVAO_sendMessage);
}

void Heavy_EQVU::cCast_t6e6wlaM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Z8uzZ9k2, 0, m, &cIf_Z8uzZ9k2_sendMessage);
}

void Heavy_EQVU::cBinop_zImFJVAO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Z8uzZ9k2, 1, m, &cIf_Z8uzZ9k2_sendMessage);
}

void Heavy_EQVU::cMsg_bllm1xiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_HbujLcB2_sendMessage);
}

void Heavy_EQVU::cBinop_Qumdr5PZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_dycds0QX_sendMessage);
}

void Heavy_EQVU::cBinop_dycds0QX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Z1x241HX_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_JMR6Dfps_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_Yfr8CjwH_sendMessage);
}

void Heavy_EQVU::cBinop_Yfr8CjwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DX0P2xNr_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RaHjaj54_sendMessage);
}

void Heavy_EQVU::cMsg_LZOtkW7t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_5RuuDxwH, 0, m, NULL);
}

void Heavy_EQVU::cMsg_lnkbOEYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_qcQlh37Y, 0, m, NULL);
}

void Heavy_EQVU::cMsg_JOklk7Ht_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9bKSPuhR, 0, m, NULL);
}

void Heavy_EQVU::cMsg_wD9xasbB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_o8GQ3X0N, 0, m, NULL);
}

void Heavy_EQVU::cMsg_M5QfpzRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_gIFdyY3a, 0, m, NULL);
}

void Heavy_EQVU::cCast_gZHaizUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_EpWVEU0S_sendMessage);
}

void Heavy_EQVU::cCast_ABWJYosN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_eW1oVMIa_sendMessage);
}

void Heavy_EQVU::cSend_mM6bPtO3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_7qWHZLYc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_OpxKpixF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_Z1x241HX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yglH406N_sendMessage);
}

void Heavy_EQVU::cBinop_yglH406N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KBMUfp4W, HV_BINOP_MULTIPLY, 1, m, &cBinop_KBMUfp4W_sendMessage);
}

void Heavy_EQVU::cBinop_KBMUfp4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_AhbF0VQ4_sendMessage);
}

void Heavy_EQVU::cBinop_AhbF0VQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_arozvre4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2s5oymEj_sendMessage);
}

void Heavy_EQVU::cMsg_7JxHY7Dv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_koYw9xCr_sendMessage);
}

void Heavy_EQVU::cBinop_koYw9xCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yk34hr5T_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wxBPL3TB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lPDKMidr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HQEHIqyc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4zL8qXRb_sendMessage);
}

void Heavy_EQVU::cBinop_6nTkdUyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LZOtkW7t_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_HbARb3Fi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lnkbOEYi_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_lQ4MNKqQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JOklk7Ht_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_5sHsOlKh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wD9xasbB_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_6qieZ5cQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M5QfpzRH_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_RaHjaj54_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3CNyzwxI, 0, m, &cVar_3CNyzwxI_sendMessage);
}

void Heavy_EQVU::cCast_DX0P2xNr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h4AeYOq5, 1, m, &cVar_h4AeYOq5_sendMessage);
}

void Heavy_EQVU::cCast_tmprAF52_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h4AeYOq5, 0, m, &cVar_h4AeYOq5_sendMessage);
}

void Heavy_EQVU::cCast_Z841HPvU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UWn17TPf, 0, m, &cVar_UWn17TPf_sendMessage);
}

void Heavy_EQVU::cSend_qnLsfukN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_gcPTKJkX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_j3muSnk9_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cxBgDxsz_sendMessage);
}

void Heavy_EQVU::cCast_j3muSnk9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KLzI3GeU, HV_BINOP_POW, 1, m, &cBinop_KLzI3GeU_sendMessage);
}

void Heavy_EQVU::cCast_cxBgDxsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_qQGcL7W1_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_qQGcL7W1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KLzI3GeU, HV_BINOP_POW, 0, m, &cBinop_KLzI3GeU_sendMessage);
}

void Heavy_EQVU::cBinop_KLzI3GeU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3JeDAlKc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hpn0EyDK_sendMessage);
}

void Heavy_EQVU::cCast_hW2IA5gj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3CNyzwxI, 0, m, &cVar_3CNyzwxI_sendMessage);
}

void Heavy_EQVU::cCast_8Fk50s3S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AP3bOOXW, 0, m, &cVar_AP3bOOXW_sendMessage);
}

void Heavy_EQVU::cCast_uTciOA7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_AP3bOOXW, 0, m, &cVar_AP3bOOXW_sendMessage);
}

void Heavy_EQVU::cCast_OD0EhNDM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3CNyzwxI, 0, m, &cVar_3CNyzwxI_sendMessage);
}

void Heavy_EQVU::cBinop_qs22KhWw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0xoVagKz, HV_BINOP_MULTIPLY, 1, m, &cBinop_0xoVagKz_sendMessage);
}

void Heavy_EQVU::cBinop_0xoVagKz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_ybxRclDK_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7jZ25tF, HV_BINOP_ADD, 1, m, &cBinop_A7jZ25tF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1yPExRa8, HV_BINOP_ADD, 1, m, &cBinop_1yPExRa8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_v2Rxa0rE, HV_BINOP_SUBTRACT, 1, m, &cBinop_v2Rxa0rE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ytVkKniE, HV_BINOP_SUBTRACT, 1, m, &cBinop_ytVkKniE_sendMessage);
}

void Heavy_EQVU::cCast_arozvre4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_OpxKpixF_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_2s5oymEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0xoVagKz, HV_BINOP_MULTIPLY, 0, m, &cBinop_0xoVagKz_sendMessage);
}

void Heavy_EQVU::cCast_4zL8qXRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6nTkdUyu, HV_BINOP_MULTIPLY, 0, m, &cBinop_6nTkdUyu_sendMessage);
}

void Heavy_EQVU::cCast_wxBPL3TB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5sHsOlKh, HV_BINOP_MULTIPLY, 0, m, &cBinop_5sHsOlKh_sendMessage);
}

void Heavy_EQVU::cCast_HQEHIqyc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HbARb3Fi, HV_BINOP_MULTIPLY, 0, m, &cBinop_HbARb3Fi_sendMessage);
}

void Heavy_EQVU::cCast_yk34hr5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6qieZ5cQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_6qieZ5cQ_sendMessage);
}

void Heavy_EQVU::cCast_lPDKMidr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQ4MNKqQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_lQ4MNKqQ_sendMessage);
}

void Heavy_EQVU::cCast_3JeDAlKc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_qnLsfukN_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uXX2S2Ki_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_S95XcR3l_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Mx6gstwx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7gZ5GYMq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UdGLxr8n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eDje7gZn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ylbGH5CG_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vJJFyRyr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zy6kQrP5_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ywcl53aw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Rfl61pxn_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VLhLGgYH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UVHIDsU7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TLH1Ptzs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZVf39Srd_sendMessage);
}

void Heavy_EQVU::cCast_hpn0EyDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_L4JVUMkf_sendMessage);
}

void Heavy_EQVU::cSend_ybxRclDK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_PKx2IABw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_mjXPYpdc_sendMessage);
}

void Heavy_EQVU::cBinop_OjGZhkkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2OVnXJo7, HV_BINOP_DIVIDE, 0, m, &cBinop_2OVnXJo7_sendMessage);
}

void Heavy_EQVU::cCast_H5aqbkG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PKx2IABw_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_2OVnXJo7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eb5r1OBH, HV_BINOP_MULTIPLY, 1, m, &cBinop_eb5r1OBH_sendMessage);
}

void Heavy_EQVU::cBinop_eb5r1OBH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gZHaizUB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ABWJYosN_sendMessage);
}

void Heavy_EQVU::cBinop_7Nu9tsuH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_oO78TfOg_sendMessage);
}

void Heavy_EQVU::cBinop_a43fyanO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gTiGT0RL, HV_BINOP_ADD, 0, m, &cBinop_gTiGT0RL_sendMessage);
}

void Heavy_EQVU::cBinop_gTiGT0RL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7jZ25tF, HV_BINOP_ADD, 0, m, &cBinop_A7jZ25tF_sendMessage);
}

void Heavy_EQVU::cBinop_xK6659vA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gTiGT0RL, HV_BINOP_ADD, 1, m, &cBinop_gTiGT0RL_sendMessage);
}

void Heavy_EQVU::cCast_S95XcR3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_7Nu9tsuH_sendMessage);
}

void Heavy_EQVU::cCast_uXX2S2Ki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_xK6659vA_sendMessage);
}

void Heavy_EQVU::cBinop_A7jZ25tF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UWn17TPf, 1, m, &cVar_UWn17TPf_sendMessage);
}

void Heavy_EQVU::cBinop_oO78TfOg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_a43fyanO, HV_BINOP_MULTIPLY, 1, m, &cBinop_a43fyanO_sendMessage);
}

void Heavy_EQVU::cBinop_sJzOZKWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jFlOPpoT, HV_BINOP_MULTIPLY, 1, m, &cBinop_jFlOPpoT_sendMessage);
}

void Heavy_EQVU::cBinop_jFlOPpoT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGD09RoN, HV_BINOP_ADD, 0, m, &cBinop_SGD09RoN_sendMessage);
}

void Heavy_EQVU::cBinop_4NN7SGtw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SGD09RoN, HV_BINOP_ADD, 1, m, &cBinop_SGD09RoN_sendMessage);
}

void Heavy_EQVU::cCast_UdGLxr8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_sJzOZKWF_sendMessage);
}

void Heavy_EQVU::cCast_7gZ5GYMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_4NN7SGtw_sendMessage);
}

void Heavy_EQVU::cCast_Mx6gstwx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Bij3Zc1, HV_BINOP_MULTIPLY, 1, m, &cBinop_3Bij3Zc1_sendMessage);
}

void Heavy_EQVU::cBinop_3Bij3Zc1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6nTkdUyu, HV_BINOP_MULTIPLY, 1, m, &cBinop_6nTkdUyu_sendMessage);
}

void Heavy_EQVU::cBinop_SGD09RoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1yPExRa8, HV_BINOP_ADD, 0, m, &cBinop_1yPExRa8_sendMessage);
}

void Heavy_EQVU::cBinop_1yPExRa8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3Bij3Zc1, HV_BINOP_MULTIPLY, 0, m, &cBinop_3Bij3Zc1_sendMessage);
}

void Heavy_EQVU::cBinop_KRqE8ITw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eetHBewC, HV_BINOP_ADD, 1, m, &cBinop_eetHBewC_sendMessage);
}

void Heavy_EQVU::cBinop_4mkNhyes_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_adsWdYMC, HV_BINOP_MULTIPLY, 1, m, &cBinop_adsWdYMC_sendMessage);
}

void Heavy_EQVU::cBinop_adsWdYMC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_eetHBewC, HV_BINOP_ADD, 0, m, &cBinop_eetHBewC_sendMessage);
}

void Heavy_EQVU::cCast_vJJFyRyr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_4mkNhyes_sendMessage);
}

void Heavy_EQVU::cCast_ylbGH5CG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_KRqE8ITw_sendMessage);
}

void Heavy_EQVU::cCast_eDje7gZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_diXi4P62_sendMessage);
}

void Heavy_EQVU::cBinop_utmeSQSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HbARb3Fi, HV_BINOP_MULTIPLY, 1, m, &cBinop_HbARb3Fi_sendMessage);
}

void Heavy_EQVU::cBinop_eetHBewC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_utmeSQSZ, HV_BINOP_MULTIPLY, 0, m, &cBinop_utmeSQSZ_sendMessage);
}

void Heavy_EQVU::cBinop_diXi4P62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_utmeSQSZ, HV_BINOP_MULTIPLY, 1, m, &cBinop_utmeSQSZ_sendMessage);
}

void Heavy_EQVU::cBinop_2UxTPhKy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oYSfJxXs, HV_BINOP_MULTIPLY, 1, m, &cBinop_oYSfJxXs_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oYSfJxXs, HV_BINOP_MULTIPLY, 0, m, &cBinop_oYSfJxXs_sendMessage);
}

void Heavy_EQVU::cBinop_oYSfJxXs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qspjI28f, HV_BINOP_ADD, 0, m, &cBinop_qspjI28f_sendMessage);
}

void Heavy_EQVU::cBinop_qspjI28f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_v2Rxa0rE, HV_BINOP_SUBTRACT, 0, m, &cBinop_v2Rxa0rE_sendMessage);
}

void Heavy_EQVU::cBinop_smDaqxTO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qspjI28f, HV_BINOP_ADD, 1, m, &cBinop_qspjI28f_sendMessage);
}

void Heavy_EQVU::cBinop_v2Rxa0rE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cZFB24z6, HV_BINOP_MULTIPLY, 0, m, &cBinop_cZFB24z6_sendMessage);
}

void Heavy_EQVU::cCast_ywcl53aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_smDaqxTO_sendMessage);
}

void Heavy_EQVU::cCast_Rfl61pxn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2UxTPhKy_sendMessage);
}

void Heavy_EQVU::cCast_zy6kQrP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cZFB24z6, HV_BINOP_MULTIPLY, 1, m, &cBinop_cZFB24z6_sendMessage);
}

void Heavy_EQVU::cBinop_cZFB24z6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lQ4MNKqQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_lQ4MNKqQ_sendMessage);
}

void Heavy_EQVU::cBinop_JdoRUuJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ivUA4HDV, HV_BINOP_ADD, 1, m, &cBinop_ivUA4HDV_sendMessage);
}

void Heavy_EQVU::cBinop_ivUA4HDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_xAC6UPdO_sendMessage);
}

void Heavy_EQVU::cBinop_MOof5Mei_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_YYDEAd75_sendMessage);
}

void Heavy_EQVU::cBinop_Oehz3O34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ivUA4HDV, HV_BINOP_ADD, 0, m, &cBinop_ivUA4HDV_sendMessage);
}

void Heavy_EQVU::cCast_UVHIDsU7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_MOof5Mei_sendMessage);
}

void Heavy_EQVU::cCast_VLhLGgYH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_JdoRUuJD_sendMessage);
}

void Heavy_EQVU::cBinop_xAC6UPdO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5sHsOlKh, HV_BINOP_MULTIPLY, 1, m, &cBinop_5sHsOlKh_sendMessage);
}

void Heavy_EQVU::cBinop_YYDEAd75_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oehz3O34, HV_BINOP_MULTIPLY, 1, m, &cBinop_Oehz3O34_sendMessage);
}

void Heavy_EQVU::cBinop_4ZyceGwJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hMBn7RL8_sendMessage);
}

void Heavy_EQVU::cBinop_obhYkSlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_THkebxqm, HV_BINOP_ADD, 0, m, &cBinop_THkebxqm_sendMessage);
}

void Heavy_EQVU::cBinop_THkebxqm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ytVkKniE, HV_BINOP_SUBTRACT, 0, m, &cBinop_ytVkKniE_sendMessage);
}

void Heavy_EQVU::cBinop_fHFmpqMr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_THkebxqm, HV_BINOP_ADD, 1, m, &cBinop_THkebxqm_sendMessage);
}

void Heavy_EQVU::cCast_ZVf39Srd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_4ZyceGwJ_sendMessage);
}

void Heavy_EQVU::cCast_TLH1Ptzs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_fHFmpqMr_sendMessage);
}

void Heavy_EQVU::cBinop_ytVkKniE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6qieZ5cQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_6qieZ5cQ_sendMessage);
}

void Heavy_EQVU::cBinop_hMBn7RL8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_obhYkSlr, HV_BINOP_MULTIPLY, 1, m, &cBinop_obhYkSlr_sendMessage);
}

void Heavy_EQVU::cBinop_hU0sEGhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_VBA5HJvW_sendMessage);
}

void Heavy_EQVU::cBinop_VBA5HJvW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_JMR6Dfps_sendMessage);
}

void Heavy_EQVU::cUnop_zWjiin8d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_VvnYuNuv_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3JLckPAI, HV_BINOP_MULTIPLY, 0, m, &cBinop_3JLckPAI_sendMessage);
}

void Heavy_EQVU::cUnop_Y0kGPRBL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KEMMxLrb_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hSfmvPuB, HV_BINOP_MULTIPLY, 0, m, &cBinop_hSfmvPuB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YZeKtUXr, HV_BINOP_MULTIPLY, 0, m, &cBinop_YZeKtUXr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_veDSBcoi, HV_BINOP_MULTIPLY, 0, m, &cBinop_veDSBcoi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTstG7vn, HV_BINOP_MULTIPLY, 0, m, &cBinop_tTstG7vn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bKdxlcP5, HV_BINOP_MULTIPLY, 0, m, &cBinop_bKdxlcP5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_VZNNY3am, HV_BINOP_MULTIPLY, 0, m, &cBinop_VZNNY3am_sendMessage);
}

void Heavy_EQVU::cBinop_eNdwsra1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 20.0f, 0, m, &cBinop_qaonieGt_sendMessage);
}

void Heavy_EQVU::cBinop_qaonieGt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Op0ojnV9, HV_BINOP_MULTIPLY, 0, m, &cBinop_Op0ojnV9_sendMessage);
}

void Heavy_EQVU::cVar_NxG0dFJy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JSFTC4bz_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_JOfuR9WJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -24.0f, 0, m, &cBinop_EIwqhqbN_sendMessage);
}

void Heavy_EQVU::cBinop_EIwqhqbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 40.0f, 0, m, &cBinop_XCmhiV4W_sendMessage);
}

void Heavy_EQVU::cVar_2WtLGqXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ftCltDDf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 20000.0f, 0, m, &cBinop_eNdwsra1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zfEyJKHG_sendMessage);
}

void Heavy_EQVU::cVar_H6pXUSEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 100.0f, 0, m, &cBinop_Ks1TOI2x_sendMessage);
}

void Heavy_EQVU::cVar_Mq0sbrTF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 24.0f, 0, m, &cBinop_JOfuR9WJ_sendMessage);
}

void Heavy_EQVU::cUnop_GGMEnsnp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_9Zx3FMiQ_sendMessage);
}

void Heavy_EQVU::cMsg_V1gl5n57_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_P8YMLKbc_sendMessage);
}

void Heavy_EQVU::cSystem_P8YMLKbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y8PmFptR, HV_BINOP_DIVIDE, 1, m, &cBinop_Y8PmFptR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JUOJYGVc_sendMessage);
}

void Heavy_EQVU::cUnop_O57sSWah_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8.0f, 0, m, &cBinop_ToNqg6xp_sendMessage);
}

void Heavy_EQVU::cBinop_E5klJt5Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WtLGqXN, 0, m, &cVar_2WtLGqXN_sendMessage);
}

void Heavy_EQVU::cBinop_6LDNo2EF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_1cHVKwKm_sendMessage);
}

void Heavy_EQVU::cBinop_1cHVKwKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_frBTuPU3, HV_BINOP_POW, 1, m, &cBinop_frBTuPU3_sendMessage);
  cMsg_CDuujeBc_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_frBTuPU3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_E5klJt5Y_sendMessage);
}

void Heavy_EQVU::cMsg_CDuujeBc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_frBTuPU3, HV_BINOP_POW, 0, m, &cBinop_frBTuPU3_sendMessage);
}

void Heavy_EQVU::cIf_ckyP8MQb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_j1dBSfVH_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 440.0f, 0, m, &cBinop_fRhNgGlx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_EQVU::cUnop_Wl6Macx5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 12.0f, 0, m, &cBinop_wjC54Sxk_sendMessage);
}

void Heavy_EQVU::cBinop_fRhNgGlx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_LOG2, m, &cUnop_Wl6Macx5_sendMessage);
}

void Heavy_EQVU::cBinop_wjC54Sxk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 69.0f, 0, m, &cBinop_KAkV7ZEk_sendMessage);
}

void Heavy_EQVU::cBinop_KAkV7ZEk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_6LDNo2EF_sendMessage);
}

void Heavy_EQVU::cCast_P1dOS3Gi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_ubfmPMhK_sendMessage);
}

void Heavy_EQVU::cCast_fRpYA4gz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ckyP8MQb, 0, m, &cIf_ckyP8MQb_sendMessage);
}

void Heavy_EQVU::cBinop_ubfmPMhK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ckyP8MQb, 1, m, &cIf_ckyP8MQb_sendMessage);
}

void Heavy_EQVU::cMsg_j1dBSfVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1500.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_6LDNo2EF_sendMessage);
}

void Heavy_EQVU::cBinop_hbEzQOq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_rI8myt2d_sendMessage);
}

void Heavy_EQVU::cBinop_rI8myt2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6z4ftd7T_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LKSqdqVz_sendMessage);
}

void Heavy_EQVU::cBinop_Ks1TOI2x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.1f, 0, m, &cBinop_2EfXcDci_sendMessage);
}

void Heavy_EQVU::cBinop_2EfXcDci_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_js19RYfP_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cMsg_QSYSX75n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Jzo9ZoBX, 0, m, NULL);
}

void Heavy_EQVU::cMsg_wjpRxGjM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_312HIS1r, 0, m, NULL);
}

void Heavy_EQVU::cMsg_3jnma2l9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_uwQtnLZr, 0, m, NULL);
}

void Heavy_EQVU::cMsg_ghgxpWcq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_dlYb6O0Y, 0, m, NULL);
}

void Heavy_EQVU::cMsg_tFkBPcXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_9Y0TLkNS, 0, m, NULL);
}

void Heavy_EQVU::cCast_ZM2yGnyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SIN, m, &cUnop_zWjiin8d_sendMessage);
}

void Heavy_EQVU::cCast_M23F8yeY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Y0kGPRBL_sendMessage);
}

void Heavy_EQVU::cSend_VvnYuNuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_4deXkcYD_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cSend_KEMMxLrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cSend_usdMIBmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_js19RYfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_yDhWbvBZ_sendMessage);
}

void Heavy_EQVU::cBinop_yDhWbvBZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3JLckPAI, HV_BINOP_MULTIPLY, 1, m, &cBinop_3JLckPAI_sendMessage);
}

void Heavy_EQVU::cBinop_3JLckPAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_FZYLQAuC_sendMessage);
}

void Heavy_EQVU::cBinop_FZYLQAuC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wId09nP7_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XBdQ13UR_sendMessage);
}

void Heavy_EQVU::cMsg_JSFTC4bz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_isj55d8g_sendMessage);
}

void Heavy_EQVU::cBinop_isj55d8g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xh7N0HgU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_MoUKh5oe_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7xrjzl9y_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ljXogb5M_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mS0qhExU_sendMessage);
}

void Heavy_EQVU::cBinop_7pek8NyC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QSYSX75n_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_2SSDTxHV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wjpRxGjM_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_uSnypcHv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3jnma2l9_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_KZXyFqGG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ghgxpWcq_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_l4sn48w8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tFkBPcXE_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_6z4ftd7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H6pXUSEH, 1, m, &cVar_H6pXUSEH_sendMessage);
}

void Heavy_EQVU::cCast_LKSqdqVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WtLGqXN, 0, m, &cVar_2WtLGqXN_sendMessage);
}

void Heavy_EQVU::cCast_ftCltDDf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_H6pXUSEH, 0, m, &cVar_H6pXUSEH_sendMessage);
}

void Heavy_EQVU::cCast_zfEyJKHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NxG0dFJy, 0, m, &cVar_NxG0dFJy_sendMessage);
}

void Heavy_EQVU::cSend_vRycTBi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cBinop_XCmhiV4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jqH0KwUy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_26a9KjVx_sendMessage);
}

void Heavy_EQVU::cCast_26a9KjVx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_L9Xk7hcZ_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_jqH0KwUy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RBaDdYnt, HV_BINOP_POW, 1, m, &cBinop_RBaDdYnt_sendMessage);
}

void Heavy_EQVU::cMsg_L9Xk7hcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 10.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RBaDdYnt, HV_BINOP_POW, 0, m, &cBinop_RBaDdYnt_sendMessage);
}

void Heavy_EQVU::cBinop_RBaDdYnt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KqZOIbx4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_pc7dLEbN_sendMessage);
}

void Heavy_EQVU::cCast_KAjFlDAa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mq0sbrTF, 0, m, &cVar_Mq0sbrTF_sendMessage);
}

void Heavy_EQVU::cCast_C3CbVvjO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WtLGqXN, 0, m, &cVar_2WtLGqXN_sendMessage);
}

void Heavy_EQVU::cCast_M0KgEhZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mq0sbrTF, 0, m, &cVar_Mq0sbrTF_sendMessage);
}

void Heavy_EQVU::cCast_jUYUkrzk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2WtLGqXN, 0, m, &cVar_2WtLGqXN_sendMessage);
}

void Heavy_EQVU::cBinop_9Zx3FMiQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WrHubdO6, HV_BINOP_MULTIPLY, 1, m, &cBinop_WrHubdO6_sendMessage);
}

void Heavy_EQVU::cBinop_WrHubdO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_lDBiGoLH_sendMessage(_c, 0, m);
  cBinop_onMessage(_c, &Context(_c)->cBinop_u6arm1bp, HV_BINOP_ADD, 1, m, &cBinop_u6arm1bp_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Aibpv7CU, HV_BINOP_ADD, 1, m, &cBinop_Aibpv7CU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_GyWGf9kf, HV_BINOP_SUBTRACT, 1, m, &cBinop_GyWGf9kf_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OXBfFWM0, HV_BINOP_SUBTRACT, 1, m, &cBinop_OXBfFWM0_sendMessage);
}

void Heavy_EQVU::cCast_XBdQ13UR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_WrHubdO6, HV_BINOP_MULTIPLY, 0, m, &cBinop_WrHubdO6_sendMessage);
}

void Heavy_EQVU::cCast_wId09nP7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_usdMIBmS_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cCast_MoUKh5oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KZXyFqGG, HV_BINOP_MULTIPLY, 0, m, &cBinop_KZXyFqGG_sendMessage);
}

void Heavy_EQVU::cCast_ljXogb5M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2SSDTxHV, HV_BINOP_MULTIPLY, 0, m, &cBinop_2SSDTxHV_sendMessage);
}

void Heavy_EQVU::cCast_Xh7N0HgU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l4sn48w8, HV_BINOP_MULTIPLY, 0, m, &cBinop_l4sn48w8_sendMessage);
}

void Heavy_EQVU::cCast_7xrjzl9y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uSnypcHv, HV_BINOP_MULTIPLY, 0, m, &cBinop_uSnypcHv_sendMessage);
}

void Heavy_EQVU::cCast_mS0qhExU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7pek8NyC, HV_BINOP_MULTIPLY, 0, m, &cBinop_7pek8NyC_sendMessage);
}

void Heavy_EQVU::cCast_pc7dLEbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_SQRT, m, &cUnop_GGMEnsnp_sendMessage);
}

void Heavy_EQVU::cCast_KqZOIbx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_vRycTBi7_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LjMpfoeJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DzfBVskK_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0r530mA3_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_77h4LBwv_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zGRcWBCz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mc11MbBx_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dykieSZd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_FDIbzK1N_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZTHQGIoy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_au4OFrIJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iMf04RhI_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KytJygG9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hLsVImqY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uK0CKcde_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_KshQHpef_sendMessage);
}

void Heavy_EQVU::cSend_lDBiGoLH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_EQVU::cMsg_I7mYnCkd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cUnop_onMessage(_c, HV_UNOP_ATAN, m, &cUnop_O57sSWah_sendMessage);
}

void Heavy_EQVU::cBinop_ToNqg6xp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y8PmFptR, HV_BINOP_DIVIDE, 0, m, &cBinop_Y8PmFptR_sendMessage);
}

void Heavy_EQVU::cCast_JUOJYGVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_I7mYnCkd_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cBinop_Y8PmFptR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Op0ojnV9, HV_BINOP_MULTIPLY, 1, m, &cBinop_Op0ojnV9_sendMessage);
}

void Heavy_EQVU::cBinop_Op0ojnV9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZM2yGnyi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_M23F8yeY_sendMessage);
}

void Heavy_EQVU::cBinop_XdDbgA5T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_zz4shEM7_sendMessage);
}

void Heavy_EQVU::cBinop_hSfmvPuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H5Qv41uo, HV_BINOP_ADD, 0, m, &cBinop_H5Qv41uo_sendMessage);
}

void Heavy_EQVU::cBinop_H5Qv41uo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u6arm1bp, HV_BINOP_ADD, 0, m, &cBinop_u6arm1bp_sendMessage);
}

void Heavy_EQVU::cBinop_hz0mb837_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H5Qv41uo, HV_BINOP_ADD, 1, m, &cBinop_H5Qv41uo_sendMessage);
}

void Heavy_EQVU::cCast_DzfBVskK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XdDbgA5T_sendMessage);
}

void Heavy_EQVU::cCast_LjMpfoeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_hz0mb837_sendMessage);
}

void Heavy_EQVU::cBinop_u6arm1bp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NxG0dFJy, 1, m, &cVar_NxG0dFJy_sendMessage);
}

void Heavy_EQVU::cBinop_zz4shEM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hSfmvPuB, HV_BINOP_MULTIPLY, 1, m, &cBinop_hSfmvPuB_sendMessage);
}

void Heavy_EQVU::cBinop_FULFsMoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YZeKtUXr, HV_BINOP_MULTIPLY, 1, m, &cBinop_YZeKtUXr_sendMessage);
}

void Heavy_EQVU::cBinop_YZeKtUXr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X1YsNFwQ, HV_BINOP_ADD, 0, m, &cBinop_X1YsNFwQ_sendMessage);
}

void Heavy_EQVU::cBinop_p4UYwbuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_X1YsNFwQ, HV_BINOP_ADD, 1, m, &cBinop_X1YsNFwQ_sendMessage);
}

void Heavy_EQVU::cCast_0r530mA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ky3XolkD, HV_BINOP_MULTIPLY, 1, m, &cBinop_Ky3XolkD_sendMessage);
}

void Heavy_EQVU::cCast_zGRcWBCz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_FULFsMoX_sendMessage);
}

void Heavy_EQVU::cCast_77h4LBwv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_p4UYwbuh_sendMessage);
}

void Heavy_EQVU::cBinop_Ky3XolkD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7pek8NyC, HV_BINOP_MULTIPLY, 1, m, &cBinop_7pek8NyC_sendMessage);
}

void Heavy_EQVU::cBinop_X1YsNFwQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Aibpv7CU, HV_BINOP_ADD, 0, m, &cBinop_Aibpv7CU_sendMessage);
}

void Heavy_EQVU::cBinop_Aibpv7CU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Ky3XolkD, HV_BINOP_MULTIPLY, 0, m, &cBinop_Ky3XolkD_sendMessage);
}

void Heavy_EQVU::cBinop_6AuI2oIq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3s7rWiOr, HV_BINOP_ADD, 1, m, &cBinop_3s7rWiOr_sendMessage);
}

void Heavy_EQVU::cBinop_UAGWFlEv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_veDSBcoi, HV_BINOP_MULTIPLY, 1, m, &cBinop_veDSBcoi_sendMessage);
}

void Heavy_EQVU::cBinop_veDSBcoi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3s7rWiOr, HV_BINOP_ADD, 0, m, &cBinop_3s7rWiOr_sendMessage);
}

void Heavy_EQVU::cCast_FDIbzK1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UAGWFlEv_sendMessage);
}

void Heavy_EQVU::cCast_dykieSZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_6AuI2oIq_sendMessage);
}

void Heavy_EQVU::cCast_mc11MbBx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -2.0f, 0, m, &cBinop_udo2nF7Y_sendMessage);
}

void Heavy_EQVU::cBinop_EFygSdUD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2SSDTxHV, HV_BINOP_MULTIPLY, 1, m, &cBinop_2SSDTxHV_sendMessage);
}

void Heavy_EQVU::cBinop_3s7rWiOr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFygSdUD, HV_BINOP_MULTIPLY, 0, m, &cBinop_EFygSdUD_sendMessage);
}

void Heavy_EQVU::cBinop_udo2nF7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EFygSdUD, HV_BINOP_MULTIPLY, 1, m, &cBinop_EFygSdUD_sendMessage);
}

void Heavy_EQVU::cBinop_dHPppmIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTstG7vn, HV_BINOP_MULTIPLY, 1, m, &cBinop_tTstG7vn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tTstG7vn, HV_BINOP_MULTIPLY, 0, m, &cBinop_tTstG7vn_sendMessage);
}

void Heavy_EQVU::cBinop_tTstG7vn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7kCrOOZd, HV_BINOP_ADD, 0, m, &cBinop_7kCrOOZd_sendMessage);
}

void Heavy_EQVU::cBinop_7kCrOOZd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GyWGf9kf, HV_BINOP_SUBTRACT, 0, m, &cBinop_GyWGf9kf_sendMessage);
}

void Heavy_EQVU::cBinop_xM94VEmV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7kCrOOZd, HV_BINOP_ADD, 1, m, &cBinop_7kCrOOZd_sendMessage);
}

void Heavy_EQVU::cBinop_GyWGf9kf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6npjMPp, HV_BINOP_MULTIPLY, 0, m, &cBinop_n6npjMPp_sendMessage);
}

void Heavy_EQVU::cCast_iMf04RhI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dHPppmIr_sendMessage);
}

void Heavy_EQVU::cCast_ZTHQGIoy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n6npjMPp, HV_BINOP_MULTIPLY, 1, m, &cBinop_n6npjMPp_sendMessage);
}

void Heavy_EQVU::cCast_au4OFrIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_xM94VEmV_sendMessage);
}

void Heavy_EQVU::cBinop_n6npjMPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uSnypcHv, HV_BINOP_MULTIPLY, 1, m, &cBinop_uSnypcHv_sendMessage);
}

void Heavy_EQVU::cBinop_CQ5sxMZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BEp2RdKC, HV_BINOP_ADD, 1, m, &cBinop_BEp2RdKC_sendMessage);
}

void Heavy_EQVU::cBinop_BEp2RdKC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_JPuAuZmJ_sendMessage);
}

void Heavy_EQVU::cBinop_rD17QVkU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_n0UUL3Rp_sendMessage);
}

void Heavy_EQVU::cBinop_bKdxlcP5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BEp2RdKC, HV_BINOP_ADD, 0, m, &cBinop_BEp2RdKC_sendMessage);
}

void Heavy_EQVU::cCast_KytJygG9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CQ5sxMZZ_sendMessage);
}

void Heavy_EQVU::cCast_hLsVImqY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_rD17QVkU_sendMessage);
}

void Heavy_EQVU::cBinop_JPuAuZmJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KZXyFqGG, HV_BINOP_MULTIPLY, 1, m, &cBinop_KZXyFqGG_sendMessage);
}

void Heavy_EQVU::cBinop_n0UUL3Rp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bKdxlcP5, HV_BINOP_MULTIPLY, 1, m, &cBinop_bKdxlcP5_sendMessage);
}

void Heavy_EQVU::cBinop_tOFufYpn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_BPSaEP8U_sendMessage);
}

void Heavy_EQVU::cBinop_VZNNY3am_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_knTyJoBI, HV_BINOP_ADD, 0, m, &cBinop_knTyJoBI_sendMessage);
}

void Heavy_EQVU::cBinop_knTyJoBI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OXBfFWM0, HV_BINOP_SUBTRACT, 0, m, &cBinop_OXBfFWM0_sendMessage);
}

void Heavy_EQVU::cBinop_TKLvsGTG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_knTyJoBI, HV_BINOP_ADD, 1, m, &cBinop_knTyJoBI_sendMessage);
}

void Heavy_EQVU::cCast_KshQHpef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_tOFufYpn_sendMessage);
}

void Heavy_EQVU::cCast_uK0CKcde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_TKLvsGTG_sendMessage);
}

void Heavy_EQVU::cBinop_OXBfFWM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_l4sn48w8, HV_BINOP_MULTIPLY, 1, m, &cBinop_l4sn48w8_sendMessage);
}

void Heavy_EQVU::cBinop_BPSaEP8U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VZNNY3am, HV_BINOP_MULTIPLY, 1, m, &cBinop_VZNNY3am_sendMessage);
}

void Heavy_EQVU::cBinop_hAQiTNEg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 0.2f, 0, m, &cBinop_bynjhfNv_sendMessage);
}

void Heavy_EQVU::cBinop_bynjhfNv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 3.0f, 0, m, &cBinop_hbEzQOq0_sendMessage);
}

void Heavy_EQVU::cExpr_98v21Rs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Y3eudSD9, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_0qkkezjA, m);
}

float Heavy_EQVU::cExpr_98v21Rs3_evaluate(const float* args) {
  	return ((float)(args[0])) / 10;
}

void Heavy_EQVU::cExpr_rxXtxhsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_uT7nzCwS, m);
  sVarf_onMessage(_c, &Context(_c)->sVarf_hmLz1YKm, m);
}

float Heavy_EQVU::cExpr_rxXtxhsK_evaluate(const float* args) {
  	return ((float)(args[0])) / 10;
}

void Heavy_EQVU::cVar_BiXRtzvn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ZOwEFvRM_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ELXbVrXX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5gOWHd06_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mtXpsTNH_sendMessage);
}

void Heavy_EQVU::cVar_wyyRsJ0s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nimJgXfX_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2112cEWb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qLdzd0Hd_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fxH0p5Io_sendMessage);
}

void Heavy_EQVU::cReceive_4deXkcYD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wF0cNdNd, HV_BINOP_MULTIPLY, 0, m, &cBinop_wF0cNdNd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6hSTVR1C, HV_BINOP_MULTIPLY, 0, m, &cBinop_6hSTVR1C_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0hcAj6ej, HV_BINOP_MULTIPLY, 0, m, &cBinop_0hcAj6ej_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QSxPZBnF, HV_BINOP_MULTIPLY, 0, m, &cBinop_QSxPZBnF_sendMessage);
}

void Heavy_EQVU::cReceive_6yyh0n9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UqTk4k0x_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QStn3lzX_sendMessage);
  cMsg_Ugrl9lXk_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UQTjTR8P_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eH6sDJ9C_sendMessage);
  cMsg_qwQolJZc_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yuADsjqK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5uLyfTFU_sendMessage);
  cMsg_spCKR7Zf_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l7ay5DTG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7DRvWloW_sendMessage);
  cMsg_a5u23spx_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L7hAZbx0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FV5745Qh_sendMessage);
  cMsg_IF4r9iGM_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XFI4JJUX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RG2Bq9iF_sendMessage);
  cMsg_gey0zGWH_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uTciOA7K_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OD0EhNDM_sendMessage);
  cMsg_WFLmZRRK_sendMessage(_c, 0, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M0KgEhZj_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jUYUkrzk_sendMessage);
  cMsg_V1gl5n57_sendMessage(_c, 0, m);
}

void Heavy_EQVU::cReceive_w9NHXTKI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lQiHyA23, 0, m, &cVar_lQiHyA23_sendMessage);
}

void Heavy_EQVU::cReceive_M5wJrTIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wlNqMSS0, 0, m, &cVar_wlNqMSS0_sendMessage);
}

void Heavy_EQVU::cReceive_pkwarQFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b9GoW53K, 0, m, &cVar_b9GoW53K_sendMessage);
}

void Heavy_EQVU::cReceive_YP2lyKct_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_vnz76X2m, 0, m, &cVar_vnz76X2m_sendMessage);
}

void Heavy_EQVU::cReceive_Tm5VYnRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KksTsWGQ, 0, m, &cVar_KksTsWGQ_sendMessage);
}

void Heavy_EQVU::cReceive_qZb1J4hd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hLJkrFBj, 0, m, &cVar_hLJkrFBj_sendMessage);
}

void Heavy_EQVU::cReceive_F3DTW6YK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3PKKi0fn, 0, m, &cVar_3PKKi0fn_sendMessage);
}

void Heavy_EQVU::cReceive_e8MQOPeJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xzQRx44A, 0, m, &cVar_xzQRx44A_sendMessage);
}

void Heavy_EQVU::cReceive_NgqcEoA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_SbTpAWOI, 0, m, &cVar_SbTpAWOI_sendMessage);
}

void Heavy_EQVU::cReceive_Ou68a73T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mhNfs6Ok, 0, m, &cVar_mhNfs6Ok_sendMessage);
}

void Heavy_EQVU::cReceive_zbH72BFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1i2jjkhP, 0, m, &cVar_1i2jjkhP_sendMessage);
}

void Heavy_EQVU::cReceive_AohqoJ6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_775QCHe0, 0, m, &cVar_775QCHe0_sendMessage);
}

void Heavy_EQVU::cReceive_dvULlMn8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3rYVtvhw, 0, m, &cVar_3rYVtvhw_sendMessage);
}

void Heavy_EQVU::cReceive_Cyj5dK4W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FAqrC730, 0, m, &cVar_FAqrC730_sendMessage);
}

void Heavy_EQVU::cReceive_bIEZRauY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Tu0Iupx2, 0, m, &cVar_Tu0Iupx2_sendMessage);
}

void Heavy_EQVU::cReceive_xNoCCLj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RITjtKXj, 0, m, &cVar_RITjtKXj_sendMessage);
}

void Heavy_EQVU::cReceive_h4clFQA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BiXRtzvn, 0, m, &cVar_BiXRtzvn_sendMessage);
}

void Heavy_EQVU::cReceive_x3rcJta4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wyyRsJ0s, 0, m, &cVar_wyyRsJ0s_sendMessage);
}



/*
 * Code for expr~ implementation
 * Write out the generic implementation code
 */

 // per class code

 // per object code


/*
 * Context Process Implementation
 */

int Heavy_EQVU::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8;

  // input and output vars
  hv_bufferf_t O0, O1;
  hv_bufferf_t I0, I1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    // load input buffers
    __hv_load_f(inputBuffers[0]+n, VOf(I0));
    __hv_load_f(inputBuffers[1]+n, VOf(I1));

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_i1L9GUcR, VOf(Bf0));
    __hv_mul_f(VIf(I0), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LpSaxQvy, VOf(Bf1));
    __hv_mul_f(VIf(I1), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_07i2LSrB, VOf(Bf2));
    __hv_line_f(&sLine_B9aSsYUg, VOf(Bf3));
    __hv_line_f(&sLine_TBFHImbf, VOf(Bf4));
    __hv_line_f(&sLine_RmoWLgur, VOf(Bf5));
    __hv_line_f(&sLine_i2DcOZR4, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_0sK5s8YV, VIf(Bf0), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_pWftslqy, VOf(Bf5));
    __hv_line_f(&sLine_XV0zhI7q, VOf(Bf4));
    __hv_line_f(&sLine_2E0um0D6, VOf(Bf3));
    __hv_line_f(&sLine_Gjkvrkzc, VOf(Bf2));
    __hv_line_f(&sLine_ChLD7RUV, VOf(Bf7));
    __hv_biquad_f(&sBiquad_s_lUrlw0s4, VIf(Bf1), VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_Q0OuA4w6, VOf(Bf2));
    __hv_line_f(&sLine_9wCbqQsf, VOf(Bf3));
    __hv_line_f(&sLine_ajwFzW5o, VOf(Bf4));
    __hv_line_f(&sLine_Js6prR57, VOf(Bf5));
    __hv_line_f(&sLine_WLr4bZdA, VOf(Bf8));
    __hv_biquad_f(&sBiquad_s_t4TIwFUX, VIf(Bf6), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_Tsd4yQYt, VOf(Bf5));
    __hv_line_f(&sLine_VNH5c4Lc, VOf(Bf4));
    __hv_line_f(&sLine_Hu6BovKt, VOf(Bf3));
    __hv_line_f(&sLine_ULEoEQYL, VOf(Bf2));
    __hv_line_f(&sLine_8HprGu87, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_VZKUzHJi, VIf(Bf7), VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_SmX8RxTU, VOf(Bf2));
    __hv_line_f(&sLine_QF0fweuu, VOf(Bf3));
    __hv_line_f(&sLine_VYMCtIzC, VOf(Bf4));
    __hv_line_f(&sLine_NzEar4Sy, VOf(Bf5));
    __hv_line_f(&sLine_bsCYE9U2, VOf(Bf7));
    __hv_biquad_f(&sBiquad_s_jdi2ACUP, VIf(Bf8), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_dqvRdwkB, VOf(Bf5));
    __hv_line_f(&sLine_9jjU45KP, VOf(Bf4));
    __hv_line_f(&sLine_XO4nZ9nT, VOf(Bf3));
    __hv_line_f(&sLine_JzpBomMY, VOf(Bf2));
    __hv_line_f(&sLine_MfLY8jSv, VOf(Bf8));
    __hv_biquad_f(&sBiquad_s_xhf849N3, VIf(Bf6), VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf2), VIf(Bf8), VOf(Bf8));
    __hv_line_f(&sLine_Jzo9ZoBX, VOf(Bf2));
    __hv_line_f(&sLine_312HIS1r, VOf(Bf3));
    __hv_line_f(&sLine_uwQtnLZr, VOf(Bf4));
    __hv_line_f(&sLine_dlYb6O0Y, VOf(Bf5));
    __hv_line_f(&sLine_9Y0TLkNS, VOf(Bf6));
    __hv_biquad_f(&sBiquad_s_XDpsTOw4, VIf(Bf7), VIf(Bf2), VIf(Bf3), VIf(Bf4), VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_5RuuDxwH, VOf(Bf5));
    __hv_line_f(&sLine_qcQlh37Y, VOf(Bf4));
    __hv_line_f(&sLine_9bKSPuhR, VOf(Bf3));
    __hv_line_f(&sLine_o8GQ3X0N, VOf(Bf2));
    __hv_line_f(&sLine_gIFdyY3a, VOf(Bf7));
    __hv_biquad_f(&sBiquad_s_OZ1pbjAn, VIf(Bf8), VIf(Bf5), VIf(Bf4), VIf(Bf3), VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_0qkkezjA, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_Y3eudSD9, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_hmLz1YKm, VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_uT7nzCwS, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_lKEbVOPI, VOf(Bf6));
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_JYf7ganH, VOf(Bf2));
    __hv_mul_f(VIf(Bf7), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf6), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_EQVU::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s)
  float **const bIn = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bIn[0] = inputBuffers+(0*n4);
  bIn[1] = inputBuffers+(1*n4);

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_EQVU::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 2 channel(s), uninterleave
  float *const bIn = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));
  #if HV_SIMD_SSE || HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 a = _mm_load_ps(inputBuffers+i);                // LRLR
    __m128 b = _mm_load_ps(inputBuffers+4+i);              // LRLR
    __m128 x = _mm_shuffle_ps(a, b, _MM_SHUFFLE(2,0,2,0)); // LLLL
    __m128 y = _mm_shuffle_ps(a, b, _MM_SHUFFLE(3,1,3,1)); // RRRR
    _mm_store_ps(bIn+j, x);
    _mm_store_ps(bIn+n4+j, y);
  }
  #elif HV_SIMD_NEON
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4x2_t a = vld2q_f32(inputBuffers+i); // load and uninterleave
    vst1q_f32(bIn+j, a.val[0]);
    vst1q_f32(bIn+n4+j, a.val[1]);
  }
  #else // HV_SIMD_NONE
  for (int j = 0; j < n4; ++j) {
    bIn[0*n4+j] = inputBuffers[0+2*j];
    bIn[1*n4+j] = inputBuffers[1+2*j];
  }
  #endif

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
