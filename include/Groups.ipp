#include "Groups.hpp"

template <element_t T, std::function<T(T, T)> op, typename Derived>
Group<T, op, Derived>::Group(T id_g, std::vector<T> elements)
    : id_g(id_g), elements(elements), order(elements.size()), is_abelian(false), is_cyclic(false)
{
    // Create the group table
    this->table = std::vector<std::vector<T>>(elements.size(), std::vector<T>(elements.size()));
    for (size_t i = 0; i < elements.size(); ++i)
    {
        for (size_t j = 0; j < elements.size(); ++j)
        {
            this->table[i][j] = op(elements[i], elements[j]);
        }
    }

    // Check if the group is abelian
    // TODO: Implement this
    
    // Check if the group is cyclic
    for (size_t i = 0; i < elements.size(); ++i)
    {
        T element = elements[i];
        bool is_cyclic = true;
        for (size_t j = 0; j < elements.size(); ++j)
        {
            if (op(element, elements[j]) != elements[j])
            {
                is_cyclic = false;
                break;
            }
        }
        if (is_cyclic)
        {
            this->is_cyclic = true;
            break;
        }
    }
}

