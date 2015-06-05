#ifndef WNDPRIESTS
#define WNDPRIESTS

#include "Base.h"

namespace UI
{
    namespace SideMenu
    {
        class WndPriests : public QWidget
        {
            Q_OBJECT

            public:
                WndPriests(QWidget* parent = nullptr);
                ~WndPriests();

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

#endif // WNDPRIESTS

