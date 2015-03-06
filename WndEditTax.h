#ifndef WNDEDITTAX_H
#define WNDEDITTAX_H

#include "Base.h"
#include "TaxInfo.h"

namespace UI
{
    class WndEditTax : public QDialog
    {
        Q_OBJECT

        public:
            WndEditTax(QWidget* parent = nullptr);
            WndEditTax(const QUuid& taxId, QWidget* parent = nullptr);
            ~WndEditTax();

        protected:
            void initializeData();

            bool loadFromDB(const QUuid& id = QUuid());
            bool saveToDB();

        protected:
            bool m_NewItem;
            TaxInfo m_Tax;

            QLabel m_lblName;
            QLineEdit m_edName;

            QLabel m_lblDescription;
            QLineEdit m_edDescription;

            QLabel m_lblFormula;
            QTextEdit m_edFormula;

            QPushButton m_btnCancel;
            QPushButton m_btnOK;
            QPushButton m_btnApply;
    };
}

#endif // WNDEDITTAX_H
