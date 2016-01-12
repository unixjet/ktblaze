#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QUiLoader>
#include <QFile>
#include <QDesktopWidget>
#include <QListWidget>
#include <utility.h>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EntryWindow),
    browser_(nullptr)
{
    ui->setupUi(this);
    connect(ui->btnOK_, &QPushButton::clicked, this, &MainWindow::HandleEnterClicked);
    connect(ui->btnCancel_, &QPushButton::clicked, this, &MainWindow::HandleCancelClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    if(browser_)
        delete browser_;
}

// #######################################
// slots handlers
void MainWindow::HandleEnterClicked()
{
    std::cout << "on enter clicked\n" ;
    Switch2Browser();
}

void MainWindow::HandleCancelClicked()
{
    this->close();
}

void MainWindow::HandleNavigationItemChanged(QListWidgetItem* current, QListWidgetItem* previous)
{
    (void)previous;
    if(current)
    {
        std::cout << utility::to_string(current->text().toStdWString()) << " selected\n";
    }
}

void MainWindow::Switch2Browser()
{
    QUiLoader loader;
    const int width = 1024 ;
    const int height = 728;

    QFile file("E:\\mgzhou\\WorkSpace\\Project\\ktblaze\\res\\interface\\server.ui");
    file.open(QFile::ReadOnly);
    browser_ = loader.load(&file, this);
    file.close();
    this->setCentralWidget(browser_);
    QRect deskRect = QApplication::desktop()->availableGeometry();

    int x = (deskRect.width() - width)/2 + deskRect.left();
    int y = (deskRect.height()- height)/2 + deskRect.top();
    this->setGeometry(QRect(x, y , width, height));
    this->setWindowTitle(QString("Browser"));

    QListWidget * navigationView = browser_->findChild<QListWidget*>("navigationView_");
    if(navigationView)
    {
        connect(navigationView, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
                this, SLOT(HandleNavigationItemChanged(QListWidgetItem*, QListWidgetItem*)));
        std::cout << "capture navigationView\n";

        QListWidgetItem * it = navigationView->item(0);
        if(it)
        {
            std::cout  << "find " << utility::to_string(it->text().toStdWString()) << "\n";
            navigationView->setItemSelected(it, true);
            HandleNavigationItemChanged(it, 0); //manual change items
        }
    }

    this->update();
}
