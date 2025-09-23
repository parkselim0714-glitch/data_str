//9월 18일 자료구조 강의

// 입력받은 정숫값의 부호(양수/음수/0)을 판단

/*#include <stdio.h>

int main(void) {
    int n;

    printf("정수: ");
    scanf("%d", &n);

    if(n > 0)
        printf("양수입니다.\n");
    else if(n < 0)
        printf("음수입니다.\n");
    else
        printf("0입니다.\n");

    return 0;
}*/


//1부터 n까지의 총합을 구하기(while문)

/*#include <stdio.h>

int main(void) {
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0; // 총합
    int i = 1;

    while(i <= n) { // i가 n 이하이면 반복
        sum += i;   // sum에 i를 증가
        i++;        // i값을 1 증가
    }
    printf("1부터 &d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}*/


//1부터 n까지의 총합을 구하기(for문)

/*#include <stdio.h>

int main(void) {
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0; //총합
    int i = 1;

    for(int j = 1; j <= n; j++) {
        sum += j;
    }

    printf("for-1부터 %d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}*/


//1부터 n까지의 총합을 구하기(가우스의 덧셈 알고리즘)
/*#include <stdio.h>

int main(void) {
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0; //총합
    int i = 1;

    //가우스의 덧셈 알고리즘
    sum = n * (n + 1) / 2;
    printf("가우스의 덧셈 알고리즘으로 구한 1부터 %d까지의 총합은 %d입니다.\n", n, sum);

    return 0;
}*/


//1부터 n까지의 총합을 구하기(최종)
/*#include <stdio.h>

int main(void) {
    int n;

    puts("1부터 n까지의 총합을 구합니다.");

    printf("n값: ");
    scanf("%d", &n);

    int sum = 0; //총합
    int sum2 = 0;
    int sum3 = 0;
    int i = 1;

    while(i <= n) {
        sum += i;
        i++;
    }

    for(int j = 1; j <= n; j++) {
        sum2 += j;
    }

    sum3 = n * (n + 1) / 2;
   
    printf("while-1부터 %d까지의 총합은 %d입니다.\n", n, sum);
    printf("for-1부터 %d가지의 총함은 %d입니다.\n", n, sum2);
    printf("가우스의 덧셈 알고리즘으로 구한 1부터 %d까지의 총합은 %d입니다.\n", n, sum3);

    return 0;
}*/


// 곱셈표
/*#include <stdio.h>

int main(void) {
    printf("-----곱셈표-----\n");

    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            printf("%d X %d = %2d", i, j, i * j);
        }
        putchar('\n');
    }

    return 0;
}


//왼쪽 아래가 직각인 이등변 삼각형을 출력
/*#include <stdio.h>

int main(void) {
    int n;

    printf("몇 단 삼각형입니까?: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}*/


//가운데 정렬인 정삼각형을 출력
#include <stdio.h>

int main(void) {
    int n;

    printf("몇 단 삼각형입니까?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // 왼쪽 공백 출력
        for (int j = n-1; j > i - 1; j--)
            putchar(' ');
        // 별 출력
        for (int j = 0; j < 2 * i + 1; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}