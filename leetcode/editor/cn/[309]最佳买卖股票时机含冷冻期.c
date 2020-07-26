//给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。 
//
// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
//
// 
// 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
// 
//
// 示例: 
//
// 输入: [1,2,3,0,2]
//输出: 3 
//解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
// Related Topics 动态规划

#include "stdlib.h"
//leetcode submit region begin(Prohibit modification and deletion)

int MAXProfit_UnlimitedK_WithFrozen(int* prices, int pricesSize) {
    int **dp = (int **)calloc(pricesSize + 1, sizeof(int *));
    for (int i = 0; i < pricesSize + 1; i++) {
        // 0 empty, 1 own shares, 2 frozen.
        dp[i] = (int *)calloc(3, sizeof(int));
    }

    dp[0][0] = 0;
    dp[0][1] = -2147483648;
    dp[0][2] = -2147483648;
    dp[1][2] = -2147483648;

    for (int i = 1; i <= pricesSize; i++) {
        dp[i][0] = (dp[i-1][0] > dp[i-1][2])? dp[i-1][0]: dp[i-1][2];
        dp[i][1] = (dp[i-1][1] > (dp[i-1][0] - prices[i-1]))? dp[i-1][1]: dp[i-1][0] - prices[i-1];

        dp[i][2] = dp[i-1][1] + prices[i-1];
    }

    int max_p = 0;
    max_p = (dp[pricesSize][0] > max_p)? dp[pricesSize][0]: max_p;
    max_p = (dp[pricesSize][2] > max_p)? dp[pricesSize][2]: max_p;
    return max_p;
}

int maxProfit(int* prices, int pricesSize){
    if (pricesSize < 2)
        return 0;
    return MAXProfit_UnlimitedK_WithFrozen(prices, pricesSize);
}


//leetcode submit region end(Prohibit modification and deletion)
