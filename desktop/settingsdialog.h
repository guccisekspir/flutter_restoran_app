#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();
    void setRestaurant(Restaurant* res);

    void listWidgetUpdateTables();
    void listWidgetUpdateProducts();

private slots:
    void on_pushButton_addTable_clicked();

    void on_pushButton_removeTable_clicked();

    void on_pushButton_addProduct_clicked();

    void on_pushButton_removeProduct_clicked();

private:
    Ui::SettingsDialog *ui;
    Restaurant* restaurant;
};

#endif // SETTINGSDIALOG_H
