#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QDialog;
class QWidget;
class QListWidgetItem;

namespace Ui {
class EntryWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
   void HandleEnterClicked();
   void HandleCancelClicked();
   void HandleNavigationItemChanged(QListWidgetItem* current, QListWidgetItem* previous);

private:
   void Switch2Browser();

private:
    Ui::EntryWindow *ui;
    QWidget * browser_;

};

#endif // MAINWINDOW_H
