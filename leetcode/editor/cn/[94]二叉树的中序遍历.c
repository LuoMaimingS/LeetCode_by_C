//给定一个二叉树，返回它的中序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct LinkedList {
    struct TreeNode* treeNode;
    struct TreeNode* next;
};

struct LinkStack {
    struct LinkedList* head;
    struct LinkedList* tail;
    int stackSize;
};


//leetcode submit region begin(Prohibit modification and deletion)



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){

}


//leetcode submit region end(Prohibit modification and deletion)
