#include "../calenmonth.hpp"

std::string calen::nameOfMonth(int Month) {
	if (Month == 1) return "January";
	else if (Month == 2) return "February";
	else if (Month == 3) return "March";
	else if (Month == 4) return "April";
	else if (Month == 5) return "May";
	else if (Month == 6) return "June";
	else if (Month == 7) return "July";
	else if (Month == 8) return "August";
	else if (Month == 9) return "September";
	else if (Month == 10) return "October";
	else if (Month == 11) return "November";
	else if (Month == 12) return "December";
	else return "ERROR";
}