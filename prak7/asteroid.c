#include "stack.h"
#include "boolean.h"
#include <stdio.h>
#include <math.h>

/*
Perhatian:
- Boleh menggunakan fungsi abs()
- Prosedur collision tidak melakukan print apapun
- Asteroid bisa terlibat tabrakan lebih dari 1 kali
*/

boolean isCollision(infotype a, infotype b)
/* Mengirim true jika terjadi tabrakan */
/* yaitu ketika a > 0 dan b < 0 */
{
    return (a > 0 && b < 0);
}

void collision(int n, infotype *asteroids, Stack *remaining)
/* Proses: Mengisi stack dengan asteroid yang tersisa setelah tabrakan. 
    Asteroid dengan ukuran lebih besar tidak akan hancur, dan apabila kedua asteroid ukurannya sama maka 
    akan sama-sama hancur.  */
/* I.S Array asteroids pasti terisi dengan elemen positif atau negatif, Stack remaining telah terbentuk */
/* F.S Stack remaining terisi oleh sisa asteroid yang tidak hancur */
/*
   Contoh simulasi:
   - Input: [5,10,-5]
     Output: [5,10]
     Penjelasan: 5(->) 10(->) -5(<-) Asteroid 5 dan 10 bergerak ke kanan, -5 ke kiri. Asteroid 10 lebih besar dari -5, sehingga -5 hancur.

   - Input: [-10,10]
     Output: [-10,10]
     Penjelasan: -10(<-) 10(->) Kedua asteroid bergerak ke arah berbeda dan tidak bertemu, jadi tidak ada yang hancur.

   - Input: [1,-2,10,5]
     Output: [-2,10,5]
     Penjelasan: 1(->) -2(<-) akan bertabrakan, namun asteroid -2 lebih besar sehingga asteroid 1 hancur. Lalu, -2(<-) 10(->) tidak akan bertabrakan. 5 tetap melaju karena bergerak ke arah yang sama.
*/
{
    int i = 0;
    infotype ast1, ast2;
    Stack temp_asteroids, temp_remaining;
    CreateEmpty(&temp_asteroids);
    CreateEmpty(&temp_remaining);

    for (i = n-1; i > -1; i --) {
        Push(&temp_asteroids, asteroids[i]);
    }

    i = n;
    while (Top(temp_asteroids)!=0){
        Pop(&temp_asteroids, &ast1);
        Pop(&temp_asteroids, &ast2);
        if (isCollision(ast1, ast2)){
            if (abs(ast1) > abs(ast2)){
                Push(&temp_asteroids, ast1);
            } else {
                Push(&temp_asteroids, ast2);
            }
        } else {
            Push(&temp_remaining, ast1);
            Push(&temp_asteroids, ast2);
        }
    }
    Pop(&temp_asteroids, &ast1);
    Push(&temp_remaining, ast1);
    
    
}

void displayAsteroids(Stack S)
/* Proses : mereverse isi stack dari parameter kemudian mencetak elemen-elemen stack tersebut ke layar. */
/* I.S. S boleh kosong */
/* F.S. Jika S tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen asteroid bernilai 4, 5, -2 akan dicetak: [-2,4,5] */
/* Jika Stack kosong : menulis [] */
/* Terdapat new line setelah kurung tutup */
/* Hint: Buatlah stack baru untuk meng-copy isi dari stack parameter */
{
    int i;
    infotype temp_val=0, to_display=0;
    Stack temp, for_display;
    CreateEmpty(&for_display);
    CreateEmpty(&temp);

    while(!IsEmpty(S)){
        Pop(&S, &temp_val);
        Push(&temp, temp_val);
    }
    while(!IsEmpty(temp)){
        Pop(&temp, &temp_val);
        Push(&for_display, temp_val);
        Push(&S, temp_val);
    }
    printf("[");
    if (!IsEmpty(for_display)){
        while(Top(for_display)!=0){
            Pop(&for_display, &to_display);
            printf("%d,", to_display);
        }
        Pop(&for_display, &to_display);
        printf("%d", to_display);
    }
    printf("]\n");

}

// int main(){
//     int n = 3;
//     infotype asteroids[n-1];
//     asteroids[0]=5;
//     asteroids[1]=10;
//     asteroids[2]=-5;
//     Stack remaining;
//     CreateEmpty(&remaining);

//     collision(n, &asteroids, &remaining);
//     displayAsteroids(remaining);

//     return 0;
// }