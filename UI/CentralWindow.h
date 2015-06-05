#ifndef CENTRALWINDOW
#define CENTRALWINDOW

#include "Base.h"
#include "SideMenu/WndComunes.h"
#include "SideMenu/WndCounties.h"
#include "SideMenu/WndDeaneries.h"
#include "SideMenu/WndHouses.h"
#include "SideMenu/WndImages.h"
#include "SideMenu/WndLanguages.h"
#include "SideMenu/WndLocalities.h"
#include "SideMenu/WndPriests.h"
#include "SideMenu/WndTaxes.h"
#include "DBWrapper/HouseManager.h"

namespace UI
{
    enum class WindowType : int
    {
        Houses = 0,
        Priests,
        Languages,
        Comunes,
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
            void onNewItem();

        protected:
            void initializeData();

        protected:
            QStackedWidget m_WidgetContainer;
            QMap<WindowType, QWidget*> m_Windows;

            QList<QShortcut*> m_Shortcuts;
            DBWrapper::HouseManager* m_pManager;
    };

    inline void callOnNewItem(WindowType type, QWidget* widget)
    {
        switch(type)
        {
        case WindowType::Comunes:
            if(qobject_cast<UI::WndComunes*>(widget) != nullptr)
                qobject_cast<UI::WndComunes*>(widget)->onNewItem();
        case WindowType::Counties:
            if(qobject_cast<UI::WndCounties*>(widget) != nullptr)
                qobject_cast<UI::WndCounties*>(widget)->onNewItem();
        case WindowType::Deaneries:
            if(qobject_cast<UI::WndDeaneries*>(widget) != nullptr)
                qobject_cast<UI::WndDeaneries*>(widget)->onNewItem();
        case WindowType::Houses:
            if(qobject_cast<UI::WndHouses*>(widget) != nullptr)
                qobject_cast<UI::WndHouses*>(widget)->onNewItem();
        case WindowType::Images:
            if(qobject_cast<UI::WndImages*>(widget) != nullptr)
                qobject_cast<UI::WndImages*>(widget)->onNewItem();
        case WindowType::Languages:
            if(qobject_cast<UI::WndLanguages*>(widget) != nullptr)
                qobject_cast<UI::WndLanguages*>(widget)->onNewItem();
        case WindowType::Localities:
            if(qobject_cast<UI::WndLocalities*>(widget) != nullptr)
                qobject_cast<UI::WndLocalities*>(widget)->onNewItem();
        case WindowType::Priests:
            if(qobject_cast<UI::WndPriests*>(widget) != nullptr)
                qobject_cast<UI::WndPriests*>(widget)->onNewItem();
        case WindowType::Taxes:
            if(qobject_cast<UI::WndTaxes*>(widget) != nullptr)
                qobject_cast<UI::WndTaxes*>(widget)->onNewItem();
        default:
            return;
        }
    }
}

#endif // CENTRALWINDOW

