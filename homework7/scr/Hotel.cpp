#include "../header/Hotel.hpp"

Hotel::Hotel() : name("None"), OfficalRating("None")
{
    ratings.clear();
}

Hotel::Hotel(string _name, string _rating) : name(_name), OfficalRating(_rating)
{
    ratings.clear();
}

Hotel::Hotel(string _name) : name(_name), OfficalRating("None")
{
    ratings.clear();
}

bool Hotel::setName(string _name)
{
    name = _name;
    return true;
}

bool Hotel::setOfficalRating(string _rating)
{
    OfficalRating = _rating;
    return true;
}

string Hotel::getName() const
{
    return name;
}

string Hotel::getRating() const
{
    return OfficalRating;
}

bool Hotel::addRating(int rating)
{
    if (rating < 0 || rating > 5)
        return false;
    ratings.push_back(rating);
    return true;
}

double Hotel::computeAvg() const
{
    if (ratings.size() == 0)
        return 0;
    double sum = 0;
    for (auto i : ratings)
        sum += i;
    return sum / ratings.size();
}
