#include <iostream>
#include "basic_vector.hpp"

using namespace std;

typedef basic_vector<double, 2> Vec2d;
typedef basic_vector<double, 3> Vec3d;

int main()
{
    Vec3d a = {1, 2, 3};
    Vec3d b = {-2, 3, 0.5};
    Vec2d c = {1, 5};

    Vec2d d = b.zy();
    cout << d << endl;
    d = d.yx();
    cout << d << endl;

    cout << b << endl;
    b.zy() = b.xz();
    cout << b << endl;

    return 0;
}