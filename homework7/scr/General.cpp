#include "../header/General.hpp"

namespace general
{
    void sigHandler(int sig)
    {
        cout << CSI << "0m"  << "unexpected exit" << endl << endl;
        exit(0);
    }
} // namespace general
