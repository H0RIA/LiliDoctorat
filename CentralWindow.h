#ifndef CENTRALWINDOW
#define CENTRALWINDOW

#include "Base.h"
#include "HouseManager.h"

class CentralWindow : public QWidget
{
    Q_OBJECT

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

    public:
        CentralWindow(QWidget* parent = nullptr);
        virtual ~CentralWindow();

    protected slots:
        void onDoubleClicked(const QModelIndex& index);

    protected:
        void initializeData();

    protected:
        QStackedWidget m_WidgetContainer;
        QMap<WindowType, QWidget*> m_Windows;

        QTableView m_View;
        HouseManager* m_pManager;
};

#endif // CENTRALWINDOW

