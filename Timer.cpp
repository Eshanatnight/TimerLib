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
    fout << "Time Taken: " << ((m_duration.count()) * 1000) << std::endl;

    return ((m_duration.count()) * 1000);
}
