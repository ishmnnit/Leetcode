#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };

class Solution {
public:

    double slopeCalculation(Point a ,Point b ){
       double slope;
       slope= (b.y - a.y)/(b.x - a.x);
       return slope;
    }

    int maxPoints(vector<Point> &points) {

        int n=points.size();
        if(n <=2)
            return n;

        int maxPoint=2;
        
        for(int i=0;i<n-1;i++){

            vector<double> slope;

            for(int j=i+1;j<n;j++){
                double s=slopeCalculation(points[i],points[j]);
                slope.push_back(s);                  
            }
            
            sort(slope.begin(),slope.end());
            int cnt=1;

            for(int k=0;k<(slope.size()-1);k++){
                if(fabs(slope[k] - slope[k+1]) < 0.00001)
                    cnt++;
                else{
                    if(cnt > maxPoint){
                        maxPoint=cnt;
                    }
                    cnt=1;
                }
            }
    
        }

        return maxPoint;        
    }
};


int main()
{
    Point p1(0,0),p2(1,1),p3(1,-1);
    vector<Point> points;
    points.push_back(p1);points.push_back(p2);points.push_back(p3);
    Solution o;
    cout<<o.maxPoints(points);

}
