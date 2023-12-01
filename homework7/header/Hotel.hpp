#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

namespace hotel
{
    using std::string;
    using std::vector;
    using std::ostream;
    class Hotel
    {

    public:
        Hotel();
        Hotel(string _name, string _rating);
        Hotel(string _name);
        bool setName(string _name);
        bool setOfficalRating(string _rating);
        string getName() const;
        string getRating() const;
        bool addRating(int rating);
        double computeAvg() const;
        friend ostream& operator<< (ostream& os, const Hotel& in);

    private:
        string name;
        string OfficalRating;
        vector<int> ratings;
    };

} // namespace hotel

#endif // HOTEL_HPP