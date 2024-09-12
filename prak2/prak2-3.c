/*
NIM             : 18222047
Nama            : Dama D. Daliman
Tanggal         : 15 Sep 23
Topik praktikum : Pengenalan C #2
Deskripsi       : Program yang menerima X dan Y dan menampilkan bilangan apa saja yang merupakan bilangan armstrong.
*/

#include <stdio.h>
// #include <math.h>

int power(angka, pangkat) {
    int i = 1, hasil = angka;
    while (i != pangkat){
        hasil *= angka;
        i++;
    }
    return hasil;
}

int hitung_digit(angka){
    int d_count = 1;
    while (angka >= 10){
        angka = angka/10;
        d_count++;
    }
    return d_count;
}

int main() {
    int x=0, y=0, digit=0, hasil, i=0, total_digit=0;

    scanf("%d %d", &x, &y);
    // scanf("%d", &x);
    // printf("x: %d, y: %d", x, y);

    for (i=x;i<=y;i++) {
        total_digit = hitung_digit(i);
        // printf("Sekarang angka: %d, dengan jum digit: %d\n", i, total_digit);
        int copy_i = i, hasil = 0;
        // printf("Status hasil: %d", hasil);

        while (copy_i > 0) {
            // printf("Sekarang angkanya: %ld\n", copy_i);

            if (copy_i%10==0) {
                copy_i = copy_i/10;
            } else {
                digit = copy_i%10;
                // printf("digit: %d", digit);
                hasil += power(digit, total_digit);

                copy_i = copy_i - copy_i%10;
                // printf("Sekarang angkanya: %ld\n", copy_i);
            }
            
            // printf("Sekarang hasilnya: %d\n", hasil);
        }

        if (i == hasil) {
            printf("%d\n", i);
        }
        // printf("\n");
    }

    return 0;
}