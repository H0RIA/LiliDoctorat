#ifndef WNDIMAGES
#define WNDIMAGES

#include "Base.h"

namespace UI
{
    class WndImages : public QWidget
    {
        Q_OBJECT

        public:
            WndImages(QWidget* parent = nullptr);
            ~WndImages();

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

#endif // WNDIMAGES

