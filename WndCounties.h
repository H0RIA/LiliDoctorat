#ifndef WNDCOUNTIES
#define WNDCOUNTIES

#include "Base.h"

namespace UI
{
    class WndCounties : public QWidget
    {
        Q_OBJECT

        public:
            WndCounties(QWidget* parent = nullptr);
            ~WndCounties();

        public slots:
            void onNewItem();

        protected:
            void resetModel();
            void initializeData();

        protected:
            QTableView m_View;
    };
}

#endif // WNDCOUNTIES

