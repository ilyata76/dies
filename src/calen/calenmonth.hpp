#pragma once


#ifndef CALENMONTH_HPP
#define CALENMONTH_HPP

	#include "./calenday.hpp"

	#include <vector>

	namespace calen {

		class calenmonth {
		public:
			int weaks;
			int days;
			int month;
			int monthofyear;
			calenday startingDay;
			calenday endingDay;

			// B
			std::vector <calenday> arrayOfDays;
			// !B

		public:
			calenmonth() { this->weaks = 0; this->days = 0; this->month = 0; this->monthofyear = 0; this->startingDay = { 1,4,1,1,1920 }; this->endingDay = { 1,4,1,1,1920 }; };
			calenmonth(int Weaks, int Days, int Month, int yom, calenday stDay, calenday enDay, std::vector <calenday> aOD) {
				this->weaks = Weaks; this->days = Days; this->month = Month; this->monthofyear = yom; this->startingDay = stDay; this->endingDay = enDay; this->arrayOfDays = aOD;
			};
			~calenmonth() {};
		};

		std::string nameOfMonth(int Month);
	}

#endif // !CALENMONTH_HPP