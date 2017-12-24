/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef DUMPTRUCK_HPP
#define DUMPTRUCK_HPP

#include <QObject>

class DumpTruck : public QObject
{
    Q_OBJECT
public:
    enum State {
        None, InLoaderQueue, Loading, InWeighQueue, Weighing, Traveling
    };
    explicit DumpTruck(int index, QObject *parent = nullptr);

    void setState(State state);
    QString getName() const;
    int getIndex() const;
    State getState() const;

signals:

public slots:
private:
    int index = -1;
    State state = None;
};

#endif // DUMPTRUCK_HPP
