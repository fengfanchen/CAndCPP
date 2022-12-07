#include "People.h"
#include "State.h"
#include <iostream>
using namespace std;


People::People()
{
	cout << "People::People() called" << endl;
	this->m_state = nullptr;
	this->m_gold = 0;
}


People::~People()
{
	cout << "People::~People() called" << endl;
	if (this->m_state)
		delete this->m_state;
}

void People::addGold(const long & value)
{
	this->m_gold += value;
}

const long& People::getCurrentGold()
{
	return m_gold;
}

void People::payByDay(const int & type)
{
	if (type == 0) {

		this->setState(new CommonVIPState(this));
	}
	else if (type == 1) {

		this->setState(new SVIPState(this));
	}
	else {

		this->setState(new SSSVIPState(this));
	}
	this->m_state->vipIncreasing();
}

string People::currentStateDesc()
{
	return this->m_state->getStatusDesc();
}

void People::setState(VIPState * vipState)
{
	if (this->m_state != nullptr) {

		delete this->m_state;
		m_state = nullptr;
	}

	this->m_state = vipState;
}