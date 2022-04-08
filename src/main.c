#include <stdio.h>
#include <stdlib.h>

int main()
{
    int xmax,ymax,zmax,numWords;
    FILE *file;
    //char *matrix, *words;
    file = fopen("..\\input\\entrada.txt","r");
    
    fscanf(file, "%d %d %d %d", &xmax, &ymax, &zmax, &numWords);

    //matrix = malloc(sizeof(char)*ymax*xmax*zmax);
    //words =  malloc(sizeof(char)*100*numWords); //a word can not have more than 100 chars
    
    char words[numWords][100];
    char matrix[zmax][ymax][xmax];
    char* aux; 
    for(int i = 0; i < numWords; i++){
        fscanf(file, "%s", &words[i]);
        //fgets(words[i],1024,file);
    }
    for(int i = 0; i < numWords; i++){
        printf("%s ",words[i]);
    }
    
    for(int z = 0; z < zmax; z++){
        for(int x = 0; x < xmax; x++){
            //fscanf(file, "%c", matrix[y][x][z]);
            fscanf(file, "%s", matrix[z][x]);

        }
    }
    for(int z = 0; z < zmax; z++){   
        for(int x = 0; x < xmax; x++){
            printf("%s\n", matrix[z][x]);
            
            //fscanf(file, "%s", matrix[x][z]);
        }
        printf("\n");
        }
    return 0;
}