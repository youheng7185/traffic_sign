/**
  ******************************************************************************
  * @file    network_bin_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-06-11T11:28:10+0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_bin_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_bin_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_bin_weights_array_u64[206] = {
  0xcbebb22127d2314eU, 0xc5e41c1e7f476fbdU, 0x1f0fbb4565ffa5b9U, 0x1d1f6033c5ecc3baU,
  0x141efcd016190e6eU, 0x8fa816d2200db2e9U, 0x291cf1d2fc81b8c6U, 0xd11fafbb581a812U,
  0x16210113fd1002faU, 0xf205efedf2120a09U, 0xffdb1fe82d343e0bU, 0xe5e8b2dbfbc40d1bU,
  0xe1b7077f1bf31dffU, 0x4594b39df92b0f04U, 0x61625a2a1f41186aU, 0xa8abac87a4e4ace9U,
  0xbd2a201827615481U, 0xb5400212119ca2aU, 0xb481d83ce3f311d6U, 0x20110ee7d620db90U,
  0x2b0ae3c2f53b2b3bU, 0xe0ec50f5cc01d027U, 0x1253e4c80ef1087fU, 0xf40b0d58bfee23ceU,
  0xdfd0af70af20010U, 0xdeefeb0802041ed9U, 0xf1131081d2e59809U, 0x57a1ffffad56U,
  0xfffffaf90000033eU, 0x1f13fffffe42U, 0xce7ffffe244U, 0x7f03fb0a0503e502U,
  0x6611f815f3eef8d8U, 0x3513fa0e00e9e8c7U, 0x6404e9e0f5edf1edU, 0x5904defeeeddf5bcU,
  0x3a06c7e0efb0f8bcU, 0x2603120c0a790fedU, 0x2914161f00770ec1U, 0x16130614f9560fa7U,
  0x78f3151a1bb8fc1fU, 0x7fef08fc00cef6f6U, 0x7fde281e0bad0fbeU, 0xe1011f020d28f40eU,
  0xef0cfd03fc19f6fdU, 0xdff41a09fc1afdd2U, 0xc0fa23170a3af612U, 0xc3ff05040241f1faU,
  0xd9f72719fd2f04c7U, 0x62ed1b09001ff802U, 0x62020d0c0825f6feU, 0x7fec1b0f002708eeU,
  0xfcff200f052df4fbU, 0xf90117ff032beff9U, 0xfaf218010b2b04edU, 0xe9f02a11153df300U,
  0xd805190d0142f503U, 0xefeb1d031146fdefU, 0x7ffe17190907fa06U, 0x7d011519090b01faU,
  0x6a01243d030505faU, 0x1d001d160efef200U, 0x1d0d1a1d0609fbf8U, 0x1b042036fd00fcfdU,
  0xe9f5241a0e57f205U, 0xeb001427074ef8faU, 0xddf72241084ef7feU, 0x64fa251e1326fb08U,
  0x600c1c120d2cf208U, 0x7fed34000c2902e6U, 0xecee230609bce107U, 0xe90116fc0abce8feU,
  0xeae812e608b2fceaU, 0xd8f0300a0f3af7feU, 0xd5fb2b071138f400U, 0xf3e226f61438fae8U,
  0x640423181f30f30cU, 0x5ffd0afe181ceceeU, 0x7ff12d12162f08edU, 0xeaf220060cc4e10cU,
  0xedee08020db8dfedU, 0xf4e71afe06aefdf2U, 0xe5f11e08163bf008U, 0xed0016ff1536f2eeU,
  0xf6ee2cf813350aeaU, 0x7df60f270726f4f6U, 0x7f01ff29f616f504U, 0x79fb032d02240003U,
  0x407001cfb20f2feU, 0x304f818fd22f6faU, 0xf7fcf01ffc25f101U, 0x1e03031c0358f5f5U,
  0x2504f927f652f203U, 0x1dfa062d0754f4ffU, 0xa52314de25f03632U, 0xbe0221df0fec3910U,
  0x812f1b0115f24524U, 0x370d03ef1ff63255U, 0x47ed12f021e9252aU, 0x471f150315011b3aU,
  0x35190cee17023563U, 0x3b0107ed26fa2d35U, 0x511809fd27fc1e44U, 0x7f021724071307ffU,
  0x77090f1d020f05ffU, 0x5dfa284a001606f6U, 0x25061e1c040902ffU, 0x2606112002160102U,
  0x1bfd1e40fe0afcfeU, 0x2901211cff51fbfcU, 0x1cff111dfe55fdfcU, 0x21fa213e0a61fcfaU,
  0x7cdd230836cb0235U, 0x76e0fa0216c3effaU, 0x7fdb2a201dbb0ec7U, 0xe8d3290b17daeb20U,
  0xe9d90af505dfedf6U, 0xe6c01d0500b607ceU, 0xcdd427061854021aU, 0xcedc09f30663f6dcU,
  0xd3d53c11045f0cc1U, 0x90fc5e5f72ed2ebU, 0x1dffb8dced48e819U, 0x52f1bbd9e754d1d4U,
  0x130fbbe8fa220ffaU, 0x1d14bed6fe2f0d19U, 0x3810b0c4023c0de5U, 0x5f12d6eaffb6f6f6U,
  0x60fbc3dcfabc021fU, 0x7ff9bae0f6f201dbU, 0x71f12414160c0817U, 0x61e2fa010216fd0cU,
  0x7fcc1e1efc0706c2U, 0xccfe0e0f110ff716U, 0xf2fafbeafa1bf005U, 0xf1d8130cf51bfecdU,
  0xd9fd0c030f32f01aU, 0xddeaf9ed0e23f70cU, 0x1da20150d1ff9c5U, 0x7f081e2210eefd0eU,
  0x72f6f4040deffcf5U, 0x76ef202d07e300cdU, 0xfc03121e0f15f404U, 0xf507f7fd0911f0ffU,
  0xf6f816250d0bfaddU, 0xda031819173af513U, 0xd4f801fd063df5faU, 0xdaf21b23123dfad5U,
  0xd3001f19f426dff5U, 0xb1e32c1f0f32f5f9U, 0x81dce0f8e623bbf4U, 0x1bf92b2a0b27effeU,
  0x9e53c29152801f3U, 0xd7e40d0bfb28d1f9U, 0x29fc2e220c1d07f8U, 0x1de53c2f051c09e5U,
  0x8ed0f19f025eaeeU, 0x8a17fce50ce73a33U, 0x960cfed814f03e19U, 0x8131f5df10df2725U,
  0x34130afb25eb2a40U, 0x3cfa06f313e21d2fU, 0x3c2a01f21cfa2935U, 0x2f1af1e50ccb1358U,
  0x2015f8de22d61719U, 0x2132faea1dc31a2aU, 0x7ff3150f0cdcf500U, 0x7d030a170be5fbf9U,
  0x7af4292e0bee00f5U, 0x22fb1a1b0011f100U, 0x180b0c130715f3feU, 0x180115320e17fdf7U,
  0xd7f81d1b0651f3faU, 0xdf001324074cfafcU, 0xcaf82a3c1458f7f5U, 0xba000003a7U,
  0xfffffd73000003dfU, 0x6c000000885U, 0xfffffe2a00000434U, 0xffffffdcfffffde2U,
  0xa800000f17U, 0xfffffc21fffffe02U, 0xffffff7400000701U, 0xe13550ffc1155c24U,
  0xf1c80e819af09921U, 0x11f1e0db03f6ea81U, 0xf1225ffaecdde313U, 0x24c0f50ed119e681U,
  0xdd1c60c20532e5c5U, 0x84006c8411888126U, 0xc1fec359efcba388U, 0xf4e9bc5681ca8f95U,
  0x9f8b41b8173d429cU, 0x18133e481d3f377fU, 0x2e109d262c14552bU, 0x1b11c1299e8f39aU,
  0xcf237fb4fe3fdd93U, 0x2de4d2cefb010284U, 0x121d59f6e781d7fbU, 0xdffffff69U,
  0x186U, 0x15effffffe3U, 0xffffffac0000050dU, 0xa881fd04f6bbace3U,
  0x3f7fd50afb3f1ff0U, 0xffffffac0000005dU,
};


ai_handle g_network_bin_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_bin_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

