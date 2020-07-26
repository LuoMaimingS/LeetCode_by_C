//你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋
//装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。 
//
// 示例 1: 
//
// 输入: [2,3,2]
//输出: 3
//解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 
//
// 示例 2: 
//
// 输入: [1,2,3,1]
//输出: 4
//解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
// Related Topics 动态规划

#include "stdlib.h"
//leetcode submit region begin(Prohibit modification and deletion)

int Subrob(int* nums, int left, int right) {
    int n = right - left + 1;
    int ** dp = (int **)calloc(n + 1, sizeof(int *));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)calloc(2, sizeof(int));
    }
    dp[0][0] = 0;
    dp[0][1] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (dp[i-1][1] > (dp[i-1][0] + nums[i-1+left]))? dp[i-1][1]: dp[i-1][0] + nums[i-1+left];
    }

    if (dp[n][0] > dp[n][1])
        return dp[n][0];
    else
        return dp[n][1];
}

int rob(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return nums[0];
    int res1 = Subrob(nums, 0, numsSize - 2);
    int res2 = Subrob(nums, 1, numsSize - 1);
    int max = (res1 > res2)? res1: res2;
    return max;
}


//leetcode submit region end(Prohibit modification and deletion)
