#include <stdio.h>
int reverse(int num, int rev) {
    if (num == 0)
        return rev;
    return reverse(num / 10, rev * 10 + num % 10);
}
int main() {
    int num = 1234;
    int rev = reverse(num, 0);
    printf("Reverse of %d is %d\n", num, rev);
    return 0;
}

