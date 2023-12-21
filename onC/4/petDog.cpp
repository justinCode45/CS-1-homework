#include <iostream>

using namespace std;

class Pet
{
public:
    virtual void print();
    string name;
};

class Dog : public Pet
{
public:
    virtual void print();
    string breed;
};

int main()
{
    Pet *petPtr;
    Dog *dogPtr;
    cout << "this program test virtual function and late binding\n";

    dogPtr = new Dog;
    dogPtr->name = "Tiny";
    dogPtr->breed = "Great Dane";

    petPtr = dogPtr;

    cout << "print dog through dog pointer\n";
    petPtr->print();

    cout << "print dog through pet pointer\n";
    dogPtr->print();

    return 0;
}

void Pet::print()
{
    cout << "Pet " << this->name << endl;
}

void Dog::print()
{
    cout << "Dog name " << this->name << endl;
    cout << "Dog breed " << this->breed << endl;
}