## 题目

208. Implement Trie (Prefix Tree)
Medium

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

## 题解

```C++
class TrieNode{
public:
    bool isleaf=false;
    unordered_map<char, TrieNode*> map;
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.size()==0)
            return;
        TrieNode* temp;
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!curr->map.count(c)){
                temp = new TrieNode();
                curr->map[c] = temp;
            }
            curr = curr->map[c];
        }
        curr->isleaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.size()==0)
            return true;
        TrieNode* temp;
        TrieNode* curr=root;
        for(int i=0;i<word.size();i++){
            char c = word[i];
            if(!curr->map.count(c)){
                return false;
            }
            curr = curr->map[c];
        }
        return curr->isleaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.size()==0)
            return true;
        TrieNode* temp;
        TrieNode* curr=root;
        for(int i=0;i<prefix.size();i++){
            char c = prefix[i];
            if(!curr->map.count(c)){
                return false;
            }
            curr = curr->map[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 ```

 ```C++
 class Trie
{
private:
	bool is_string = false;
	Trie* next[26] = { nullptr };
public:
	Trie() {}

	void insert(const string& word)//插入单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)root->next[w - 'a'] = new Trie();
			root = root->next[w - 'a'];
		}
		root->is_string = true;
	}

	bool search(const string& word)//查找单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)return false;
			root = root->next[w - 'a'];
		}
		return root->is_string;
	}

	bool startsWith(const string& prefix)//查找前缀
	{
		Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;
			root = root->next[p - 'a'];
		}
		return true;
	}
};
```