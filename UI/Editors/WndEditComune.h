#ifndef WNDEDITCOMUNE_H
#define WNDEDITCOMUNE_H

#include "UI/Core/LineEdit.h"
#include "DBWrapper/County.h"
#include "DBWrapper/Comune.h"

namespace UI
{
    namespace Editors
    {
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

                bool eventFilter(QObject* o, QEvent * ev);

            protected slots:
                void onCancel();
                void onOK();
                void onApply();

                bool onKeyPressed(QKeyEvent* ev);
                void on_edCounty_doubleClicked(QMouseEvent* ev);

            protected:
                bool m_NewItem;
                DBWrapper::Comune m_Comune;
                DBWrapper::County m_County;

                QLabel m_lblNameRO;
                QLineEdit m_edNameRO;

                QLabel m_lblNameDE;
                QLineEdit m_edNameDE;

                QLabel m_lblNameSX;
                QLineEdit m_edNameSX;

                QLabel m_lblNameHU;
                QLineEdit m_edNameHU;

                QLabel m_lblCountyRO;
                Core::LineEdit m_edCountyRO;

                QPushButton m_btnCancel;
                QPushButton m_btnOK;
                QPushButton m_btnApply;
        };
    }
}

#endif // WNDEDITCOMUNE_H
