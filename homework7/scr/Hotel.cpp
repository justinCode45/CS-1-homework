#include "../header/Hotel.hpp"

using namespace hotel;

Hotel::Hotel() : name("None"), OfficalRating("None")
{
    this->ratings.clear();
}

Hotel::Hotel(string _name, string _rating) : name(_name), OfficalRating(_rating)
{
    this->ratings.clear();
}

Hotel::Hotel(string _name) : name(_name), OfficalRating("None")
{
    this->ratings.clear();
}

bool Hotel::setName(string _name)
{
    this->name = _name;
    return true;
}

bool Hotel::setOfficalRating(string _rating)
{
    this->OfficalRating = _rating;
    return true;
}

string Hotel::getName() const
{
    return this->name;
}

string Hotel::Hotel::getRating() const
{
    return this->OfficalRating;
}

bool Hotel::Hotel::addRating(int rating)
{
    if (rating < 1 || rating > 5)
        return false;
    this->ratings.push_back(rating);
    return true;
}

double Hotel::Hotel::computeAvg() const
{
    if (this->ratings.size() == 0)
        return 0;
    double sum = 0;
    for (auto i : this->ratings)
        sum += i;
    return sum / this->ratings.size();
}
