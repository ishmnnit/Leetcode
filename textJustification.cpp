#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void display(vector<string> str){

    for(int i=0;i<str.size();i++){
        cout<<str[i]<<"\n";
    }

}

vector<int> wordLengthCalculation(vector<string> words)
{
    vector<int> wordLength;
    for(int i=0;i<words.size();i++){
        wordLength.push_back(words[i].length());
    }
}

struct node {
    int row,col,cost;
};


vector<string> fullJustify(vector<string> &words, int L) {
    vector<int> wordLength=wordLengthCalculation(words);
    display(words);
    int n=words.size();
    node cost[n][n];

    // One Word 
    for(int i=0;i<n;i++){
        cost[i][i].cost=L-words[i].length();
    }

    //Intialize 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cost[i][j].cost=INT_MAX;
        }
    }

    int sum[n+1];
    sum[0]=0;
    for(int i=0;i<n;i++){
        sum[i+1]=wordLength[i]+sum[i];
    }

    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            if(sum[j+1]-sum[i] < L ) {
                cost[i][j].cost=0;
                //continue;
            }
            cout<<"i="<<i<<"\t"<<"j="<<j<<"\n";
            for(int k=0;k<l-1;k++){
                if(cost[i][j].cost > cost[i][k].cost+ cost[k+1][j].cost){
                        cost[i][j].cost=cost[i][k].cost+cost[k+1][j].cost;
                }
            }
        }
    }
    cout<<"Reched Herre \n";
    vector<string> result;
    cout<<cost[0][n-1].cost;
    return result;
}


int main(){
    string str[]={"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> input(str,str+6);
    vector<string> result=fullJustify(input,16);
}
