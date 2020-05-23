// And then write the implementation for its functions
// in a seperate file (of the same name)

#include "Date.h"
 
// Date constructor
Date::Date(int year, int month, int day)
{
    SetDate(year, month, day);
}
 
// Date member function
void Date::SetDate(int year, int month, int day)
{
    m_month = month;
    m_day = day;
    m_year = year;
}
