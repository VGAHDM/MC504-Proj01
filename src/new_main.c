#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct struct_args {
    char *words;
    char *matrix;
    int numWords;
    int xmax;
    int ymax;
    int zmax;
} struct_args;


//////////////////////////////////////////////
//Functions

void *search_x(void *args){
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
                s[x] =*(matrix+(z*xmax*ymax)+x+(y*ymax));
            }
            s[10]='\0';
            for(int i = 0; i < numWords*2; i ++){
                if(strstr(s,words+(i*100)) != NULL){
                    //printf("%s\n", s);
                    printf("word %s found by search_x\n", words+((i%numWords)*100));
                }
            }
        }
    }
    
    return NULL;
}

void *search_y(void *args){
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
            s[10]='\0';
            for(int i = 0; i < numWords*2; i ++){
                if(strstr(s,words+(i*100)) != NULL){
                    //printf("%s\n", s);
                    printf("word %s found by search_y\n", words+((i%numWords)*100));
                }
            }
        }
    }
    
    return NULL;
}

void *search_z(void *args){
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
            s[10]='\0';
            //printf("%s\n", s);
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
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    // func xy
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
        for(int i = 0; i < 15; i++){
            s[i] = '_';
            sInv[i] = '_';
        }
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
                        //printf("z = %d\n", z);
                        //printf("sentence: %s\n", s);
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        //printf("z = %d\n", z);
                        //printf("sentence: %s\n", sInv);
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
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
        for(int i = 0; i < 15; i++){
            s[i] = '_';
            sInv[i] = '_';
        }
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
                        //printf("z = %d\n", z);
                        //printf("sentence: %s\n", s);
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        //printf("z = %d\n", z);
                        //printf("sentence: %s\n", sInv);
                        printf("word %s found by search_xy\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
}

void *search_xz(void *args){
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int numWords = arg -> numWords;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;

    // func xz
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
        for(int i = 0; i < 15; i++){
            s[i] = '_';
            sInv[i] = '_';
        }
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
                        //printf("y = %d\n", y);
                        //printf("sentence: %s\n", s);
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                       // printf("y = %d\n", y);
                       // printf("sentence: %s\n", sInv);
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
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
        for(int i = 0; i < 15; i++){
            s[i] = '_';
            sInv[i] = '_';
        }
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
                        //printf("y = %d\n", y);
                        //printf("sentence: %s\n", s);
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        //printf("y = %d\n", y);
                        //printf("sentence: %s\n", sInv);
                        printf("word %s found by search_xz\n", words+((i%numWords)*100));
                       // printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
}

void *search_yz(void *args){
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
        for(int i = 0; i < 15; i++){
            s[i] = '_';
            sInv[i] = '_';
        }
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
                        //printf("x = %d\n", x);
                       //printf("sentence: %s\n", s);
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                       // printf("x = %d\n", x);
                        //printf("sentence: %s\n", sInv);
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                       // printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
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
        for(int i = 0; i < 15; i++){
            s[i] = '_';
            sInv[i] = '_';
        }
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
                        //printf("x = %d\n", x);
                        //printf("sentence: %s\n", s);
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                    if(strstr(sInv,words+(i*100)) != NULL){
                        //printf("x = %d\n", x);
                        //printf("sentence: %s\n", sInv);
                        printf("word %s found by search_yz\n", words+((i%numWords)*100));
                        //printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
}





void print_grid(char *matrix, int xmax, int ymax, int zmax){
    for(int i=0; i<zmax; i++){
        printf("__________ ");
    }
    printf("\n");


    for(int y = 0; y < ymax; y++){   
        for(int z = 0; z < zmax; z++){// printa a matriz
            for(int x = 0; x < xmax; x++){
                printf("%c", *(matrix+(z*xmax*ymax)+(y*ymax)+x));
            }
            printf("|");
        }
        printf("\n");
    }


    for(int i=0; i<zmax; i++){
        printf("---------- ");
    }
    printf("\n\n");
} 

////////////////////////////////
///////////////////////////////
///////////////////////////////

void main(){
    int xmax,ymax,zmax,numWords;
    FILE *file;
    file = fopen("..\\input\\entrada.txt","r");
    
    fscanf(file, "%d %d %d %d\n", &xmax, &ymax, &zmax, &numWords);

    char * words;
    char * matrix; 

    words = malloc(sizeof(char)*100*numWords*2);
    matrix = malloc(sizeof(char)*zmax*ymax*xmax);
    
    for(int i = 0; i < numWords; i++){
        fgets((words+i*100),98,file);
        (words+i*100)[strcspn((words+i*100), "\n")] = 0;
        strcpy((words+(i+numWords)*100),(words+i*100));
        strrev((words+(i+numWords)*100)); 
    }
 
    for(int z = 0; z < zmax; z++){
        for(int x = 0; x < xmax; x++){
            fgets((matrix+(x*xmax)+(z*xmax*ymax)),xmax+2,file);
            (matrix+(x*xmax)+(z*xmax*ymax))[strcspn((matrix+(x*xmax)+(z*xmax*ymax)), "\n")] = 0;

        }
    } 


    int x=4;
    int y=7;
    int z=3;
    //char s=matrix+(z*xmax*ymax)+y+(x*xmax);
    //printf("Caracter:%c", *(matrix+(z*xmax*ymax)+x+(y*ymax)));


    struct_args argumentos;
    argumentos.words=words;
    argumentos.matrix=matrix;
    argumentos.numWords=numWords;
    argumentos.xmax=xmax;
    argumentos.ymax=ymax;
    argumentos.zmax=zmax;
    
    print_grid(matrix, xmax, ymax, zmax);

    pthread_t threadx;
    pthread_t thready;
    pthread_t threadz;
    pthread_t threadxy;
    pthread_t threadxz;
    pthread_t threadyz;


    pthread_create (&threadx, NULL, &search_x, (void *) &argumentos);
    pthread_create (&thready, NULL, &search_y, (void *) &argumentos);
    pthread_create (&threadz, NULL, &search_z, (void *) &argumentos);
    pthread_create (&threadxy, NULL, &search_xy, (void *) &argumentos);
    pthread_create (&threadxz, NULL, &search_xz, (void *) &argumentos);
    pthread_create (&threadyz, NULL, &search_yz, (void *) &argumentos);
    
    
    pthread_join(threadx, NULL);
    pthread_join(thready, NULL);
    pthread_join(threadz, NULL);
    pthread_join(threadxy, NULL);
    pthread_join(threadxz, NULL);
    pthread_join(threadyz, NULL);
}