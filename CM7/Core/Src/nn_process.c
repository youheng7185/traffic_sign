/*
 * nn_process.c
 *
 *  Created on: Jun 10, 2025
 *      Author: lapchong
 */

#include "network.h"
#include "network_data.h"
#include "network_data_params.h"
#include "network_config.h"
#include "main.h"
#include "st7789.h"
#include <stdio.h>
#include <stdbool.h>

static ai_handle network = AI_HANDLE_NULL;
static ai_buffer ai_input[AI_NETWORK_IN_NUM];
static ai_buffer ai_output[AI_NETWORK_OUT_NUM];

AI_ALIGNED(32)
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];
AI_ALIGNED(32)
static ai_u8 in_data[AI_NETWORK_IN_1_SIZE];
AI_ALIGNED(32)
static ai_u8 out_data[AI_NETWORK_OUT_1_SIZE];

// func prototype for preprocess
void convert_framebuffer_to_input(uint8_t in_data[AI_NETWORK_IN_1_SIZE]);
void convert_framebuffer_to_input_correct(uint8_t *in_data);

int aiInit(void) {
	ai_error err;

	const ai_handle acts_addr[] = { activations };
	err = ai_network_create_and_init(&network, acts_addr, NULL);

	if (err.type != AI_ERROR_NONE)
	{
		while(1);
	}

    // Copy model input/output tensor descriptors, then attach your buffers
    const ai_buffer *ai_input_desc = ai_network_inputs_get(network, NULL);
    const ai_buffer *ai_output_desc = ai_network_outputs_get(network, NULL);

    // Copy descriptor and attach input buffer
    ai_input[0] = ai_input_desc[0];
    ai_input[0].data = AI_HANDLE_PTR(in_data);

    // Copy descriptor and attach output buffer
    ai_output[0] = ai_output_desc[0];
    ai_output[0].data = AI_HANDLE_PTR(out_data);

	return 0;
}

int aiRun(void) {
	convert_framebuffer_to_input_correct(in_data);

	ai_i32 n_batch;

	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);

	SCB_CleanDCache_by_Addr((uint32_t*)in_data, sizeof(in_data));

	n_batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
	if (n_batch != 1) {
		ai_error err;
		err = ai_network_get_error(network);
		while(1);
	}

	//SCB_InvalidateDCache_by_Addr((uint32_t*)out_data, sizeof(out_data));

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
    *r |= *r >> 5; // Fill lower bits
    *g |= *g >> 6;
    *b |= *b >> 5;
}

void convert_framebuffer_to_input(uint8_t *in_data) {
    const int scale_x = 240 / INPUT_WIDTH; // 7
    const int scale_y = 240 / INPUT_HEIGHT; // 7

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

void convert_framebuffer_to_input_correct(uint8_t *in_data) {
    const int scale_x = 240 / INPUT_WIDTH; // 7
    const int scale_y = 240 / INPUT_HEIGHT; // 7

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
            // Keep RGB order and 0-255 range as per your training
            in_data[dst_index + 0] = r;  // Red
            in_data[dst_index + 1] = g;  // Green
            in_data[dst_index + 2] = b;  // Blue
        }
    }
}

const char* gtsrb_labels[43] = {
    "Speed limit (20km/h)", "Speed limit (30km/h)", "Speed limit (50km/h)", "Speed limit (60km/h)",
    "Speed limit (70km/h)", "Speed limit (80km/h)", "End of speed limit (80km/h)", "Speed limit (100km/h)",
    "Speed limit (120km/h)", "No passing", "No passing for vehicles over 3.5 metric tons", "Right-of-way at the next intersection",
    "Priority road", "Yield", "Stop", "No vehicles", "Vehicles over 3.5 metric tons prohibited", "No entry",
    "General caution", "Dangerous curve to the left", "Dangerous curve to the right", "Double curve",
    "Bumpy road", "Slippery road", "Road narrows on the right", "Road work", "Traffic signals", "Pedestrians",
    "Children crossing", "Bicycles crossing", "Beware of ice/snow", "Wild animals crossing", "End of all speed and passing limits",
    "Turn right ahead", "Turn left ahead", "Ahead only", "Go straight or right", "Go straight or left",
    "Keep right", "Keep left", "Roundabout mandatory", "End of no passing", "End of no passing by vehicles over 3.5 metric tons"
};

void print_result()
{
    static int last_index = -2;  // -2 = uninitialized, -1 = "nothing"
    static int repeat_count = 0;

    bool if_found = false;
    int max_index = -1;
    uint8_t max_value = 0;

    // Find the class with the highest score over 200
    for (uint8_t i = 0; i < 43; i++)
    {
        if (out_data[i] > max_value)
        {
            max_value = out_data[i];
            max_index = i;
        }
    }

    char debug[70];

    if (max_value > 200)
    {
        if (max_index == last_index)
        {
            repeat_count++;
        }
        else
        {
            last_index = max_index;
            repeat_count = 1;
        }

        if (repeat_count >= 3)
        {
            sprintf(debug, "sign: %s (%d)", gtsrb_labels[max_index], max_value);
            ST7789_WriteString(0, 215, debug, Font_11x18, 0x0000, 0xFFFF);
        }
    }
    else // nothing detected
    {
        if (last_index == -1)
        {
            repeat_count++;
        }
        else
        {
            last_index = -1;
            repeat_count = 1;
        }

        if (repeat_count >= 3)
        {
            sprintf(debug, "nothing                       ");
            ST7789_WriteString(0, 215, debug, Font_11x18, 0x0000, 0xFFFF);
        }
    }
}
