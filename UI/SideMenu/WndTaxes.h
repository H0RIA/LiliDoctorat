#ifndef WNDTAXES
#define WNDTAXES

#include "Base.h"

namespace UI
{
    namespace SideMenu
    {
        class WndTaxes : public QWidget
        {
            Q_OBJECT

            public:
                WndTaxes(QWidget* parent = nullptr);
                ~WndTaxes();

            public slots:
                void onNewItem();
                void onDoubleClicked(const QModelIndex& index);

            protected:
                void resetModel();
                void initializeData();

            protected:
                QTableView m_View;
        };
    }
}

#endif // WNDTAXES

