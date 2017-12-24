/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef DIALOGSIMULATION_HPP
#define DIALOGSIMULATION_HPP

#include <QDialog>
#include <QHash>
#include <QAbstractButton>
#include <QLineSeries>
#include <QSplineSeries>

using namespace QtCharts;

namespace Ui {
class DialogSimulation;
}

class DialogSimulation : public QDialog
{
    Q_OBJECT

public:
    enum Columns {
        Clock, LQt, Lt, WQt, Wt, LoaderQueue, WeighQueue, FutureEventList, Bl, Bs
    };
    explicit DialogSimulation(QWidget *parent = 0);
    ~DialogSimulation();

public slots:
    void onFinished(int code);
    void onStatisticsButtonClicked(bool checked);

private:
    void initializeSimulationTable();
    void executeSimulation();
    void visualizeDataTable();
    void addStatisticsButton();
    Ui::DialogSimulation *ui;
    QList<QHash<Columns, QString>> lstMap;
    QLineSeries *seriesBlData;
    QLineSeries *seriesBsData;
    QLineSeries *seriesLoading;
    QLineSeries *seriesWeighing;
};

#endif // DIALOGSIMULATION_HPP
