#ifndef WNDLANGUAGES
#define WNDLANGUAGES

#include "Base.h"

namespace UI
{
    namespace SideMenu
    {
        class WndLanguages : public QWidget
        {
            Q_OBJECT

            public:
                WndLanguages(QWidget* parent = nullptr);
                ~WndLanguages();

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

#endif // WNDLANGUAGES

