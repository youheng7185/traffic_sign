/*
 * nn_process_bin.c
 *
 *  Created on: Jun 11, 2025
 *      Author: lapchong
 */

#include "main.h"
#include "nn_process_bin.h"
#include "network_bin.h"
#include "network_bin_config.h"
#include "network_bin_data.h"
#include "network_bin_data_params.h"
#include "nn_process.h"

static ai_handle network = AI_HANDLE_NULL;
static ai_buffer ai_input[AI_NETWORK_BIN_IN_NUM];
static ai_buffer ai_output[AI_NETWORK_BIN_OUT_NUM];

AI_ALIGNED(AI_NETWORK_BIN_ACTIVATIONS_ALIGNMENT)
static ai_u8 activations[AI_NETWORK_BIN_DATA_ACTIVATIONS_SIZE];

AI_ALIGNED(AI_NETWORK_BIN_INPUTS_IN_ACTIVATIONS)
static ai_u8 in_data[AI_NETWORK_BIN_IN_1_SIZE];

AI_ALIGNED(AI_NETWORK_BIN_OUTPUTS_IN_ACTIVATIONS)
static ai_u8 out_data[AI_NETWORK_BIN_OUT_1_SIZE];


int aiBinInit(void) {
	ai_error err;

	const ai_handle acts_addr[] = { activations };
	err = ai_network_bin_create_and_init(&network, acts_addr, NULL);

	if (err.type != AI_ERROR_NONE)
	{
		while(1);
	}

    // Copy model input/output tensor descriptors, then attach your buffers
    const ai_buffer *ai_input_desc = ai_network_bin_inputs_get(network, NULL);
    const ai_buffer *ai_output_desc = ai_network_bin_outputs_get(network, NULL);

    // Copy descriptor and attach input buffer
    ai_input[0] = ai_input_desc[0];
    ai_input[0].data = AI_HANDLE_PTR(in_data);

    // Copy descriptor and attach output buffer
    ai_output[0] = ai_output_desc[0];
    ai_output[0].data = AI_HANDLE_PTR(out_data);

	return 0;
}

int aiBinRun(void) {
	memcpy(in_data, shared_buffer, 3072);

	ai_i32 n_batch;

	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	SCB_CleanDCache_by_Addr((uint32_t*)in_data, sizeof(in_data));

	n_batch = ai_network_bin_run(network, &ai_input[0], &ai_output[0]);
	if (n_batch != 1) {
		ai_error err;
		err = ai_network_bin_get_error(network);
		while(1);
	}

	return 0;
}
