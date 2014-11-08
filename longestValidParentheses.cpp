#include<iostream>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
    int result=0,i=0;

    while(i<s.length()&& s[i]!='(')
        i++;

    if(i!=s.length()){
        int openCount=0,current=0;
        while(i< s.length()){
            if(s[i]==')'){
                if(openCount >= 0){
                    current=current+2;
                    if(current > result )
                    result=current;
                    openCount = openCount -1;
                }
                else{
                openCount= -1;
                }
            }else{
                openCount=openCount+1;
            }
        i++;
        cout<<"i="<<i<<"\n";
      }
    }
    return result;
}


int main(){
    string s;
    cin>> s; 
    cout<<longestValidParentheses(s);

}
