#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

/*
FSTREAM
    fstream file;
    file.open("file.txt", ios::in | ios::out);
    if(file.good() == true)
    {
        while(!file.eof())
        {
            string temp;
            file >> temp;
        }
    }

SIEVE
    int size = 1000000;
	vector<bool> sieve (size + 1);
	for(int i = 2; i <= sqrt(size); i++) {
		for(int j = i; j <= size; j+=i) {
			if(j != i) //wykreslamy wielokrotnosci wieksze od i
				sieve[j] = true;
		}
	}

    for(int i = 2; i < size; i++) {
        if(sieve[i] == false) 
            cout << i << "\n";    
    }

OPERATONS ON VECTORS
#include <algorithm>
find(vector.begin(), vector.end(), item) != vector.end()
count (myvector.begin(), myvector.end(), 20);
*/

using namespace std;

int main()
{
    
}