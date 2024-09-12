/*
NIM             : 18222047
Nama            : Dama D. Daliman
Tanggal         : 15 Sep 23
Topik praktikum : Pengenalan C #2
Deskripsi       : Hasil penjumlahan suku-suku genap dalam barisan bilangan Fibonacci sampai suku ke-n ATAU \( -1 \)
*/

#include <stdio.h>

int main() {

    int n=0, i=1, fibi=1, fibi_min=0, fibi_plus=1, sum=0;

    scanf("%d", &n);
    
    if (n >= 1 && n <= 50) {
        while (i != n+1) {

            // printf("Bilangan fibo ke-%ld, nilainya: %ld\n", i, fibi);

            if (fibi%2 == 0) {
                sum += fibi;
            }

            fibi_min = fibi;
            fibi = fibi_plus;
            fibi_plus = fibi + fibi_min;
            i++;
        }
    } else {
        sum = -1;
    }
    
    printf("%d\n", sum);

    return 0;
}