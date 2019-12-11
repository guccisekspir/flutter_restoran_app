#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTableWidgetItem>
#include <QString>
#include <QDebug>

#include "restaurant.h"
#include "settingsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void updateWidgets();
    void updateTableWidget(QString tableName);
    void updateLabelTotal();

    void on_actionRestaurant_Settings_triggered();

    void on_listWidget_tables_itemClicked(QListWidgetItem *item);

    void on_listWidget_menu_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_addOrder_clicked();

    void on_tableWidget_tables_cellClicked(int row, int column);

    void on_pushButton_pay_clicked();

private:
    Restaurant* restaurant;
    SettingsDialog settingsDialog;
    Ui::MainWindow *ui;

    Table* activeTable;

};
#endif // MAINWINDOW_H
