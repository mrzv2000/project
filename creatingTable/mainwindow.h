#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString headLable;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ShowButt_clicked();

    void on_searchButt_clicked();



private:
    Ui::MainWindow *ui;
    void showInfo();
    void search();
};
#endif // MAINWINDOW_H
