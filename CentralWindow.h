#ifndef CENTRALWINDOW
#define CENTRALWINDOW

#include "Base.h"
#include "HouseManager.h"

class CentralWindow : public QWidget
{
    Q_OBJECT

    public:
        CentralWindow(QWidget* parent = nullptr);
        virtual ~CentralWindow();

    protected:
        QTableView m_View;
        HouseManager* m_pManager;
};

#endif // CENTRALWINDOW

