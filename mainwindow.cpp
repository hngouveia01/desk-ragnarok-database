#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPixmap>
#include <QListWidget>
#include <QListWidgetItem>
#include <QSqlQueryModel>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("192.168.1.69");
    db.setDatabaseName("rathena_rag");
    db.setUserName("root");
    db.setPassword("mirolhadb");


    if (!db.open()) {
        QMessageBox::information(parent, "Error", "Error while opening database");
        exit(EXIT_FAILURE);
    }

    ui->lineEditSearch->setFocus();

    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name");
}

MainWindow::~MainWindow()
{
    if (db.isOpen()) {
        db.close();
    }

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query("select item_db.item_image, item_db.id, item_db.name_japanese FROM item_db WHERE item_db.name_japanese LIKE '%" + ui->lineEditSearch->text() + "%' UNION SELECT mob_db.image_mob, mob_db.id, mob_db.iName FROM mob_db WHERE mob_db.iName LIKE '%" + ui->lineEditSearch->text() + "%'");
    query.exec();

    int currentRow = 0;

    while (query.next()) {
        ui->tableWidget->insertRow(currentRow);

        QString id = query.value(1).toString();
        QString name = query.value(2).toString();

        QByteArray outByteArray = query.value(0).toByteArray();
        QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData(outByteArray);
        QIcon icon = QIcon(outPixmap);

        QTableWidgetItem *itemIcon = new QTableWidgetItem();
        itemIcon->setIcon(icon);
        ui->tableWidget->setVerticalHeaderItem(currentRow, itemIcon);

        auto *itemId = new QTableWidgetItem(id);
        ui->tableWidget->setItem(currentRow, 0, itemId);

        auto *itemName = new QTableWidgetItem(name);
        ui->tableWidget->setItem(currentRow, 1, itemName);
        currentRow++;
    }
    ui->tableWidget->resizeRowsToContents();
}

void MainWindow::on_lineEditSearch_returnPressed()
{
    on_pushButton_clicked();
}
