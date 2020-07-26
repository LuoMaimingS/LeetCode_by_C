//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。 
//
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 示例 1: 
//
// 输入: [2,4,1], k = 2
//输出: 2
//解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
// 
//
// 示例 2: 
//
// 输入: [3,2,6,5,0,3], k = 2
//输出: 7
//解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 
//。
// 
// Related Topics 动态规划

#include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
int MAXProfit_UnlimitedK(int* prices, int pricesSize) {
    int **dp = (int **)calloc(pricesSize + 1, sizeof(int *));
    for (int i = 0; i < pricesSize + 1; i++) {
        dp[i] = (int *)calloc(2, sizeof(int));
    }

    dp[0][0] = 0;
    dp[0][1] = -2147483648;

    for (int i = 1; i <= pricesSize; i++) {
        dp[i][0] = (dp[i-1][0] > (dp[i-1][1] + prices[i-1]))? dp[i-1][0]: dp[i-1][1] + prices[i-1];
        dp[i][1] = (dp[i-1][1] > (dp[i-1][0] - prices[i-1]))? dp[i-1][1]: dp[i-1][0] - prices[i-1];
    }

    int max_p = 0;
    max_p = (dp[pricesSize][0] > max_p)? dp[pricesSize][0]: max_p;
    return max_p;
}

int MAXProfit_limitedK(int* prices, int pricesSize, int k) {
    int ***dp = (int ***)calloc(pricesSize + 1, sizeof(int **));
    for (int i = 0; i < pricesSize + 1; i++) {
        dp[i] = (int **)calloc(k + 1, sizeof(int * ));
        for (int j = 0; j < k + 1; j++) {
            dp[i][j] = (int *)calloc(2, sizeof(int));
        }
    }

    for (int j = 0; j < k + 1; j++) {
        dp[0][j][0] = 0;
        dp[0][j][1] = -2147483648;
    }

    for (int i = 1; i <= pricesSize; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = (dp[i-1][j][0] > (dp[i-1][j][1] + prices[i-1]))? dp[i-1][j][0]: dp[i-1][j][1] + prices[i-1];
            if (j == k) {
                dp[i][j][1] = -2147483648;
            } else {
                dp[i][j][1] = (dp[i-1][j][1] > (dp[i-1][j+1][0] - prices[i-1]))? dp[i-1][j][1]: dp[i-1][j+1][0] - prices[i-1];
            }
        }
    }

    int max_p = 0;
    for (int j = 0; j <= k; j++) {
        max_p = (dp[pricesSize][j][0] > max_p)? dp[pricesSize][j][0]: max_p;
    }
    return max_p;
}

int maxProfit(int k, int* prices, int pricesSize){
    if (k >= (int)(pricesSize / 2)) {
        return MAXProfit_UnlimitedK(prices, pricesSize);
    } else {
        return MAXProfit_limitedK(prices, pricesSize, k);
    }
}


//leetcode submit region end(Prohibit modification and deletion)
