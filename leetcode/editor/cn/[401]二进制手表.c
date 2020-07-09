//二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。 
//
// 每个 LED 代表一个 0 或 1，最低位在右侧。 
//
// 
//
// 例如，上面的二进制手表读取 “3:25”。 
//
// 给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。 
//
// 
//
// 示例： 
//
// 输入: n = 1
//返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "
//0:32"] 
//
// 
//
// 提示： 
//
// 
// 输出的顺序没有要求。 
// 小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。 
// 分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。 
// 超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。 
// 
// Related Topics 位运算 回溯算法


#include "stdio.h"
#include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
const int POSSIBLE_COM = 24 * 60;
const int TOTAL_DIGITS = 10;

int val[10] = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};

void backtrack(int current_p, int digit_left, int hour, int minute, int* returnSize, char** result) {
    if (digit_left == 0) {
        if (hour < 10) {
            result[*returnSize] = (char *)calloc(5, sizeof(char));
        } else {
            result[*returnSize] = (char *)calloc(6, sizeof(char));
        }
        if (minute >= 10) {
            sprintf(result[*returnSize], "%d:%d", hour, minute);
        } else if (minute > 0){
            sprintf(result[*returnSize], "%d:0%d", hour, minute);
        } else if (minute == 0) {
            sprintf(result[*returnSize], "%d:00", hour);
        }
        (*returnSize) ++;
        return;
    }

    for (int i=current_p; i<TOTAL_DIGITS; i++) {
        if (((i<=3) && (hour + val[i] >= 12)) || ((i>3) && (minute + val[i] >= 60))) {
            continue;
        }
        //Do choice.
        if (i <= 3) {
            hour += val[i];
        } else {
            minute += val[i];
        }

        backtrack(i+1, digit_left-1, hour, minute, returnSize, result);
        // Cancel choice.
        if (i <= 3) {
            hour -= val[i];
        } else {
            minute -= val[i];
        }
    }
}

char ** readBinaryWatch(int num, int* returnSize){
    char **res = (char **)malloc(POSSIBLE_COM * sizeof(char *));
    *returnSize = 0;
    backtrack(0, num, 0, 0, returnSize, res);
    return res;
}

//leetcode submit region end(Prohibit modification and deletion)
