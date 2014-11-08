#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 static bool myfunc(const Interval &a, const Interval &b){
        return (a.start < b.start);
    }
   vector<Interval> merge(vector<Interval> &intervals) {
    stack<Interval> st;
    vector<Interval> result;
    if(intervals.size()==0)
      return result;
      
    sort(intervals.begin(),intervals.end(),Solution::myfunc);
    for(int i=intervals.size()-1;i>=0;i--){
        st.push(intervals[i]);
    }

   while(st.size()>1){
       Interval top1=st.top();st.pop();
       Interval top2=st.top();st.pop();

       if(top1.end >= top2.start){
           Interval top;
           top.start=top1.start;
           top.end=max(top1.end,top2.end);
           st.push(top);
       }
       else{
           result.push_back(top1);
           st.push(top2);
       }
   }

   if(st.empty()==false){
       Interval top=st.top();
       result.push_back(st.top());
   }


    return result;
}

int main(){
    vector<Interval> results;
    vector<Interval> input ;
    Interval top1,top2,top3,top4;
    top1.start=1;top1.end=3;
    top2.start=4;top2.end=6;
    top3.start=8;top3.end=17;
    top4.start=15;top4.end=18;
    input.push_back(top1);input.push_back(top2);input.push_back(top3);input.push_back(top4);
    results=merge(input);
    for(int i=0;i<results.size();i++){
        cout<<"[ ";cout<<results[i].start<<","<<results[i].end<<"]"<<"\n";
    }

    return 0;
}
