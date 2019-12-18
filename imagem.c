#include <stdio.h>
#include "filter.h"

char tipo[2];
int coluna, linha;
int max;

void gerar(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
   int i, j;

  printf("%s\n%i %i\n%i\n", tipo, coluna, linha, max);
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            printf("%i %i %i\n", mode[i][j].r, mode[i][j].g, mode[i][j].b);

        }
    }
}

void ler(int altura, int largura, PIXEL image[altura][largura]){
  int i,j;
        for(i=0; i<linha; i++){
            for(j=0; j<coluna; j++){
                scanf("%i %i %i", &image[i][j].r, &image[i][j].g, &image[i][j].b);

            }
        }
}


void filtro(int choose, int lin, int col, int maxi, PIXEL original[lin][col], PIXEL modefild[lin][col]){
enum {Normal = 1,Girar, Blur, Sharpen, Gray, Outline, Thresholding, Emboss, Entity}Escolha;
Escolha = choose;
switch (Escolha) {
    int i,j;

    case Normal:
            for(i=0; i<linha; i++){
                for(j=0; j<coluna; j++){
                    modefild[i][j].r = original[i][j].r;
                    modefild[i][j].g = original[i][j].g;
                    modefild[i][j].b = original[i][j].b;

                }
            }
        break;

    case Girar:
        inverte(lin, col, maxi, original, modefild);
        break;

    case Blur:
      
        blur(lin, col, maxi, original, modefild);

        break;
    case Sharpen:
        
        sharpen(lin, col, maxi, original, modefild);
        break;

    case Gray:
  
        gray(lin, col, maxi, original, modefild);
        break;

    case Outline:
     
        outline(lin, col, maxi, original, modefild);
        break;

    case Thresholding:
        
        thresholding(lin, col, maxi, original, modefild);
        break;

    case Emboss:
        
        emboss(lin, col, maxi, original, modefild);
        break;

    case Entity:
    
        identity(lin, col, maxi, original, modefild);
        break;
    
    }
}