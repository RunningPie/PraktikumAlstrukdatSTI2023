#include <stdlib.h>
#include "arraydin.h"
#include <stdio.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin(){
    ArrayDin arr;
    arr.A = (ElType *) malloc (InitialSize*sizeof(ElType));
    arr.Capacity = InitialSize;
    arr.Neff = 0;
    return arr;
}

/**
 * Destruktor
 * I.S. ArrayDin terdefinisi
 * F.S. array->A terdealokasi
 */
void DeallocateArrayDin(ArrayDin *array){
    free((*array).A);
    (*array).Capacity = 0;
    (*array).Neff = 0;
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin array){
    return (array.Neff == 0);
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin array){
    return(array.Neff);
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ArrayDin array, IdxType i){
    return ((array.A)[i]);

}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin array){
    return(array.Capacity);
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ArrayDin *array, ElType el, IdxType i){
    if((*array).Neff == (*array).Capacity)
    {
        (*array).A         = realloc((*array).A, 2*((*array).Capacity)*sizeof(ElType));
        (*array).Capacity *= 2;
    }
    
    for(int j = (*array).Neff; j > i; j--)
    {
        ((*array).A)[j] = ((*array).A)[j-1];
    }
    ((*array).A)[i] = el;
    (*array).Neff++;
}

void InsertLast(ArrayDin *array, ElType el){
    InsertAt(array, el, (*array).Neff);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *array, ElType el){
    InsertAt(array, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *array, IdxType i){
    for(int j = i; j < (*array).Neff - 1; j++)
    {
        (*array).A[j] = (*array).A[j+1]; 
    }
    (*array).Neff--;
}

void DeleteLast(ArrayDin *array){
    DeleteAt(array, (*array).Neff-1);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *array){
    DeleteAt(array, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin array){
    int i;

    printf("[");
    
    for(i=0;i<=array.Neff-2;i++){
        printf("%d, ", Get(array, i));
    }

    printf("%d]", Get(array, array.Neff-1));

    printf("\n");

}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *array){
    // ArrayDin arr;
    // int i;

    // arr = MakeArrayDin();

    // for (i=0; (*array).Neff-1; i++){
    //     InsertAt(&arr, Get( (*array), ((*array).Neff-1)-i ), i);
    // }
    // (*array).A = arr.A;
    for(int i = 0; i < (*array).Neff/2; i++)
    {
        ElType temp = (*array).A[i];
        (*array).A[i] = (*array).A[(*array).Neff-i-1];
        (*array).A[(*array).Neff-i-1] = temp; 
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin array) {
    return array;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin array, ElType el){
    // int i=-1;

    // while (i<=array.Neff-1 && Get(array, i) != el) {
    //     i++;
    // }

    // // printf("index: %d, neff: %d", i, array.Neff);
    // if (i==-1 || i>=array.Neff) {
    //     return -1;
    // } else {
    //     return i;
    // }
    for(int i = 0; i < array.Neff; i++)
    {
        if(array.A[i] == el) return i;
    }
    return -1;
}


// int main(){

//     ArrayDin A1, A2;
//     A1 = MakeArrayDin();
//     printf("%u\n", IsEmpty(A1));    
//     printf("%d\n", Length(A1));    
//     printf("%d\n", Get(A1, 0));

//     InsertAt(&A1, 20, 0); 
//     printf("%u\n", IsEmpty(A1));   
//     printf("%d\n", Get(A1, 0));
//     printf("%d\n", Length(A1));

//     InsertAt(&A1, 21, 1);  
//     printf("%u\n", IsEmpty(A1));  
//     printf("%d\n", Get(A1, 1));
//     printf("%d\n", Length(A1));

//     InsertAt(&A1, 23, 2);  
//     printf("%u\n", IsEmpty(A1));  
//     printf("%d\n", Get(A1, 1));
//     printf("%d\n", Length(A1));

//     DeleteAt(&A1, 0);   
//     printf("%u\n", IsEmpty(A1)); 
//     printf("%d\n", Get(A1, 0));
//     printf("%d\n", Length(A1));

//     PrintArrayDin(A1);
//     // ReverseArrayDin(&A1);
//     printf("idx: %d", SearchArrayDin(A1, 21));
//     printf("idx: %d", SearchArrayDin(A1, 20));
//     A2 = CopyArrayDin(A1);
//     PrintArrayDin(A2);

//     return 0;
// }