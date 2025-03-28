#include <stdio.h>

int main() {
    int itemNumber, maxWeight;
    // 사용자로부터 물품의 수와 배낭의 최대 무게를 입력받음
    scanf("%d %d", &itemNumber, &maxWeight);
    
    int itemWeight[100001], itemValue[1001];
    // itemWeight와 itemValue는 입력받은 값으로만 사용되므로 초기화가 필요 없음
    for(int i = 1; i <= itemNumber; i++) {
        scanf("%d %d", &itemWeight[i], &itemValue[i]);
    }

    int dp[100001] = {0}; // dp 배열 초기화, dp[w]는 무게 w에서의 최대 가치

    for(int i = 1; i <= itemNumber; i++) { // 각 물품을 하나씩 고려
        // 현재 물품을 고려하여 배낭의 무게를 역순으로 탐색
        for(int w = maxWeight; w >= itemWeight[i]; w--) {
            // dp[w - itemWeight[i]]: 현재 물품을 포함했을 때 남는 무게에서의 최대 가치
            // itemValue[i]: 현재 물품의 가치
            // dp[w]: 현재 물품을 포함하지 않았을 때의 최대 가치
            if(dp[w - itemWeight[i]] + itemValue[i] > dp[w]) {
                // 현재 물품을 포함했을 때의 가치가 더 크다면 dp[w]를 갱신
                dp[w] = dp[w - itemWeight[i]] + itemValue[i];
            }
        }
    }

    // 배낭의 최대 무게에서 얻을 수 있는 최대 가치를 출력
    printf("%d\n", dp[maxWeight]);
    return 0;
}