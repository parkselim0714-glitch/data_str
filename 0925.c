// 202530212 박 세림
// 9월 25일 강의

// int[5]형 배열(자료형이 int형이고 요소가 5개)에 값을 입력해 출력

/*#define N 5                               // 배열의 요소 개수
int main() {
    int a[N];                               // 배열의 선언
    for(int i = 0; i < N; i++) {            // 각 요소에 값을 입력
        printf("a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    puts("각 요소의 값");
    for(int i = 0; i < N; i++) {            // 각 요소의 값을 입력
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}*/


// int형 배열을 초기화하고 출력

/*#include <stdio.h>

int main(void) {
    int a[5] = {13, 42, 53, 134, 25};       // 요소의 개수
    int na = sizeof(a) / sizeof(int);              
    printf("배열 a의 요소 개수는 %d입니다.\n", na);
    
    for(int i = 0; i < na; i++)
        printf("a[%d] = %d\n", i, a[i]);
    
    return 0;
}*/


// int형 객체를 동적으로 생성하고 해체

/*#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *X = calloc(1, sizeof(int));
    if(X == NULL)
        puts("메모리 할당에 실패했습니다.");
    else {
        *X = 57;
        printf("*X = %d\n", *X);
        free(X);
    }

    return 0;
}*/


// int형 배열을 동적으로 생성하고 해제

/*#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int el_num;
    printf("요소 개수 : ");
    scanf("%d", &el_num);
    int*a = calloc(el_num, sizeof(int));

    if (a==NULL)
        puts("메모리 확보에 실패했습니다.");
    else{
        printf("초기화 상태 확인.\n", el_num);
        for (int i = 0; i < el_num; i++){
            printf("a[%d] = %d\n", i, a[i]);
        }
        
        printf("%d개의 정수를 입력하세요.\n", el_num);
        for (int i = 0; i < el_num; i++){
            printf("a[%d] : ", i);
            scanf("%d", &a[i]);
        }
        printf("각 요소값은 아래와 같습니다.\n");
        for (int i = 0; i < el_num; i++)
            printf("a[%d] = %d\n", i, a[i]);
        free(a);
    }
    
    return 0;
}*/


// 배열 요소의 최댓값을 구하고 출력(요소값 입력)

#include <stdio.h>
#include <stdlib.h>

/*-- 요소 개수가 n인 배열 a의 요소의 최댓값 --*/
int maxof(const int a[], int elem_cnt) {

    int max = a[0];                                 // 최댓값
    for(int i = 1; i < elem_cnt; i++) 
        if(a[i] > max) max = a[i];
    return max;
}

int main(void) {

    int number;                                     // 인원 = 배열 height의 요소 개수
    printf("사람 수: ");
    scanf("%d", &number);
    int *height = calloc(number, sizeof(int));      // 요소 개수 number 개인 배열을 생성
    printf("%d명의 키를 입력하세요.\n", number);
    for(int i = 0; i < number; i++) {
        printf("height[%d]: ", i);
        scanf("%d", &height[i]);
    }
    printf("최댓값은 %d입니다.\n", maxof(height, number));
    free(height);                                   // 배열 height를 해제

    return 0;
}

