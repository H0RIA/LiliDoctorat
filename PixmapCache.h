#ifndef PIXMAPCACHE
#define PIXMAPCACHE

#include "PixmapCacheItem.h"

class PixmapCache : public QObject
{
    Q_OBJECT

    DECLARE_AS_SINGLETON(PixmapCache)
    DECLARE_SINGLETON_OBJECT(PixmapCacheItem, Pixmaps)

    public:
        bool remPixmapCacheItem(const QString& path, const QSize& size);
        PixmapCacheItem* findPixmapCacheItem(const QString& path, const QSize& size = QSize());
        PixmapCacheItem* createPixmapCacheItem(const QPixmap& pix, const QString& path, const QSize& size = QSize());
        PixmapCacheItem* createPixmapCacheItem(const QString& path, const QSize& size = QSize());
};

#endif // PIXMAPCACHE

