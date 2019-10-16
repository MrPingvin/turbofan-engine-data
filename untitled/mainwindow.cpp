#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include "qfile.h"
#include "qtextcodec.h"
#include "iostream"
#include "fstream"
#include "formuls.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Ishodnie_clicked()
{
    ui->ObshieIshodnie->setCheckable(true);
    ui->ObshieIshodnie->setEnabled(true);
    model = new QStandardItemModel( 0, 0, this);
    ui->tableView->setModel( model );
    qDebug() << "Ishodnie";
}
void MainWindow::on_Rasschetnie_clicked()
{
    ui->ObshieIshodnie->setCheckable(false);
    ui->ObshieIshodnie->setEnabled(false);
    model = new QStandardItemModel( 0, 0, this);
    ui->tableView->setModel( model );
    qDebug() << "Rasschet";
}
void MainWindow::on_ObshieIshodnie_clicked()
{
    if (ui->Ishodnie->isChecked())
    {
        QTextCodec *utf= QTextCodec::codecForName( "UTF-8" );
        model = new QStandardItemModel( 10, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..Data\\all\\param.txt";
        ifstream filePARAM(fortext.toStdString());
        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }

        i=0;
        fortext = "..Data\\all\\znach.txt";
        ifstream fileZNACH(fortext.toStdString());
        if (fileZNACH.is_open())
        {
            qDebug() << "Open";
            while (getline(fileZNACH, answ))
            {
                QModelIndex index = model->index(i,1);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(1);
            fileZNACH.close();
        }
    }
    else
    {
        model = new QStandardItemModel( 0, 0, this);
        ui->tableView->setModel( model );
    }
    qDebug() << "ObshieIshodnie";
}

void MainWindow::on_KND_clicked()
{
    QTextCodec *utf= QTextCodec::codecForName( "UTF-8" );
    if (ui->Ishodnie->isChecked())
    {
        model = new QStandardItemModel( 11, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..Data\\KND\\param.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }

        i=0;
        fortext = "..Data\\KND\\znach.txt";
        ifstream fileZNACH(fortext.toStdString());

        if (fileZNACH.is_open())
        {
            qDebug() << "Open";
            while (getline(fileZNACH, answ))
            {
                QModelIndex index = model->index(i,1);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(1);
            fileZNACH.close();
        }
    }
    else
    {
        model = new QStandardItemModel( 15, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..NameForm\\KND.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }
        int iner=0;
        QModelIndex index = model->index(0,1);//Затрачиваемая работа на привод КНД
        model->setData( index, Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")));index = model->index(++iner,1);
        index = model->index(1,1);//Наружный диаметр первой ступени КНД
        //model->setData( index, );
        index = model->index(2,1);//Средний диаметр КНД на входе
        //model->setData( index, );
        index = model->index(3,1);//Диаметр втулки КНД на входе
        //model->setData( index, );
        index = model->index(4,1);//Показатель политропы сжатия в КНД
        //model->setData( index, );
        index = model->index(5,1);//Отношение площадей кольцевых сечений входа из КНД
        //model->setData( index, );
        index = model->index(6,1);//Площадь кольцевого сечения на выходе из КНД
        //model->setData( index, );
        index = model->index(7,1);//Относительный диаметр втулки на выходе из КНД
        //model->setData( index, );
        index = model->index(8,1);//Наружный диаметр на выходе из КНД
        //model->setData( index, );
        index = model->index(9,1);//Диаметр втулки КНД на выходе
        //model->setData( index, );
        index = model->index(10,1);//Средний диаметр КНД на выходе
        //model->setData( index, );
        index = model->index(11,1);//Частота вращения ротора КНД
        //model->setData( index, );
        index = model->index(12,1);//Площадь кольцевого сечения за вентилятором по наружному контуру
        //model->setData( index, );
        index = model->index(13,1);//Диаметр передней кромки разделителя контуров
        //model->setData( index, );
        index = model->index(14,1);//Полусуммка средних диаметров на входе и выходе КНД
        ui->tableView->resizeColumnToContents(1);
     }
  qDebug() << "KND";
}

void MainWindow::on_KVD_clicked()
{
    QTextCodec *utf= QTextCodec::codecForName( "UTF-8" );
    if (ui->Ishodnie->isChecked())
    {
        model = new QStandardItemModel( 11, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..Data\\KVD\\param.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }

        i=0;
        fortext = "..Data\\KVD\\znach.txt";
        ifstream fileZNACH(fortext.toStdString());

        if (fileZNACH.is_open())
        {
            qDebug() << "Open";
            while (getline(fileZNACH, answ))
            {
                QModelIndex index = model->index(i,1);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(1);
            fileZNACH.close();
        }
    }
    else
    {
        model = new QStandardItemModel( 24, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..NameForm\\KVD.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }
        QModelIndex index = model->index(0,1);//температура на входе в КВД
        model->setData( index, TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")));
        index = model->index(1,1);//Давление на входе в КВД
        model->setData( index, RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh")));
        index = model->index(2,1);//Затрачиваемая работа на привод КВД
        model->setData(index, LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")));
        index = model->index(3,1);//Температура охдаждающего воздуха ТВД
        model->setData(index, Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))));
        index = model->index(4,1);//Температура рабочей лопатки ТВД с учетом ее охлаждения
        model->setData(index, Tlohl(Tl(TTVDvih(FindARG("Tg"),LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg")),UTVDsr(FindARG("Y"),Cad(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("NTVD")),FindARG("ZstKVD")),FindARG("Kg"),FindARG("Rg")),FindARG("QTVD"),Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")))));
        index = model->index(5,1);//Температура на выходе из КВД
        model->setData(index, TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))));
        index = model->index(6,1);//Давление воздуха на выходе из КВД
        model->setData(index, RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))));//////
        index = model->index(7,1);//Критическая скорость на выходе из КВД
        model->setData(index, akrKVDvih(FindARG("K"),FindARG("R"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))))); //нет аргумента TvhKVD температура входа
        index = model->index(8,1);//Скорость на выходе из КВД
        model->setData(index, CvihKVD(FindARG("LvihKVD"),akrKVDvih(FindARG("K"),FindARG("R"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))))));
        index = model->index(9,1);//Приведенный расход воздуха на выходе из КВД
        model->setData(index, qLvihKVD(FindARG("K"),FindARG("LvihKVD")));
        index = model->index(10,1);//Площадь кольцевого сечения канала на выходе из КВД
        model->setData(index, FvihKVD(FindARG("GvKVD"),FindARG("GohlTVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),FindARG("Sv"),RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("KG")));
        index = model->index(11,1);//Показатель политропы сжатия в КВД
        model->setData(index, NKVDmin1(FindARG("PKVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R"))));
        index = model->index(12,1);//Отношение кольцевых площадей входа и выхода КВД
        model->setData(index, FKVD(FindARG("PKVD"),FindARG("NKVD"),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("qLvhKVD")));
        index = model->index(13,1);//Площадь кольцевого сечения канала на входе в КВД
        model->setData(index, FvhKVD(FKVD(FindARG("PKVD"),FindARG("NKVD"),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("qLvhKVD")),FvihKVD(FindARG("GvKVD"),FindARG("GohlTVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),FindARG("Sv"),RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("KG"))));
        index = model->index(14,1);//Наружный диаметр на входе в КВД
        model->setData(index, DkKVDvh(FvhKVD(FKVD(FindARG("PKVD"),FindARG("NKVD"),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("qLvhKVD")),FvihKVD(FindARG("GvKVD"),FindARG("GohlTVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),FindARG("Sv"),RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("KG"))),FindARG("dvtKVDvh")));
        index = model->index(15,1);//Диаметр втулки на входе в КВД
        model->setData(index, DvtKVDvh(FindARG("dvtKVDvh"),FindARG("dvtKVDvh")));//DKVDvh = dvtKVDvh
        index = model->index(16,1);//Средний диаметр на входе в КВД
        model->setData(index, DsrKVDvh(DkKVDvh(FvhKVD(FKVD(FindARG("PKVD"),FindARG("NKVD"),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("qLvhKVD")),FvihKVD(FindARG("GvKVD"),FindARG("GohlTVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),FindARG("Sv"),RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("KG"))),FindARG("dvtKVDvh")),DvtKVDvh(FindARG("dvtKVDvh"),FindARG("dvtKVDvh"))));
        index = model->index(17,1);//Высота лопатки последней ступени КВД !!!!!нужно добавить разные схемы
        model->setData(index, hkKVDDk(FindARG("dvtKVDvih"),FindARG("dvtKVDvh")));
        index = model->index(18,1);//Окружная скорость на внешнем диаметре первой ступени КВД
       // model->setData(index, UkKVD(FindARG("dvtKVDvh"),ngg(UTVDsr(),Dgsr)));
        index = model->index(19,1);//Средний диаметр КВД
        model->setData(index, DKVDsrvihDk(DkKVDvh(FvhKVD(FKVD(FindARG("PKVD"),FindARG("NKVD"),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("qLvhKVD")),FvihKVD(FindARG("GvKVD"),FindARG("GohlTVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),FindARG("Sv"),RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("KG"))),FindARG("dvtKVDvh")),hkKVDDk(FindARG("dvtKVDvih"),FindARG("dvtKVDvh"))));
        index = model->index(20,1);//Число ступеней КВД
        //model->setData(index, ZKVD(DTVDsr(DvihTVDsr(Dgsr)),DKVDsrvihDk(DkKVDvh(FvhKVD(FKVD(FindARG("PKVD"),FindARG("NKVD"),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("qLvhKVD")),FvihKVD(FindARG("GvKVD"),FindARG("GohlTVD"),TvihKVD(Tohl(TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD"))),FindARG("Sv"),RvihKVD(FindARG("PKVD"),RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh"))),qLvihKVD(FindARG("K"),FindARG("LvihKVD")),FindARG("KG"))),FindARG("dvtKVDvh")),hkKVDDk(FindARG("dvtKVDvih"),FindARG("dvtKVDvh"))),FindARG("ZstKVD"),FindARG("Kgg")));
        //index = model->index(21,1);//Площадь кольцевого сечения проточной части за КНД для внутреннего контура
        //model->setData(index, );
        //index = model->index(22,1);//Наружный диаметр на выходе из КВД
        //model->setData(index, );
        //index = model->index(23,1);//Диаметр втулки на выходе из КВД
        //model->setData(index, );
        ui->tableView->resizeColumnToContents(1);
    }
  qDebug() << "KVD";
}

void MainWindow::on_TVD_clicked()
{
    QTextCodec *utf= QTextCodec::codecForName( "UTF-8" );
    if (ui->Ishodnie->isChecked())
    {
        model = new QStandardItemModel( 11, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..Data\\TVD\\param.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }

        i=0;
        fortext = "..Data\\TVD\\znach.txt";
        ifstream fileZNACH(fortext.toStdString());
        if (fileZNACH.is_open())
        {
            qDebug() << "Open";
            while (getline(fileZNACH, answ))
            {
                QModelIndex index = model->index(i,1);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(1);
            fileZNACH.close();
        }
    }
    else
    {
        model = new QStandardItemModel( 23, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..NameForm\\TVD.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }
        QModelIndex index = model->index(0,1);//Потребная внутренняя удельная работа ТВД
        model->setData( index, LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")));
        index = model->index(1,1);//Условная адиабатная скорость ТВД
        model->setData( index, Cad(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("NTVD")));
        index = model->index(2,1);//Окружная скорость на среднем диаметре ТВД
        model->setData( index, UTVDsr(FindARG("Y"),Cad(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("NTVD")),FindARG("ZstKVD")));
        index = model->index(3,1);//Температура газа за ТВД
        model->setData( index, TTVDvih(FindARG("Tg"),LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg")));
        index = model->index(4,1);//Температура в корневом сечении неохлаждаемых рабочих лопаток ступени ТВД
        model->setData( index, Tl(TTVDvih(FindARG("Tg"),LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg")),UTVDsr(FindARG("Y"),Cad(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("NTVD")),FindARG("ZstKVD")),FindARG("Kg"),FindARG("Rg")));
        index = model->index(5,1);//Относительная высота рабочих лопаток ступени ТВД
        model->setData( index, DTVDsrhrl(UTVDsr(FindARG("Y"),Cad(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("NTVD")),FindARG("ZstKVD")),FindARG("Pm"),FindARG("F"),FindARG("Kq"),FindARG("qTVD")));
        index = model->index(6,1);//Отношение полных давлений в ТВД
        model->setData( index, PgPtTVD(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg"),FindARG("Tg"),FindARG("NTVD")));
        index = model->index(7,1);//Полное давление перед ТВД
        model->setData( index, Pg(RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh")),FindARG("PKVD"),FindARG("qKS")));
        index = model->index(8,1);//Полное давление за ТВД
       // model->setData( index, PtTVD(Pg(RKVDvh(FindARG("Pv"),FindARG("Pn"),FindARG("qvh"),FindARG("qVHA"),FindARG("qpereh")),FindARG("PKVD"),FindARG("qKS")),PgPtTVD(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg"),FindARG("Tg"),FindARG("NTVD"))));
        index = model->index(9,1);//Приведенный расход на выходе из ТВД
        model->setData( index, qL2TVD(FindARG("Kg"),FindARG("L2TVD")));
        index = model->index(10,1);//Площадь кольцевого сечения каналов на выходе из ТВД
        model->setData( index, FtTVD(FindARG("GgTVD"),FindARG("GohlTVD"),FindARG("GvKVD"),TTVDvih(FindARG("Tg"),LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg")),FindARG("Sg"),PtTVD(Pg(FindARG("PKVD"),FindARG("PKVD"),FindARG("qKS")),PgPtTVD(LTVD(LKVD(FindARG("K"),FindARG("R"),TKVDvh(FindARG("Tn"),Lvent(FindARG("K"),FindARG("R"),FindARG("Tn"),FindARG("Pv"),FindARG("Nven")),FindARG("K"),FindARG("R")),FindARG("PKVD"),FindARG("NKVD")),FindARG("KT")),FindARG("Kg"),FindARG("Rg"),FindARG("Tg"),FindARG("NTVD"))),qL2TVD(FindARG("Kg"),FindARG("L2TVD")),FindARG("a2TVD")));
        index = model->index(11,1);//Высота рабочей лопатке на выходе последней ступени ТВД
        //model->setData( index, hTVDvih(FtTVD(),DTVDsr(),hrl));
        index = model->index(12,1);//Средний диаметр ТВД на выходе
        //model->setData( index, DvihTVDsr(hTVDvih(),DTVDsr(),hrl));
        index = model->index(13,1);//Наружный диаметр последней ступени ТВД
        //model->setData( index, DvihTVDnaruj());
        index = model->index(14,1);//Внутренний диаметр на выходе из последней ступени ТВД
        //model->setData( index, DTVDvtul());
        index = model->index(15,1);//Относительный диаметр втулки последней ступени ТВД
        //model->setData( index, dvihTVD());
        index = model->index(16,1);//Приведенный расход газа на выходе из ТВД
        model->setData( index, qLg(FindARG("Kg"),FindARG("Lg")));
        index = model->index(17,1);//Площадь кольцевого сечения канала на входе в ступень ТВД
        model->setData( index, FgTVD(FindARG("GgTVD"),FindARG("Tg"),FindARG("Sg"),Pg(FindARG("PKVD"),FindARG("PKVD"),FindARG("qKS")),qLg(FindARG("Kg"),FindARG("Lg"))));
        index = model->index(18,1);//Средний диаметр ТВД на входе
        //model->setData( index, DvihTVDsr(Dg));
        index = model->index(19,1);//Наружный диаметр на входе ТВД
        //model->setData( index, Dgnar(Dgsr));
        index = model->index(20,1);//Диаметр втулки на входе ТВД
        //model->setData( index, Dgvt());
        index = model->index(21,1);//Частота вращения ротора ТВД
        //model->setData( index, ngg(UTVDsr(),Dgsr));
        index = model->index(22,1);//Средний диаметр ТВД
        //model->setData( index, );
        ui->tableView->resizeColumnToContents(1);
    }
  qDebug() << "TVD";
}

void MainWindow::on_TND_clicked()
{
    QTextCodec *utf= QTextCodec::codecForName( "UTF-8" );
    if (ui->Ishodnie->isChecked())
    {
        model = new QStandardItemModel( 11, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..Data\\TND\\param.txt";
        ifstream filePARAM(fortext.toStdString());
        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }

        i=0;
        fortext = "..Data\\TND\\znach.txt";
        ifstream fileZNACH(fortext.toStdString());
        if (fileZNACH.is_open())
        {
            qDebug() << "Open";
            while (getline(fileZNACH, answ))
            {
                QModelIndex index = model->index(i,1);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(1);
            fileZNACH.close();
        }
    }
    else
    {
        model = new QStandardItemModel( 22, 2, this);
        model->setHeaderData(0, Qt::Horizontal, "ПАРАМЕТРЫ");
        model->setHeaderData(1, Qt::Horizontal, "ЗНАЧЕНИЕ");

        ui->tableView->setModel( model );
        ui->tableView->setStyleSheet("QHeaderView::section:all{background-color: cyan;}");
        int i = 0;
        fortext = "..NameForm\\TND.txt";
        ifstream filePARAM(fortext.toStdString());

        if (filePARAM.is_open())
        {
            qDebug() << "Open";
            while (getline(filePARAM, answ))
            {
                QModelIndex index = model->index(i,0);
                arr.append(stroka.fromStdString(answ));

                arr = utf->fromUnicode(arr);
                model->setData( index, arr);

                arr.clear();
                i++;

            }
            ui->tableView->resizeColumnToContents(0);
            filePARAM.close();
        }
    }
  qDebug() << "TND";
}
