#include "DateDialog.h"

using namespace UI::Core;

DateDialog::DateDialog(QWidget *parent)
    :   QDialog(parent, Qt::Popup)
{
    resize(260, 230);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

    verticalLayout->addWidget(calendarWidget);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

    verticalLayout->addWidget(buttonBox);

    setLayout(verticalLayout);

    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

QDate
DateDialog::selectedDate() const
{
    return calendarWidget->selectedDate();
}
