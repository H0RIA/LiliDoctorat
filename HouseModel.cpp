#include "Language.h"
#include "HouseModel.h"

HouseModel::HouseModel(QObject* parent)
    :   QAbstractTableModel(parent),
        m_pManager(HouseManager::instance())
{
}

HouseModel::~HouseModel(){}

HouseManager*
HouseModel::getHouseManager()
{
    return m_pManager;
}

int
HouseModel::rowCount(const QModelIndex &parent)const
{
    Q_UNUSED(parent);

    return m_pManager->getHouses().count();
}

int
HouseModel::columnCount(const QModelIndex &parent)const
{
    Q_UNUSED(parent);

    return (int)HouseModelColumn::MaxCount;
}

QVariant
HouseModel::data(const QModelIndex &index, int role)const
{
    int rowIndex = index.row();
    int colIndex = index.column();

    House* house = nullptr;

    switch(role){
    case Qt::DisplayRole:
        house = m_pManager->getHouses().at(rowIndex);
        if(house != nullptr){
            switch(colIndex){
            case HouseModelColumn::Dating:
                return house->HouseDating();
                break;
            case HouseModelColumn::Description:
                return house->Description();
                break;
            case HouseModelColumn::Id:
                return house->Id();
                break;
            case HouseModelColumn::Name:
                return house->Name()[Language::LANGUAGE_GERMAN];
                break;
            case HouseModelColumn::Thumbnail:
                if(!house->getImages().empty()){
                    if(house->getImages().front() != nullptr){
                        return house->getImages().front()->Path();
//                        if(house->getImageInfoList().front()->getPixmap() != nullptr){
//                            return (qptrdiff)house->getImageInfoList().front()->getPixmap();
//                        }
                    }
                }
                break;
            }
        }
        break;
    }

    return QVariant();
}

QVariant
HouseModel::headerData(int section, Qt::Orientation orientation, int role)const
{
    Q_UNUSED(orientation);

    switch(role){
    case Qt::DisplayRole:
        switch(section){
        case HouseModelColumn::Dating:
            return QObject::tr("Dating");
            break;
        case HouseModelColumn::Description:
            return QObject::tr("Description");
            break;
        case HouseModelColumn::Id:
            return QObject::tr("Id");
            break;
        case HouseModelColumn::Name:
            return QObject::tr("Name");
            break;
        case HouseModelColumn::Thumbnail:
            return QObject::tr("Thumbnail");
            break;
        }

        break;
    }

    return QVariant();
}
