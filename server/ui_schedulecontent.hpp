#ifndef UI_SCHEDULECONTENT_HPP
#define UI_SCHEDULECONTENT_HPP

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>

#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QDate>

QT_BEGIN_NAMESPACE

class Ui_ScheduleContent
{
public:
    QWidget * mainGridLayout_;
    QLabel * scheduleNameLabel_;
    QLineEdit * scheduleNameEdit_;

    QDateEdit * beginDate_;
    QDateEdit * endDate_;

    void setupUi(QWidget* parent)
    {
        mainGridLayout_ = new QGridLayout;
        parent->setLayout(mainGridLayout_);

        scheduleNameLabel_ = new QLabel;
        scheduleNameEdit_ = new QLineEdit;




    }

private slots:
    void HandleBeginDateChanged(QDate date);
    void HandleEndDateChanged(QDate date);


};

namespace Ui
{
    class ScheduleContent : public Ui_ScheduleContent {};
}

QT_END_NAMESPACE

#endif // UI_SCHEDULECONTENT_HPP

