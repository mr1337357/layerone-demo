#include <stdint.h>
//uint8_t sprite_load(const uint8_t *sprite);
void font_load(const uint8_t *font,int len);
void sprite_clear(uint8_t slot);
void sprite_blit(uint8_t slot,uint8_t x,uint8_t y);
void gfx_clear_screen();
void gfx_flip();
void gfx_drawpixel(uint16_t x,uint16_t y,uint8_t color);
uint8_t gfx_getpixel(uint16_t x,uint16_t y);
void set_bw();
void gfx_init();
void gfx_singlebuffer();
void print(char *message);
void screen_putch(char c);