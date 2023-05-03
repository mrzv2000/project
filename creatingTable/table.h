#ifndef TABLE_H
#define TABLE_H
#include<QString>
#include<QVector>
class table
{
public:
    table();
    QVector<QString> infoVect;
    QVector<QString> searchVect;
    void saveInfo(QString);
    void searchInfo(QString , QString);
    QString warning;
};

#endif // TABLE_H
