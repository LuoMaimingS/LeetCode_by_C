//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
// 注意:
//不能使用代码库中的排序函数来解决这道题。
//
// 示例:
//
// 输入: [2,0,2,1,1,0]
//输出: [0,0,1,1,2,2]
//
// 进阶：
//
//
// 一个直观的解决方案是使用计数排序的两趟扫描算法。
// 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
// 你能想出一个仅使用常数空间的一趟扫描算法吗？
//
// Related Topics 排序 数组 双指针
#include "stdio.h"

//leetcode submit region begin(Prohibit modification and deletion)


void sortColors(int* nums, int numsSize){
    int next_0, next_2;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            next_0 = i;
            break;
        }
    }
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] != 2) {
            next_2 = i;
            break;
        }
    }

    int k = 0;
    while (k <= next_2) {
        if ((nums[k] == 0) && (k > next_0)) {
            int temp = nums[k];
            nums[k] = nums[next_0];
            nums[next_0++] = temp;
            while (next_0 < numsSize) {
                if (nums[next_0] != 0)
                    break;
                next_0 ++;
            }
            if (nums[k] == 2) {
                int temp1 = nums[k];
                nums[k] = nums[next_2];
                nums[next_2--] = temp1;
                while (next_2 >= 0) {
                    if (nums[next_2] != 2)
                        break;
                    next_2--;
                }
            }
        } else if (nums[k] == 2) {
            int temp = nums[k];
            nums[k] = nums[next_2];
            nums[next_2--] = temp;
            while (next_2 >= 0) {
                if (nums[next_2] != 2)
                    break;
                next_2 --;
            }
            if ((nums[k] == 0) && (k >= next_0)) {
                int temp1 = nums[k];
                nums[k] = nums[next_0];
                nums[next_0++] = temp1;
                while (next_0 < numsSize) {
                    if (nums[next_0] != 0)
                        break;
                    next_0++;
                }
            }
        }
        k ++;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
