#ifndef CENTRALWINDOW
#define CENTRALWINDOW

#include "Base.h"
#include "HouseManager.h"

enum class WindowType : int
{
    Houses = 0,
    Priests,
    Languages,
    Counties,
    Deaneries,
    Localities,
    Images,
    Taxes
};

class CentralWindow : public QWidget
{
    Q_OBJECT

    public:
        CentralWindow(QWidget* parent = nullptr);
        virtual ~CentralWindow();

    public slots:
        void onDockSelectWindow(WindowType wndType);


    protected:
        void initializeData();

    protected:
        QStackedWidget m_WidgetContainer;
        QMap<WindowType, QWidget*> m_Windows;

//        QTableView m_View;
        HouseManager* m_pManager;
};

#endif // CENTRALWINDOW

