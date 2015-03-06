#ifndef WNDEDITTAX_H
#define WNDEDITTAX_H

#include "Base.h"

namespace UI
{
    class WndEditTax : public QDialog
    {
        Q_OBJECT

        public:
            WndEditTax(QWidget* parent = nullptr);
            WndEditTax(const QUuid& taxId, QWidget* parent = nullptr);
            ~WndEditTax();

        protected:
            void initializeData();

            void loadFromDB(const QUuid& id = QUuid());
            void saveToDB();

        protected:
            bool m_NewItem;
            QUuid m_TaxId;
    };
}

#endif // WNDEDITTAX_H
