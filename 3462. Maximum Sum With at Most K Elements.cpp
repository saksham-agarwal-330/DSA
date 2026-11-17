// Problem 3462. Maximum Sum With at Most K Elements
// https://leetcode.com/problems/maximum-sum-with-at-most-k-elements

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long sum = 0;
        priority_queue<pair<int,int>> maxHeap;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                maxHeap.push({grid[i][j],i});
            }
        }

        while(k){
            auto largest = maxHeap.top();
            maxHeap.pop();

            if(limits[largest.second] > 0){
                sum += largest.first;
                limits[largest.second]--;
                k--;
            }
        }

        return sum;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<int> limits = {1, 2};
    int k = 2;

    cout<<sol.maxSum(grid,limits,k)<<endl;

    return 0;
}