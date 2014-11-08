#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;



string multiply(string num1, string num2) {

    int l1=num1.length();
    int l2=num2.length();

    vector<int> result(l1+l2,0);

    for(int i=0;i<l1;i++){
        int n1=num1[l1-i-1]-'0';
        int carry=0;
        for(int j=0;j<l2;j++){
            int n2=num2[l2-j-1]-'0';
            int sum=n1*n2+result[i+j]+carry;
            carry=sum/10;
            result[i+j]=sum%10;
        }
        if(carry!=0)
            result[i+l2]=result[i+l2]+carry;
    }
    int i=l1+l2-1;
    while(result[i]==0 && i>=0)
         i--;
    string res="";
    while(i>=0){
        res=res+char(result[i]+'0');
        i--;
    }
    return res;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<multiply(s1,s2);
}
