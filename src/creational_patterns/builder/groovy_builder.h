#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
 * We are not having to create a separate builder class here.
*/
struct Tag {
    std::string name;
    std::string text;
    std::vector<Tag> children;
    std::vector<std::pair<std::string, std::string>> attributes;

    friend std::ostream& operator<<(std::ostream& os, const Tag& tag) {
        os << "<" << tag.name;

        for (const auto& attribute : tag.attributes) {
            os << " " << attribute.first << "=\"" << attribute.second << "\"";
        }

        if (tag.children.empty() && tag.text.empty()) {
            os << "/>" << std::endl;
        } else {
            os << ">" << std::endl;

            if (!tag.text.empty()) {
                os << tag.text << std::endl;
            }

            for (const auto& child : tag.children) {
                os << child;
            }

            os << "</" << tag.name << ">" << std::endl;
        }

        return os;
    }
};

struct P : Tag {
    P(const std::string& text) {
        name = "p";
        this->text = text;
    }

    P(std::initializer_list<Tag> children) : Tag{"p", ""} {
        for (const auto& child : children) {
            this->children.push_back(child);
        }
    }
};

struct IMG : Tag {
    explicit IMG(const std::string& url) {
        name = "img";
        attributes.emplace_back(std::make_pair("src", url));
    }
};

namespace GroovyBuilder {
    void run() {
        cout << 
            P {
                IMG { "http://example.com/image.png" }
            }
        << endl;
    }
}