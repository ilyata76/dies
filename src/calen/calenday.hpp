#pragma once

#ifndef CALENDAY_HPP
#define CALENDAY_HPP

	namespace calen {

		class calenday {
		public:
			int weak;
			int number;
			int day;
		public:
			calenday() { this->weak = 1; this->number = 1; this->day = 1; };
			calenday(int W, int N, int D) { this->weak = W; this->number = N; this->day = D; };
			~calenday() {};
		};
			

	}

#endif // !CALENDAY_HPP