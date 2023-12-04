#include <fmt/chrono.h>
#include <fmt/format.h>

#include <string>
#include <vector>

class Tier
{
   public:
    virtual void iss() const = 0;
    /*
    da iss pure virtual ist
    {
        fmt::println("Fresse wie ein Tier");
    };
    */
};
class Hund : public Tier
{
   public:
    void iss() const final
    {
        fmt::println("Wuff! Fresse gerade");
    };
};
class Pudel : public Hund
{
   public:
    /*
    because iss is marked as final in Hund
     void iss() const override
     {
         fmt::println("Der Pudel frisst gerade");
     };
     */
};
class Mensch : public Tier
{
   public:
    void iss() const override
    {
        fmt::println("Esse gerade");
    };
};

void tierPrinter(Tier* t)
{
    t->iss();
}

int main()
{
    std::vector<Tier*> tiere;
    // tiere.push_back(new Tier());
    tiere.push_back(new Hund());
    tiere.push_back(new Pudel());
    tiere.push_back(new Mensch());
    for (auto* tier : tiere)
    {
        tier->iss();
    }

    return 0;
}