#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (&mytApp, &MYTApp::searchFinished, this, &MainWindow::receiveSearch);
    ui->videoList->setEditTriggers(QAbstractItemView::NoEditTriggers); // Stops the user from editing the search results.
    ui->videoList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveSearch(QList<videoData> videoList)
{
    ui->searchBar->setText(curSearch);
    ui->searchBar->setEnabled(true);
    ui->searchButton->setEnabled(true);

    // First we clear the table using a for loop so that we don't lose the column labels
    for (int i = ui->videoList->rowCount() - 1; i > 0; i--)
    {
        ui->videoList->removeRow(i);
    }

    ui->videoList->setRowCount(videoList.size());
    for (int i = 0; i < videoList.size(); i++)
    {
        ui->videoList->setItem(i, 0, new QTableWidgetItem("Placeholder"));
        ui->videoList->setItem(i, 1, new QTableWidgetItem(videoList[i].title));
        ui->videoList->setItem(i, 2, new QTableWidgetItem(videoList[i].channel));
        ui->videoList->setItem(i, 3, new QTableWidgetItem(videoList[i].uploadDate));
        ui->videoList->setItem(i, 4, new QTableWidgetItem(videoList[i].views));
    }
}

void MainWindow::on_searchButton_clicked()
{
    curSearch = ui->searchBar->text();
    mytApp.getSearch(curSearch);
    ui->searchBar->setText(tr("Please wait..."));
    ui->searchBar->setEnabled(false);
    ui->searchButton->setEnabled(false);
}

void MainWindow::on_searchBar_returnPressed()
{
    on_searchButton_clicked();
}
