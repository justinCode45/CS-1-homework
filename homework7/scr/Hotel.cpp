#include "../header/Hotel.hpp"

namespace hotel
{
    Hotel::Hotel() : name("None"), OfficalRating("None")
    {
        this->ratings.clear();
        this->detail = "Not implemented yet";
    }

    Hotel::Hotel(std::string _name, std::string _rating) : name(_name), OfficalRating(_rating)
    {
        this->ratings.clear();
        this->detail = "Not implemented yet";
    }

    Hotel::Hotel(std::string _name) : name(_name), OfficalRating("None")
    {
        this->ratings.clear();
        this->detail = "Not implemented yet";
    }

    bool Hotel::setName(std::string _name)
    {
        this->name = _name;
        return true;
    }

    bool Hotel::setOfficalRating(std::string _rating)
    {
        this->OfficalRating = _rating;
        return true;
    }

    inline std::string Hotel::getName() const
    {
        return this->name;
    }

    inline optional<std::string> Hotel::getOfficalRating() const
    {
        if (this->OfficalRating == "None")
            return std::nullopt;
        return this->OfficalRating;
    }

    inline bool Hotel::addRating(int rating)
    {
        if (rating < 1 || rating > 5)
            return false;
        this->ratings.push_back(rating);
        return true;
    }

    double Hotel::computeAvg() const
    {
        if (this->ratings.size() == 0)
            return 0;
        double sum = 0;
        for (auto i : this->ratings)
            sum += i;
        return sum / this->ratings.size();
    }

    ostream &operator<<(ostream &os, const Hotel &in)
    {

        os.setf(std::ios::fixed);
        os.precision(1);

        int l = color(in.name, FSGR::brightYellow).length() - in.name.length();
        int oR = in.getOfficalRating().value_or("0")[0] - '0';
        os << "====" << std::setfill('=') << std::left << std::setw(l + 20) << color(in.name, FSGR::brightYellow) << std::endl;
        os << "Official rating : " << outputRating(oR) << std::endl;
        os << "Actual   rating : " << in.computeAvg() << color("*", FSGR::brightYellow) << std::endl;
        os << "Detail          : " << in.detail << std::endl;

        os.unsetf(std::ios::fixed);
        os.precision(6);
        return os;
    }

    bool compareHotel(const Hotel &a, const Hotel &b)
    {
        return a.computeAvg() > b.computeAvg();
    }

    bool laodData(std::string path_HotelData, std::string path_ActualReating, HotelList &hotels)
    {
        ifstream inHotelData(path_HotelData);
        ifstream inActualReating(path_ActualReating);
        if (inHotelData.fail())
        {
            inHotelData.open("hotelData.txt");
            if (inHotelData.fail())
            {
                return false;
            }
        }
        if (inActualReating.fail())
        {
            inActualReating.open("actualRating.txt");
            if (inActualReating.fail())
            {
                return false;
            }
        }

        while (1)
        {
            std::string name, officalRating;
            inHotelData >> name >> officalRating;
            if (inHotelData.fail())
            {
                break;
            }

            hotels[name].setOfficalRating(officalRating);
        }

        while (1)
        {
            std::string name;
            int actualRating;
            inActualReating >> name >> actualRating;
            if (inActualReating.fail())
            {
                break;
            }

            hotels[name].addRating(actualRating);
        }
        return true;
    }

    std::string outputRating(double rating)
    {
        int r = rating;
        double d = rating - r;
        std::string out = "";

        int orlangth = 0;

        for (int i = 0; i < r; i++)
        {
            out += general::color("*", general::SGRC::blink,
                                  general::SGRC::underline,
                                  general::FSGR::brightYellow);
            orlangth++;
        }

        if (d >= 0.5)
        {
            out += general::color("*", general::FSGR::brightWhite);
            orlangth++;
        }
        else if (d > 0)
        {
            out += general::color("*", general::FSGR::white);
            orlangth++;
        }

        for (int i = 0; i < 5 - orlangth; i++)
        {
            out += general::color(" ", general::SGRC::underline);
        }

        return out;
    }

    HotelList::HotelList()
    {
        this->hotels.clear();
    }

    void HotelList::push_back(const Hotel &hotel)
    {
        function<Hotel *(std::string)> searchHotel = [&](std::string name) -> Hotel *
        {
            for (auto &i : this->hotels)
            {
                if (i.getName() == name)
                {
                    return &i;
                }
            }
            return nullptr;
        };
        Hotel *h = searchHotel(hotel.getName());
        if (h == nullptr)
        {
            this->hotels.push_back(hotel);
        }
    }

    Hotel &HotelList::operator[](int index)
    {
        return this->hotels[index];
    }

    Hotel &HotelList::operator[](std::string name)
    {
        for (auto &i : this->hotels)
        {
            if (i.getName() == name)
            {
                return i;
            }
        }
        this->push_back(Hotel(name));
        return this->back();
    }

    unsigned int HotelList::size() const
    {
        return this->hotels.size();
    }

    HotelList::iterType HotelList::begin()
    {
        return this->hotels.begin();
    }

    HotelList::iterType HotelList::end()
    {
        return this->hotels.end();
    }

    Hotel &HotelList::back()
    {
        return this->hotels.back();
    }

    ostream &operator<<(ostream &os, const HotelList &in)
    {
        os.setf(std::ios::left);
        os.setf(std::ios::fixed);
        os.precision(1);

        os << "Hotel Name          Official Rating    Actual Rating" << std::endl;
        os << "====================================================" << std::endl;
        for (const auto &i : in.hotels)
        {
            int oR = i.getOfficalRating().value_or("0")[0] - '0';
            int ndLength = general::color(i.getName(), FSGR::brightWhite).length() - i.getName().length();
            std::string officalRating = outputRating(oR);
            // std::string actualRating = outputRating(i.computeAvg());

            os << std::setfill(' ') << std::setw(20 + ndLength) << general::color(i.getName(), FSGR::brightWhite)
               << officalRating << "              "
               << i.computeAvg() << color("*", FSGR::brightYellow)
               << std::endl;
        }

        os.unsetf(std::ios::left);
        os.unsetf(std::ios::fixed);
        os.precision(6);

        return os;
    }

    bool HotelList::find(std::string name) const
    {
        for (auto &i : this->hotels)
        {
            if (i.getName() == name)
            {
                return true;
            }
        }
        return false;
    }

    std::string Hotel::getDetail() const
    {
        return this->detail;
    }

    void Hotel::setDetail(std::string _detail)
    {
        this->detail = _detail;
    }

    void HotelList::remove(int index)
    {
        this->hotels.erase(this->hotels.begin() + index);
    }

    void HotelList::remove(std::string name)
    {
        for (auto i = this->hotels.begin(); i != this->hotels.end(); i++)
        {
            if (i->getName() == name)
            {
                this->hotels.erase(i);
                return;
            }
        }
    }

    Hotel Hotel::clone() const
    {
        Hotel out;
        out.name = this->name;
        out.detail = this->detail;
        out.OfficalRating = this->OfficalRating;
        out.ratings = this->ratings;
        return out;
    }

}