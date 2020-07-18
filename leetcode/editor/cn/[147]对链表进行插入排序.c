//对链表进行插入排序。 
//
// 
//插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。 
//每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。 
//
// 
//
// 插入排序算法： 
//
// 
// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。 
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。 
// 重复直到所有输入数据插入完为止。 
// 
//
// 
//
// 示例 1： 
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
// 
//
// 示例 2： 
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5
// 
// Related Topics 排序 链表

#include "stdlib.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
//leetcode submit region begin(Prohibit modification and deletion)


struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL)
        return NULL;

    struct ListNode* phantom_head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    phantom_head->next = head;
    struct ListNode* cur_node = head->next;
    head->next = NULL;

    while (cur_node != NULL) {
        struct ListNode* insert_prev_p = phantom_head;
        while ((insert_prev_p->next != NULL) && (insert_prev_p->next->val) <= cur_node->val) {
            insert_prev_p = insert_prev_p->next;
        }
        struct ListNode* temp = cur_node->next;
        cur_node->next = insert_prev_p->next;
        insert_prev_p->next = cur_node;
        cur_node = temp;
    }
    return phantom_head->next;
}


//leetcode submit region end(Prohibit modification and deletion)
