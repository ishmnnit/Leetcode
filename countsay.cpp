#include<iostream>
using namespace std;


string next(string str){
    int count=1;
    string res;
    for(int i=0;i<str.length()-1;i++){
        if(str[i]==str[i+1])
            count++;
        else {
            res.push_back(count+'0');
            res.push_back(str[i]);
            count=1;
        }
    }
    res.push_back(count+'0');
    res.push_back(str[str.length()-1]);
    return res;
}

string countAndSay(int n) {
    string s="1";
    for(int i=1;i<n;i++){
     cout<<s<<"\n";    
     s=next(s);
    }         
    return s;
}

int main(){
    int n;
    cin>> n;
    cout<<"\n";
    cout<< countAndSay(n);
    cout<<"\n";
}
