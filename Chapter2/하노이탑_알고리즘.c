#include <stdio.h>

void hanoi (int num, char start, char mid, char end) {
    
    // 끝나는 조건
    if (num == 1) {
        printf("원반 %d을 %c에서 %c에서 이동했습니다.\n", num, start, end);
    }
    else {
        // 첫번째 조건 
        hanoi(num - 1, start, end, mid);
        // 두번째 조건 (첫 번째에 큰 원반을  맨끝으로 옮김)
        printf("원반 %d을 %c에서 %c에서 이동했습니다.\n", num, start, end);
        // 세번째 조건 (중간에 있는 원반을 끝으로 옮김)
        hanoi(num -1, mid, start, end);
    }
}

int main(void) {
    hanoi(3, 'A', 'B', 'C');

    return 0;
}