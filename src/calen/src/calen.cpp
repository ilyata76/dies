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
		result.weaks = startingDay.weak;
		result.days = DayOfMonth(startingDay.dayofmonth, startingDay.dayofyear);
		result.month = startingDay.dayofmonth;
		result.startingDay = startingDay;
		result.monthofyear = startingDay.dayofyear;
		result.arrayOfDays.push_back(startingDay);

	if (!DATE.CheckDate() || DATE.getYear() < 1920) {
		std::cerr << "ERROR: invalid date\n";
		return result;
	}

	if (DATE.getYear() < startingDay.dayofyear) {
		std::cerr << "ERROR: invalid date-input (second date < first)\n";
		return result;
	} else if (DATE.getYear() == startingDay.dayofyear && DATE.getMonth() < startingDay.dayofmonth) {
		std::cerr << "ERROR: invalid date-input (second date < first)\n";
		return result;
	} else if (DATE.getYear() == startingDay.dayofyear && DATE.getMonth() == startingDay.dayofmonth && DATE.getDay() < startingDay.day) {
		std::cerr << "ERROR: invalid date-input (second date < first)\n";
		return result;
	}

	calenday iterday = startingDay;

	if (DATE.getMonth() == result.month && DATE.getYear() == result.monthofyear) {

		while (iterday.day < DATE.getDay() && iterday.day < DayOfMonth(iterday.dayofmonth, iterday.dayofyear)) {
			while (iterday.number <= 7 && iterday.day < DATE.getDay() && iterday.day < DayOfMonth(iterday.dayofmonth, iterday.dayofyear)) {
				iterday.number++; iterday.day++;
				if (iterday.number != 8) result.arrayOfDays.push_back(iterday);
			}
			if (iterday.number == 8) { iterday.number = 1; iterday.weak++; result.weaks++; result.arrayOfDays.push_back(iterday); }
		}

		int j = result.arrayOfDays.size() - 1;


		if (result.arrayOfDays[j].day == DayOfMonth(iterday.dayofmonth, iterday.dayofyear)) {
			startingDay.day = 1;
			startingDay.weak = 1;

			startingDay.number = result.arrayOfDays[j].number + 1;
				if (startingDay.number == 8) startingDay.number = 1;

			startingDay.dayofmonth++;
				if (startingDay.dayofmonth == 13) {
					startingDay.dayofyear++;
					startingDay.dayofmonth = 1;
				} else {
					startingDay.dayofyear = result.arrayOfDays[j].dayofyear;
				}
		}

		else {

			startingDay.day = result.arrayOfDays[j].day + 1;
			startingDay.number = result.arrayOfDays[j].number + 1;
			startingDay.weak = result.arrayOfDays[j].weak;
				if (startingDay.number == 8) {
					startingDay.weak++;
					startingDay.number = 1;
				}

			startingDay.dayofmonth = result.arrayOfDays[j].dayofmonth;
			startingDay.dayofyear = result.arrayOfDays[j].dayofyear;

		}

		result.endingDay = result.arrayOfDays[j];
	}

	else {

	}

	return result;
}

calen::calen calen::createCalen(std::string ORIENTATION, dies startingDate, dies endingDate) {
	using namespace calen;

	calen result;

		result.orientation = ORIENTATION;
		result.startingYear = startingDate.getYear();
		result.endingYear = endingDate.getYear();
		result.years = result.endingYear - result.startingYear + 1;

	calenday startingDay = getDayStartingCalen(startingDate);

		result.startingDay = startingDay;

	calenmonth startingMonth = createCalenMonth(startingDay,
		dies(startingDay.dayofyear, startingDay.dayofmonth, DayOfMonth(startingDay.dayofmonth, startingDay.dayofyear))
	);

		result.startingMonth = startingMonth;
		result.arrayOfMonths.push_back(startingMonth);

	if (endingDate.getYear() == startingMonth.monthofyear) {
		while (startingMonth.month < endingDate.getMonth() - 1) {
			startingMonth = createCalenMonth(startingDay,
				dies(startingDay.dayofyear, startingDay.dayofmonth, DayOfMonth(startingDay.dayofmonth, startingDay.dayofyear)));

				result.arrayOfMonths.push_back(startingMonth);
		};
	} else {
		while (startingMonth.monthofyear != endingDate.getYear()) {
			startingMonth = createCalenMonth(startingDay,
				dies(startingDay.dayofyear, startingDay.dayofmonth, DayOfMonth(startingDay.dayofmonth, startingDay.dayofyear)));

			result.arrayOfMonths.push_back(startingMonth);
		};
		while (startingMonth.month < endingDate.getMonth() - 1) {
			startingMonth = createCalenMonth(startingDay,
				dies(startingDay.dayofyear, startingDay.dayofmonth, DayOfMonth(startingDay.dayofmonth, startingDay.dayofyear)));

			result.arrayOfMonths.push_back(startingMonth);
		};
	}


	startingMonth = createCalenMonth(startingDay,
		dies(startingDay.dayofyear, startingDay.dayofmonth, endingDate.getDay())
	);

		result.arrayOfMonths.push_back(startingMonth);
		result.endingMonth = startingMonth;
		result.endingDay = startingMonth.arrayOfDays[startingMonth.arrayOfDays.size() - 1];

	return result;
}


void calen::calenOCraw(calen object) {
	using namespace calen;
	std::cout << "YEAR\tMONTH\tDAY\tNUMBER\tWEAK\n";
	for (int i = 0; i < object.arrayOfMonths.size(); i++) {
		for (int j = 0; j < object.arrayOfMonths[i].arrayOfDays.size(); j++) {
			std::cout << object.arrayOfMonths[i].arrayOfDays[j].dayofyear << "\t" << object.arrayOfMonths[i].arrayOfDays[j].dayofmonth << "\t" << object.arrayOfMonths[i].arrayOfDays[j].day
				<< "\t" << object.arrayOfMonths[i].arrayOfDays[j].number << "\t" << object.arrayOfMonths[i].arrayOfDays[j].weak << std::endl;
		}
	}
}

void calen::calenOFraw(calen object, std::ofstream& file) {
	using namespace calen;
	file << "YEAR\tMONTH\tDAY\tNUMBER\tWEAK\n";
	for (int i = 0; i < object.arrayOfMonths.size(); i++) {
		for (int j = 0; j < object.arrayOfMonths[i].arrayOfDays.size(); j++) {
			file << object.arrayOfMonths[i].arrayOfDays[j].dayofyear << "\t" << object.arrayOfMonths[i].arrayOfDays[j].dayofmonth << "\t" << object.arrayOfMonths[i].arrayOfDays[j].day
				<< "\t" << object.arrayOfMonths[i].arrayOfDays[j].number << "\t" << object.arrayOfMonths[i].arrayOfDays[j].weak << std::endl;
		}
	}
}