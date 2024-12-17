#include "person_builder.h"

PersonBuilder Person::create()
{
    return PersonBuilder();
}

PersonAddressBuilder PersonBuilderBase::lives() const
{
    return PersonAddressBuilder{m_person};
}

PersonJobBuilder PersonBuilderBase::works() const
{
    return PersonJobBuilder{m_person};
}