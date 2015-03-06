#include "WndFilterBase.h"

struct ColInfo{
    int _index;
    QString _name;
};

WndFilterBase::WndFilterBase(QWidget *parent)
    :   QDialog(parent),
        m_TableName(),
        m_View(this)
{
    initializeData();
}

WndFilterBase::WndFilterBase(const QString& table, QWidget *parent)
    :   QDialog(parent),
        m_TableName(table),
        m_View(this)
{
    initializeData();
}

WndFilterBase::~WndFilterBase()
{
}

void
WndFilterBase::onItemSelected(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    QSqlDriver* driver = QSqlDatabase::database().driver();
    QSqlRecord record = driver->record(m_TableName);

    QString idColumnName = "";
    int idColumnIndex = -1;
    if(!record.isEmpty()){
        for(int i = 0; i < record.count(); i++){
            if(record.fieldName(i).compare("Id") == 0){
                idColumnName = "Id";
                idColumnIndex = i;
                break;
            }
        }
    }

    if(idColumnName.isEmpty())
        return;


    QModelIndex newIndex = m_View.model()->index(index.row(), idColumnIndex);
    QVariant idVar = m_View.model()->data(newIndex);

    emit itemSelected(idVar.toUuid());
}

void
WndFilterBase::initializeData()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(m_TableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!model->select()){
        qDebug() << model->lastError().text();
    }else{
        QSqlDriver* driver = QSqlDatabase::database().driver();
        QSqlRecord record = driver->record(m_TableName);

        if(!record.isEmpty()){
            for(int i = 0; i < record.count(); i++)
                model->setHeaderData(i, Qt::Horizontal, QObject::tr(record.fieldName(i)));
        }

        m_View.setModel(model);

        if(!record.isEmpty()){
            for(int i = 0; i < record.count(); i++){
                if(record.fieldName(i).indexOf("Id") == 0)
                    m_View.setColumnHidden(i, true);
            }

        }
    }

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onItemSelected(QModelIndex)));
}
