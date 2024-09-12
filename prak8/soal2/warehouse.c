/*
NIM         : 18222047
Nama        : Dama Dhananjaya Daliman
Tanggal     : 3 Nov 2023
Topik Prak  : Set, Map, Hashmap
Deskripsi   : program yang melakukan pengelolaan terhadap gudang bahan makanan. Program akan menerima input sebuah integer antara angka 1 hingga 4. Program akan berhenti apabila input yang diterima bernilai 4.
*/

#include "warehouse.h"
#include <stdio.h>
#include <string.h>

void manageWareHouse(Map *wareHouse)
/*
I.S. variable wareHouse sudah terisi dengan bahan-bahan

Buatlah program yang melakukan pengelolaan terhadap gudang bahan makanan. Program akan menerima input sebuah integer antara angka 1 hingga 4. Program akan berhenti apabila input yang diterima bernilai 4.

Untuk keterangan input dan bagaimana proses pengelolaan, dapat dilihat dalam soal
*/
{
    int op_in=0;
    boolean run = true;

    while (run){
        scanf("%d", &op_in);
        if (op_in == 1){
            int i;
            for (i=0; i < (*wareHouse).Count; i++){
                printf("Bahan %d: %d\n", (*wareHouse).Elements[i].Key, (*wareHouse).Elements[i].Value);
            }
        } else if (op_in == 2){
            char s_kurang[100];
            scanf("%s", &s_kurang);

            int i;
            for(i=0; i < strlen(s_kurang); i++){
                keytype no_bahan = s_kurang[i] - '0';
                if (IsMember((*wareHouse), no_bahan)){
                    valuetype *stok = &((*wareHouse).Elements[no_bahan-1].Value);
                    if (*stok == 0){
                        printf("Stok bahan %d sudah habis\n", no_bahan);
                    } else {
                        *stok = *stok-1;
                    }
                }
            }
        } else if (op_in == 3) {
            char s_tambah[100];
            scanf("%s", &s_tambah);

            int i;
            for(i=0; i < strlen(s_tambah); i++){
                keytype no_bahan = s_tambah[i] - '0';
                if (IsMember((*wareHouse), no_bahan)){
                    (*wareHouse).Elements[no_bahan-1].Value++;
                }
            }
        } else {
            run = false;
        }
    }
}

// int main(){
//     Map wh;
//     CreateEmpty(&wh);
    
//     printf("Creating wh map\n");
    
//     Insert(&wh, 1, 1);
//     Insert(&wh, 2, 3);
//     Insert(&wh, 3, 3);
//     Insert(&wh, 4, 4);
//     Insert(&wh, 5, 5);

//     printf("Finished creating wh map\n");
//     printf("with length: %d\n", wh.Count);
//     printf("and first element <%d, %d>\n", wh.Elements[0].Key, wh.Elements[0].Value);
//     printf("entering procedure\n");
//     manageWareHouse(&wh);

//     return 0;
// }