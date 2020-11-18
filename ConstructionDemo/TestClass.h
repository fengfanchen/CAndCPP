#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QString>
#include <QDebug>

class TestClass
{
public:
    TestClass() = delete;
    TestClass(int intValue, QString stringValue);
    TestClass(TestClass &test) = default;

    int getIntValue();
    QString getStringValue();
    void setIntValue(const int &intvalue);
    void setStringValule(const QString &stringValue);


    friend QDebug operator << (QDebug os, TestClass test){

        os << "(" << test.m_intValue << ", "
           << test.m_stringValue << ")";

        return os;
    }

private:
    int m_intValue;
    QString m_stringValue;
};

#endif // TESTCLASS_H
