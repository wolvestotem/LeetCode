## 题目
648. Replace Words

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

## 题解

```C++
class TrieNode{
public:
    bool leaf=false;
    unordered_map<char,TrieNode*> map;
};

class Trie{
private:
TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string& s){
        TrieNode* curr(root);
        for(int i=0;i<s.size();i++){
            if(!curr->map.count(s[i]))
                curr->map[s[i]]=new TrieNode();
            curr = curr->map[s[i]];
        }
        curr->leaf=true;
    }

    int search(string s){//# root
        TrieNode* curr(root);
        int num=0;
        for(int i=0;i<s.size();i++){
            if(curr->leaf)
                return num;
            if(!curr->map.count(s[i]))
                return -1;
            
            curr=curr->map[s[i]];
            num++;
        }
        return (curr->leaf)?num:-1;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for(auto root: dictionary){
            t.insert(root);
        }
        sentence.push_back(' ');
        int start=0;
        int found = sentence.find_first_of(' ');
        while(found!=sentence.size()-1){
            found = sentence.find_first_of(' ',start);
            string temp = sentence.substr(start, found-start);
            // cout<<'*'<<temp<<'*'<<'\t';
            int res = t.search(temp);
            // cout<<res<<'\t';
            if(res!=-1){
                sentence.replace(sentence.begin()+start, sentence.begin()+found, temp.substr(0,res));
            }
            found = sentence.find_first_of(' ',start);
            start = found+1;
        }
        sentence.pop_back();
        return sentence;
    }
};
```