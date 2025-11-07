// 202530212 박 세림
// 11월 06일 강의
// 10월 31일 강의
// 10월 30일 강의

// 스택
// 초기화 함수
// - 스태그이 메모리 공간(배열)을 확보하는 등의 준비 작업을 수행하는 함수
// 1. 배열을 위한 메모리 공간을 만들 떄 스택은 비어 있어야(데이터가 하나도 쌓여 있지 않은 상태여야) 하므로 스택 포인터 ptr 값을 0으로 함.
// 2. 요소의 개수가 max인 배열 stk를 생성함. 이때, 스택의 개별 요소에 접근하는 인덱스 식은 바닥(bottom)부터 stk[0], stk[1], ..., stk[max-1]이 됨.
// 3. 매개변수 max로 받은 값을 스택 최대 용량을 나타내는 구조체의 멤버 max에 저장.
/*#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

//--- 스택 초기화 (Initialize) ---
int Initialize(IntStack *s, int max) {
    s->ptr = 0;
    s->stk = (int*)calloc(max, sizeof(int));
    if (s->stk == NULL) {
        s->max = 0;
        return -1; // 메모리 할당 실패
    }
    s->max = max;
    return 0; // 성공
}

//--- 스택에 데이터를 푸시 (Push) ---
int Push(IntStack *s, int x) {
    if (s->ptr >= s->max)
        return -1; // Overflow
    s->stk[s->ptr++] = x;
    return 0;
}

//--- 스택에서 데이터를 팝 (Pop) ---
int Pop(IntStack *s, int *x) {
    if (s->ptr <= 0)
        return -1; // Underflow
    *x = s->stk[--s->ptr];
    return 0;
}

//--- 스택에서 데이터를 피크 (Peek) ---
int Peek(const IntStack *s, int *x) {
    if (s->ptr <= 0)
        return -1; // 스택 비어 있음
    *x = s->stk[s->ptr - 1];
    return 0;
}

//--- 스택 비우기 (Clear) ---
void Clear(IntStack *s) {
    s->ptr = 0;
}

//--- 스택의 최대 용량 (Capacity) ---
int Capacity(const IntStack *s) {
    return s->max;
}

//--- 스택의 데이터 개수 (Size) ---
int Size(const IntStack *s) {
    return s->ptr;
}

//--- 스택이 비어 있나요? (IsEmpty) ---
int IsEmpty(const IntStack *s) {
    return (s->ptr <= 0) ? 1 : 0;
}

//--- 스택이 가득 찼나요? (IsFull) ---
int IsFull(const IntStack *s) {
    return (s->ptr >= s->max) ? 1 : 0;
}

//--- 스택에서 검색 (Search) ---
int Search(const IntStack *s, int x) {
    for (int i = s->ptr - 1; i >= 0; i--) {
        if (s->stk[i] == x)
            return s->ptr - i; // top으로부터의 거리 반환 (1부터 시작)
    }
    return -1; // 찾지 못함
}

//--- 스택의 모든 데이터를 출력 (Print) ---
void Print(const IntStack *s) {
    if (IsEmpty(s)) {
        puts("스택은 비어 있습니다.");
    } else {
        printf("Bottom -> Top: [");
        for (int i = 0; i < s->ptr; i++) {
            printf("%d", s->stk[i]);
            if (i < s->ptr - 1)
                printf(", ");
        }
        printf("]\n");
    }
}

//--- 스택 종료 및 메모리 해제 (Terminate) ---
void Terminate(IntStack *s) {
    free(s->stk); // 동적 할당 메모리 해제
    s->max = s->ptr = 0;
    s->stk = NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h" // IntStack 헤더 파일 포함

int main(void) {
    IntStack s;
    int menu, x;

    // 스택 초기화 (용량 64로 가정)
    if (Initialize(&s, 64) == -1) {
        puts("스택 생성에 실패했습니다.");
        return 1;
    }

    while (1) {
        printf("\n현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
        // 메뉴 확장: (1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6)비우기 (7)정보 (0)종료
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6)비우기 (7)정보 (0)종료: ");
        scanf("%d", &menu);

        if (menu == 0)
            break;

        switch (menu) {
            case 1: { // 푸시
                printf("데이터: ");
                scanf("%d", &x);
                if (Push(&s, x) == -1)
                    puts("\a오류: 푸시에 실패했습니다. (스택 가득 참)");
                break;
            }
            case 2: { // 팝
                if (Pop(&s, &x) == -1)
                    puts("\a오류: 팝에 실패했습니다. (스택 비어 있음)");
                else
                    printf("팝 데이터는 %d입니다.\n", x);
                break;
            }
            case 3: { // 피크
                if (Peek(&s, &x) == -1)
                    puts("\a오류: 피크에 실패했습니다. (스택 비어 있음)");
                else
                    printf("피크 데이터는 %d입니다.\n", x);
                break;
            }
            case 4: { // 출력
                puts("--- 스택 내용 ---");
                Print(&s);
                break;
            }
            case 5: { // 검색
                printf("검색할 데이터: ");
                scanf("%d", &x);
                int idx = Search(&s, x);
                if (idx == -1)
                    printf("%d은(는) 스택에 없습니다.\n", x);
                else
                    printf("%d은(는) top에서 %d번째에 있습니다.\n", x, idx);
                break;
            }
            case 6: { // 비우기
                Clear(&s);
                puts("스택을 비웠습니다.");
                break;
            }
            case 7: { // 정보
                printf("최대 용량: %d\n", Capacity(&s));
                printf("현재 데이터 수: %d\n", Size(&s));
                printf("스택 상태: %s\n", IsEmpty(&s) ? "비어 있음" : IsFull(&s) ? "가득 참" : "사용 중");
                break;
            }
            default:
                puts("\a올바른 메뉴를 선택하세요.");
                break;
        }
    }

    // 프로그램 종료 시 메모리 해제
    Terminate(&s);
    puts("스택을 종료합니다.");
    
    return 0;
}


// 큐
// IntQueue.c

#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

//--- 큐 초기화 (Initialize) ---
int Initialize(IntQueue *q, int max) {
    q->num = q->front = q->rear = 0;
    q->que = (int*)calloc(max, sizeof(int));
    if (q->que == NULL) {
        q->max = 0;
        return -1; // 메모리 할당 실패
    }
    q->max = max;
    return 0; // 성공
}

//--- 큐에 데이터를 인큐 (EnQueue) ---
int EnQueue(IntQueue *q, int x) {
    if (q->num >= q->max)
        return -1; // Overflow
    
    q->que[q->rear++] = x; // 데이터 저장 후 rear 증가
    q->num++;              // 요소 개수 증가
    
    // rear가 최대 용량에 도달하면 맨 앞으로 돌아감 (링 버퍼)
    if (q->rear == q->max)
        q->rear = 0;
        
    return 0; // 성공
}

//--- 큐에서 데이터를 디큐 (DeQueue) ---
int DeQueue(IntQueue *q, int *x) {
    if (q->num <= 0)
        return -1; // Underflow
    
    *x = q->que[q->front++]; // front 요소 반환 후 front 증가
    q->num--;                // 요소 개수 감소

    // front가 최대 용량에 도달하면 맨 앞으로 돌아감 (링 버퍼)
    if (q->front == q->max)
        q->front = 0;
        
    return 0;
}

//--- 큐에서 데이터를 피크 (Peek) ---
int Peek(const IntQueue *q, int *x) {
    if (q->num <= 0)
        return -1; // 큐 비어 있음
    
    *x = q->que[q->front]; // front 요소 반환
    return 0;
}

//--- 큐 비우기 (Clear) ---
void Clear(IntQueue *q) {
    q->num = q->front = q->rear = 0;
}

//--- 큐의 최대 용량 (Capacity) ---
int Capacity(const IntQueue *q) {
    return q->max;
}

//--- 큐의 데이터 개수 (Size) ---
int Size(const IntQueue *q) {
    return q->num;
}

//--- 큐가 비어 있나요? (IsEmpty) ---
int IsEmpty(const IntQueue *q) {
    return (q->num <= 0) ? 1 : 0;
}

//--- 큐가 가득 찼나요? (IsFull) ---
int IsFull(const IntQueue *q) {
    return (q->num >= q->max) ? 1 : 0;
}

//--- 큐에서 검색 (Search) ---
// 찾으면 배열 인덱스를 반환, 못 찾으면 -1 반환 (교재의 방식에 따름)
int Search(const IntQueue *q, int x) {
    for (int i = 0; i < q->num; i++) {
        // 실제 배열 인덱스 계산: (시작 위치 + 논리적 위치) % 최대 용량
        int idx = (q->front + i) % q->max;
        if (q->que[idx] == x)
            return idx; // 검색 성공 (배열 인덱스 반환)
    }
    return -1; // 검색 실패
}

//--- 모든 데이터를 출력 (Print) ---
void Print(const IntQueue *q) {
    int i;
    int idx;
    
    printf("큐: [");
    for (i = 0; i < q->num; i++) {
        idx = (q->front + i) % q->max; 
        printf("%d", q->que[idx]);
        if (i < q->num - 1)
            printf(", ");
    }
    printf("]\n");
}

//--- 큐 종료 및 메모리 해제 (Terminate) ---
void Terminate(IntQueue *q) {
    if (q->que != NULL) {
        free(q->que); // 메모리 해제
    }
    q->max = q->num = q->front = q->rear = 0; 
    q->que = NULL;
}

// IntQueueTest.c

#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h" // IntQueue 헤더 파일 포함

int main(void) {
    IntQueue que;
    int menu, x;
    
    // 큐 초기화 (용량 64로 가정)
    if (Initialize(&que, 64) == -1) {
        puts("큐 생성에 실패했습니다.");
        return 1;
    }
    
    while (1) {
        printf("\n현재 데이터 수: %d / %d\n", Size(&que), Capacity(&que));
        // 메뉴 확장: (1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색 (6)비우기 (7)정보 (0)종료
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)검색 (6)비우기 (7)정보 (0)종료: ");
        scanf("%d", &menu);

        if (menu == 0)
            break;

        switch (menu) {
            case 1: { // 인큐
                printf("데이터: ");
                scanf("%d", &x);
                if (EnQueue(&que, x) == -1)
                    puts("\a오류: 인큐에 실패했습니다. (큐 가득 참)");
                break;
            }
            case 2: { // 디큐
                if (DeQueue(&que, &x) == -1)
                    puts("\a오류: 디큐에 실패했습니다. (큐 비어 있음)");
                else
                    printf("디큐한 데이터는 %d입니다.\n", x);
                break;
            }
            case 3: { // 피크
                if (Peek(&que, &x) == -1)
                    puts("\a오류: 피크에 실패했습니다. (큐 비어 있음)");
                else
                    printf("피크한 데이터는 %d입니다.\n", x);
                break;
            }
            case 4: { // 큐 출력
                Print(&que);
                break;
            }
            case 5: { // 검색
                printf("검색할 데이터: ");
                scanf("%d", &x);
                int idx = Search(&que, x);
                
                if (idx == -1)
                    printf("%d은(는) 큐에 없습니다.\n", x);
                else
                    printf("%d은(는) 배열 인덱스 %d 위치에 있습니다.\n", x, idx);
                break;
            }
            case 6: { // 큐 비우기
                Clear(&que); 
                puts("큐를 비웠습니다.");
                break;
            }
            case 7: { // 정보출력
                printf("최대 용량: %d\n", Capacity(&que));
                printf("현재 데이터 수: %d\n", Size(&que));
                printf("큐 상태: %s\n", IsEmpty(&que) ? "비어 있음" : IsFull(&que) ? "가득 참" : "사용 중");
                break;
            }
            default:
                puts("\a올바른 메뉴를 선택하세요.");
                break;
        }
    }

    // 프로그램 종료 시 메모리 해제
    Terminate(&que);
    puts("큐를 종료합니다.");
    
    return 0;
}


// 버블 정렬
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    int i, j;
    int temp; // 교환을 위한 임시 변수

    // 바깥쪽 루프: 총 n-1 번의 '패스(Pass)'를 수행
    for (i = 0; i < n - 1; i++) {
        // 안쪽 루프: 인접한 원소들을 비교하고 교환
        // i가 증가할수록 배열의 끝에는 정렬된 원소가 쌓이므로, 비교 범위가 줄어든다.
        for (j = 0; j < n - 1 - i; j++) {
            // 오름차순 정렬: 현재 원소가 다음 원소보다 크면 교환
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int data[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(data) / sizeof(data[0]); // 배열의 크기 계산

    printf("--- 버블 정렬 (오름차순) ---\n");
    
    // 정렬 전 배열 출력
    printf("정렬 전: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // 버블 정렬 함수 호출
    bubble_sort(data, n);

    // 정렬 후 배열 출력
    printf("정렬 후: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    return 0;
}

// 단순 선택 정렬
// 아직 정렬하지 않은 부분에서 값이 가장 작은 요소를 선택하고 아직 정렬하지 않은 부분의 첫 번째 요소와 교환
void selection(int a[], int n) {
    for(int i = 0; i <n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);    
    }
}

// 단순 삽입 정렬
#include <stdio.h>
#include <stdlib.h>

// 단순 삽입 정렬 함수
void intsertion(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;
        for(j = i; j > 0 && a[j - 1] > tmp; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
    }
}

int main(void) {
    int nx;
    puts("단순 삽입 정렬");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));

    for(int i = 0; i< nx; i++) {
        printf("x[%d]: ", i);
    scanf("%d", &x[i]);
    }

    intsertion(x, nx);

    puts("오름차순으로 정렬했습니다.");
    for(int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    
    free(x);

    return 0;
}*/

// 퀵 정렬
#include <stdio.h>
#include <stdlib.h> // calloc, free 함수를 사용하기 위해 필요

// 퀵 정렬에서 두 원소의 위치를 교환하는 함수 (swap)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 파티션(Partition) 함수: 피벗을 기준으로 배열을 나누는 역할
// L: 배열의 시작 인덱스, R: 배열의 끝 인덱스
int partition(int arr[], int L, int R) {
    int pivot = arr[R]; // 가장 오른쪽 원소를 피벗으로 선택
    int i = L - 1; // 피벗보다 작은 요소들의 경계 (작은 요소가 들어갈 위치)

    // L부터 R-1까지 순회하며 피벗과 비교
    for (int j = L; j <= R - 1; j++) {
        // 현재 원소가 피벗보다 작거나 같으면
        if (arr[j] <= pivot) {
            i++; // 경계를 증가시키고
            swap(&arr[i], &arr[j]); // arr[j]를 작은 요소 영역으로 이동 (교환)
        }
    }
    // 루프가 끝난 후, 피벗을 i+1 위치(작은 요소 영역 바로 다음)로 이동
    swap(&arr[i + 1], &arr[R]);
    
    // 최종적으로 피벗이 위치한 인덱스를 반환
    return (i + 1);
}

// 퀵 정렬 (quick) 함수
// arr: 배열, L: 시작 인덱스, R: 끝 인덱스
void quick(int arr[], int L, int R) {
    if (L < R) { // 정렬할 원소가 2개 이상일 때만 수행
        // 1. 파티션: 배열을 피벗을 기준으로 두 부분으로 나눔
        int pivot_index = partition(arr, L, R);

        // 2. 재귀 호출: 피벗의 왼쪽 부분 정렬
        quick(arr, L, pivot_index - 1);

        // 3. 재귀 호출: 피벗의 오른쪽 부분 정렬
        quick(arr, pivot_index + 1, R);
    }
}

// 이미지에 나타난 main 함수 구조를 따름
int main(void) {
    int nx;
    
    puts("퀵 정렬");
    printf("요소의 개수 입력 : ");
    scanf("%d", &nx); // nx: 요소의 개수

    // nx 개의 정수형(int) 배열을 동적으로 할당 (calloc은 메모리를 0으로 초기화)
    int *x = (int *)calloc(nx, sizeof(int));

    // 사용자로부터 배열 요소 입력 받기
    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    // 배열 x에 대해 퀵 정렬 수행
    // quick(배열, 시작 인덱스, 끝 인덱스)
    // 시작 인덱스: 0, 끝 인덱스: nx - 1
    quick(x, 0, nx - 1); 

    puts("오름차순으로 정렬했습니다.");
    
    // 정렬된 배열 출력
    for (int i = 0; i < nx; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }

    // 동적으로 할당된 메모리 해제
    free(x); 
    
    return 0;
}

// 병합 정렬

// 힙 정렬
