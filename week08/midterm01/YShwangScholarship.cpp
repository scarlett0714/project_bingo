#include "YShwangScholarship.h"

YShwangScholarship::YShwangScholarship()
{
}

YShwangScholarship::YShwangScholarship(const string& title, const int& number)
	: m_title(title), m_number(number)
{
	if (m_number > 0) {
		team = shared_ptr<YShwangStudent* []>(new YShwangStudent * [m_number]);
		//team = new Salesman* [m_number];		
	}
	else
		team = nullptr;
}

void YShwangScholarship::apply(YShwangStudent& student)
{


	if (team != nullptr) {
		double sum = team[0]->getScore(); //³» ¸â¹ö : . vs ->
		highestScore = team[0]->getScore();
		for (size_t i = 1; i < m_number; i++) {
			if (highestScore < team[i]->getScore()) {
				highestScore = team[i]->getScore();
			}
			sum += team[i]->getScore();
		}
		
	}
}
