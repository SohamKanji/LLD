/**
 * Classes should be open for extension, but closed for modification.
*/

#pragma once
#include <string>
#include <vector>

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product {
    std::string name;
    Color color;
    Size size;
};

struct ProductFilter {
    std::vector<Product*> by_color(std::vector<Product*> items, Color color);
    std::vector<Product*> by_size(std::vector<Product*> items, Size size);
    std::vector<Product*> by_color_and_size(std::vector<Product*> items, Color color, Size size);

    /**
     * This is a violation of the Open/Closed Principle.
     * If we want to filter by size and color, we have to modify this class.
     * This class should be closed for modification.
    */ 
};

template <typename T> struct Specification {
    virtual bool is_satisfied(T* item) const = 0;
    /**
     * Look down below, we are also implementing the AndSpecification class.
     * Say, if i overload && operator here, then i won't even need to implement AndSpecification class, right?
     * But that would be a violation of the Open/Closed Principle. 
     * Because consequence of overloading && operator would be that we might need to modify child classes.
     * Instead we can define a free function, to overload the operator. 
    */
};

template <typename T> struct Filter {
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product> {
    std::vector<Product*> filter(std::vector<Product*> items, Specification<Product>& spec) override;
};

struct ColorSpecification : Specification<Product> {
    Color m_color;
    explicit ColorSpecification(const Color color);
    bool is_satisfied(Product* item) const override;
};

struct SizeSpecification : Specification<Product> {
    Size m_size;
    explicit SizeSpecification(const Size size);
    bool is_satisfied(Product* item) const override;
};

template <typename T> struct AndSpecification: Specification<T> {
    const Specification<T>& m_first;
    const Specification<T>& m_second;
    AndSpecification(const Specification<T>& first, const Specification<T>& second);
    bool is_satisfied(Product* item) const override;
};

template <typename T> AndSpecification<T> operator&&(const Specification<T>& first, const Specification<T>& second);

namespace OpenClosedPrinciple
{
    void run();
}

