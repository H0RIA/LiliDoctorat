#include "UI/Editors/WndEditComune.h"
#include "DBWrapper/Comune.h"
#include "WndComunes.h"

using namespace UI::SideMenu;

WndComunes::WndComunes(QWidget *parent)
    :   QWidget(parent)
{
    initializeData();
}

WndComunes::~WndComunes()
{
}

void
WndComunes::onNewItem()
{
    Editors::WndEditComune newEditor(this);
    newEditor.exec();
    QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
    if(model != nullptr)
        model->select();
}

void
WndComunes::onDoubleClicked(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    QModelIndex indexId = index.model()->index(index.row(), 0);
    QUuid id = index.model()->data(indexId).toUuid();
    if(!id.isNull()){
        Editors::WndEditComune dialog(id, this);
        dialog.exec();

        QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
        if(model != nullptr)
            model->select();
    }
}

void
WndComunes::resetModel()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(DBWrapper::Comune::STR_TABLE_NAME);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    if(!model->select()){
        qDebug() << model->lastError().text();
    }else{
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name RO"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Name DE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Name SX"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Name HU"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("IdCounty"));
        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
        m_View.setColumnHidden(5, true);
    }
}

void
WndComunes::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}
