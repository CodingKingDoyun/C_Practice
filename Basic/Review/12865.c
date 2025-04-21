//https://www.acmicpc.net/problem/12865
#include <stdio.h>
#include <string.h> // memset 함수 사용을 위해 포함

int main() {
    int itemNumber, maxWeight;
    // 사용자로부터 아이템 개수와 최대 무게를 입력받음
    scanf("%d %d", &itemNumber, &maxWeight);
    
    // 아이템의 무게와 가치를 저장할 배열 선언
    int itemWeight[100001], itemValue[1001];
    for(int i = 1; i <= itemNumber; i++) {
        // 각 아이템의 무게와 가치를 입력받음
        scanf("%d %d", &itemWeight[i], &itemValue[i]);
    }

    // dp 배열 선언 및 0으로 초기화
    // dp[w]는 무게 w를 초과하지 않는 상태에서 얻을 수 있는 최대 가치를 저장
    int dp[maxWeight + 1];
    memset(dp, 0, sizeof(dp)); // dp 배열을 0으로 초기화
    
    // 각 아이템에 대해 반복
    for(int i = 1; i <= itemNumber; i++) {
        // 현재 아이템을 포함하는 경우를 고려
        // 무게를 역순으로 순회하여 중복 계산 방지
        for(int w = maxWeight; w >= itemWeight[i]; w--) {
            // 현재 아이템을 포함했을 때의 가치가 더 크다면 dp 값을 갱신
            if(dp[w - itemWeight[i]] + itemValue[i] > dp[w]) {
                dp[w] = dp[w - itemWeight[i]] + itemValue[i];
            }
        }
    }

    // 최대 무게에서 얻을 수 있는 최대 가치를 출력
    printf("%d\n", dp[maxWeight]);
    return 0;
}