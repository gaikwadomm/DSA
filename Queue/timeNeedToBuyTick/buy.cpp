#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//O(n^2) in worst case TC
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);

        while(tickets[k]){
            tickets[q.front()]--;
            if(tickets[q.front()]){
                q.push(q.front());
            }
            q.pop();
            time++;
        }
        return time;
    }
};

//O(n) TC
class AnotherSolution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                time+=min(tickets[i], tickets[k]);
            } else{
                time += min(tickets[k]-1, tickets[i]);
            }
        }

        return time;
    }
};