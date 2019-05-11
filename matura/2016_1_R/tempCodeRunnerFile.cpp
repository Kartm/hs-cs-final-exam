fstream file;
    vector<string> wrong;
    file.open("dane_6_3.txt", ios::in);
    if(file.is_open()) {
        for(int i = 0; i < 3000; i++) {
            string a, b;
            file >> a >> b;
            if(isWrong(a, b)) {
                wrong.push_back(a);
            }
        }
    }
    file.close();

    file.open("wyniki_6_3.txt", ios::out);
    if(file.is_open()) {
        for(int i = 0; i < wrong.size(); i++) {
            file << wrong[i] << "\n";
        }
    }
    file.close();