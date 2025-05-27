#include<iostream>
#include<vector>
using namespace std;

int smallestDistinctWindow(string s){
    int n = s.length();
    int first = 0, second = 0, smallest = n, diff = 0;
    vector<int> count(256, 0);

    //Calculate number of unique charcter
    for(int i=0;i<n;i++){
        if(!count[s[i]]){
            count[s[i]] = 1;
            diff++;
        }
    }

    for(int i=0;i<256;i++){
        count[i]=0;
    }

    //Now slid the window
    while(second<n){
        //diff exists i.e find the window with all the char
        while(diff && second<n){
            if(!count[s[second]]){
                diff--;
            }
            count[s[second]]++;
            second++;
        }
        smallest = min(smallest, second - first);
        
        //start reducing the window 
        while(diff!=1){
            smallest = min(smallest, second - first);
            count[s[first]]--;
            if(count[s[first]]==0){
                diff++;
                // second++;
            }
            first++;
        }
    }
    return smallest;
}

int main(){
    cout<<"The min len substring with all the char in it is of length : "<<smallestDistinctWindow("AABBBCBBAC");
}
