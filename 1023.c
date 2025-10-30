// 202530212 박 세림
// 10월 23일 강의

// 선형 검색
/*#include <stdio.h>
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
}*/


// 이진 검색
#include <stdio.h>
#include <stdlib.h>

//요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 이진 검색
int bin_search(const int a[], int n, int key) {
    int pl = 0;
    int pr = n - 1;

    do {
        int pc = (pl + pr) / 2;
        if(a[pc] == key)
            return pc; // 검색 성공 (인덱스 반환)
        else if(a[pc] < key)
            pl = pc + 1; // 검색 범위를 오른쪽 절반으로 좁힘
        else
            pr = pc - 1; // 검색 범위를 왼쪽 절반으로 좁힘
    } while(pl <= pr);
    
    return -1; // 검색 실패
}

int main(void) {
    int nx; // 요소 개수
    int ky; // 검색할 키 값
    int idx; // 검색 결과 인덱스

    puts("이진 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    
    // 배열 동적 할당
    int *x = calloc(nx, sizeof(int));
    if (x == NULL) {
        puts("메모리 할당에 실패했습니다.");
        return 1;
    }

    printf("오름차순으로 입력하세요.\n");
    // 배열 요소 입력 받기 (오름차순 보장 필요)
    for (int i = 0; i < nx; i++) {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
            // 오름차순 검사 (단순화를 위해 첫 요소는 무조건 입력, 이후 요소는 이전 요소보다 크거나 같아야 함)
        } while (i > 0 && x[i] < x[i-1]); 
    }

    // 검색할 키 값 입력 받기
    printf("검색할 값: ");
    scanf("%d", &ky);
    
    // 이진 검색 함수 호출
    idx = bin_search(x, nx, ky);

    // 결과 출력
    if (idx == -1) {
        puts("검색에 실패했습니다.");
    } else {
        printf("%d은(는) x[%d]에 있습니다.\n", ky, idx);
    }

    // 동적 할당 해제
    free(x);
    
    return 0;
}