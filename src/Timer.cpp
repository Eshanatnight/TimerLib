#include "Timer.h"

Timer::Timer()
{
    m_startPoint = std::chrono::steady_clock::now();
    setFilePath();                   //? Sets the FilePath Correctly
    fout.open(m_filepath, fout.app); //? Appends To the File with new Logs
}

Timer::~Timer()
{
    m_endPoint = std::chrono::steady_clock::now();
    LogDuration();
    if (fout.is_open())
    {
        fout.close();
        std::cout << "Something went wrong in File Stream Element Deleation" << std::endl;
    }
}
void Timer::setFilePath()
{
    m_filepath.append(m_date.getDateAsStr());
    m_filepath.push_back('/');
    m_filepath.append("analytics.tlogs");
}

double Timer::LogDuration()
{
    m_duration = m_endPoint - m_startPoint;

    if (fout.is_open())
    {
        fout << "Time Taken: " << ((m_duration.count()) * 1000) << std::endl;
        fout.close();
    }

    return ((m_duration.count()) * 1000);
}

void Timer::getFilePath()
{
    std::cout << "Enter FilePath: ";
    std::getline(std::cin, m_filepath);
}
