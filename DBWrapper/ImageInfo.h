#ifndef IMAGEINFO
#define IMAGEINFO

#include "Base.h"

namespace DBWrapper
{
    class ImageInfo
    {
        DECLARE_PROPERTY(QUuid, Id)
        DECLARE_PROPERTY(QString, Path)
        DECLARE_PROPERTY(QString, Name)
        DECLARE_PROPERTY(QString, Details)

        public:
            static QString STR_CREATE_TABLE;
            static QString STR_TABLE_NAME;

        public:
            ImageInfo();
            ImageInfo(const ImageInfo& ii);
            virtual ~ImageInfo();

            QPixmap* getPixmap();
            const QPixmap* getPixmap()const;

            ImageInfo& operator=(const ImageInfo& ii);
            bool operator==(const ImageInfo& ii)const;
            bool operator!=(const ImageInfo& ii)const;

            static bool CreateTable();
            static bool TableExists();
            bool LoadFromDB();
            bool SaveToDB()const;
            bool ExistsInDB()const;

        protected:
            QPixmap* m_pImage;
    };
}

#endif // IMAGEINFO

