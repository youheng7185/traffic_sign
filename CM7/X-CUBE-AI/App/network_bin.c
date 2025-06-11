/**
  ******************************************************************************
  * @file    network_bin.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-06-11T10:47:20+0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "network_bin.h"
#include "network_bin_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_bin
 
#undef AI_NETWORK_BIN_MODEL_SIGNATURE
#define AI_NETWORK_BIN_MODEL_SIGNATURE     "0x787aede3026c9361c89aecc86c4b5d18"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2025-06-11T10:47:20+0800"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_BIN_N_BATCHES
#define AI_NETWORK_BIN_N_BATCHES         (1)

static ai_ptr g_network_bin_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_network_bin_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_keras_tensor_90_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3072, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3073, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  gemm_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  nl_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conversion_8_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 216, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  gemm_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  gemm_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 2, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 652, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2816, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  gemm_5_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 56, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  gemm_6_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 18, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  nl_7_scratch0_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 124, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0107796099036932f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0107796099036932f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004526991862803698f, 0.005349670071154833f, 0.012187550775706768f, 0.005402963608503342f, 0.0036712519358843565f, 0.005637998227030039f, 0.005039249546825886f, 0.014201853424310684f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.057082150131464005f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.15037113428115845f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01656840741634369f, 0.014207970350980759f, 0.016037115827202797f, 0.019287144765257835f, 0.014246663078665733f, 0.014620183035731316f, 0.017905961722135544f, 0.010419824160635471f, 0.024744579568505287f, 0.012384855188429356f, 0.014689277857542038f, 0.014402675442397594f, 0.018972555175423622f, 0.016761282458901405f, 0.011503278277814388f, 0.017944522202014923f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_8_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_5_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18880410492420197f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_5_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004512723069638014f, 0.019482199102640152f, 0.012307986617088318f, 0.003769651288166642f, 0.0039014299400150776f, 0.01670967973768711f, 0.009512323886156082f, 0.01629040576517582f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.23075531423091888f),
    AI_PACK_INTQ_ZP(106)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_6_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 2,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023382287472486496f, 0.026012655347585678f),
    AI_PACK_INTQ_ZP(0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_7_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_keras_tensor_90_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003921568859368563f),
    AI_PACK_UINTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 16, 16), AI_STRIDE_INIT(4, 1, 1, 8, 128),
  1, &conv2d_1_output_array, &conv2d_1_output_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 652, 1, 1), AI_STRIDE_INIT(4, 1, 1, 652, 652),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 2), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 8), AI_STRIDE_INIT(4, 1, 3, 24, 72),
  1, &conv2d_1_weights_array, &conv2d_1_weights_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 1, 1, 16, 16),
  1, &conv2d_3_output_array, &conv2d_3_output_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 2816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2816, 2816),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 8, 3, 3, 16), AI_STRIDE_INIT(4, 1, 8, 128, 384),
  1, &conv2d_3_weights_array, &conv2d_3_weights_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &conversion_0_output_array, &conversion_0_output_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conversion_8_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &conversion_8_output_array, &conversion_8_output_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &gemm_5_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8, 8),
  1, &gemm_5_output_array, &gemm_5_output_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_scratch0, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 2, 2, 112, 112),
  1, &gemm_5_scratch0_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  gemm_5_weights, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 16, 8, 1, 1), AI_STRIDE_INIT(4, 1, 16, 128, 128),
  1, &gemm_5_weights_array, &gemm_5_weights_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  gemm_6_bias, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &gemm_6_bias_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  gemm_6_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &gemm_6_output_array, &gemm_6_output_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  gemm_6_scratch0, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 2, 2, 36, 36),
  1, &gemm_6_scratch0_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  gemm_6_weights, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 8, 2, 1, 1), AI_STRIDE_INIT(4, 1, 8, 16, 16),
  1, &gemm_6_weights_array, &gemm_6_weights_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  nl_7_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &nl_7_output_array, &nl_7_output_array_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  nl_7_scratch0, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 124, 1, 1), AI_STRIDE_INIT(4, 4, 4, 496, 496),
  1, &nl_7_scratch0_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_keras_tensor_90_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 32, 32), AI_STRIDE_INIT(4, 1, 1, 3, 96),
  1, &serving_default_keras_tensor_90_output_array, &serving_default_keras_tensor_90_output_array_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_8_layer, 8,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_8_chain,
  NULL, &conversion_8_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i32 nl_7_nl_params_data[] = { 1982173056, 24, -124 };
AI_ARRAY_OBJ_DECLARE(
    nl_7_nl_params, AI_ARRAY_FORMAT_S32,
    nl_7_nl_params_data, nl_7_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  nl_7_layer, 7,
  SM_TYPE, 0x0, NULL,
  sm, forward_sm_integer,
  &nl_7_chain,
  NULL, &conversion_8_layer, AI_STATIC, 
  .nl_params = &nl_7_nl_params, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_6_weights, &gemm_6_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_6_layer, 6,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_6_chain,
  NULL, &nl_7_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_5_weights, &gemm_5_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_5_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &gemm_5_chain,
  NULL, &gemm_6_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 4,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_sssa8_ch_nl_pool,
  &conv2d_3_chain,
  NULL, &gemm_5_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(16, 16), 
  .pool_stride = AI_SHAPE_2D_INIT(16, 16), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_ap_array_integer_INT8), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_1_scratch0, &conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 2,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_sssa8_ch_nl_pool,
  &conv2d_1_chain,
  NULL, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_integer_INT8), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_keras_tensor_90_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_0_chain,
  NULL, &conv2d_1_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1648, 1, 1),
    1648, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 8976, 1, 1),
    8976, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_BIN_IN_NUM, &serving_default_keras_tensor_90_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_BIN_OUT_NUM, &conversion_8_output),
  &conversion_0_layer, 0x2fd2006b, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 1648, 1, 1),
      1648, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 8976, 1, 1),
      8976, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_BIN_IN_NUM, &serving_default_keras_tensor_90_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_BIN_OUT_NUM, &conversion_8_output),
  &conversion_0_layer, 0x2fd2006b, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_bin_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_network_bin_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_keras_tensor_90_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 276);
    serving_default_keras_tensor_90_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 276);
    conversion_0_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 272);
    conversion_0_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 272);
    conv2d_1_scratch0_array.data = AI_PTR(g_network_bin_activations_map[0] + 3348);
    conv2d_1_scratch0_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 3348);
    conv2d_1_scratch1_array.data = AI_PTR(g_network_bin_activations_map[0] + 4000);
    conv2d_1_scratch1_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 4000);
    conv2d_1_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 0);
    conv2d_1_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 0);
    conv2d_3_scratch0_array.data = AI_PTR(g_network_bin_activations_map[0] + 2048);
    conv2d_3_scratch0_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 2048);
    conv2d_3_scratch1_array.data = AI_PTR(g_network_bin_activations_map[0] + 4864);
    conv2d_3_scratch1_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 4864);
    conv2d_3_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 8960);
    conv2d_3_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 8960);
    gemm_5_scratch0_array.data = AI_PTR(g_network_bin_activations_map[0] + 0);
    gemm_5_scratch0_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 0);
    gemm_5_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 112);
    gemm_5_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 112);
    gemm_6_scratch0_array.data = AI_PTR(g_network_bin_activations_map[0] + 0);
    gemm_6_scratch0_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 0);
    gemm_6_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 36);
    gemm_6_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 36);
    nl_7_scratch0_array.data = AI_PTR(g_network_bin_activations_map[0] + 40);
    nl_7_scratch0_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 40);
    nl_7_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 0);
    nl_7_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 0);
    conversion_8_output_array.data = AI_PTR(g_network_bin_activations_map[0] + 4);
    conversion_8_output_array.data_start = AI_PTR(g_network_bin_activations_map[0] + 4);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool network_bin_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_network_bin_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(g_network_bin_weights_map[0] + 0);
    conv2d_1_weights_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 0);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(g_network_bin_weights_map[0] + 216);
    conv2d_1_bias_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 216);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(g_network_bin_weights_map[0] + 248);
    conv2d_3_weights_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 248);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(g_network_bin_weights_map[0] + 1400);
    conv2d_3_bias_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 1400);
    gemm_5_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_5_weights_array.data = AI_PTR(g_network_bin_weights_map[0] + 1464);
    gemm_5_weights_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 1464);
    gemm_5_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_5_bias_array.data = AI_PTR(g_network_bin_weights_map[0] + 1592);
    gemm_5_bias_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 1592);
    gemm_6_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_6_weights_array.data = AI_PTR(g_network_bin_weights_map[0] + 1624);
    gemm_6_weights_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 1624);
    gemm_6_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_6_bias_array.data = AI_PTR(g_network_bin_weights_map[0] + 1640);
    gemm_6_bias_array.data_start = AI_PTR(g_network_bin_weights_map[0] + 1640);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_bin_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_BIN_MODEL_NAME,
      .model_signature   = AI_NETWORK_BIN_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 534740,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x2fd2006b,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_network_bin_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_BIN_MODEL_NAME,
      .model_signature   = AI_NETWORK_BIN_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 534740,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x2fd2006b,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_network_bin_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_network_bin_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_network_bin_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_network_bin_create(network, AI_NETWORK_BIN_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_network_bin_data_params_get(&params) != true) {
    err = ai_network_bin_get_error(*network);
    return err;
  }
#if defined(AI_NETWORK_BIN_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_NETWORK_BIN_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_network_bin_init(*network, &params) != true) {
    err = ai_network_bin_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_network_bin_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_network_bin_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_network_bin_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_network_bin_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= network_bin_configure_weights(net_ctx, params);
  ok &= network_bin_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_bin_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_network_bin_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_BIN_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

