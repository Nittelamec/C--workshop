#include "address_book.hh"

#include <map>
#include <optional>
#include <vector>

#include "contact_details.hh"

bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    if (full_name.empty())
        return false;
    std::optional<ContactDetails> details =
        ContactDetails::makeDetails(number, email);
    if (!details.has_value())
        return false;

    auto value = std::multimap<std::string, ContactDetails>::value_type(
        full_name, details.value());
    table.insert(value);

    return true;
}

std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> res{};
    for (const auto& [name, details] : table)
    {
        if (!name.compare(full_name))
            res.push_back(details);
    }
    return res;
}

std::size_t AddressBook::count(const std::string& full_name)
{
    size_t cpt = 0;
    for (const auto& [name, details] : table)
    {
        if (!name.compare(full_name))
            cpt = cpt + 1;
    }
    return cpt;
}

bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    size_t count_full_name = count(full_name);
    if (index > count_full_name)
        return false;

    auto it = table.begin();
    std::vector<std::multimap<std::string, ContactDetails>::iterator> targets;
    while (it != table.end())
    {
        if (!(it->first.compare(full_name)))
            targets.push_back(it);
        it++;
    }
    if (targets.size() > index)
    {
        table.erase(targets[index]);
        return true;
    }
    return false;
}

void AddressBook::remove_all(const std::string& full_name)
{
    std::multimap<std::string, ContactDetails>::iterator it = table.begin();
    while (it != table.end())
    {
        if (!(it->first.compare(full_name)))
            it = table.erase(it);
        else
            it++;
    }
}

std::ostream& operator<<(std::ostream& os, const AddressBook& b)
{
    os << b.table.size() << " contact(s) in the address book.\n";
    for (const auto& elem : b.table)
        os << "- " << elem.first << ": " << elem.second;
    return os;
}
