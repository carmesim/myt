#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MYTApp mytApp;
    QList<videoData> videoList; ///< QList for video results.
    QString curSearch = ""; ///< QString that holds the last search, for advancing pages and restoring the search query after switching to the "Please wait" message.
    Ui::MainWindow *ui;

private slots:
    /*!
     * \brief Slot for receiving MYTApp's search results.
     * \param videoList List of videos found for the search.
     */
    void receiveSearch(QList<videoData> _videoList);
    void on_searchButton_clicked();
    void on_searchBar_returnPressed();
    void on_videoList_cellDoubleClicked(int row, int column);
};
#endif // MAINWINDOW_H
