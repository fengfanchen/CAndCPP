#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test: public QObject{

	Q_OBJECT
public:
	Test();
	void print();
};

#endif
