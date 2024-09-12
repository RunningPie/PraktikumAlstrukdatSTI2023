#include "twoSum.h"
#include <stdlib.h>
#include <stdio.h>

int twoSum(List L1, List L2)
/* I.S. Masing-masing elemen dari L1 dan L2 merupakan angka dan */
/* L1 maupun L2 tidak kosong */
/* F.S. Menghasilkan angka hasil penjumlahan dua buah list L1 dan L2 */

/* Contoh */
/* L1 = 1 -> 2 -> 3  = 321 */ 
/* L2 = 5 -> 4 = 45 */
/* maka hasilnya adalah */
/* 321 + 45 = 366 */

/* L1 = 1 -> 9 -> 9 */
/* L2 = 9 */
/* maka hasilnya adalah */
/* 991 + 9 = 1000 */
{
    List temp;
    CreateEmpty(&temp);
    address p1 = First(L1), p2 = First(L2);
    while (p1 != Nil || p2 != Nil){
        infotype p1_val, p2_val;
        if (p1 == Nil){
            p1_val = 0;
        } else {
            p1_val = Info(p1);
        }

        if (p2 == Nil){
            p2_val = 0;
        } else {
            p2_val = Info(p2);
        }

        // printf("Info p1: %d\n", p1_val);
        // printf("Info p2: %d\n", p2_val);

        InsVFirst(&temp, p1_val+p2_val);
        // PrintInfo(temp);

        if (p1 != Nil){
            p1 = Next(p1);
        }
        if (p2 != Nil){
            p2 = Next(p2);
        }
    }

    address p_temp = First(temp);
    int sum = 0;
    while (p_temp != Nil){
        sum *= 10;
        sum += Info(p_temp);
        p_temp = Next(p_temp);
    }
    return sum;
}

// int main(){
//     List test_l1, test_l2;
//     CreateEmpty(&test_l1);
//     CreateEmpty(&test_l2);

//     InsVLast(&test_l1, 1);
//     InsVLast(&test_l1, 2);
//     InsVLast(&test_l1, 3);

//     InsVLast(&test_l2, 5);
//     InsVLast(&test_l2, 4);

//     printf("twoSum: %d\n", twoSum(test_l1, test_l2));

//     return 0;
// }