#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// ������� ��� ���������� ������ � �����
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

// ������� ��� ��������� ������ � ����
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

// ������� ��� ��������� ������ �� ����� ������ � �������
void printArray(const vector<int>& arr) {
    cout << "Size of the resulting array: " << arr.size() << endl;
    cout << "Content of the resulting array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// ������� ��� ��������� �������� ����� � ������
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

    // ������� ��'� ����� � ������
    cout << "Enter the input filename: ";
    cin >> inputFilename;

    // ������� ����� � �����
    vector<int> arr = readArrayFromFile(inputFilename);

    // ��������� ������ ����� � ������
    removeOddNumbers(arr);

    // ������� ��'� ��������� ����� � ������
    cout << "Enter the output filename: ";
    cin >> outputFilename;

    // �������� ��������� � ���� "array_out_n.txt"
    writeArrayToFile(outputFilename, arr);

    // �������� ����� �� ���� ������ � �������
    printArray(arr);

    return 0;
}