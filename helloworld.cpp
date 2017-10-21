#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal {
private:
    int height;
    int weight;
    string name;

    static int numOfAnimals;

public:
    int getHeight() { return height; }
    int getWeight() { return weight; }
    string getName() { return name; }
    void setHeight(int cm) { height = cm; }
    void setWeight(int kg) { weight = kg; }
    void setName(string animalName) { name = animalName; }

    void setAll(int, int, string);

    Animal(int, int, string);
    ~Animal();

    Animal();

    static int getNumOfAnimals() { return numOfAnimals; }
    void toString();
};

// declar static variable
int Animal::numOfAnimals = 0;
void Animal::setAll(int height, int weight, string name) {
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

Animal::Animal(int height, int weight, string name) {
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numOfAnimals++;
}

Animal::~Animal() {
    cout << "Aimal " << this -> name << " destroyed" << endl;
}

Animal::Animal() {
    Animal::numOfAnimals++;
}

void Animal::toString() {
    cout << this -> name << " is " << this -> height << " cms tall and " << this -> weight << " kgs in weight" << endl;
}

class Dog: public Animal {
private:
    string sound = "Woof";
public:
    void getSound() { cout << sound << endl; }
    Dog(int, int, string, string);
    Dog():Animal(){};
    void toString();
};

Dog::Dog(int height, int weight, string name, string bark) : Animal(height, weight, name) {
    this -> sound = bark;
}

void Dog::toString() {
    cout << this -> getName() << " is " << this -> getHeight() << " cms tall and " << this -> getWeight() << " kgs in weight and says " << this -> sound;
}

// Default value can be assigned here
int addNumbers(int firstNum, int secondNum = 0) {
    int combinedValue = firstNum + secondNum;

    return combinedValue;
}

int addNumbers(int firstNum, int secondNum, int thirdNum) {

    return firstNum + secondNum + thirdNum;
}

int getFactorial(int number) {
    int sum;
    if (number == 1) sum = 1;
    else sum = getFactorial(number - 1) * number;
    return sum;
}

void numChanger(int* num) {
    cout << "Previous num " << *num << endl;
    *num = 55;
}


int main(int argc, char const *argv[]) {

    cout << "Hello World!" << endl;

    int five = 5;

    cout << "5++ = " << five++ << endl;
    cout << "++5 = " << ++five << endl;
    cout << "5-- = " << five-- << endl;
    cout << "--5 = " << --five << endl;

    // Array

    // int myFavNum[5];
    // int badNums[5] = {4, 13, 14, 24, 34};
    // cout << "Bad Number 1: " << badNums[0] << endl;
    //
    // char name[5][5] = { {'J', 'A', 'M', 'E', 'S'},
    //                     {'J', 'A', 'M', 'E', 'S'}
    // };
    //
    // cout << "random num: " << rand() % 100 << endl;

    // string numberGuessed;
    // int intNumberGuessed = 0;
    //
    // do {
    //     cout << "Guess between 1 and 10: ";
    //     getline(cin, numberGuessed);
    //     intNumberGuessed = stoi(numberGuessed);
    //     cout << intNumberGuessed << endl;
    // } while (intNumberGuessed !=4);
    //
    // cout << "You Win." << endl;
    //
    // string yourName;
    // cout << "What's your name? \n";
    // getline(cin, yourName);
    //
    // cout << "Hello " << yourName << endl;

    vector<int> lotteryNumVect(10);
    int lotteryNumArray[5] = {4, 13, 14, 24, 34};

    // lotteryNumArray+3 means only take first 3 number from array
    lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);
    lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);
    cout << lotteryNumVect.at(5) << endl;

    // Inser in the end of vector
    lotteryNumVect.push_back(64);

    cout << "Final Value " << lotteryNumVect.back() << endl;

    lotteryNumVect.pop_back();

    cout << addNumbers(1) << endl;
    cout << addNumbers(1, 5, 6) << endl;

    cout << "The factorial of 3 is " << getFactorial(3) << endl;

    // File IO
    string outWord = "Sample out word.";

    ofstream writer("out.txt");
    if (!writer) {
        cout << "Error opening file" << endl;
        return -1;
    } else {
        writer << outWord << endl;
        writer.close();
    }

    // append string
    ofstream writer2("out.txt", ios::app);
    if (!writer2) {
        cout << "Error opening file" << endl;
        return -1;
    } else {
        writer2 << "Line Appended." << endl;
        writer2.close();
    }

    char letter;
    ifstream reader("out.txt");
    if (!reader) {
        cout << "Error opening file" << endl;
        return -1;
    } else {
        for (int i = 0; !reader.eof(); i++) {
            reader.get(letter);
            cout << letter;
        }
        cout << endl;
        reader.close();
    }

    int number = 0;

    // Simple exception handling
    try {
        if (number != 0) {
            cout << 2/number << endl;
        } else throw(number);
    } catch (int number) {
        cout << number << " is not valid" << endl;
    }

    // pointer and reference
    int myNum = 7;
    int* myNumPtr = &myNum;
    cout << "Address of pointer " << myNumPtr << endl;
    cout << "Data at memory address " << *myNumPtr << endl;

    int badNums[5] = {4, 13, 14, 24, 34};
    int *numArrPtr = badNums;
    cout << "Address " << numArrPtr << " Value " << *numArrPtr << endl;
    numArrPtr++;
    cout << "Address " << numArrPtr << " Value " << *numArrPtr << endl;
    cout << "Address " << badNums << " Value " << *badNums << endl;

    numChanger(myNumPtr);
    cout << "myNum is now " << myNum << endl;

    int& myNumRef = myNum;
    cout << "myNum: " << myNum << endl;
    myNumRef++;
    cout << "myNum: " << myNum << endl;

    Animal fred;
    fred.setHeight(33);
    fred.setWeight(10);
    fred.setName("Fred");
    cout << fred.getName() << " is " << fred.getHeight() << " cms tall and " << fred.getWeight() << " kgs in weight" << endl;

    Animal tom(36, 15, "Tom");
    cout << tom.getName() << " is " << tom.getHeight() << " cms tall and " << tom.getWeight() << " kgs in weight" << endl;

    Dog spot(38, 16, "Spot", "Woof");
    cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;
    spot.getSound();
    tom.toString();
    spot.toString();

    // call functioin of super class
    spot.Animal::toString();

    return 0;
}
