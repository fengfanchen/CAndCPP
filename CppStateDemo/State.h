#pragma once

#include <string>
using namespace std;

class People;

class VIPState
{
public:
	VIPState(People *people);

	virtual void vipIncreasing() = 0;
	virtual string getStatusDesc() const  = 0;
	virtual ~VIPState() = 0;

protected:
	People *m_people;
};


class SSSVIPState : public VIPState{

public:
	SSSVIPState(People *people);
	~SSSVIPState();
	string getStatusDesc() const;
	void vipIncreasing();
};

class SVIPState : public VIPState{

public:
	SVIPState(People *people);
	~SVIPState();
	string getStatusDesc() const;
	void vipIncreasing();
};

class CommonVIPState : public VIPState{

public:
	CommonVIPState(People *people);
	~CommonVIPState();
	string getStatusDesc() const;
	void vipIncreasing();
};

