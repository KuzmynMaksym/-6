#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функція для зчитування масиву з файлу
vector<int> readArrayFromFile(const string& filename) {
    vector<int> arr;
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Unable to open input file " << filename << endl;
        exit(1);
    }
    int num;
    while (inputFile >> num) {
        arr.push_back(num);
    }
    inputFile.close();
    return arr;
}

// Функція для виведення масиву у файл
void writeArrayToFile(const string& filename, const vector<int>& arr) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Unable to open output file " << filename << endl;
        exit(1);
    }
    for (int num : arr) {
        outputFile << num << " ";
    }
    outputFile.close();
}

// Функція для виведення розміру та вмісту масиву у консоль
void printArray(const vector<int>& arr) {
    cout << "Size of the resulting array: " << arr.size() << endl;
    cout << "Content of the resulting array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Функція для видалення непарних чисел з масиву
void removeOddNumbers(vector<int>& arr) {
    vector<int> temp;
    for (int num : arr) {
        if (num % 2 == 0) {
            temp.push_back(num);
        }
    }
    arr = temp;
}

int main() {
    string inputFilename, outputFilename;

    // Зчитуємо ім'я файлу з консолі
    cout << "Enter the input filename: ";
    cin >> inputFilename;

    // Зчитуємо масив з файлу
    vector<int> arr = readArrayFromFile(inputFilename);

    // Видаляємо непарні числа з масиву
    removeOddNumbers(arr);

    // Зчитуємо ім'я вихідного файлу з консолі
    cout << "Enter the output filename: ";
    cin >> outputFilename;

    // Записуємо результат у файл "array_out_n.txt"
    writeArrayToFile(outputFilename, arr);

    // Виводимо розмір та вміст масиву у консоль
    printArray(arr);

    return 0;
}