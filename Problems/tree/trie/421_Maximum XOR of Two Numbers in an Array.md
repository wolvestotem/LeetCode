## 题目

421. Maximum XOR of Two Numbers in an Array

Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?

## 题解

```C++
class TrieNode{
public:
    unordered_map<char,TrieNode*> map;
};

class Solution {
    TrieNode* root;
public:
    Solution(){
        root = new TrieNode();
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<string> strs;
        for(int num:nums){
            strs.push_back(bitset<31>(num).to_string());
        }

        TrieNode *curr(root);
        for(auto str:strs){
            curr = root;
            for(int i=0;i<str.size();i++){
                if(!curr->map.count(str[i])){
                    curr->map[str[i]]=new TrieNode();
                }
                curr = curr->map[str[i]];
            }
        }

        int maxxor=0;
        
        for(auto str:strs){
            int currxor=0;
            curr = root;
            for(int i=0;i<str.size();i++){
                char c = (str[i]=='0')?'1':'0';
                if(curr->map.count(c)){
                    currxor = (currxor|1)<<1;
                    curr = curr->map[c];
                }
                else{
                    currxor = currxor<<1;
                    curr = curr->map[str[i]];
                }
            }
            maxxor = max(maxxor,currxor>>1);
        }
        return maxxor;
    }
};
```

`Improved version`

```C++
class TrieNode{
public:
    unordered_map<char,TrieNode*> map;
};

class Solution {
    TrieNode* root;
public:
    Solution(){
        root = new TrieNode();
    }
    int findMaximumXOR(vector<int>& nums) {
        vector<string> strs;
        for(int num:nums){
            strs.push_back(bitset<31>(num).to_string());
        }
        int maxxor=0;
        int currxor;
        TrieNode *curr(root);
        TrieNode* xornode(root);
        for(auto str:strs){
            curr = root;
            xornode = root;
            currxor=0;
            for(int i=0;i<str.size();i++){
                if(!curr->map.count(str[i])){
                    curr->map[str[i]]=new TrieNode();
                }
                curr = curr->map[str[i]];

                char c = (str[i]=='0')?'1':'0';
                if(xornode->map.count(c)){
                    currxor = (currxor<<1)|1;
                    xornode = xornode->map[c];
                }
                else{
                    currxor = currxor<<1;
                    xornode = xornode->map[str[i]];
                }

                
            }
            maxxor = max(maxxor,currxor);
        }

        return maxxor;
    }
};
```