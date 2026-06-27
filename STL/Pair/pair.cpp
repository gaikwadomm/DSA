#include<iostream>
#include<utility> //For including pair
using namespace std;



int main(){
    pair<string, int> name_age;
    name_age = make_pair("om", 19);

    cout<<name_age.first<<" ";
    cout<<name_age.second<<" ";

    pair<string, pair<int, int>> name_age_wt;
    name_age_wt = make_pair("om", make_pair(19,87));
    cout<<name_age_wt.first<<" ";
    cout<<name_age_wt.second.first<<" ";
    cout<<name_age_wt.second.second<<" ";
}