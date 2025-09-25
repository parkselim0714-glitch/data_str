// 202530212 �� ����
// 9�� 25�� ����

// int[5]�� �迭(�ڷ����� int���̰� ��Ұ� 5��)�� ���� �Է��� ���

/*#define N 5                               // �迭�� ��� ����
int main() {
    int a[N];                               // �迭�� ����
    for(int i = 0; i < N; i++) {            // �� ��ҿ� ���� �Է�
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    puts("�� ����� ��");
    for(int i = 0; i < N; i++) {            // �� ����� ���� �Է�
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}*/


// int�� �迭�� �ʱ�ȭ�ϰ� ���

/*#include <stdio.h>

int main(void) {
    int a[5] = {13, 42, 53, 134, 25};       // ����� ����
    int na = sizeof(a) / sizeof(int);              
    printf("�迭 a�� ��� ������ %d�Դϴ�.\n", na);
    
    for(int i = 0; i < na; i++)
        printf("a[%d] = %d\n", i, a[i]);
    
    return 0;
}*/


// int�� ��ü�� �������� �����ϰ� ��ü

/*#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *X = calloc(1, sizeof(int));
    if(X == NULL)
        puts("�޸� �Ҵ翡 �����߽��ϴ�.");
    else {
        *X = 57;
        printf("*X = %d\n", *X);
        free(X);
    }

    return 0;
}*/


// int�� �迭�� �������� �����ϰ� ����

/*#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int el_num;
    printf("��� ���� : ");
    scanf("%d", &el_num);
    int*a = calloc(el_num, sizeof(int));

    if (a==NULL)
        puts("�޸� Ȯ���� �����߽��ϴ�.");
    else{
        printf("�ʱ�ȭ ���� Ȯ��.\n", el_num);
        for (int i = 0; i < el_num; i++){
            printf("a[%d] = %d\n", i, a[i]);
        }
        
        printf("%d���� ������ �Է��ϼ���.\n", el_num);
        for (int i = 0; i < el_num; i++){
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }
        printf("�� ��Ұ��� �Ʒ��� �����ϴ�.\n");
        for (int i = 0; i < el_num; i++)
            printf("a[%d] = %d\n", i, a[i]);
        free(a);
    }
    
    return 0;
}*/


// �迭 ����� �ִ��� ���ϰ� ���(��Ұ� �Է�)

#include <stdio.h>
#include <stdlib.h>

/*-- ��� ������ n�� �迭 a�� ����� �ִ� --*/
int maxof(const int a[], int elem_cnt) {

    int max = a[0];                                 // �ִ�
    for(int i = 1; i < elem_cnt; i++) 
        if(a[i] > max) max = a[i];
    return max;
}

int main(void) {

    int number;                                     // �ο� = �迭 height�� ��� ����
    printf("��� ��: ");
    scanf("%d", &number);
    int *height = calloc(number, sizeof(int));      // ��� ���� number ���� �迭�� ����
    printf("%d���� Ű�� �Է��ϼ���.\n", number);
    for(int i = 0; i < number; i++) {
        printf("height[%d]: ", i);
        scanf("%d", &height[i]);
    }
    printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
    free(height);                                   // �迭 height�� ����

    return 0;
}

