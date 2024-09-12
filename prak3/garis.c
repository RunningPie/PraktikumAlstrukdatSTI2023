#include <stdio.h>
#include "point.h"
#include "garis.h"
#include <math.h>


void MakeGARIS (POINT P1, POINT P2, GARIS *L) {

    PAwal(*L) = P1;
    PAkhir(*L) = P2;

}

void BacaGARIS (GARIS *L){

    BacaPOINT(&PAwal(*L));
    BacaPOINT(&PAkhir(*L));

    while (EQ(PAwal(*L), PAkhir(*L))) {
        printf("Garis tidak valid\n");
        BacaPOINT(&PAwal(*L));
        BacaPOINT(&PAkhir(*L));
    }

    // MakeGARIS()
}

void TulisGARIS (GARIS L){

    printf("(");
    TulisPOINT(PAwal(L));
    printf(",");
    TulisPOINT(PAkhir(L));
    printf(")");

}
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
/* Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma. */

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L) {
    return (Panjang(PAwal(L), PAkhir(L)));
}
/* Menghitung panjang garis L : berikan rumusnya */
// sqrt [(x2-x1)^2 + (y2-y1)^2] //

float Gradien (GARIS L){
    return( (Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L))) );
}
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2){
    return ( (Gradien(L1) * Gradien(L2)) == -1 );
}
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */

boolean IsSejajar (GARIS L1, GARIS L2){
    return ( (Gradien(L1) == Gradien(L2)) );
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */

// int main(){
//     GARIS G1;

//     BacaGARIS(&G1);
//     TulisGARIS(G1);

//     return 0;
// }