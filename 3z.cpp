#include <iostream>
using namespace std;

struct SafeArray {
    int* data;
    int size;
};

void createArray(SafeArray& arr, int size) { //сщздание массива
    arr.size = size;
    arr.data = new int[size]{};

    cout << "Введите элементы массива: " << endl;

    for (int i = 0; i < size; i++) {
        cin >> arr.data[i];
    }
}

int main() {
    //..
}