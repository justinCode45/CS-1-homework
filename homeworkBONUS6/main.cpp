#include <iostream>
#include "airplane.hpp"
#include "./header/General.hpp"
#include "./header/ConsoleUI.hpp"
#include "./header/UIObject.hpp"
#include <vector>
#include <tuple>
#include <functional>
#include <thread>
#include <sstream>

#define CSI "\x1b["
#define SHEIGHT 50
#define SWIDTH 150

using namespace std;

#define echo "[" + color("Echoing", FSGR::green) + "] "

bool again();

int main()
{
    //---------------------------------prepare---------------------------------
    string planeName;
    ConsoleUI prepareUI(SHEIGHT, SWIDTH);
    Image preImage(0, 0);
    InputBox preInput(SHEIGHT, SWIDTH);
    TextBox preText(10, 45);
    preText << "The purpose of the program is to help user reserve the seat on A380 or B747. \n"
            << color("Please check your console can show all picuter.\n", FSGR::brightRed);
    preImage.setImage("./img/miku.ans");
    preInput.prompt = "Enter the plane you want to reserve a seat on (A380 or B747): ";
    preInput.eprompt = "Enter the plane you want to reserve a seat on (" + color("A380 or B747", FSGR::brightRed) + "): ";

    prepareUI.uioj.push_back(&preImage);
    prepareUI.uioj.push_back(&preInput);
    prepareUI.uioj.push_back(&preText);

    prepareUI.display();

    planeName = get<0>(preInput.getInput<string>(
        (function<bool(tuple<string> &)>)[](tuple<string> x)
            ->bool { return get<0>(x) == "A380" || get<0>(x) == "B747"; }));

    Airplane airplane(planeName + ".txt");

    //---------------------------------main---------------------------------
    ConsoleUI mainUI(SHEIGHT, SWIDTH);
    Image mainImage(0, 0);
    mainImage.setImage("./img/airplane.ans");
    TextBox seatText(10, 45);
    TextBox AirplaneCabin(10, 10);
    InputBox getCabin(SHEIGHT, SWIDTH);
    InputBox getNumber(SHEIGHT, SWIDTH);
    InputBox getRow(SHEIGHT, SWIDTH);
    InputBox getAgain(SHEIGHT, SWIDTH);

    mainUI.addUIObject(&mainImage);
    mainUI.addUIObject(&seatText);
    mainUI.addUIObject(&AirplaneCabin);
    auto InputCTRL = mainUI.addUIObject(nullptr);

    while (1)
    {
        *InputCTRL = &getCabin;
        mainUI.display();
        getCabin.prompt = "Which cabin do you want to reserve (" + airplane.getCabinList() + "): ";
        getCabin.eprompt = "Which cabin do you want to reserve (" + color(airplane.getCabinList(), FSGR::brightRed) + "): ";
        auto [cabinName] = getCabin.getInput<string>(
            (function<bool(tuple<string> &)>)
                [&airplane](tuple<string> x)
                    ->bool { return airplane.cabinMap.find(get<0>(x)) != airplane.cabinMap.end(); });
        AirplaneCabin.clear();
        AirplaneCabin << planeName << "\n"
                      << cabinName << "\n";

        *InputCTRL = &getNumber;
        mainUI.display();
        getNumber.prompt = "How many seat do you want to reserve (1 or 2): ";
        getNumber.eprompt = "How many seat do you want to reserve (" + color("1 or 2", FSGR::brightRed) + "): ";
        auto [seatNumber] = getNumber.getInput<int>(
            (function<bool(tuple<int> &)>)
                [](tuple<int> x)
                    ->bool { return get<0>(x) == 1 || get<0>(x) == 2; });
        AirplaneCabin.clear();
        AirplaneCabin << planeName << "\n"
                      << cabinName << "\n"
                      << seatNumber << "\n";

        Cabin *nowCabin = airplane.cabinMap[cabinName];

        int *chooseSeatRow = new int[seatNumber];

        for (int i = 0; i < seatNumber; i++)
        {

            *InputCTRL = &getRow;
            getRow.prompt = "Enter the seat row (" + to_string(nowCabin->rowStart) + " <= r <= " + to_string(nowCabin->rowStart + nowCabin->row - 1) + "): ";
            getRow.eprompt = "Enter the seat row (" + color(to_string(nowCabin->rowStart) + " <= r <= " + to_string(nowCabin->rowStart + nowCabin->row - 1), FSGR::brightRed) + "): ";
            mainUI.display();
            auto [rowChoose] = getRow.getInput<int>(
                (function<bool(tuple<int> &)>)
                    [&nowCabin](tuple<int> x)
                        ->bool { return get<0>(x) >= nowCabin->rowStart && get<0>(x) <= nowCabin->rowStart + nowCabin->row - 1; });
            
            AirplaneCabin.clear();
            chooseSeatRow[i] = rowChoose;
            AirplaneCabin << planeName << "\n"
                          << cabinName << "\n"
                          << seatNumber << "\n";
            for (int j = 0; j <= i; j++)
            {
                AirplaneCabin << chooseSeatRow[j] << " ";
            }

            bool reserve = nowCabin->reserveSeat(rowChoose);
            if (!reserve)
            {
                AirplaneCabin.clear();
                AirplaneCabin << planeName << "\n"
                              << cabinName << "\n";
                for (int j = 0; j <= i-1; j++)
                {
                    AirplaneCabin << chooseSeatRow[j] << " ";
                }
                AirplaneCabin << "No seat."
                              << "\n";
                i--;
            }
            else
            {
                seatText.clear();
                seatText << nowCabin->print();
            }
        }
        getAgain.prompt = "Do you want to continue?(Y/N) : ";
        getAgain.eprompt = "Do you want to continue?(" + color("Y/N", FSGR::brightRed) + ") : ";
        *InputCTRL = &getAgain;
        mainUI.display();
        auto [temp] = getAgain.getInput<char>(
            (function<bool(tuple<char> &)>)
                [](tuple<char> x)
                    ->bool { return get<0>(x) == 'y' || get<0>(x) == 'Y' || get<0>(x) == 'n' || get<0>(x) == 'N'; });
        if (!(temp == 'y' || temp == 'Y'))
        {
            break;
        }
    }
    return 0;
}

bool again()
{
    auto [temp] = getInput<char>(
        (function<bool(tuple<char> &)>)
            [](tuple<char> x)
                ->bool { return get<0>(x) == 'y' || get<0>(x) == 'Y' || get<0>(x) == 'n' || get<0>(x) == 'N'; },
        "Do you want to continue?(Y/N) :",
        "Do you want to continue?(" + color("Y/N", FSGR::brightRed) + ") :");

    return temp == 'y' || temp == 'Y';
}
