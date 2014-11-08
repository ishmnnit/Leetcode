#include<iostream>
using namespace std;


bool valid(string s){
        if (s.size()==0){return false;}
        if (s[0]=='0'){return false;}
        if (s.size()==2){
            if (s[0]>'2' || (s[0]=='2'&& s[1]>'6')){return false;}
        }
        return true;
 }


int numDecodings(string s) {
    int n=s.length();
    if (n==0){
        return 0;
    }

    int res[n];
    for(int i=0;i<n;i++)res[i]=0;
    if (s[0]!='0'){
        res[0]=1;
    } // set res[0]

    if (n==1){
        return res[0];
    }
    
    if (valid(s.substr(0,2))){
        res[1]++;
    } //set res[1]
    if (s[0]!='0' && s[1]!='0'){
        res[1]++;
    } //set res[1]
    
    for (int i=2;i<n;i++){
        if (s[i]!='0'){
            res[i]+=res[i-1];
        }
        
        if (valid(s.substr(i-1,2))){
                res[i]+=res[i-2];
            }
        }
         
        return res[n-1];

}

int main(){
    string s;
    cin>>s;
    cout<<numDecodings(s)<<"\n";
}
