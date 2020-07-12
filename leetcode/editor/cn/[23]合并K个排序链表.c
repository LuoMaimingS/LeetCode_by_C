//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。 
//
// 示例: 
//
// 输入:
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//输出: 1->1->2->3->4->4->5->6 
// Related Topics 堆 链表 分治算法
#include "stdlib.h"
#include "stdio.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void SiftDown(struct ListNode** heap, int i, int heap_size) {
    struct ListNode* target_p = heap[i];    // 需要被下沉的结点
    int target_val = target_p->val;
    int k = i;
    while (k < heap_size) {
        // k为根节点
        if ((2 * k + 1) >= heap_size)
            break;

        int left_child = 2 * k + 1;
        int right_child = (left_child == heap_size - 1) ? left_child: left_child + 1;
        int smaller_index = (heap[left_child]->val < heap[right_child]->val) ? left_child: right_child;
        if (heap[smaller_index]->val < target_val) {
            heap[k] = heap[smaller_index];
            k = smaller_index;
        } else {
            break;
        }
    }
    heap[k] = target_p;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    // 去除空链表
    for (int i = 0; i < listsSize;) {
        if (lists[i] == NULL) {
            listsSize --;
            lists[i] = lists[listsSize];
        } else
            i ++;
    }

    // 初始化堆
    for (int i = (listsSize >> 1) - 1; i >= 0; i--) {
        SiftDown(lists, i, listsSize);
    }

    // 合并链表
    struct ListNode unreal_head;
    struct ListNode* tail = &unreal_head;
    while (listsSize > 0) {
        // 取出最小元素
        struct ListNode* p_min_elem = lists[0];
        if (p_min_elem->next == NULL) {
            listsSize --;
            lists[0] = lists[listsSize];
        } else {
            lists[0] = lists[0]->next;
        }
        SiftDown(lists, 0, listsSize);
        tail->next = p_min_elem;
        tail = tail->next;
    }
    tail->next = NULL;
    return unreal_head.next;
}


//leetcode submit region end(Prohibit modification and deletion)
