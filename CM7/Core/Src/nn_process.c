/*
 * nn_process.c
 *
 *  Created on: Jun 10, 2025
 *      Author: lapchong
 */

#include "network.h"
#include "network_data.h"
#include "network_data_params.h"
#include "main.h"

static ai_handle network = AI_HANDLE_NULL;
static ai_buffer *ai_input;
static ai_buffer *ai_output;

AI_ALIGNED(32)
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
AI_ALIGNED(32)
static ai_u8 in_data[AI_NETWORK_IN_1_SIZE];
AI_ALIGNED(32)
static ai_u8 out_data[AI_NETWORK_OUT_1_SIZE];

// func prototype for preprocess
void convert_framebuffer_to_input(uint8_t in_data[AI_NETWORK_IN_1_SIZE]);

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

int aiRun(void) {
	convert_framebuffer_to_input(in_data);

	ai_i32 n_batch;

	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	n_batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
	if (n_batch != 1) {
		ai_error err;
		err = ai_network_get_error(network);
		while(1);
	}
	return 0;
}

#define OV7670_QVGA_WIDTH   320
#define OV7670_QVGA_HEIGHT  240

#define INPUT_WIDTH   32
#define INPUT_HEIGHT  32
#define INPUT_CHANNELS 3

#define CROP_X_OFFSET ((OV7670_QVGA_WIDTH - 240) / 2)  // 40
#define CROP_Y_OFFSET 0

static inline void rgb565_to_rgb888(uint16_t rgb565, uint8_t* r, uint8_t* g, uint8_t* b) {
    *r = ((rgb565 >> 11) & 0x1F) << 3;
    *g = ((rgb565 >> 5) & 0x3F) << 2;
    *b = (rgb565 & 0x1F) << 3;
    *r |= *r >> 5;  // Fill lower bits
    *g |= *g >> 6;
    *b |= *b >> 5;
}

void convert_framebuffer_to_input(uint8_t in_data[AI_NETWORK_IN_1_SIZE]) {
    const int scale_x = 240 / INPUT_WIDTH;   // 7
    const int scale_y = 240 / INPUT_HEIGHT;  // 7

    for (int y = 0; y < INPUT_HEIGHT; ++y) {
        for (int x = 0; x < INPUT_WIDTH; ++x) {
            int src_x = CROP_X_OFFSET + x * scale_x;
            int src_y = CROP_Y_OFFSET + y * scale_y;
            int pixel_index = src_y * OV7670_QVGA_WIDTH + src_x;
            int word_index = pixel_index / 2;
            int is_even = (pixel_index % 2 == 0);

            uint32_t word = frame_buffer[word_index];
            uint16_t rgb565 = is_even ? (word & 0xFFFF) : (word >> 16);

            uint8_t r, g, b;
            rgb565_to_rgb888(rgb565, &r, &g, &b);

            int dst_index = (y * INPUT_WIDTH + x) * 3;
            in_data[dst_index + 0] = r;
            in_data[dst_index + 1] = g;
            in_data[dst_index + 2] = b;
        }
    }
}
