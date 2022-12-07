#include "State.h"
#include "People.h"
#include <iostream>
using namespace std;


VIPState::VIPState(People *people){

	this->m_people = people;
}

VIPState::~VIPState() {

}

SSSVIPState::SSSVIPState(People *people) : VIPState(people){

}

SSSVIPState::~SSSVIPState()
{
}

string SSSVIPState::getStatusDesc() const
{
	return string("SSS级VIP");
}

void SSSVIPState::vipIncreasing() 
{
	m_people->addGold(100);
	cout << "金币+100" << endl;
}

SVIPState::SVIPState(People *people) : VIPState(people) {

}

SVIPState::~SVIPState()
{
}

string SVIPState::getStatusDesc() const
{
	return string("S级VIP");
}

void SVIPState::vipIncreasing()
{
	m_people->addGold(10);
	cout << "金币+10" << endl;
}


CommonVIPState::CommonVIPState(People *people) : VIPState(people) {

}

CommonVIPState::~CommonVIPState()
{
}

string CommonVIPState::getStatusDesc() const
{
	return string("普通VIP");
}

void CommonVIPState::vipIncreasing()
{
	long currentGold = m_people->getCurrentGold();
	if (currentGold <= 0)
		return;

	long dGold = currentGold - 5;
	if (dGold < 0) {

		m_people->addGold(currentGold);
		cout << "金币-" << currentGold << endl;
		return;
	}
	
	m_people->addGold(-5);
	cout << "金币-5" << endl;
}


