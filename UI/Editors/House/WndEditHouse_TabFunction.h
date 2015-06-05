#ifndef WNDHOUSE_TABFUNCTION
#define WNDHOUSE_TABFUNCTION

#include "DBWrapper/HouseFunction.h"
#include "Base.h"

namespace UI
{
    class WndEditHouse_TabFunction : public QWidget
    {
        Q_OBJECT

        public:
            WndEditHouse_TabFunction(const QUuid& houseId, bool newItem, QWidget* parent = nullptr);

            bool saveToDB();
            bool loadFromDB(const QUuid& id);

        protected:
            DBWrapper::HouseFunction m_Function;
    };
}

#endif // WNDHOUSE_TABFUNCTION

