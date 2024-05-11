//
// Created by Maxwell on 2024-04-28.
//

#include "Led.h"




void r1_on()
{
    HAL_GPIO_WritePin(r1_GPIO_Port, r1_Pin, GPIO_PIN_RESET);
}
void g1_on()
{
    HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_RESET);
}
void y1_on()
{
    HAL_GPIO_WritePin(y1_GPIO_Port, y1_Pin, GPIO_PIN_RESET);
}
void r1_off()
{
    HAL_GPIO_WritePin(r1_GPIO_Port, r1_Pin, GPIO_PIN_SET);
}
void g1_off()
{
    HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, GPIO_PIN_SET);
}
void y1_off()
{
    HAL_GPIO_WritePin(y1_GPIO_Port, y1_Pin, GPIO_PIN_SET);
}
//*********************************************************************************
void r2_on()
{
    HAL_GPIO_WritePin(r2_GPIO_Port, r2_Pin, GPIO_PIN_RESET);
}
void g2_on()
{
    HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_RESET);
}
void y2_on()
{
    HAL_GPIO_WritePin(y2_GPIO_Port, y2_Pin, GPIO_PIN_RESET);
}
void r2_off()
{
    HAL_GPIO_WritePin(r2_GPIO_Port, r2_Pin, GPIO_PIN_SET);
}
void g2_off()
{
    HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, GPIO_PIN_SET);
}
void y2_off()
{
    HAL_GPIO_WritePin(y2_GPIO_Port, y2_Pin, GPIO_PIN_SET);
}
//*********************************************************************************
void r3_on()
{
    HAL_GPIO_WritePin(r3_GPIO_Port, r3_Pin, GPIO_PIN_RESET);
}
void g3_on()
{
    HAL_GPIO_WritePin(g3_GPIO_Port, g3_Pin, GPIO_PIN_RESET);
}
void y3_on()
{
    HAL_GPIO_WritePin(y3_GPIO_Port, y3_Pin, GPIO_PIN_RESET);
}
void r3_off()
{
    HAL_GPIO_WritePin(r3_GPIO_Port, r3_Pin, GPIO_PIN_SET);
}
void g3_off()
{
    HAL_GPIO_WritePin(g3_GPIO_Port, g3_Pin, GPIO_PIN_SET);
}
void y3_off()
{
    HAL_GPIO_WritePin(y3_GPIO_Port, y3_Pin, GPIO_PIN_SET);
}
//*********************************************************************************
void r4_on()
{
    HAL_GPIO_WritePin(r4_GPIO_Port, r4_Pin, GPIO_PIN_RESET);
}
void g4_on()
{
    HAL_GPIO_WritePin(g4_GPIO_Port, g4_Pin, GPIO_PIN_RESET);
}
void y4_on()
{
    HAL_GPIO_WritePin(y4_GPIO_Port, y4_Pin, GPIO_PIN_RESET);
}
void r4_off()
{
    HAL_GPIO_WritePin(r4_GPIO_Port, r4_Pin, GPIO_PIN_SET);
}
void g4_off()
{
    HAL_GPIO_WritePin(g4_GPIO_Port, g4_Pin, GPIO_PIN_SET);
}
void y4_off()
{
    HAL_GPIO_WritePin(y4_GPIO_Port, y4_Pin, GPIO_PIN_SET);
}

