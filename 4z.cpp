#include <iostream>
#include <windows.h>

using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int students;
    int subjects;

    cout << "Введите кол-во студентов: ";
    cin >> students;

    cout << "Введите кол-во предметов: ";
    cin >> subjects;

    int** grades = new int*[students];  //созд. двумер. динамич. массив

    for (int i = 0; i < students; i++) { 
        grades[i] = new int[subjects]{};
    }

    for (int i = 0; i < students; i++) {  //заполн. оценки
        cout << "Введите оценки студента " << i + 1 << ":" << endl;

        for (int j = 0; j < subjects; j++) {
            cin >> grades[i][j];
        }
    }

    cout << endl << "Таблица оценок:" << endl;  //выводим матр. оценок

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {
            cout << grades[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Средние оценки студентов:" << endl; // счит. сред. оценку каждого студента

    for (int i = 0; i < students; i++) {
        int sum = 0;
        for (int j = 0; j < subjects; j++) {
            sum += grades[i][j];
        }
        double average = static_cast<double>(sum) / subjects;

        cout << "Студент " << i + 1 << ": " << average << endl;
    }

    for (int i = 0; i < students; i++) {
        delete[] grades[i];
    }

    delete[] grades;

    grades = nullptr;

    return 0;


}