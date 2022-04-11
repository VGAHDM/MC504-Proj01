#include "header.h"

void main(){
    int xmax,ymax,zmax,numWords;
    FILE *file;
    file = fopen("..\\input\\entrada.txt","r");
    
    fscanf(file, "%d %d %d %d\n", &xmax, &ymax, &zmax, &numWords);

    char * words;
    char * matrix; 

    words = malloc(sizeof(char)*100*numWords*2); //lista que guarda as palvras a serem procuradas e suas versoes de trás para frente
    matrix = malloc(sizeof(char)*zmax*ymax*xmax); //caca-palavras
    
    for(int i = 0; i < numWords; i++){// recebe a lista de palavras
        fgets((words+i*100),98,file);
        (words+i*100)[strcspn((words+i*100), "\n")] = 0;//remove \n
        strcpy((words+(i+numWords)*100),(words+i*100)); //copia a palavra
        strrev((words+(i+numWords)*100));   //inverte a palavra copiada
    }
 
    for(int z = 0; z < zmax; z++){  // recebe o caca-palavras
        for(int x = 0; x < xmax; x++){
            fgets((matrix+(x*xmax)+(z*xmax*ymax)),xmax+2,file);
            (matrix+(x*xmax)+(z*xmax*ymax))[strcspn((matrix+(x*xmax)+(z*xmax*ymax)), "\n")] = 0;

        }
    } 
    
    print_grid(matrix, xmax, ymax, zmax); // imprime o caca-palavras
    
    //Monta o struct
    struct_args argumentos;
    argumentos.words=words;
    argumentos.matrix=matrix;
    argumentos.numWords=numWords;
    argumentos.xmax=xmax;
    argumentos.ymax=ymax;
    argumentos.zmax=zmax;
    
    //declara as threads
    pthread_t threadx;
    pthread_t thready;
    pthread_t threadz;
    pthread_t threadxy;
    pthread_t threadxz;
    pthread_t threadyz;

    //declara as threads
    pthread_create (&threadx, NULL, &search_x, (void *) &argumentos);
    pthread_create (&thready, NULL, &search_y, (void *) &argumentos);
    pthread_create (&threadz, NULL, &search_z, (void *) &argumentos);
    pthread_create (&threadxy, NULL, &search_xy, (void *) &argumentos);
    pthread_create (&threadxz, NULL, &search_xz, (void *) &argumentos);
    pthread_create (&threadyz, NULL, &search_yz, (void *) &argumentos);
    
    //realiza o join das threads 
    pthread_join(threadx, NULL);
    pthread_join(thready, NULL);
    pthread_join(threadz, NULL);
    pthread_join(threadxy, NULL);
    pthread_join(threadxz, NULL);
    pthread_join(threadyz, NULL);
}