#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int cnt=0;
void combinationSum(vector<int> &candidates, int target,int currentSum,
        set<vector<int> > &result,vector<int> curResult,int start){

    if(currentSum == target){
        sort(curResult.begin(),curResult.end());
        result.insert(curResult);
    }

    if(currentSum > target ){
        return;
    }

    for(int i=start;i<candidates.size();i++){
        if(currentSum +candidates[i] <= target){
            curResult.push_back(candidates[i]);
            combinationSum(candidates,target,currentSum+candidates[i],result,curResult,i+1);
            curResult.pop_back();
        }
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
    vector<vector<int> > resultVec;
    set<vector<int> > result;
    vector<int> curResult;
    combinationSum(candidates,target,0,result,curResult,0);
    copy(result.begin(), result.end(), back_inserter(resultVec));
    return resultVec;
}


int main(){

    vector<int> candidates ;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    vector<vector<int> > result;

    result=combinationSum(candidates,8);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }

}
