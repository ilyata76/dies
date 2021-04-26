#pragma once

#ifndef CALEN_HPP
#define CALEN_HPP

	#include "../dies/date.hpp"
	#include "./calenmonth.hpp"

	#include <iostream>
	#include <fstream>

	namespace calen {

		class calen {
		public:
			std::string orientation;
			
			int startingYear;
			int endingYear;

			calenmonth startingMonth;
			calenmonth endingMonth;

			calenday startingDay;
			calenday endingDay;

			int years;
			std::vector <calenmonth> arrayOfMonths;

		public:
			calen() { 
				this->orientation = ""; this->startingYear = 1; this->endingYear = 1; 
				this->years = 0;
			};
		public:
			calen(int ORIENT, int stYear, int enYear, calenmonth stMonth, calenmonth enMonth, calenday stDay, calenday enDay, std::vector <calenmonth> aOM) {
				this->orientation = ORIENT; this->startingYear = stYear; this->endingYear = enYear;
				this->startingMonth = stMonth; this->endingMonth = enMonth; this->startingDay = stDay; this->endingDay = enDay;
				this->arrayOfMonths = aOM;
			};
		public:
			~calen() {};
		};

		calenday getDayStartingCalen(dies DATE);
		calenmonth createCalenMonth(calenday& startingDay, dies DATE);
		calen createCalen(std::string ORIENTATION, dies startingDate, dies endingDate);

		void calenOCraw(calen object); // only coords in console
		void calenOFraw(calen object, std::ofstream& file); // only coords in file

	}

#endif // !CALEN_HPP