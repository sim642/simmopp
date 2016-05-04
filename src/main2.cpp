#include <iostream>

#include <simmo/bitmatrix.hpp>

using namespace std;
using namespace simmo;

int main()
{
    bitmatrix<2, 3> A = bitmatrix<2, 3>::eye();
    const bitmatrix<2, 3> B = bitmatrix<2, 3>{}.set(0, 2);
    A += B;

    cout << A(0, 0) << endl;
    cout << A(0, 1) << endl;
    cout << A(0, 2) << endl;
    cout << A(1, 0) << endl;
    cout << A(1, 1) << endl;
    cout << A(1, 2) << endl;
    return 0;
}