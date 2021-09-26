#include <iostream>
#include <vector>

#include "ComplexNumber.cpp"

int main() {

    ComplexNumber<int> complex1(2,3);
    ComplexNumber<int> complex2(7,4);
    ComplexNumber<int> complex3(7, 5);
    ComplexNumber<int> complex4(4,7);
    ComplexNumber<int> complex5(2,6);

    vector<ComplexNumber<int>> v;
    v.push_back(complex1);
    v.push_back(complex2);
    v.push_back(complex3);
    v.push_back(complex4);
    v.push_back(complex5);

    sortVector(v, IsGreaterThan<ComplexNumber<int>>());
    ostream out;
    for (ComplexNumber i : v) {
        operator<<(out, i);
    }

    return 0;
}
