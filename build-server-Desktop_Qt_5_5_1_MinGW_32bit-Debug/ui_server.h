/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_browser_
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *mainLayout_;
    QStackedWidget *stackedWidget;
    QWidget *mapPage_;
    QWidget *schedulePage_;
    QWidget *userPage_;
    QWidget *configPage_;
    QWidget *firmwarePage_;
    QDockWidget *navigationDock_;
    QWidget *dockWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *dockLayout_;
    QListWidget *navigationView_;

    void setupUi(QWidget *browser_)
    {
        if (browser_->objectName().isEmpty())
            browser_->setObjectName(QStringLiteral("browser_"));
        browser_->resize(844, 607);
        horizontalLayoutWidget = new QWidget(browser_);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(180, 9, 661, 591));
        mainLayout_ = new QHBoxLayout(horizontalLayoutWidget);
        mainLayout_->setObjectName(QStringLiteral("mainLayout_"));
        mainLayout_->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(horizontalLayoutWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        mapPage_ = new QWidget();
        mapPage_->setObjectName(QStringLiteral("mapPage_"));
        stackedWidget->addWidget(mapPage_);
        schedulePage_ = new QWidget();
        schedulePage_->setObjectName(QStringLiteral("schedulePage_"));
        stackedWidget->addWidget(schedulePage_);
        userPage_ = new QWidget();
        userPage_->setObjectName(QStringLiteral("userPage_"));
        stackedWidget->addWidget(userPage_);
        configPage_ = new QWidget();
        configPage_->setObjectName(QStringLiteral("configPage_"));
        stackedWidget->addWidget(configPage_);
        firmwarePage_ = new QWidget();
        firmwarePage_->setObjectName(QStringLiteral("firmwarePage_"));
        stackedWidget->addWidget(firmwarePage_);

        mainLayout_->addWidget(stackedWidget);

        navigationDock_ = new QDockWidget(browser_);
        navigationDock_->setObjectName(QStringLiteral("navigationDock_"));
        navigationDock_->setGeometry(QRect(10, 20, 161, 581));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayoutWidget = new QWidget(dockWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 160, 551));
        dockLayout_ = new QVBoxLayout(verticalLayoutWidget);
        dockLayout_->setObjectName(QStringLiteral("dockLayout_"));
        dockLayout_->setContentsMargins(0, 0, 0, 0);
        navigationView_ = new QListWidget(verticalLayoutWidget);
        new QListWidgetItem(navigationView_);
        new QListWidgetItem(navigationView_);
        new QListWidgetItem(navigationView_);
        new QListWidgetItem(navigationView_);
        new QListWidgetItem(navigationView_);
        navigationView_->setObjectName(QStringLiteral("navigationView_"));

        dockLayout_->addWidget(navigationView_);

        navigationDock_->setWidget(dockWidgetContents);

        retranslateUi(browser_);

        QMetaObject::connectSlotsByName(browser_);
    } // setupUi

    void retranslateUi(QWidget *browser_)
    {
        browser_->setWindowTitle(QApplication::translate("browser_", "Browser", 0));

        const bool __sortingEnabled = navigationView_->isSortingEnabled();
        navigationView_->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = navigationView_->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("browser_", "\351\200\232\344\277\241MAP", 0));
        QListWidgetItem *___qlistwidgetitem1 = navigationView_->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("browser_", "\350\256\241\345\210\222\347\256\241\347\220\206", 0));
        QListWidgetItem *___qlistwidgetitem2 = navigationView_->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("browser_", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        QListWidgetItem *___qlistwidgetitem3 = navigationView_->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("browser_", "\351\205\215\347\275\256\346\226\207\344\273\266", 0));
        QListWidgetItem *___qlistwidgetitem4 = navigationView_->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("browser_", "\345\233\272\344\273\266\347\256\241\347\220\206", 0));
        navigationView_->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class browser_: public Ui_browser_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
