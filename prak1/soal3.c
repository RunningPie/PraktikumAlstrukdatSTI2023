/*
NIM             : 18222047
Nama            : Dama Dhananjaya Daliman
Tanggal         : 08 September 2023
Topik praktikum : Pengenalan C
Deskripsi       : Program untuk menentukan bilangan palindrom prima ke-N

*Bilangan Cantik adalah bilangan yang ketika dibentuk dari
penjumlahan atau pengalian dari 2 angka, hasilnya akan berupa
bilangan kelipatan dari 4

*/

#include <stdio.h>

int isPrima(x) {
    int hasil = 0, divider=2;
    if (x==0 || x==1) {
        return 0;
    }
    if (x==2 || x==3) {
        return 1;
    }

    while (divider<x){
        // printf("%d mod by %d\n", x, divider);
        if (x%divider==0){
            divider = x+1;
        }
        divider++;
    }

    // printf("divider: %d", divider);

    if (divider != x+2){
        return 1;
    } else {
        // printf("Not prime! \n");
        return 0;
    }
    
}

int isPalindrom(num) {
    int origin=num, digit=0, reverse = 0;
    while (origin > 0){
        digit = origin%10;
        reverse *= 10;
        reverse += digit;
        origin = origin/10;
    }
            // printf("bil prima yg origin: %ld\n", i);
            // printf("kebalikannya: %ld\n", reverse);
    // printf("new pal: %d == num: %d\n", reverse, num);
    return reverse == num;
}

int main(){
    int input, i, j, palindrome_count, prime_res;
    i = 2;
    palindrome_count = 0;
    prime_res = 0;

    scanf("%d", &input);

    while (palindrome_count != input){
        if (isPalindrom(i) && isPrima(i)){
            // printf("Is prima and is palindrom\n");
            palindrome_count++;
            prime_res = i;
        }
        i++;
    }

    printf("%d\n", prime_res);

    return 0;
}