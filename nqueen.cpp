#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void storeConfig(vector<int> curResult,vector<vector<string> > &result,int n){

    vector<string> solution;
    for(int i=0;i<n;i++){
        string s(n,'.');
        s[curResult[i]]='Q';
        solution.push_back(s);
    }
    result.push_back(solution);
}

bool isValid(vector<int> curResult,int current,int r){
    for(int i=0;i<current;i++){
        if(curResult[i]==r|| (current - i == abs(r- curResult[i])) )
                return false;
    }
    return true;
}

void solveNQueens(int current,int n,vector<vector<string> > &result,vector<int> curResult) {

    if(current==n){
        storeConfig(curResult,result, n);
    } 
    else{
        for(int i=0;i<n;i++)
        {
            curResult[current]=i;
            if(isValid(curResult,current,i)){
                solveNQueens(current+1,n,result,curResult);
            }
        }
    }

}



vector<vector<string> > solveNQueens(int n) {

    vector<vector<string> > result;
    vector<int> curResult;
    for(int i=0;i<n;i++)
        curResult.push_back(-1);
    solveNQueens(0,n,result,curResult);
    return result;
 }


int main(){

     vector<vector<string> > result;
     result= solveNQueens(4);
     for(int i=0;i<result.size();i++){
         for(int j=0;j<result[i].size();j++){
             cout<<result[i][j]<<"\n";
         }
         cout<<"\n\n\n";
     }

}
