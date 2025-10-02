// 202530212 박세림
// 10월 02일 강의

// 배열 요소를 역순으로 정렬
/*#include <stdio.h>
#include <stdlib.h>

// type형 x값과 y값을 교환
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

// 요소 개수가 n인 배열 a의 요소를 역수능로 정렬
void ary_reverse(int a[], int n) {
    for(int i = 0; i < n / 2; i++) 
    swap(int, a[i], a[n-i-1]);
}*/


// 배열 요소를 역순으로 정리하는 프로그램
/*#include <stdio.h>
#include <stdlib.h>                                     // calloc 때문에 쓰는 거임      


int main(void) {
    int nx;                                             // 배열 x의 요소 개수

    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for(int i = 0; i < nx; i++) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    ary_reverse(x, nx);                                 // 배열 x의 요소를 역순으로 정렬
    printf("배열의 요소를 역순으로 정렬했습니다.\n");
    for(int i = 0; i < nx; i++)
        printf("x[%d] = %d\n", i, x[i]);
    free(x);                                             // 배열 x를 해제

    return 0;
}*/


// 기수 변환을 수행하는 프로그램
/*#include <stdio.h>

int main(void) {
    puts("10진수를 기수 변환합니다.");

    int retry;                                              // ?븳 踰? ?뜑?

    do{
        unsigned no;                                        // 蹂??솚?븯?뒗 ?젙?닔
        int      cd;                                        // 湲곗닔 
        printf(("변환하는 음이 아닌 정수: "));                // 蹂??솚?븳 媛믪쓽 媛? ?옄由ъ쓽 ?닽?옄瑜? ????옣?븯?뒗 臾몄옄 諛곗뿴
        scanf("%u", &no);

        do{
            printf("어떤 진수로 변환할까요?(2-36): ");
            scanf("%d", &cd);
        } while(cd < 2 || cd > 36);

        int dno = card_conv(no, cd, cno);                   // no瑜? dno?옄由ъ쓽 cd吏꾩닔濡? 蹂??솚

        printf("%d진수로", cd);
        for(int i = 0; i < dno; i++)                        // 媛? ?옄由ъ쓽 臾몄옄瑜? 李⑤??濡? 異쒕젰
            printf("%c", cno[i]);
        printf("입니다.\n")

        printf("한 번 더 할까요?(1...예/0...아니오): ");
        scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}*/


// 1,000 이하의 소수를 나열(버전 1)
/*#include <stdio.h>

int main(void) {
    unsigned long counter =0;                           // ?굹?닓?뀍 ?슏?닔
    for(int n = 2; n <= 1000; n++) {
        int i;
        for(i = 2; i < n; i++) {
            counter++;
            if(n % i == 0)                              // ?굹?늻?뼱?뼥?뼱吏?硫? ?냼?닔媛? ?븘?떂
                break;                                  // ?뜑 ?씠?긽?쓽 諛섎났??? 遺덊븘?슂
        }
        if(n == i)                                      // 留덉??留됯퉴吏? ?굹?늻?뼱?뼥?뼱吏?吏? ?븡?쓬
            printf("%d\n", n);
    }
    printf("나눗셈을 실행한 횟수: %lu\n", counter);

    return 0;
}*/


// 1,000 이하의 소수를 나열(버전 2)
/*#include <stdio.h>

int main(void) {
    int prime[500];                         // ?냼?닔瑜? ????옣?븯?뒗 諛곗뿴
    int ptr = 0;                            // ?씠誘? ?뼸??? ?냼?닔?쓽 媛쒖닔
    unsigned long counter = 0;              // ?굹?닓?뀍 ?슏?닔
    prime[ptr++] = 2;                       // 2?뒗 ?냼?닔?엯?땲?떎.
    for(int n = 3; n <= 1000; n += 2) {     // ????닔留뚯쓣 ????긽
        int i;
        for(i = 1; i < ptr; i++) {          // ?씠誘? ?뼸??? ?냼?닔濡? ?굹?닎
            counter++;
            if(n % prime[i] == 0)           // ?굹?늻?뼱?뼥?뼱吏?誘?濡? ?냼?닔媛? ?븘?떂
                break;                      // ?뜑 ?씠?긽?쓽 諛섎났??? 遺덊븘?슂
        }
        if(ptr ==i)                         // 留덉??留됯퉴吏? ?굹?늻?뼱?뼥?뼱吏?吏? ?븡?븯?떎硫?
            prime[ptr++] = n;               // 諛곗뿴?뿉 ????옣
    }
    for(int i = 0; i < ptr; i++)
        printf("%d\n", prime[i]);
    printf("나눗셈을 실행한 횟수: %lu\n", counter);

    return 0;
}*/


// 1,000 이하의 소수를 나열(버전 3)
/*#include <stdio.h>

int main(void) {
    int prime[500];                                                 // ?냼?닔瑜? ????옣?븯?뒗 諛곗뿴
    int ptr = 0;                                                    // ?씠誘? ?뼸??? ?냼?닔?쓽 媛쒖닔
    unsigned long counter = 0;                                      // 怨깆뀍怨? ?굹?닓?뀍?쓽 ?떎?뻾 ?슏?닔
    prime[ptr++] = 2;                                               // 2?뒗 ?냼?닔
    prime[ptr++] = 3;                                               // 3??? ?냼?닔
    for(int n = 5; n <= 1000; n += 2) {                             // ????닔留뚯쓣 ????긽
        int i;
        int flag = 0;
        for(i = 1; counter++, prime[i] * prime[i] <= n; i++) {
            counter++;
            if(n % prime[i] == 0) {                                 // ?굹?늻?뼱?뼥?뼱吏?硫? ?냼?닔媛? ?븘?떂
                flag = 1;
                break;                                              // ?뜑 ?씠?긽?쓽 諛섎났??? 遺덊븘?슂
            }
        }
        if(! flag)                                                   // 留덉??留됯퉴吏? ?굹?늻?뼱?뼥?뼱吏?吏? ?븡?쓬
            prime[ptr++] = n;                                        // 諛곗뿴?뿉 ????옣
    }
}*/


// 한 해의 지난 날 수를 구하여 출력
#include <stdio.h>

// 각 달의 날 수
int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// year년이 윤년인가?
int isleap(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

// y년 m월 d일의 그 해 지난 날 수를 구함
int dayof_year(int y, int m,int d) {
    int days = d;                                                                   // 날 수
    for(int i = 1; i < m; i++)
        days += mdays[isleap(y)][i - 1];
    return days;
}

int main(void) {
    int retry;                                                                      // 다시?
    do {
        int year, month, day;                                                       // 년, 월, 일
        printf("?뀈: "); scanf("%d", &year);
        printf("?썡: "); scanf("%d", &year);
        printf("?씪: "); scanf("%d", &year);
        printf("%d?뀈?쓽 %d?씪吏몄엯?땲?떎.\n: ", year, dayof_year(year, month, day));
        printf("?떎?떆 ?븷源뚯슂?(1...?삁/0...?븘?땲?삤): "); scanf("%d", &retry);
    } while(retry == 1);

    return 0;
}