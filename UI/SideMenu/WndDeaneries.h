#ifndef WNDDEANERIES
#define WNDDEANERIES

#include "Base.h"

namespace UI
{
    namespace SideMenu
    {
        class WndDeaneries : public QWidget
        {
            Q_OBJECT

            public:
                WndDeaneries(QWidget* parent = nullptr);
                ~WndDeaneries();

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


#endif // WNDDEANERIES

