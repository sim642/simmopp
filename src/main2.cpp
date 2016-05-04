#include <iostream>

#include <simmo/bitmatrix.hpp>

using namespace std;
using namespace simmo;

int main()
{
    bitmatrix<2, 3> A = bitmatrix<2, 3>::eye();
    A(0, 2) = true;
    cout << A(0, 0) << endl;
    cout << A(0, 1) << endl;
    cout << A(0, 2) << endl;
    cout << A(1, 0) << endl;
    cout << A(1, 1) << endl;
    cout << A(1, 2) << endl;

    cout << endl;

    const bitmatrix<2, 3> B = A;
    cout << B(0, 0) << endl;
    cout << B(0, 1) << endl;
    cout << B(0, 2) << endl;
    cout << B(1, 0) << endl;
    cout << B(1, 1) << endl;
    cout << B(1, 2) << endl;
    return 0;
}