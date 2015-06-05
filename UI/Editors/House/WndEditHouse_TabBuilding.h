#ifndef WNDHOUSE_TABBUILDING
#define WNDHOUSE_TABBUILDING

#include "DBWrapper/BuildingInfo.h"

namespace UI
{
    class WndEditHouse_TabBuilding : public QWidget
    {
        Q_OBJECT

        public:
            WndEditHouse_TabBuilding(const QUuid& houseId, bool newItem, QWidget* parent = nullptr);
            ~WndEditHouse_TabBuilding();

        protected:
            void loadFromDB();
            void saveToDB();

            bool eventFilter(QObject* o, QEvent * ev);

            void initializeData();

        protected:
            bool m_NewItem;
            QUuid m_HouseId;
            DBWrapper::BuildingInfo m_Building;

            QLabel m_lblShape;
            QLineEdit m_edShape;
            QLabel m_lblRoomPlacement;
            QLineEdit m_edRoomPlacement;
            QLabel m_lblRoomCount;
            QLineEdit m_edRoomCount;
            QLabel m_lblFrontFloorCount;
            QLineEdit m_edFrontFloorCount;
            QLabel m_lblBackFloorCount;
            QLineEdit m_edBackFloorCount;

            QLabel m_lblFrontBay;
            QLineEdit m_edFrontBay;
            QLabel m_lblSideBay;
            QLineEdit m_edSideBay;
            QLabel m_lblBuildDate;
            QLineEdit m_edBuildDate;
            QLabel m_lblArchitecturalStyle;
            QLineEdit m_edArchitecturalStyle;
            QLabel m_lblDoors;
            QLineEdit m_edDoors;

            QLabel m_lblBasementVault;
            QLineEdit m_edBasementVault;
            QLabel m_lblRoof;
            QLineEdit m_edRoof;
            QLabel m_lblCeiling;
            QLineEdit m_edCeiling;
            QLabel m_lblPinion;
            QLineEdit m_edPinion;
    };
}

#endif // WNDHOUSE_TABBUILDING

