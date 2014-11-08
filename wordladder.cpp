#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>
#include<vector>
using namespace std;


struct pathNode {
    string word;
    int length; 
};

vector<vector<string> > ladderLength(string start, string end, unordered_set<string> &dict) {
   
    vector<vector<string> > result;
    if(start.length()==0 || start.length()!=end.length() || start == end ){
        return result;
    }

    unordered_set<string> visited;
    queue<pathNode> q;
    pathNode startNode;
    startNode.word=start;
    startNode.length=1;
    q.push(startNode);
    
    while(!q.empty()){
        pathNode node1=q.front();
        q.pop();
        pathNode node ;
        int length=node1.length;
        string word=node1.word;
        //cout<<"Word:::"<<word<<"\n";   
        for(int i=0;i<word.length();i++){
            
            char original=word[i];
            for(char c='a'; c<='z';c++){
                word[i]=c;

                if(word==end){
                   
                }
                
                unordered_set<string>::const_iterator iter1=dict.find(word);
                unordered_set<string>::const_iterator iter2=visited.find(word);

                if(iter1!=dict.end() && iter2==visited.end()){
                    //cout<<word<<"\n";
                    node.word=word;
                    node.length=length+1;
                    q.push(node);
                    visited.insert(word);
                }
            }
            word[i]=original;
        }
    }
    return result;
}


int main(){
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict = { "hot","dot","dog","lot","log" };
   cout<< ladderLength(start,end,dict);

}
