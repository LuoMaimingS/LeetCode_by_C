//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//
// 你需要按照以下要求，帮助老师给这些孩子分发糖果：
//
//
// 每个孩子至少分配到 1 个糖果。
// 相邻的孩子中，评分高的孩子必须获得更多的糖果。
//
//
// 那么这样下来，老师至少需要准备多少颗糖果呢？
//
// 示例 1:
//
// 输入: [1,0,2]
//输出: 5
//解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
//
//
// 示例 2:
//
// 输入: [1,2,2]
//输出: 4
//解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
//     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
// Related Topics 贪心算法

#include "stdio.h"
#include "stdlib.h"
#include "memory.h"
//leetcode submit region begin(Prohibit modification and deletion)
void allocate_candies(int * nums, int * ratings, int left_valley, int right_valley) {
    nums[left_valley] = 1;
    nums[right_valley] = 1;
    for (int i = left_valley + 1; i <= right_valley; i++) {
        if (ratings[i] > ratings[i - 1]) {
            nums[i] = nums[i - 1] + 1;
        } else {
            nums[i] = 1;
        }
    }
    for (int i = right_valley - 1; i >= left_valley; i--) {
        if (ratings[i] > ratings[i + 1]) {
            nums[i] = (nums[i + 1] + 1 > nums[i])? nums[i + 1] + 1: nums[i];
        }
    }
}


int candy(int* ratings, int ratingsSize){
    if (ratingsSize == 1)
        return 1;
    int *nums = (int *)calloc(ratingsSize, sizeof(int));
    memset(nums, 1, ratingsSize * sizeof(int));

    int *valley = (int *)calloc(ratingsSize, sizeof(int));
    int valleySize = 0;
    if (ratings[0] <= ratings[1]) {
        valley[valleySize++] = 0;
    }

    for (int i = 1; i < ratingsSize - 1; i++) {
        if ((ratings[i] <= ratings[i - 1]) && (ratings[i] <= ratings[i + 1])) {
            valley[valleySize++] = i;
        }
    }

    if (ratings[ratingsSize - 1] <= ratings[ratingsSize - 2]) {
        valley[valleySize++] = ratingsSize - 1;
    }

    if (valleySize == 1) {
        if ((valley[0] == 0) || (valley[0] == ratingsSize - 1)) {
            return (1 + ratingsSize) * ratingsSize / 2;
        } else {
            int left = valley[0] + 1;
            int right = ratingsSize - valley[0];
            return (((1 + left) * left / 2) + ((1 + right) * right / 2)) - 1;
        }
    }

    for (int i = 0; i < valleySize - 1; i++) {
        allocate_candies(nums, ratings, valley[i], valley[i + 1]);
    }

    if (valley[0] != 0) {
        for (int i = valley[0] - 1; i >= 0; i--) {
            nums[i] = nums[i + 1] + 1;
        }
    }

    if (valley[valleySize - 1] != ratingsSize - 1) {
        for (int i = valley[valleySize - 1] + 1; i < ratingsSize; i++) {
            nums[i] = nums[i - 1] + 1;
        }
    }

    int candies = 0;
    for (int i = 0; i < ratingsSize; i++) {
        candies += nums[i];
    }
    return candies;
}


//leetcode submit region end(Prohibit modification and deletion)