/*
NIM         : 18222047
Nama        : Dama Dhananjaya Daliman
Tanggal     : 10 Nov 2023
Topik Prak  : Linked List (List Berkait/Linier)
Deskripsi   :
Febri ingin membeli tiket konser band kesukaannya tapi sayang sekali
Febri kalah war dengan 15 juta fans lainnya saat ingin membeli tiket tersebut.
Akhirnya Febri memilih untuk membeli tiket dari orang lain, untuk memastikan Febri tidak ditipu,
ia menanyakan lagu dari album band tersebut kepada penjual. Febri akan terus bertanya sampai
semua lagu dari album tersebut disebutkan oleh penjual atau salah satu jawaban dari penjual salah.
*/

#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    List input_l;
    CreateEmpty(&input_l);

    // char input_str[5];
    // scanf("%s", input_str);
    // printf("%d\n", strlen(input_str));
    
    static FILE * input_str;
    static int retval;
    char currentInput;

    input_str = stdin;
    retval = fscanf(input_str, "%d", &currentInput);
    

    int i = 0;
    while(currentInput != '\n'){
        // printf("Current char: %c\n", input_str[i]);
        if (currentInput == '-'){
            retval = fscanf(input_str, "%c", &currentInput);
            retval = fscanf(input_str, "%c", &currentInput);
        } else if (currentInput != ' '){
            // char non[5];
            InsVLast(&input_l, currentInput);
        }
        retval = fscanf(input_str, "%c", &currentInput);
        i++;
    }

    // PrintInfo(input_l);

    boolean ask = true, poser = true;
    int guess=-1;
    List guesses;
    CreateEmpty(&guesses);

    while (ask){
        scanf("%d", &guess);

        if (Search(input_l, guess) == Nil) {
            ask = false;
            poser = true;
        } else {
            if (Search(guesses, guess) == Nil){
                InsVLast(&guesses, guess);
            }
        }

        if (NbElmt(input_l) == NbElmt(guesses)){
            ask = false;
            poser = false;
        }
    }
    if (!poser){
        printf("Berhasil menebak %d lagu\n", NbElmt(guesses));
    } else {
        printf("Poser! %d tidak ada di dalam album\n", guess);
    }

    return 0;
}