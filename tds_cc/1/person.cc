#include <string>

class Person
{
public:
    Person(const std::string& name, unsigned int age)
        : name_(name)
        , age_(age)
    {}

private:
    const std::string name_;
    unsigned int age_;
};

int main()
{
    Person p1("Damso", 42);
    return 0;
}
