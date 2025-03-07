#include "VecNf.h"
void doNothing(VecNf tar) { return; }

int main()
{
    float a_value[] = { 3.0, 2.0 };
    float b_value[] = { 1, 2, 3 };
    float c_value[] = { 6, 5, 4 };
    float d_value[] = { 10.0, 5.0 };
    float e_value[] = { 11, 12, 13 };
    VecNf A(a_value, 2);
    VecNf B(b_value, 3);
    VecNf C(c_value, 3);
    VecNf D(d_value, 2);
    VecNf E(e_value, 3);
    VecNf T;


    cout << A + D << endl; //Assignment & Outputs the vector

    cout << E - B << endl; // Vector subtraction & Outputs the vector

    cout << B + C + E << endl; //Vector addition & Outputs the vector

    cout << C - B << endl; // Vector subtraction & Outputs the vector

    cout << A + D << endl; // Vector addition&Outputs the vector

    doNothing(T); // call by value

    cout << E[2] << endl; // Indexing

    cout << E * B << endl; // Inner Product

    cout << 5 * D << endl; // Scalar

    cout << A * C << endl; // Inconsistent

    return 0;
}