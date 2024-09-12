/*
NIM         : 18222047
Nama        : Dama Dhananjaya Daliman
Tanggal     : 10 Nov 2023
Topik Prak  : Linked List (List Berkait/Linier)
Deskripsi   : Memeriksa palindrome dari sebuah list linier.
*/

#include "palindromeListLinier.h"

boolean isPalindromeList(List l)
{
    List ori_temp, invers_ori;
    CreateEmpty(&ori_temp);
    CreateEmpty(&invers_ori);

    if (IsEmpty(l)) {
        return true;
    } else {
        int i;
        address p=First(l);
        for (i=1; i <= NbElmt(l); i++){
            InsVFirst(&invers_ori, Info(p));
            InsVLast(&ori_temp, Info(p));
            p = Next(p);
        }

        PrintInfo(ori_temp);
        PrintInfo(invers_ori);

        // int i;
        boolean palindrome = true;
        address p1=First(ori_temp), p2 = First(invers_ori);
        for (i=1; i <= NbElmt(ori_temp); i++){
            if (Info(p1) != Info(p2)) {
                palindrome = false;
            } else {
                p1 = Next(p1);
                p2 = Next(p2);
            }
        }
        return palindrome;
    }
}

/*
    Diberikan sebuah list linier l,
    kembalikan true jika list tersebut merupakan palindrome dan false jika tidak.
    Contoh input/output:
    l: [1,2,3,4,5,4,3,2,1]
    expected return: true

    Di atas merupakan palindrome list linier karena jika dibaca dari kiri maupun kanan, tetap sama.

    l: [1,1,2,1]
    expected return: false

    Di atas bukan palindrome list linier karena jika dibaca dari kiri maupun kanan, berbeda. 1,1 dan 1,2.

    P.S. List linier kosong merupakan palindrome.
*/

// int main() {
//     List test_l;
//     CreateEmpty(&test_l);

//     // InsVLast(&test_l, 1);
//     // InsVLast(&test_l, 2);
//     // InsVLast(&test_l, 3);
//     // InsVLast(&test_l, 4);
//     // InsVLast(&test_l, 5);
//     // InsVLast(&test_l, 4);
//     // InsVLast(&test_l, 3);
//     // InsVLast(&test_l, 2);
//     // InsVLast(&test_l, 1);

//     // InsVLast(&test_l, 1);
//     // InsVLast(&test_l, 1);
//     // InsVLast(&test_l, 2);
//     // InsVLast(&test_l, 1);

//     InsVLast(&test_l, 1);

//     PrintInfo(test_l);
//     printf("Is List Palindrome? %u\n", isPalindromeList(test_l));
// }