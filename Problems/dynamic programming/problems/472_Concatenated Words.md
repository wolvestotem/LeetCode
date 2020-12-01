## 题目

472. Concatenated Words
Hard
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

## 题解

涉及到一个单词在另一个单词中是否存在的问题，可以使用prefix tree::search，构建一颗prefix tree，利用leaf状态判断是否是单词。
一个单词中涉及多个单词组成问题，dfs遍历所有情况，backtracking

curr->leaf是在子节点中的性质，map.count()是父节点中的性质，需要理清楚判断节点条件


```C++
class TrieNode{
public:
    bool leaf = false; 
    unordered_map<char, TrieNode*> map;
};

class Solution {
    TrieNode* root;
public:
    Solution(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* curr(root);
        for(int i=0;i<word.size();i++){
            if(!curr->map.count(word[i])){
                curr->map[word[i]] = new TrieNode();
            }
            curr = curr->map[word[i]];
        }
        curr->leaf = true;
    }

    bool search(string word, int count, int index){
        if(index==word.size()){
            if(count>=2)
                return true;
            else
                return false;
        }

        TrieNode* curr(root);
        for(int i=index;i<word.size();i++){
            if(!curr->map.count(word[i]))
                return false;
            curr = curr->map[word[i]];
            if(curr->leaf){
                if (search(word, count+1, i+1)){
                    return true;
                }
            }
            
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.empty()) return {};
        for(auto word: words){
            insert(word);
        }

        vector<string> res;
        for(auto word: words){
            if(search(word,0,0))
                res.push_back(word);
        }

        return res;
    }
};
```


也可以使用word break，在一个unordered_set字典中，查找一个单词是否有substring可以被查找到，dp去重重复查找
```C++
class Solution {
       unordered_set<string> dict;
     bool wordBreak(string s) {
        int n=s.size();
        bool dp[n+1];
        memset(dp,false,n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]){
                if(dict.find(s.substr(j,i-j))!=dict.end()){//found
                    dp[i]=true;
                    break;
                  }
                }
            }
        }
        return dp[n];
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
         for(auto s:words)
        {
            dict.insert(s);
        }
        vector<string> res;
        for(auto s:words)
        {
            if(s.size()==0)
                continue;
            dict.erase(s);
           if( wordBreak(s))
               res.push_back(s);
            dict.insert(s);
        }
        return res;
    }
};
```