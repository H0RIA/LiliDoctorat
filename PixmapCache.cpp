#include "PixmapCache.h"

IMPLEMENT_SINGLETON(PixmapCache)

PixmapCache::PixmapCache()
    :   m_Pixmaps()
{}

PixmapCache::~PixmapCache()
{
    clearPixmaps();
}

bool
PixmapCache::remPixmapCacheItem(const QString& path, const QSize& size)
{
    if(path.isEmpty())
        return false;

    bool found = false;
    foreach(PixmapCacheItem* currentItem, m_Pixmaps){
        if(currentItem != nullptr){
            if(currentItem->Path() == path && currentItem->Size() == size){
                m_Pixmaps.removeAll(currentItem);
                delete currentItem;
                found = true;
                break;
            }
        }
    }

    return found;
}

PixmapCacheItem*
PixmapCache::findPixmapCacheItem(const QString& path, const QSize& size)
{
    PixmapCacheItem* item = nullptr;

    foreach(PixmapCacheItem* currentItem, m_Pixmaps){
        if(currentItem != nullptr){
            if(currentItem->Path() == path && currentItem->Size() == size){
                item = currentItem;
                break;
            }
        }
    }

    return item;
}

PixmapCacheItem*
PixmapCache::createPixmapCacheItem(const QPixmap& pix, const QString& path, const QSize& size)
{
    PixmapCacheItem* item = findPixmapCacheItem(path, size);

    if(item == nullptr){
        item = new PixmapCacheItem();
        item->setPath(path);
        item->setPixmap(pix);
        item->setSize(size);
        m_Pixmaps.append(item);
    }

    return item;
}
