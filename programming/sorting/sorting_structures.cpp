#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    int price;
    string name;
};

struct SortPriceAscending {
    bool operator() (const Product &a, const Product &b) {
        return a.price < b.price;
    }
};

void printVec(vector<Product> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i].price << ", " << vec[i].name << "\n";
    }
    return;
}

int main() {
    vector<Product> products;
    Product book;
    book.price = 10;
    book.name = "Book";
    products.push_back(book);

    Product car;
    car.price = 1999;
    car.name = "Car";
    products.push_back(car);

    sort(products.begin(), products.end(), SortPriceAscending());
    printVec(products);

    return 0;
}