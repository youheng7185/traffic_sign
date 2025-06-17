/*
 * nn_process.h
 *
 *  Created on: Jun 10, 2025
 *      Author: lapchong
 */

#ifndef INC_NN_PROCESS_H_
#define INC_NN_PROCESS_H_

extern uint8_t shared_buffer[3072];

int aiInit(void);
int aiRun(void);
void print_result();
void convert_framebuffer_to_input_correct(const uint32_t *frame_buffer, uint8_t *in_data);

#endif /* INC_NN_PROCESS_H_ */
