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
#include "ui_DialogCharts.h"

DialogCharts::DialogCharts(QWidget *parent, QLineSeries *seriesBlData, QLineSeries *seriesBsData) :
    QDialog(parent),
    ui(new Ui::DialogCharts), seriesBlData(seriesBlData), seriesBsData(seriesBsData)
{
    ui->setupUi(this);

    this->initBlChart();
}

DialogCharts::~DialogCharts()
{
    delete ui;
}

void DialogCharts::initBlChart()
{
    this->chartBl = new QChart();

    QAreaSeries *seriesBl = new QAreaSeries(seriesBlData);
    seriesBl->setName("Loaders Busy Time");
    seriesBl->setOpacity(.7);

    QAreaSeries *seriesBs = new QAreaSeries(seriesBsData);
    seriesBs->setName("Scale Busy Time");
    seriesBs->setOpacity(.7);

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

    this->chartBl->addSeries(seriesBs);
    this->chartBl->addSeries(seriesBl);
    this->chartBl->setTitle("Total Busy Time");
    this->chartBl->setAnimationOptions(QChart::AllAnimations);

    this->chartBl->createDefaultAxes();
    int max = qMax(CumulativeStatistics::getLoadersBusyTime(), CumulativeStatistics::getScaleBusyTime());
    this->chartBl->axisX()->setRange(0, DataProvider::getCurrentClock());
    this->chartBl->axisY()->setRange(0, max);

    this->chartBl->legend()->setVisible(true);
    this->chartBl->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(this->chartBl, this);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->horizontalLayout->addWidget(chartView, 0, 0);
}
