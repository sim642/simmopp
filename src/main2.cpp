#include <iostream>

#include <simmo/bitmatrix.hpp>

using namespace std;
using namespace simmo;

int main()
{
    bitmatrix<4, 4> A;
    A.set(0, 1);
    A.set(1, 0).set(1, 1).set(1, 2).set(1, 3);
    A.set(2, 3);
    A.set(3, 0).set(3, 1).set(3, 3);

    bitmatrix<4, 4> P;
    P.set(0, 1).set(1, 0).set(2, 2).set(3, 3);

    auto M = P * A;
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            cout << M(row, col) << " ";
        }
        cout << endl;
    }
    return 0;
}