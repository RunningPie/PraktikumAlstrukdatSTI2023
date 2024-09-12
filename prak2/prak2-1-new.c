/*
NIM             : 18222047
Nama            : Dama D. Daliman
Tanggal         : 15 Sep 23
Topik praktikum : Pengenalan C #2
Deskripsi       : program mencari bilangan terbesar kedua dari input.
*/

#include <stdio.h>

int main(){
long int n_input = 0, i=0, line_input=0, max=LONG_MIN, scndmax=LONG_MIN;

scanf("%ld", &n_input);

while (i < n_input) {
    scanf("%ld", &line_input);
    if (line_input > max) {
        scndmax = max;
        max = line_input;
    } else if (line_input > scndmax && line_input < max) {
        scndmax = line_input;
    }

    i++;
}

printf("%ld\n", scndmax);

return 0;
}
