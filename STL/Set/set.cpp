#include<iostream>
#include<set>
using namespace std;

class Person{
    public:
    string name;
    int age;

    //Set me kis hisab se sort ya arrange hoga uska method
    // 
    // Overloads the less-than operator (<) for the Person class to enable comparison based on the 'age' member.
    // This allows objects of Person to be compared using their ages, which is particularly useful when storing
    // Person objects in ordered containers like std::set or std::map, where elements are sorted according to this operator.
    //
    // Internally, when two Person objects are compared using <, this operator function is called with the left-hand side
    // object as 'this' and the right-hand side object as 'other'. The function returns true if the age of the current
    // object is less than the age of 'other', and false otherwise. This comparison is used by STL containers to maintain
    // order and uniqueness of elements.
    bool operator < (const Person &other) const{
        return age < other.age;
    }
};

int main(){
    //In set duplicate elements are not allowed
    //Elements are stored in sorted order
    //Underlying data structure is balanced BST or AVL Tree or Red-Black Tree
    set<int>s;
    //insert
    s.insert(7);
    s.insert(1);
    s.insert(2);
    s.insert(2);

    for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";

    //Search
    if(s.find(71)!=s.end()) cout<<endl<<7<<" present.";

    cout<<endl<<s.count(7);

    s.insert(71);
    s.erase(71);
    cout<<endl<<s.count(71)<<endl;

    // set<int, greater<int>>sDescend;
    // //insert
    // sDescend.insert(7);
    // sDescend.insert(1);
    // sDescend.insert(2);
    // sDescend.insert(2);

    // for(auto it=sDescend.begin();it!=sDescend.end();it++) cout<<*it<<" ";

    set<Person> sp;
    Person p1, p2, p3;
    p1.name = "Om Gaikwad";
    p1.age = 19;
    p2.name = "John Doe";
    p2.age = 18;
    p3.name = "Jane Doe";
    p3.age = 21;
    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);

    for(auto it=sp.begin();it!=sp.end();it++){
        cout<<it->name<<" "<<it->age<<endl;
    }
}