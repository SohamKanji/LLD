#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * We can also take a functional approach to factory pattern.
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

class DrinkWithVolumeFactory
{
    map<string, function<unique_ptr<HotDrink>()>> factories;
public:
    
    DrinkWithVolumeFactory()
    {
        factories["tea"] = [] {
            auto tea = make_unique<Tea>();
            tea->prepare(200);
            return tea;
        };

        factories["coffee"] = [] {
            auto coffee = make_unique<Coffee>();
            coffee->prepare(100);
            return coffee;
        };
    }

    unique_ptr<HotDrink> make_drink(const string& name)
    {
        return factories[name]();
    }

};

