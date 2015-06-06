#ifndef WNDFILTERBASE_H
#define WNDFILTERBASE_H

#include "Base.h"

namespace UI
{
    namespace Core
    {
        class WndFilterBase : public QDialog
        {
            Q_OBJECT

            public:
                explicit WndFilterBase(QWidget *parent = 0);
                explicit WndFilterBase(const QString& table, QWidget *parent = 0);
                ~WndFilterBase();

                QUuid getSelectedId()const;

                void setImageColumn(int index, bool image = true);
                void setImageColumn(const QString& name, bool image = true);

            signals:
                void itemSelected(const QUuid& id);

            public slots:
                void onItemSelected(const QModelIndex& index);

            protected:
                void initializeData();

            protected:
                QString m_TableName;
                QTableView m_View;
                QUuid m_SelectedId;

                QList<int> m_ImageColumns;
        };
    }
}

#endif // WNDFILTERBASE_H
