#ifndef WNDEDITLOCALITY_H
#define WNDEDITLOCALITY_H

#include "UI/Core/LineEdit.h"
#include "DBWrapper/Comune.h"
#include "DBWrapper/Locality.h"

namespace UI
{
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

            bool eventFilter(QObject* o, QEvent * ev);

        protected slots:
            void onCancel();
            void onOK();
            void onApply();

            bool onKeyPressed(QKeyEvent* ev);
            void on_edComune_doubleClicked(QMouseEvent* ev);

        protected:
            bool m_NewItem;
            DBWrapper::Locality m_Locality;
            DBWrapper::Comune m_Comune;

            QLabel m_lblNameRO;
            QLineEdit m_edNameRO;

            QLabel m_lblNameDE;
            QLineEdit m_edNameDE;

            QLabel m_lblNameSX;
            QLineEdit m_edNameSX;

            QLabel m_lblNameHU;
            QLineEdit m_edNameHU;

            QLabel m_lblComuneRO;
            Core::LineEdit m_edComuneRO;

            QPushButton m_btnCancel;
            QPushButton m_btnOK;
            QPushButton m_btnApply;
    };
}

#endif // WNDEDITLOCALITY_H
