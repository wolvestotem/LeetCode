#include"../leetcode.h"

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> d(wordList.begin(), wordList.end()), beginSet, endSet, *forwardSet, *targetSet;
        if(d.count(endWord) == 0) return 0;
        beginSet.insert(beginWord);
        endSet.insert(endWord);
        int res = 1;
        while(!beginSet.empty() && !endSet.empty()){
            res++;
            if(beginSet.size() <= endSet.size()){
                forwardSet = &beginSet;
                targetSet = &endSet;
            }else{
                forwardSet = &endSet;
                targetSet = &beginSet;
            }
            unordered_set<string> nextForwardSet;
            for(auto curr: *forwardSet){
                for(int i = 0; i < curr.size(); i++){
                    auto tmp = curr[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        curr[i] = c;
                        if(targetSet->count(curr) != 0) return res;
                        if(d.count(curr) != 0){
                            nextForwardSet.insert(curr);
                            d.erase(curr);
                        }
                    }
                    curr[i] = tmp;
                }
            }
            swap(*forwardSet, nextForwardSet);
        }
        return 0;
    }