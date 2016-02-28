#include <iostream>
#include "simmo/basic_vector.hpp"

using namespace std;
using namespace simmo;

//typedef basic_vector<double, 0> Vec0d;
typedef basic_vector<double, 1> Vec1d;
typedef basic_vector<double, 2> Vec2d;
typedef basic_vector<double, 3> Vec3d;

int main()
{
    Vec3d a = {1, 2, 3};
    Vec3d b(-2, 3, 0.5);
    Vec2d c{1, 5};

    Vec2d d = b.zy();
    cout << d << endl;
    d = d.yx();
    cout << d << endl;

    cout << b << endl;
    b.zy() = b.xz();
    cout << b << endl;
    b.yzx() = a.zxy();
    cout << b << endl;

    Vec1d v = 5;
    Vec1d u = v.x();
    cout << u << endl;

    double k = u.x();
    cout << k << endl;

    v.x() = 6;
    cout << v << endl;

    d.swizzle() = a.yx();
    cout << d << endl;

    return 0;
}