#ifndef _OLED_H
#define _OLED_H

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

#include "main.h"
// OLED初始化
void OLED_Init(void );

// OLED写指令
void OLED_WR_Byte_CMD(uint8_t cmd);

// OLED写数据
void OLED_WR_Byte_DATA(uint8_t cmd_data);

void OLED_ColorTurn(u8 i);

void OLED_DisplayTurn(u8 i);

void OLED_DisPlay_On(void);

void OLED_DisPlay_Off(void);

void OLED_Refresh(void);

void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);

void OLED_Clear(void);

void OLED_ShowChinese(u8 x,u8 y,u8 num,u8 size1,u8 mode);

void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 size1,u8 mode);

void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);

void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size1,u8 mode);

void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
#endif //SPI_OLED_H
