#include "oled.h"
//#include "spi.h"

//uint8_t u8x8_byte_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
//    static uint8_t buffer[32];        /* u8g2/u8x8 will never send more than 32 bytes between START_TRANSFER and END_TRANSFER */
//    static uint8_t buf_idx;
//    uint8_t *data;
//
//    switch (msg) {
//        case U8X8_MSG_BYTE_SEND:
//            data = (uint8_t *) arg_ptr;
//            while (arg_int > 0) {
//                buffer[buf_idx++] = *data;
//                data++;
//                arg_int--;
//            }
//            break;
//        case U8X8_MSG_BYTE_INIT:
//            /* add your custom code to init i2c subsystem */
//            break;
//        case U8X8_MSG_BYTE_SET_DC:
//            HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
//            break;
//        case U8X8_MSG_BYTE_START_TRANSFER:
//            buf_idx = 0;
//            break;
//        case U8X8_MSG_BYTE_END_TRANSFER:
//            if (HAL_SPI_Transmit_DMA(&hspi2, buffer, buf_idx) != HAL_OK){
//                return 0;
//            }
//            break;
//        default:
//            return 0;
//    }
//    return 1;
//}


uint8_t u8x8_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
        //Initialize SPI peripheral
        case U8X8_MSG_GPIO_AND_DELAY_INIT:
            break;
            //Function which implements a delay, arg_int contains the amount of ms
        case U8X8_MSG_DELAY_MILLI:
            HAL_Delay(arg_int);
            break;
            //Function which delays 10us
        case U8X8_MSG_DELAY_10MICRO:
//            for (int i = 0; i < 100; ++i) {
//                __NOP();
//            }
            break;
            //Function which delays 100ns
        case U8X8_MSG_DELAY_100NANO:
            __NOP();
            break;
            //Function to define the logic level of the clockline
        case U8X8_MSG_GPIO_SPI_CLOCK:
//      if(arg_int) GPIO_SetBits(PORT_LCD_SCK, PIN_LCD_SCK);
//	  else GPIO_ResetBits(PORT_LCD_SCK, PIN_LCD_SCK);
            HAL_GPIO_WritePin(OLED_CLK_GPIO_Port, OLED_CLK_Pin, arg_int);
            break;
            //Function to define the logic level of the data line to the display
        case U8X8_MSG_GPIO_SPI_DATA:
//  	  if(arg_int) GPIO_SetBits(PORT_LCD_MOSI, PIN_LCD_MOSI);
//      else GPIO_ResetBits(PORT_LCD_MOSI, PIN_LCD_MOSI);
            HAL_GPIO_WritePin(OLED_MOSI_GPIO_Port, OLED_MOSI_Pin, arg_int);
            break;
            // Function to define the logic level of the CS line
        case U8X8_MSG_GPIO_CS:
//	  if(arg_int) GPIO_SetBits(PORT_LCD_CS ,PIN_LCD_CS);
//	  else GPIO_ResetBits(PORT_LCD_CS, PIN_LCD_CS);
            HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, arg_int);
            break;
            //Function to define the logic level of the Data/ Command line
        case U8X8_MSG_GPIO_DC:
//	  if(arg_int) GPIO_SetBits(PORT_LCD_RS,PIN_LCD_RS);
//	  else GPIO_ResetBits(PORT_LCD_RS,PIN_LCD_RS);
            HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, arg_int);
            break;
            //Function to define the logic level of the RESET line
        case U8X8_MSG_GPIO_RESET:
            //   if(arg_int) GPIO_SetBits(PORT_LCD_RST,PIN_LCD_RST);
            //   else GPIO_ResetBits(PORT_LCD_RST,PIN_LCD_RST);
            HAL_GPIO_WritePin(OLED_RES_GPIO_Port, OLED_RES_Pin, arg_int);
            break;
        default:
            return 0; //A message was received which is not implemented, return 0 to indicate an error
    }
    return 1; // command processed successfully.
}


// 初始化参数设置
void u8g2Init(u8g2_t *u8g2) {
    u8g2_Setup_ssd1306_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8x8_gpio_and_delay); // 初始化 u8g2 结构体
    u8g2_InitDisplay(u8g2);        // 根据所选的芯片进行初始化工作，初始化完成后，显示器处于关闭状态
    u8g2_SetPowerSave(u8g2, 0);    // 打开显示器

//    u8g2_SetContrast(&u8g2, 100);  //设置对比度
    u8g2_ClearBuffer(u8g2);
}

/*官方提供的Logo绘制demo*/
void draw(u8g2_t *u8g2) {
    u8g2_SetFontMode(u8g2, 1); /*字体模式选择*/
    u8g2_SetFontDirection(u8g2, 0); /*字体方向选择*/
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf); /*字库选择*/
    u8g2_DrawStr(u8g2, 0, 20, "U");

    u8g2_SetFontDirection(u8g2, 1);
    u8g2_SetFont(u8g2, u8g2_font_inb30_mn);
    u8g2_DrawStr(u8g2, 21, 8, "8");

    u8g2_SetFontDirection(u8g2, 0);
    u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
    u8g2_DrawStr(u8g2, 51, 30, "g");
    u8g2_DrawStr(u8g2, 67, 30, "\xb2");

    u8g2_DrawHLine(u8g2, 2, 35, 47);
    u8g2_DrawHLine(u8g2, 3, 36, 47);
    u8g2_DrawVLine(u8g2, 45, 32, 12);
    u8g2_DrawVLine(u8g2, 46, 33, 12);

    u8g2_SetFont(u8g2, u8g2_font_4x6_tr);
    u8g2_DrawStr(u8g2, 1, 54, "github.com/olikraus/u8g2");
}
