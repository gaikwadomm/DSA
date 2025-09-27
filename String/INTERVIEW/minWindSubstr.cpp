#include<iostream>
#include<vector>
#include<climits>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";

        vector<int> need(256, 0);
        vector<int> have(256, 0);

        int left = 0, right = 0, minLen = INT_MAX;
        int required = t.size(), start = 0;

        for(char c:t){
            need[c]++;
        }

        while(right<s.size()){
            char c = s[right];
            if(need[c]>0){
                if(have[c]<need[c]) required--;
                have[c]++;
            }

            while(required==0){
                if(right-left+1<minLen){
                    minLen = right-left+1;
                    start = left;
                }

                char lc = s[left];
                if(need[lc]>0){
                    have[lc]--;
                    if(have[lc]<need[lc]) required++;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
