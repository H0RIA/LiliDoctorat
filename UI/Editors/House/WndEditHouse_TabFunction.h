#ifndef WNDHOUSE_TABFUNCTION
#define WNDHOUSE_TABFUNCTION

#include "DBWrapper/HouseFunction.h"
#include "DBWrapper/House.h"
#include "Base.h"

namespace UI
{
    namespace Editors
    {
        namespace House
        {
            class WndEditHouse_TabFunction : public QWidget
            {
                Q_OBJECT

                public:
                    WndEditHouse_TabFunction(DBWrapper::House* pHouse, bool newItem, QWidget* parent = nullptr);

                    bool saveToDB();
                    bool loadFromDB(const QUuid& id);

                protected:
                    void initializeData();

                protected:
                    DBWrapper::HouseFunction m_Function;

                    QLabel m_lblOriginal;
                    QLineEdit m_edOriginal;

                    QLabel m_lblCurrent;
                    QLineEdit m_edCurrent;

                    QLabel m_lblLegalStatus;
                    QComboBox m_cbLegal;
            };
        }
    }
}

#endif // WNDHOUSE_TABFUNCTION

