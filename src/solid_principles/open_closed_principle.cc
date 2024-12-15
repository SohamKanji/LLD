#include "open_closed_principle.h"
#include <iostream>


std::vector<Product*> BetterFilter::filter(std::vector<Product*> items, Specification<Product>& spec) 
{
    std::vector<Product*> result;
    for (auto& item : items)
    {
        if (spec.is_satisfied(item))
        {
            result.push_back(item);
        }   
    }
    return result;
}

ColorSpecification::ColorSpecification(const Color color) : m_color(color) 
{

}

bool ColorSpecification::is_satisfied(Product* item) const {
    return item->color == m_color;
}

SizeSpecification::SizeSpecification(const Size size) : m_size(size) 
{

}

bool SizeSpecification::is_satisfied(Product* item) const {
    return item->size == m_size;
}

template <typename T> AndSpecification<T>::AndSpecification(const Specification<T>& first, const Specification<T>& second) : m_first(first), m_second(second)
{

}

template <typename T> bool AndSpecification<T>::is_satisfied(Product* item)  const
{
    return m_first.is_satisfied(item) && m_second.is_satisfied(item);
}

template <typename T> AndSpecification<T> operator&&(const Specification<T>& first, const Specification<T>& second)
{
    return {first, second};
}

void OpenClosedPrinciple::run()
{
    Product apple{"Apple", Color::Green, Size::Small};
    Product tree{"Tree", Color::Green, Size::Large};
    Product house{"House", Color::Blue, Size::Large};

    const std::vector<Product*> all {&apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green(Color::Green);
    auto green_things = bf.filter(all, green);

    std::cout << "Products filtered by green" << std::endl;
    for(auto& x: green_things) {
        std::cout << x->name << std::endl;
    }

    SizeSpecification large(Size::Large);
    auto large_green_spec = large && green;
    auto large_green_things = bf.filter(all, large_green_spec);
    std::cout << "Products filtered by large and green" << std::endl;
    for(auto& x: large_green_things) {
        std::cout << x->name << std::endl;
    }
}

