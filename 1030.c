// 202530212 박 세림

// 10월 30일 강의

// 스택
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
}*/


// 버블 정렬
