//给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。 
//
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。 
//
// 返回获得利润的最大值。 
//
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。 
//
// 示例 1: 
//
// 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出: 8
//解释: 能够达到的最大利润:  
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8. 
//
// 注意: 
//
// 
// 0 < prices.length <= 50000. 
// 0 < prices[i] < 50000. 
// 0 <= fee < 50000. 
// 
// Related Topics 贪心算法 数组 动态规划

#include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
int MAXProfit_UnlimitedK_WithFee(int* prices, int pricesSize, int fee) {
    int **dp = (int **)calloc(pricesSize + 1, sizeof(int *));
    for (int i = 0; i < pricesSize + 1; i++) {
        dp[i] = (int *)calloc(2, sizeof(int));
    }

    dp[0][0] = 0;
    dp[0][1] = -2147483648;

    for (int i = 1; i <= pricesSize; i++) {
        dp[i][0] = (dp[i-1][0] > (dp[i-1][1] + prices[i-1]))? dp[i-1][0]: dp[i-1][1] + prices[i-1];
        dp[i][1] = (dp[i-1][1] > (dp[i-1][0] - prices[i-1] - fee))? dp[i-1][1]: dp[i-1][0] - prices[i-1] - fee;
    }

    int max_p = 0;
    max_p = (dp[pricesSize][0] > max_p)? dp[pricesSize][0]: max_p;
    return max_p;
}

int MAXProfit_UnlimitedK_WithFee_ReduceSpace(int* prices, int pricesSize, int fee) {
    int dp_0 = 0;
    int dp_1 = -2147483648;

    for (int i = 1; i <= pricesSize; i++) {
        int ldp_0 = dp_0, ldp_1 = dp_1;
        dp_0 = (ldp_0 > (ldp_1 + prices[i-1]))? ldp_0: ldp_1 + prices[i-1];
        dp_1 = (ldp_1 > (ldp_0 - prices[i-1] - fee))? ldp_1: ldp_0 - prices[i-1] - fee;
    }

    int max_p = 0;
    max_p = (dp_0 > max_p)? dp_0: max_p;
    return max_p;
}

int maxProfit(int* prices, int pricesSize, int fee){
    return MAXProfit_UnlimitedK_WithFee_ReduceSpace(prices, pricesSize, fee);
}


//leetcode submit region end(Prohibit modification and deletion)
