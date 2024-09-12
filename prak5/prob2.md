Terdapat track lari yang dibuat dari X character dengan pelari memiliki N energy untuk melakukan lari hingga garis finish. Tiap character yang diinjak membutuhkan 1 energy kecuali Pocari '>'. Lakukanlah Implementasikan lari.h dan submit lari.c

Contoh track

---->--@--#--.

| Character | Keterangan                                                                                                                                                          |
|-----------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|     -     | 1. Jalan biasa<br>2. Mengurangi 1 energy                                                                                                                            |
|     >     | 1. Pocari<br>2. Menambahkan 1 energy<br><br>**TIDAK MENGURANGI ENERGY**                                                                                             |
|     @     | 1. Punch<br>2. Digunakan untuk menghancurkan Block '#'<br>3. Mengurangi 1 energy<br>4. Tidak stack                                                                  |
|     #     | 1. Block<br>2. Dapat dilewati jika memiliki skill punch dan tetap mengurangi 1 energy<br>3. Jika tidak memiliki skill punch, energy menjadi -1 dan kondisi berakhir |
|     .     | 1. Merupakan garis finish<br>2. Mengurangi 1 energy                                                                                                                 |


| Input        | Output             | Explanation                                                                                                                                                                                                                                                                                                                                        |
|--------------|--------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 3<br>--.     | FINISH<br>ENERGY 0 | 1. - Energy berkurang 1, energy menjadi 2<br>2. - Energy berkurang 1, energy menjadi 1<br>3. . Energy berkurang 1, energy menjadi 0                                                                                                                                                                                                                |
| 2<br>--.     | FAIL<br>ENERGY 0   | 1. - Energy berkurang 1, energy menjadi 1<br>2. - Energy berkurang 1, energy menjadi 0<br><br>Pelari tidak cukup energy untuk ke garis finish                                                                                                                                                                                                      |
| 4<br>->@#    | FINISH<br>ENERGY 1 | 1. - Energy berkurang 1, energy menjadi 3<br>2. > Energy bertambah, energy menjadi 4<br>3. @ Energy berkurang 1, energy menjadi 3, mendapatkan skill punch<br>4. # Energy berkurang 1, energy menjadi 2, menggunakan skill punch untuk menghancuran block dan pelari sudah tidak memiliki skill punch<br>5. . Energy berkurang 1, energy menjadi 1 |
| 4<br>--#---. | FAIL<br>ENERGY -1  | 1. - Energy berkurang 1, energy menjadi 3<br>2. - Energy berkurang 1, energy menjadi 2<br>3. # Energy menjadi -1, Block tidak dapat dihancurkan dikarenakan tidak memiliki skill punch dan kondidsi berakhir                                                                                                                                       |

File yang diperlukan mesinkarakter.c mesinkarakter.h boolean.h

NOTE:
1. Output terdapat newline
2. Input untuk menerima energy dapat menggunakan scanf