/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#include "CumulativeStatistics.hpp"
#include "DataProvider.hpp"
#include "DialogCharts.hpp"
#include "DialogSimulation.hpp"
#include "FutureEventList.hpp"
#include "Loader.hpp"
#include "LoadingQueue.hpp"
#include "Scale.hpp"
#include "WeighQueue.hpp"
#include "ui_DialogSimulation.h"

#include <QMessageBox>
#include <QPushButton>
#include <QSettings>

DialogSimulation::DialogSimulation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSimulation)
{
    ui->setupUi(this);

    connect(this, &DialogSimulation::finished, this, &DialogSimulation::onFinished);

    this->seriesBlData = new QLineSeries(this);
    this->seriesBsData = new QLineSeries(this);

    // Simulation table
    this->initializeSimulationTable();

    // Statistics button
    this->addStatisticsButton();
}

DialogSimulation::~DialogSimulation()
{
    delete ui;
}

void DialogSimulation::onFinished(int code)
{
    Q_UNUSED(code);

    QSettings settings;
    settings.setValue("simulator/headerState", ui->tableWidgetSimulation->horizontalHeader()->saveState());
    settings.setValue("simulator/geometry", this->saveGeometry());
}

void DialogSimulation::onStatisticsButtonClicked(bool checked)
{
    Q_UNUSED(checked);

    DialogCharts dlg(this, this->seriesBlData, this->seriesBsData);
    dlg.exec();
}

void DialogSimulation::initializeSimulationTable()
{
    // Headers
    QStringList strLstHeaders;
    strLstHeaders << "Clock t" << "LQ(t)" << "L(t)" << "WQ(t)" << "W(t)" << "Loader Queue" << "Weigh Queue" << "Future Event List" << "B L" << "B S";
    ui->tableWidgetSimulation->setHorizontalHeaderLabels(strLstHeaders);
    QSettings settings;
    ui->tableWidgetSimulation->setRowCount(settings.value("simulation/count").toUInt());


    // Load past state
    ui->tableWidgetSimulation->horizontalHeader()->restoreState(settings.value("simulator/headerState").toByteArray());
    this->restoreGeometry(settings.value("simulator/geometry").toByteArray());

    // Execute simulation
    this->executeSimulation();

    // Load table
    this->visualizeDataTable();
}

void DialogSimulation::executeSimulation()
{
    QSettings settings;

    // First item

    // Trucks
    QList<DumpTruck*> trucks;
    auto truckCount = settings.value("simulation/itemsInitialize/trucks").toUInt();
    for (unsigned int i = 1; i < truckCount + 1; ++i) {
        auto dt = new DumpTruck(i, this);
        trucks.append(dt);
    }

    // Loading queue
    LoadingQueue loadingQueue;
    auto loadingQueueCount = settings.value("simulation/itemsInitialize/loadingQueue").toUInt();
    for (unsigned int i = 0; i < loadingQueueCount; ++i) {
        loadingQueue.addTruck(trucks.at(i));
    }

    // Loaders
    Loader loaders;

    auto loaderCount = settings.value("simulation/itemsInitialize/loader").toUInt();
    loaderCount += loadingQueueCount;
    for (unsigned int i = loadingQueueCount; i < loaderCount; ++i) {
        loaders.addTruck(trucks.at(i));
    }

    // Weigh queue
    ::WeighQueue weighQueue;

    auto weighQueueCount = settings.value("simulation/itemsInitialize/weighQueue").toUInt();
    weighQueueCount += loaderCount;
    for (unsigned int i = loaderCount; i < weighQueueCount; ++i) {
        weighQueue.addTruck(trucks.at(i));
    }

    // Scale
    Scale scale;
    if(settings.value("simulation/itemsInitialize/scale").toBool()) {
        scale.addTruck(trucks.last());
    }

    // Events
    auto futureEventList = ::FutureEventList::getInstance();

    QHash<Columns, QString> firstRow;

    firstRow[Clock] = QString::number(DataProvider::getCurrentClock());
    firstRow[LQt] = loadingQueue.getCount();
    firstRow[Lt] = loaders.getCount();
    firstRow[WQt] = weighQueue.getCount();
    firstRow[Wt] = scale.getCount();
    firstRow[LoaderQueue] = loadingQueue.getString();
    firstRow[WeighQueue] = weighQueue.getString();
    firstRow[FutureEventList] = futureEventList->getString();
    firstRow[Bl] = QString::number(CumulativeStatistics::getLoadersBusyTime());
    this->seriesBlData->append(DataProvider::getCurrentClock(), CumulativeStatistics::getLoadersBusyTime());
    firstRow[Bs] = QString::number(CumulativeStatistics::getScaleBusyTime());
    this->seriesBsData->append(DataProvider::getCurrentClock(), CumulativeStatistics::getScaleBusyTime());
    lstMap.append(firstRow);

    auto simulationCount = settings.value("simulation/count").toUInt();

    // Rest of items
    for (unsigned int i = 0; i < simulationCount - 1; ++i) {
        Event *nextEvent = futureEventList->getNextEvent();

        if(nextEvent == nullptr) {
            // All events are processed
            QMessageBox::information(this, "End of Process", "No event is in future event list.");
            break;
        }

        // Update clock
        DataProvider::updateClock(nextEvent->getTime());

        loadingQueue.processEvents(nextEvent);

        // Process loaders events
        loaders.processEvents(loadingQueue, weighQueue);

        // Process scale events
        scale.processEvents(weighQueue);

        QHash<Columns, QString> row;

        row[Clock] = QString::number(DataProvider::getCurrentClock());
        row[LQt] = loadingQueue.getCount();
        row[Lt] = loaders.getCount();
        row[WQt] = weighQueue.getCount();
        row[Wt] = scale.getCount();
        row[LoaderQueue] = loadingQueue.getString();
        row[WeighQueue] = weighQueue.getString();
        row[FutureEventList] = futureEventList->getString();
        row[Bl] = QString::number(CumulativeStatistics::getLoadersBusyTime());
        this->seriesBlData->append(DataProvider::getCurrentClock(), CumulativeStatistics::getLoadersBusyTime());
        row[Bs] = QString::number(CumulativeStatistics::getScaleBusyTime());
        this->seriesBsData->append(DataProvider::getCurrentClock(), CumulativeStatistics::getScaleBusyTime());
        lstMap.append(row);
    }

    // Cleanup
    foreach (auto truck, trucks) {
        truck->deleteLater();
    }

}

void DialogSimulation::visualizeDataTable()
{
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

void DialogSimulation::addStatisticsButton()
{
    QPushButton *button = ui->buttonBox->addButton("Statistics", QDialogButtonBox::ActionRole);
    connect(button, &QAbstractButton::clicked, this, &DialogSimulation::onStatisticsButtonClicked);
}
