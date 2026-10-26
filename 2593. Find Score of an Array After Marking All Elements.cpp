// 2593. Find Score of an Array After Marking All Elements
// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Compare{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        // index,val
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare>minHeap;

        for(int i =0;i<n;i++){
            minHeap.push({i,nums[i]});
        }

        vector<bool>mark(n,false);
        long long score = 0;
        while(!minHeap.empty()){
            auto small = minHeap.top();
            int idx = small.first;
            int val = small.second;
            if(!mark[idx]){
                score += val;
                mark[idx] = true;
                if(idx > 0){
                    mark[idx-1] = true;
                }
                if(idx < n-1){
                    mark[idx+1] = true;
                }
            }
            minHeap.pop();
        }

        return score;
    }
};

int main(){
    Solution sol;
    vector<int>nums={2,1,3,4,5,2};
    long long score = sol.findScore(nums);

    cout<<score<<endl;

    return 0;
}