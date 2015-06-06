#ifndef WNDEDITHOUSE_TABTAXES_H
#define WNDEDITHOUSE_TABTAXES_H

#include <QWidget>

namespace UI
{
    namespace Editors
    {
        namespace House
        {
            class WndEditHouse_TabTaxes : public QWidget
            {
                Q_OBJECT

                public:
                    WndEditHouse_TabTaxes(const QUuid& houseId, bool newItem, QWidget* parent = nullptr);
                    ~WndEditHouse_TabTaxes();

                    void houseSaved();
            };
        }
    }
}

#endif // WNDEDITHOUSE_TABTAXES_H
