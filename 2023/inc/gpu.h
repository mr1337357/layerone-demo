#ifndef GPU_H 
#define GPU_H 

#include <stdint.h>

#define VENST_FUDGE 0
#define HENST_FUDGE 0
#define VSPOL 0                 // sync polarities
#define HSPOL 0

#define CHR_FGCOLOR	     	    0x5000
#define CHR_BGCOLOR	     	    0x5100
#define CHR_FONTBASE            0x5200
#define CHR_PRINTCHAR           0x5300
#define CHR_PRINTCHARTRANS	    0x5380
#define CHR_TXTAREASTART        0x5800
#define CHR_TXTAREAEND          0x5900
#define CHR_PRINTPOS	        0x5A00

#define RCC_SRCADDR	     	    0x6200
#define RCC_DESTADDR	        0x6300
#define RCC_RECTSIZE	        0x6400
#define RCC_COLOR	     	    0x6600
#define RCC_STARTCOPY	        0x6700

#define RCC_OPER_MASK           0x0380
#define RCC_OPER_SOLID          0x0000
#define RCC_OPER_COPY           0x0080
#define RCC_OPER_TRANS          0x0300

#define RCC_ROP_MASK            0x0078
#define RCC_ROP_BLACK           0x0000
#define RCC_ROP_COPY            0x0060
#define RCC_ROP_WHITE           0x0780

#define IPU_SRCADDR	     	    0x7100
#define IPU_DESTADDR            0x7200
#define IPU_DECOMPRESS          0x7400

// MAX BUFFER SIZE MUST BE GREATER THAN 32KB IF DOUBLE BUFFERING
#define GFX_MAX_BUFFER_SIZE 76800

extern volatile uint32_t frames;

extern __eds__ uint8_t GFXDisplayBuffer[GFX_MAX_BUFFER_SIZE] __attribute__((section("DISPLAY"),space(eds)));

void __attribute__((interrupt, auto_psv))_GFX1Interrupt(void);

void gpu_init(void);
void gpu_vsync();
void gpu_flush();
void gpu_config(void);
void gpu_set_fb(__eds__ uint8_t *buf);
void gpu_flip_fb(void);
void gpu_clear_fb(void);
void gpu_draw_border(uint16_t c);

void gpu_config_clut();
void gpu_clut_set(uint8_t index, uint16_t color);

void gpu_config_chr(void);
void gpu_chr_print(char *c, uint16_t x, uint16_t y, uint8_t transparent);
void gpu_chr_fg_color(unsigned int color);
void gpu_chr_bg_color(unsigned int color);

void rcc_set_fb_dest(__eds__ uint8_t *buf);
void rcc_set_fb_src(__eds__ uint8_t *buf);
void rcc_color(unsigned int color);
void rcc_rec(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void rcc_pixel(unsigned long ax, unsigned long ay);
void rcc_line(float x1, float y1, float x2, float y2, uint8_t color);
void rcc_blit(uint32_t sprite, uint16_t x, uint16_t y, uint16_t w, uint16_t h);
void rcc_scroll();
uint16_t rgb_2_565(uint8_t r, uint8_t g, uint8_t b);

#endif
