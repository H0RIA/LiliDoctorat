#ifndef WNDEDITPRIEST_H
#define WNDEDITPRIEST_H

#include "PriestInfo.h"

class WndEditPriest : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditPriest(QWidget *parent = 0);
        WndEditPriest(const QUuid& priestId, QWidget* parent = nullptr);
        ~WndEditPriest();

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
        PriestInfo m_Priest;

        QLabel m_lblFirstName;
        QLineEdit m_edFirstName;

        QLabel m_lblLastName;
        QLineEdit m_edLastName;

        QPushButton m_btnCancel;
        QPushButton m_btnOK;
        QPushButton m_btnApply;
};

#endif // WNDEDITPRIEST_H
