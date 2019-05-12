/**************************************************************************
** Code written by Hesam Gholami.
**
** Email: hesamgholami@yahoo.com
** Website: http://hesam.org
**
** This file created in 12.
**************************************************************************/
#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSimulation_clicked();

private:
    Ui::MainWindow *ui;
    void initializeLoadingTimeTable();
    void initializeWeghingTimeTable();
    void initializeTravelTimeTable();
    void saveData();
    void loadData();
};

#endif // MAINWINDOW_HPP
