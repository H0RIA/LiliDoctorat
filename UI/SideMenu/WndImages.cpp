#include "UI/SideMenu/ThumbnailDelegate.h"
#include "UI/Editors/WndEditImage.h"
#include "WndImages.h"

using namespace UI::SideMenu;

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
    Editors::WndEditImage newEditor(this);
    newEditor.exec();
    QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
    if(model != nullptr)
        model->select();
}

void
WndImages::onDoubleClicked(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    QModelIndex indexId = index.model()->index(index.row(), 0);
    QUuid id = index.model()->data(indexId).toUuid();
    if(!id.isNull()){
        Editors::WndEditImage dialog(id, this);
        dialog.exec();

        QSqlTableModel* model = qobject_cast<QSqlTableModel*>(m_View.model());
        if(model != nullptr)
            model->select();
    }
}

void
WndImages::resetModel()
{
    QSqlTableModel* model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable(DBWrapper::ImageInfo::STR_TABLE_NAME);
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

        m_View.setItemDelegateForColumn(1, new SideMenu::ThumbnailDelegate(this));
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

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}
