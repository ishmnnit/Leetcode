#include<iostream>
#include<vector>
using namespace std;


void combine(int n,int k,int len,int start,
        vector<vector<int> > &result,vector<int> curResult){

    if(len==k){
        result.push_back(curResult);
    }

    for(int i=start;i<n;i++){
        curResult.push_back(i+1);
        combine(n,k,len+1,i+1,result,curResult);
        curResult.pop_back();
    }

}

vector<vector<int> > combine(int n, int k) {

    vector<vector<int> > result;
    vector<int> curResult;
    combine(n,k,0,0,result,curResult);
    return result;

             
}

int main(){

    vector<vector<int> > result;
    result=combine(4,2);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
