#include <iostream>
#include <windows.h>

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

void reSizeArray(SafeArray& arr, int newSize) {
    int* newData = new int[newSize]{};

    int minSize;

    if (arr.size < newSize)
        minSize = arr.size;
    else
        minSize = newSize;
    for (int i = 0; i < minSize; i++) {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = newSize;
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    SafeArray arr;

    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    createArray(arr, size);

    printSafe(arr);

    int index;

    cout << "Введите индекс элемета: ";
    cin >> index;

    cout << "Элемет: " << getElement(arr, index) << endl;

    int newSize;

    cout << "Введите новый размер массива: ";
    cin >> newSize;
    
    reSizeArray(arr, newSize);

    printSafe(arr);

    delete[] arr.data;
    arr.data = nullptr;

    return 0;

}