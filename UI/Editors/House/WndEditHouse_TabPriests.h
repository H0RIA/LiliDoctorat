#ifndef WNDEDITHOUSE_TABPRIESTS_H
#define WNDEDITHOUSE_TABPRIESTS_H

#include "UI/Core/LineEdit.h"
#include "DBWrapper/House.h"

namespace UI
{
    namespace Editors
    {
        namespace House
        {
            class WndEditHouse_TabPriests : public QWidget
            {
                Q_OBJECT

                public:
                    explicit WndEditHouse_TabPriests(DBWrapper::House* pHouse, bool newItem, QWidget* parent = nullptr);
                    ~WndEditHouse_TabPriests();

                protected slots:
                    void onAddPriest();
                    void onSelectStart(QMouseEvent* ev);
                    void onSelectEnd(QMouseEvent* ev);
                    void onFindPriest(QMouseEvent* ev);

                protected:
                    void resetModel();
                    void updatePriest(const QUuid& id);
                    void initializeData();

                protected:
                    DBWrapper::House* m_pHouse;
                    QTableView m_View;

                    // Right side
                    QLabel m_lblFirstName;
                    Core::LineEdit m_edFirstName;

                    QLabel m_lblLastName;
                    Core::LineEdit m_edLastName;

                    QLabel m_lblStartDate;
                    Core::LineEdit m_edStartDate;

                    QLabel m_lblEndDate;
                    Core::LineEdit m_edEndDate;

                    QPushButton m_btnAdd;
                    DBWrapper::PriestInfo m_Priest;
                    DBWrapper::PriestTenure m_PriestTenure;
            };
        }
    }
}

#endif // WNDEDITHOUSE_TABPRIESTS_H
