#include <stdio.h>
#include "filter.h"

void gray(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int media;
    int i,j;
    for ( i = 0; i < altura; i++){
        for ( j= 0; j < largura; j++){
            media = (image[i][j].r + image[i][j].g + image[i][j].b)/3;
            mode[i][j].r = media;
            mode[i][j].g = media;
            mode[i][j].b = media;
        }
    }
}



void thresholding(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int media;
    int i,j;
        for ( i = 0; i < altura; i++){
            for ( j= 0; j < largura; j++){
                media = (image[i][j].r + image[i][j].g + image[i][j].b)/3;
                if (media > (maxx/2)){
                    mode[i][j].r = maxx;
                    mode[i][j].g = maxx;
                    mode[i][j].b = maxx;
                }
                else {
                    mode[i][j].r = 0;
                    mode[i][j].g = 0;
                    mode[i][j].b = 0;
                }
            }
        }
}


void blur(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int lin, col, i, j, sumr, sumg, sumb;

    float boxblur[3][3] = {
        {1/9.f, 1/9.f, 1/9.f},
        {1/9.f, 1/9.f, 1/9.f},
        {1/9.f, 1/9.f, 1/9.f}
    };
    for(lin = 1; lin < altura-1; lin++){
        for(col = 1; col< largura-1; col++){
            sumr = 0, sumg = 0, sumb = 0;
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    sumr += image[lin-1 +i] [col -1 +j].r * boxblur [i][j];
                    sumg += image[lin-1 +i] [col -1 +j].g * boxblur [i][j];
                    sumb += image[lin-1 +i] [col -1 +j].b * boxblur [i][j];
                }
            }
            if (sumr>maxx){
                sumr = maxx;
            }if (sumr<0){
                sumr = 0;
            }if (sumg > maxx){
                sumg = maxx;
            }if (sumg<0){
                sumg = 0;    
            }if (sumb>maxx){
                sumb = maxx;
            }if (sumb<0){
                sumb = 0;
            }
            
            mode[lin][col].r = sumr;
            mode[lin][col].g = sumg;
            mode[lin][col].b = sumb;
            }
        }
    }


void sharpen(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int lin, col, i, j, sumr, sumg, sumb;

    float boxsharpen[3][3] = {
        { 0, -1,  0},
        { -1, 5, -1},
        { 0, -1,  0}
    };

    for(lin = 1; lin < altura-1; lin++){
        for(col = 1; col< largura-1; col++){
            sumr = 0, sumg = 0, sumb = 0;
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    sumr += image[lin-1 +i] [col -1 +j].r * boxsharpen [i][j];
                    sumg += image[lin-1 +i] [col -1 +j].g * boxsharpen [i][j];
                    sumb += image[lin-1 +i] [col -1 +j].b * boxsharpen [i][j];
                }
                
            }
            if (sumr>maxx){
                sumr = maxx;
            }if (sumr<0){
                sumr = 0;
            }if (sumg>maxx){
                sumg = maxx;
            }if (sumg<0){
                sumg = 0;
            }if (sumb>maxx){
                sumb = maxx;
            }if (sumb<0){
                sumb = 0;
            } 
            mode[lin][col].r = sumr;
            mode[lin][col].g = sumg;
            mode[lin][col].b = sumb;
        }
    }
}

void emboss(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int lin, col, i, j, sumr, sumg, sumb;

    float boxemboss[3][3] = {
        { -2,-1, 0},
        { -1, 1, 1},
        { 0, 1,  2}
    };

    for(lin = 1; lin < altura-1; lin++){
        for(col = 1; col< largura-1; col++){
            sumr = 0, sumg = 0, sumb = 0;
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    sumr += image[lin-1 +i] [col -1 +j].r * boxemboss [i][j];
                    sumg += image[lin-1 +i] [col -1 +j].g * boxemboss [i][j];
                    sumb += image[lin-1 +i] [col -1 +j].b * boxemboss [i][j];
                }
                
            }
            if (sumr>maxx){
                sumr = maxx;
            }if (sumr<0){
                sumr = 0;
            }if (sumg>maxx){
                sumg = maxx;
            }if (sumg<0){
                sumg = 0;
            }if (sumb>maxx){
                sumb = maxx;
            }if (sumb<0){
                sumb = 0;
            } 
            mode[lin][col].r = sumr;
            mode[lin][col].g = sumg;
            mode[lin][col].b = sumb;
        }
    }
}

void outline(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int lin, col, i, j, sumr, sumg, sumb;

    float boxoutline[3][3] = {
        { -1, -1, -1},
        { -1, 8, -1},
        { -1, -1, -1}
    };

    for(lin = 1; lin < altura-1; lin++){
        for(col = 1; col< largura-1; col++){
            sumr = 0, sumg = 0, sumb = 0;
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    sumr += image[lin-1 +i] [col -1 +j].r * boxoutline [i][j];
                    sumg += image[lin-1 +i] [col -1 +j].g * boxoutline [i][j];
                    sumb += image[lin-1 +i] [col -1 +j].b * boxoutline [i][j];
                }
                
            }
            if (sumr>maxx){
                sumr = maxx;
            }if (sumr<0){
                sumr = 0;
            }if (sumg>maxx){
                sumg = maxx;
            }if (sumg<0){
                sumg = 0;
            }if (sumb>maxx){
                sumb = maxx;
            }if (sumb<0){
                sumb = 0;
            } 
            mode[lin][col].r = sumr;
            mode[lin][col].g = sumg;
            mode[lin][col].b = sumb;
        }
    }
}

void identity(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
    int lin, col, i, j, sumr, sumg, sumb;

    float boxidentity[3][3] = {
        { 0, 0, 0},
        { 0, 1, 0},
        { 0, 0, 0}
    };

    for(lin = 1; lin < altura-1; lin++){
        for(col = 1; col< largura-1; col++){
            sumr = 0, sumg = 0, sumb = 0;
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    sumr += image[lin-1 +i] [col -1 +j].r * boxidentity [i][j];
                    sumg += image[lin-1 +i] [col -1 +j].g * boxidentity [i][j];
                    sumb += image[lin-1 +i] [col -1 +j].b * boxidentity [i][j];
                }
                
            }
            if (sumr>maxx){
                sumr = maxx;
            }if (sumr<0){
                sumr = 0;
            }if (sumg>maxx){
                sumg = maxx;
            }if (sumg<0){
                sumg = 0;
            }if (sumb>maxx){
                sumb = maxx;
            }if (sumb<0){
                sumb = 0;
            } 
            mode[lin][col].r = sumr;
            mode[lin][col].g = sumg;
            mode[lin][col].b = sumb;
        }
    }
}

void inverte(int altura, int largura, int maxx, PIXEL image[altura][largura], PIXEL mode[altura][largura]){
   int i, j;
   
   for(i=0; i<altura; i++){
        for(j=0; j<largura; j++){
            mode[i][j].r = image[altura - i - 1][largura - j -1].r;
            mode[i][j].g = image[altura - i - 1][largura - j -1].g; 
            mode[i][j].b = image[altura - i - 1][largura - j -1].b;

        }
    }
    
}

