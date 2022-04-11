#include "header.h"

void *search_x(void *args){
    /* 
    Procura ocorrencia de palavras na direcao x (no mesmo plano e na mesma linha)
     */
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    char s[100];
    for(int z = 0; z < zmax; z ++){
        for(int y = 0; y < ymax; y ++){
            for(int x = 0; x < xmax; x ++){
                s[x] =*(matrix+(z*xmax*ymax)+x+(y*ymax)); // salva uma linha da matrix em uma variavel auxiliar
            }
            s[xmax]='\0';
            for(int i = 0; i < numWords*2; i ++){
                if(strstr(s,words+(i*100)) != NULL){    //compara com a lista de palavras
                    printf("word %s found by search_x\n", words+((i%numWords)*100));
                }
            }
        }
    }
    
    return NULL;
}

void *search_y(void *args){
    /* 
    Procura ocorrencia de palavras na direcao y (no mesmo plano e na mesma coluna)
     */
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;
    
    char s[100];
    for(int x = 0; x < xmax; x ++){
        for(int z = 0; z < zmax; z ++){
            for(int y = 0; y < ymax; y ++){
                s[y] =*(matrix+(z*xmax*ymax)+x+(y*ymax));
            }
            s[ymax]='\0';
            for(int i = 0; i < numWords*2; i ++){
                if(strstr(s,words+(i*100)) != NULL){
                    printf("word %s found by search_y\n", words+((i%numWords)*100));
                }
            }
        }
    }
    
    return NULL;
}

void *search_z(void *args){
    /* 
    Procura ocorrencia de palavras na direcao z (na mesma coluna e na mesma linha)
     */
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    char s[100];
    for(int x = 0; x < xmax; x ++){
        for(int y = 0; y < ymax; y ++){
            for(int z = 0; z < zmax; z ++){
                s[z] =*(matrix+(z*xmax*ymax)+x+(y*ymax));
            }
            s[zmax]='\0';
            for(int i = 0; i < numWords*2; i ++){
                if(strstr(s,words+(i*100)) != NULL){
                    printf("word %s found by search_z\n", words+((i%numWords)*100));
                }
            }
        }
    }
    return NULL;
}


void *search_xy(void *args){
    /* 
    Procura ocorrencia de palavras na direcao xy (no mesmo plano)
    As variaveis com sufixo inv percorrem os eixos em ordem inversa, ou seja, do valor máximo para o valor mínimo
    As variaveis com prefixo iter tem o objetivo de iterar no eixo correspondente sem modificar o valor original

     */
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    int xInv, yInv, iterX, iterY,iterXInv, iterYInv, x,y;
    char s[100];
    char sInv[100];
    for(int z = 0; z < zmax; z++){
        x = 0;
        y = 0;
        xInv = xmax-1;
        yInv = ymax-1;
        iterX = x;
        iterXInv = xInv;
        for(int i = 0; i < (xmax+ymax+zmax); i++){
            s[i] = '_';
            sInv[i] = '_';
        }
        // Esse bloco encontra as diagonais iterando a partir do eixo X
        while (x < xmax){
            s[iterX] =*(matrix+(z*xmax*ymax)+iterX+(y*ymax));
            sInv[iterXInv] = *(matrix+(z*xmax*ymax)+iterXInv+(y*ymax));
            iterX++;
            iterXInv--;
            y++;
            yInv--;
            if(y == ymax || iterX == xmax){
                iterX = x;
                iterXInv = xInv;
                y = 0;
                yInv = ymax-1;
                x ++;
                xInv--;
                for(int i = 0; i < numWords*2; i ++){
                    if(strstr(s,words+(i*100)) != NULL){
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                    }
                }
                for(int i = 0; i <(xmax+ymax+zmax); i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }           
            }          
        }
        x = 0;
        y = 0;
        xInv = xmax-1;
        yInv = ymax-1;
        iterY = y;
        iterYInv = yInv;
        for(int i = 0; i < (xmax+ymax+zmax); i++){
            s[i] = '_';
            sInv[i] = '_';
        }
        // Esse bloco encontra as diagonais iterando a partir do eixo Y      
        while (y < ymax){
            s[iterY] = *(matrix+(z*xmax*ymax)+x+(iterY*ymax));
            sInv[iterYInv] = *(matrix+(z*xmax*ymax)+x+(iterYInv*ymax));
            iterY++;
            iterYInv--;
            x++;
            xInv--;
            if(x == xmax || iterY == ymax){
                iterY = y;
                iterYInv = yInv;
                x = 0;
                xInv = xmax-1;
                y ++;
                yInv--;
                for(int i = 0; i < numWords*2; i ++){
                    if(strstr(s,words+(i*100)) != NULL){
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                    }
                }
                for(int i = 0; i <(xmax+ymax+zmax); i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
}

void *search_xz(void *args){
    /* 
    Procura ocorrencia de palavras na direcao xz (na mesma coluna)
    As variaveis com sufixo inv percorrem os eixos em ordem inversa, ou seja, do valor máximo para o valor mínimo
    As variaveis com prefixo iter tem o objetivo de iterar no eixo correspondente sem modificar o valor original

     */
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    int zInv, iterz,iterzInv, z;
    int xInv, yInv, iterX, iterY,iterXInv, iterYInv, x,y;
    char s[100];
    char sInv[100];
    for(int y = 0; y < ymax; y++){
        x = 0;
        z = 0;
        xInv = xmax-1;
        zInv = zmax-1;
        iterX = x;
        iterXInv = xInv;
        for(int i = 0; i < (xmax+ymax+zmax); i++){
            s[i] = '_';
            sInv[i] = '_';
        }
        // Esse bloco encontra as diagonais iterando a partir do eixo X   
        while (x < xmax){
            s[iterX] = *(matrix+(z*xmax*ymax)+iterX+(y*ymax));
            sInv[iterXInv] = *(matrix+(z*xmax*ymax)+iterXInv+(y*ymax));
            iterX++;
            iterXInv--;
            z++;
            zInv--;
            if(z == zmax || iterX == xmax){
                iterX = x;
                iterXInv = xInv;
                z = 0;
                zInv = zmax-1;
                x ++;
                xInv--;
                for(int i = 0; i < numWords*2; i ++){
                    if(strstr(s,words+(i*100)) != NULL){
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                    }
                }
                for(int i = 0; i < (xmax+ymax+zmax); i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }           
            }          
        }
        x = 0;
        z = 0;
        xInv = xmax-1;
        zInv = zmax-1;
        iterz = z;
        iterzInv = zInv;
        for(int i = 0; i < (xmax+ymax+zmax); i++){
            s[i] = '_';
            sInv[i] = '_';
        }
        // Esse bloco encontra as diagonais iterando a partir do eixo Z   
        while (z < zmax){
            
            
            s[iterz] = *(matrix+(iterz*xmax*ymax)+x+(y*ymax));
            sInv[iterzInv] = *(matrix+(iterzInv*xmax*ymax)+x+(y*ymax));
            iterz++;
            iterzInv--;
            x++;
            xInv--;
            if(x == xmax || iterz == zmax){
                iterz = z;
                iterzInv = zInv;
                x = 0;
                xInv = xmax-1;
                z ++;
                zInv--;
                for(int i = 0; i < numWords*2; i ++){
                    if(strstr(s,words+(i*100)) != NULL){
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                    }
                }
                for(int i = 0; i <(xmax+ymax+zmax); i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
}

void *search_yz(void *args){
    /* 
    Procura ocorrencia de palavras na direcao yz (na mesma linha)
    As variaveis com sufixo inv percorrem os eixos em ordem inversa, ou seja, do valor máximo para o valor mínimo
    As variaveis com prefixo iter tem o objetivo de iterar no eixo correspondente sem modificar o valor original

     */
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    int zInv, iterz,iterzInv, z;
    int xInv, yInv, iterX, iterY,iterXInv, iterYInv, x,y;
    char s[100];
    char sInv[100];
    for(int x = 0; x < xmax; x++){
        y = 0;
        z = 0;
        yInv = ymax-1;
        zInv = zmax-1;
        iterY = y;
        iterYInv = yInv;
        for(int i = 0; i < (xmax+ymax+zmax); i++){
            s[i] = '_';
            sInv[i] = '_';
        }
        // Esse bloco encontra as diagonais iterando a partir do eixo Y  
        while (y < ymax){
            s[iterY] = *(matrix+(z*xmax*ymax)+x+(iterY*ymax));
            sInv[iterYInv] = *(matrix+(z*xmax*ymax)+x+(iterYInv*ymax));
            iterY++;
            iterYInv--;
            z++;
            zInv--;
            if(z == zmax || iterY == ymax){
                iterY = y;
                iterYInv = yInv;
                z = 0;
                zInv = zmax-1;
                y ++;
                yInv--;
                for(int i = 0; i < numWords*2; i ++){
                    if(strstr(s,words+(i*100)) != NULL){
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                    }
                }
                for(int i = 0; i < (xmax+ymax+zmax); i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }           
            }          
        }
        y = 0;
        z = 0;
        yInv = ymax-1;
        zInv = zmax-1;
        iterz = z;
        iterzInv = zInv;
        for(int i = 0; i < (xmax+ymax+zmax); i++){
            s[i] = '_';
            sInv[i] = '_';
        }
        // Esse bloco encontra as diagonais iterando a partir do eixo Z   
        while (z < zmax){
            s[iterz] =*(matrix+(iterz*xmax*ymax)+x+(y*ymax));
            sInv[iterzInv] = *(matrix+(iterzInv*xmax*ymax)+x+(y*ymax));
            iterz++;
            iterzInv--;
            y++;
            yInv--;
            if(y == ymax || iterz == zmax){
                iterz = z;
                iterzInv = zInv;
                y = 0;
                yInv = ymax-1;
                z ++;
                zInv--;
                for(int i = 0; i < numWords*2; i ++){
                    if(strstr(s,words+(i*100)) != NULL){
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                    }
                }
                for(int i = 0; i < (xmax+ymax+zmax); i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
}





void print_grid(char *matrix, int xmax, int ymax, int zmax){
    for(int i=0; i<zmax; i++){
        printf(" __________");
    }
    printf("\n");


    for(int y = 0; y < ymax; y++){   
        printf("|");
        for(int z = 0; z < zmax; z++){// printa a matriz
            for(int x = 0; x < xmax; x++){
                printf("%c", *(matrix+(z*xmax*ymax)+(y*ymax)+x));
            }
            printf("|");
        }
        printf("\n");
    }


    for(int i=0; i<zmax; i++){
        printf(" ----------");
    }
    printf("\n\n");
}