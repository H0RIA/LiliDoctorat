#ifndef WNDCONFIG
#define WNDCONFIG

#include "Base.h"

class WndConfig : public QWidget
{
    Q_OBJECT

    public:
        WndConfig(QWidget* parent = nullptr);
        ~WndConfig();

    protected:
        void initializeData();

    protected:
        QTabWidget* m_pTab;
};

#endif // WNDCONFIG

