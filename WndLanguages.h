#ifndef WNDLANGUAGES
#define WNDLANGUAGES

#include "Base.h"

namespace UI
{
    class WndLanguages : public QWidget
    {
        Q_OBJECT

        public:
            WndLanguages(QWidget* parent = nullptr);
            ~WndLanguages();

        public slots:
            void onNewItem();

        protected:
    };
}

#endif // WNDLANGUAGES

