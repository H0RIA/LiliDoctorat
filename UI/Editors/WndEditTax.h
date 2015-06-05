#ifndef WNDEDITTAX_H
#define WNDEDITTAX_H

#include "Base.h"
#include "DBWrapper/TaxInfo.h"

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

            bool eventFilter(QObject* o, QEvent * ev);

        protected slots:
            void onCancel();
            void onOK();
            void onApply();

            bool onKeyPressed(QKeyEvent* ev);

        protected:
            bool m_NewItem;
            DBWrapper::TaxInfo m_Tax;

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
