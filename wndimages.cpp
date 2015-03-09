#include "WndEditImage.h"
#include "WndImages.h"

using namespace UI;

WndImages::WndImages(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndImages::~WndImages(){}

void
WndImages::onNewItem()
{
    WndEditImage newEditor(this);
    newEditor.exec();
    QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
    if(model != nullptr)
        model->select();
}

void
WndImages::resetModel()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(ImageInfo::STR_TABLE_NAME);
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    if(!model->select()){
        qDebug() << model->lastError().text();
    }else{
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Path"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Name"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Details"));
        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
    }
}

void
WndImages::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);
}
