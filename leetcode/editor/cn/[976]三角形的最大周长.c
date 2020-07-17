//给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
//
// 如果不能形成任何面积不为零的三角形，返回 0。
//
//
//
//
//
//
// 示例 1：
//
// 输入：[2,1,2]
//输出：5
//
//
// 示例 2：
//
// 输入：[1,2,1]
//输出：0
//
//
// 示例 3：
//
// 输入：[3,2,3,4]
//输出：10
//
//
// 示例 4：
//
// 输入：[3,6,2,3]
//输出：8
//
//
//
//
// 提示：
//
//
// 3 <= A.length <= 10000
// 1 <= A[i] <= 10^6
//
// Related Topics 排序 数学

#include "stdio.h"
#include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
void MaxHeapSiftDown(int* heap, int i, int heapSize) {
    int target_val = heap[i];
    int k = i;
    while (k < heapSize) {
        if (2 * k + 1 >= heapSize) {
            break;
        }
        int left_child = 2 * k + 1;
        int right_child = ((left_child + 1) >= heapSize)? left_child: left_child + 1;
        int larger_index = (heap[right_child] > heap[left_child])? right_child: left_child;
        if (heap[larger_index] > target_val) {
            heap[k] = heap[larger_index];
            k = larger_index;
        } else {
            break;
        }
    }
    heap[k] = target_val;
}


int largestPerimeter(int* A, int ASize){
    // Can't Form.
    if (ASize < 3)
        return 0;

    for (int i = (ASize - 1) >> 1; i >= 0; i--) {
        MaxHeapSiftDown(A, i, ASize);
    }
    int edge3 = A[0];
    A[0] = A[--ASize];
    MaxHeapSiftDown(A, 0, ASize);
    int edge2 = A[0];
    A[0] = A[--ASize];
    MaxHeapSiftDown(A, 0, ASize);
    int max_perimeter = 0;
    while (ASize > 0) {
        int edge1 = A[0];
        if (edge1 + edge2 > edge3){
            max_perimeter = edge1 + edge2 + edge3;
            break;
        } else {
            edge3 = edge2;
            edge2 = edge1;
            A[0] = A[--ASize];
            MaxHeapSiftDown(A, 0, ASize);
        }
    }
    return max_perimeter;
}


//leetcode submit region end(Prohibit modification and deletion)