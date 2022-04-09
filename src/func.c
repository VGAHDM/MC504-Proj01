#include stdio.h
#include string.h

void searchX(){
    for(int x = 0; x < xmax; x ++){
        for(int y = 0; y < ymax; y ++){
            for(int z = 0; z < zmax; z ++){
                s[z] = matrix[z][y][x];
            }
            for(int i = 0; i < numWords*2; i ++){
                if(strstr(s,words[i]) != NULL){
                    printf("word found:", words[i%numWords]);
                }
            }
        }
    }
}
// func eixo y
for(int x = 0; x < xmax; x ++){
    for(int z = 0; z < zmax; z ++){
        for(int y = 0; y < ymax; y ++){
            s[y] = matrix[z][y][x];
        }
        for(int i = 0; i < numWords*2; i ++){
            if(strstr(s,words[i]) != NULL){
                printf("word found:", words[i%numWords]);
            }
        }
    }
}
// func eixo x
for(int z = 0; z < zmax; z ++){
    for(int y = 0; y < ymax; y ++){
        for(int x = 0; x < xmax; x ++){
            s[x] = matrix[z][y][x];
        }
        for(int i = 0; i < numWords*2; i ++){
            if(strstr(s,words[i]) != NULL){
                printf("word found:", words[i%numWords]);
            }
        }
    }
}