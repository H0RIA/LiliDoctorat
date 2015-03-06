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
    };
}

#endif // WNDCOUNTIES

