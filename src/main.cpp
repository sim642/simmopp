#include <iostream>
#include <simmo/vector.hpp>

using namespace std;
using namespace simmo;

int main()
{
    vector3d a = {1, 2, 3};
    vector3d b = {5, 6, 7};
    b.y() = a.z();

    cout << a.x() << " " << b.y() << endl;
    return 0;
}