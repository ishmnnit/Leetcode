#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct pairs
{
    int i;
    int h;
};

int maxArea(vector<int> &height) {
   if(height.size() <=1)
       return 0;
   int maxArea=0;
   int start=0;
   int end=height.size()-1;

   while(start<end){
        
       int area=(end-start)*min(height[start],height[end]);
       if(area > maxArea)
           maxArea=area;

       if(height[start] > height[end]){
           end--;
       }
       else{
           start++;
       }


   }
   return maxArea;

}

int main(){

}
