#include <QCoreApplication>
#include <iostream>

using namespace std;

union myUnion
{
    int iValue;
    float fValue;
};

struct myStruct
{
    int iValue;
    float fValue;
};

union eu{
    struct entry{
        quint32 x;
        qint32  y;   // 64 bits
        quint16 z;
        quint16 v;
        quint16 n;
        quint16 t;   // 64 bits
            // Total : 128 bits
    };

    char packed[16];
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    myStruct myS;
    myS.iValue = 1;
    myS.fValue = 2.0;

    myUnion myU;
    myU.iValue = 1;
    myU.fValue = 2.0;

    cout << myS.iValue << " " << myS.fValue << endl;
    cout << myU.iValue << " " << myU.fValue << endl;

    return a.exec();
}
