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
            s[iterX] = matrix[z][y][iterX];
            sInv[iterXInv] = matrix[z][y][iterXInv];
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
                    if(strstr(s,words[i]) != NULL){
                        printf("z = %d\n", z);
                        printf("sentence: %s\n", s);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                    if(strstr(sInv,words[i]) != NULL){
                        printf("z = %d\n", z);
                        printf("sentence: %s\n", sInv);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
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
            
            
            s[iterY] = matrix[z][iterY][x];
            sInv[iterYInv] = matrix[z][iterYInv][x];
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
                    if(strstr(s,words[i]) != NULL){
                        printf("z = %d\n", z);
                        printf("sentence: %s\n", s);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                    if(strstr(sInv,words[i]) != NULL){
                        printf("z = %d\n", z);
                        printf("sentence: %s\n", sInv);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////

    // func xz
    int zInv, iterz,iterzInv, z;
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
            s[iterX] = matrix[z][y][iterX];
            sInv[iterXInv] = matrix[z][y][iterXInv];
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
                    if(strstr(s,words[i]) != NULL){
                        printf("y = %d\n", y);
                        printf("sentence: %s\n", s);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                    if(strstr(sInv,words[i]) != NULL){
                        printf("y = %d\n", y);
                        printf("sentence: %s\n", sInv);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
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
            
            
            s[iterz] = matrix[iterz][y][x];
            sInv[iterzInv] = matrix[iterzInv][y][x];
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
                    if(strstr(s,words[i]) != NULL){
                        printf("y = %d\n", y);
                        printf("sentence: %s\n", s);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                    if(strstr(sInv,words[i]) != NULL){
                        printf("y = %d\n", y);
                        printf("sentence: %s\n", sInv);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
        /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////
        // func yz
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
            s[iterY] = matrix[z][iterY][x];
            sInv[iterYInv] = matrix[z][iterYInv][x];
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
                    if(strstr(s,words[i]) != NULL){
                        printf("x = %d\n", x);
                        printf("sentence: %s\n", s);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                    if(strstr(sInv,words[i]) != NULL){
                        printf("x = %d\n", x);
                        printf("sentence: %s\n", sInv);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
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
            
            
            s[iterz] = matrix[iterz][y][x];
            sInv[iterzInv] = matrix[iterzInv][y][x];
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
                    if(strstr(s,words[i]) != NULL){
                        printf("x = %d\n", x);
                        printf("sentence: %s\n", s);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                    if(strstr(sInv,words[i]) != NULL){
                        printf("x = %d\n", x);
                        printf("sentence: %s\n", sInv);
                        printf("word found: %s\n", words[i%numWords]);
                        printf("________________________\n");
                    }
                }
                for(int i = 0; i < 15; i++){
                    s[i] = '_';
                    sInv[i] = '_';
                }     
            }
        }
    }
    return 0;
}