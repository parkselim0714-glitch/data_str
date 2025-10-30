// 202530212 박 세림

// 10월 30일 강의

// IntStack.h
#ifndef __INTSTACK_H
#define __INTSTACK_H

// 스택을 구현하는 구조체
typedef struct {
    int max;    // 스택 용량 (최대 요소 개수)
    int ptr;    // 스택 포인터 (다음에 push할 요소의 인덱스)
    int *stk;   // 스택의 첫 요소에 대한 포인터 (실제 배열)
} IntStack;

// 스택 초기화
int Initialize(IntStack *s, int max);

// 스택에 데이터를 푸시
int Push(IntStack *s, int x);

// 스택에서 데이터를 팝
int Pop(IntStack *s, int *x);

// 스택에서 데이터를 피크
int Peek(const IntStack *s, int *x);

// 스택 비우기
void Clear(IntStack *s);

// 스택의 최대 용량
int Capacity(const IntStack *s);

// 스택의 데이터 개수
int Size(const IntStack *s);

// 스택이 비어 있나요?
int IsEmpty(const IntStack *s);

// 스택이 가득 찼나요?
int IsFull(const IntStack *s);

// 스택에서 검색 (top에서부터의 거리 반환)
int Search(const IntStack *s, int x);

// 스택의 모든 데이터 출력
void Print(const IntStack *s); // 이미지 4에 포함된 함수

// 스택 종료 및 메모리 해제
void Terminate(IntStack *s); // 이미지 4에 포함된 함수

#endif /* __INTSTACK_H */