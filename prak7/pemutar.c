#include "stack.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[20];
    int length;
} song;

int main() {
    Stack played;
    song songlist[10];
    int num = -1, i=-1, j=-1, op=-1, idx=-1;
    char input_t[20];
    boolean can_play=false;

    CreateEmpty(&played);

    scanf("%d", &num);
    for (i=0; i<num; i++){
        scanf("%s", input_t);
        for(j=0; j<strlen(input_t); j++){
            songlist[i].title[j] = input_t[j];
        }
    }

    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d", &op);
        if (op==1){
            scanf("%d", &idx);
            Push(&played, idx);
            can_play = true;
        } else {
            if (!IsEmpty(played)){
                Pop(&played, &idx);
                if (!IsEmpty(played)){
                    Pop(&played, &idx);
                    Push(&played, idx);
                    can_play=true;
                } else {
                    can_play = false;
                }
                
            } else {
                can_play = false;
            }
            
        }
        if (can_play) {
            printf("Playing: ", songlist[idx].title[i]);
            for(j=0; j<strlen(songlist[idx].title); j++){
                printf("%c", songlist[idx].title[j]);
            }
            printf("\n");
        } else {
            printf("No music is played\n");
        }
        
    }




    return 0;
}