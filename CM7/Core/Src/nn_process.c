/*
 * nn_process.c
 *
 *  Created on: Jun 10, 2025
 *      Author: lapchong
 */

#include "network.h"
#include "network_data.h"
#include "network_data_params.h"

static ai_handle network = AI_HANDLE_NULL;
static ai_buffer *ai_input;
static ai_buffer *ai_output;

AI_ALIGNED(32)
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
AI_ALIGNED(32)
static ai_u8 in_data[AI_NETWORK_IN_1_SIZE];
AI_ALIGNED(32)
static ai_u8 out_data[AI_NETWORK_OUT_1_SIZE];

int aiInit(void) {
	ai_error err;

	const ai_handle acts[] = { activations };
	err = ai_network_create_and_init(&network, acts, NULL);

	if (err.type != AI_ERROR_NONE)
	{
		while(1);
	}

	ai_input = ai_network_inputs_get(network, NULL);
	ai_output = ai_network_outputs_get(network, NULL);

	return 0;
}
