#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
int AliveNeighbors(const vector<vector<char>>& field, int row, int col, int rows, int cols) {
    int aliveCount = 0;
    for (int i = -1; i <= 1; ++i) 
    {
        for (int j = -1; j <= 1; ++j) 
        {
            if (i == 0 && j == 0) continue;

            int neighborRow = row + i;
            int neighborCol = col + j;
            if (neighborRow >= 0 && neighborRow < rows && neighborCol >= 0 && neighborCol < cols) {
                if (field[neighborRow][neighborCol] == '*') {
                    aliveCount++;
                }
            }
        }
    }
    return aliveCount;
}
int countTotalAlive(const vector<vector<char>>& field) 
{
    int count = 0;
    for (const auto& row : field) {
        for (char cell : row) {
            if (cell == '*') count++;
        }
    }
    return count;
}

void printField(const vector<vector<char>>& field, int generation, int aliveCount) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    cout << "Поколение: " << generation << " | Живых клеток: " << aliveCount << "\n\n";
    for (const auto& row : field) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string filename = "init.txt";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
        return 1;
    }

    int rows, cols;
    if (!(file >> rows >> cols)) {
        cerr << "Ошибка: Неверный формат размера сетки в файле." << endl;
        return 1;
    }

    vector<vector<char>> currentField(rows, vector<char>(cols, '-'));
    int r, c;
    while (file >> r >> c) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            currentField[r][c] = '*';
        }
    }
    file.close();

    int generation = 1;
    int aliveCount = countTotalAlive(currentField);
    printField(currentField, generation, aliveCount);

    string stopReason = "";

    while (true) 
    {
        if (aliveCount == 0) {
            stopReason = "Все клетки погибли.";
            break;
        }

        vector<vector<char>> nextField(rows, vector<char>(cols, '-'));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int neighbors = AliveNeighbors(currentField, i, j, rows, cols);

                if (currentField[i][j] == '*') {
                    if (neighbors == 2 || neighbors == 3) {
                        nextField[i][j] = '*';
                    }
                }
                else {
                    if (neighbors == 3) {
                        nextField[i][j] = '*';
                    }
                }
            }
        }

        if (currentField == nextField) {
            stopReason = "Сложилась стабильная конфигурация (состояние не меняется).";
            break;
        }
        currentField = nextField;
        generation++;
        aliveCount = countTotalAlive(currentField);

        printField(currentField, generation, aliveCount);

        this_thread::sleep_for(chrono::milliseconds(500));
    }
    printField(currentField, generation, aliveCount);
    cout << "========================================" << "\n";
    cout << "ИГРА ОСТАНОВЛЕНА" << "\n";
    cout << "Причина: " << stopReason << "\n";
    cout << "Итоговое количество поколений: " << generation << "\n";
    cout << "Живых клеток на момент окончания: " << aliveCount << "\n";
    cout << "========================================" << endl;

    return 0;
}