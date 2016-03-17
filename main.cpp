#include <QCoreApplication>
#include <iostream>
#include <QUdpSocket>

using namespace std;

struct entry{
    quint32 x;
    qint32  y;   // 64 bits
    quint16 z;
    quint16 v;
    quint16 n;
    quint16 t;   // 64 bits
        // Total : 128 bits
};

union eu{
    entry e;
    char packed[16];
    char mini[8];
};

QUdpSocket udpServerSocket;

void readUdpDatagrams(){

}

int  main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    eu e;

    char to[16]         = {1, 0, 0, 0, 2, 0, 0, 0, 3, 0, 4, 0, 5, 0, 6, 0};
    char mini_sample[8] = {7, 0, 0, 0, 8, 0, 0, 0};

    memcpy(&e.packed, &to, 16);

    cout << "X = " << e.e.x << " ";
    cout << "Y = " << e.e.y << " ";
    cout << "T = " << e.e.t << " ";
    cout << "Z = " << e.e.z << " ";
    cout << "V = " << e.e.v << " ";
    cout << "N = " << e.e.n << " ";
    cout << "\n";

    memcpy(&e.packed, &mini_sample, 8);

    cout << "X = " << e.e.x << " ";
    cout << "Y = " << e.e.y << " ";
    cout << "\n";

    return a.exec();
}

