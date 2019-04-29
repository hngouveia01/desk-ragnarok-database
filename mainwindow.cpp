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
    }
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
    QSqlQuery query;
    query.exec("SELECT id, name_japanese, item_image FROM item_db WHERE name_japanese LIKE '%" + ui->lineEditSearch->text() + "%'");

    ui->listWidget->clear();

    while (query.next()) {
        QString name = query.value(0).toString() + " " + query.value(1).toString();
        QByteArray outByteArray = query.value(2).toByteArray();
        QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData(outByteArray);
        QIcon icon = QIcon(outPixmap);
        QListWidgetItem *item = new QListWidgetItem(icon, name);
        ui->listWidget->addItem(item);
    }
}

void MainWindow::on_lineEditSearch_returnPressed()
{
    on_pushButton_clicked();
}
