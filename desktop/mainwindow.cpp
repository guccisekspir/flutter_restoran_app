#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    restaurant = new Restaurant("Restoranım");
    settingsDialog.setRestaurant(restaurant);
    this->setWindowTitle(restaurant->getName());

    ui->tableWidget_tables->setColumnCount(2);
    QStringList headers;
    headers << "Ürün" << "Fiyat";
    ui->tableWidget_tables->setHorizontalHeaderLabels(headers);

    restaurant->addTable("Masa 1");
    restaurant->addTable("Masa 2");
    restaurant->addTable("Masa 3");

    restaurant->addProduct("Çay", 2.5);
    restaurant->addProduct("Gözleme", 10);
    restaurant->addProduct("Filtre Kahve", 9);
    restaurant->addProduct("Kola", 3.5);

    restaurant->addOrder("Masa 1", "Çay", 1);
    restaurant->addOrder("Masa 1", "Gözleme", 1);
    restaurant->addOrder("Masa 1", "Filtre Kahve", 1);
    restaurant->addOrder("Masa 1", "Kola", 1);

    this->updateWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateWidgets(){
    // update_listWidget_menu
    ui->listWidget_menu->clear();
    for(auto product : restaurant->getProducts() ){
        ui->listWidget_menu->addItem(product.getName());
    }

    // update_listWidget_tables
    ui->listWidget_tables->clear();
    for(auto table : restaurant->getTables() ){
        ui->listWidget_tables->addItem(table.getName());
    }

}

void MainWindow::updateTableWidget(QString tableName){
    ui->tableWidget_tables->clearContents();
    ui->tableWidget_tables->setRowCount(0);

    activeTable = restaurant->getTable(tableName);
    if(activeTable != nullptr){
        for(auto order : activeTable->getOrders()){
            ui->tableWidget_tables->insertRow(ui->tableWidget_tables->rowCount());
            ui->tableWidget_tables->setItem(ui->tableWidget_tables->rowCount()-1, 0, new QTableWidgetItem(order._product->getName()));
            ui->tableWidget_tables->setItem(ui->tableWidget_tables->rowCount()-1, 1, new QTableWidgetItem( QString::number(order._product->getPrice())));
        }
    }
    this->updateLabelTotal();

}

void MainWindow::updateLabelTotal(){
    double total = 0;
    for(auto order : activeTable->getOrders()){
        total += order._quantity * order._product->getPrice();
    }
    ui->label_tableTotal->setText("Masa Toplam: " + QString::number(total) + " ₺");
}

void MainWindow::on_actionRestaurant_Settings_triggered()
{
    settingsDialog.setModal(true);
    settingsDialog.exec();
    if(!settingsDialog.isVisible()){
        this->updateWidgets();
        this->setWindowTitle(restaurant->getName());
    }
}

void MainWindow::on_listWidget_tables_itemClicked(QListWidgetItem *item)
{
    this->updateTableWidget(item->text());
}

// ÇİFT TIK İLE SİPARİŞ EKLEME
void MainWindow::on_listWidget_menu_itemDoubleClicked(QListWidgetItem *item)
{
    Product* product = restaurant->getProduct(item->text());
    if(product != nullptr && activeTable != nullptr){
        activeTable->addOrder(product, 1);
        this->updateTableWidget(activeTable->getName());
    }
}

// ADD ORDER BUTONU
void MainWindow::on_pushButton_addOrder_clicked()
{
    QList<QListWidgetItem*> items= ui->listWidget_menu->selectedItems();
    Product* product = nullptr;
    if(!items.empty()){
        product = restaurant->getProduct(items.first()->text());
    }
    if(product != nullptr && activeTable != nullptr){
        activeTable->addOrder(product, 1);
        items = ui->listWidget_tables->selectedItems();
        this->updateTableWidget(items.first()->text());
    }
}

void MainWindow::on_tableWidget_tables_cellClicked(int row, int column)
{
    float total = 0;
    QList<QTableWidgetItem*> items = ui->tableWidget_tables->selectedItems();
    for(auto item : items){
        if(restaurant->getProduct(item->text()) != nullptr ){
            total += restaurant->getProduct(item->text())->getPrice();
        }

    }
    ui->label_tableSelected->setText("Seçili Ürünler: " + QString::number(total) + " ₺");

}

void MainWindow::on_pushButton_pay_clicked()
{
    QList<QTableWidgetItem*> items = ui->tableWidget_tables->selectedItems();
    restaurant->checkOut(activeTable->getName(), items);
    ui->label_balance->setText("Hasılat: " + QString::number(restaurant->getBalance()) + " ₺");
    this->updateLabelTotal();
    this->updateTableWidget(activeTable->getName());
    ui->label_tableSelected->setText("Seçili Toplam: 0");

}
