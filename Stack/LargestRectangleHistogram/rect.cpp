#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Finding the right next shortest form arr
        int n = heights.size();
        vector<int> h1(n, n);
        stack<int> st1;

        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[i]<heights[st1.top()]){
                h1[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }

        //Finding the left next shortest from arr
        vector<int> h2(n, -1);
        stack<int> st2;

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[i]<heights[st2.top()]){
                h2[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = h1[i] - h2[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }

        return maxArea;
    }
};