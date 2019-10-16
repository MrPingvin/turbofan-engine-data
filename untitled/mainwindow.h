#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QDir>
#include <QWidget>
#include <QAbstractItemModel>
#include <QMessageBox>
#include <QDebug>
#include "fstream"
#include "ostream"
#include <QString>
#include <QDialog>
#include "string"
#include <QTextCodec>
#include <QAbstractItemModel>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Ishodnie_clicked();
    void on_Rasschetnie_clicked();
    void on_ObshieIshodnie_clicked();
    void on_KND_clicked();
    void on_KVD_clicked();
    void on_TVD_clicked();
    void on_TND_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QString fortext,stroka;
    string answ;
    QByteArray arr;
};

#endif // MAINWINDOW_H
