Author:Justin Chen
Email Address:justin.sc12@nycu.edu.tw
HW Number:7
Description: The purpose of this program is to compute the average rating of each hotel.
Last Change: Dec.1,2023

Modifications to the sample program have been approved by the teacher.

Anything special? 
 0.  color output
 1.  You can add rating to the hotel
 2.  Header and implementation separation
 3.  Ordering hotel by actual rating .
 4.  Support add detail to hotel (Not implemented yet)
 5.  short main function and main.cpp
 6.  by using HotelList class, you can access Hotel object by index or name
 7.  Ensure that there exists no same name hotel in HotelList object
 8.  use namespce to avoid same name of class or function 
 9.  use ifndef and define to avoid same file duplicate references
 10. template function for coloring output and get input 
 11. use requires and concept to restrict whether it is a legal template parameter in compiler time (C++20)
     (like trait in Rust)
    

Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 , C++20
          g++ (Alpine 13.2.1_git20231014)    13.2.1 , C++20
          

Command : g++ main.cpp ./scr/*.cpp -o main -std=c++20 