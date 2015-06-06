#include "PixmapCache.h"
#include "ThumbnailDelegate.h"

using namespace UI::SideMenu;

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
        QFileInfo fi(path);
        if(!fi.isFile() || !fi.exists())
            return;

        int rectSide = qMin(option.rect.width(), option.rect.height());
        QRect ourRect = option.rect;
        ourRect.setWidth(rectSide);
        ourRect.setHeight(rectSide);
        ourRect.moveCenter(option.rect.center());
        PixmapCacheItem* cacheItem = PixmapCache::instance()->findPixmapCacheItem(path, ourRect.size());
        QPixmap pixmap;
        if(cacheItem != nullptr)
            pixmap = cacheItem->Pixmap();

        if(!pixmap.isNull()){
            painter->drawPixmap(ourRect, pixmap);
        }else{
            pixmap = QPixmap(path);
            pixmap = pixmap.scaled(rectSide, rectSide);
            if(!pixmap.isNull()){
                painter->drawPixmap(ourRect, pixmap);
                PixmapCache::instance()->createPixmapCacheItem(pixmap, path, ourRect.size());
            }
        }
    }
}

QSize
ThumbnailDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    return QSize(96, 96);
}
