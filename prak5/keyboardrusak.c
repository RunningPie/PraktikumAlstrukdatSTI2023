#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"

void printword(Word cword){
    int i;
    for (i=0; i<cword.Length; i++){
        printf("%c", cword.TabWord[i]);
    }
    printf("\n");
}

int main() {

    boolean isQwerty = false;
    char newTab[NMax];
    int i, wordCount;;

    STARTWORD();
    
    while (!isEndWord()){
        if (wordCount > 0){
            printf(" ");
        }
        for (i=0; i<currentWord.Length; i++){
            isQwerty = (currentWord.TabWord[i] == 'q' || currentWord.TabWord[i] == 'w' ||
                        currentWord.TabWord[i] == 'e' || currentWord.TabWord[i] == 'r' ||
                        currentWord.TabWord[i] == 't' || currentWord.TabWord[i] == 'y');
            if (isQwerty && i > 1) {
                int j, newi=0;
                // char temp;
                // printf("Switching %c with %c\n", currentWord.TabWord[i-1], currentWord.TabWord[i-2]);
                for (j=i-1; j>=0; j--) {
                    newTab[newi] = currentWord.TabWord[j];
                    newi++;
                }
                for (newi=0; newi<i;newi++){
                    currentWord.TabWord[newi] = newTab[newi];
                }
                // printf("Current word is: ");
                // printword(currentWord);
            }
        }
        for (i=0; i<currentWord.Length; i++) {
            printf("%c", currentWord.TabWord[i]);
        }
        wordCount++;
        ADVWORD();
    }

    printf(".\n");

    return 0;
}