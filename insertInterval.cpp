#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct Interval {
    int start,end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    };


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    stack<Interval> st;
    vector<Interval> result;
    for(int i=intervals.size()-1;i>=0;i--){
        st.push(intervals[i]);
         };

    while(st.empty()==false){
        Interval top= st.top();
        st.pop();
        if(newInterval.start > top.end){
            result.push_back(top);
        }
        else{
            Interval temp;
            temp.start=min(top.start,newInterval.start);
            temp.end=max(top.end,newInterval.end);
            st.push(temp);
            break;
        }
    }

    while(st.size()>1){

        Interval top1=st.top();st.pop();
        Interval top2=st.top();st.pop();
        if(top1.end < top2.start){
            result.push_back(top1);
            result.push_back(top2);
            break;
        }
        else{
            cout<<"top1=" <<top1.start<<" "<<top1.end<<"\n";
            cout<<"top2="<<top2.start<<" "<<top2.end<<"\n";
            Interval top;
            top.start=min(top1.start,top2.start);
            top.end=max(top1.end,top2.end);
            st.push(top);
        }

    }

    while(st.empty()==false)
    {
        Interval top=st.top();
        st.pop();
        result.push_back(top);
    }

    return result;

}
    


int main(){
    vector<Interval> results;
    vector<Interval> input ;
    //[1,2],[3,5],[6,7],[8,10],[12,16]
    Interval top1,top2,top3,top4,top5;
    top1.start=1;top1.end=2;
    top2.start=3;top2.end=5;
    top3.start=6;top3.end=7;
    top4.start=8;top4.end=10;
    top5.start=12;top5.end=16;
    input.push_back(top1);input.push_back(top2);input.push_back(top3);input.push_back(top4);input.push_back(top5);
    Interval newInterval;
    newInterval.start=4;
    newInterval.end=9;
    results=insert(input,newInterval);
    for(int i=0;i<results.size();i++){
        cout<<"[ ";cout<<results[i].start<<","<<results[i].end<<"]"<<"\n";
    }                                              
    return 0;
}
