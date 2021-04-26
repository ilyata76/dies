# DIES/DATE CLASS  
  
## DATE_CPP  
  
LeapYear(int Y)  
YearMonthDayCheck(int Year, int Month, int Day)  
DayOfMonth(int month or string month, int year)  
toLower(string)  
dies() make object (INT_CHECK)  
dies(int x) make object xxxx.xx.xx  
dies(int Year, int Month, int Day)  
  
methods:  
    dies.input(int Year, int Month, int Day)  
    dies.getDay // dies.getMonth // dies.getYear  
    dies.CheckDate() == true if object (INT_CHECK)  
  
operators:  
    '> >= < <= == ='  
    A - B return the difference in days  
    A + int // A - int  
    ++ --  
    += int // -= int  
  
  
## DRAND_CPP  
  
int_rand_result(int a, int b)  
float_rand_result(float a, float b)  
drand(date a, date b)  
  
  
## CALEN_CPP  
  
getDayStartingCalen(dies) - просчёт с января 1920 return calenday  
createCalenMonth(calenday, dies) - формирование одного месяца return calenmonth, изменяет calenday на следующий  

createCalen(string, dies, dies) - создаёт объект calen::calen
  
# Compile with CMake  