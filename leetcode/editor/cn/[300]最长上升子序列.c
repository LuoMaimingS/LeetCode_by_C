//给定一个无序的整数数组，找到其中最长上升子序列的长度。 
//
// 示例: 
//
// 输入: [10,9,2,5,3,7,101,18]
//输出: 4 
//解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。 
//
// 说明: 
//
// 
// 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。 
// 你算法的时间复杂度应该为 O(n2) 。 
// 
//
// 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗? 
// Related Topics 二分查找 动态规划

#include "stdlib.h"

int ON2_lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    int* dp = (int *)calloc(numsSize, sizeof(int));
    dp[0] = 1;

    for (int i = 1; i < numsSize; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = ((dp[j] + 1) > dp[i])? dp[j] + 1: dp[i];
            }
        }
    }

    int max = 1;
    for (int i = 0; i < numsSize; i++) {
        max = (dp[i] > max)? dp[i]: max;
    }
    return max;
}

//leetcode submit region begin(Prohibit modification and deletion)

int BinarySearch(int *nums, int val, int start, int end) {
    int left = start, right = end;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < val) {
            left = mid + 1;
        } else if (nums[mid] > val) {
            right = mid;
        }
    }
    if (nums[left] >= val)
        return left;
    else
        return left + 1;
}

int lengthOfLIS(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    if (numsSize == 1)
        return 1;
    int * arr_groups = (int * )calloc(numsSize, sizeof(int));

    arr_groups[0] = nums[0];
    int groupSize = 1;
    for (int i = 1; i < numsSize; i++) {
        int put_index = BinarySearch(arr_groups, nums[i], 0, groupSize - 1);
        arr_groups[put_index] = nums[i];
        if (put_index == groupSize) {
            groupSize ++;
        }
    }
    return groupSize;
}

//leetcode submit region end(Prohibit modification and deletion)