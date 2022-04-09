#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int xmax,ymax,zmax,numWords;
    FILE *file;
    file = fopen("..\\input\\entrada.txt","r");
    
    fscanf(file, "%d %d %d %d", &xmax, &ymax, &zmax, &numWords);

    char words[numWords*2][100];
    char matrix[zmax][ymax][xmax];
    char* aux; 

    for(int i = 0; i < numWords; i++){
        fscanf(file, "%s", &words[i]);
        strcpy(words[i+numWords],words[i]);
        strrev(words[i+numWords]);
    }

    for(int z = 0; z < zmax; z++){
        for(int x = 0; x < xmax; x++){
            fscanf(file, "%s", matrix[z][x]);

        }
    }

    /* for(int i = 0; i < numWords*2; i++){
        printf("%s ",words[i]);
    } */
    /*
    for(int z = 0; z < zmax; z++){
        for(int y = 0; y < ymax; y++){   
            for(int x = 0; x < xmax; x++){
                printf("%c", matrix[z][y][x]);
                
                //fscanf(file, "%s", matrix[x][z]);
            }
            printf("\n");
        }
    } */

    //x,y,z,xy,xz,yz,xyz
    return 0;
}