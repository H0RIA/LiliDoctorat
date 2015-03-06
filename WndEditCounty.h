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
            void onLanguageChanged();

            void onCancel();
            void onOK();
            void onApply();

        protected:
            bool m_NewItem;
            County m_County;

            QLabel m_lblLanguage;
            QComboBox m_cbLanguage;

            QLabel m_lblName;
            QLineEdit m_edName;

            QPushButton m_btnCancel;
            QPushButton m_btnOK;
            QPushButton m_btnApply;
    };
}

#endif // WNDEDITCOUNTY_H
