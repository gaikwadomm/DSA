#include<iostream>
#include<vector>
using namespace std;

int longestUniqueString(string sentence){
    int n = sentence.size();
    vector<bool> count(256, 0);
    int first = 0, second = 0, length = 0, index;

    while(second<n){
        // index = (int)sentence[second];
        while(count[sentence[second]]){
            count[sentence[first]] = 0;
            first++;
        }
        count[sentence[second]] = 1;
        length = max(length, second -  first + 1);
        second++;
    }

    return length;
}

// int longestUniqueString(string sentence){
    // vector<int> capitalChar(26, 0);
    // int first = 0, second =0, index, count = 0,maxCount=0;
    // while(first<=second){
    //     if((int)sentence[second] >=65 && (int)sentence[second]<=90){
    //         index = (int)sentence[second] % 65;
    //     }
    //     else{
    //         index = ((int)sentence[second] % 97)+26;
    //     }

    //     repeatedChar[index] += 1;

    //     if(repeatedChar[index]>1){
    //         first = locateChar[index] + 1;
    //         locateChar[index] = second;
    //         repeatedChar[index]--;
    //         second++;
    //         if(count>maxCount){
    //             maxCount = count;
    //         }
    //         count = 0;
    //     }
    //     else{
    //         locateChar[index] = second;
    //         second++;
    //         count++;
    //     }
        
    // }

    // return maxCount;
// }

int main(){
    // longestUsingBF("ababc");
    cout<<"The answer is "<<longestUniqueString("abcdecbeadf");
}
