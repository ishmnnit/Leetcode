#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


bool isValid(vector<int> curResult,int current,int r){
    for(int i=0;i<current;i++){
        if(curResult[i]==r|| (current - i == abs(r- curResult[i])) )
                return false;
    }
    return true;
}

void solveNQueens(int current,int n,int &result,vector<int> curResult) {

    if(current==n){
        result=result+1;
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



int solveNQueens(int n) {
    int result=0;
    vector<int> curResult;
    for(int i=0;i<n;i++)
        curResult.push_back(-1);
    solveNQueens(0,n,result,curResult);
    return result;
 }


int main(){
     cout<< solveNQueens(5);
}
