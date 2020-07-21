//给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
//
// 如果数组元素个数小于 2，则返回 0。
//
// 示例 1:
//
// 输入: [3,6,9,1]
//输出: 3
//解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
//
// 示例 2:
//
// 输入: [10]
//输出: 0
//解释: 数组元素个数小于 2，因此返回 0。
//
// 说明:
//
//
// 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
// 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
//
// Related Topics 排序

#include "stdlib.h"
#include "stdio.h"
#include "memory.h"

//leetcode submit region begin(Prohibit modification and deletion)


int maximumGap(int* nums, int numsSize){
    if (numsSize < 2)
        return 0;


    int max = 0;
    int min = 2147483647;
    for (int i = 0 ; i < numsSize; i++) {
        if (nums[i] > max)
            max = nums[i];
        if (nums[i] < min)
            min = nums[i];
    }
    if (max == min)
        return 0;

    int bucket_size = (max - min) / (numsSize - 1);
    bucket_size = (bucket_size == 0)? 1: bucket_size;
    int bucket_num = (max - min) / bucket_size + (int)((max - min) % bucket_size > 0);
    // ith bucket stores [min + i * bucket_size, min + (i+1) * bucket_size)
    int *bucket_i_min = (int *)malloc((bucket_num) * sizeof(int));
    int *bucket_i_max = (int *)malloc((bucket_num) * sizeof(int));
    memset(bucket_i_min, -1, bucket_num * sizeof(int));
    memset(bucket_i_max, -1, bucket_num * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == max)
            continue;
        int b_idx = (nums[i] - min) / bucket_size;
        if (bucket_i_min[b_idx] == -1) {
            bucket_i_min[b_idx] = nums[i];
            bucket_i_max[b_idx] = nums[i];
        } else {
            if (nums[i] < bucket_i_min[b_idx])
                bucket_i_min[b_idx] = nums[i];
            if (nums[i] > bucket_i_max[b_idx])
                bucket_i_max[b_idx] = nums[i];
        }
    }
    bucket_i_max[bucket_num - 1] = max;
    if (bucket_i_min[bucket_num - 1] == -1)
        bucket_i_min[bucket_num - 1] = max;

    int left = bucket_i_max[0], right;
    int max_gap = bucket_i_max[0] - bucket_i_min[0];
    int k = 1;
    while (k < bucket_num) {
        // empty bucket.
        if (bucket_i_min[k] != -1) {
            right = bucket_i_min[k];
            int cur_gap = right - left;
            max_gap = (cur_gap > max_gap)? cur_gap: max_gap;
            left = bucket_i_max[k];
        }
        k++;
    }
    return max_gap;
}


//leetcode submit region end(Prohibit modification and deletion)
