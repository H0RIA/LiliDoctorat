#include "UI/SideMenu/ThumbnailDelegate.h"
#include "WndFilterBase.h"

using namespace UI::Core;

WndFilterBase::WndFilterBase(QWidget *parent)
    :   QDialog(parent)
        ,m_TableName()
        ,m_View(this)
        ,m_SelectedId()
        ,m_ImageColumns()
{
    initializeData();
}

WndFilterBase::WndFilterBase(const QString& table, QWidget *parent)
    :   QDialog(parent)
        ,m_TableName(table)
        ,m_View(this)
        ,m_SelectedId()
        ,m_ImageColumns()
{
    initializeData();
}

WndFilterBase::~WndFilterBase(){}

QUuid
WndFilterBase::getSelectedId()const
{
    return m_SelectedId;
}

void
WndFilterBase::setImageColumn(int index, bool image)
{
    if(!image){
        m_ImageColumns.removeAll(index);
    }else{
        if(!m_ImageColumns.contains(index)){
            m_ImageColumns.append(index);
            m_View.setItemDelegateForColumn(index, new SideMenu::ThumbnailDelegate(this));
        } else{
            return;
        }
    }
}

void
WndFilterBase::setImageColumn(const QString& name, bool image)
{
    QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
    if(model != nullptr)
        setImageColumn(model->fieldIndex(name), image);
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
    m_SelectedId = QUuid(m_View.model()->data(newIndex).toString());

    emit itemSelected(m_SelectedId);

    done(0);
}

void
WndFilterBase::initializeData()
{
    m_View.setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_View.setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

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
                model->setHeaderData(i, Qt::Horizontal, record.fieldName(i));
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

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);
}
