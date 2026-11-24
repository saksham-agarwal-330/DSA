// Problem 539. Minimum Time Difference
// https://leetcode.com/problems/minimum-time-difference

#include<iostream>
using namespace std;

class Solution {
public:
    int convertToMinutes(string time){
        int hour = (time[0] - '0')*10 + (time[1]-'0');
        int min = (time[3] - '0')*10 + (time[4]-'0');

        return hour*60 + min;
    }
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>minutes(n);
        for(int i = 0;i<n;i++){
            minutes[i] = convertToMinutes(timePoints[i]);
        }

        sort(minutes.begin(),minutes.end());

        int diff = INT_MAX;
        for(int i = 0;i<n-1;i++){
            diff = min(diff,minutes[i+1]-minutes[i]);
        }

        diff = min(diff,24*60 - minutes[n-1] + minutes[0]);
        return diff;
    }
};

int main(){
    Solution sol;
    vector<string> timePoints = {"00:00", "23:59", "00:00"};

    cout<<sol.findMinDifference(timePoints)<<endl;

    return 0;
}