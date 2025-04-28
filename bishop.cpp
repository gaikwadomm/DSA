#include<iostream>
#include<cmath>

using namespace std;

void bishop_path(int a, int b){
    int total = 0;

    // (1,1), (1,8), (8,1), (8,8)
    total = min(8-a,8-b)+min(a-1,b-1)+min(8-a,b-1)+min(a-1,8-b);
    
    cout<<"The total number of steps that the Bishop can go with are "<<total;
}

int main(){
    int a,b;
    do{
        cout<<"Enter the position along the x axis : ";
        cin>>a;
        if(a<1 || a>8){
            cout<<"The position should be in between 1 and 8 including both"<<endl;
            continue;
        }
        cout<<"Enter the position along the y axis : ";
        cin>>b;
        if(b<1 || b>8){
            cout<<"The position should be in between 1 and 8 including both"<<endl;
            continue;
        }
    }while((a<1 || a>8) || (b<1 || b>8));

    bishop_path(a,b);
}

