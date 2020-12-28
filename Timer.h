#pragma once
#include <fstream>
#include <chrono>
#include <sstream>
class Timer
{
    private:
        std::chrono::_V2::steady_clock::time_point m_startPoint;
        std::chrono::_V2::steady_clock::time_point m_endPoint;
        std::chrono::duration<double> m_duration;
        std::ofstream fout;

        // note: For Debug Purposes
        // todo: Maybe a new way to Write the path
        std::string m_filepath = "logfiles/binaryTimeLogs/";

        struct date
        {
            std::time_t ttime = time(NULL);
            tm* datetime = localtime(&ttime);

            [[nodiscard]] std::string getDateAsStr() const
            {
                std::stringstream ss;
                ss << (datetime->tm_mday) << "_" << (datetime->tm_mon) + 1 << "_" << (datetime->tm_year) + 1900;
                return ss.str();
            }

            /*
                note: depricated maybe possible use in future
                note: deactive for now

            [[nodiscard]] std::string getTimeAsStr()
            {
                std::stringstream ss;
                ss << (datetime->tm_hour) << ":" << (datetime->tm_min) << ":" << (datetime->tm_sec) << ".tlogs";
                return ss.str();
            }
            */

        } m_date;

    public:
        Timer();
        ~Timer();
        void setFilePath();
        double LogDuration();
};
