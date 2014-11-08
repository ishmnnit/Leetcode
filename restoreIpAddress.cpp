#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

bool isValid(string s){

    if(s.length()==1){
        if(s[0]=='0')
            return false;
    }else if(s.length()==2){
        if(s[0]=='0')
            return false;
    }else if(s.length()==3){
        if(atoi(s.c_str())>255)
            return false;
    }
    else {
        return false;
    }
    return true;

}

void restoreIpAddresses(string s,int count,int size,string current,vector<string> &result){
    if(count==size && s.length()==0){
        result.push_back(current.substr(0,current.length()-1));
        return;
    }
    for(int i=1;i<=3 && s.length()>=i;i++){
        if(isValid(s.substr(0,i))){
                restoreIpAddresses(s.substr(i),count+1,size,current+s.substr(0,i)+".",result);
        }
    }
}


vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string current;
    restoreIpAddresses(s,0,4,current,result);
    return result;
 }

int main(){

    vector<string> result;
    result=restoreIpAddresses("25525511135");
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<"\n";
    }
}
