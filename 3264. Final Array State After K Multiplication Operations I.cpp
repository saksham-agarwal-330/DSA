// Problem 3264. Final Array State After K Multiplication Operations I
// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1){
            return nums;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

        for(int i=0;i<nums.size();i++){
            minHeap.push({nums[i],i});
        }

        while(!minHeap.empty() && k){
            int miniVal = minHeap.top().first;
            int miniIdx = minHeap.top().second;
            minHeap.pop();
            int newVal = miniVal * multiplier;
            nums[miniIdx] = newVal;
            minHeap.push({newVal,miniIdx});
            k--;
        }
        return nums;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2, 1, 3, 5, 6};
    int k = 5;
    int multiplier = 2;
    vector<int>ans = sol.getFinalState(nums,k,multiplier);

    for(int num : nums){
        cout<<num<<" ";
    }

    return 0;

}