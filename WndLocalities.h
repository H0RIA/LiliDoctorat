#ifndef WNDLOCALITIES
#define WNDLOCALITIES

#include "Base.h"

namespace UI
{
    class WndLocalities : public QWidget
    {
        Q_OBJECT

        public:
            WndLocalities(QWidget* parent = nullptr);
            ~WndLocalities();

        public slots:
            void onNewItem();

        protected:
    };
}

#endif // WNDLOCALITIES

