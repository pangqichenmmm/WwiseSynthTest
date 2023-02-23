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

#ifndef _HEAVY_CONTEXT_SIMPLEWIND_HPP_
#define _HEAVY_CONTEXT_SIMPLEWIND_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlRandom.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvSignalBiquad.h"
#include "HvMath.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"

class Heavy_simplewind : public HeavyContext {

 public:
  Heavy_simplewind(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_simplewind();

  const char *getName() override { return "simplewind"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        Q = 0xF3BA5CD4, // Q
        CENTERFREQUENCY_01 = 0x539436C5, // centerFrequency_01
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_LNariU1G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HI6yFwth_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JXqHpLBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YUUzT1Nq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Ut2KROdh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MpukXy1s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RXCwGwjY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xD0WXOdt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QYiXp3oS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2ELCgWs7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9RBd7wYr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5mgrQimj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AdtTEv0k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uKCrqlef_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j77bfEW0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qARU9djJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YhJ2mUVn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ImYE6J60_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_5NgUs3TE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KjW7NUFS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_asjdDVST_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HlIpYDxl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cyfHx8lk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7mEaJmV3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vWWR6X0n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_56lHuWtG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pFwJNtMv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ilqDtc7I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_rvFHrFrb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w4dgY1iW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jSkr6Fxg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hrvoaqTs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VKvxcsVu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B0Dy87Gm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_H92SaStD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4794lSFM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5wUlXbLe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_E7n2i3mx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_POSC8jM0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GUl7WROr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qXYlqaez_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZipaQtMp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Gow4UYW1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hv5LRCYI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SLJlhNQU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VPrHRjEA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aToNe714_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aDpZAXeA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s5yIf5HM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X14ugGAI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wjlNfbPF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qCo9Cosy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HvX7eRXo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B6Ow3bNZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_f8nIr4pW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qXYJP8wz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NV9LJKGy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3qulVK9O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qvVxm5vQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JIG2sfaR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6Dp77w1V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IbzT0oFu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8z52sEky_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_muvZbSkm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KatO2R4M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_rnVTF3g0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PWwMBngN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PV3xI4NC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dsbb3CKr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iNgmXkqM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_L9tM22yT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ND0PSBtU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mEnoP1O2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0MXamQSk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gk1qcmPj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5LTqmyos_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZE4H2x1H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ImRtDtzG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yrssERi7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t0nElMON_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BwK98EfF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j9s3g4ek_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_0dpOfKk2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_34VIoGLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PzkaMneA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ptCVMQ5o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_metDTtmk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pnDusCNg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jp0Hr0ta_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dQWKELLt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YVnTxwhJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5gHpRfYb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uxvvBNvo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8bvdpAVQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FMDP7mkC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qT9ks1lO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MEezljh0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YerjGTXV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aYZVsd44_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cRandom_CNA9oJ3N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8LoD6OmI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_MtnJdK9d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Krlk9ooR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KXhdJhgc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pugepOCm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3qasQFy6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_n2oxIAPU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_K4asmVyX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ODi6JyVJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WGSd3Fft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_29UDY23L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zciNg3QK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Elrr7ZOz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_zfbxdukH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qVywKOEw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NEmuw60l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nk7Rz9jm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gUm6hpjN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SxiBgaDr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M2Bl7kDz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_w4qdVVLr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Tnn0ML5k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_r7w6WmIr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZFlpuQZh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_52q22pQg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UdUp9HPv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_cTVTNs60_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ytE7P0VG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cko23i0K_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cUnop_auHyL77P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4rUeXNFI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_rhYRKs4x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_OwlRwcK0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ERkNgM0g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ap77CUvR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jgyf58RN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1qd6BzXE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Qxg9UTAq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hk3gALr4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0Fg95qLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZKUAbTmx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_D33e11Hz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_n5dkzjJT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Wrdh59Du_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_X0qMNzI4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cMsg_OJXiGw1O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_A5SK7wOq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_y9BylY82_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lxPcL1td_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ktFv4UK8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HbemhgJq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PjsMrc3H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NerCvDnG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9ImgedE5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_brapplz9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d4mPCZ7l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_lHWDltxr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NGkPXvOE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qvw22M3R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8nvKSPGs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AuAZ4E9W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e7hUNND5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cCtRb39k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_P3Mu29wX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IfZd6Db0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5Kb8A6o5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WmdXYqsz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CE1No0YR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h4wJ1p5v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bP1vJL0J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kerqTkJq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WATKl0mk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jv7Pjklr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_DFuMXeZZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalBiquad_k sBiquad_k_3mb6sMn4;
  SignalBiquad_k sBiquad_k_fC0JfbU8;
  SignalBiquad_k sBiquad_k_FdaUkxV7;
  SignalBiquad_k sBiquad_k_r90Kg5Ng;
  SignalBiquad_k sBiquad_k_HmP6VGy4;
  SignalBiquad_k sBiquad_k_0md13wFu;
  ControlBinop cBinop_LNariU1G;
  ControlBinop cBinop_HI6yFwth;
  ControlBinop cBinop_JXqHpLBG;
  ControlBinop cBinop_MpukXy1s;
  ControlBinop cBinop_xD0WXOdt;
  ControlBinop cBinop_QYiXp3oS;
  ControlBinop cBinop_2ELCgWs7;
  ControlBinop cBinop_9RBd7wYr;
  ControlBinop cBinop_5mgrQimj;
  ControlVar cVar_AdtTEv0k;
  ControlBinop cBinop_uKCrqlef;
  ControlBinop cBinop_j77bfEW0;
  ControlBinop cBinop_qARU9djJ;
  ControlBinop cBinop_YhJ2mUVn;
  ControlVar cVar_ImYE6J60;
  ControlBinop cBinop_KjW7NUFS;
  ControlBinop cBinop_asjdDVST;
  ControlBinop cBinop_HlIpYDxl;
  ControlBinop cBinop_cyfHx8lk;
  ControlBinop cBinop_7mEaJmV3;
  ControlBinop cBinop_vWWR6X0n;
  ControlBinop cBinop_56lHuWtG;
  ControlBinop cBinop_pFwJNtMv;
  ControlBinop cBinop_ilqDtc7I;
  ControlBinop cBinop_w4dgY1iW;
  ControlBinop cBinop_hrvoaqTs;
  ControlBinop cBinop_VKvxcsVu;
  ControlBinop cBinop_B0Dy87Gm;
  ControlBinop cBinop_H92SaStD;
  ControlBinop cBinop_4794lSFM;
  ControlVar cVar_POSC8jM0;
  ControlBinop cBinop_GUl7WROr;
  ControlVar cVar_qXYlqaez;
  ControlBinop cBinop_ZipaQtMp;
  ControlBinop cBinop_Gow4UYW1;
  ControlBinop cBinop_hv5LRCYI;
  ControlBinop cBinop_SLJlhNQU;
  ControlBinop cBinop_VPrHRjEA;
  ControlVar cVar_aToNe714;
  ControlBinop cBinop_aDpZAXeA;
  ControlBinop cBinop_s5yIf5HM;
  ControlBinop cBinop_X14ugGAI;
  ControlBinop cBinop_wjlNfbPF;
  ControlBinop cBinop_qCo9Cosy;
  ControlBinop cBinop_HvX7eRXo;
  ControlBinop cBinop_B6Ow3bNZ;
  ControlVar cVar_f8nIr4pW;
  ControlBinop cBinop_qXYJP8wz;
  ControlBinop cBinop_NV9LJKGy;
  ControlBinop cBinop_3qulVK9O;
  ControlBinop cBinop_qvVxm5vQ;
  ControlBinop cBinop_JIG2sfaR;
  ControlBinop cBinop_6Dp77w1V;
  ControlVar cVar_IbzT0oFu;
  ControlBinop cBinop_8z52sEky;
  ControlBinop cBinop_PWwMBngN;
  ControlBinop cBinop_Dsbb3CKr;
  ControlBinop cBinop_iNgmXkqM;
  ControlVar cVar_L9tM22yT;
  ControlBinop cBinop_ND0PSBtU;
  ControlBinop cBinop_mEnoP1O2;
  ControlBinop cBinop_0MXamQSk;
  ControlBinop cBinop_gk1qcmPj;
  ControlBinop cBinop_5LTqmyos;
  ControlBinop cBinop_ZE4H2x1H;
  ControlBinop cBinop_ImRtDtzG;
  ControlBinop cBinop_yrssERi7;
  ControlBinop cBinop_t0nElMON;
  ControlBinop cBinop_BwK98EfF;
  ControlBinop cBinop_j9s3g4ek;
  ControlBinop cBinop_34VIoGLt;
  ControlBinop cBinop_PzkaMneA;
  ControlBinop cBinop_ptCVMQ5o;
  ControlBinop cBinop_metDTtmk;
  ControlBinop cBinop_pnDusCNg;
  ControlVar cVar_dQWKELLt;
  ControlVar cVar_uxvvBNvo;
  ControlBinop cBinop_8bvdpAVQ;
  ControlVar cVar_qT9ks1lO;
  ControlVar cVar_MEezljh0;
  ControlRandom cRandom_CNA9oJ3N;
  ControlSlice cSlice_8LoD6OmI;
  ControlBinop cBinop_Krlk9ooR;
  SignalVari sVari_28loyaXI;
  ControlBinop cBinop_pugepOCm;
  ControlBinop cBinop_3qasQFy6;
  ControlBinop cBinop_n2oxIAPU;
  ControlBinop cBinop_K4asmVyX;
  ControlBinop cBinop_ODi6JyVJ;
  ControlBinop cBinop_WGSd3Fft;
  ControlBinop cBinop_29UDY23L;
  ControlBinop cBinop_zciNg3QK;
  ControlBinop cBinop_Elrr7ZOz;
  ControlVar cVar_qVywKOEw;
  ControlBinop cBinop_NEmuw60l;
  ControlBinop cBinop_nk7Rz9jm;
  ControlBinop cBinop_gUm6hpjN;
  ControlBinop cBinop_SxiBgaDr;
  ControlBinop cBinop_M2Bl7kDz;
  ControlBinop cBinop_ZFlpuQZh;
  ControlBinop cBinop_52q22pQg;
  ControlBinop cBinop_UdUp9HPv;
  ControlVar cVar_cTVTNs60;
  ControlBinop cBinop_4rUeXNFI;
  ControlSlice cSlice_rhYRKs4x;
  ControlRandom cRandom_OwlRwcK0;
  SignalVari sVari_ZqchcoIu;
  ControlVar cVar_1qd6BzXE;
  ControlVar cVar_Qxg9UTAq;
  ControlVar cVar_0Fg95qLM;
  ControlBinop cBinop_ZKUAbTmx;
  ControlRandom cRandom_D33e11Hz;
  ControlSlice cSlice_Wrdh59Du;
  SignalVari sVari_k0wfz3d5;
  ControlVar cVar_A5SK7wOq;
  ControlBinop cBinop_PjsMrc3H;
  ControlBinop cBinop_NerCvDnG;
  ControlVar cVar_9ImgedE5;
  ControlBinop cBinop_brapplz9;
  ControlBinop cBinop_NGkPXvOE;
  ControlBinop cBinop_Qvw22M3R;
  ControlBinop cBinop_8nvKSPGs;
  ControlBinop cBinop_AuAZ4E9W;
  ControlBinop cBinop_e7hUNND5;
  ControlBinop cBinop_cCtRb39k;
  ControlBinop cBinop_P3Mu29wX;
  ControlBinop cBinop_IfZd6Db0;
  ControlBinop cBinop_5Kb8A6o5;
  ControlBinop cBinop_WmdXYqsz;
  ControlVar cVar_CE1No0YR;
  ControlBinop cBinop_h4wJ1p5v;
  ControlBinop cBinop_bP1vJL0J;
  ControlBinop cBinop_kerqTkJq;
  ControlBinop cBinop_Jv7Pjklr;
};

#endif // _HEAVY_CONTEXT_SIMPLEWIND_HPP_
