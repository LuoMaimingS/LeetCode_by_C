//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 堆 分治算法

#include "stdio.h"
#include "stdlib.h"

//leetcode submit region begin(Prohibit modification and deletion)
void MaxHeapSiftUp(int * heap, int i) {
    int target_val = heap[i];
    int k = i;
    while (k > 0) {
        int parent = (k - 1) >> 1;
        if (heap[parent] < target_val) {
            heap[k] = heap[parent];
            k = parent;
        } else {
            break;
        }
    }
    heap[k] = target_val;
}

void MaxHeapSiftDown(int * heap, int i, int heapSize) {
    int target_val = heap[i];
    int k = i;
    while (k < heapSize) {
        if ((2 * k + 1) >= heapSize) {
            break;
        }
        int left_child = 2 * k + 1;
        int right_child = ((left_child + 1) >= heapSize)? left_child: left_child + 1;
        int larger_index = (heap[left_child] > heap[right_child])? left_child: right_child;
        if (heap[larger_index] > target_val) {
            heap[k] = heap[larger_index];
            k = larger_index;
        } else {
            break;
        }
    }
    heap[k] = target_val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int *maxHeap = (int *)calloc(k + 1, sizeof(int));
    *returnSize = 0;
    if (k == 0)
        return maxHeap;
    for (int i = 0; i < arrSize; i++) {
        if (*returnSize < k) {
            maxHeap[*returnSize] = arr[i];
            MaxHeapSiftUp(maxHeap, i);
            (*returnSize) ++;
        } else {
            if (arr[i] < maxHeap[0]) {
                maxHeap[0] = arr[i];
                MaxHeapSiftDown(maxHeap, 0, *returnSize);
            }
        }
    }
    return maxHeap;
}


//leetcode submit region end(Prohibit modification and deletion)
