#include "../src/dies.hpp"
#include "../src/calen/calen.hpp"


#include <iostream>
#include <vector>
#include <map>

std::vector <std::string> fillnumbersVERT(calen::calen, int);


int main() {
	calen::calen CL = calen::createCalen("vertical", dies(2020, 5, 10), dies(2021, 5, 12));

	if (CL.orientation == "vertical") {
		std::vector <std::string> vecN0 = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		std::vector <std::string> vecN1 = fillnumbersVERT(CL, 1);
		std::vector <std::string> vecN2 = fillnumbersVERT(CL, 2);
		std::vector <std::string> vecN3 = fillnumbersVERT(CL, 3);
		std::vector <std::string> vecN4 = fillnumbersVERT(CL, 4);
		std::vector <std::string> vecN5 = fillnumbersVERT(CL, 5);
		std::vector <std::string> vecN6 = fillnumbersVERT(CL, 6);
		std::vector <std::string> vecN7 = fillnumbersVERT(CL, 7);
		std::vector <std::vector <std::string>> vecvec = { vecN0, vecN1, vecN2, vecN3, vecN4, vecN5, vecN6, vecN7 };

		std::map <int, std::string> weekday = {
			{0, "ом"},
			{1, "бр"},
			{2, "яп"},
			{3, "вр"},
			{4, "ор"},
			{5, "яа"},
			{6, "бя"}
		}; std::map <int, std::string>::iterator itWD = weekday.begin();

		int sleshcount = 0;

		for (int k = 0; k < vecN1.size(); k++) {
			if (vecN1[k][0] == '/') sleshcount++;
		}

		int IT = 0;
		int stWeaks = 0; int itN = 0;

		for (int k = 0; k < sleshcount; k++) {

			for (int i = 1; itWD != weekday.end(); i++, itWD++) {

				// getting year, month, weaks
				int gt = 0; int ginstr = 0; std::string weaks = ""; std::string year = ""; std::string month = ""; int Mon = 0;
				if (i == 1 && k == 0) {
					/*vecvec[i][0] == /1|2020|5\*/
					for (int g = 0; g < vecvec[i][0].size(); g++) {
						if (vecvec[i][0][g] == '|' && gt == 0) { gt++; continue; }
						if (vecvec[i][0][g] == '|' && gt == 1) { ginstr = 1; continue; }

						if (ginstr == 0 && gt == 0 && vecvec[i][0][g] != '/') {
							month.push_back(vecvec[i][0][g]);
						}

						if (ginstr == 0 && gt == 1 && vecvec[i][0][g] != '|') {
							year.push_back(vecvec[i][0][g]);
						}

						if (ginstr == 1 && vecvec[i][0][g] != '\\') {
							weaks.push_back(vecvec[i][0][g]);
						}
					}
					stWeaks += std::stoi(weaks); itN++;
					std::cout << "===========================\n";
					Mon = std::stoi(month) - 1;
					std::cout << "MONTH: " << vecN0[Mon] << "  YEAR: " << year << std::endl << std::endl;
				}
				else if (i == 1 && k != 0) {
					int c = stWeaks + itN;
					for (int g = 0; g < vecvec[i][c].size(); g++) {
						if (vecvec[i][c][g] == '|' && gt == 0) { gt++; continue; }
						if (vecvec[i][c][g] == '|' && gt == 1) { ginstr = 1; continue; }

						if (ginstr == 0 && gt == 0 && vecvec[i][c][g] != '/') {
							month.push_back(vecvec[i][c][g]);
						}

						if (ginstr == 0 && gt == 1 && vecvec[i][c][g] != '|') {
							year.push_back(vecvec[i][c][g]);
						}

						if (ginstr == 1 && vecvec[i][c][g] != '\\') {
							weaks.push_back(vecvec[i][c][g]);
						}
					}
					stWeaks += std::stoi(weaks); itN++;
					std::cout << "===========================\n";
					Mon = std::stoi(month) - 1;
					std::cout << "MONTH: " << vecN0[Mon] << "  YEAR: " << year << std::endl << std::endl;
				}


				// output monthes
				IT = -1;
				std::cout << itWD->second << "   ";
				for (int j = 0; j < vecvec[i].size(); j++) {

					if (vecvec[i][j][0] == '/') {
						if (IT == k) break;
						else IT++;
					}
					else if (IT == k) std::cout << std::setw(2) << std::setfill(' ') << vecvec[i][j] << " ";

				} std::cout << '\n';

			} itWD = weekday.begin();
			std::cout << '\n';
		}

	}
	if (CL.orientation == "horizontal") {

	}

	return 0;
}

std::vector <std::string> fillnumbersVERT(calen::calen CL, int N) {
	int iterweak = 0; int v = -1;
	std::vector <std::string> result;
	std::vector <std::string> resmonth;

	for (int itMonth = 0; itMonth < CL.arrayOfMonths.size(); itMonth++) {

		result.push_back("/" + std::to_string(CL.arrayOfMonths[itMonth].month) + "|" +
			std::to_string(CL.arrayOfMonths[itMonth].monthofyear) + "|" + std::to_string(CL.arrayOfMonths[itMonth].weaks) + "\\");

		for (int itDay = 0; itDay < CL.arrayOfMonths[itMonth].arrayOfDays.size(); itDay++) {
			for (itDay; itDay < CL.arrayOfMonths[itMonth].arrayOfDays.size(); itDay++) {
				if (CL.arrayOfMonths[itMonth].arrayOfDays[itDay].number == N) {
					v = itDay; iterweak++; break;
				}
				else v = -1;
			}
			if (v != -1) {
				if (iterweak == 1) {
					for (int i = 1; i < CL.arrayOfMonths[itMonth].arrayOfDays[v].weak; i++) {
						result.push_back(" ");
						resmonth.push_back(" ");
					}
				}
				result.push_back(std::to_string(CL.arrayOfMonths[itMonth].arrayOfDays[v].day));
				resmonth.push_back(std::to_string(CL.arrayOfMonths[itMonth].arrayOfDays[v].day));
			}
		}

		for (int k = resmonth.size(); k < CL.arrayOfMonths[itMonth].weaks; k++) {
			result.push_back(" ");
		}
		resmonth.clear();

		iterweak = 0;
	}

	resmonth.clear();
	return result;
}