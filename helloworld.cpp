#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

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

    return 0;
}
