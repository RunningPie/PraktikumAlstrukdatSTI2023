/*
NIM         : 18222047
Nama        : Dama Dhananjaya Daliman
Tanggal     : 17 Nov 2023
Topik Prak  : Variasi Linked List
Deskripsi   : 
*/

#include "swap.h"

address AddressAtIndex(List L, infotype x)
/* 
Mencari address suatu node pada element ke- X
*/
{
    address t = First(L);
    int index = 0;
    while (Next(t) != Nil){
        if (index == (x-1)){
            return t;
        } else {
            t = Next(t);
            index++;
        }
    }
}
void Swap(List *L1)
/*
Kondisi awal: L1 sudah terisi dengan beberapa node.
Lakukan swap node pada node yang ada di tengah dari suatu List
*/
{
    int index1, index2;
    address node1, node2;
    scanf("%d %d", &index1, &index2);
    node1 = AddressAtIndex((*L1), index1);
    // printf("Line 37: %d\n", Info(node1));
    node2 = AddressAtIndex((*L1), index2);
    // printf("Line 39: %d\n", Info(node2));

    address prevn1 = Prev(node1), prevn2 = Prev(node2);
    address nextn1 = Next(node1), nextn2 = Next(node2);
    // printf("Line 43 ok\n");
    // printf("Info prevn1: %d\n", Info(prevn1));
    // printf("Info prevn2: %d\n", Info(prevn2));
    // printf("Info mextn1: %d\n", Info(nextn1));
    // printf("Info nextn2: %d\n", Info(nextn2));

    if (Next(node1) == node2) {
        Next(node1) = nextn2;
        Prev(node1) = node2;
        Next(node2) = node1;
        Prev(node2) = prevn1;

        Prev(nextn2) = node1;
        Next(prevn1) = node2;
    } else if (Next(node2) == node1) {
        Next(node2) = nextn1;
        Prev(node2) = node1;
        Next(node1) = node2;
        Prev(node1) = prevn2;

        Prev(nextn1) = node2;
        Next(prevn2) = node1;
    } else {
        Next(prevn1) = node2;
        Prev(node2) = prevn1;
        Next(node2) = nextn1;
        Prev(nextn1) = node2;
        // printf("Line 53 ok\n");

        Next(prevn2) = node1;
        Prev(node1) = prevn2;
        Next(node1) = nextn2;
        Prev(nextn2) = node1;
        // printf("Line 59 ok\n");
    }
}

// int main() {
//     List test_L;
//     CreateEmpty(&test_L);

//     // TC 1
//     InsVLast(&test_L, 4);
//     InsVLast(&test_L, 5);
//     InsVLast(&test_L, 6);
//     InsVLast(&test_L, 7);
//     InsVLast(&test_L, 8);

//     // TC 2
//     // InsVLast(&test_L, 1);
//     // InsVLast(&test_L, 2);
//     // InsVLast(&test_L, 3);
//     // InsVLast(&test_L, 4);
//     // InsVLast(&test_L, 5);
//     // InsVLast(&test_L, 6);
//     // InsVLast(&test_L, 7);
//     // InsVLast(&test_L, 8);
//     // InsVLast(&test_L, 9);
//     // InsVLast(&test_L, 10);

//     PrintForward(test_L);

//     Swap(&test_L);

//     PrintForward(test_L);

//     return 0;
// }