#include "person.hh"

#include <ostream>

#include "nft.hh"

// Initiliaze its member attributes.
Person::Person(const std::string& name, uint money)
    : name_(name)
    , money_(money)
    , nfts_(std::vector<NFT>{})
{}

// Returns the list of NFTs it owns.
std::vector<std::string> Person::enumerate_nfts() const
{
    auto begin = nfts_.begin();
    std::vector<std::string> res;
    while (begin != nfts_.end())
    {
        std::string nft_name = *begin->get();
        res.push_back(nft_name);
        begin++;
    }
    return res;
}

// Give it a NFT.
void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}

// Take away a NFT.
NFT Person::remove_nft(const std::string& name)
{
    auto begin = nfts_.begin();
    while (begin != nfts_.end())
    {
        if (!begin->get()->compare(name))
        {
            NFT res = std::move(*begin);
            begin = nfts_.erase(begin);
            return res;
        }
        else
            begin++;
    }
    return create_empty_nft();
}

// Add money.
void Person::add_money(uint money)
{
    money_ += money;
}

// Remove money, if possible.
bool Person::remove_money(uint money)
{
    if (money_ < money)
        return false;
    money_ -= money;
    return true;
}

// Getters for money and name.
uint Person::get_money() const
{
    return money_;
}

const std::string& Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << '\n';
    os << "Money: " << p.get_money() << '\n';

    os << "NFTs:";

    for (std::string elem : p.enumerate_nfts())
        os << " " << elem;
    os << '\n';

    return os;
}
