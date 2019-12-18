#include <stdio.h>
#include <stdlib.h>
#include "filter.h"
#include "imagem.h"


char tipo[2];
int coluna, linha;
int max;
int escolha;
int main (){
//Remember to put a filter option on the first line of the lena.txt file.
// 1 - Imagem original.
// 2 - Rotacionar 180°.
// 3 - Blur.
// 4 - Sharpen.
// 5 - Gray.
// 6 - Outline.
// 7 - Thresholding.
// 8 - Emboss.
// 9 - Entity.   
//Choose an option from 1 to 9:
escolha = 2;

scanf ("%s", tipo);
scanf("%i %i", &coluna, &linha);
scanf("%i", &max);

PIXEL imagem[linha][coluna];
PIXEL modificada[linha][coluna];

ler(linha, coluna, imagem);
filtro(escolha, linha, coluna, max, imagem, modificada);
gerar(linha, coluna, max, imagem, modificada);

return 0;
}




