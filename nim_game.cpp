#include<iostream>
using namespace std;



int main(){
    int maxIncreament, winningNumber, currentNumber = 0;
    int playerTurn = 1;
    cout<<"Enter the increamenting number : ";
    cin>>maxIncreament;
    cout<<"Enter the winning number : ";
    cin>>winningNumber;

    cout << "\nGame starts now! First to reach " << winningNumber << " wins.\n";

    while(true){
        int choosenNumber;
        cout<<"Player "<<playerTurn<<" enter a number ( 1 to "<<maxIncreament<<" ) : ";
        cin>>choosenNumber;

        if(choosenNumber<1 || choosenNumber>maxIncreament){
            cout<<"Invalid Input! ChooseNumber between ( 1 to "<<maxIncreament<<" ).\n";
            continue;
        }

        currentNumber += choosenNumber;
        cout<<"Current Total : "<<currentNumber<<endl;

        if(currentNumber>=winningNumber){
            cout<<"The player "<<playerTurn<<" is the winner by reaching "<<winningNumber;
            break;
        }

        playerTurn = (playerTurn == 1)? 2 : 1;

    }

}