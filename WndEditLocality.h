#ifndef WNDEDITLOCALITY_H
#define WNDEDITLOCALITY_H

#include "LineEdit.h"
#include "Comune.h"
#include "Locality.h"

class WndEditLocality : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditLocality(QWidget *parent = 0);
        WndEditLocality(const QUuid& localityId, QWidget* parent = nullptr);
        ~WndEditLocality();

    protected:
        void initializeData();

        bool loadFromDB(const QUuid& id = QUuid());
        bool saveToDB();

    protected slots:
        void onCancel();
        void onOK();
        void onApply();

        void on_edComune_doubleClicked(QMouseEvent* ev);

    protected:
        bool m_NewItem;
        Locality m_Locality;
        Comune m_Comune;

        QLabel m_lblNameRO;
        QLineEdit m_edNameRO;

        QLabel m_lblNameDE;
        QLineEdit m_edNameDE;

        QLabel m_lblNameSX;
        QLineEdit m_edNameSX;

        QLabel m_lblNameHU;
        QLineEdit m_edNameHU;

        QLabel m_lblComuneRO;
        LineEdit m_edComuneRO;

        QPushButton m_btnCancel;
        QPushButton m_btnOK;
        QPushButton m_btnApply;
};

#endif // WNDEDITLOCALITY_H
