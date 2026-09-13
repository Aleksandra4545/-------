#include <iostream>
using namespace std;

void fillArray(int (&arr)[10]) {      // arr ssilka na massiv is 10 el.
    cout << "Введите 10 элементов массива:" << endl;

    for (int& : arr) {
        cin >> x;         // prohodim po vsem el. massiva
    }
}

