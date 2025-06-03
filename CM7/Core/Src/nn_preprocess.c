/*
 * nn_preprocess.c
 *
 *  Created on: Jun 3, 2025
 *      Author: lapchong
 */

#include "nn_preprocess.h"
#include "stm32h7xx_hal.h"
#include "main.h"
#include "st7789.h"

#define SRC_WIDTH  320
#define SRC_HEIGHT 240
#define CROP_SIZE  240
#define DST_SIZE   192

uint8_t frame_to_feed[DST_SIZE * DST_SIZE * 3];

void pre_process_copy_buffer()
{
	// Crop origin: centered 240x240
	int crop_x = (SRC_WIDTH - CROP_SIZE) / 2;  // 40
	int crop_y = (SRC_HEIGHT - CROP_SIZE) / 2; // 0

	// Scale factor
	float scale = (float)CROP_SIZE / DST_SIZE;
	for (int y = 0; y < DST_SIZE; y++) {
		for (int x = 0; x < DST_SIZE; x++) {
			// Nearest neighbor source coordinates
			int src_x = crop_x + (int)(x * scale);
			int src_y = crop_y + (int)(y * scale);
			int pixel_index = src_y * SRC_WIDTH + src_x;

			// Extract RGB565 from packed source[]
			uint32_t word = frame_buffer[pixel_index / 2];
			uint16_t pixel565 = (pixel_index % 2 == 0) ?
				(word & 0xFFFF) :
				((word >> 16) & 0xFFFF);

			// Convert to RGB888
			uint8_t r = ((pixel565 >> 11) & 0x1F) << 3;
			uint8_t g = ((pixel565 >> 5) & 0x3F) << 2;
			uint8_t b = (pixel565 & 0x1F) << 3;

			// Store in target buffer
			int dst_index = (y * DST_SIZE + x) * 3;
			frame_to_feed[dst_index + 0] = r;
			frame_to_feed[dst_index + 1] = g;
			frame_to_feed[dst_index + 2] = b;
		}
	}
}

uint16_t rgb565_buffer[DST_SIZE * DST_SIZE]; // RGB565 version for LCD

void display_192x192_frame()
{
	// Convert RGB888 to RGB565
	for (int i = 0; i < DST_SIZE * DST_SIZE; i++) {
	    uint8_t r = frame_to_feed[i * 3 + 0];
	    uint8_t g = frame_to_feed[i * 3 + 1];
	    uint8_t b = frame_to_feed[i * 3 + 2];

	    // Pack into RGB565: 5 bits R, 6 bits G, 5 bits B
	    uint16_t rgb565 = ((r & 0xF8) << 8) |
	                       ((g & 0xFC) << 3) |
	                       ((b & 0xF8) >> 3);

	    rgb565_buffer[i] = (rgb565 >> 8) | (rgb565 << 8);
	}

	// Now draw to LCD
	ST7789_DrawImage(0, 0, DST_SIZE, DST_SIZE, rgb565_buffer);
}
