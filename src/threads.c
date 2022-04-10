#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct struct_args {
    char *words;
    char *matrix;
    int xmax;
    int ymax;
    int zmax;
} struct_args;

void *search_x(void *args){
    struct_args *arg=(struct_args *) args;

    char *words = arg -> words;
    char *matrix = arg -> matrix;
    int xmax = arg -> xmax;
    int ymax = arg -> ymax;
    int zmax = arg -> zmax;
    
    printf("Primeira palavra: %s", words+100);
    printf("Xmax: %d, Ymax: %d, Zmax: %d", xmax, ymax, zmax);
    printf("Primeira letra %c:", *matrix);

    /*
    Adicionar a estrutura da funcao
    */
    return NULL;
}


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


    struct_args argumentos;
    argumentos.words=words;
    argumentos.matrix=matrix;
    argumentos.xmax=xmax;
    argumentos.ymax=ymax;
    argumentos.zmax=zmax;
    

    pthread_t threadx;
    pthread_create (&threadx, NULL, &search_x, (void *) &argumentos);
    pthread_join(threadx, NULL);
}