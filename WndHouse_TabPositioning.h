#ifndef WNDHOUSE_TABPOSITIONING
#define WNDHOUSE_TABPOSITIONING

#include "HousePositioning.h"

class WndHouse_TabPositioning : public QWidget
{
    Q_OBJECT

    public:
        WndHouse_TabPositioning(QWidget* parent = nullptr, const QUuid& idPositioning = QUuid());

        bool saveToDB();
        bool loadFromDB(const QUuid& idPositioning);

    protected:
        QLabel m_lblFromChurch;
        QTextEdit m_edFromChurch;

        QLabel m_lblFromStreet;
        QTextEdit m_edFromStreet;

        QLabel m_lblFromGarden;
        QTextEdit m_edFromGarden;

        QLabel m_lblDeclivity;
        QTextEdit m_edDeclivity;

        HousePositioning m_Positioning;
};

#endif // WNDHOUSE_TABPOSITIONING

