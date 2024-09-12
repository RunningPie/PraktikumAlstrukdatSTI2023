/*
NIM             : 18222047
Nama            : Dama Dhananjaya Daliman
Tanggal         : 08 September 2023
Topik praktikum : Pengenalan C
Deskripsi       : Program mencari bilangan terbesar
*/

#include <stdio.h>

int main(){
    long int a, b, c, result;
    // a = 0;
    // b = 0;
    // c = 0;
    // result = 0;

    // printf("program jalan");
    scanf("%ld %ld %ld", &a, &b, &c);
    // scanf("%ld", a);
    // printf("%ld", a);
    // printf("scan berhasil");
    // printf("%ld %ld %ld", a, b, c);

    if (a>b){
        if (a>c){
            result = a;
        } else {
            result = c;
        }
    } else {
        if (b>c){
            result = b;
        } else {
            result = c;
        }
    }
    // printf("if berhasil");

    printf("Diantara %ld, %ld, dan %ld. Angka terbesar adalah %ld\n", a, b, c, result);

    return 0;
}