#pragma once

#ifndef CALEN_HPP
#define CALEN_HPP

	#include "../dies/date.hpp"
	#include "./calenmonth.hpp"
	#include <iostream>

	namespace calen {

		class calen {
		private:
			int orientation;
			
			int startingYear;
			int endingYear;

			calenmonth startingMonth;
			calenmonth endingMonth;

			calenday startingDay;
			calenday endingDay;

		public:
			calen() { 
				this->orientation = 0; this->startingYear = 1; this->endingYear = 1; 
				this->startingMonth; this->endingMonth; this->startingDay; this->endingDay;
			};
			calen(int ORIENT, int stYear, int enYear, calenmonth stMonth, calenmonth enMonth, calenday stDay, calenday enDay) {
				this->orientation = ORIENT; this->startingYear = stYear; this->endingYear = enYear;
				this->startingMonth = stMonth; this->endingMonth = enMonth; this->startingDay = stDay; this->endingDay = enDay;
			};
			~calen() {};
		};

	}

#endif // !CALEN_HPP