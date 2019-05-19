#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

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

    m_db = Database();

    try {
        m_db.initialize();
    } catch (DbException& e) {
        QMessageBox::information(parent, "Error", e.getMessage());
        exit(EXIT_FAILURE);
    }

    ui->lineEditSearchMonster->setFocus();

    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ID" << "Name");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEditSearchMonster_returnPressed() {
    ui->tableWidget->setRowCount(0);

    int currentRow = 0;

    while (1) {
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
