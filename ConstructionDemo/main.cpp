#include <QCoreApplication>
#include <TestClass.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestClass test2(1, "Hello World");
    TestClass test(test2);
    qDebug() << test;

    return a.exec();
}
