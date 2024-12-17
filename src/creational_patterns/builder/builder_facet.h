#pragma once
#include "person_builder.h" 

namespace BuilderFacet
{
    void run()
    {
        Person p = Person::create()
            .lives().at("123 London Road").with_postcode("SW1 1GB").in("London")
            .works().at("PragmaSoft").as_a("Consultant").earning(10e6);

        cout << p << endl;
    }
}