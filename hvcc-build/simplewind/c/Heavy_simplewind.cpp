/**
 * Copyright (c) 2023 Enzien Audio, Ltd.
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

#include "Heavy_simplewind.hpp"

#define Context(_c) reinterpret_cast<Heavy_simplewind *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_simplewind_new(double sampleRate) {
    return new Heavy_simplewind(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_simplewind_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_simplewind(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_simplewind::Heavy_simplewind(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sBiquad_k_init(&sBiquad_k_3mb6sMn4, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_fC0JfbU8, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_FdaUkxV7, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_r90Kg5Ng, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_HmP6VGy4, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sBiquad_k_init(&sBiquad_k_0md13wFu, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_HI6yFwth, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_MpukXy1s, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_QYiXp3oS, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_AdtTEv0k, 1.0f);
  numBytes += cBinop_init(&cBinop_uKCrqlef, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_j77bfEW0, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_YhJ2mUVn, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ImYE6J60, 22050.0f);
  numBytes += cBinop_init(&cBinop_pFwJNtMv, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_B0Dy87Gm, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_H92SaStD, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_4794lSFM, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_POSC8jM0, 1.0f);
  numBytes += cVar_init_f(&cVar_qXYlqaez, 22050.0f);
  numBytes += cBinop_init(&cBinop_Gow4UYW1, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_hv5LRCYI, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_aToNe714, 0.0f);
  numBytes += cBinop_init(&cBinop_s5yIf5HM, 0.0f); // __add
  numBytes += cVar_init_f(&cVar_f8nIr4pW, 1.0f);
  numBytes += cBinop_init(&cBinop_NV9LJKGy, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_qvVxm5vQ, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_IbzT0oFu, 22050.0f);
  numBytes += cBinop_init(&cBinop_8z52sEky, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_PWwMBngN, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_iNgmXkqM, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_L9tM22yT, 0.0f);
  numBytes += cBinop_init(&cBinop_mEnoP1O2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_5LTqmyos, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yrssERi7, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_34VIoGLt, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_PzkaMneA, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_metDTtmk, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_dQWKELLt, 22050.0f);
  numBytes += cVar_init_f(&cVar_uxvvBNvo, 1.0f);
  numBytes += cVar_init_f(&cVar_qT9ks1lO, 0.0f);
  numBytes += cVar_init_f(&cVar_MEezljh0, 0.0f);
  numBytes += cRandom_init(&cRandom_CNA9oJ3N, -1090710771);
  numBytes += cSlice_init(&cSlice_8LoD6OmI, 1, 1);
  numBytes += sVari_init(&sVari_28loyaXI, 0, 0, false);
  numBytes += cBinop_init(&cBinop_3qasQFy6, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_n2oxIAPU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_K4asmVyX, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Elrr7ZOz, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_qVywKOEw, 22050.0f);
  numBytes += cBinop_init(&cBinop_SxiBgaDr, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_UdUp9HPv, 0.0f); // __div
  numBytes += cVar_init_f(&cVar_cTVTNs60, 1.0f);
  numBytes += cSlice_init(&cSlice_rhYRKs4x, 1, 1);
  numBytes += cRandom_init(&cRandom_OwlRwcK0, 1262334789);
  numBytes += sVari_init(&sVari_ZqchcoIu, 0, 0, false);
  numBytes += cVar_init_f(&cVar_1qd6BzXE, 0.0f);
  numBytes += cVar_init_f(&cVar_Qxg9UTAq, 0.0f);
  numBytes += cVar_init_f(&cVar_0Fg95qLM, 0.0f);
  numBytes += cRandom_init(&cRandom_D33e11Hz, 577767536);
  numBytes += cSlice_init(&cSlice_Wrdh59Du, 1, 1);
  numBytes += sVari_init(&sVari_k0wfz3d5, 0, 0, false);
  numBytes += cVar_init_f(&cVar_A5SK7wOq, 0.0f);
  numBytes += cVar_init_f(&cVar_9ImgedE5, 22050.0f);
  numBytes += cBinop_init(&cBinop_NGkPXvOE, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Qvw22M3R, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_P3Mu29wX, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_IfZd6Db0, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_CE1No0YR, 1.0f);
  numBytes += cBinop_init(&cBinop_kerqTkJq, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Jv7Pjklr, 0.0f); // __add
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_simplewind::~Heavy_simplewind() {
  // nothing to free
}

HvTable *Heavy_simplewind::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_simplewind::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xF3BA5CD4: { // Q
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FMDP7mkC_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_ap77CUvR_sendMessage);
      break;
    }
    case 0x539436C5: { // centerFrequency_01
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_y9BylY82_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_simplewind::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "Q";
        info->hash = 0xF3BA5CD4;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.1f;
        info->maxVal = 2.0f;
        info->defaultVal = 1.2f;
        break;
      }
      case 1: {
        info->name = "centerFrequency_01";
        info->hash = 0x539436C5;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 20.0f;
        info->maxVal = 20000.0f;
        info->defaultVal = 130.0f;
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
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_simplewind::cBinop_LNariU1G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_KjW7NUFS_sendMessage);
}

void Heavy_simplewind::cBinop_HI6yFwth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uKCrqlef, HV_BINOP_MULTIPLY, 1, m, &cBinop_uKCrqlef_sendMessage);
}

void Heavy_simplewind::cBinop_JXqHpLBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_uKCrqlef, HV_BINOP_MULTIPLY, 0, m, &cBinop_uKCrqlef_sendMessage);
}

void Heavy_simplewind::cMsg_YUUzT1Nq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Ut2KROdh_sendMessage);
}

void Heavy_simplewind::cSystem_Ut2KROdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j77bfEW0, HV_BINOP_DIVIDE, 1, m, &cBinop_j77bfEW0_sendMessage);
}

void Heavy_simplewind::cBinop_MpukXy1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_HlIpYDxl_sendMessage);
}

void Heavy_simplewind::cCast_RXCwGwjY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ImYE6J60, 0, m, &cVar_ImYE6J60_sendMessage);
}

void Heavy_simplewind::cBinop_xD0WXOdt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fC0JfbU8, 4, m);
}

void Heavy_simplewind::cBinop_QYiXp3oS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HI6yFwth, HV_BINOP_ADD, 1, m, &cBinop_HI6yFwth_sendMessage);
}

void Heavy_simplewind::cBinop_2ELCgWs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_9RBd7wYr_sendMessage);
}

void Heavy_simplewind::cBinop_9RBd7wYr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fC0JfbU8, 5, m);
}

void Heavy_simplewind::cBinop_5mgrQimj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YhJ2mUVn, HV_BINOP_MULTIPLY, 1, m, &cBinop_YhJ2mUVn_sendMessage);
}

void Heavy_simplewind::cVar_AdtTEv0k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_asjdDVST_sendMessage);
}

void Heavy_simplewind::cBinop_uKCrqlef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_fC0JfbU8, 1, m);
}

void Heavy_simplewind::cBinop_j77bfEW0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QYiXp3oS, HV_BINOP_MULTIPLY, 1, m, &cBinop_QYiXp3oS_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_5NgUs3TE_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MpukXy1s, HV_BINOP_DIVIDE, 0, m, &cBinop_MpukXy1s_sendMessage);
}

void Heavy_simplewind::cBinop_qARU9djJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_2ELCgWs7_sendMessage);
}

void Heavy_simplewind::cBinop_YhJ2mUVn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_xD0WXOdt_sendMessage);
}

void Heavy_simplewind::cVar_ImYE6J60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_cyfHx8lk_sendMessage);
}

void Heavy_simplewind::cUnop_5NgUs3TE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_5mgrQimj_sendMessage);
}

void Heavy_simplewind::cBinop_KjW7NUFS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_qARU9djJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YhJ2mUVn, HV_BINOP_MULTIPLY, 0, m, &cBinop_YhJ2mUVn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QYiXp3oS, HV_BINOP_MULTIPLY, 0, m, &cBinop_QYiXp3oS_sendMessage);
}

void Heavy_simplewind::cBinop_asjdDVST_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MpukXy1s, HV_BINOP_DIVIDE, 1, m, &cBinop_MpukXy1s_sendMessage);
}

void Heavy_simplewind::cBinop_HlIpYDxl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LNariU1G_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HI6yFwth, HV_BINOP_ADD, 0, m, &cBinop_HI6yFwth_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_JXqHpLBG_sendMessage);
}

void Heavy_simplewind::cBinop_cyfHx8lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_j77bfEW0, HV_BINOP_DIVIDE, 0, m, &cBinop_j77bfEW0_sendMessage);
}

void Heavy_simplewind::cBinop_7mEaJmV3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H92SaStD, HV_BINOP_MULTIPLY, 0, m, &cBinop_H92SaStD_sendMessage);
}

void Heavy_simplewind::cBinop_vWWR6X0n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_56lHuWtG_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_B0Dy87Gm, HV_BINOP_MULTIPLY, 0, m, &cBinop_B0Dy87Gm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_4794lSFM, HV_BINOP_MULTIPLY, 0, m, &cBinop_4794lSFM_sendMessage);
}

void Heavy_simplewind::cBinop_56lHuWtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_GUl7WROr_sendMessage);
}

void Heavy_simplewind::cBinop_pFwJNtMv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_ilqDtc7I_sendMessage);
}

void Heavy_simplewind::cBinop_ilqDtc7I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_w4dgY1iW_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gow4UYW1, HV_BINOP_ADD, 0, m, &cBinop_Gow4UYW1_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_7mEaJmV3_sendMessage);
}

void Heavy_simplewind::cUnop_rvFHrFrb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_VPrHRjEA_sendMessage);
}

void Heavy_simplewind::cBinop_w4dgY1iW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_vWWR6X0n_sendMessage);
}

void Heavy_simplewind::cCast_jSkr6Fxg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qXYlqaez, 0, m, &cVar_qXYlqaez_sendMessage);
}

void Heavy_simplewind::cBinop_hrvoaqTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_HmP6VGy4, 4, m);
}

void Heavy_simplewind::cBinop_VKvxcsVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_HmP6VGy4, 5, m);
}

void Heavy_simplewind::cBinop_B0Dy87Gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_hrvoaqTs_sendMessage);
}

void Heavy_simplewind::cBinop_H92SaStD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_HmP6VGy4, 1, m);
}

void Heavy_simplewind::cBinop_4794lSFM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gow4UYW1, HV_BINOP_ADD, 1, m, &cBinop_Gow4UYW1_sendMessage);
}

void Heavy_simplewind::cMsg_5wUlXbLe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_E7n2i3mx_sendMessage);
}

void Heavy_simplewind::cSystem_E7n2i3mx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hv5LRCYI, HV_BINOP_DIVIDE, 1, m, &cBinop_hv5LRCYI_sendMessage);
}

void Heavy_simplewind::cVar_POSC8jM0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_ZipaQtMp_sendMessage);
}

void Heavy_simplewind::cBinop_GUl7WROr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_VKvxcsVu_sendMessage);
}

void Heavy_simplewind::cVar_qXYlqaez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_SLJlhNQU_sendMessage);
}

void Heavy_simplewind::cBinop_ZipaQtMp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFwJNtMv, HV_BINOP_DIVIDE, 1, m, &cBinop_pFwJNtMv_sendMessage);
}

void Heavy_simplewind::cBinop_Gow4UYW1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_H92SaStD, HV_BINOP_MULTIPLY, 1, m, &cBinop_H92SaStD_sendMessage);
}

void Heavy_simplewind::cBinop_hv5LRCYI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4794lSFM, HV_BINOP_MULTIPLY, 1, m, &cBinop_4794lSFM_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_rvFHrFrb_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pFwJNtMv, HV_BINOP_DIVIDE, 0, m, &cBinop_pFwJNtMv_sendMessage);
}

void Heavy_simplewind::cBinop_SLJlhNQU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hv5LRCYI, HV_BINOP_DIVIDE, 0, m, &cBinop_hv5LRCYI_sendMessage);
}

void Heavy_simplewind::cBinop_VPrHRjEA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_B0Dy87Gm, HV_BINOP_MULTIPLY, 1, m, &cBinop_B0Dy87Gm_sendMessage);
}

void Heavy_simplewind::cVar_aToNe714_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A5SK7wOq, 0, m, &cVar_A5SK7wOq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MEezljh0, 0, m, &cVar_MEezljh0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qT9ks1lO, 0, m, &cVar_qT9ks1lO_sendMessage);
}

void Heavy_simplewind::cBinop_aDpZAXeA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_0md13wFu, 5, m);
}

void Heavy_simplewind::cBinop_s5yIf5HM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PWwMBngN, HV_BINOP_MULTIPLY, 1, m, &cBinop_PWwMBngN_sendMessage);
}

void Heavy_simplewind::cBinop_X14ugGAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_qvVxm5vQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_qvVxm5vQ_sendMessage);
}

void Heavy_simplewind::cBinop_wjlNfbPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iNgmXkqM, HV_BINOP_DIVIDE, 0, m, &cBinop_iNgmXkqM_sendMessage);
}

void Heavy_simplewind::cBinop_qCo9Cosy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_6Dp77w1V_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_qvVxm5vQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_qvVxm5vQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NV9LJKGy, HV_BINOP_MULTIPLY, 0, m, &cBinop_NV9LJKGy_sendMessage);
}

void Heavy_simplewind::cBinop_HvX7eRXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_qCo9Cosy_sendMessage);
}

void Heavy_simplewind::cBinop_B6Ow3bNZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_HvX7eRXo_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_s5yIf5HM, HV_BINOP_ADD, 0, m, &cBinop_s5yIf5HM_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Dsbb3CKr_sendMessage);
}

void Heavy_simplewind::cVar_f8nIr4pW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_qXYJP8wz_sendMessage);
}

void Heavy_simplewind::cBinop_qXYJP8wz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8z52sEky, HV_BINOP_DIVIDE, 1, m, &cBinop_8z52sEky_sendMessage);
}

void Heavy_simplewind::cBinop_NV9LJKGy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s5yIf5HM, HV_BINOP_ADD, 1, m, &cBinop_s5yIf5HM_sendMessage);
}

void Heavy_simplewind::cBinop_3qulVK9O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_0md13wFu, 4, m);
}

void Heavy_simplewind::cBinop_qvVxm5vQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_3qulVK9O_sendMessage);
}

void Heavy_simplewind::cBinop_JIG2sfaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_aDpZAXeA_sendMessage);
}

void Heavy_simplewind::cBinop_6Dp77w1V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_JIG2sfaR_sendMessage);
}

void Heavy_simplewind::cVar_IbzT0oFu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_wjlNfbPF_sendMessage);
}

void Heavy_simplewind::cBinop_8z52sEky_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_B6Ow3bNZ_sendMessage);
}

void Heavy_simplewind::cUnop_muvZbSkm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_X14ugGAI_sendMessage);
}

void Heavy_simplewind::cMsg_KatO2R4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rnVTF3g0_sendMessage);
}

void Heavy_simplewind::cSystem_rnVTF3g0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iNgmXkqM, HV_BINOP_DIVIDE, 1, m, &cBinop_iNgmXkqM_sendMessage);
}

void Heavy_simplewind::cBinop_PWwMBngN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_0md13wFu, 1, m);
}

void Heavy_simplewind::cCast_PV3xI4NC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IbzT0oFu, 0, m, &cVar_IbzT0oFu_sendMessage);
}

void Heavy_simplewind::cBinop_Dsbb3CKr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PWwMBngN, HV_BINOP_MULTIPLY, 0, m, &cBinop_PWwMBngN_sendMessage);
}

void Heavy_simplewind::cBinop_iNgmXkqM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NV9LJKGy, HV_BINOP_MULTIPLY, 1, m, &cBinop_NV9LJKGy_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_muvZbSkm_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8z52sEky, HV_BINOP_DIVIDE, 0, m, &cBinop_8z52sEky_sendMessage);
}

void Heavy_simplewind::cVar_L9tM22yT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qXYlqaez, 0, m, &cVar_qXYlqaez_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IbzT0oFu, 0, m, &cVar_IbzT0oFu_sendMessage);
}

void Heavy_simplewind::cBinop_ND0PSBtU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ptCVMQ5o_sendMessage);
}

void Heavy_simplewind::cBinop_mEnoP1O2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_r90Kg5Ng, 1, m);
}

void Heavy_simplewind::cBinop_0MXamQSk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_34VIoGLt, HV_BINOP_DIVIDE, 1, m, &cBinop_34VIoGLt_sendMessage);
}

void Heavy_simplewind::cBinop_gk1qcmPj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_BwK98EfF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5LTqmyos, HV_BINOP_MULTIPLY, 0, m, &cBinop_5LTqmyos_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_metDTtmk, HV_BINOP_MULTIPLY, 0, m, &cBinop_metDTtmk_sendMessage);
}

void Heavy_simplewind::cBinop_5LTqmyos_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_t0nElMON_sendMessage);
}

void Heavy_simplewind::cBinop_ZE4H2x1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PzkaMneA, HV_BINOP_DIVIDE, 0, m, &cBinop_PzkaMneA_sendMessage);
}

void Heavy_simplewind::cBinop_ImRtDtzG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5LTqmyos, HV_BINOP_MULTIPLY, 1, m, &cBinop_5LTqmyos_sendMessage);
}

void Heavy_simplewind::cBinop_yrssERi7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mEnoP1O2, HV_BINOP_MULTIPLY, 1, m, &cBinop_mEnoP1O2_sendMessage);
}

void Heavy_simplewind::cBinop_t0nElMON_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_r90Kg5Ng, 4, m);
}

void Heavy_simplewind::cBinop_BwK98EfF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ND0PSBtU_sendMessage);
}

void Heavy_simplewind::cBinop_j9s3g4ek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_gk1qcmPj_sendMessage);
}

void Heavy_simplewind::cUnop_0dpOfKk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_ImRtDtzG_sendMessage);
}

void Heavy_simplewind::cBinop_34VIoGLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_8bvdpAVQ_sendMessage);
}

void Heavy_simplewind::cBinop_PzkaMneA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_metDTtmk, HV_BINOP_MULTIPLY, 1, m, &cBinop_metDTtmk_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_0dpOfKk2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_34VIoGLt, HV_BINOP_DIVIDE, 0, m, &cBinop_34VIoGLt_sendMessage);
}

void Heavy_simplewind::cBinop_ptCVMQ5o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_r90Kg5Ng, 5, m);
}

void Heavy_simplewind::cBinop_metDTtmk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yrssERi7, HV_BINOP_ADD, 1, m, &cBinop_yrssERi7_sendMessage);
}

void Heavy_simplewind::cBinop_pnDusCNg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mEnoP1O2, HV_BINOP_MULTIPLY, 0, m, &cBinop_mEnoP1O2_sendMessage);
}

void Heavy_simplewind::cCast_jp0Hr0ta_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dQWKELLt, 0, m, &cVar_dQWKELLt_sendMessage);
}

void Heavy_simplewind::cVar_dQWKELLt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_ZE4H2x1H_sendMessage);
}

void Heavy_simplewind::cSystem_YVnTxwhJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PzkaMneA, HV_BINOP_DIVIDE, 1, m, &cBinop_PzkaMneA_sendMessage);
}

void Heavy_simplewind::cMsg_5gHpRfYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YVnTxwhJ_sendMessage);
}

void Heavy_simplewind::cVar_uxvvBNvo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_0MXamQSk_sendMessage);
}

void Heavy_simplewind::cBinop_8bvdpAVQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_j9s3g4ek_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yrssERi7, HV_BINOP_ADD, 0, m, &cBinop_yrssERi7_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_pnDusCNg_sendMessage);
}

void Heavy_simplewind::cReceive_FMDP7mkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qT9ks1lO, 0, m, &cVar_qT9ks1lO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MEezljh0, 0, m, &cVar_MEezljh0_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_A5SK7wOq, 0, m, &cVar_A5SK7wOq_sendMessage);
}

void Heavy_simplewind::cVar_qT9ks1lO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_cTVTNs60, 0, m, &cVar_cTVTNs60_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_w4qdVVLr_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AdtTEv0k, 0, m, &cVar_AdtTEv0k_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RXCwGwjY_sendMessage);
}

void Heavy_simplewind::cVar_MEezljh0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CE1No0YR, 0, m, &cVar_CE1No0YR_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WATKl0mk_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uxvvBNvo, 0, m, &cVar_uxvvBNvo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jp0Hr0ta_sendMessage);
}

void Heavy_simplewind::cMsg_YerjGTXV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_28loyaXI, m);
}

void Heavy_simplewind::cSwitchcase_aYZVsd44_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8LoD6OmI, 0, m, &cSlice_8LoD6OmI_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CNA9oJ3N, 0, m, &cRandom_CNA9oJ3N_sendMessage);
      break;
    }
  }
}

void Heavy_simplewind::cRandom_CNA9oJ3N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_Krlk9ooR_sendMessage);
}

void Heavy_simplewind::cSlice_8LoD6OmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_CNA9oJ3N, 1, m, &cRandom_CNA9oJ3N_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simplewind::cUnop_MtnJdK9d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YerjGTXV_sendMessage(_c, 0, m);
}

void Heavy_simplewind::cBinop_Krlk9ooR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_MtnJdK9d_sendMessage);
}

void Heavy_simplewind::cMsg_KXhdJhgc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 130.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_Qxg9UTAq, 0, m, &cVar_Qxg9UTAq_sendMessage);
}

void Heavy_simplewind::cBinop_pugepOCm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_zciNg3QK_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Elrr7ZOz, HV_BINOP_MULTIPLY, 0, m, &cBinop_Elrr7ZOz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_3qasQFy6, HV_BINOP_MULTIPLY, 0, m, &cBinop_3qasQFy6_sendMessage);
}

void Heavy_simplewind::cBinop_3qasQFy6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_n2oxIAPU, HV_BINOP_ADD, 1, m, &cBinop_n2oxIAPU_sendMessage);
}

void Heavy_simplewind::cBinop_n2oxIAPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SxiBgaDr, HV_BINOP_MULTIPLY, 1, m, &cBinop_SxiBgaDr_sendMessage);
}

void Heavy_simplewind::cBinop_K4asmVyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_29UDY23L_sendMessage);
}

void Heavy_simplewind::cBinop_ODi6JyVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3mb6sMn4, 5, m);
}

void Heavy_simplewind::cBinop_WGSd3Fft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3mb6sMn4, 4, m);
}

void Heavy_simplewind::cBinop_29UDY23L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_M2Bl7kDz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_n2oxIAPU, HV_BINOP_ADD, 0, m, &cBinop_n2oxIAPU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_gUm6hpjN_sendMessage);
}

void Heavy_simplewind::cBinop_zciNg3QK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_nk7Rz9jm_sendMessage);
}

void Heavy_simplewind::cBinop_Elrr7ZOz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_WGSd3Fft_sendMessage);
}

void Heavy_simplewind::cUnop_zfbxdukH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_52q22pQg_sendMessage);
}

void Heavy_simplewind::cVar_qVywKOEw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_NEmuw60l_sendMessage);
}

void Heavy_simplewind::cBinop_NEmuw60l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UdUp9HPv, HV_BINOP_DIVIDE, 0, m, &cBinop_UdUp9HPv_sendMessage);
}

void Heavy_simplewind::cBinop_nk7Rz9jm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_ODi6JyVJ_sendMessage);
}

void Heavy_simplewind::cBinop_gUm6hpjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_SxiBgaDr, HV_BINOP_MULTIPLY, 0, m, &cBinop_SxiBgaDr_sendMessage);
}

void Heavy_simplewind::cBinop_SxiBgaDr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_3mb6sMn4, 1, m);
}

void Heavy_simplewind::cBinop_M2Bl7kDz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_pugepOCm_sendMessage);
}

void Heavy_simplewind::cCast_w4qdVVLr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qVywKOEw, 0, m, &cVar_qVywKOEw_sendMessage);
}

void Heavy_simplewind::cMsg_Tnn0ML5k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_r7w6WmIr_sendMessage);
}

void Heavy_simplewind::cSystem_r7w6WmIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UdUp9HPv, HV_BINOP_DIVIDE, 1, m, &cBinop_UdUp9HPv_sendMessage);
}

void Heavy_simplewind::cBinop_ZFlpuQZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K4asmVyX, HV_BINOP_DIVIDE, 1, m, &cBinop_K4asmVyX_sendMessage);
}

void Heavy_simplewind::cBinop_52q22pQg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Elrr7ZOz, HV_BINOP_MULTIPLY, 1, m, &cBinop_Elrr7ZOz_sendMessage);
}

void Heavy_simplewind::cBinop_UdUp9HPv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_3qasQFy6, HV_BINOP_MULTIPLY, 1, m, &cBinop_3qasQFy6_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_zfbxdukH_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_K4asmVyX, HV_BINOP_DIVIDE, 0, m, &cBinop_K4asmVyX_sendMessage);
}

void Heavy_simplewind::cVar_cTVTNs60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_ZFlpuQZh_sendMessage);
}

void Heavy_simplewind::cMsg_ytE7P0VG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_ZqchcoIu, m);
}

void Heavy_simplewind::cSwitchcase_cko23i0K_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rhYRKs4x, 0, m, &cSlice_rhYRKs4x_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OwlRwcK0, 0, m, &cRandom_OwlRwcK0_sendMessage);
      break;
    }
  }
}

void Heavy_simplewind::cUnop_auHyL77P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ytE7P0VG_sendMessage(_c, 0, m);
}

void Heavy_simplewind::cBinop_4rUeXNFI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_auHyL77P_sendMessage);
}

void Heavy_simplewind::cSlice_rhYRKs4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_OwlRwcK0, 1, m, &cRandom_OwlRwcK0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simplewind::cRandom_OwlRwcK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_4rUeXNFI_sendMessage);
}

void Heavy_simplewind::cMsg_ERkNgM0g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.2f);
  cVar_onMessage(_c, &Context(_c)->cVar_MEezljh0, 0, m, &cVar_MEezljh0_sendMessage);
}

void Heavy_simplewind::cReceive_ap77CUvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_aYZVsd44_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_X0qMNzI4_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_cko23i0K_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_cTVTNs60, 0, m, &cVar_cTVTNs60_sendMessage);
  cMsg_Tnn0ML5k_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qVywKOEw, 0, m, &cVar_qVywKOEw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_CE1No0YR, 0, m, &cVar_CE1No0YR_sendMessage);
  cMsg_d4mPCZ7l_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9ImgedE5, 0, m, &cVar_9ImgedE5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_POSC8jM0, 0, m, &cVar_POSC8jM0_sendMessage);
  cMsg_5wUlXbLe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qXYlqaez, 0, m, &cVar_qXYlqaez_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_AdtTEv0k, 0, m, &cVar_AdtTEv0k_sendMessage);
  cMsg_YUUzT1Nq_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ImYE6J60, 0, m, &cVar_ImYE6J60_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_uxvvBNvo, 0, m, &cVar_uxvvBNvo_sendMessage);
  cMsg_5gHpRfYb_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_dQWKELLt, 0, m, &cVar_dQWKELLt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_f8nIr4pW, 0, m, &cVar_f8nIr4pW_sendMessage);
  cMsg_KatO2R4M_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_IbzT0oFu, 0, m, &cVar_IbzT0oFu_sendMessage);
  cMsg_ktFv4UK8_sendMessage(_c, 0, m);
  cMsg_HbemhgJq_sendMessage(_c, 0, m);
  cMsg_hk3gALr4_sendMessage(_c, 0, m);
  cMsg_jgyf58RN_sendMessage(_c, 0, m);
  cMsg_ERkNgM0g_sendMessage(_c, 0, m);
  cMsg_KXhdJhgc_sendMessage(_c, 0, m);
}

void Heavy_simplewind::cMsg_jgyf58RN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.2f);
  cVar_onMessage(_c, &Context(_c)->cVar_A5SK7wOq, 0, m, &cVar_A5SK7wOq_sendMessage);
}

void Heavy_simplewind::cVar_1qd6BzXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Qxg9UTAq, 0, m, &cVar_Qxg9UTAq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L9tM22yT, 0, m, &cVar_L9tM22yT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_0Fg95qLM, 0, m, &cVar_0Fg95qLM_sendMessage);
}

void Heavy_simplewind::cVar_Qxg9UTAq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9ImgedE5, 0, m, &cVar_9ImgedE5_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dQWKELLt, 0, m, &cVar_dQWKELLt_sendMessage);
}

void Heavy_simplewind::cMsg_hk3gALr4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 130.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_L9tM22yT, 0, m, &cVar_L9tM22yT_sendMessage);
}

void Heavy_simplewind::cVar_0Fg95qLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qVywKOEw, 0, m, &cVar_qVywKOEw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ImYE6J60, 0, m, &cVar_ImYE6J60_sendMessage);
}

void Heavy_simplewind::cBinop_ZKUAbTmx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_n5dkzjJT_sendMessage);
}

void Heavy_simplewind::cRandom_D33e11Hz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_ZKUAbTmx_sendMessage);
}

void Heavy_simplewind::cUnop_n5dkzjJT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_OJXiGw1O_sendMessage(_c, 0, m);
}

void Heavy_simplewind::cSlice_Wrdh59Du_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_D33e11Hz, 1, m, &cRandom_D33e11Hz_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_simplewind::cSwitchcase_X0qMNzI4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Wrdh59Du, 0, m, &cSlice_Wrdh59Du_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_D33e11Hz, 0, m, &cRandom_D33e11Hz_sendMessage);
      break;
    }
  }
}

void Heavy_simplewind::cMsg_OJXiGw1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_k0wfz3d5, m);
}

void Heavy_simplewind::cVar_A5SK7wOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_POSC8jM0, 0, m, &cVar_POSC8jM0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jSkr6Fxg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_f8nIr4pW, 0, m, &cVar_f8nIr4pW_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PV3xI4NC_sendMessage);
}

void Heavy_simplewind::cReceive_y9BylY82_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0Fg95qLM, 0, m, &cVar_0Fg95qLM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Qxg9UTAq, 0, m, &cVar_Qxg9UTAq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_L9tM22yT, 0, m, &cVar_L9tM22yT_sendMessage);
}

void Heavy_simplewind::cMsg_lxPcL1td_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 300.0f);
}

void Heavy_simplewind::cMsg_ktFv4UK8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 130.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_0Fg95qLM, 0, m, &cVar_0Fg95qLM_sendMessage);
}

void Heavy_simplewind::cMsg_HbemhgJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.2f);
}

void Heavy_simplewind::cBinop_PjsMrc3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bP1vJL0J_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jv7Pjklr, HV_BINOP_ADD, 0, m, &cBinop_Jv7Pjklr_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_cCtRb39k_sendMessage);
}

void Heavy_simplewind::cBinop_NerCvDnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_WmdXYqsz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_P3Mu29wX, HV_BINOP_MULTIPLY, 0, m, &cBinop_P3Mu29wX_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_IfZd6Db0, HV_BINOP_MULTIPLY, 0, m, &cBinop_IfZd6Db0_sendMessage);
}

void Heavy_simplewind::cVar_9ImgedE5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_AuAZ4E9W_sendMessage);
}

void Heavy_simplewind::cBinop_brapplz9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P3Mu29wX, HV_BINOP_MULTIPLY, 1, m, &cBinop_P3Mu29wX_sendMessage);
}

void Heavy_simplewind::cMsg_d4mPCZ7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_lHWDltxr_sendMessage);
}

void Heavy_simplewind::cSystem_lHWDltxr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qvw22M3R, HV_BINOP_DIVIDE, 1, m, &cBinop_Qvw22M3R_sendMessage);
}

void Heavy_simplewind::cBinop_NGkPXvOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_PjsMrc3H_sendMessage);
}

void Heavy_simplewind::cBinop_Qvw22M3R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_IfZd6Db0, HV_BINOP_MULTIPLY, 1, m, &cBinop_IfZd6Db0_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_DFuMXeZZ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NGkPXvOE, HV_BINOP_DIVIDE, 0, m, &cBinop_NGkPXvOE_sendMessage);
}

void Heavy_simplewind::cBinop_8nvKSPGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_FdaUkxV7, 5, m);
}

void Heavy_simplewind::cBinop_AuAZ4E9W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Qvw22M3R, HV_BINOP_DIVIDE, 0, m, &cBinop_Qvw22M3R_sendMessage);
}

void Heavy_simplewind::cBinop_e7hUNND5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_FdaUkxV7, 4, m);
}

void Heavy_simplewind::cBinop_cCtRb39k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kerqTkJq, HV_BINOP_MULTIPLY, 0, m, &cBinop_kerqTkJq_sendMessage);
}

void Heavy_simplewind::cBinop_P3Mu29wX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_e7hUNND5_sendMessage);
}

void Heavy_simplewind::cBinop_IfZd6Db0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jv7Pjklr, HV_BINOP_ADD, 1, m, &cBinop_Jv7Pjklr_sendMessage);
}

void Heavy_simplewind::cBinop_5Kb8A6o5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_8nvKSPGs_sendMessage);
}

void Heavy_simplewind::cBinop_WmdXYqsz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5Kb8A6o5_sendMessage);
}

void Heavy_simplewind::cVar_CE1No0YR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_h4wJ1p5v_sendMessage);
}

void Heavy_simplewind::cBinop_h4wJ1p5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NGkPXvOE, HV_BINOP_DIVIDE, 1, m, &cBinop_NGkPXvOE_sendMessage);
}

void Heavy_simplewind::cBinop_bP1vJL0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_NerCvDnG_sendMessage);
}

void Heavy_simplewind::cBinop_kerqTkJq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_FdaUkxV7, 1, m);
}

void Heavy_simplewind::cCast_WATKl0mk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9ImgedE5, 0, m, &cVar_9ImgedE5_sendMessage);
}

void Heavy_simplewind::cBinop_Jv7Pjklr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kerqTkJq, HV_BINOP_MULTIPLY, 1, m, &cBinop_kerqTkJq_sendMessage);
}

void Heavy_simplewind::cUnop_DFuMXeZZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_brapplz9_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_simplewind::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

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

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_i(&sVari_28loyaXI, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_28loyaXI, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_3mb6sMn4, VIf(Bf1), VOf(Bf1));
    __hv_biquad_k_f(&sBiquad_k_fC0JfbU8, VIf(Bf1), VOf(Bf1));
    __hv_varread_i(&sVari_k0wfz3d5, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varwrite_i(&sVari_k0wfz3d5, VIi(Bi0));
    __hv_biquad_k_f(&sBiquad_k_FdaUkxV7, VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_r90Kg5Ng, VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_i(&sVari_ZqchcoIu, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_varwrite_i(&sVari_ZqchcoIu, VIi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_HmP6VGy4, VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_0md13wFu, VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_simplewind::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_simplewind::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

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
