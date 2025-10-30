// 202530212 박 세림

// 10월 30일 강의

// IntQueue.h
#ifndef __INTQUEUE_H
#define __INTQUEUE_H

#include <stdlib.h> // calloc, free 사용을 위해 필요

// 큐를 구현하는 구조체
typedef struct {
    int max;    // 큐 용량 (최대 요소 개수)
    int num;    // 현재 데이터 수
    int front;  // 프런트 (가장 먼저 나올 요소의 인덱스)
    int rear;   // 리어 (가장 나중에 들어온 요소의 다음 인덱스)
    int *que;   // 큐의 첫 요소에 대한 포인터 (실제 배열)
} IntQueue;

// 큐 초기화
int Initialize(IntQueue *q, int max);

// 큐에 데이터를 인큐 (EnQueue)
int EnQueue(IntQueue *q, int x);

// 큐에서 데이터를 디큐 (DeQueue) (Pop과 유사)
int DeQueue(IntQueue *q, int *x);

// 큐에서 데이터를 피크 (Peek) (프런트 요소 확인)
int Peek(const IntQueue *q, int *x);

// 큐 비우기
void Clear(IntQueue *q);

// 큐의 최대 용량
int Capacity(const IntQueue *q);

// 큐의 데이터 개수
int Size(const IntQueue *q);

// 큐가 비어 있나요?
int IsEmpty(const IntQueue *q);

// 큐가 가득 찼나요?
int IsFull(const IntQueue *q);

// 큐에서 검색 (Search: 배열 인덱스 또는 front로부터의 거리 반환)
int Search(const IntQueue *q, int x);

// 큐의 모든 데이터 출력
void Print(const IntQueue *q);

// 큐 종료 및 메모리 해제
void Terminate(IntQueue *q);

#endif /* __INTQUEUE_H */