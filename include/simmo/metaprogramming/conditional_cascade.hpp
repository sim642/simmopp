#ifndef SIMMOPP_CONDITIONAL_CASCADE_HPP
#define SIMMOPP_CONDITIONAL_CASCADE_HPP

#include <type_traits>

namespace simmo
{

template<typename... Ts> struct make_void { typedef void type;};
template<typename... Ts> using void_t = typename make_void<Ts...>::type;

// primary template handles types that have no nested ::type member:
template< class, class = void_t<> >
struct has_type_member : std::false_type { };

// specialization recognizes types that do have a nested ::type member:
template< class T >
struct has_type_member<T, void_t<typename T::type>> : std::true_type { };

template<typename... Args>
struct conditional_cascade;

template<typename Arg, typename... Args>
struct conditional_cascade<Arg, Args...>
{
    typedef typename std::conditional_t<has_type_member<Arg>::value, Arg, conditional_cascade<Args...>>::type type;
};

template<>
struct conditional_cascade<>
{

};

template<typename T>
struct type_wrapper
{
    typedef T type;
};

}

#endif //SIMMOPP_CONDITIONAL_CASCADE_HPP
