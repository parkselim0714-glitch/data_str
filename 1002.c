// 202530212 �ڼ���
// 10�� 02�� ����

// �迭 ��Ҹ� �������� ����
/*#include <stdio.h>
#include <stdlib.h>

// type�� x���� y���� ��ȯ
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

// ��� ������ n�� �迭 a�� ��Ҹ� �����ɷ� ����
void ary_reverse(int a[], int n) {
    for(int i = 0; i < n / 2; i++) 
    swap(int, a[i], a[n-i-1]);
}*/


// �迭 ��Ҹ� �������� �����ϴ� ���α׷�
/*#include <stdio.h>
#include <stdlib.h>                                     // calloc ������ ���� ����      


int main(void) {
    int nx;                                             // �迭 x�� ��� ����

    printf("��� ����: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for(int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    ary_reverse(x, nx);                                 // �迭 x�� ��Ҹ� �������� ����
    printf("�迭�� ��Ҹ� �������� �����߽��ϴ�.\n");
    for(int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                                             // �迭 x�� ����

    return 0;
}*/


// ��� ��ȯ�� �����ϴ� ���α׷�
/*#include <stdio.h>

int main(void) {
    puts("10������ ��� ��ȯ�մϴ�.");

    int retry;                                              // ?�� �? ?��?

    do{
        unsigned no;                                        // �??��?��?�� ?��?��
        int      cd;                                        // 기수 
        printf(("��ȯ�ϴ� ���� �ƴ� ����: "));                // �??��?�� 값의 �? ?��리의 ?��?���? ????��?��?�� 문자 배열
        scanf("%u", &no);

        do{
            printf("� ������ ��ȯ�ұ��?(2-36): ");
            scanf("%d", &cd);
        } while(cd < 2 || cd > 36);

        int dno = card_conv(no, cd, cno);                   // no�? dno?��리의 cd진수�? �??��

        printf("%d������", cd);
        for(int i = 0; i < dno; i++)                        // �? ?��리의 문자�? 차�??�? 출력
            printf("%c", cno[i]);
        printf("�Դϴ�.\n")

        printf("�� �� �� �ұ��?(1...��/0...�ƴϿ�): ");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}*/


// 1,000 ������ �Ҽ��� ����(���� 1)
/*#include <stdio.h>

int main(void) {
    unsigned long counter =0;                           // ?��?��?�� ?��?��
    for(int n = 2; n <= 1000; n++) {
        int i;
        for(i = 2; i < n; i++) {
            counter++;
            if(n % i == 0)                              // ?��?��?��?��?���?�? ?��?���? ?��?��
                break;                                  // ?�� ?��?��?�� 반복??? 불필?��
        }
        if(n == i)                                      // 마�??막까�? ?��?��?��?��?���?�? ?��?��
            printf("%d\n", n);
    }
    printf("�������� ������ Ƚ��: %lu\n", counter);

    return 0;
}*/


// 1,000 ������ �Ҽ��� ����(���� 2)
/*#include <stdio.h>

int main(void) {
    int prime[500];                         // ?��?���? ????��?��?�� 배열
    int ptr = 0;                            // ?���? ?��??? ?��?��?�� 개수
    unsigned long counter = 0;              // ?��?��?�� ?��?��
    prime[ptr++] = 2;                       // 2?�� ?��?��?��?��?��.
    for(int n = 3; n <= 1000; n += 2) {     // ????��만을 ????��
        int i;
        for(i = 1; i < ptr; i++) {          // ?���? ?��??? ?��?���? ?��?��
            counter++;
            if(n % prime[i] == 0)           // ?��?��?��?��?���?�?�? ?��?���? ?��?��
                break;                      // ?�� ?��?��?�� 반복??? 불필?��
        }
        if(ptr ==i)                         // 마�??막까�? ?��?��?��?��?���?�? ?��?��?���?
            prime[ptr++] = n;               // 배열?�� ????��
    }
    for(int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("�������� ������ Ƚ��: %lu\n", counter);

    return 0;
}*/


// 1,000 ������ �Ҽ��� ����(���� 3)
/*#include <stdio.h>

int main(void) {
    int prime[500];                                                 // ?��?���? ????��?��?�� 배열
    int ptr = 0;                                                    // ?���? ?��??? ?��?��?�� 개수
    unsigned long counter = 0;                                      // 곱셈�? ?��?��?��?�� ?��?�� ?��?��
    prime[ptr++] = 2;                                               // 2?�� ?��?��
    prime[ptr++] = 3;                                               // 3??? ?��?��
    for(int n = 5; n <= 1000; n += 2) {                             // ????��만을 ????��
        int i;
        int flag = 0;
        for(i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if(n % prime[i] == 0) {                                 // ?��?��?��?��?���?�? ?��?���? ?��?��
                flag = 1;
                break;                                              // ?�� ?��?��?�� 반복??? 불필?��
            }
        }
        if(! flag)                                                   // 마�??막까�? ?��?��?��?��?���?�? ?��?��
            prime[ptr++] = n;                                        // 배열?�� ????��
    }
}*/


// �� ���� ���� �� ���� ���Ͽ� ���
#include <stdio.h>

// �� ���� �� ��
int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// year���� �����ΰ�?
int isleap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

// y�� m�� d���� �� �� ���� �� ���� ����
int dayof_year(int y, int m,int d) {
    int days = d;                                                                   // �� ��
    for(int i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days;
}

int main(void) {
    int retry;                                                                      // �ٽ�?
    do {
        int year, month, day;                                                       // ��, ��, ��
        printf("?��: "); scanf("%d", &year);
        printf("?��: "); scanf("%d", &year);
        printf("?��: "); scanf("%d", &year);
        printf("%d?��?�� %d?��째입?��?��.\n: ", year, dayof_year(year, month, day));
        printf("?��?�� ?��까요?(1...?��/0...?��?��?��): "); scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}