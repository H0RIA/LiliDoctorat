#ifndef IMAGEINFO
#define IMAGEINFO

#include "Base.h"

class ImageInfo
{
    DECLARE_PROPERTY(QUuid, Id)
    DECLARE_PROPERTY(QString, Path)
    DECLARE_PROPERTY(QString, Name)
    DECLARE_PROPERTY(QString, Details)

    public:
        ImageInfo();
        ImageInfo(const ImageInfo& ii);
        virtual ~ImageInfo();

        QPixmap* getPixmap();
        const QPixmap* getPixmap()const;

        ImageInfo& operator=(const ImageInfo& ii);
        bool operator==(const ImageInfo& ii)const;
        bool operator!=(const ImageInfo& ii)const;

    protected:
        QPixmap* m_pImage;
};

#endif // IMAGEINFO

