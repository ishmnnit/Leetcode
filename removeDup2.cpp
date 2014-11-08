#include<iostream>
using namespace std;



int removeDuplicates(){
}


int removeDuplicates2(int arr[], int n) {
    if(n<=1)
        return n;
    int count=1;
    bool flag=false;

    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1] && !flag)
        {
          count++;
          flag=true;
        }else if(arr[i]!=arr[i+1])
        {
            count++;
            flag=false;
        }
    }
    return count ;
}



int main()
{
    int arr[]={1,1,1,2,2,2,3,3};
    cout<<"Length of Duplicates="<<removeDuplicates2(arr,8)<<"\n";;

}
