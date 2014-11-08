#include<iostream>
#include<vector>
using namespace std;


void computeLPS(string pat, vector<int> &lps){
    int len = 0;  // length of the previous longest prefix suffix
    int i=1;
    lps.push_back(0); // lps[0] is always 0
    int M=pat.length();
 
    // the loop calculates lps[i] for i = 1 to M-1
    while(i < M){
       if(pat[i] == pat[len]){
         len++;i++;
         lps.push_back(len);
       }
       else { // (pat[i] != pat[len]){
         if( len != 0 ){ // This is tricky. Consider the example AAACAAAA and i = 7.
           len = lps[len-1];// Also, note that we do not increment i here
         }
         else { // if (len == 0){
           lps.push_back(0);
           i++;
         }
        } 
    }
}

int kmp(string txt,string pat){
    vector<int> lps;
    computeLPS(txt,lps);
    int n=txt.length();
    int m=pat.length();

    int i=0,j=0;

    while(i<n){
        if(txt[i]==pat[j]){
            i++;j++;
            if(j==m) // Pattern found
                return i-j;
        }
        else{
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
    return -1;
}

int main(){
 vector<int> lps ;
// computeLPS("AABAACAABAA",lps);
 //for(int i=0;i<lps.size();i++)
   //  cout<<lps[i]<<"\t";

 string txt = "ABABDABACDABABCABAB";
 string pat = "ABABCABAB";
 cout<<kmp(txt,pat);
}
