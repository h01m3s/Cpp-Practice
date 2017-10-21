#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal {
public:
    void getFamily() { cout << "We are animals" << endl; }
    // void getClass() { cout << "I'm an animal" << endl; }
    virtual void getClass() { cout << "I'm an animal" << endl; }
};

class Dog : public Animal {
public:
    void getClass() { cout << "I'm a dog" << endl; }
};

class GermanShepard : public Dog {
public:
    void getClass() { cout << "I'm a German Shepard" << endl; }
    void getDerived() { cout << "I'm a Animal and Dog " << endl; }
};

void whatClassAreYou(Animal *animal) {
    animal -> getClass();
}

int main(int argc, char const *argv[]) {

    Animal *animal = new Animal;
    Dog *dog = new Dog;

    animal->getClass();
    dog->getClass();

    // polymorphism
    whatClassAreYou(animal);
    whatClassAreYou(dog);

    Dog spot;
    GermanShepard max;
    Animal *ptrDog = &spot;
    Animal *ptrGShepard = &max;
    ptrDog->getFamily();
    ptrDog->getClass();

    ptrGShepard->getFamily();
    ptrGShepard->getClass();

    return 0;
}
