#include "ImageInfo.h"

using namespace DBWrapper;

QString ImageInfo::STR_CREATE_TABLE = "Create table ImageInfo (\
Id varchar(50) primary key,\
Path varchar(512),\
Name varchar(50),\
Details text)";
QString ImageInfo::STR_TABLE_NAME = "ImageInfo";

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

bool
ImageInfo::CreateTable()
{
    bool result = true;
    RunQuery(ImageInfo::STR_CREATE_TABLE, result);

    return result;
}

bool
ImageInfo::TableExists()
{
    return ::TableExists(ImageInfo::STR_TABLE_NAME);
}

bool
ImageInfo::LoadFromDB()
{
    if(m_Id.isNull())
        return false;

    QString strQuery = QString("Select * From %1 Where Id = '%2'").arg(ImageInfo::STR_TABLE_NAME).arg(m_Id.toString());
    QSqlQuery query(strQuery);
    if(query.next()){
        setPath(query.value("Path").toString());
        setName(query.value("Name").toString());
        setDetails(query.value("Details").toString());

        return true;
    }

    return false;
}

bool
ImageInfo::SaveToDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query;
    QString strQuery;

    if(!ExistsInDB()){
        // We must insert the new data
        strQuery = QString("Insert into %1 (Id, Path, Name, Details) Values('%2', '%3', '%4', '%5')")
                .arg(ImageInfo::STR_TABLE_NAME).arg(m_Id.toString()).arg(Path()).arg(Name()).arg(Details());
    }else{
        // We must update the old data

        strQuery = QString("Update %1 Set Path = '%2', Name = '%3', Details = '%4' Where Id = '%5'")
                .arg(ImageInfo::STR_TABLE_NAME).arg(Path()).arg(Name()).arg(Details()).arg(m_Id.toString());
    }

    if(!query.exec(strQuery)){
        qDebug() << query.lastError().text();
        return false;
    }

    return true;
}

bool
ImageInfo::ExistsInDB()const
{
    if(m_Id.isNull())
        return false;

    QSqlQuery query(QString("Select Count(*) As EntryExists From %1 Where Id = '%2'").arg(ImageInfo::STR_TABLE_NAME).arg(m_Id.toString()));
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            return true;
    }

    return false;
}
