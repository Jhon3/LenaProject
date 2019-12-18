#ifndef __FILTER_H__
#define __FILTER_H__
typedef struct{
    int r, g, b;
}PIXEL;

void gray(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void thresholding(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void blur(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void sharpen(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void emboss(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void identity(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void outline(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
void inverte(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);
#endif