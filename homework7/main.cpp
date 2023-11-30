#include <iostream>
#include "./header/Hotel.hpp"
#include <fstream>
#include <functional>
#include <vector>
#include <iomanip>

using namespace std;
using namespace hotel;

void laodData(ifstream &inHotelData, ifstream &inActualReating, vector<Hotel> &hotels);

int main()
{

    cout << "The purpose of this program is to compute the average rating of each hotel." << endl;
    cout << "You can input at most finite hotels." << endl;
    cout << "Please provide the hotel data file name: hotelData.txt" << endl;
    cout << "Please provide the actual rating file name: actualRating.txt" << endl;

    vector<Hotel> hotels;
    hotels.push_back(Hotel("The_grand_hotel", "5-star"));
    cout << "Name and official rating of hotel 0: " << hotels[0].getName() << " " << hotels[0].getRating() << endl;
    hotels[0].setName("The_Grand_Hotel");
    cout << "Name and official rating of hotel 0: " << hotels[0].getName() << " " << hotels[0].getRating() << endl;
    hotels.push_back(Hotel("Regent_Taipei", "5-star"));
    cout << "Name and official rating of hotel 1: " << hotels[1].getName() << " " << hotels[1].getRating() << endl;
    hotels.push_back(Hotel());
    cout << "Name and official rating of hotel 2: " << hotels[2].getName() << " " << hotels[2].getRating() << endl;
    hotels[2].setName("Kindness_Hotel");
    hotels[2].setOfficalRating("3-star");
    cout << "Name and official rating of hotel 2: " << hotels[2].getName() << " " << hotels[2].getRating() << endl;

    ifstream inHotelData("hotelData.txt");
    ifstream inActualReating("actualRating.txt");
    if (inHotelData.fail() || inActualReating.fail())
    {
        cout << "File open failed!" << endl;
        return 0;
    }

    laodData(inHotelData, inActualReating, hotels);
    cout.setf(ios::fixed);
    cout.precision(2);

    cout << endl;
    cout << setw(20) << left << "Hotel name" << setw(20) << left << "Official rating" << setw(20) << left << "Actual rating" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const auto &i : hotels)
    {
        cout << setw(20) << i.getName()
             << setw(20) << i.getRating()
             << setw(20) << i.computeAvg()
             << endl;
    }

    return 0;
}

void laodData(ifstream &inHotelData, ifstream &inActualReating, vector<Hotel> &hotels)
{
    function<Hotel *(string)> searchHotel = [&](string name) -> Hotel *
    {
        for (auto &i : hotels)
        {
            if (i.getName() == name)
            {
                return &i;
            }
        }
        return nullptr;
    };

    while (1)
    {
        string name, officalRating;
        inHotelData >> name >> officalRating;
        if (inHotelData.fail())
        {
            break;
        }
        Hotel *hotel = searchHotel(name);
        if (hotel != nullptr)
        {
            hotel->setOfficalRating(officalRating);
        }
        else
        {
            hotels.push_back(Hotel(name, officalRating));
        }
    }

    while (1)
    {
        string name;
        int actualRating;
        inActualReating >> name >> actualRating;
        if (inActualReating.fail())
        {
            break;
        }
        Hotel *hotel = searchHotel(name);
        if (hotel != nullptr)
        {
            hotel->addRating(actualRating);
        }
        else
        {
            hotels.push_back(Hotel(name));
            hotels.back().addRating(actualRating);
        }
    }
}
