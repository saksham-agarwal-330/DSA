// Problem 2554. Maximum Number of Integers to Choose From a Range I
// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>ban;
        for(int num : banned){
            ban.insert(num);
        }
        int sum = 0;
        int count = 0;
        int i = 1;
        while(i<=n){
            if(ban.find(i) == ban.end()){
                sum += i;
                if(sum <= maxSum){
                    count++;
                }
                else{
                    break;
                }
            }
            i++;
        }

        return count;
    }
};

int main(){
    Solution sol;
    vector<int> banned = {1, 6, 5};
    int n = 5;
    int maxSum = 6;

    cout<<sol.maxCount(banned,n,maxSum)<<endl;

    return 0;
}