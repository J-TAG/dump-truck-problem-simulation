/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "DialogSimulation.hpp"
#include "FutureEventList.hpp"
#include "Loader.hpp"
#include "LoadingQueue.hpp"
#include "Scale.hpp"
#include "WeighQueue.hpp"
#include "ui_DialogSimulation.h"

DialogSimulation::DialogSimulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSimulation)
{
    ui->setupUi(this);

    // Simulation table
    this->initializeSimulationTable();
}

DialogSimulation::~DialogSimulation()
{
    delete ui;
}

void DialogSimulation::initializeSimulationTable()
{
    // Headers
    QStringList strLstHeaders;
    strLstHeaders << "Clock t" << "LQ(t)" << "L(t)" << "WQ(t)" << "W(t)" << "Loader Queue" << "Weigh Queue" << "Future Event List" << "B L" << "B S";
    ui->tableWidgetSimulation->setHorizontalHeaderLabels(strLstHeaders);

    // Trucks
    DumpTruck dt1(1);
    DumpTruck dt2(2);
    DumpTruck dt3(3);
    DumpTruck dt4(4);
    DumpTruck dt5(5);
    DumpTruck dt6(6);

    // Loading queue
    LoadingQueue loadingQueue;
    loadingQueue.addTruck(&dt4);
    loadingQueue.addTruck(&dt5);
    loadingQueue.addTruck(&dt6);

    // Loaders
    Loader loaders;
    loaders.addTruck(&dt3);
    loaders.addTruck(&dt2);

    // Weigh queue
    ::WeighQueue weighQueue;

    // Scale
    Scale scale;
    scale.addTruck(&dt1);

    // Events
    auto futureEventList = ::FutureEventList::getInstance();


    short clock = 0;

    QHash<Columns, QString> row1;

    row1[Clock] = QString::number(clock);
    row1[LQt] = loadingQueue.getCount();
    row1[Lt] = loaders.getCount();
    row1[WQt] = weighQueue.getCount();
    row1[Wt] = scale.getCount();
    row1[LoaderQueue] = loadingQueue.getString();
    row1[WeighQueue] = weighQueue.getString();
    row1[FutureEventList] = futureEventList->getString();
    row1[Bl] = "";
    row1[Bs] = "";
    lstMap.append(row1);


    // View items
    for (int i = 0; i < lstMap.count(); ++i) {
        auto map = lstMap.at(i);

        QTableWidgetItem *item1 = new QTableWidgetItem(map[Clock]);
        ui->tableWidgetSimulation->setItem(i, 0, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(map[LQt]);
        ui->tableWidgetSimulation->setItem(i, 1, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(map[Lt]);
        ui->tableWidgetSimulation->setItem(i, 2, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(map[WQt]);
        ui->tableWidgetSimulation->setItem(i, 3, item4);

        QTableWidgetItem *item5 = new QTableWidgetItem(map[Wt]);
        ui->tableWidgetSimulation->setItem(i, 4, item5);

        QTableWidgetItem *item6 = new QTableWidgetItem(map[LoaderQueue]);
        ui->tableWidgetSimulation->setItem(i, 5, item6);

        QTableWidgetItem *item7 = new QTableWidgetItem(map[WeighQueue]);
        ui->tableWidgetSimulation->setItem(i, 6, item7);

        QTableWidgetItem *item8 = new QTableWidgetItem(map[FutureEventList]);
        ui->tableWidgetSimulation->setItem(i, 7, item8);

        QTableWidgetItem *item9 = new QTableWidgetItem(map[Bl]);
        ui->tableWidgetSimulation->setItem(i, 8, item9);

        QTableWidgetItem *item10 = new QTableWidgetItem(map[Bs]);
        ui->tableWidgetSimulation->setItem(i, 9, item10);
    }

}
