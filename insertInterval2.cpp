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
    vector<Interval> result;
    int i=0;
    bool flag=true;
    if(intervals.size()==0 || newInterval.end < intervals[0].start){
        result.push_back(newInterval);
        flag=false;
    }

    while(i<intervals.size()){
        if(flag){
            if(intervals[i].end < newInterval.start){
                result.push_back(intervals[i]);
                i++;
            }
            else{
                if(newInterval.end < intervals[i].start){
                result.push_back(newInterval);
                }
                intervals[i].end=max(intervals[i].end,newInterval.end);
                intervals[i].start=min(intervals[i].start,newInterval.start);
                flag=false;
            }
        }
        else{
            if(i+1==intervals.size() || intervals[i].end < intervals[i+1].start)
                result.push_back(intervals[i]);
            else{
                intervals[i+1].end=max(intervals[i].end,intervals[i+1].end);
                intervals[i+1].start=min(intervals[i].start,intervals[i+1].start);
            }
            i++;
        }
    }
    if(intervals.size()!=0 || intervals[intervals.size()-1].end < newInterval.end)
        result.push_back(newInterval);
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
    newInterval.start=0;
    newInterval.end=15;
    results=insert(input,newInterval);
    for(int i=0;i<results.size();i++){
        cout<<"[ ";cout<<results[i].start<<","<<results[i].end<<"]"<<"\n";
    }                                              
    return 0;
}
