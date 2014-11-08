#include<iostream>
#include<vector>
using namespace std;

bool DFS(int i,int j,vector<vector<char> > board,vector<vector<bool> >visited,string word,int len){
     if(board[i][j] != word[len] || visited[i][j]== true){
         return false;
     }

    if(len==word.length()-1)
        return true;

    int index1[]={-1,1,0,0};
    int index2[]={0,0,1,-1};

    visited[i][j]=true;
    for(int k=0;k<4;k++){
        if(i+index1[k] >=0 && i+index1[k] < board.size() && 
                j+index2[k]>=0 && j+index2[k] < board[0].size()){
            if(DFS(i+index1[k], j+index2[k],board,visited,word,len+1))
                return true;
        }

    }
    visited[i][j]=false;
    return false;
}

bool exist(vector<vector<char> > &board, string word) {

    vector<vector<bool> > visited;

    for(int i=0;i<board.size();i++){
        vector<bool> v;
        for(int j=0;j<board[0].size();j++){
            v.push_back(false);
        }
        visited.push_back(v);
    }

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(DFS(i,j,board,visited,word,0)){
                return true;
            }
        }
    }

    return false;

 }


int main(){

    vector<vector<char> > board;

    string str1 ="ABCE";
    string str2 ="SFCS";
    string str3 ="ADEE";

    vector<char> data1(str1.begin(), str1.end());
    vector<char> data2(str2.begin(), str2.end());
    vector<char> data3(str3.begin(), str3.end());

    board.push_back(data1);
    board.push_back(data2);
    board.push_back(data3);

    string word;
    cin>>word;

    if(exist(board,word)){
        cout<<"Word exists in grid\n";
    }else{
        cout<<"Word does not exists in grid\n";
    }
}
