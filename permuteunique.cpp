#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool swapit(int current,int i,vector<int> num){

    for(int j=current; j<i;j++){
        if(num[i]==num[j])
            return false;
    }
    return true;
}


void permuteUnique(vector<vector<int> > & result ,int current,vector<int> num)
{
    if(num.size()==current){
        result.push_back(num);
        return ;
    }

    for(int i=current ;i< num.size();i++){
        if(swapit(current,i,num)){
            swap(num[i],num[current]);
            permuteUnique(result,current+1,num);
            swap(num[i],num[current]);
        }
    }

}

vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<vector<int> > result;
    permuteUnique(result,0,num);
    return result;
}

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    vector<vector<int> > result;
    result=permuteUnique(num);
    
    for(int i=0;i<result.size();i++){
         for(int j=0;j<result[0].size();j++){
             cout<<result[i][j]<<"\t";
         }
         cout<<"\n";
    }

}
