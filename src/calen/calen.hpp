#pragma once

#ifndef CALEN_HPP
#define CALEN_HPP

	#include "../dies/date.hpp"
	#include "./calenmonth.hpp"
	#include <iostream>

	namespace calen {
		// TODO B: сделать разбиение всего календаря на годы, годы на месяцы, месяцы на дни, чтобы обращаться можно было к каждому из них
			// как метод или как надстройку?
		class calen {
		public:
			std::string orientation;
			
			int startingYear;
			int endingYear;

			calenmonth startingMonth;
			calenmonth endingMonth;

			calenday startingDay;
			calenday endingDay;

			// B
			int years;
			std::vector <calenmonth> arrayOfMonths;
			// !B

		public:
			calen() { 
				this->orientation = ""; this->startingYear = 1; this->endingYear = 1; 
				//this->startingMonth; this->endingMonth; this->startingDay; this->endingDay;
				this->years = 0;
			};
		private:
			calen(int ORIENT, int stYear, int enYear, calenmonth stMonth, calenmonth enMonth, calenday stDay, calenday enDay, std::vector <calenmonth> aOM) {
				this->orientation = ORIENT; this->startingYear = stYear; this->endingYear = enYear;
				this->startingMonth = stMonth; this->endingMonth = enMonth; this->startingDay = stDay; this->endingDay = enDay;
				this->arrayOfMonths = aOM;
			};
		public:
			void calenOC(calen object); // out-console
			void calenOF(calen object); // out-file
			void calenOCraw(calen object); // only coords in console
			void calenOFraw(calen object); // only coords in file

			~calen() {};
		};

		// 1 январь 1920 г - четверг . 31 декабря - пятница
		// то есть координаты: weak = 1 number = 4 day = 1

		calenday getDayStartingCalen(dies DATE);
		calenmonth createCalenMonth(calenday& startingDay, dies DATE);
		calen createCalen(std::string ORIENTATION, dies startingDate, dies endingDate);


	}

#endif // !CALEN_HPP