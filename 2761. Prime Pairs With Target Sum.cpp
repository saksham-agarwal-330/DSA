// Problem 2761. Prime Pairs With Target Sum
// https://leetcode.com/problems/prime-pairs-with-target-sum

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool>sieve(int n){
        vector<bool>primes(n+1,true);
        primes[0] = false;
        primes[1] = false;

        for(int i=2;i*i<=n;i++){
            if(!primes[i]){
                continue;
            }
            for(int p=i*i;p<=n;p = p+i){
                primes[p] = false;
            }
        }

        return primes;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool>primes = sieve(n);
        vector<vector<int>>ans;

        for(int i = 2;i<=n/2;i++){
            int j = n-i;
            if(primes[i] && primes[j]){
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    // int n = 2;
    int n = 10;
    vector<vector<int>>ans = sol.findPrimePairs(n);

    for(auto p : ans){
        cout<<p[0]<<" "<<p[1]<<endl;
    }

    return 0;
}