#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<bool> extractData(string cells) {
    vector<bool> data;
    for(int i = 0; i < cells.size(); i++) {
        if(cells[i] == 'X') data.push_back(true);
        else data.push_back(false);
    }
    return data;
}

void printCells(vector<vector<bool> > cells) {
    for(int i = 0; i < cells.size(); i++) {
        for(int j = 0; j < cells[i].size(); j++) {
            if(cells[i][j] == true) cout << "X";
            else cout << ".";
        }
        cout << "\n";
    }
}

pair<int, int> getCoordinates(int i, int j) {
    if(i < 0) i = 12 + i;
    if(j < 0) j = 20 + j;
    if(i > 11) i = i - 12;
    if(j > 19) j = j - 20;
    return make_pair(i, j);
}

int countAliveNeighbors(int i, int j, vector<vector<bool> > &cells) {
    int counter = 0;
    for(int k = -1; k <= 1; k++) {
        for(int l = -1; l <= 1; l++) {
            if(abs(k) + abs(l) != 0) {
                int newI = i + k;
                int newJ = j + l;
                pair<int, int> neighborCoordinates = getCoordinates(newI, newJ);
                if(cells[neighborCoordinates.first][neighborCoordinates.second] == true) counter++;
            }
        }
    }
    return counter;
}

vector<vector<bool> > generation(vector<vector<bool> > cells) {
    vector<vector<bool> > newCells = cells;
    for(int i = 0; i < cells.size(); i++) {
        for(int j = 0; j < cells[i].size(); j++) {
            int aliveNeighbors = countAliveNeighbors(i, j, cells);
            //if(aliveNeighbors > 0) cout << "(" << i + 1 << ", " << j + 1 << "): " << aliveNeighbors << "\n";
            if(cells[i][j] == true) { //* alive, has 2 or 3 alive neighbors
                if(aliveNeighbors < 2 || aliveNeighbors > 3) newCells[i][j] = false;
            } else { //* dead, but has exactly 3 alive neighbors
                if(aliveNeighbors == 3) newCells[i][j] = true;
            }
        }
    }
    return newCells;
}

void a(vector<vector<bool> > cells) {
    for(int i = 0; i < 36; i++) {
        cells = generation(cells);
    }
    cout << "a) " << countAliveNeighbors(2-1, 19-1, cells) << "\n";
    return;
}

void b(vector<vector<bool> > cells) {
    cells = generation(cells);
    int aliveCounter = 0;
    for(int i = 0; i < cells.size(); i++) {
        for(int j = 0; j < cells[i].size(); j++) {
            if(cells[i][j] == true) aliveCounter++;
        }
    }
    cout << "b) " << aliveCounter << "\n";
    return;
}

bool areTheSame(vector<vector<bool> > &a, vector<vector<bool> > &b) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            if(a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

void c(vector<vector<bool> > cells) {
    vector<vector<bool> > previousCells = cells;
    for(int i = 0; i < 100 - 1; i++) {
        previousCells = cells;
        cells = generation(cells);
        if(areTheSame(previousCells, cells)) {
            int counter = 0;
            for(int i = 0; i < cells.size(); i++) {
                for(int j = 0; j < cells[i].size(); j++) {
                    if(cells[i][j] == true) counter++;
                }
            }
            cout << "c) " << i + 1 << ", " << counter << "\n";
            return;
        }
    }
    return;
}

int main() {
    fstream file;
    vector<vector<bool> > cells;
    file.open("gra.txt", ios::in);
    if(file.is_open()) {
        for(int i = 0; i < 12; i++) {
            string line;
            file >> line;
            cells.push_back(extractData(line));
        }
    }
    file.close();
    
    printCells(cells);
    cout << "\n";

    a(cells);
    b(cells);
    c(cells);
    return 0;
}