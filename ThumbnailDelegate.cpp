#include "ThumbnailDelegate.h"

ThumbnailDelegate::ThumbnailDelegate(QWidget *parent)
    :   QStyledItemDelegate(parent)
{
}

void
ThumbnailDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(painter)

    QString path = index.data().toString();
    if(!path.isEmpty()){
        QPixmap pixmap(path);
        int rectSide = qMin(option.rect.width(), option.rect.height());
        QRect ourRect = option.rect;
        ourRect.setWidth(rectSide);
        ourRect.setHeight(rectSide);
        ourRect.moveCenter(option.rect.center());
        pixmap = pixmap.scaled(rectSide, rectSide);
        if(!pixmap.isNull())
            painter->drawPixmap(ourRect, pixmap);
    }
}

QSize
ThumbnailDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return QSize(96, 96);
}

