#ifndef GROUPS_HPP
#define GROUPS_HPP

#include <functional>
#include <type_traits>
#include <concepts>
#include <vector>

template <typename T>
concept element_t = std::is_arithmetic_v<T>;

// Group class
template <element_t T, std::function<T(T, T)> op, typename Derived>
class Group 
{
private:
    T id_g;                             // Identity element
    int order;                          // Order of the group
    std::vector<T> elements;            // Elements of the group
    std::vector<std::vector<T>> table;  // Group table
    bool is_abelian;                    // Is the group abelian?
    bool is_cyclic;                     // Is the group cyclic?

public:
    Group() = default;

    Group(T id_g, std::vector<T> elements);

    T identity() const;

    std::vector<T> elements() const;

    std::vector<std::vector<T>> table() const;

};

#endif // GROUPS_HPP
