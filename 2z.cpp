#include <iostream>
using namespace std;

void process(int*& arr, int size) {

    int negativeIndex = -1;
    
    for (int i = 0; i < size; i++) { // находим 1 отр. эл.
        if (arr[i] < 0) {
            negativeIndex = i;
            break;
        }
    }

    if (negativeIndex == -1) {
        cout << "Отрицательных элементов нет" << endl;
        return;
    }

    int newSize = negativeIndex;
                                        // созд. новый массив разм. до отриц. эл. 
    int* newArr = new int[newSize]{};

    for (int i = 0; i < newSize; i++) {  // копир. эл.
        newArr[i] = arr[i];
    }

    delete[] arr; // освоб. старую память

    arr = newArr;

    cout << "Первый отрицательный элемент находится под индексом: " << negativeIndex << endl;

    cout << "Новый массив: ";

    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

}

int main() {
    int size;

    cout << "Введите размер массива: ";
    cin >> size;

    int* arr = new int[size]{}; // выдел. динам. память

    cout << "Введите элементы массива: " << endl; // заполн. массив

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";  // вывод. исход. массив

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    process(arr, size);

    delete[] arr;

    arr = nullptr;

    if (arr == nullptr) {
        cout << "Указатель arr обнулен" << endl;
    }

    return 0;
}

