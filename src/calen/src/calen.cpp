#include "../calen.hpp"

// 1 €нварь 1920 г - четверг . 31 декабр€ - п€тница
// то есть координаты: weak = 1 number = 4 day = 1


calen::calenday calen::getDayStartingCalen(dies DATE) {

	using namespace calen;

	calenday std1920;
		std1920.day = 1;
		std1920.weak = 1;
		std1920.number = 4;
		std1920.dayofmonth = 1;
		std1920.dayofyear = 1920;

		if (!DATE.CheckDate() || DATE.getYear() < 1920) { 
			std::cerr << "ERROR: invalid date\n";
			return std1920; 
		}

	calenmonth stm1920;
		stm1920.weaks = 0;
		stm1920.days = 31;
		stm1920.month = 1;
		stm1920.monthofyear = 1920;
		stm1920.startingDay = std1920;
		stm1920.arrayOfDays.push_back(std1920);

	calenday iterday = std1920;
	calenmonth itermonth = stm1920;

	if (DATE.getYear() == itermonth.monthofyear && DATE.getMonth() == itermonth.month && DATE.getDay() == itermonth.startingDay.day) {
		return iterday;
	} 
	
	else if (DATE.getYear() == itermonth.monthofyear && DATE.getMonth() == itermonth.month && DATE.getDay() != itermonth.startingDay.day) {
		while (iterday.day <= itermonth.days && iterday.day < DATE.getDay()) {
			do {
				iterday.number++; iterday.day++;
			} while (iterday.number <= 7 && iterday.day <= itermonth.days && iterday.day < DATE.getDay());
			if (iterday.number == 8) { iterday.number = 1; iterday.weak++; }
		}
	}

	else {
		while (true) {

			if (DATE.getYear() == itermonth.monthofyear)
				if (DATE.getMonth() == itermonth.month)
						break;

			while (iterday.day <= itermonth.days) {
				do {
					iterday.number++; iterday.day++;
				} while (iterday.number <= 7 && iterday.day <= itermonth.days);
				if (iterday.number == 8) { iterday.number = 1; iterday.weak++; }
			}

			if (iterday.day == itermonth.days + 1) {
				itermonth.month++;
				itermonth.days = DayOfMonth(itermonth.month, itermonth.monthofyear);
				iterday.day = 1;
				iterday.weak = 1;
			}

			if (itermonth.month == 13) {
				itermonth.month = 1;
				itermonth.monthofyear++;
				itermonth.days = DayOfMonth(itermonth.month, itermonth.monthofyear);
				iterday.day = 1;
				iterday.weak = 1;
			}
		}

		while (iterday.day <= itermonth.days && iterday.day < DATE.getDay()) {
			while (iterday.number <= 7 && iterday.day < itermonth.days && iterday.day < DATE.getDay()) {
				iterday.number++; iterday.day++;
			}
			if (iterday.number == 8) { iterday.number = 1; iterday.weak++; }
		}
	}

	stm1920.~calenmonth();
	std1920.~calenday();

	iterday.dayofmonth = itermonth.month;
	iterday.dayofyear = itermonth.monthofyear;
	itermonth.~calenmonth();
	return iterday;	
}


calen::calenmonth calen::createCalenMonth(calenday& startingDay, dies DATE) {
	
	calenmonth result;
		result.days = DayOfMonth(startingDay.dayofmonth, startingDay.dayofyear);
		result.month = startingDay.dayofmonth;
		result.startingDay = startingDay;
		result.monthofyear = startingDay.dayofyear;
		result.arrayOfDays.push_back(startingDay);

	if (!DATE.CheckDate() || DATE.getYear() < 1920) {
		std::cerr << "ERROR: invalid date\n";
		return result;
	}

	calenday iterday = startingDay;

	if (DATE.getMonth() == result.month && DATE.getYear() == result.monthofyear) {
		for (int i = 0; DATE.getDay() != result.arrayOfDays[i].day; i++) {
			while (iterday.day < DATE.getDay() && iterday.day < DayOfMonth(iterday.dayofmonth, iterday.dayofyear)) {
				while (iterday.number <= 7 && iterday.day < DATE.getDay() && iterday.day < DayOfMonth(iterday.dayofmonth, iterday.dayofyear)) {
					iterday.number++; iterday.day++;
					if (iterday.number != 8) result.arrayOfDays.push_back(iterday);
				}
				if (iterday.number == 8) { iterday.number = 1; iterday.weak++; result.arrayOfDays.push_back(iterday); }
			}
		}
	}

	else {

	}

	return result;
}