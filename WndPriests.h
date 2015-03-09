#ifndef WNDPRIESTS
#define WNDPRIESTS

#include "Base.h"

namespace UI
{
    class WndPriests : public QWidget
    {
        Q_OBJECT

        public:
            WndPriests(QWidget* parent = nullptr);
            ~WndPriests();

        public slots:
            void onNewItem();

        protected:
            void resetModel();
            void initializeData();

        protected:
            QTableView m_View;
    };
}

#endif // WNDPRIESTS

