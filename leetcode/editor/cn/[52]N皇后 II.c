//n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 
//
// 上图为 8 皇后问题的一种解法。 
//
// 给定一个整数 n，返回 n 皇后不同的解决方案的数量。 
//
// 示例: 
//
// 输入: 4
//输出: 2
//解释: 4 皇后问题存在如下两个不同的解法。
//[
// [".Q..",  // 解法 1
//  "...Q",
//  "Q...",
//  "..Q."],
//
// ["..Q.",  // 解法 2
//  "Q...",
//  "...Q",
//  ".Q.."]
//]
// 
//
// 
//
// 提示： 
//
// 
// 皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或七步
//，可进可退。（引用自 百度百科 - 皇后 ） 
// 
// Related Topics 回溯算法

# include "stdbool.h"
# include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
bool valid_put(int n, int* board, int row, int col) {
    for (int i=0; i<row; i++) {
        if (board[i] == col || i + board[i] == row + col || i - board[i] == row - col) {
            return false;
        }
    }
    return true;
}

void backtrack(int n, int* board, int row, int *result) {
    if (row == n) {
        (*result) ++;
        return;
    }

    for (int j=0; j<n; j++) {
        if (!valid_put(n, board, row, j)) {
            continue;
        }
        board[row] = j;
        backtrack(n, board, row + 1, result);
        board[row] = 0;
    }
}


int totalNQueens(int n){
    int *result = (int *)calloc(1, sizeof(int));
    int* board = (int *)calloc(n, sizeof(int));
    backtrack(n, board, 0, result);
    return *result;
}

//leetcode submit region end(Prohibit modification and deletion)
