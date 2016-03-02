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

    return 0;
}