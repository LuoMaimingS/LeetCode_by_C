//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 注意空字符串可被认为是有效字符串。 
//
// 示例 1: 
//
// 输入: "()"
//输出: true
// 
//
// 示例 2: 
//
// 输入: "()[]{}"
//输出: true
// 
//
// 示例 3: 
//
// 输入: "(]"
//输出: false
// 
//
// 示例 4: 
//
// 输入: "([)]"
//输出: false
// 
//
// 示例 5: 
//
// 输入: "{[]}"
//输出: true 
// Related Topics 栈 字符串

# include "string.h"
#include "stdbool.h"

//leetcode submit region begin(Prohibit modification and deletion)
bool isValid(char * s){
    char stack[3500];
    int stack_pointer = -1;
    char temp;
    for (int i=0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack_pointer ++;
            stack[stack_pointer] = s[i];
        } else {
            // 右括号
            if (stack_pointer < 0) {
                return false;
            }
            temp = stack[stack_pointer];
            if (s[i] == ')') {
                if (temp == '(')
                    stack_pointer--;
                else
                    return false;
            } else if (s[i] == ']') {
                if (temp == '[')
                    stack_pointer--;
                else
                    return false;
            } else if (s[i] == '}') {
                if (temp == '{')
                    stack_pointer--;
                else
                    return false;
            }
        }
    }
    // 仍有左括号
    if (stack_pointer >= 0)
        return false;
    return true;
}

//leetcode submit region end(Prohibit modification and deletion)