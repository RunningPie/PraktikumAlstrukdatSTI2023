#include <stdio.h>
#include "balikstring.h"
// #include "panjangstring.h"

// Menerima argumen pointer yang merupakan sebuah string
// Mengembalikan panjang string
int panjangString(char* ch){
    int i = 0, count=0;
    while (*(ch+i) != '\0'){
        // printf("%c", *(str+i));
        i += sizeof(char);
        count++;
    }
    return count;
}


// Menerima argumen pointer yang merupakan sebuah string (diasumsikan tidak ada huruf kapital)
// Parameter str merupakan string yang akan dibalik
// Contoh : str adalah "slevel" maka akan terubah menjadi "levels"
void membalikString(char* str){
    int i;
    char* newstr = " ";

    printf("%c", *str);

    for (i=0; i <= panjangString(str); i += sizeof(char)) {
        // printf("%c diassign %c\n", newstr[i], str[panjangString(str)-i]);
        *(newstr+i) = *(str+i);
    }

    // while (*newstr++= *str++);

    // printf("Ini newstr:");
    // printf("%d", panjangString(newstr));
    // printf("%c", newstr[0]);
    // for (i=0; i<=panjangString(newstr); i++){
    //     printf("%c", newstr[i]);
    // }

    // str = newstr;
    
}

int main() {

    char test[100] = "hello";
    int i;

    printf("string awal:");
    printf("%d\n", panjangString(test));

    for (i=0; i<=panjangString(test); i++){
        printf("%c", test[i]);
    }

    printf("\n");

    printf("String dibalik:");
    membalikString(test);

    // for (i=0; i<=panjangString(test); i++){
    //     printf("%c", test[i]);
    // }

    return 0;
}