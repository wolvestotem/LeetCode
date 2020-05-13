#include"../leetcode.h"

class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        int synx;
        synx = (x>0)?1:-1;
        queue<int> q;
        int e;
        while(x!=0){
            e=x%10;
            x = (x-e)/10;
            q.push(e);
        }
        int result=0;
        int t;
        while(!q.empty()){
            t=q.front();
            q.pop();
            if(synx==1){
                if((INT_MAX-t)/10>=result)
                    result = result*10+t;
                else
                    return 0;
            }
            if(synx==-1){
                if((INT_MIN-t)/10 <= result)
                    result = result*10+t;
                else 
                    return 0;
            }
            
        }
        return result;
    }
};