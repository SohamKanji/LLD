/**
 * Lets us create complex objects step by step.
*/

#pragma once
#include <string>
#include <vector>
#include <sstream>  
#include <iostream>
#include "groovy_builder.h"
#include "builder_facet.h"

using namespace std;

class HTMLElement
{
    /**
     * We can make HTMLBuilder a friend class of HTMLElement so that it can access private members of HTMLElement.
     * This way client code can't directly create HTMLElement objects, they have to use HTMLBuilder to create HTMLElement objects.
    */
    friend class HTMLBuilder;
    string name, text;
    vector<HTMLElement> elements;
    const size_t indent_size = 2;
    HTMLElement() {}
    HTMLElement(const string& name, const string& text) : name(name), text(text) {}
public:
    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if (text.size() > 0)
            oss << string(indent_size * (indent + 1), ' ') << text << endl;

        for (const auto& e : elements)
            oss << e.str(indent + 1);

        oss << i << "</" << name << ">" << endl;
        return oss.str();
    }  
};

struct HTMLBuilder
{
    HTMLElement root;

    HTMLBuilder(string root_name)
    {
        root.name = root_name;
    }

    HTMLBuilder& add_child(string child_name, string child_text)
    {
        HTMLElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }

    string str() const { return root.str(); }

    static HTMLBuilder create(string root_name)
    {
        return HTMLBuilder(root_name);
    }

    HTMLElement build() { return root; }
};

namespace Builder
{
    void run()
    {
        HTMLBuilder builder{"ul"};
        builder.add_child("li", "hello").add_child("li", "world");
        cout << builder.str() << endl;

        auto builder2 = HTMLBuilder::create("ul").add_child("li", "hello").add_child("li", "world");
        cout << builder2.str() << endl;
    }
} // namespace Builder