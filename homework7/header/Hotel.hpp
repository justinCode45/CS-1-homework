#ifndef HOTEL_HPP
#define HOTEL_HPP

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <functional>
#include "General.hpp"
#include <optional>
namespace hotel
{

    using general::BSGR;
    using general::color;
    using general::FSGR;
    using std::function;
    using std::ifstream;
    using std::optional;
    using std::ostream;
    using std::vector;

    class Hotel
    {

    public:
        Hotel();
        Hotel(std::string _name, std::string _rating);
        Hotel(std::string _name);
        /* Avoid using it, it will cause duplication of hotel names,
           when this hotel is in HotleList.
        */
        bool setName(std::string _name);
        bool setOfficalRating(std::string _rating);
        std::string getName() const;
        optional<std::string> getOfficalRating() const;
        bool addRating(int rating);
        double computeAvg() const;
        friend ostream &operator<<(ostream &os, const Hotel &in);
        std::string getDetail() const;
        void setDetail(std::string _detail);
        Hotel clone() const;
    private:
        std::string name;
        std::string detail;
        std::string OfficalRating;
        vector<int> ratings;
    };

    class HotelList
    {
    private:
        vector<Hotel> hotels;
        using iterType = decltype(hotels.begin());

    public:
        friend class Iterator;
        HotelList();
        void push_back(const Hotel &hotel);
        Hotel &operator[](int index);
        Hotel &operator[](std::string name);
        void remove(int index);
        void remove(std::string name);
        bool find(std::string name) const;
        unsigned int size() const;
        iterType begin();
        iterType end();
        Hotel &back();
        friend ostream &operator<<(ostream &os, const HotelList &in);
    };

    bool laodData(std::string path_HotelData, std::string path_ActualReating, HotelList &hotels);
    bool compareHotel(const Hotel &a, const Hotel &b);
    std::string outputRating(double rating);

} // namespace hotel

#endif // HOTEL_HPP