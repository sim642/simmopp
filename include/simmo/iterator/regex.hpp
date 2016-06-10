#ifndef SIMMOPP_REGEX_ITERATOR_HPP
#define SIMMOPP_REGEX_ITERATOR_HPP

#include <regex>

namespace std
{

template<typename BidirIt, typename CharT, typename Traits>
auto& begin(std::regex_iterator<BidirIt, CharT, Traits> &iter) noexcept
{
    return iter;
};

template<typename BidirIt, typename CharT, typename Traits>
auto end(const std::regex_iterator<BidirIt, CharT, Traits> &iter) noexcept
{
    return std::regex_iterator<BidirIt, CharT, Traits>();
};

template<typename BidirIt, typename CharT, typename Traits>
auto begin(std::regex_token_iterator<BidirIt, CharT, Traits> iter) noexcept
{
    return iter;
};

template<typename BidirIt, typename CharT, typename Traits>
auto end(const std::regex_token_iterator<BidirIt, CharT, Traits> &iter) noexcept
{
    return std::regex_token_iterator<BidirIt, CharT, Traits>();
};

}

#endif //SIMMOPP_REGEX_ITERATOR_HPP
