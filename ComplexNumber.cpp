//
// Created by clinton schultz on 5/5/21.
//

#ifndef COMPLEXNUMBER_COMPLEXNUMBER
#define COMPLEXNUMBER_COMPLEXNUMBER

#include <string>
#include <vector>
#include <iostream>

using namespace std;

template<typename Object>
class ComplexNumber
{
    public:
        explicit ComplexNumber(const Object & a, const Object & b) : first(a), second(b) { }
        Object getA() const { return first; }
        Object getB() const { return second; }

    private:
        Object first, second;
};

template<typename Object>
ComplexNumber<Object> operator+(const ComplexNumber<Object> & lhs, const ComplexNumber<Object> & rhs) {
    ComplexNumber<Object> answer(lhs);
    answer += rhs;
    return answer;
}

template<typename Object>
ComplexNumber<Object> operator-(const ComplexNumber<Object> & lhs, const ComplexNumber<Object> & rhs) {
    if (lhs > rhs) {
        ComplexNumber<Object> answer(lhs);
        answer -= rhs;
        return answer;
    }
    else {
        ComplexNumber<Object> answer(rhs);
        answer -= lhs;
        return answer;
    }
}

template<typename Object>
ostream & operator<<(ostream & out, const ComplexNumber<Object> & rhs) {
    rhs.print(out);
    return out;
}

template<typename Object>
class IsGreaterThan
{
    public:
        bool operator() (const Object & lhs, const Object & rhs) const
        {
            if (lhs.getA() != rhs.getA()) {
                if (lhs.getA() > rhs.getA()) { return rhs < lhs; }
                else { return rhs > lhs; }
            }
            else {
                if (lhs.getB() > rhs.getA()) { return rhs < lhs; }
                else { return rhs < lhs; }
            }
        }
};

template<typename T, typename Comparator>
void sortVector(vector<T*> & v, Comparator isGreaterThan) {
    bool sorted = false;

    while (!sorted) {
        sorted = true;
        for (int i = 0; i < v.size() - 1; i++) {
            if (isGreaterThan(*v[i+1], *v[i])) {
                sorted = false;
                T* temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
}

template <typename T, typename Comparator>
bool sortVerification(const vector<T*> & v, Comparator isGreaterThan) {
    for (int i = 1; i < v.size(); i++) {
        if (isGreaterThan(*v[i], *v[i-1])) {
            return false;
        }
    }
    return true;
}

#endif