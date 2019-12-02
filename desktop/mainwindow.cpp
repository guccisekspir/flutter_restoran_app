#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    restaurant = new Restaurant("My Restaurant");
    settingsDialog.setRestaurant(restaurant);
    this->setWindowTitle(restaurant->getName());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRestaurant_Settings_triggered()
{
    settingsDialog.setModal(true);
    settingsDialog.exec();

}
