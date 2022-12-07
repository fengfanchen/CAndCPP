#pragma once

#include <string>
using namespace std;

class VIPState;

class People
{
public:
	People();
	~People();
	void addGold(const long &value);
	const long& getCurrentGold();
	void payByDay(const int &type);	//√ø»’“ª≥‰
	string currentStateDesc();

protected:
	void setState(VIPState *vipState);

private:
	long m_gold;
	VIPState *m_state;
};

