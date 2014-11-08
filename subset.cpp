#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<vector<int> > subsets(vector<int> &S) {

    vector<vector<int> > result;
    int n=S.size();
    int num=pow(2,n);
    for(int i=0;i<num;i++){
        vector<int> res;
        for(int j=0;j<n;j++){
            if((1<<j) & i)
            {
                res.push_back(S[j]);
            }
        }
        sort(res.begin(),res.end());
        result.push_back(res);
    }
    return result;
}

int main(){
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    vector<vector<int> > result=subsets(s);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }

}
