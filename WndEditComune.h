#ifndef WNDEDITCOMUNE_H
#define WNDEDITCOMUNE_H

#include "LineEdit.h"
#include "County.h"
#include "Comune.h"

class WndEditComune : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditComune(QWidget *parent = 0);
        WndEditComune(const QUuid& comuneId, QWidget* parent = nullptr);
        ~WndEditComune();

    protected:
        void initializeData();

        bool loadFromDB(const QUuid& id = QUuid());
        bool saveToDB();

    signals:

    protected slots:
        void onCancel();
        void onOK();
        void onApply();

        void on_edCounty_doubleClicked(QMouseEvent* ev);

    protected:
        bool m_NewItem;
        Comune m_Comune;
        County m_County;

        QLabel m_lblNameRO;
        QLineEdit m_edNameRO;

        QLabel m_lblNameDE;
        QLineEdit m_edNameDE;

        QLabel m_lblNameSX;
        QLineEdit m_edNameSX;

        QLabel m_lblNameHU;
        QLineEdit m_edNameHU;

        QLabel m_lblCountyRO;
        LineEdit m_edCountyRO;

        QPushButton m_btnCancel;
        QPushButton m_btnOK;
        QPushButton m_btnApply;
};

#endif // WNDEDITCOMUNE_H