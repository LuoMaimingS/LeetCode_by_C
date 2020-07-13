//在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 示例 1: 
//
// 输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 说明: 
//
// 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。 
// Related Topics 堆 分治算法
#include "stdio.h"
#include "stdlib.h"
//leetcode submit region begin(Prohibit modification and deletion)
void MinHeapSiftDown(int* heap, int i, int heap_size) {
    int target_val = heap[i];
    int k = i;
    while (k < heap_size) {
        if ((2 * k + 1) >= heap_size) {
            break;
        }
        int left_child = 2 * k + 1;
        int right_child = ((left_child + 1) < heap_size)? left_child + 1: left_child;
        int smaller_index = (heap[left_child] < heap[right_child])? left_child: right_child;
        if (heap[smaller_index] < target_val) {
            heap[k] = heap[smaller_index];
            k = smaller_index;
        } else {
            break;
        }
    }
    heap[k] = target_val;
}

void MinHeapSiftUp(int* heap, int i) {
    int target_val = heap[i];
    int k = i;
    while (k > 0) {
        int parent = (k - 1) >> 1;
        if (target_val < heap[parent]) {
            heap[k] = heap[parent];
            k = parent;
        } else {
            break;
        }
    }
    heap[k] = target_val;
}

int findKthLargest(int* nums, int numsSize, int k){
    int * heap = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        if (i >= k) {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                MinHeapSiftDown(heap, 0, k);
            }
        } else {
            heap[i] = nums[i];
            MinHeapSiftUp(heap, i);
        }
    }
    return heap[0];
}


//leetcode submit region end(Prohibit modification and deletion)
