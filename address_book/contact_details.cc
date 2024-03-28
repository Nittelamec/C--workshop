#include "contact_details.hh"

#include <optional>
#include <string>

ContactDetails::ContactDetails(const std::string& telephone_number,
                               const std::string& personal_email)
    : number_(telephone_number)
    , email_(personal_email)
{}

std::optional<ContactDetails>
ContactDetails::makeDetails(const std::string& telephone_number,
                            const std::string& personal_email)
{
    auto it = telephone_number.begin();
    while (it != telephone_number.end())
    {
        if (!std::isdigit(*it))
            return std::nullopt;
        it++;
    }
    if (personal_email.find('@') == std::string::npos)
        return std::nullopt;

    return ContactDetails(telephone_number, personal_email);
}

std::ostream& operator<<(std::ostream& os,
                         const ContactDetails& contact_details)
{
    os << contact_details.number_ << ", " << contact_details.email_ << '\n';
    return os;
}
