#pragma once
#include <iostream>
#include <unordered_map>

/**
 * The Abstract Factory Design Pattern is used to provide an interface for creating families of 
 * related or dependent objects without specifying their concrete classes. It is particularly 
 * useful in scenarios where your system needs to be decoupled from the specific implementations 
 * of the objects it creates.
*/

struct HotDrink
{
    virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink
{
    void prepare(int volume) override
    {
        std::cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon" << std::endl;
    }
};

struct Coffee : HotDrink
{
    void prepare(int volume) override
    {
        std::cout << "Grind some beans, boil water, pour " << volume << "ml, add cream and sugar" << std::endl;
    }
};

struct HotDrinkFactory
{
    virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Tea>();
    }
};

struct CoffeeFactory : HotDrinkFactory
{
    std::unique_ptr<HotDrink> make() const override
    {
        return std::make_unique<Coffee>();
    }
};

struct DrinkFactory
{
public:
    DrinkFactory()
    {
        hot_factories["tea"] = std::make_unique<TeaFactory>();
        hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
    }

    std::unique_ptr<HotDrink> make_drink(const std::string& name)
    {
        auto drink = hot_factories[name]->make();
        drink->prepare(200);
        return drink;
    }
private:
    std::unordered_map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
};

namespace AbstractFactory
{
    void run()
    {
        DrinkFactory df;
        df.make_drink("tea");
    }
}