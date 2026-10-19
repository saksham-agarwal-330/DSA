// Problem 2523. Closest Prime Numbers in Range
// https://leetcode.com/problems/closest-prime-numbers-in-range

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<bool> sieve(int n){
        if(n<2){
            return {};
        }
        vector<bool>primes(n+1,true);
        primes[0] = false;
        primes[1] = false;

        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j] = false;
                }
            }
        }

        return primes;
    }
    vector<int> closestPrimes(int left, int right) {
        if(right < 2){
            return  {-1,-1};
        }
        vector<bool>primes = sieve(right);
        int prev = -1;
        int diff = INT_MAX;
        vector<int>ans = {-1,-1};
        for(int i = left;i<=right;i++){
            if(primes[i]){
                if(prev != -1 && i-prev < diff){
                    diff = i-prev;
                    ans[0] = prev;
                    ans[1] = i;
                }
                prev = i;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int left = 10;
    int right = 19;

    vector<int>ans = sol.closestPrimes(left,right);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}