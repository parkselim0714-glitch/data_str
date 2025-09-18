#include <stdio.h>

int main(void) {
    int n;

    printf("Á¤¼ö: ");
    scanf("%d", &n);

    if(n == 1)
        puts("A");
    else if(n == 2)
        puts("B");
    else if(n == 3)
        puts("C");

    return 0;
}