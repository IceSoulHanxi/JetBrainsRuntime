/*
 * Copyright (c) 1997, 2013, Oracle and/or its affiliates. All rights reserved.
 * Copyright (c) 2015, 2023, Loongson Technology. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef CPU_LOONGARCH_VM_VERSION_LOONGARCH_HPP
#define CPU_LOONGARCH_VM_VERSION_LOONGARCH_HPP

#include "runtime/abstract_vm_version.hpp"
#include "runtime/globals_extension.hpp"
#include "utilities/sizes.hpp"

class VM_Version: public Abstract_VM_Version {
  friend class JVMCIVMStructs;

public:

  union LoongArch_Cpucfg_Id0 {
    uint32_t value;
    struct {
      uint32_t PRID      : 32;
    } bits;
  };

  union LoongArch_Cpucfg_Id1 {
    uint32_t value;
    struct {
      uint32_t ARCH      : 2,
               PGMMU     : 1,
               IOCSR     : 1,
               PALEN     : 8,
               VALEN     : 8,
               UAL       : 1, // unaligned access
               RI        : 1,
               EP        : 1,
               RPLV      : 1,
               HP        : 1,
               IOCSR_BRD : 1,
               MSG_INT   : 1,
                         : 5;
    } bits;
  };

  union LoongArch_Cpucfg_Id2 {
    uint32_t value;
    struct {
      uint32_t FP_CFG     : 1, // FP is used, use FP_CFG instead
               FP_SP      : 1,
               FP_DP      : 1,
               FP_VER     : 3,
               LSX        : 1,
               LASX       : 1,
               COMPLEX    : 1,
               CRYPTO     : 1,
               LVZ        : 1,
               LVZ_VER    : 3,
               LLFTP      : 1,
               LLFTP_VER  : 3,
               LBT_X86    : 1,
               LBT_ARM    : 1,
               LBT_MIPS   : 1,
               LSPW       : 1,
               LAM        : 1,
                          : 9;
    } bits;
  };

  union LoongArch_Cpucfg_Id3 {
    uint32_t value;
    struct {
      uint32_t CCDMA      : 1,
               SFB        : 1,
               UCACC      : 1,
               LLEXC      : 1,
               SCDLY      : 1,
               LLDBAR     : 1,
               ITLBHMC    : 1,
               ICHMC      : 1,
               SPW_LVL    : 3,
               SPW_HP_HF  : 1,
               RVA        : 1,
               RVAMAXM1   : 4,
                          : 15;
    } bits;
  };

  union LoongArch_Cpucfg_Id4 {
    uint32_t value;
    struct {
      uint32_t CC_FREQ      : 32;
    } bits;
  };

  union LoongArch_Cpucfg_Id5 {
    uint32_t value;
    struct {
      uint32_t CC_MUL      : 16,
               CC_DIV      : 16;
    } bits;
  };

  union LoongArch_Cpucfg_Id6 {
    uint32_t value;
    struct {
      uint32_t PMP      : 1,
               PMVER    : 3,
               PMNUM    : 4,
               PMBITS   : 6,
               UPM      : 1,
                        : 17;
    } bits;
  };

  union LoongArch_Cpucfg_Id10 {
    uint32_t value;
    struct {
      uint32_t L1IU_PRESENT    : 1,
               L1IU_UNIFY      : 1,
               L1D_PRESENT     : 1,
               L2IU_PRESENT    : 1,
               L2IU_UNIFY      : 1,
               L2IU_PRIVATE    : 1,
               L2IU_INCLUSIVE  : 1,
               L2D_PRESENT     : 1,
               L2D_PRIVATE     : 1,
               L2D_INCLUSIVE   : 1,
               L3IU_PRESENT    : 1,
               L3IU_UNIFY      : 1,
               L3IU_PRIVATE    : 1,
               L3IU_INCLUSIVE  : 1,
               L3D_PRESENT     : 1,
               L3D_PRIVATE     : 1,
               L3D_INCLUSIVE   : 1,
                               : 15;
    } bits;
  };

  union LoongArch_Cpucfg_Id11 {
    uint32_t value;
    struct {
      uint32_t WAYM1         : 16,
               INDEXMLOG2    : 8,
               LINESIZELOG2  : 7,
                             : 1;
    } bits;
  };

  union LoongArch_Cpucfg_Id12 {
    uint32_t value;
    struct {
      uint32_t WAYM1         : 16,
               INDEXMLOG2    : 8,
               LINESIZELOG2  : 7,
                             : 1;
    } bits;
  };

  union LoongArch_Cpucfg_Id13 {
    uint32_t value;
    struct {
      uint32_t WAYM1         : 16,
               INDEXMLOG2    : 8,
               LINESIZELOG2  : 7,
                             : 1;
    } bits;
  };

  union LoongArch_Cpucfg_Id14 {
    uint32_t value;
    struct {
      uint32_t WAYM1         : 16,
               INDEXMLOG2    : 8,
               LINESIZELOG2  : 7,
                             : 1;
    } bits;
  };

#define CPU_FEATURE_FLAGS(decl)                 \
    decl(LAM,           lam,             1)     \
    decl(UAL,           ual,             2)     \
    decl(LSX,           lsx,             4)     \
    decl(LASX,          lasx,            5)     \
    decl(COMPLEX,       complex,         7)     \
    decl(CRYPTO,        crypto,          8)     \
    decl(LBT_X86,       lbt_x86,         10)    \
    decl(LBT_ARM,       lbt_arm,         11)    \
    decl(LBT_MIPS,      lbt_mips,        12)    \
    /* flags above must follow Linux HWCAP */   \
    decl(LA32,          la32,            13)    \
    decl(LA64,          la64,            14)    \
    decl(FP,            fp,              15)    \
    decl(LLEXC,         llexc,           16)    \
    decl(SCDLY,         scdly,           17)    \
    decl(LLDBAR,        lldbar,          18)    \
    decl(CCDMA,         ccdma,           19)    \
    decl(LLSYNC,        llsync,          20)    \
    decl(TGTSYNC,       tgtsync,         21)    \
    decl(ULSYNC,        ulsync,          22)    \

  enum Feature_Flag {
#define DECLARE_CPU_FEATURE_FLAG(id, name, bit) CPU_##id = (1 << bit),
    CPU_FEATURE_FLAGS(DECLARE_CPU_FEATURE_FLAG)
#undef DECLARE_CPU_FEATURE_FLAG
  };

protected:

  static bool _cpu_info_is_initialized;

  struct CpuidInfo {
    LoongArch_Cpucfg_Id0   cpucfg_info_id0;
    LoongArch_Cpucfg_Id1   cpucfg_info_id1;
    LoongArch_Cpucfg_Id2   cpucfg_info_id2;
    LoongArch_Cpucfg_Id3   cpucfg_info_id3;
    LoongArch_Cpucfg_Id4   cpucfg_info_id4;
    LoongArch_Cpucfg_Id5   cpucfg_info_id5;
    LoongArch_Cpucfg_Id6   cpucfg_info_id6;
    LoongArch_Cpucfg_Id10  cpucfg_info_id10;
    LoongArch_Cpucfg_Id11  cpucfg_info_id11;
    LoongArch_Cpucfg_Id12  cpucfg_info_id12;
    LoongArch_Cpucfg_Id13  cpucfg_info_id13;
    LoongArch_Cpucfg_Id14  cpucfg_info_id14;
  };

  // The actual cpuid info block
  static CpuidInfo _cpuid_info;

  static uint32_t get_feature_flags_by_cpucfg();
  static void     get_processor_features();
  static void     get_os_cpu_info();

public:
  // Offsets for cpuid asm stub
  static ByteSize Loongson_Cpucfg_id0_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id0); }
  static ByteSize Loongson_Cpucfg_id1_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id1); }
  static ByteSize Loongson_Cpucfg_id2_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id2); }
  static ByteSize Loongson_Cpucfg_id3_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id3); }
  static ByteSize Loongson_Cpucfg_id4_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id4); }
  static ByteSize Loongson_Cpucfg_id5_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id5); }
  static ByteSize Loongson_Cpucfg_id6_offset()  { return byte_offset_of(CpuidInfo, cpucfg_info_id6); }
  static ByteSize Loongson_Cpucfg_id10_offset() { return byte_offset_of(CpuidInfo, cpucfg_info_id10); }
  static ByteSize Loongson_Cpucfg_id11_offset() { return byte_offset_of(CpuidInfo, cpucfg_info_id11); }
  static ByteSize Loongson_Cpucfg_id12_offset() { return byte_offset_of(CpuidInfo, cpucfg_info_id12); }
  static ByteSize Loongson_Cpucfg_id13_offset() { return byte_offset_of(CpuidInfo, cpucfg_info_id13); }
  static ByteSize Loongson_Cpucfg_id14_offset() { return byte_offset_of(CpuidInfo, cpucfg_info_id14); }

  static void clean_cpuFeatures()   { _features = 0; }

  // Initialization
  static void initialize();

  static bool cpu_info_is_initialized()                   { return _cpu_info_is_initialized; }

  static bool is_la32()             { return _features & CPU_LA32; }
  static bool is_la64()             { return _features & CPU_LA64; }
  static bool supports_crypto()     { return _features & CPU_CRYPTO; }
  static bool supports_lsx()        { return _features & CPU_LSX; }
  static bool supports_lasx()       { return _features & CPU_LASX; }
  static bool supports_lam()        { return _features & CPU_LAM; }
  static bool supports_llexc()      { return _features & CPU_LLEXC; }
  static bool supports_scdly()      { return _features & CPU_SCDLY; }
  static bool supports_lldbar()     { return _features & CPU_LLDBAR; }
  static bool supports_ual()        { return _features & CPU_UAL; }
  static bool supports_lbt_x86()    { return _features & CPU_LBT_X86; }
  static bool supports_lbt_arm()    { return _features & CPU_LBT_ARM; }
  static bool supports_lbt_mips()   { return _features & CPU_LBT_MIPS; }
  static bool needs_llsync()        { return !supports_lldbar(); }
  static bool needs_tgtsync()       { return 1; }
  static bool needs_ulsync()        { return 1; }

  static bool supports_fast_class_init_checks() { return true; }
  static bool supports_float16() { return UseLSX; }
  constexpr static bool supports_stack_watermark_barrier() { return true; }

  // Check intrinsic support
  static bool is_intrinsic_supported(vmIntrinsicID id);

  static void initialize_cpu_information(void);
};

#endif // CPU_LOONGARCH_VM_VERSION_LOONGARCH_HPP
