// Problem: 3727. Maximum Alternating Sum of Squares
// https://leetcode.com/problems/maximum-alternating-sum-of-squares

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>squares(n,0);
        for(int i = 0;i<n;i++){
            squares[i]= nums[i]*nums[i];
        }

        sort(squares.begin(),squares.end());

        long long score = 0;
        int i =0,j= n-1;
        while(i<=j){
            score += squares[j];
            if(i != j){
                score -= squares[i];
            }
            i++;
            j--;
        }
        return score;
    }
};

int main(){
    Solution sol;
    vector<int>nums = {1,-1,2,-2,3,-3};
    long long maxi = sol.maxAlternatingSum(nums);
    cout<<maxi<<endl;

    return 0;
}