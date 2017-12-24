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
    explicit DialogCharts(QWidget *parent, QLineSeries *seriesBlData, QLineSeries *seriesBsData);
    ~DialogCharts();

private:
    void initBlChart();
    Ui::DialogCharts *ui;
    QChart *chartBl;
    QChart *chartBs;
    QLineSeries *seriesBlData;
    QLineSeries *seriesBsData;
};

#endif // DIALOGCHARTS_HPP
