#ifndef THUMBNAILDELEGATE
#define THUMBNAILDELEGATE

#include "Base.h"

class ThumbnailDelegate : public QStyledItemDelegate
{
    Q_OBJECT

    public:
        ThumbnailDelegate(QWidget *parent = nullptr);
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    protected:
};

#endif // THUMBNAILDELEGATE

