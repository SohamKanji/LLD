#pragma once
#include <string>
#include <vector>

struct Journal
{
    explicit Journal(const std::string& title);

    void add_entry(const std::string& entry);

    /**
     * Should we have this here? No. This is a violation of the Single Responsibility Principle.
     * This class should only be responsible for managing the journal entries.
     * Saving the journal entries to a file should be handled by a separate class.
    */
    void save(const std::string& filename);

    std::string title;
    std::vector<std::string> entries;

};

struct PersistenceManager
{
    static void save(const Journal& journal, const std::string& filename);
};

namespace SingleResponsibilityPrinciple
{
    void run();
}
