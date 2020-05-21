#include"../leetcode.h"

class brute{
public:
    int bruteforce(string txt,string pat){
        int M=txt.size();
        int N=pat.size();
        for(int i=0;i<M-N;i++){
            int j;
            bool match=true;
            for(j=0;j<N;j++){
                if(pat[j]!=txt[i+j]){
                    match=false;
                    break;
                }
            }
            if(match) return i;
        }
        return -1;
    }
};