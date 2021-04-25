#pragma once

#ifndef CALENDAY_HPP
#define CALENDAY_HPP

	namespace calen {

		class calenday {
		public:
			int weak;
			int number;
			int day;
			int dayofmonth;
			int dayofyear;
		public:
			calenday() { this->weak = 1; this->number = 1; this->day = 1; this->dayofmonth = 1; this->dayofyear = 1; };
			calenday(int W, int N, int D, int M, int Y) { this->weak = W; this->number = N; this->day = D; this->dayofmonth = M; this->dayofyear = Y; };
			~calenday() {};
		};
			

	}

#endif // !CALENDAY_HPP