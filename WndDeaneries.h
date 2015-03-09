#ifndef WNDDEANERIES
#define WNDDEANERIES

#include "Base.h"

namespace UI
{
    class WndDeaneries : public QWidget
    {
        Q_OBJECT

        public:
            WndDeaneries(QWidget* parent = nullptr);
            ~WndDeaneries();

        public slots:
            void onNewItem();

        protected:
            void resetModel();
            void initializeData();

        protected:
            QTableView m_View;
    };
}


#endif // WNDDEANERIES

