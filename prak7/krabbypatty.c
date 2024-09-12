#include "stack.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void krabbyPatty(Stack *ingredients, Stack *burger)
/*
Membuat satu Krabby Patty dari tumpukan bahan

~ CONTOH 1 ~
Awal:
ingredients -> [7, 1, 9, 2, 3, 4, 3, 0, 1, 2]
burger -> []

Akhir:
ingredients -> [7, 1]
burger -> [0, 2, 3, 4, 3, 1, 2, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- keju
- patty
- selada
- bawang
- selada
- keju
- roti bawah

Sisa bahan di tumpukan bahan:
- patty
- saus

~ CONTOH 2 ~
Awal:
ingredients -> [0, 2, 9, 3, 4, 3, 7, 0, 9, 9]
burger -> []

Akhir:
ingredients -> [0, 2, 9, 3, 4, 3, 7]
burger -> [0, 9]

Terjemahan:
Krabby Patty dapat dibuat dengan susunan:
- roti atas
- roti bawah

Sisa bahan di tumpukan bahan:
- saus
- selada
- bawang
- selada
- roti atas
- keju
- roti bawah

~ CONTOH 3 ~
Awal:
ingredients -> [1, 3, 8, 5, 7, 9]
burger -> []

Akhir:
ingredients -> []
burger -> []

Terjemahan:
Krabby Patty tidak dapat dibuat

Tidak ada bahan tersisa di tumpukan bahan
*/
{
    boolean found9 = false, found0 = false;
    int ing=-1, temp9=0, temp_ing=-1;
    Stack popped_ings;
    CreateEmpty(&popped_ings);

    while(!IsEmpty(*ingredients) && (!found9 || !found0)) {
        Pop(ingredients, &ing);
        if (ing == 0){
            if(!found0){
                found0 = true;
            }
        } else if (ing == 9){
            if(!found9){
                found9 = true;
            }
        } else {
            Push(&popped_ings, ing);
        }
        // displayStack(*burger);
    }
    if (found0 && found9){
        Push(burger, 0);
        while(!IsEmpty(popped_ings)){
            Pop(&popped_ings, &temp_ing);
            Push(burger, temp_ing);
        }
        Push(burger, 9);
    }

}

// void displayStack(Stack S)
// /* Proses : mereverse isi stack dari parameter kemudian mencetak elemen-elemen stack tersebut ke layar. */
// /* I.S. S boleh kosong */
// /* F.S. Jika S tidak kosong: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen asteroid bernilai 4, 5, -2 akan dicetak: [-2,4,5] */
// /* Jika Stack kosong : menulis [] */
// /* Terdapat new line setelah kurung tutup */
// /* Hint: Buatlah stack baru untuk meng-copy isi dari stack parameter */
// {
//     int i;
//     infotype temp_val=0, to_display=0;
//     Stack temp, for_display;
//     CreateEmpty(&for_display);
//     CreateEmpty(&temp);

//     while(!IsEmpty(S)){
//         Pop(&S, &temp_val);
//         Push(&temp, temp_val);
//     }
//     while(!IsEmpty(temp)){
//         Pop(&temp, &temp_val);
//         Push(&for_display, temp_val);
//         Push(&S, temp_val);
//     }
//     printf("[");
//     if (!IsEmpty(for_display)){
//         while(Top(for_display)!=0){
//             Pop(&for_display, &to_display);
//             printf("%d,", to_display);
//         }
//         Pop(&for_display, &to_display);
//         printf("%d", to_display);
//     }
//     printf("]\n");

// }

// int main(){
//     Stack ingredients, burger;
//     CreateEmpty(&ingredients);
//     CreateEmpty(&burger);

//     int i;
//     for (i=0;i<=9;i++){
//         Push(&ingredients, i);
//     }

//     displayStack(ingredients);

//     krabbyPatty(&ingredients, &burger);

//     displayStack(burger);

//     return 0;
// }