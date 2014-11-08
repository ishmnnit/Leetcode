#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include <limits.h>
using namespace std;

int mincut(string s){

    int n=s.length();
    int c[n][n];
    bool p[n][n];

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             c[i][j]=2147483647;
         }
        }
    for(int i=0;i<n;i++){
        c[i][i]=0;
        p[i][i]=true;
    }

    for(int L=2;L<=n;L++){
        for(int i=0;i<n-L+1;i++){
            int j=i+L-1;
            if(L==2){
                if(s[i]==s[j]){
                    p[i][j]=true;
                    c[i][j]=0;
                }
                else {
                    p[i][j]=false;
                    c[i][j]=1;
                }
            }
            else{
                p[i][j]=(s[i]==s[j]) && p[i+1][j-1];
            }

            if(p[i][j]==true)
                c[i][j]=0;
            else{
                for(int k=i;k<j;k++){
                   c[i][j]=min(c[i][j],c[i][k]+1+c[k+1][j]);
                }
            }
        }

    }
    return c[0][n-1];
}

int main()
{
    string s;
    cin>> s;
    cout<<"Min Cut="<< mincut(s)<<"\n";;
}
