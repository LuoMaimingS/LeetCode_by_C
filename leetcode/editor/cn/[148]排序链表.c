//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。 
//
// 示例 1: 
//
// 输入: 4->2->1->3
//输出: 1->2->3->4
// 
//
// 示例 2: 
//
// 输入: -1->5->3->4->0
//输出: -1->0->3->4->5 
// Related Topics 排序 链表

#include "stdlib.h"
#include "stdio.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

//leetcode submit region begin(Prohibit modification and deletion)
struct ListNode* merge(struct ListNode * left, struct ListNode * right) {
    struct ListNode* phantom_head = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* phantom_tail = phantom_head;
    struct ListNode* p_left = left;
    struct ListNode* p_right = right;
    while ((p_left != NULL) && (p_right != NULL)) {
        if (p_left->val <= p_right->val) {
            phantom_tail->next = p_left;
            p_left = p_left->next;
        }
        else {
            phantom_tail->next = p_right;
            p_right = p_right->next;
        }
        phantom_tail = phantom_tail->next;
    }
    if (p_left == NULL)
        phantom_tail->next = p_right;
    if (p_right == NULL)
        phantom_tail->next = p_left;
    return phantom_head->next;
}

struct ListNode* mergeSort(struct ListNode* head) {
    if (head->next == NULL)
        return head;

    struct ListNode* slow_p = head;
    struct ListNode* fast_p = head;
    while ((fast_p->next != NULL) && (fast_p->next->next != NULL)) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
    }

    struct ListNode* left_head = head;
    struct ListNode* right_head = slow_p->next;
    slow_p->next = NULL;

    struct ListNode* sorted_left = mergeSort(left_head);
    struct ListNode* sorted_right = mergeSort(right_head);
    head = merge(sorted_left, sorted_right);

    return head;
}

struct ListNode* sortList(struct ListNode* head){
    if (head == NULL)
        return NULL;
    else
        return mergeSort(head);
}


//leetcode submit region end(Prohibit modification and deletion)
