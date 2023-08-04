    #include <stdio.h>

    int bSearch(int ar[], int len, int target) {
        int first = 0;
        int end = (len - 1);
        int mid;
        int nCount = 0;

        // fisrt == end도 포함
        while (first <= end) {
            // 중간 값 구하기 {(처음 값 + 마지막 값) / 2 }
            mid = (first + end) / 2;

            // 중간 값이랑 찾는 목표가 같을 시 mid 인덱스 값 return
            if (target == ar[mid]) {
                return mid;
            }
            else {
                // 찾는 목표값과 중간에 있는 값 비교
                if (target < ar[mid]) {
                    // -1을 하는 이유 : 이미 맨위에 if에서 ad[mid]를 검사하기 때문이다 그리고 -1을 안해주면 first가 end 값보다 커진다.
                    end = mid - 1;
                }
                else {
                    first = mid + 1;
                }
                nCount += 1;
            }
        }

        printf("비교연산 횟수 : %d\n", nCount);
        return -1;
    }

    int main(void) {
        // 찾은 결과를 받는 변수(못 찾으면 -1 반환)
        int idx;
        int ar1[500] = {0, };
        int ar2[5000] = {0, };
        int ar3[50000] = {0, };

        // 배열, 배열의 사이즈, 찾을 목표
        idx = bSearch(ar1, sizeof(ar1)/sizeof(int), 1);
        // 찾는 목표가 없을 시
        if (idx == -1) {
            printf("탐색 실패\n");
        }
        // 찾는 목표의 인덱스 출력
        else {
            printf("타겟 저장 인덱스 :%d\n", idx);
        }

        idx = bSearch(ar2, sizeof(ar2)/sizeof(int), 1);
        if (idx == -1) {
            printf("탐색 실패\n");
        }
        else {
            printf("타겟 저장 인덱스 :%d\n", idx);
        }

        idx = bSearch(ar3, sizeof(ar3)/sizeof(int), 1);
        if (idx == -1) {
            printf("탐색 실패\n");
        }
        else {
            printf("타겟 저장 인덱스 :%d\n", idx);
        }

        return 0;
    }