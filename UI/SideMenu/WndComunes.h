#ifndef WNDCOMUNES_H
#define WNDCOMUNES_H

#include "Base.h"

namespace UI
{
    namespace SideMenu
    {
        class WndComunes : public QWidget
        {
            Q_OBJECT

            public:
                explicit WndComunes(QWidget *parent = 0);
                ~WndComunes();

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

#endif // WNDCOMUNES_H
