#include "table.h"
#include<QString>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
table::table()
{

}
void table::saveInfo(QString fileName){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        warning = "File Not Found";
    }else{
        QString word;
        QString line;
        QStringList words;
        QTextStream putIn(&file);
        while (!putIn.atEnd()) {
            line = putIn.readLine();
            words = line.split(" ");
            foreach (word, words) {
                infoVect.push_back(word);
            }
        }
    }
}

void table::searchInfo(QString fileName , QString key){
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)){
        warning = "File Not Found";
    }else{
        QString word;
        QString line;
        QStringList words;
        QTextStream putIn(&file);
        while (!putIn.atEnd()) {
            line = putIn.readLine();
            if(line.contains(key)){
                words = line.split(" ");
                foreach (word, words) {
                    searchVect.push_back(word);
                }
            }

        }
    }
}
