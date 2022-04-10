#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct struct_args {
    char * words;
    char * matrix;
    int xmax;
    int ymax;
    int zmax;
} struct_args;

int main()
{
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
 

    /* for(int z = 0; z < zmax; z++)// printa a matriz
        for(int y = 0; y < ymax; y++){   
            for(int x = 0; x < xmax; x++){
                printf("%c", *(matrix+(z*xmax*ymax)+(y*xmax)+x));
            }
            printf("\n");
        }
    } */ 
    /* struct_args var; //print do dicionario e teste de struct
    var.words = words;
    for(int i = 0; i < numWords*2; i++){
        printf("%s-",(var.words+i*100));
    }  */
    //x,y,z,xy,xz,yz,xyz
    return 0;
}