//编写一个程序，通过已填充的空格来解决数独问题。
//
// 一个数独的解法需遵循如下规则：
//
//
// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
//
//
// 空白格用 '.' 表示。
//
//
//
// 一个数独。
//
//
//
// 答案被标成红色。
//
// Note:
//
//
// 给定的数独序列只包含数字 1-9 和字符 '.' 。
// 你可以假设给定的数独只有唯一解。
// 给定数独永远是 9x9 形式的。
//
// Related Topics 哈希表 回溯算法

#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
bool valid_num(char ** board, int position, int num) {
    int row = position / 9;
    int col = position % 9;

    for (int i=0; i<9; i++) {
        if (board[i][col] == num)
            return false;
    }

    for (int j=0; j<9; j++) {
        if (board[col][j] == num)
            return false;
    }

    // The Up-left Corner Of The Block's Index.
    int temp_index = (row / 3) * 27 + (col / 3) * 3;
    while (temp_index < position) {
        int temp_row = temp_index / 9;
        int temp_col = temp_index % 9;
        if (board[temp_row][temp_col] == num)
            return false;

        int temp_inc = temp_index % 3;
        if ((temp_inc == 0) || (temp_inc == 1)) {
            temp_index ++;
        } else {
            temp_index = temp_index + 7;
        }
    }
    return true;
}


bool backtrack(int n, char ** board, int boardSize) {
    if (n == boardSize * boardSize) {
        return true;
    }

    // Fine Next Blank Grid.
    int next_n = n;
    int next_row, next_col;
    while (1) {
        next_row = next_n / 9;
        next_col = next_n % 9;
        if (board[next_row][next_col] == '.') {
            break;
        } else
            next_n ++;
        if (n == boardSize * boardSize) {
            return true;
        }
    }

    for (int i=1; i<=9; i++) {
        if (!valid_num(board, next_n, i))
            continue;

        // Do Choice.
        sprintf(&board[next_row][next_col], "%d", i);
        bool res = backtrack(next_n, board, boardSize);
        if (res)
            return true;
        // Cancel Choice.
        sprintf(&board[next_row][next_col], ".");
    }
    return false;
}


void solveSudoku(char** board, int boardSize, int* boardColSize){
    backtrack(0, board, boardSize);
}
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    char ** board = calloc(9, sizeof(char *));
    char b[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    printf("%d.\n", b);
    printf("%s", b[0]);
}