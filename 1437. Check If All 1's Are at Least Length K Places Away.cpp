// Problem 1437. Check If All 1's Are at Least Length K Places Away
// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int prev = -1;
        for(int i = 0;i<n;i++){
            if(nums[i] == 1){
                if(prev == -1){
                    prev = i;
                }
                else{
                    int dis = i-prev-1;
                    if(dis < k){
                        return false;
                    }
                    prev = i;
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,0,0,0,1,0,0,1};
    int k = 2;

    if(sol.kLengthApart(nums,k)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

    return 0;
}