#pragma once
#include <string>
#include <iostream>
using namespace std;

class PersonBuilder;
class PersonAddressBuilder;
class PersonJobBuilder;

class Person {
    string m_name;
    string m_street_address;
    string m_postcode;
    string m_city;
    string m_company_name;
    string m_position;
    int m_annual_income;

public:
    
    friend ostream& operator<<(ostream& os, const Person& obj)
    {
        return os
            << "name: " << obj.m_name
            << " street_address: " << obj.m_street_address
            << " postcode: " << obj.m_postcode
            << " city: " << obj.m_city
            << " company_name: " << obj.m_company_name
            << " position: " << obj.m_position
            << " annual_income: " << obj.m_annual_income;
    }

    static PersonBuilder create();

    friend class PersonBuilder;
    friend class PersonAddressBuilder;
    friend class PersonJobBuilder;

    
};

class PersonBuilderBase
{
protected:
    Person& m_person;
public:
    PersonBuilderBase(Person& person) : m_person(person) {}
    PersonAddressBuilder lives() const;

    PersonJobBuilder works() const;

    operator Person()
    {
        return std::move(m_person);
    }
};

class PersonBuilder : public PersonBuilderBase
{
    Person m_person;
public:
    PersonBuilder() : PersonBuilderBase{m_person} {}
};

class PersonAddressBuilder : public PersonBuilderBase
{
public:
    PersonAddressBuilder(Person& person) : PersonBuilderBase(person) {}
    PersonAddressBuilder& at(string street_address)
    {
        m_person.m_street_address = street_address;
        return *this;
    }
    PersonAddressBuilder& with_postcode(string postcode)
    {
        m_person.m_postcode = postcode;
        return *this;
    }
    PersonAddressBuilder& in(string city)
    {
        m_person.m_city = city;
        return *this;
    }
};

class PersonJobBuilder : public PersonBuilderBase
{
public:
    PersonJobBuilder(Person& person) : PersonBuilderBase(person) {}
    PersonJobBuilder& at(string company_name)
    {
        m_person.m_company_name = company_name;
        return *this;
    }
    PersonJobBuilder& as_a(string position)
    {
        m_person.m_position = position;
        return *this;
    }
    PersonJobBuilder& earning(int annual_income)
    {
        m_person.m_annual_income = annual_income;
        return *this;
    }
};