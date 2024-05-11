/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define y3_Pin GPIO_PIN_13
#define y3_GPIO_Port GPIOC
#define g3_Pin GPIO_PIN_14
#define g3_GPIO_Port GPIOC
#define r3_Pin GPIO_PIN_15
#define r3_GPIO_Port GPIOC
#define Uart_led_Pin GPIO_PIN_1
#define Uart_led_GPIO_Port GPIOB
#define r1_Pin GPIO_PIN_8
#define r1_GPIO_Port GPIOA
#define g1_Pin GPIO_PIN_11
#define g1_GPIO_Port GPIOA
#define y1_Pin GPIO_PIN_12
#define y1_GPIO_Port GPIOA
#define r4_Pin GPIO_PIN_15
#define r4_GPIO_Port GPIOA
#define g4_Pin GPIO_PIN_3
#define g4_GPIO_Port GPIOB
#define y4_Pin GPIO_PIN_4
#define y4_GPIO_Port GPIOB
#define r2_Pin GPIO_PIN_5
#define r2_GPIO_Port GPIOB
#define g2_Pin GPIO_PIN_6
#define g2_GPIO_Port GPIOB
#define y2_Pin GPIO_PIN_7
#define y2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
