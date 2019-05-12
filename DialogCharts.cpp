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
#include "ui_DialogCharts.h"

DialogCharts::DialogCharts(QWidget *parent, QLineSeries *seriesBlData, QLineSeries *seriesBsData, QLineSeries *seriesLoading, QLineSeries *seriesWeighing) :
    QDialog(parent),
    ui(new Ui::DialogCharts), seriesBlData(seriesBlData), seriesBsData(seriesBsData), seriesLoading(seriesLoading), seriesWeighing(seriesWeighing)
{
    ui->setupUi(this);

    // Busy chart
    this->initBusyChart();

    // Queue chart
    this->initQueueChart();
}

DialogCharts::~DialogCharts()
{
    this->chartBusy->removeSeries(this->seriesBl);
    this->chartBusy->removeSeries(this->seriesBs);
    this->chartQueue->removeSeries(this->seriesLoading);
    this->chartQueue->removeSeries(this->seriesWeighing);
    delete ui;
}

void DialogCharts::initBusyChart()
{
    this->chartBusy = new QChart();

    this->seriesBl = new QAreaSeries(this->seriesBlData);
    seriesBl->setName("Loaders Busy Time");
    seriesBl->setOpacity(.85);

    this->seriesBs = new QAreaSeries(this->seriesBsData);
    seriesBs->setName("Scale Busy Time");
    seriesBs->setOpacity(.85);

    QLinearGradient gradientBl(QPointF(0, 0), QPointF(0, 1));
    gradientBl.setColorAt(0.0, 0x72309f);
    gradientBl.setColorAt(1.0, 0xcccccc);
    gradientBl.setCoordinateMode(QGradient::ObjectBoundingMode);
    seriesBl->setBrush(gradientBl);

    QLinearGradient gradientBs(QPointF(0, 0), QPointF(0, 1));
    gradientBs.setColorAt(0.0, 0x234563);
    gradientBs.setColorAt(1.0, 0xcccccc);
    gradientBs.setCoordinateMode(QGradient::ObjectBoundingMode);
    seriesBs->setBrush(gradientBs);

    this->chartBusy->addSeries(seriesBs);
    this->chartBusy->addSeries(seriesBl);
    this->chartBusy->setTitle("Total Busy Time");
    this->chartBusy->setAnimationOptions(QChart::AllAnimations);

    this->chartBusy->createDefaultAxes();
    unsigned int max = qMax(CumulativeStatistics::getLoadersBusyTime(), CumulativeStatistics::getScaleBusyTime());
    this->chartBusy->axes(Qt::Horizontal).back()->setRange(0, DataProvider::getCurrentClock());
    this->chartBusy->axes(Qt::Horizontal).back()->setTitleText("Clock");
    this->chartBusy->axes(Qt::Vertical).back()->setRange(0, max);
    this->chartBusy->axes(Qt::Vertical).back()->setTitleText("Busy Time");

    this->chartBusy->legend()->setVisible(true);
    this->chartBusy->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(this->chartBusy, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(chartView, 0, nullptr);
}

void DialogCharts::initQueueChart()
{
    this->chartQueue = new QChart();

    this->seriesLoading->setName("Loadeing Queue");
    this->seriesWeighing->setName("Weighing Queue");

    this->chartQueue->addSeries(this->seriesLoading);
    this->chartQueue->addSeries(this->seriesWeighing);
    this->chartQueue->setTitle("Queues");
    this->chartQueue->setAnimationOptions(QChart::AllAnimations);

    this->chartQueue->createDefaultAxes();
    QSettings settings;
    auto truckCount = settings.value("simulation/itemsInitialize/trucks").toUInt();
    this->chartQueue->axes(Qt::Horizontal).back()->setRange(0, DataProvider::getCurrentClock());
    this->chartQueue->axes(Qt::Horizontal).back()->setTitleText("Clock");
    this->chartQueue->axes(Qt::Vertical).back()->setRange(0, truckCount);
    this->chartQueue->axes(Qt::Vertical).back()->setTitleText("Trucks in Queue");

    this->chartQueue->legend()->setVisible(true);
    this->chartQueue->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(this->chartQueue, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(chartView, 0, nullptr);
}
