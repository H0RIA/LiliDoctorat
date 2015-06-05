#ifndef WNDEDITHOUSE_TABTAXES_H
#define WNDEDITHOUSE_TABTAXES_H

#include <QWidget>

namespace UI
{
    class WndEditHouse_TabTaxes : public QWidget
    {
        Q_OBJECT

        public:
            WndEditHouse_TabTaxes(const QUuid& houseId, bool newItem, QWidget* parent = nullptr);
            ~WndEditHouse_TabTaxes();
    };
}

#endif // WNDEDITHOUSE_TABTAXES_H
