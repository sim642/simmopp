#include <iostream>
#include <simmo/vector.hpp>

using namespace std;
using namespace simmo;

int main()
{
    const vector3d a = {1, 2, 3};
    vector2d b = {5, 6};
    b.y() = a.z();

    cout << a.x() << " " << b.y() << endl;
    return 0;
}