#include <stdio.h>
#include "balikstring.h"

int panjangString(char* ch)
{
    int panjang = 0;
    while(*ch != '\0') {panjang++; ch++;}
    return panjang;
}

void membalikString(char* str)
{
    int n = panjangString(str);
    for(int i = 0; i < n/2; i++)
    {
        char temp = str[i];
        str[i] = str[n-i-1]; str[n-i-1] = temp;
    }
}
