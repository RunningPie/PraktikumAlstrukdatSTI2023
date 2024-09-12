#include <stdio.h>

int is_prime(long long int num) {
    if (num <= 1) return 0;  // 0 dan 1 bukan bilangan prima
    if (num <= 3) return 1;  // 2 dan 3 adalah bilangan prima

    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (long long int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }

    return 1;
}

int is_palindrome(long long int num) {
    long long int original = num;
    long long int reverse = 0;

    while (num > 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }

    return original == reverse;
}

int main() {
    long long int N;
    scanf("%lld", &N);

    long long int count = 0;
    long long int num = 2;

    while (count < N) {
        if (is_prime(num) && is_palindrome(num)) {
            count++;
        }
        num++;
    }

    printf("%lld\n", num - 1);

    return 0;
}
