## 题目

211. Design Add and Search Words Data Structure

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

    WordDictionary() Initializes the object.
    void addWord(word) Adds word to the data structure, it can be matched later.
    bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

## 题解

注意！！
search中需要判断最终节点是否是leaf
思路就是回溯

```C++
class TrieNode{
    public:
    bool leaf=false;
    unordered_map<char,TrieNode*> map;
};

class WordDictionary {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if(word.empty())
            return;
        
        TrieNode* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->map.count(word[i]))
                curr->map[word[i]] = new TrieNode();
            curr = curr->map[word[i]];
        }
        curr->leaf =true;
    }
    
    bool dfs(string& s, int index, TrieNode* curr){
        if(index==s.size()){
            return curr->leaf;
        }
        char c = s[index];
        bool res=false;
        if(c=='.'){
            for(auto p:curr->map){
                res = res||dfs(s, index+1, p.second);
            }
        }
        else{
            if(!curr->map.count(c)) return false;
            res = dfs(s, index+1, curr->map[c]);
        }
        return res;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(word.empty())
            return false;
        TrieNode* curr(root);
        return dfs(word, 0, curr);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 ```
