//堆箱子。给你一堆n个箱子，箱子宽 wi、深 di、高 hi。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。实现一种方法，搭出最
//高的一堆箱子。箱堆的高度为每个箱子高度的总和。 
//
// 输入使用数组[wi, di, hi]表示每个箱子。 
//
// 示例1: 
//
//  输入：box = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
// 输出：6
// 
//
// 示例2: 
//
//  输入：box = [[1, 1, 1], [2, 3, 4], [2, 6, 7], [3, 4, 5]]
// 输出：10
// 
//
// 提示: 
//
// 
// 箱子的数目不大于3000个。 
// 
// Related Topics 动态规划 回溯算法

# include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
const int MAX_N = 10000000;

void backtrack(int** box, int* used_box, int height, int *max_height, int boxSize, int used_box_size, int last_w, int last_d, int last_h) {
    if (used_box_size == boxSize)
        return;

    for (int i=0; i<boxSize; i++) {
        if ((used_box[i] == 1) || ((used_box[i] == 0) && ((box[i][0] >= last_w) || (box[i][1] >= last_d) || (box[i][2] >= last_h))))
            continue;

        used_box[i] = 1;
        height += box[i][2];
        if (height > (*max_height))
            (*max_height) = height;
        backtrack(box, used_box, height, max_height, boxSize, used_box_size + 1, box[i][0], box[i][1], box[i][2]);

        used_box[i] = 0;
        height -= box[i][2];
    }
}


int pileBox(int** box, int boxSize, int* boxColSize){
    int *used_box = (int *)calloc(boxSize, sizeof(int));
    int *max_height = (int *)calloc(1, sizeof(int));
    backtrack(box, used_box, 0, max_height, boxSize, 0, MAX_N, MAX_N, MAX_N);
    return *max_height;
}


//leetcode submit region end(Prohibit modification and deletion)
