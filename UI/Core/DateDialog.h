#ifndef DATEDIALOG
#define DATEDIALOG

#include "Base.h"
//class QCalendarWidget;
//class QDialogButtonBox;
//class QVBoxLayout;

namespace UI
{
    namespace Core
    {
        class DateDialog : public QDialog
        {
           Q_OBJECT

            public:
               DateDialog(QWidget *parent = nullptr);
               QDate selectedDate() const;

            private:
               QWidget *widget;
               QCalendarWidget *calendarWidget;
               QDialogButtonBox* buttonBox;
               QVBoxLayout *verticalLayout;
        };
    }
}

#endif // DATEDIALOG

