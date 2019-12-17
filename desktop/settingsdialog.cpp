#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <QDebug>
SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::setRestaurant(Restaurant *res){
    restaurant = res;
    qDebug() << restaurant->getName() << " aktarıldı.";
    this->setWindowTitle(restaurant->getName() + " Settings Panel");
}

void SettingsDialog::listWidgetUpdateTables(){
    ui->listWidget_tables->clear();
    for(auto table : restaurant->getTables()){
        ui->listWidget_tables->addItem(table.getName());
    }
}

void SettingsDialog::listWidgetUpdateProducts(){
    ui->listWidget_products->clear();
    for(auto product : restaurant->getProducts()){
        qDebug() << product.getPrice();
        ui->listWidget_products->addItem(product.getName() + "\t" + QString::number(product.getPrice()));
    }
}

void SettingsDialog::on_pushButton_addTable_clicked()
{
    QString name = ui->lineEdit_tableName->text();
    if(name != ""){
        if(restaurant->addTable(name) == true){
            qDebug() << name << " başarıyla eklendi!" << endl;
            listWidgetUpdateTables();
        }else{
            qDebug() << name << " adlı bir ürün zaten var. Farklı bir isim deneyin." << endl;
        }
    }else{
        qDebug() << "Ürün ismi boş olamaz!" << endl;
    }
}

void SettingsDialog::on_pushButton_removeTable_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget_tables->selectedItems();
    foreach(QListWidgetItem* item, items){
        if(restaurant->deleteTable(item->text())){
            qDebug() << item->text() << " adlı eleman siliniyor." << endl;
            listWidgetUpdateTables();
            delete item;
        }else{
            qDebug() << item->text() << " adlı eleman silinemedi." << endl;
        }
    }
}

void SettingsDialog::on_pushButton_addProduct_clicked()
{
    QString name = ui->lineEdit_productName->text();
    double price = ui->doubleSpinBox_productPrice->value();
    qDebug() << "Seçilen item'ın değeri: " << price;
    if(name != ""){
        if(restaurant->addProduct(name, price) == true){
            qDebug() << name << " başarıyla eklendi!" << endl;
            listWidgetUpdateProducts();
        }else{
            qDebug() << name << " adlı bir masa zaten var. Farklı bir isim deneyin." << endl;
        }
    }else{
        qDebug() << "Masa ismi boş olamaz!" << endl;
    }
}

void SettingsDialog::on_pushButton_removeProduct_clicked()
{
    QList<QListWidgetItem*> items = ui->listWidget_products->selectedItems();
    foreach(QListWidgetItem* item, items){
        QString name = item->text();
        QStringList strList = name.split("\t");
        name = strList.value(strList.length()-2);
        if(restaurant->deleteProduct(name)){
            qDebug() << name << " adlı eleman siliniyor." << endl;
            listWidgetUpdateTables();
            delete item;
        }else{
            qDebug() << name << " adlı eleman silinemedi." << endl;
        }
    }
}

void SettingsDialog::on_pushButton_saveChanges_clicked()
{
    restaurant->setName(ui->lineEdit_restaurantName->text());
}
