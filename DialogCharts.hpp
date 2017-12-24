/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef DIALOGCHARTS_HPP
#define DIALOGCHARTS_HPP

#include <QDialog>
#include <QtCharts>

using namespace QtCharts;

namespace Ui {
class DialogCharts;
}

class DialogCharts : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCharts(QWidget *parent, QLineSeries *seriesBlData, QLineSeries *seriesBsData, QLineSeries *seriesLoading, QLineSeries *seriesWeighing);
    ~DialogCharts();

private:
    void initBusyChart();
    void initQueueChart();
    Ui::DialogCharts *ui;
    QChart *chartBusy;
    QChart *chartQueue;
    QLineSeries *seriesBlData;
    QLineSeries *seriesBsData;
    QLineSeries *seriesLoading;
    QLineSeries *seriesWeighing;
    QAreaSeries *seriesBl;
    QAreaSeries *seriesBs;
};

#endif // DIALOGCHARTS_HPP
