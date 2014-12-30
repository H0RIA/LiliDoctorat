#include "ImageInfo.h"

ImageInfo::ImageInfo()
    :   m_Id(QUuid::createUuid()),
        m_Path(),
        m_Name(),
        m_Details(),
        m_pImage(nullptr)
{}

ImageInfo::ImageInfo(const ImageInfo& ii)
    :   m_Id(ii.Id()),
        m_Path(ii.Path()),
        m_Name(ii.Name()),
        m_Details(ii.Details()),
        m_pImage(nullptr)
{}

ImageInfo::~ImageInfo(){}

QPixmap*
ImageInfo::getPixmap()
{
    if(m_pImage == nullptr){
        if(!m_Path.isEmpty()){
            m_pImage = new QPixmap(m_Path);
            *m_pImage = m_pImage->scaled(QSize(96, 96));
        }
    }

    return m_pImage;
}

const QPixmap*
ImageInfo::getPixmap()const
{
    if(m_pImage == nullptr){
        if(!m_Path.isEmpty()){
            const_cast<QPixmap*>(m_pImage) = new QPixmap(m_Path);
            *(const_cast<QPixmap*>(m_pImage)) = m_pImage->scaled(QSize(96, 96));
        }
    }

    return m_pImage;
}

ImageInfo&
ImageInfo::operator=(const ImageInfo& ii)
{
    m_Id = ii.Id();
    m_Path = ii.Path();
    m_Name = ii.Name();
    m_Details = ii.Details();
    m_pImage = nullptr;

    return *this;
}

bool
ImageInfo::operator==(const ImageInfo& ii)const
{
    if(m_Id == ii.Id())
        return true;

    // TODO: should we check for the other data also? validate name & path & details?

    return false;
}

bool
ImageInfo::operator!=(const ImageInfo& ii)const
{
    return !(this->operator ==(ii));
}
