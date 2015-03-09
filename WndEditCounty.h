#ifndef WNDEDITCOUNTY_H
#define WNDEDITCOUNTY_H

#include "County.h"
#include "Base.h"

namespace UI
{
    class WndEditCounty : public QDialog
    {
        Q_OBJECT

        public:
            explicit WndEditCounty(QWidget *parent = nullptr);
            WndEditCounty(const QUuid& countyId, QWidget* parent = nullptr);
            ~WndEditCounty();

        protected:
            void initializeData();

            bool loadFromDB(const QUuid& id = QUuid());
            bool saveToDB();

        signals:

        protected slots:
            void onCancel();
            void onOK();
            void onApply();

        protected:
            bool m_NewItem;
            County m_County;

            QLabel m_lblNameRO;
            QLineEdit m_edNameRO;

            QLabel m_lblNameDE;
            QLineEdit m_edNameDE;

            QLabel m_lblNameSX;
            QLineEdit m_edNameSX;

            QLabel m_lblNameHU;
            QLineEdit m_edNameHU;

            QPushButton m_btnCancel;
            QPushButton m_btnOK;
            QPushButton m_btnApply;
    };
}

#endif // WNDEDITCOUNTY_H
