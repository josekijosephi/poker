// Here we can define a class in it's own header file
#ifndef DATE_H
#define DATE_H
// The above two line are the "header guards"
 
class Date
{
private:
    int m_year;
    int m_month;
    int m_day;
 
public:
    Date(int year, int month, int day);
 
    void SetDate(int year, int month, int day);
 
    int getYear() { return m_year; }
    int getMonth() { return m_month; }
    int getDay()  { return m_day; }
};
 
#endif
