#ifndef PIXMAPCACHEITEM
#define PIXMAPCACHEITEM

#include "Base.h"

class PixmapCacheItem
{
    DECLARE_PROPERTY_GREF(QUuid, Id)
    DECLARE_PROPERTY_GREF(QPixmap, Pixmap)
    DECLARE_PROPERTY(QString, Path)
    DECLARE_PROPERTY(QSize, Size)

public:
    PixmapCacheItem();
    PixmapCacheItem(const PixmapCacheItem& pi);
    PixmapCacheItem(const PixmapCacheItem&& pi) = delete;

    PixmapCacheItem& operator=(const PixmapCacheItem& item);
    bool operator!=(const PixmapCacheItem& item)const;
    bool operator==(const PixmapCacheItem& item)const;
};

#endif // PIXMAPCACHEITEM

