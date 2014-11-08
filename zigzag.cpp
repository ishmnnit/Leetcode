#include<iostream>
using namespace std;

string convert(string s, int nRows) {
    int boundry=2*(nRows-1);
    string result="";
    
    for(int i=0;i< nRows;i++){
        cout<<"i="<<i<<"\n";
        if(i==0 || i==nRows-1){
            int j=i;
            while(j<s.length()){
                result=result+s[j];
                j=j+boundry;
            }
        }
        else{
            cout<<"inside="<<i<<"\n";
            int large=2*(nRows-i-1);
            int small=boundry-large;
            bool flag=true;
            int j=i;
            while(j<s.length()){
                result=result+s[j];
                if(flag)
                    j=j+large;
                else
                    j=j+small;
                flag=!flag;
            } // end while
        } // end else

    }//end for
    return result;
}

int main(){
    string s;
    cin>> s;
    int row;
    cin>>row;
    cout<< convert(s,row);
}
