#ifndef SIMMOPP_BASIC_LINE_HPP
#define SIMMOPP_BASIC_LINE_HPP

#include "vector.hpp"
#include "point.hpp"

namespace simmo
{

template<typename T, size_t N>
class basic_line
{
public:
    typedef point<T, N> point_t;
    typedef vector<T, N> vector_t;
    
    basic_line() = default;
    
    basic_line(const point_t &n_p, const vector_t &n_v) : p(n_p), v(n_v)
    {
        
    }

    basic_line(const point_t &n_p1, const point_t &n_p2) : p(n_p1), v(n_p2 - n_p1)
    {

    }
    
    basic_line(point_t &&n_p, vector_t &&n_v) : p(std::move(n_p)), v(std::move(n_v))
    {
        
    }

    basic_line(point_t &&n_p1, point_t &&n_p2) : p(std::move(n_p1)), v(std::move(n_p2 - n_p1))
    {

    }

    template<typename U>
    explicit basic_line(const basic_line<U, N> &other) : p(other.p), v(other.v)
    {

    }

    auto& operator =(const basic_line<T, N> &other)
    {
        p = other.p;
        v = other.v;
        return *this;
    }

    auto& operator =(basic_line<T, N> &&other)
    {
        p = std::move(other.p);
        v = std::move(other.v);
        return *this;
    }

protected:
    point_t p;
    vector_t v;
};

}

#endif //SIMMOPP_BASIC_LINE_HPP
