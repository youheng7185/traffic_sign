/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
#define OV7670_QVGA_WIDTH  320
#define OV7670_QVGA_HEIGHT 240

extern uint32_t frame_buffer[OV7670_QVGA_WIDTH * OV7670_QVGA_HEIGHT/2];
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CAMERA_RESET_Pin GPIO_PIN_2
#define CAMERA_RESET_GPIO_Port GPIOE
#define cam_pwdn_Pin GPIO_PIN_3
#define cam_pwdn_GPIO_Port GPIOE
#define touch_irq_Pin GPIO_PIN_0
#define touch_irq_GPIO_Port GPIOC
#define touch_cs_Pin GPIO_PIN_3
#define touch_cs_GPIO_Port GPIOC
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOD
#define LCD_RST_Pin GPIO_PIN_5
#define LCD_RST_GPIO_Port GPIOD
#define LCD_DC_Pin GPIO_PIN_6
#define LCD_DC_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
