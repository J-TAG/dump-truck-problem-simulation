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

private:
    void initializeSimulationTable();
    Ui::DialogSimulation *ui;
    QList<QHash<Columns, QString>> lstMap;
};

#endif // DIALOGSIMULATION_HPP
