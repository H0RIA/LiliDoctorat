#include "HouseModel.h"

HouseModel::HouseModel(QObject* parent)
    :   QAbstractTableModel(parent),
        m_pManager(HouseManager::instance())
{
}

HouseModel::~HouseModel(){}

int
HouseModel::rowCount(const QModelIndex &parent)const
{
    Q_UNUSED(parent);

    return m_pManager->getHouseList().count();
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
        house = m_pManager->getHouseList().at(rowIndex);
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
                return house->Name();
                break;
            case HouseModelColumn::Thumbnail:
                if(!house->getImageInfoList().empty()){
                    if(house->getImageInfoList().front() != nullptr){
                        return house->getImageInfoList().front()->Path();
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
