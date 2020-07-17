//给出一个区间的集合，请合并所有重叠的区间。 
//
// 示例 1: 
//
// 输入: [[1,3],[2,6],[8,10],[15,18]]
//输出: [[1,6],[8,10],[15,18]]
//解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2: 
//
// 输入: [[1,4],[4,5]]
//输出: [[1,5]]
//解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。 
// Related Topics 排序 数组

#include "stdlib.h"
#include "stdio.h"

//leetcode submit region begin(Prohibit modification and deletion)


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void MinHeapSiftDown(int ** heap, int i, int heapSize) {
    int *target_p = heap[i];
    int target_val = target_p[0];
    int k = i;
    while (k < heapSize) {
        if (2 * k + 1 >= heapSize) {
            break;
        }
        int left_child = 2 * k + 1;
        int right_child = ((left_child + 1) >= heapSize)? left_child: left_child + 1;
        int smaller_index = (heap[left_child][0] <= heap[right_child][0])? left_child: right_child;
        if (heap[smaller_index][0] < target_val) {
            heap[k] = heap[smaller_index];
            k = smaller_index;
        } else {
            break;
        }
    }
    heap[k] = target_p;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int empty_flag = intervalsSize;
    for (int i = (intervalsSize - 1) >> 1; i >= 0; i--) {
        MinHeapSiftDown(intervals, i, intervalsSize);
    }

    int** merged = (int **)calloc(intervalsSize, sizeof(int *));
    *returnSize = 0;
    for(int i = 0; i < intervalsSize; ++i) {
        merged[i] = (int *)calloc(2, sizeof(int));
    }

    if (intervalsSize > 0) {
        merged[*returnSize][0] = intervals[0][0];
        merged[*returnSize][1] = intervals[0][1];
        intervals[0] = intervals[--intervalsSize];
        MinHeapSiftDown(intervals, 0, intervalsSize);
    }

    while (intervalsSize > 0) {
        int *temp_interval = intervals[0];

        if (temp_interval[1] <= merged[*returnSize][1]) {
            // [         ]
            //   [    ]
            // do nothing.
        } else {
            if ((temp_interval[0] <= merged[*returnSize][1]) && (temp_interval[1] > merged[*returnSize][1])) {
                // [         ]
                //   [          ]
                merged[*returnSize][1] = temp_interval[1];
            } else {
                // [         ]
                //              [          ]
                (*returnSize) ++;
                merged[*returnSize][0] = temp_interval[0];
                merged[*returnSize][1] = temp_interval[1];
            }
        }
        intervals[0] = intervals[--intervalsSize];
        MinHeapSiftDown(intervals, 0, intervalsSize);
    }

    if (empty_flag > 0)
        (*returnSize) ++;

    int *retColSize = (int *)malloc(sizeof(int) * *returnSize);
    for (int i = 0; i < *returnSize; i++) {
        retColSize[i] = 2;
    }
    *returnColumnSizes = retColSize;

    return merged;
}


//leetcode submit region end(Prohibit modification and deletion)
