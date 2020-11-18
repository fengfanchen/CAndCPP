#include "TestClass.h"
#include <QDebug>

//TestClass::TestClass()
//{
//    qDebug() << "TestClass()";
//}

TestClass::TestClass(int intValue, QString stringValue)
{
    this->m_intValue = intValue;
    this->m_stringValue = stringValue;
}

//TestClass::TestClass(TestClass &test)
//{
//    this->m_intValue = test.getIntValue();
//    this->m_stringValue = test.getStringValue();
//}

int TestClass::getIntValue()
{
    return this->m_intValue;
}

QString TestClass::getStringValue()
{
    return this->m_stringValue;
}

void TestClass::setIntValue(const int &intvalue)
{
    this->m_intValue = intvalue;
}

void TestClass::setStringValule(const QString &stringValue)
{
    this->m_stringValue = stringValue;
}
