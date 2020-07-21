//给定一个无序的数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。
//
// 示例 1:
//
// 输入: nums = [1, 5, 1, 1, 6, 4]
//输出: 一个可能的答案是 [1, 4, 1, 5, 1, 6]
//
// 示例 2:
//
// 输入: nums = [1, 3, 2, 2, 3, 1]
//输出: 一个可能的答案是 [2, 3, 1, 3, 1, 2]
//
// 说明:
//你可以假设所有输入都会得到有效的结果。
//
// 进阶:
//你能用 O(n) 时间复杂度和 / 或原地 O(1) 额外空间来实现吗？
// Related Topics 排序

#include "stdlib.h"
#include "stdio.h"

//leetcode submit region begin(Prohibit modification and deletion)

int partition(int * nums, int left, int right) {
    int k = left;
    int pivot = nums[left];
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < pivot) {
            k ++;
            int temp = nums[k];
            nums[k] = nums[i];
            nums[i] = temp;
        }
    }
    int temp = nums[k];
    nums[k] = nums[left];
    nums[left] = temp;
    return k;
}

void wiggleSort(int* nums, int numsSize){
    int k , target_k = numsSize / 2;
    int left = 0, right = numsSize - 1;
    while (1) {
        k = partition(nums, left, right);
        if (k == target_k)
            break;
        if (k < target_k) {
            left = k + 1;
        } else {
            right = k - 1;
        }
    }
    int *wiggle = (int *)calloc(numsSize, sizeof(int));
    for (int j = 0; j < numsSize; j++) {
        wiggle[j] = nums[j];
    }
    int target_val = wiggle[target_k];
    int temp_pos = target_k + 1;
    for (int i = target_k + 1; i < numsSize; i++) {
        if (wiggle[i] == target_val) {
            int temp = wiggle[i];
            wiggle[i] = wiggle[temp_pos];
            wiggle[temp_pos] = temp;
            temp_pos ++;
        }
    }

    left = (numsSize - 1) / 2;
    right = numsSize - 1;
    int j = 0;
    while (j < numsSize) {
        if (j % 2 == 0) {
            nums[j++] = wiggle[left--];
        } else {
            nums[j++] = wiggle[right--];
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)