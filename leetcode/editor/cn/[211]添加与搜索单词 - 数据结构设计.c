//设计一个支持以下两种操作的数据结构： 
//
// void addWord(word)
//bool search(word)
// 
//
// search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。 
//
// 示例: 
//
// addWord("bad")
//addWord("dad")
//addWord("mad")
//search("pad") -> false
//search("bad") -> true
//search(".ad") -> true
//search("b..") -> true
// 
//
// 说明: 
//
// 你可以假设所有单词都是由小写字母 a-z 组成的。 
// Related Topics 设计 字典树 回溯算法


//leetcode submit region begin(Prohibit modification and deletion)



typedef struct {
    
} WordDictionary;

/** Initialize your data structure here. */

WordDictionary* wordDictionaryCreate() {
    
}

/** Adds a word into the data structure. */
void wordDictionaryAddWord(WordDictionary* obj, char * word) {
  
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
bool wordDictionarySearch(WordDictionary* obj, char * word) {
  
}

void wordDictionaryFree(WordDictionary* obj) {
    
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/
//leetcode submit region end(Prohibit modification and deletion)
