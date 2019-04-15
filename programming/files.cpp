#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("foo.txt", ios::in);
    if(file.good() == true)
    {
        while(!file.eof())
        {
            //! watch out - it's ignoring empty lines
            string temp;
            file >> temp;
            cout << temp << "\n";
        }
    }
    file.close();

    fstream file2;
    file2.open("foo2.txt", ios::out);
    if(file2.good() == true)
    {
        string temp = "text";
            file2 << temp;
    }
    file2.close();
}