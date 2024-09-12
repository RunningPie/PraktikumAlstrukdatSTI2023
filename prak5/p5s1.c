#include <stdio.h>
#include "boolean.h"
#include "mesinkarakter.h"
#include "mesinkata.h"

int main() {
    int sumlength = 0;

    STARTWORD();
    sumlength += currentWord.Length;
    ADVWORD();
    while(!isEndWord()){
            ADVWORD();
    }
    sumlength += currentWord.Length;

    printf("%d\n", sumlength);
    return 0;
}