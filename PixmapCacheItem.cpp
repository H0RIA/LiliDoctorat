#include "PixmapCacheItem.h"

PixmapCacheItem::PixmapCacheItem()
    :   m_Id(QUuid::createUuid())
        ,m_Pixmap()
        ,m_Path()
        ,m_Size()
{}

PixmapCacheItem::PixmapCacheItem(const PixmapCacheItem& pi)
    :   m_Id(pi.Id())
        ,m_Pixmap(pi.Pixmap())
        ,m_Path(pi.Path())
        ,m_Size(pi.Size())
{}

PixmapCacheItem&
PixmapCacheItem::operator=(const PixmapCacheItem& item)
{
    m_Id = item.Id();
    m_Pixmap = item.Pixmap();
    m_Path = item.Path();
    m_Size = item.Size();

    return *this;
}

bool
PixmapCacheItem::operator!=(const PixmapCacheItem& item)const
{
    if(m_Path == item.Path() && m_Size == item.Size())
        return true;

    return false;
}

bool
PixmapCacheItem::operator==(const PixmapCacheItem& item)const
{
    return !(this->operator !=(item));
}
