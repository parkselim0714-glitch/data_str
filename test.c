// 9�� 18�� ����

// �Է¹��� �������� ��ȣ(���/����/0)�� �Ǵ�

/*#include <stdio.h>

int main(void) {
    int n;

    printf("����: ");
    scanf("%d", &n);

    if(n > 0)
        printf("����Դϴ�.\n");
    else if(n < 0)
        printf("�����Դϴ�.\n");
    else
        printf("0�Դϴ�.\n");

    return 0;
}*/


// 1���� n������ ������ ���ϱ�(while��)

/*#include <stdio.h>

int main(void) {
    int n;

    puts("1���� n������ ������ ���մϴ�.");

    printf("n��: ");
    scanf("%d", &n);

    int sum = 0; //����
    int i = 1;

    for(int j = 1; j <= n; j++) {
        sum += j;
    }

    printf("while-1���� %d������ ������ %d�Դϴ�.\n", n, sum);

    return 0;
}*/


// 1���� n������ ������ ���ϱ�(for��)

/*#include <stdio.h>

int main(void) {
    int n;

    puts("1���� n������ ������ ���մϴ�.");

    printf("n��: ");
    scanf("%d", &n);

    int sum = 0; //����
    int i = 1;

    for(int j = 1; j <= n; j++) {
        sum += j;
    }

    printf("for-1���� %d������ ������ %d�Դϴ�.\n", n, sum);

    return 0;
}*/


// 1���� n������ ������ ���ϱ�(���콺�� ���� �˰���)

/*#include <stdio.h>

int main(void) {
    int n;

    puts("1���� n������ ������ ���մϴ�.");

    printf("n��: ");
    scanf("%d", &n);

    int sum = 0; //����
    int i = 1;

    //���콺�� ���� �˰���
    sum = n * (n + 1) / 2;
    printf("���콺�� ���� �˰������� ���� 1���� %d������ ������ %d�Դϴ�.\n", n, sum);

    return 0;
}*/


// 1���� n������ ������ ���ϱ�(����)
/*#include <stdio.h>

int main(void) {
    int n;

    puts("1���� n������ ������ ���մϴ�.");

    printf("n��: ");
    scanf("%d", &n);

    int sum = 0; //����
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
   
    printf("while-1���� %d������ ������ %d�Դϴ�.\n", n, sum);
    printf("for-1���� %d������ ������ %d�Դϴ�.\n", n, sum2);
    printf("���콺�� ���� �˰������� ���� 1���� %d������ ������ %d�Դϴ�.\n", n, sum3);

    return 0;
}*/


// ����ǥ
/*#include <stdio.h>

int main(void) {
    printf("-----����ǥ-----\n");

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%d X %d = %2d  ", i, j, i * j);
        }
        putchar('\n');
    }

    return 0;
}*/


// ���� �Ʒ��� ������ �̵ �ﰢ���� ���
/*#include <stdio.h>

int main(void) {
    int n;

    printf("�� �� �ﰢ���Դϱ�?: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}*/


// ��� ������ ���ﰢ���� ���
#include <stdio.h>

int main(void) {
    int n;

    printf("�� �� �ﰢ���Դϱ�?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // ���� ���� ���
        for (int j = n-1; j > i - 1; j--)
            putchar(' ');
        // �� ���
        for (int j = 0; j < 2 * i + 1; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}


// �ﰢ�� ���(����)
#include <stdio.h>

int main(void) {
    int n;

    printf("�� �� �ﰢ���Դϱ�?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        // ���� ���� ���
        for (int j = n-1; j > i - 1; j--)
            putchar(' ');
        // �� ���
        for (int j = 0; j < 2 * i + 1; j++)
            putchar('*');
        putchar('\n');
    }

    return 0;
}