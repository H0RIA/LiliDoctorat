#ifndef WNDHOUSE_TABFUNCTION
#define WNDHOUSE_TABFUNCTION

#include "HouseFunction.h"
#include "Base.h"

class WndHouse_TabFunction : public QWidget
{
    Q_OBJECT

    public:
        WndHouse_TabFunction(QWidget* parent = nullptr);

        bool saveToDB();
        bool loadFromDB(const QUuid& id);

    protected:
        HouseFunction m_Function;
};

#endif // WNDHOUSE_TABFUNCTION

