/*
NIM             : 18222047
Nama            : Dama D. Daliman
Tanggal         : 15 Sep 23
Topik praktikum : Pengenalan C #2
Deskripsi       : program mencari bilangan terbesar kedua dari input.
*/

#include <stdio.h>

int main() {

    long int n_input = 0, i=2, line_input=0, max=0, scndmax=0, temp=0;

    scanf("%ld", &n_input);

    scanf("%ld", &line_input);
    max = line_input;

    scanf("%ld", &line_input);
    scndmax = line_input;

    if (scndmax > max) {
        temp = scndmax;
        scndmax = max;
        max = temp;
    }

    while (i < n_input) {
        scanf("%ld", &line_input);
        if (line_input > max) {
            scndmax = max;
            max = line_input;
        } else if (line_input > scndmax && line_input < max) {
            scndmax = line_input;
        }

        // printf("Sekarang looping ke: %ld\n", i);
        // printf("Sekarang nilai 2nd max: %ld\n", scndmax);
        // printf("Sekarang nilai max: %ld\n", max);

        i++;
    }

    printf("%ld\n", scndmax);

    return 0;
}