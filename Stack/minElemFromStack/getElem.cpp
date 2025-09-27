#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class SpecialStack {
  public:
    stack<long long> st;
    long long mod = 1000000001LL;
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Add an element to the top of Stack
        if(st.empty()){
            long long val = 1LL*x*mod + x;
            st.push(val);
        } else{
            long long val = 1LL*x*mod + (min((long long)x, st.top()%mod));
            st.push(val);
        }
    }

    void pop() {
        // Remove the top element from the Stack
        if(!st.empty()){
            st.pop();
        }
    }
 
    int peek() {
        // Returns top element of the Stack
        if(st.empty()) return -1;
        return st.top()/mod;
    }

    bool isEmpty() {
        // Check if stack is empty
        if(st.empty()) return 1;
        return 0;
    }

    int getMin() {
        // Finds minimum element of Stack
        if(!st.empty()){
            return st.top() % mod;
        }
        return -1;
    }
};