#include <iostream>
using namespace std;

class DayMonthYear{
    private:
        int DAY;
        int MONTH;
        int YEAR;
    public:

        DayMonthYear(int day, int month, int year);
        void setDay();
        void setMonth();
        void setYear();
        int getDay();
        int getMonth();
        int getYear();   

        void caculateAge();
        void checkHoliday();
};

DayMonthYear :: DayMonthYear(int day, int month, int year){
    DAY = day;
    MONTH = month;
    YEAR = year;
}

void DayMonthYear :: setDay(){
    int day;
    DAY = day;
}
int DayMonthYear :: getDay(){
    return DAY;
}
void DayMonthYear :: setMonth(){
    int month;
    MONTH = month;
}
int DayMonthYear :: getMonth(){
    return MONTH;
}
void DayMonthYear :: setYear(){
    int year;
    YEAR = year;
}
int DayMonthYear :: getYear(){
    return YEAR;
}

void DayMonthYear :: caculateAge(){

    
    // Lấy ngày, tháng, năm hiện tại
    time_t now = time(NULL);
    tm *ltm = localtime(&now);
    int currentDay = ltm->tm_mday;
    int currentMonth = 1 + ltm->tm_mon;
    int currentYear = 1900 + ltm->tm_year;
   
    
    int age;
    age = currentYear - getYear();
    if(currentMonth < getMonth()||  currentMonth == getMonth() && currentDay < getDay()){
        age -= 1;
    }
    cout <<"Age: " << age<< endl;
}

void DayMonthYear :: checkHoliday(){

    if(getDay() == 1 && getMonth() == 1 || getDay() == 30 && getMonth() == 4 ||getDay() == 1 && getMonth() == 5 ||getDay() == 2 && getMonth() == 9){
        cout << "It's holiday\n";
    }

    else cout << "It isn't holiday\n";
}

int main(int argc, char const *argv[])
{

    DayMonthYear Toan(22, 9, 2002);
    Toan.caculateAge();
    Toan.checkHoliday();

    return 0;
}
