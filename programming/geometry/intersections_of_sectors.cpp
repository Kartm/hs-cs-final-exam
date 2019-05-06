#include <iostream>
#include <cmath>

using namespace std;

struct point {
    double x;
    double y;
};

struct vec {
    double x;
    double y;
};

double vectorProduct(vec u, vec v) {
    return u.x * v.y - v.x * u.y;
}

bool doIntersect(point A, point B, point C, point D) {
    vec AB {B.x - A.x, B.y - A.y};
    vec CD {D.x - C.x, D.y - C.y};
    //* are the beginning and end of sector CD located on the opposite sides of line AB?
    vec AC {C.x - A.x, C.y - A.y};
    vec AD {D.x - A.x, D.y - A.y};
    //* both vAB * vAC and vAB * vAD must be of opposite signs
    cout << vectorProduct(AB, AC) << "\n";
    cout << vectorProduct(AB, AD) << "\n";
    return true;
}

//* vector product
int main() {
    point A, B, C, D;
    A.x = 0;
    A.y = 0;
    B.x = 1;
    B.y = 1;
    C.x = -1;
    C.y = 2;
    D.x = 2;
    D.y = -1;
    cout << doIntersect(A, B, C, D);
    return 0;
}