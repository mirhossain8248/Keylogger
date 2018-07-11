/*
Helper.h is just extra functionality for the program to work.
Focuses on formatting and converting all characters into strings
*/

#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper
{
    template <class T>
    /*
    Convert everything into a string (Prototype)
    */
    std::string ToString(const T &);

    /*
    Keeps track of DD/MM/YYYY and hour/minute/seconds
    */
    struct DateTime
    {
        DateTime()
        {
            time_t ms;
            time(&ms);

            struct tm *info = localtime(&ms);
            D = info -> tm_mday; //day
            m = info -> tm_mon + 1; //month (Added 1 since month starts at 0
            y = 1900 + info -> tm_year; //year
            M = info -> tm_min; //Minute
            H = info -> tm_hour; //Hour
            S = info -> tm_sec; //Seconds
        }

        /*
        Display the date/time
        */

        DateTime(int D, int m, int y, int H, int M, int S)
        :D(D), m(m), y(y), H(H), M(M), S(S) {}

        DateTime(int D, int m, int y)
        :D(D), m(m), y(y), H(0), M(0), S(0) {}

        DateTime Now() const
        {
            return DateTime();
        }

        int D, m, y, H, M, S;

        //Display as DD/MM/YYYY
        std::string GetDateString() const
        {
            return std::string(D < 10 ? "0" : "") + ToString(D) +
                   std::string(m < 10 ? ".0" : ".") + ToString(m) + "." +
                   ToString(y);
        }

        //Display time as HH:MM:SS
        std::string GetTimeString(const std::string &sep = ":") const  //display seperator
        {
            return std::string(H < 10 ? "0" : "") + ToString(H) + sep +
                   std::string(M < 10 ? "0" : "") + ToString(M) + sep +
                   std::string(S < 10 ? sep : "") + ToString(S);
        }

        //Displays everything
        std::string GetDateTimeString(const std::string &sep = ":") const
        {
            return GetDateString() + " " + GetTimeString(sep);
        }
};

    template <class T>
    //Converts everything into an string
    std::string ToString(const T &e)
    {
        std::ostringstream s;
        s << e;
        return s.str();
    }

}

#endif // HELPER_H
