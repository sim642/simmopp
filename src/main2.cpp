#include <iostream>

#include <simmo/bitmatrix.hpp>

using namespace std;
using namespace simmo;

int main()
{
    cout << (bitmatrix<4, 4>::eye() == bitmatrix<4, 4>{}.set(0, 0).set(1, 1).set(2, 2).set(3, 3)) << endl;
    cout << (bitmatrix<2, 3>::eye() == bitmatrix<2, 3>{}.set(0, 0).set(1, 1)) << endl;

    return 0;
}