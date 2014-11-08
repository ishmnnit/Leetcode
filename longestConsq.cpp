#include<iostream>
#include<set>
#include<vector>
using namespace std;

int findConsecutive(set<int> &numSet,int num,int step)
{
    int len=0;
    while(numSet.find(num)!=numSet.end()){
        numSet.erase(num);
        num=num+step;
        len=len+1;
    }
    return len;
}



int longestConsecutive(vector<int> &num) {            
    set<int> numSet;
    for(int i=0;i<num.size();i++){
        numSet.insert(num[i]);
    }
    int maxLen=0;

    for(int i=0;i<num.size();i++){

        int left=findConsecutive(numSet,num[i],1);
        int right=findConsecutive(numSet,num[i]-1,-1);
        if(maxLen <  left+right){
            maxLen=left+right;
        }
    }
    return maxLen;
}

int main(){
    int x[6]={100, 4, 200, 1, 3, 2};
    vector<int> v(x, x + sizeof x / sizeof x[0]);
    cout<<longestConsecutive(v);
}
