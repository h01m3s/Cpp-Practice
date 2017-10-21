// Binary Search Implementation

using namespace std;

int binSearch(int *arr, int target, int low, int high) {
    int mid;
    if (low > high) return -1;

    // mid = (low + high) /2;
    mid = low + (high - low) / 2;

    if (target == arr[mid]) {
        return mid;
    } else if (target < arr[mid]) {
        return binSearch(arr, target, low, mid - 1);
    } else {
        return binSearch(arr, target, mid + 1, high);
    }
}

int main(int argc, char const *argv[]) {
    return 0;
}
