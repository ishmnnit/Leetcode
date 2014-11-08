#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int> > result;
    set<vector<int> > output;
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
        output.insert(res);
    }
    copy(output.begin(), output.end(),back_inserter(result));
    return result;
}

int main(){
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(2);
    vector<vector<int> > result=subsetsWithDup(s);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }

}
