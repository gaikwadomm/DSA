#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if (k > n) return q; // if k > size, return as is
    
        stack<int> st;

        for (int i = 0; i < k; i++) {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
     
        for (int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }
    
        return q;
    }
};