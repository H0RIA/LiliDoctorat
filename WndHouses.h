#ifndef WNDHOUSES
#define WNDHOUSES

#include "Base.h"

namespace UI
{
    class WndHouses : public QWidget
    {
        Q_OBJECT

        public:
            WndHouses(QWidget* parent = nullptr);
            ~WndHouses();

        public slots:
            void onNewItem();

        protected:
            void resetModel();
            void initializeData();

        protected slots:
            void onDoubleClicked(const QModelIndex& index);

        protected:
            QTableView m_View;
    };
}

#endif // WNDHOUSES

