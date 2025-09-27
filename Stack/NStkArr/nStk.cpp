#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#include <bits/stdc++.h> 
class Node{
    public:
    int index;
    Node *next;

    Node(int x){
        index = x;
        next = NULL;
    }
};

class NStack
{
public:
    stack<int> st;
    int *arr;
    Node **Top;
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        arr = new int[S];
        Top = new Node *[N];
        for(int i=0;i<N;i++) Top[i]=NULL;
        for(int i=0;i<S;i++) st.push(i);
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Write your code here.
        if(st.empty()) return 0;

        arr[st.top()]=x;
        Node *temp = new Node(st.top());
        temp->next = Top[m-1];
        Top[m-1] = temp;
        st.pop();
        return 1;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        if(Top[m-1]==NULL) return -1;
        
        int element = arr[Top[m-1]->index];
        st.push(Top[m-1]->index);
        Top[m-1] = Top[m-1]->next;
        return element;
    }
};