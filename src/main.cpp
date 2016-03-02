#include <iostream>

#include <simmo/vector.hpp>
#include <simmo/point.hpp>

using namespace std;
using namespace simmo;

int main()
{
    const vector3d a = {1, 2, 3};
    vector2d b{5, 6};
    vector3d c(1, 2, 5);
    vector2d d = b;
    b.y() = a.z();

    cout << a << " " << b << " " << c << " " << d << endl;
    cout << sizeof(a) << " " << sizeof(b) << endl;
    return 0;
}