// Problem - 3963. Create Grid With Exactly One Path
// https://leetcode.com/problems/create-grid-with-exactly-one-path?envType=daily-question&envId=2026-10-27

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m);
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 || j == n-1){
                    grid[i].push_back('.');
                }
                else{
                    grid[i].push_back('#');
                }
            }
        }
        return grid;
    }
};

int main(){
    Solution sol;
    int rows = 2,cols = 3;
    vector<string>grid = sol.createGrid(rows,cols);

    for(int i =0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}