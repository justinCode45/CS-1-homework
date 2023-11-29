#include <iostream>
#include "./header/Hotel.hpp"
#include <fstream>
#include <functional>
#include <vector>

using namespace std;


void laodData(ifstream &inHotelData, ifstream &inActualReating, Hotel* hotels,int &n);

int main()
{
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
    


    return 0;
}

void laodData(ifstream &inHotelData, ifstream &inActualReating, Hotel* hotels,int &n)
{
    function<int(string)> searchHotel = [&](string name) -> bool
    {
        for (int i=0;i<n;i++)
        {
            if (hotels[i].getName() == name)
                return i;
        }
        return -1;
    };
    

}