#include "auction.hh"

#include <utility>

// Start the auction with the given (non-null) NFT.
Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
    , highest_bidder_(nullptr)
    , highest_bid_(initial_bid)
{
    if (nft.get()->empty())
        throw std::runtime_error("Empty nft.");
    nft_ = std::move(nft);
}

// Allow a person to bid at the auction.
bool Auction::bid(Person& person, uint money)
{
    if (person.get_money() < money)
        return false;
    if (person.get_money() > highest_bid_)
    {
        if (highest_bidder_ != nullptr)
            highest_bidder_->add_money(highest_bid_);
        person.remove_money(money);
        highest_bid_ = money;
        highest_bidder_ = &person;
        return true;
    }
    return false;
}

// Getters for the nft name and highest bid.
const std::string& Auction::get_nft_name() const
{
    return *nft_.get();
}

uint Auction::get_highest_bid() const
{
    return highest_bid_;
}

Auction::~Auction()
{
    if (highest_bidder_ == nullptr)
        organizer_.add_nft(std::move(nft_));
    else
    {
        highest_bidder_->add_nft(std::move(nft_));
        organizer_.add_money(std::move(highest_bid_));
    }
}
