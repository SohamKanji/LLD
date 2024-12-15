#include "single_responsibility_principle.h"

#include <fstream>
#include <iostream>

Journal::Journal(const std::string& title) : title(title) {}

void Journal::add_entry(const std::string& entry)
{
    static int count = 1;
    entries.push_back(std::to_string(count++) + ": " + entry);
}

void PersistenceManager::save(const Journal& journal, const std::string& filename)
{
    std::ofstream ofs(filename);
    for (const auto& entry : journal.entries)
    {
        ofs << entry << std::endl;
    }
}

void SingleResponsibilityPrinciple::run()
{
    Journal journal("Dear Diary");
    journal.add_entry("I ate a bug");
    journal.add_entry("I cried today");

    for(auto& entry : journal.entries)
    {
        std::cout << entry << std::endl;
    }

    PersistenceManager::save(journal, "./src/solid_principles/diary.txt");
}