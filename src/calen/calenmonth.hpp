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
			calenday startingDay;
			calenday endingDay;

			// B
			std::vector <calenday> arrayOfDays;
			// !B

		public:
			calenmonth() { this->weaks = 0; this->days = 0; this->startingDay = { 1,1,1 }; this->endingDay = { 1,1,1 }; };
			calenmonth(int Weaks, int Days, calenday stDay, calenday enDay, std::vector <calenday> aOD) {
				this->weaks = Weaks; this->days = Days; this->startingDay = stDay; this->endingDay = enDay; this->arrayOfDays = aOD;
			};
			~calenmonth() {};
		};

	}

#endif // !CALENMONTH_HPP