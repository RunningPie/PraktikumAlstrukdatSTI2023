Saat nugas di cafe, laptop Tuan Rian ketumpahan minuman sehingga keyboard dari laptopnya rusak. Apabila Tuan Rian mengetikkan huruf `'q', 'w', 'e', 'r', 't', 'y'` di keyboardnya akan menyebabkan karakter-karakter yang telah diketikkan sebelumnya pada kata tersebut akan terbalik. Sebagai contoh apabila Tuan Rian ingin mengetikkan kata `keyboard`, maka saat Tuan Rian telah mengetik `ke`, `ke` akan terbalik menjadi `ek` karena Tuan Rian mengetikkan huruf `y`, lalu saat terbentuk `ekyboa` dan bertemu huruf `r` maka `ekyboa` akan terbalik lagi menjadi `aobyke`. Hasil dari keyboard rusak Tuan Rian saat mengetikkan `keyboard` adalah `aobykerd`.

Buatlah sebuah program yang membaca sebuah pita karakter, lalu mensimulasikan keyboard rusak milik Tuan Rian.

Masukan berupa karakter alfabet a sampai z dan keluaran diakhiri dengan newline. Gunakan mesinkarakter.h, mesinkarakter.c, mesinkata.h, dan mesinkata.c untuk membantu pengerjaan soal.

Contoh input dan output:

| Input                          | Output                         | Penjelasan                                           |
| ------------------------------ | ------------------------------ | ---------------------------------------------------- |
| qwerty.                        | teqwry.                        | qwerty -> wqerty -> eqwrty -> rwqety -> teqwry       |
| aku suka praktikum alstrukdat. | aku suka karptikum adkurslatt. | aku                                                  |
|                                |                                | suka                                                 |
|                                |                                | praktikum -> karptikum                               |
|                                |                                | alstrukdat -> slatrukdat -> talsrukdat -> adkurslatt |

Perhatian:

- Terdapat newline disetiap output
- Pembalikan hanya berlaku di kata tersebut, sehingga kata sebelumnya tidak akan terpengaruh
