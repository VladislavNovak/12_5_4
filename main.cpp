#include <iostream>

using std::cout;
using std::endl;

// BigO = n
int getDuplicate(int minValue, const int* arr, int arrSize) {
    int arraySum = 0;
    int sumSeq = 0;

    for (int i = 0, startValue = minValue; i < arrSize; ++i, ++startValue) {
        arraySum += arr[i];
        if (i < (arrSize - 1)) sumSeq += startValue;
    }

    int duplicate = arraySum - sumSeq;
    return duplicate;
}

// get the minimum value in the array. BigO = n
int getMinInArray(const int* arr, int arrSize) {
    int minValue = arr[0];

    for (int i = 0; i < arrSize; ++i) {
        int current = arr[i];
        if (current < minValue) minValue = current;
    }

    return minValue;
}

void findDuplicate(const int* arr, int arrSize) {
    int minValue = getMinInArray(arr, arrSize);
    int duplicate = getDuplicate(minValue, arr, arrSize);

    cout << "------------------" << endl;
    cout << "Min (start) value: \t\t" << minValue << endl;
    cout << "Repeating number in array: \t" << duplicate << endl;
}

int main() {
    const int ROW_COUNT = 3;
    const int LENGTH = 15;
    int table[ROW_COUNT][LENGTH] = {
            // start: 105, duplicate: 108
            {114, 111, 106, 107, 108, 105, 115, 108, 110, 109, 112, 113, 116, 117, 118},
            // start: 5, duplicate: 6
            { 7, 6, 11, 16, 18, 6, 12, 8, 17, 13, 9, 14, 15, 10, 5 },
            // start: 46, duplicate: 49
            {49, 50, 52, 51, 46, 58, 53, 57, 59, 54, 47, 55, 56, 49, 48 },
            };

    for (auto &row : table) findDuplicate(row, LENGTH);
}
