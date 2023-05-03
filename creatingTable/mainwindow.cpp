#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableWidget>
#include<QTableWidgetItem>
#include"table.h"
#include<QDebug>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto header = ui->tableWidget->horizontalHeader();
    connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
        headLable = ui->tableWidget->horizontalHeaderItem(logicalIndex)->text();
        //qDebug() << logicalIndex << headLable;
    });
}

void MainWindow::showInfo(){
    table obj1;
    obj1.saveInfo("//home//mohammadreza//information");
    //qDebug()<<obj1.infoVect.at(1);
    int numOfRows , counter=0;
    QString columnName;
    QStringList header;
    header <<"Name" <<"Family Name" << "Age";
    numOfRows = obj1.infoVect.size()/3;
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(numOfRows);
    for(int i=0 ; i<numOfRows ; i++){
        for(int j=0 ; j<3 ; j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(obj1.infoVect.at(counter));
            ui->tableWidget->setHorizontalHeaderLabels(header);
            ui->tableWidget->setItem(i,j,item);
            counter++;
        }
    }
}

void MainWindow::search(){
    table obj1;
    QString keyToSearch;
    obj1.searchInfo("//home//mohammadreza//information" ,  keyToSearch = ui->searchLine->text());
    //qDebug()<<obj1.infoVect.at(1);
    int numOfRows , counter=0;
    QString columnName;
    QStringList header;
    header <<"Name" <<"Family Name" << "Age";
    numOfRows = obj1.searchVect.size()/3;
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(numOfRows);
    for(int i=0 ; i<numOfRows ; i++){
        for(int j=0 ; j<3 ; j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(obj1.searchVect.at(counter));
            ui->tableWidget->setHorizontalHeaderLabels(header);
            ui->tableWidget->setItem(i,j,item);
            counter++;
        }
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ShowButt_clicked()
{
    showInfo();
}


void MainWindow::on_searchButt_clicked()
{
    search();
}


//void MainWindow::on_checking_clicked()
//{
//    QString informationBox = "You are searching by "+ headLable;
//    QMessageBox::information(this , tr("Search") , informationBox);
//}

