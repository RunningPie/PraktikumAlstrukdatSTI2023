/*
NIM             : 18222047
Nama            : Dama Dhananjaya Daliman
Tanggal         : 08 September 2023
Topik praktikum : Pengenalan C
Deskripsi       : Program mencari bilangan cantik*

*Bilangan Cantik adalah bilangan yang ketika dibentuk dari
penjumlahan atau pengalian dari 2 angka, hasilnya akan berupa
bilangan kelipatan dari 4

*/

#include <stdio.h>

int main(){
    long int a, b;

    scanf("%ld %ld", &a, &b);

    if((a+b)%4 == 0 || (a*b)%4 == 0){
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}