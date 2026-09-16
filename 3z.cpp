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

int& getElement(SafeArray& arr, int index) { // безопас. получ. эл.
    static int dummy = 0;

    if (index >= 0 && index < arr.size) {
        return arr.data[index];
    }

    cout << "Ошибка: индекс находится вне границ массива" << endl;

    return dummy;
}

void printSafe(const SafeArray& arr) {
    cout << "Массив: ";

    for (int i = 0; i < arr.size; i++) {
        cout << arr.data[i] << " ";
    }
    cout << endl;
}


int main() {
    //..
}