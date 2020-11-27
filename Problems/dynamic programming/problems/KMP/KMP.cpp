#include"../leetcode.h"

class KMP{
private:
    string model;
    int table[100][128];// must 100>=N
public:
    // KMP(string pat):model(pat) {};//初始化列表  或者  this指针
    KMP(string pat){
        this->model=pat;
        int N=pat.size();
        
        int X=0;
        table[0][pat[0]]=1;
        for(int j=1;j<N;j++){
            for(int c=0;c<128;c++){
                table[j][c]=table[X][c];
            }
            table[j][pat[j]]=j+1;
            X=table[X][pat[j]];
        }
    }

    int search(string txt){
        int curr=0;
        for(int i=0;i<txt.size();i++){
            curr = table[curr][txt[i]];
            if(curr==model.size())//match
                return i-model.size()+1;
        }
        return -1;
    }

};