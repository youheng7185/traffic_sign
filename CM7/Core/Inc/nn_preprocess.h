/*
 * nn_preprocess.h
 *
 *  Created on: Jun 3, 2025
 *      Author: lapchong
 */

#ifndef INC_NN_PREPROCESS_H_
#define INC_NN_PREPROCESS_H_

#include <stdint.h>

#define DST_SIZE   192

extern uint8_t frame_to_feed[DST_SIZE * DST_SIZE * 3];

void pre_process_copy_buffer();
void display_192x192_frame();

#endif /* INC_NN_PREPROCESS_H_ */
