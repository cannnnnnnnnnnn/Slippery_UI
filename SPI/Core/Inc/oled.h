#ifndef _OLED_H
#define _OLED_H

#include "main.h"
// OLED初始化
void OLED_Init(void );

// OLED写指令
void OLED_WR_Byte_CMD(uint8_t cmd);

// OLED写数据
void OLED_WR_Byte_DATA(uint8_t cmd_data);

void OLED_ColorTurn(uint8_t i);

void OLED_DisplayTurn(uint8_t i);

void OLED_DisPlay_On(void);

void OLED_DisPlay_Off(void);

void OLED_Refresh(void);

void OLED_ShowPicture(uint8_t x,uint8_t y,uint8_t sizex,uint8_t sizey,uint8_t BMP[],uint8_t mode);

void OLED_Clear(void);

void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t num,uint8_t size1,uint8_t mode);

void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1,uint8_t mode);

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1,uint8_t mode);

void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1,uint8_t mode);

void OLED_ScrollDisplay(uint8_t num,uint8_t space,uint8_t mode);
#endif //SPI_OLED_H
