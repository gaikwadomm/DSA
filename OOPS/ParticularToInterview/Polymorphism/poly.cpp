#include<iostream>
using namespace std;

//function overloading
class Area{
    public:
    int calculateArea(int r){
        return 3.14*r*r;
    }
    //will give the error as the parameter are not different
    // int calculateArea(int l){
    //     return l;
    // }

    int calculateArea(int l, int b){
        return l * b;
    }
};

//Operator overloading
class Complex{
    int real, img;
    public:
    Complex(){
        real = 0;
        img = 0;
    }

    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    void display(){
        cout<<real<<" +i"<<img;
    }
    Complex operator +(Complex& c){
        Complex ans;                    
        ans.real = this->real + c.real;
        ans.img = this->img + c.img;
        return ans;
    }
};

int main(){
    // Area a1, a2;
    // cout<<a1.calculateArea(2)<<endl;
    // cout<<a2.calculateArea(3);

    //Operator overloading
    Complex c1(3,2);
    Complex c2(4, 6);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}