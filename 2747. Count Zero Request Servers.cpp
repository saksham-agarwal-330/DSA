// Problem 2747. Count Zero Request Servers
// https://leetcode.com/problems/count-zero-request-servers?envType=daily-question&envId=2026-11-06

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();
        sort(logs.begin(), logs.end(), [](vector<int>&a, vector<int>&b){
            return a[1] < b[1];
        });

        int q = queries.size();
        vector<pair<int,int>>queryTimeIndex(q);
        for(int i = 0;i<q;i++){
            queryTimeIndex[i] = {queries[i],i};
        }

        sort(queryTimeIndex.begin(),queryTimeIndex.end());

        vector<int>ans(q);
        unordered_map<int,int>freq;
        int i = 0,j = 0;

        for(auto [query,time] : queryTimeIndex){
            int st = query - x;
            int en = query;

            while(j<m && logs[j][1] <= en){
                freq[logs[j][0]]++;
                j++;
            }

            while(i < m && logs[i][1] < st){
                freq[logs[i][0]]--;
                if(freq[logs[i][0]] == 0){
                    freq.erase(logs[i][0]);
                }
                i++;
            }

            ans[time] = n - freq.size();
        }

        return ans;
    }
};

int main(){
    Solution sol;
    int n = 3;
    vector<vector<int>> logs = {{1,3},{2,6},{1,5}};
    int x = 5;
    vector<int> queries = {10,11};

    vector<int> ans = sol.countServers(n,logs,x,queries);

    for(int i : ans){
        cout<<i<<" "<<endl;
    }

    return 0;
}