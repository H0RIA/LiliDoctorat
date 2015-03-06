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

    protected slots:
        void onDoubleClicked(const QModelIndex& index);

    protected:
        QStackedWidget m_WidgetContainer;
        QTableView m_View;
        HouseManager* m_pManager;
};

#endif // CENTRALWINDOW

