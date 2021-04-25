#pragma once

#ifndef CALEN_HPP
#define CALEN_HPP

	#include "../dies/date.hpp"
	#include "./calenmonth.hpp"
	#include <iostream>

	namespace calen {
		// TODO B: ������� ��������� ����� ��������� �� ����, ���� �� ������, ������ �� ���, ����� ���������� ����� ���� � ������� �� ���
			// ��� ����� ��� ��� ����������?
		class calen {
		private:
			int orientation;
			
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
				this->orientation = 0; this->startingYear = 1; this->endingYear = 1; 
				//this->startingMonth; this->endingMonth; this->startingDay; this->endingDay;
				this->years = 0;
			};
			calen(int ORIENT, int stYear, int enYear, calenmonth stMonth, calenmonth enMonth, calenday stDay, calenday enDay, std::vector <calenmonth> aOM) {
				this->orientation = ORIENT; this->startingYear = stYear; this->endingYear = enYear;
				this->startingMonth = stMonth; this->endingMonth = enMonth; this->startingDay = stDay; this->endingDay = enDay;
				this->arrayOfMonths = aOM;
			};

			void calenOC(calen object); // out-console
			void calenOF(calen object); // out-file

			~calen() {};
		};

		// ����� ��������� �� ��������� ������� ��� � ������
		// ����� ���������� ���������� ���������� ���
		// ������ ���� � ���������� ������ ������, ������� � ������� ��� ��� (�.�. ������ ����� ����� ��� �� ��������)
		// ��� �������� ����� ����� (��� �������� Month � ����� ������), ����������� ���������� � ���������� �� ��������� �����
		// � ��� �� ������� ��� ��������� ���


		// ������� ��������� ���������� ���������� ��� ������

		// ��������� ������ - ������������ ������� ������


		// 1 ������ 1920 � - ������� . 31 ������� - �������
		// �� ���� ����������: weak = 1 number = 4 day = 1

		calenday getDayStartingCalen(dies DATE);


	}

#endif // !CALEN_HPP