//给定一个非负整数数组，你最初位于数组的第一个位置。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 判断你是否能够到达最后一个位置。
//
// 示例 1:
//
// 输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
//
//
// 示例 2:
//
// 输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
//
// Related Topics 贪心算法 数组

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
//leetcode submit region begin(Prohibit modification and deletion)

bool canJump(int* nums, int numsSize){
    int cur_p = 0;
    int last_max_can_get = 0;
    int max_can_get = 0;
    while (max_can_get < numsSize - 1) {
        for (int i = cur_p; i <= max_can_get; i++) {
            max_can_get = ((i + nums[i]) > max_can_get)? i + nums[i]: max_can_get;
            if (max_can_get >= numsSize - 1)
                return true;
        }
        if (last_max_can_get == max_can_get) {
            return false;
        }
        last_max_can_get = max_can_get;
        cur_p ++;
    }
    return true;
}
//leetcode submit region end(Prohibit modification and deletion)