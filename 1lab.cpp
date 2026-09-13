#include <iostream>
using namespace std;

void fillArray(int (&arr)[10]) {      // arr ssilka na massiv is 10 el.
    cout << "Введите 10 элементов массива:" << endl;

    for (int& x : arr) {
        cin >> x;         // prohodim po vsem el. massiva
    }
}

void printArray(const int (&arr)[10]) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void swapElements(int (&arr)[10], int index1, int index2) {
    int temp = arr[index1];    // vrem. perem. 
    arr[index1] = arr[index2]; // pervay zamena
    arr[index2] = temp;        // vtoray zamena
}

void multiplyByTwo(int (&arr)[10]) {
    for (int& x : arr) {
        x *= 2;
    }
}

int main() { 
    int arr[10]; // sozdaem massiv

    fillArray(arr); // zapolniaem

    cout << "Исходный массив: ";
    printArray(arr);

    swapElements(arr, 0, 1); // meniaem 0 i 1 el.

    cout << "После обмена 1 и 2 элементов: ";
    printArray(arr);

    multiplyByTwo(arr); // umnozaem
    
    cout << "После умножения всех элементов на 2: ";
    printArray(arr);

    return 0;


}
