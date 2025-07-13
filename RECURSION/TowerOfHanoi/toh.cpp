#include<iostream>
using namespace std;

void toh(int n, int source , int helper, int destination){
    if(n==1){
        cout << "Move disk "<<n<<" from rod " << source << " to rod " << destination << endl;
        return;
    }
    toh(n-1, source, destination, helper);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    toh(n-1, helper, source, destination);
}

int main(){
    int n = 5, source = 1, helper = 2, destination = 3;
    cout << "The sequence of moves involved in the Tower of Hanoi are: " << endl;
    toh(n, source, helper, destination);
    return 0;
}