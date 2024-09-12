#include "duplicates.h"

boolean hasDuplicate(int n, int *nums, int k)
/* I.S Array nums bisa kosong, n merupakan panjang array nums, k merupakan integer positif */
/* F.S Mengembalikan boolean apabila terdapat duplicate number pada rentang k di array nums. 
Apabila nums kosong atau hanya 1 elemen maka mengembalikan nilai false */
/* 
  Contoh:
- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 4

  return: true
  Penjelasan: Elemen 6 berulang dengan jarak 4 yang mana <= k

- nums: [5, 6, 8, 2, 4, 6, 9]
  k: 2

  return: false
  Penjelasan: Tidak ada elemen berulang dengan jarak k = 2
*/
{
    if (n == 0 || n == 1){
      return false;
    } else {
        // int i=0;
        // while (i < n-1){
        //     int j=i+1;
        //     int ctr = 1;
        //     while (ctr <= k && j < n){
        //         if (nums[i] == nums[j]){
        //             return true;
        //         }
        //         ctr++;
        //         j++;
        //     }
        //     i++;
        // }

        // return false;

      HashMap temp;
      int i;
      CreateEmpty(&temp);
      for (i=0; i < n; i++){
        // valuetype * currV = Value(temp, nums[i]);
        if (Value(temp, nums[i])== Undefined){
          Insert(&temp, nums[i], i);
        } else {
          if (i - Value(temp, nums[i]) <= k) {
            return true;
          }
        }
      }
      return false;
    }
}

// int main(){
//   int arr[10];
//   int k = 4;
//   int n = 7;

//   arr[0] = 5;
//   arr[1] = 6;
//   arr[2] = 8;
//   arr[3] = 2;
//   arr[4] = 4;
//   arr[5] = 6;
//   arr[6] = 9;
//   // arr[0] = 5;

//   printf("%u\n", hasDuplicate(n, &arr[0], k));


// }