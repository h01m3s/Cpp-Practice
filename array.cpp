#include <iostream>
#include <array>

void PrintArray(int* array, unsigned int size) {

}

int main(int argc, char const *argv[]) {
    // have bounds check optionaly
    // On stack
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;

    // change data arr don't own if out of bounds
    int dataOld[5];
    dataOld[0] = 0;

    return 0;
}
