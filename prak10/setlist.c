/*
NIM         : 18222047
Nama        : Dama Dhananjaya Daliman
Tanggal     : 17 Nov 2023
Topik Prak  : Variasi Linked List
Deskripsi   : Implementasi Set dengan LinkedList
*/

#include "setlist.h"

/* ********* Prototype ********* */

address Alokasi (infotype Elmt)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=Elmt, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc (sizeof(ElmtSet));
    if (P != Nil){
        Info(P) = Elmt;
        Next(P) = Nil;
    } else {
        return Nil;
    }
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong */
{
    First(*S) = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
{
    return (First(S) == Nil);
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen terakhir Set S. */
/* I.S. S mungkin kosong
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota terakhir dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    address P = Alokasi(Elmt);
    if (IsEmpty(*S)){
        First(*S) = P;
    } else {
        if (!IsMember((*S), Elmt)){
            address traversor = First(*S);
            while (Next(traversor) != Nil){
                traversor = Next(traversor);
            }
            Next(traversor) = P;
        } else {
            return;
        }
    }
}
void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    if (IsMember((*S), Elmt)){
        address traversor = First(*S);
        address prev = First(*S);
        while (Info(traversor) != Elmt){
            prev = traversor;
            traversor = Next(traversor);
        }
        // keluar dari sini traversor == Elmt
        // traversor mungkin adalah First(*S)
        if (traversor == First(*S)){
            First(*S) = Next(traversor);
        } else {
            Next(prev) = Next(traversor);
        }
        Next(traversor) = Nil;
        Dealokasi(traversor);
    } else {
        return;
    }
}
boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    if (IsEmpty(S)){
        return false;
    } else {
        address t = First(S);
        boolean found = false;
        while (Next(t) != Nil && !found){
            if (Info(t) == Elmt){
                found = true;;
            } else {
                t = Next(t);
            }
        }
        return found;
    }

}
int Count(Set S)
/* Mengembalikan jumlah elemen/anggota di dalam S*/
{
    address t = First(S);
    int count = 0;
    while(t != Nil){
        count++;
        t = Next(t);
    }
    return count;
}