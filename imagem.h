#ifndef __IMAGEM_H__
#define __IMAGEM_H__


char tipo[2];
int coluna, linha;
int max;

void ler(int altura, int largura, PIXEL image[altura][largura]);
void filtro(int choose, int lin, int col, int maxi, PIXEL original[lin][col], PIXEL modefild[lin][col]);
void gerar(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]);


#endif