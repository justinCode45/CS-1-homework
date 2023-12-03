#include "./header/Hotel.hpp"
#include "./header/General.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <signal.h>
using namespace std;

using general::color;
using general::FSGR;
using hotel::Hotel;
using hotel::HotelList;
using general::funcTulp;


int main()
{
    signal(SIGINT, general::sigHandler);

    cout << "The purpose of this program is to compute the average rating of each hotel." << endl;
    cout << "You can input at most finite hotels." << endl;
    cout << "Please provide the hotel data file name: hotelData.txt" << endl;
    cout << "Please provide the actual rating file name: actualRating.txt" << endl;

    HotelList hotelL; // self-defined class

    hotelL.push_back(Hotel("The_grand_hotel", "5-star"));
    cout << "Name and official rating of hotel 0: " << hotelL[0].getName() << " " << hotelL[0].getOfficalRating().value_or("None") << endl;
    hotelL[0].setName("The_Grand_Hotel");
    cout << "Name and official rating of hotel 0: " << hotelL[0].getName() << " " << hotelL[0].getOfficalRating().value_or("None") << endl;
    hotelL.push_back(Hotel("Regent_Taipei", "5-star"));
    cout << "Name and official rating of hotel 1: " << hotelL[1].getName() << " " << hotelL[1].getOfficalRating().value_or("None") << endl;
    hotelL.push_back(Hotel());
    cout << "Name and official rating of hotel 2: " << hotelL[2].getName() << " " << hotelL[2].getOfficalRating().value_or("None") << endl;
    hotelL[2].setName("Kindness_Hotel");
    hotelL[2].setOfficalRating("3-star");
    cout << "Name and official rating of hotel 2: " << hotelL[2].getName() << " " << hotelL[2].getOfficalRating().value_or("None") << endl;
    cout << endl;

    /*--------------------------------------------------------------------------------------------------------------------*/

    if (!hotel::laodData("hotelData.txt", "actualRating.txt", hotelL))
    {
        cout << "Error: cannot open file." << endl;
        return 0;
    }

    sort(hotelL.begin(), hotelL.end(), hotel::compareHotel);

    cout << hotelL << endl;

    while (1)
    {
        auto [name] = general::getInput<string>(
            (funcTulp<string>)[&](tuple<string> & in)->bool {
                return hotelL.find(get<0>(in));
            },
            "Please input the name of the hotel you want to search: ",
            color("Not in the list",FSGR::brightRed) + ", please try again: ");

        auto [rating] = general::getInput<int>(
            (funcTulp<int>)[](tuple<int> & in)->bool {
                return get<0>(in) >= 1 && get<0>(in) <= 5;
            },
            "Please input the rating you want to give (1~5): ",
            "Please input the rating you want to give " + color("(1~5)", FSGR::brightRed) + ":");

        hotelL[name].addRating(rating);

        sort(hotelL.begin(), hotelL.end(), hotel::compareHotel);

        cout << endl
             << hotelL[name] << endl;
        cout << endl
             << hotelL << endl;
        
        auto [again] = general::getInput<string>(
            (funcTulp<string>)[](tuple<string> & in)->bool {
                return get<0>(in) == "y" || get<0>(in) == "n" || get<0>(in) == "Y" || get<0>(in) == "N";
            },
            "Do you want to continue? (y/n): ",
            "Please input " + color("(y/n)", FSGR::brightRed) + ": ");

        if (again == "n" || again == "N")
        {
            break;
        }

    }

    return 0;
}