#include "DBWrapper/DBManager.h"
#include "UI/Editors/WndEditTax.h"
#include "WndTaxes.h"

using namespace UI::SideMenu;

WndTaxes::WndTaxes(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndTaxes::~WndTaxes()
{
}

void
WndTaxes::onNewItem()
{
    Editors::WndEditTax newEditor(this);
    newEditor.exec();
    QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
    if(model != nullptr)
        model->select();
}

void
WndTaxes::onDoubleClicked(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    QModelIndex indexId = index.model()->index(index.row(), 0);
    QUuid id = index.model()->data(indexId).toUuid();
    if(!id.isNull()){
        Editors::WndEditTax dialog(id, this);
        dialog.exec();

        QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
        if(model != nullptr)
            model->select();
    }
}

void
WndTaxes::resetModel()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(DBWrapper::TaxInfo::STR_TABLE_NAME);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    if(!model->select()){
        qDebug() << model->lastError().text();
    }else{
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Description"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Formula"));
        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
    }
}

void
WndTaxes::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}
