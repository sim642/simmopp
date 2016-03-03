#include <iostream>

#include <simmo/vector.hpp>
#include <simmo/point.hpp>

using namespace std;
using namespace simmo;

int main()
{
    vector2d a(1, 2), b(5, 6), c(-2, 5);
    cout << a << endl;

    cout << +a << endl;
    cout << -a << endl;

    cout << a + b << endl;
    cout << a - c << endl;
    cout << 2.0 * a << endl;
    cout << a * 2.0 << endl;
    cout << a / 7.0 << endl;

    a += b;
    cout << a << endl;
    a -= c;
    cout << a << endl;

    a *= 2;
    cout << a << endl;
    a /= 7;
    cout << a << endl;

    cout << "--------" << endl;

    a = {1, 2};

    point2d A(5, 7), B(1, -3);
    cout << A << endl;

    cout << A + a << endl;
    cout << a + A << endl;
    cout << A - a << endl;
    cout << A - B << endl;

    A += a;
    cout << A << endl;
    A -= b;
    cout << A << endl;

    cout << "-----------" << endl;

    cout << norm(a) << endl;
    cout << dot(a, b) << endl;

    cout << norm(vector3i(5, 6, 8)) << endl;

    auto n = cross(vector3i{1, 2, 3}, vector3i{-1, 5, -10}) ;
    cout << n << " " << norm(n) << " " << normalize(n) << endl;

    return 0;
}