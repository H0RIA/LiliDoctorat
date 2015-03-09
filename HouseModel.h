#ifndef HOUSEMODEL
#define HOUSEMODEL

#include "HouseManager.h"

enum class HouseModelColumn{
    NameRO = 0,
    NameDE,
    NameSX,
    NameHU,
    Description,
    Id,
    Dating,
    Thumbnail,
    MaxCount
};

class HouseModel : public QAbstractTableModel
{
    Q_OBJECT

    public:
        HouseModel(QObject* parent = nullptr);
        virtual ~HouseModel();

        HouseManager* getHouseManager();
//        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
//        QModelIndex parent(const QModelIndex &child) const override;

        int rowCount(const QModelIndex &parent = QModelIndex()) const override;
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

//        bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
//        QModelIndex sibling(int row, int column, const QModelIndex &idx) const override;
//        bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;

//        bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
//        QMap<int, QVariant> itemData(const QModelIndex &index) const override;
//        bool setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles) override;
//        bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//        bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
//        bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
//        bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
//        bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild) override;
//        bool moveColumns(const QModelIndex &sourceParent, int sourceColumn, int count, const QModelIndex &destinationParent, int destinationChild) override;

//        inline bool insertRow(int row, const QModelIndex &parent = QModelIndex()) override;
//        inline bool insertColumn(int column, const QModelIndex &parent = QModelIndex()) override;
//        inline bool removeRow(int row, const QModelIndex &parent = QModelIndex()) override;
//        inline bool removeColumn(int column, const QModelIndex &parent = QModelIndex()) override;
//        inline bool moveRow(const QModelIndex &sourceParent, int sourceRow, const QModelIndex &destinationParent, int destinationChild) override;
//        inline bool moveColumn(const QModelIndex &sourceParent, int sourceColumn, const QModelIndex &destinationParent, int destinationChild) override;

//        void fetchMore(const QModelIndex &parent) override;
//        bool canFetchMore(const QModelIndex &parent) const override;
//        Qt::ItemFlags flags(const QModelIndex &index) const override;
//        void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;

//        QModelIndex buddy(const QModelIndex &index) const override;
//        QModelIndexList match(const QModelIndex &start, int role, const QVariant &value, int hits = 1,
//                                   Qt::MatchFlags flags = Qt::MatchFlags(Qt::MatchStartsWith|Qt::MatchWrap)) const override;
//        QSize span(const QModelIndex &index) const override;

//        QHash<int,QByteArray> roleNames() const override;

    protected:
        HouseManager* m_pManager;
};

#endif // HOUSEMODEL

