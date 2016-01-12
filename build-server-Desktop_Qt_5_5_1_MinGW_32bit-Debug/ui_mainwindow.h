/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntryWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *inputLayout_;
    QLabel *lableInput_;
    QLineEdit *inputUserName_;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *buttonLayout_;
    QPushButton *btnOK_;
    QPushButton *btnCancel_;

    void setupUi(QMainWindow *EntryWindow)
    {
        if (EntryWindow->objectName().isEmpty())
            EntryWindow->setObjectName(QStringLiteral("EntryWindow"));
        EntryWindow->resize(504, 353);
        centralWidget = new QWidget(EntryWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(60, 50, 351, 51));
        inputLayout_ = new QHBoxLayout(horizontalLayoutWidget);
        inputLayout_->setSpacing(6);
        inputLayout_->setContentsMargins(11, 11, 11, 11);
        inputLayout_->setObjectName(QStringLiteral("inputLayout_"));
        inputLayout_->setContentsMargins(0, 0, 0, 0);
        lableInput_ = new QLabel(horizontalLayoutWidget);
        lableInput_->setObjectName(QStringLiteral("lableInput_"));

        inputLayout_->addWidget(lableInput_);

        inputUserName_ = new QLineEdit(horizontalLayoutWidget);
        inputUserName_->setObjectName(QStringLiteral("inputUserName_"));

        inputLayout_->addWidget(inputUserName_);

        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(90, 140, 271, 41));
        buttonLayout_ = new QHBoxLayout(horizontalLayoutWidget_2);
        buttonLayout_->setSpacing(30);
        buttonLayout_->setContentsMargins(11, 11, 11, 11);
        buttonLayout_->setObjectName(QStringLiteral("buttonLayout_"));
        buttonLayout_->setContentsMargins(0, 0, 0, 0);
        btnOK_ = new QPushButton(horizontalLayoutWidget_2);
        btnOK_->setObjectName(QStringLiteral("btnOK_"));

        buttonLayout_->addWidget(btnOK_);

        btnCancel_ = new QPushButton(horizontalLayoutWidget_2);
        btnCancel_->setObjectName(QStringLiteral("btnCancel_"));

        buttonLayout_->addWidget(btnCancel_);

        EntryWindow->setCentralWidget(centralWidget);

        retranslateUi(EntryWindow);

        QMetaObject::connectSlotsByName(EntryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EntryWindow)
    {
        EntryWindow->setWindowTitle(QApplication::translate("EntryWindow", "EntryWindow", 0));
        lableInput_->setText(QApplication::translate("EntryWindow", "\347\224\250\346\210\267\345\220\215", 0));
        btnOK_->setText(QApplication::translate("EntryWindow", "\347\241\256\345\256\232", 0));
        btnCancel_->setText(QApplication::translate("EntryWindow", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class EntryWindow: public Ui_EntryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
