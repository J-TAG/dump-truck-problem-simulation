/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Loading time
    this->initializeLoadingTimeTable();

    // Weighing time
    this->initializeWeghingTimeTable();

    // Travel time
    this->initializeTravelTimeTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeLoadingTimeTable()
{

    // Headers
    QStringList strLstHeaders;
    strLstHeaders << "Loading Time" << "Probability" << "Cumulative Probability" << "Random Digit Assignment";
    ui->tableWidgetLoadingTime->setHorizontalHeaderLabels(strLstHeaders);

    // Items
    QTableWidgetItem *item1 = new QTableWidgetItem("5");
    ui->tableWidgetLoadingTime->setItem(0, 0, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem("10");
    ui->tableWidgetLoadingTime->setItem(1, 0, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("15");
    ui->tableWidgetLoadingTime->setItem(2, 0, item3);

    QTableWidgetItem *item4 = new QTableWidgetItem("0.30");
    ui->tableWidgetLoadingTime->setItem(0, 1, item4);

    QTableWidgetItem *item5 = new QTableWidgetItem("0.50");
    ui->tableWidgetLoadingTime->setItem(1, 1, item5);

    QTableWidgetItem *item6 = new QTableWidgetItem("0.20");
    ui->tableWidgetLoadingTime->setItem(2, 1, item6);

    QTableWidgetItem *item7 = new QTableWidgetItem("0.30");
    ui->tableWidgetLoadingTime->setItem(0, 2, item7);

    QTableWidgetItem *item8 = new QTableWidgetItem("0.80");
    ui->tableWidgetLoadingTime->setItem(1, 2, item8);

    QTableWidgetItem *item9 = new QTableWidgetItem("1.00");
    ui->tableWidgetLoadingTime->setItem(2, 2, item9);

    QTableWidgetItem *item10 = new QTableWidgetItem("1-3");
    ui->tableWidgetLoadingTime->setItem(0, 3, item10);

    QTableWidgetItem *item11 = new QTableWidgetItem("4-8");
    ui->tableWidgetLoadingTime->setItem(1, 3, item11);

    QTableWidgetItem *item12 = new QTableWidgetItem("9-0");
    ui->tableWidgetLoadingTime->setItem(2, 3, item12);
}

void MainWindow::initializeWeghingTimeTable()
{
    // Headers
    QStringList strLstHeaders;
    strLstHeaders << "Weighing Time" << "Probability" << "Cumulative Probability" << "Random Digit Assignment";
    ui->tableWidgetWeighingTime->setHorizontalHeaderLabels(strLstHeaders);

    // Items
    QTableWidgetItem *item1 = new QTableWidgetItem("12");
    ui->tableWidgetWeighingTime->setItem(0, 0, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem("16");
    ui->tableWidgetWeighingTime->setItem(1, 0, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("0.70");
    ui->tableWidgetWeighingTime->setItem(0, 1, item3);

    QTableWidgetItem *item4 = new QTableWidgetItem("0.30");
    ui->tableWidgetWeighingTime->setItem(1, 1, item4);

    QTableWidgetItem *item5 = new QTableWidgetItem("0.70");
    ui->tableWidgetWeighingTime->setItem(0, 2, item5);

    QTableWidgetItem *item6 = new QTableWidgetItem("1.00");
    ui->tableWidgetWeighingTime->setItem(1, 2, item6);

    QTableWidgetItem *item7 = new QTableWidgetItem("1-7");
    ui->tableWidgetWeighingTime->setItem(0, 3, item7);

    QTableWidgetItem *item8 = new QTableWidgetItem("8-0");
    ui->tableWidgetWeighingTime->setItem(1, 3, item8);
}

void MainWindow::initializeTravelTimeTable()
{
    // Headers
    QStringList strLstHeaders;
    strLstHeaders << "Travel Time" << "Probability" << "Cumulative Probability" << "Random Digit Assignment";
    ui->tableWidgetTravelTime->setHorizontalHeaderLabels(strLstHeaders);

    // Items
    QTableWidgetItem *item1 = new QTableWidgetItem("40");
    ui->tableWidgetTravelTime->setItem(0, 0, item1);

    QTableWidgetItem *item2 = new QTableWidgetItem("60");
    ui->tableWidgetTravelTime->setItem(1, 0, item2);

    QTableWidgetItem *item3 = new QTableWidgetItem("80");
    ui->tableWidgetTravelTime->setItem(2, 0, item3);

    QTableWidgetItem *item4 = new QTableWidgetItem("100");
    ui->tableWidgetTravelTime->setItem(3, 0, item4);

    QTableWidgetItem *item5 = new QTableWidgetItem("0.40");
    ui->tableWidgetTravelTime->setItem(0, 1, item5);

    QTableWidgetItem *item6 = new QTableWidgetItem("0.30");
    ui->tableWidgetTravelTime->setItem(1, 1, item6);

    QTableWidgetItem *item7 = new QTableWidgetItem("0.20");
    ui->tableWidgetTravelTime->setItem(2, 1, item7);

    QTableWidgetItem *item8 = new QTableWidgetItem("0.10");
    ui->tableWidgetTravelTime->setItem(3, 1, item8);

    QTableWidgetItem *item9 = new QTableWidgetItem("0.40");
    ui->tableWidgetTravelTime->setItem(0, 2, item9);

    QTableWidgetItem *item10 = new QTableWidgetItem("0.70");
    ui->tableWidgetTravelTime->setItem(1, 2, item10);

    QTableWidgetItem *item11 = new QTableWidgetItem("0.90");
    ui->tableWidgetTravelTime->setItem(2, 2, item11);

    QTableWidgetItem *item12 = new QTableWidgetItem("1.00");
    ui->tableWidgetTravelTime->setItem(3, 2, item12);

    QTableWidgetItem *item13 = new QTableWidgetItem("1-4");
    ui->tableWidgetTravelTime->setItem(0, 3, item13);

    QTableWidgetItem *item14 = new QTableWidgetItem("5-7");
    ui->tableWidgetTravelTime->setItem(1, 3, item14);

    QTableWidgetItem *item15 = new QTableWidgetItem("8-9");
    ui->tableWidgetTravelTime->setItem(2, 3, item15);

    QTableWidgetItem *item16 = new QTableWidgetItem("0");
    ui->tableWidgetTravelTime->setItem(3, 3, item16);
}
