/**
 * High-level modules should not depend on low-level modules. Both should depend on abstractions.
*/
#pragma once
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    std::string name;
};

struct RelationshipBrowser
{
    virtual std::vector<Person> find_all_children_of(const std::string& name) = 0;
};

struct Relationships : RelationshipBrowser // Low level module
{
    std::vector<std::tuple<Person, Relationship, Person>> relations;

    void add_parent_child_relationship(const Person& parent, const Person& child) {
        relations.push_back({parent, Relationship::parent, child});
        relations.push_back({child, Relationship::child, parent});
    }

    std::vector<Person> find_all_children_of(const std::string& name) override {
        std::vector<Person> result;
        for(auto&& [first, relation, second] : relations) {
            if(relation==Relationship::parent && first.name == name) {
                result.push_back(second);
            }
        }
        return result;
    }
};

struct Research // High level module
{
    Research(RelationshipBrowser& browser) 
    {
        for (auto& child: browser.find_all_children_of("John")) {
            std::cout << "John has a child called " << child.name << std::endl;
        }
    } // this depends on the abstraction, not on the concrete low-level module

    /**
     * the following implementaion depends on the exact
    */
    // Research(const Relationships& relationships) {
    //     auto& relations = relationships.relations;
    //     for(auto&& [first, relation, second] : relations) {
    //         if(relation==Relationship::parent && first.name == "John") {
    //             std::cout << "John has a child called " << second.name << std::endl;
    //         }
    //     }
    // }
};

namespace DependencyInversionPrinciple
{
    void run() {
        Person parent{"John"};
        Person child1{"Chris"};
        Person child2{"Matt"};

        Relationships relationships;
        relationships.add_parent_child_relationship(parent, child1);
        relationships.add_parent_child_relationship(parent, child2);

        Research _(relationships);
    }
}

