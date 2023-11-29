/* Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:7
 * Description: .
 * Last Change: Nov.9,2023
 * Anything special?
 *  1. color output
 *  2. More specical functions are in other file.
 *
 * Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 ,C++17
 *           g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0 ,C++17
 *           g++ (tdm64-1) 9.2.0 ,C++17 (Embarcadero Dev-C++)
 *
 *
 */
#include <iostream>
#include <string>
#include <fstream>
#include <optional>
#include <variant>
#include <vector>
#include <map>
using namespace std;

const int N = 20;

template <class T>
using Result = optional<T>;

class Hotel
{

public:
    Hotel();
    Hotel(string _name, string _rating);
    Hotel(string _name);
    bool setName(string _name);
    bool setOfficalRating(string _rating);
    Result<string> getName() const;
    Result<string> getRating() const;
    bool addRating(int rating);
    double computeAvg() const;

private:
    string name;
    string OfficalRating;
    vector<int> ratings;
};

void laodData(ifstream &inHotelData, ifstream &inActualReating, map<string, Hotel> &hotels);

int main()
{
    map<string, Hotel> hotels;

    ifstream inHotelData("hotelData.txt");
    ifstream inActualReating("actualRating.txt");
    cout << "The purpose of this program is to compute the average rating of each hotel." << endl;
    cout << "You can input at most " << N << " hotels." << endl;
    cout << "Please provide the hotel data file name: hotelData.txt" << endl;
    cout << "Please provide the actual rating file name: actualRating.txt" << endl;
    cout << endl;

    laodData(inHotelData, inActualReating, hotels);
    for (auto i : hotels)
    {
        Hotel n = i.second;
        cout << n.getName().value() << " " << n.getRating().value_or("None") << " " << n.computeAvg() << endl;
    }

    return 0;
}

void laodData(ifstream &inHotelData, ifstream &inActualReating, map<string, Hotel> &hotels)
{
    while (1)
    {
        string name, rating;
        inHotelData >> name >> rating;
        if (inHotelData.fail())
            break;
        hotels.insert(std::pair<string, Hotel>(name, Hotel(name, rating)));
    }
    while (1)
    {
        string name;
        int rating;
        inActualReating >> name >> rating;
        if (inActualReating.fail())
            break;

        hotels.insert(std::pair<string, Hotel>(name, Hotel(name)));
        hotels[name].addRating(rating);
    }
}

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

Result<string> Hotel::getName() const
{
    if (name == "None")
        return std::nullopt;
    return name;
}

Result<string> Hotel::getRating() const
{
    if (OfficalRating == "None")
        return std::nullopt;
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
