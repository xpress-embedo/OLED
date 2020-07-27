/*
 * @file OLED.h
 * @author xpress_embedo
 * @date 2 Feb, 2020
 * 
 * @brief This file contains OLED drivers for SSD1306 Controller
 *
 */

#ifndef OLED_H
#define	OLED_H

#include "main.h"
#include "I2C.h"

#ifdef	__cplusplus
extern "C"
{
#endif

extern const uint8_t SMALL_FONTS[];
extern const uint8_t TINY_FONTS[];
extern const uint8_t BIG_FONTS[];

typedef struct _Current_Font_s
{
  const uint8_t *font;        // Fonts Stored are Const
  uint8_t x_size;
  uint8_t y_size;
  uint8_t offset;
  uint8_t numchars;
  uint8_t inverted;
} Current_Font_s;

#define LEFT                  0
#define RIGHT                 254
#define CENTER                255

#define BLACK                 0
#define WHITE                 1
#define INVERSE               2

//#define SSD1306_ADDR        0x3D
#define SSD1306_ADDR          0x3C

/* SSD1306 Display Type*/
#define SSD1306_128_64
// #define SSD1306_128_32
// #define SSD1306_96_16

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 64
#endif
#if defined SSD1306_128_32
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 32
#endif
#if defined SSD1306_96_16
  #define SSD1306_LCDWIDTH                  96
  #define SSD1306_LCDHEIGHT                 16
#endif

#define SSD1306_COMMAND                     0x00
#define SSD1306_DATA                        0xC0
#define SSD1306_DATA_CONTINUE               0x40

/* SSD1306 Command Set*/
// Fundamental Commands
#define SSD1306_SET_CONTRAST_CONTROL                    0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME                   0xA4
#define SSD1306_DISPLAY_ALL_ON                          0xA5
#define SSD1306_NORMAL_DISPLAY                          0xA6
#define SSD1306_INVERT_DISPLAY                          0xA7
#define SSD1306_DISPLAY_OFF                             0xAE
#define SSD1306_DISPLAY_ON                              0xAF
#define SSD1306_NOP                                     0xE3
// Scrolling Commands
#define SSD1306_HORIZONTAL_SCROLL_RIGHT                 0x26
#define SSD1306_HORIZONTAL_SCROLL_LEFT                  0x27
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT    0x29
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT     0x2A
#define SSD1306_DEACTIVATE_SCROLL                       0x2E
#define SSD1306_ACTIVATE_SCROLL                         0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA                0xA3
// Addressing Setting Commands
#define SSD1306_SET_LOWER_COLUMN                        0x00
#define SSD1306_SET_HIGHER_COLUMN                       0x10
#define SSD1306_MEMORY_ADDR_MODE                        0x20
#define SSD1306_SET_COLUMN_ADDR                         0x21
#define SSD1306_SET_PAGE_ADDR                           0x22
// Hardware Configuration Commands
#define SSD1306_SET_START_LINE                          0x40
#define SSD1306_SET_SEGMENT_REMAP                       0xA0
#define SSD1306_SET_MULTIPLEX_RATIO                     0xA8
#define SSD1306_COM_SCAN_DIR_INC                        0xC0
#define SSD1306_COM_SCAN_DIR_DEC                        0xC8
#define SSD1306_SET_DISPLAY_OFFSET                      0xD3
#define SSD1306_SET_COM_PINS                            0xDA
#define SSD1306_CHARGE_PUMP                             0x8D
// Timing & Driving Scheme Setting Commands
#define SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO             0xD5
#define SSD1306_SET_PRECHARGE_PERIOD                    0xD9
#define SSD1306_SET_VCOM_DESELECT                       0xDB

/*Function Prototypes*/
void OLED_Init( void );
uint8_t OLED_Width( void );
uint8_t OLED_Height( void );
void OLED_Update( void );
void OLED_SetContrast( uint8_t contrast );
void OLED_ClearDisplay( void );
void OLED_FillDisplay( void );
void OLED_DrawPixel( int16_t x, int16_t y, uint8_t color );
void OLED_InvertDisplay( uint8_t value );
void OLED_SetFont( const uint8_t *font);
void OLED_InvertFont( uint8_t invert_status );
void OLED_Line( int16_t x_start, int16_t y_start, int16_t x_end, int16_t y_end, uint8_t color);
void OLED_V_Line( int16_t y_start, int16_t y_end, int16_t x_pos, uint8_t color);
void OLED_H_Line( int16_t x_start, int16_t x_end, int16_t y_pos, uint8_t color);
void OLED_Rectangle( int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
void OLED_FillRectangle( int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
void OLED_Triangle( int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
void OLED_Circle( int16_t x_center, int16_t y_center, int16_t radius, uint8_t color);
void OLED_Image( const uint8_t *image );
void OLED_Write( int16_t x, int16_t y, char value );
void OLED_Write_Text( int16_t x, int16_t y, char *text);


#ifdef	__cplusplus
}
#endif

#endif	/* OLED_H */

