/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Led.h"
#include "string.h"
//#include "Uart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

// 定义数码管位选引�?????????????????????



/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t dispaly_val;
const uint16_t digit_codes[] = {
        0x003F, 0x0006, 0x005B, 0x004F, 0x0066, 0x006D, 0x007D, 0x0007, 0x007F, 0x006F,
        0x0000};
uint8_t digbuf[] = {
        11,11,11,11,11,11,11,11
};
uint8_t digcom=0;
uint16_t countdown_value = 20;
uint16_t counter = 0;

uint16_t uart_counter=0;
uint8_t rx_data[1]={0};

uint16_t init_total_cycle=60;
uint16_t init_red_time=30;
uint16_t init_green_time=25;
uint16_t init_yellow_time=5;


typedef struct {

    uint16_t red_time;          // 红灯时间，单位根据实际需求设定（如秒�????????????
    uint16_t green_time;        // 绿灯时间，单位同�????????????
    uint16_t yellow_time;       // 黄灯时间，单位同�????????????
    uint16_t total_cycle;       // 总周期，即一个完整的红绿黄灯循环时间
    uint8_t light_state;        // 0:红灯�????????????1:绿灯�????????????2:黄灯

    uint16_t display_time;
} traffic_light;
traffic_light trafficLight_1;


traffic_light trafficLight_2;


traffic_light trafficLight_3;


traffic_light trafficLight_4;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void trafficLight_init()
{
    trafficLight_1.total_cycle=init_total_cycle;
    trafficLight_2.total_cycle=init_total_cycle;
    trafficLight_3.total_cycle=init_total_cycle;
    trafficLight_4.total_cycle=init_total_cycle;

    trafficLight_1.red_time=init_red_time;
    trafficLight_2.red_time=init_red_time;
    trafficLight_3.red_time=init_red_time;
    trafficLight_4.red_time=init_red_time;

    trafficLight_1.green_time=init_green_time;
    trafficLight_2.green_time=init_green_time;
    trafficLight_3.green_time=init_green_time;
    trafficLight_4.green_time=init_green_time;

    trafficLight_1.yellow_time=init_yellow_time;
    trafficLight_2.yellow_time=init_yellow_time;
    trafficLight_3.yellow_time=init_yellow_time;
    trafficLight_4.yellow_time=init_yellow_time;

    trafficLight_1.light_state=0;
    trafficLight_2.light_state=0;
    trafficLight_3.light_state=1;
    trafficLight_4.light_state=1;

}

void seg_display()
{
    digbuf[0]=trafficLight_1.display_time/10;
    digbuf[1]=trafficLight_1.display_time%10;

    digbuf[2]=trafficLight_2.display_time/10;;
    digbuf[3]=trafficLight_2.display_time%10;;

    digbuf[4]=trafficLight_3.display_time/10;
    digbuf[5]=trafficLight_3.display_time%10;

    digbuf[6]=trafficLight_4.display_time/10;
    digbuf[7]=trafficLight_4.display_time%10;

}
void trafficLight_control()
{
    switch (trafficLight_1.light_state) {
        case 0:
            r1_on();
            g1_off();
            y1_off();
            break;
        case 1:
            r1_off();
            g1_on();
            y1_off();
            break;
        case 2:
            r1_off();
            g1_off();
            y1_on();
            break;

        default:
            break;
    }
    switch (trafficLight_2.light_state) {
        case 0:
            r2_on();
            g2_off();
            y2_off();
            break;
        case 1:
            r2_off();
            g2_on();
            y2_off();
            break;
        case 2:
            r2_off();
            g2_off();
            y2_on();
            break;

        default:
            break;
    }

    switch (trafficLight_3.light_state) {
        case 0:
            r3_on();
            g3_off();
            y3_off();
            break;
        case 1:
            r3_off();
            g3_on();
            y3_off();
            break;
        case 2:
            r3_off();
            g3_off();
            y3_on();
            break;

        default:
            break;
    }

    switch (trafficLight_4.light_state) {
        case 0:
            r4_on();
            g4_off();
            y4_off();
            break;
        case 1:
            r4_off();
            g4_on();
            y4_off();
            break;
        case 2:
            r4_off();
            g4_off();
            y4_on();
            break;

        default:
            break;
    }

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
    trafficLight_init();

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
    HAL_TIM_Base_Start_IT(&htim2);

    HAL_TIM_Base_Start_IT(&htim3);
    HAL_TIM_Base_Start_IT(&htim4);


    HAL_UART_Receive_IT(&huart1, rx_data, 1);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    while (1)
    {
        seg_display();
        trafficLight_control();





    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart)
{
    if (huart->Instance==USART1)
    {
        HAL_UART_Receive_IT(&huart1, rx_data, 1);
        switch (rx_data[0]) {
            case '1':
                HAL_UART_Transmit_IT(&huart1,"okok111111111111\r\n",sizeof("okok111111111111\r\n"));
                break;
            default:
                HAL_UART_Transmit_IT(&huart1,"okok\r\n",sizeof("okok\r\n"));
                break;
        }
    }
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance==TIM2)
    {
        if (uart_counter++==500)
        {
            //HAL_UART_Transmit(&huart1,"okok\r\n",sizeof("okok\r\n"),10000);
            uart_counter=0;
        }
    }


    if(htim->Instance==TIM3)
    {
        GPIOA->ODR=~(0x0001<<digcom);
        GPIOB->ODR=digit_codes[digbuf[digcom]]<<8;
        if (++digcom==8) {
            digcom = 0;
        }
    }
    if(htim->Instance==TIM4)
    {
        if(counter++==1000)
        {

            // 根据交�?�灯1的当前状态，更新其显示时间和状�?�，并�?�减对应颜色的显示时�????????????
            switch (trafficLight_1.light_state) {
                case 0: // 红灯状�??
                    trafficLight_1.display_time=trafficLight_1.red_time; // 设置当前显示时间为红灯时�????????????
                    trafficLight_1.red_time--; // 红灯时间递减
                    if(trafficLight_1.red_time==0) // 当红灯时间用完后
                    {
                        trafficLight_1.light_state=1; // 更改状�?�为绿灯
                        trafficLight_1.red_time=init_red_time; // 重置红灯时间
                    }
                    break;
                case 1: // 绿灯状�??
                    trafficLight_1.display_time=trafficLight_1.green_time; // 设置当前显示时间为绿灯时�????????????
                    trafficLight_1.green_time--; // 绿灯时间递减
                    if(trafficLight_1.green_time==0) // 当绿灯时间用完后
                    {
                        trafficLight_1.light_state=2; // 更改状�?�为黄灯
                        trafficLight_1.green_time=init_green_time; // 重置绿灯时间
                    }
                    break;
                case 2: // 黄灯状�??
                    trafficLight_1.display_time=trafficLight_1.yellow_time; // 设置当前显示时间为黄灯时�????????????
                    trafficLight_1.yellow_time--; // 黄灯时间递减
                    if(trafficLight_1.yellow_time==0) // 当黄灯时间用完后
                    {
                        trafficLight_1.light_state=0; // 更改状�?�为红灯
                        trafficLight_1.yellow_time=init_yellow_time; // 重置黄灯时间
                    }
                    break;
            }
            // 根据交�?�灯2的当前状态，更新其显示时间和状�?�，并�?�减对应颜色的显示时�????????????
            switch (trafficLight_2.light_state) {
                case 0: // 红灯状�??
                    trafficLight_2.display_time=trafficLight_2.red_time; // 设置当前显示时间为红灯时�????????????
                    trafficLight_2.red_time--; // 红灯时间递减
                    if(trafficLight_2.red_time==0) // 当红灯时间用完后
                    {
                        trafficLight_2.light_state=1; // 更改状�?�为绿灯
                        trafficLight_2.red_time=init_red_time; // 重置红灯时间
                    }
                    break;
                case 1: // 绿灯状�??
                    trafficLight_2.display_time=trafficLight_2.green_time; // 设置当前显示时间为绿灯时�????????????
                    trafficLight_2.green_time--; // 绿灯时间递减
                    if(trafficLight_2.green_time==0) // 当绿灯时间用完后
                    {
                        trafficLight_2.light_state=2; // 更改状�?�为黄灯
                        trafficLight_2.green_time=init_green_time; // 重置绿灯时间
                    }
                    break;
                case 2: // 黄灯状�??
                    trafficLight_2.display_time=trafficLight_2.yellow_time; // 设置当前显示时间为黄灯时�????????????
                    trafficLight_2.yellow_time--; // 黄灯时间递减
                    if(trafficLight_2.yellow_time==0) // 当黄灯时间用完后
                    {
                        trafficLight_2.light_state=0; // 更改状�?�为红灯
                        trafficLight_2.yellow_time=init_yellow_time; // 重置黄灯时间
                    }
                    break;
            }
            // 根据交�?�灯3的当前状态，更新其显示时间和状�?�，并�?�减对应颜色的显示时�????????????
            switch (trafficLight_3.light_state) {
                case 0: // 红灯状�??
                    trafficLight_3.display_time=trafficLight_3.red_time; // 设置当前显示时间为红灯时�????????????
                    trafficLight_3.red_time--; // 红灯时间递减
                    if(trafficLight_3.red_time==0) // 当红灯时间用完后
                    {
                        trafficLight_3.light_state=1; // 更改状�?�为绿灯
                        trafficLight_3.red_time=init_red_time; // 重置红灯时间
                    }
                    break;
                case 1: // 绿灯状�??
                    trafficLight_3.display_time=trafficLight_3.green_time; // 设置当前显示时间为绿灯时�????????????
                    trafficLight_3.green_time--; // 绿灯时间递减
                    if(trafficLight_3.green_time==0) // 当绿灯时间用完后
                    {
                        trafficLight_3.light_state=2; // 更改状�?�为黄灯
                        trafficLight_3.green_time=init_green_time; // 重置绿灯时间
                    }
                    break;
                case 2: // 黄灯状�??
                    trafficLight_3.display_time=trafficLight_3.yellow_time; // 设置当前显示时间为黄灯时�????????????
                    trafficLight_3.yellow_time--; // 黄灯时间递减
                    if(trafficLight_3.yellow_time==0) // 当黄灯时间用完后
                    {
                        trafficLight_3.light_state=0; // 更改状�?�为红灯
                        trafficLight_3.yellow_time=init_yellow_time; // 重置黄灯时间
                    }
                    break;
            }
            // 根据交�?�灯4的当前状态，更新其显示时间和状�?�，并�?�减对应颜色的显示时�????????????
            switch (trafficLight_4.light_state) {
                case 0: // 红灯状�??
                    trafficLight_4.display_time=trafficLight_4.red_time; // 设置当前显示时间为红灯时�????????????
                    trafficLight_4.red_time--; // 红灯时间递减
                    
                    if(trafficLight_4.red_time==0) // 当红灯时间用完后
                    {
                        trafficLight_4.light_state=1; // 更改状�?�为绿灯
                        trafficLight_4.red_time=init_red_time; // 重置红灯时间
                    }
                    break;
                case 1: // 绿灯状�??
                    trafficLight_4.display_time=trafficLight_4.green_time; // 设置当前显示时间为绿灯时�????????????
                    trafficLight_4.green_time--; // 绿灯时间递减
                    if(trafficLight_4.green_time==0) // 当绿灯时间用完后
                    {
                        trafficLight_4.light_state=2; // 更改状�?�为黄灯
                        trafficLight_4.green_time=init_green_time; // 重置绿灯时间
                    }
                    break;
                case 2: // 黄灯状�??
                    trafficLight_4.display_time=trafficLight_4.yellow_time; // 设置当前显示时间为黄灯时�????????????
                    trafficLight_4.yellow_time--; // 黄灯时间递减
                    if(trafficLight_4.yellow_time==0) // 当黄灯时间用完后
                    {
                        trafficLight_4.light_state=0; // 更改状�?�为红灯
                        trafficLight_4.yellow_time=init_yellow_time; // 重置黄灯时间
                    }
                    break;
            }



            counter=0;
        }
    }

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
