#ifndef WNDEDITHOUSE_TABPRIESTS_H
#define WNDEDITHOUSE_TABPRIESTS_H

#include <QWidget>

namespace UI
{
    class WndEditHouse_TabPriests : public QWidget
    {
        Q_OBJECT

        public:
            explicit WndEditHouse_TabPriests(const QUuid& houseId, bool newItem, QWidget* parent = nullptr);
            ~WndEditHouse_TabPriests();

        signals:

        public slots:
    };
}

#endif // WNDEDITHOUSE_TABPRIESTS_H
