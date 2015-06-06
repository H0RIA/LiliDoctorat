#ifndef WNDEDITHOUSE_TABTAXES_H
#define WNDEDITHOUSE_TABTAXES_H

#include "DBWrapper/House.h"

namespace UI
{
    namespace Editors
    {
        namespace House
        {
            class WndEditHouse_TabTaxes : public QWidget
            {
                Q_OBJECT

                public:
                    WndEditHouse_TabTaxes(const QUuid& houseId, bool newItem, QWidget* parent = nullptr);
                    ~WndEditHouse_TabTaxes();

                    void houseSaved();

                protected:
                    void initializeData();

                protected:
                    DBWrapper::House* m_pHouse;
                    QTableView m_View;

                    // Right side
                    QPushButton m_btnAddTax;
                    bool m_bNewHouseItem;
                    bool m_bAutoAddPriest;
            };
        }
    }
}

#endif // WNDEDITHOUSE_TABTAXES_H
