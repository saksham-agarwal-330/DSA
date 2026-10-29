// Problem 2284. Sender With Largest Word Count
// https://leetcode.com/problems/sender-with-largest-word-count

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int countWords(string message){
        int count = 0;
        int n = message.length();
        for(int i = 0;i<n;i++){
            if(message[i] == ' '){
                count++;
            }
        }
        return count+1;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>senderWordCount;
        int maxWords = 0;
        string senderName = "";
        int n = messages.size();
        for(int i = 0;i<n;i++){
            int count = countWords(messages[i]);
            senderWordCount[senders[i]] += count;
            int total = senderWordCount[senders[i]];

            if (total > maxWords || (total == maxWords && senders[i] > senderName)) {
                maxWords = total;
                senderName = senders[i];
            }
        }

        return senderName;
    }
};

int main(){
    Solution sol;
    vector<string>messages = {"Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"};
    vector<string>senders = {"Alice","userTwo","userThree","Alice"};

    cout<<sol.largestWordCount(messages,senders)<<endl;

    return 0;

}

