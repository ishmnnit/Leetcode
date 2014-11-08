#include<iostream>
#include<vector>
using namespace std;


vector<vector<int> > generateMatrix(int n) {

    int count=0;
    int k=0;
    vector<vector<int> > result;
    vector<int> res;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            res.push_back(-1);
        }
        result.push_back(res);
    }

    while(n>0){

        if(n==1){
            result[k][k]=count+1;
        }

        for(int i=0;i<n-1;i++){
            result[k][k+i]=++count;

        }

        for(int i=0;i<n-1;i++){
            result[k+i][k+n-1]=++count;
        }

        for(int i=0;i<n-1;i++){
            result[k+n-1][k+n-1-i]=++count;
        }

        for(int i=0;i<n-1;i++){
            result[k+n-1-i][k]=++count;
        }
        n=n-2;
        k=k+1;

    }

    return result ;
}

int main(){

    int n;
    cin>>n;
    vector<vector<int> > result = generateMatrix(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
