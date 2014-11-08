#include<iostream>
using namespace std;


 int numDistinct(string S, string T) {
     int n=S.length();
     int m=T.length();
     if(m > n )
         return 0;

     int mat[m+1][n+1];
     for(int i=0;i<=n;i++)
         mat[0][i]=1;
     for(int i=1;i<=m;i++)
         mat[i][0]=0;

     for(int i=1;i<=m;i++){
         for(int j=1;j<=n;j++){
             mat[i][j]=mat[i][j-1]+(T[i]==S[j]?mat[i-1][j-1]:0);
         }
     }

     return mat[m][n];
         
 }
int main(){

    string S = "rabbbit"; 
    string T = "rabbit";
    cout<<numDistinct(S,T);
}
