#include<iostream>
#include<queue>
#include<vector>
using namespace std;

string solve(string A) {
std::string ans = "";
    // Frequency map for ASCII characters
    std::vector<int> counts(256, 0); 
    // Queue to store characters that have appeared once, in order
    std::queue<char> q;

    for (char c : A) {
        counts[c]++;
        
        if(counts[c]==1) q.push(c);
        
        while(!q.empty() && counts[q.front()]>1) q.pop();
        
        if(q.empty()) ans.push_back('#');
        else ans.push_back(q.front());
    }
    return ans;
}