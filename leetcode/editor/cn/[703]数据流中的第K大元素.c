//设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。 
//
// 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返
//回当前数据流中第K大的元素。 
//
// 示例: 
//
// 
//int k = 3;
//int[] arr = [4,5,8,2];
//KthLargest kthLargest = new KthLargest(3, arr);
//kthLargest.add(3);   // returns 4
//kthLargest.add(5);   // returns 5
//kthLargest.add(10);  // returns 5
//kthLargest.add(9);   // returns 8
//kthLargest.add(4);   // returns 8
// 
//
// 说明: 
//你可以假设 nums 的长度≥ k-1 且k ≥ 1。 
// Related Topics 堆

#include "stdlib.h"
#include "stdio.h"
//leetcode submit region begin(Prohibit modification and deletion)
void MinHeapSiftUp(int * heap, int i) {
    int target_val = heap[i];
    int k = i;
    while (k > 0) {
        int parent = (k - 1) >> 1;
        if (heap[parent] > target_val) {
            heap[k] = heap[parent];
            k = parent;
        } else {
            break;
        }
    }
    heap[k] = target_val;
}

void MinHeapSiftDown(int * heap, int i, int heapSize) {
    int target_val = heap[i];
    int k = i;
    while (k < heapSize) {
        if ((2 * k + 1) >= heapSize) {
            break;
        }
        int left_child = 2 * k + 1;
        int right_child = ((left_child + 1) >= heapSize)? left_child: left_child + 1;
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

typedef struct {
    int * heap;
    int heapSize;
    int maxSize;
} KthLargest;


KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    int *heap = (int *)calloc(k + 1, sizeof(int));
    KthLargest* KLobj = (KthLargest*)malloc(sizeof(KthLargest));
    KLobj->heap = heap;
    KLobj->heapSize = 0;
    KLobj->maxSize = k;

    for (int i=0; i<numsSize; i++) {
        if (KLobj->heapSize == k) {
            if (nums[i] > heap[0]) {
                heap[0] = nums[i];
                MinHeapSiftDown(heap, 0, KLobj->heapSize);
            }
        } else{
            KLobj->heap[KLobj->heapSize] = nums[i];
            MinHeapSiftUp(heap, KLobj->heapSize);
            KLobj->heapSize++;
        }
    }
    // printf("%d.\n", KLobj->heap[0]);
    return KLobj;
}

int kthLargestAdd(KthLargest* obj, int val) {
  if (obj->heapSize == obj->maxSize) {
      if (val > obj->heap[0]) {
          obj->heap[0] = val;
          MinHeapSiftDown(obj->heap, 0, obj->heapSize);
      }
  } else {
      obj->heap[obj->heapSize] = val;
      MinHeapSiftUp(obj->heap, obj->heapSize);
      obj->heapSize++;
  }
  // printf("%d.\n", obj->heap[0]);
  return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/
//leetcode submit region end(Prohibit modification and deletion)
