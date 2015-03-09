#ifndef WNDEDITDEANERY_H
#define WNDEDITDEANERY_H

#include "Deanery.h"

class WndEditDeanery : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditDeanery(QWidget *parent = 0);
        WndEditDeanery(const QUuid& deaneryId, QWidget* parent = nullptr);
        ~WndEditDeanery();

    protected:
        void initializeData();

        bool loadFromDB(const QUuid& id = QUuid());
        bool saveToDB();

    protected slots:
        void onCancel();
        void onOK();
        void onApply();

    protected:
        bool m_NewItem;
        Deanery m_Deanery;

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

#endif // WNDEDITDEANERY_H
