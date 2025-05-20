#include<iostream>
#include<vector>
using namespace std;

bool checkPangram(string st){
    int n = st.size();
    vector<int> ans(26, 0); //26 element as 0
    if(n<26){
        return 0;
    }
    int ascii,index;
    for(char c:st){
        ascii = (int)c;
        if(ascii>=97 && ascii<=122){
            // index = c - 'a'; this also works
            index = ascii % 97; 
            cout<<endl<<index;
            ans[index] = 1;
        }
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i]==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    cout<<endl<<"The ans is "<<checkPangram("abcdefghajklmnopqrstuvwxyz");
}
