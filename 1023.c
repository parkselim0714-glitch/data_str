// 202530212 박 세림
// 10월 23일 강의

// 선형 검색
#include <stdio.h>
#include <stdlib.h>

// 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색
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
    puts("선형 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));                       // 요소의 개수가 nx인 int형 배열 x를 생성
    for(int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값: ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);                            // 배열 x의 값이 ky인 요소를 선형 검색
    if(idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
    free(x);                                                // 배열 x를 해제

    return 0;
}


// 이진 검색
#include <stdio.h>
#include <stdlib.h>

//요소의 개수가 n인 배열 a에서 ket와 일치하는 요소를 이진 검색
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
    puts("이진 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    printf("오름차순")
}
}