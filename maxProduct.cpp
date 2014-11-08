#include<iostream>
#include<algorithm>
using namespace std;


int maxProduct(int A[], int n) {

    int maximum=1;

    int currentMax=1;
    int currentMin=1;

    for(int i=0;i<n;i++){
        if(A[i] > 0 ){
            currentMax=currentMax*A[i];
            currentMin=min(currentMin*A[i],1);
        }

        if(A[i]==0){
            currentMin=1;
            currentMax=1;
        }

        if(A[i] < 0) {
            int temp=currentMax;
            currentMax=max(currentMin*A[i],1);
            currentMin=temp*A[i];
        }

        if(currentMax > maximum )
            maximum=currentMax;
     }
    
    return maximum;
}

int main(){

    int arr[]={6,-3,-10,0,2};
    cout<< maxProduct(arr,5);
}

