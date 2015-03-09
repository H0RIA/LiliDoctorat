#include "WndEditPriest.h"
#include "WndPriests.h"

using namespace UI;

WndPriests::WndPriests(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndPriests::~WndPriests(){}

void
WndPriests::onNewItem()
{
    WndEditPriest newEditor(this);
    newEditor.exec();
    QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
    if(model != nullptr)
        model->select();
}

void
WndPriests::resetModel()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(PriestInfo::STR_TABLE_NAME);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    if(!model->select()){
        qDebug() << model->lastError().text();
    }else{
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
    }
}

void
WndPriests::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);
}
