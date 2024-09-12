/*
NIM         : 18222047
Nama        : Dama Dhananjaya Daliman
Tanggal     : 3 Nov 2023
Topik Prak  : Set, Map, Hashmap
Deskripsi   : Implementasi set.c dengan fungsi tambahan
*/

#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    S->Elements[S->Count] = Elmt;
    S->Count++;
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (S->Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->Elements[iterator - 1] = S->Elements[iterator];
    }
    S->Count--;
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (S.Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

Set SetUnion(Set s1, Set s2)
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]
{
    Set temp;
    CreateEmpty(&temp);
    
    int i;
    for(i=0; i< s1.Count; i++){
        if (!IsFull(s1)){
            if (!IsMember(temp, s1.Elements[i])){
                Insert(&temp, s1.Elements[i]);
            }
        } else {
            break;
        }
    }
    for(i=0; i< s2.Count; i++){
        if (!IsFull(s1)){
            if (!IsMember(temp, s2.Elements[i])){
                Insert(&temp, s2.Elements[i]);
            }
        } else {
            break;
        }
    }

    return temp;
}

Set SetIntersection(Set s1, Set s2)
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]
{
    Set temp;
    CreateEmpty(&temp);

    int i;
    for (i=0; i < s1.Count; i++){
        if (IsMember(s2, s1.Elements[i])){
            if(!IsFull(temp) && !IsMember(temp, s1.Elements[i])){
                Insert(&temp, s1.Elements[i]);
            }
        }
    }
    return temp;
}

Set SetSymmetricDifference(Set s1, Set s2)
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]
{
    Set uni, inter, result;
    CreateEmpty(&uni);
    CreateEmpty(&inter);
    CreateEmpty(&result);

    uni = SetUnion(s1, s2);
    inter = SetIntersection(s1, s2);

    int i;
    for(i=0; i < uni.Count; i++){
        if (!IsMember(inter, uni.Elements[i])){
            if(!IsFull(result)){
                Insert(&result, uni.Elements[i]);
            } else {
                break;
            }
        }
    }
    return result;
}

Set SetSubtract(Set s1, Set s2)
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]
{
    Set inter, result;
    CreateEmpty(&inter);
    CreateEmpty(&result);

    inter = SetIntersection(s1, s2);

    int i;
    for (i=0; i < s1.Count; i++){
        if (!IsMember(inter, s1.Elements[i])){
            if(!IsFull(result)){
                Insert(&result, s1.Elements[i]);
            }
        }
    }

    return result;
}