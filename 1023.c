// 202530212 �� ����
// 10�� 23�� ����

// ���� �˻�
#include <stdio.h>
#include <stdlib.h>

// ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�
int search(const int a[], int n, int key) {
    int i = 0;
    while(1) {
        if(i == n)
            return -1;
        if(a[i] == key)
            return i;
        i++;
    }
}

int main(void) {
    int nx, ky;
    puts("���� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));                       // ����� ������ nx�� int�� �迭 x�� ����
    for(int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    printf("�˻���: ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);                            // �迭 x�� ���� ky�� ��Ҹ� ���� �˻�
    if(idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
    free(x);                                                // �迭 x�� ����

    return 0;
}


// ���� �˻�
#include <stdio.h>
#include <stdlib.h>

//����� ������ n�� �迭 a���� ket�� ��ġ�ϴ� ��Ҹ� ���� �˻�
int bin_search(const int a[], int n, int key) {
    int pl = 0;
    int pr = n - 1;

    do {
        int pc = (pl + pr) / 2;
        if(a[pc] == key)
            return pc;
        else if(a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while(pl < = pr);
      return -1;

int main(void) {
    int nx, ky;
    puts("���� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    printf("��������")
}
}