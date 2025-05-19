//The difference in the string and the array
//is that we dont have to give the size 
//at the end of the string there 
//will be the null character (\0) by default

#include<iostream>
#include<vector>
using namespace std;

int main(){
    //point to note 
    //if we input as om gaikwad 
    //than the output will om (bcoz of cin as when user put input if 
    //he put space, tab or enter than it will stop taking input)
    //bcoz there is space in between
    //so how to solve it
    //use getline(cin,string_variable_name);

    // string name;
    // cout<<"Enter the name : ";
    // cin>>name;
    // // name[2]='\0'; //if the input is tiger than the  
    //              //the output will be tier instead of e 
    //              //we replace it with the null character which 
    //              //will not print
    // cout<<name;

    string name;
    cout<<"Enter Name : ";
    getline(cin, name);  //works for tab and space not for enter 
                         //if enter than it will stop 
    cout<<name;
    cout<<endl;
    cout<<name.size();

    string fname = "om", lname = "gaikwad";
    // string newname = fname+lname;
    string newname = fname.append(lname);

    cout<<endl<<newname; //omgaikwad
    newname.push_back('a');
    cout<<endl<<newname;
    newname.pop_back();
    cout<<endl<<newname;
}

