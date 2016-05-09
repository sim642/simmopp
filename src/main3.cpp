#include <iostream>
#include <unordered_map>
#include <cassert>

#include <simmo/point.hpp>

using namespace std;
using namespace simmo;

int main()
{
    unordered_map<point2i, int> m;
    assert((point2i{-1, -2} == point2i{-1, -2}));
    assert((hash<point2i>()(point2i{-1, -2}) == hash<point2i>()(point2i{-1, -2})));
    m.emplace(make_pair(point2i{-1.0, -2}, 123));
    m.emplace(make_pair(point2i{-1.0, 3.0}, 2));
    m.emplace(make_pair(point2i{-1.0, -123123.1}, 1));

    m[point2i{-1.0, -2}] = 3;
    for (const auto &p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}