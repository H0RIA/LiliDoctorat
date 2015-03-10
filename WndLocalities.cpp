#include "WndEditLocality.h"
#include "County.h"
#include "Locality.h"
#include "WndLocalities.h"

using namespace UI;

WndLocalities::WndLocalities(QWidget* parent)
    :   QWidget(parent),
        m_View(this)
{
    initializeData();
}

WndLocalities::~WndLocalities(){}

void
WndLocalities::onNewItem()
{
    WndEditLocality newEditor(this);
    newEditor.exec();
    resetModel();
}

void
WndLocalities::onDoubleClicked(const QModelIndex& index)
{
    if(!index.isValid())
        return;

    QModelIndex indexId = index.model()->index(index.row(), 0);
    QUuid id = index.model()->data(indexId).toUuid();
    if(!id.isNull()){
        WndEditLocality dialog(id, this);
        dialog.exec();

        resetModel();
    }
}

void
WndLocalities::resetModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString strQuery = QString("Select %1.*, %2.NameRO As ComuneRO, %3.NameDE As ComuneDE, %4.NameSX As ComuneSX, %5.NameHU As ComuneHU,\
%6.NameRO As CountyRO, %7.NameDE As CountyDE, %8.NameSX As CountySX, %9.NameHU As CountyHU \
  From %10 Join %11 On %12.IdComune = %13.Id \
Join %14 on %15.IdCounty = %16.Id")
            .arg(Locality::STR_TABLE_NAME)
            .arg(Comune::STR_TABLE_NAME).arg(Comune::STR_TABLE_NAME).arg(Comune::STR_TABLE_NAME).arg(Comune::STR_TABLE_NAME)
            .arg(County::STR_TABLE_NAME).arg(County::STR_TABLE_NAME).arg(County::STR_TABLE_NAME).arg(County::STR_TABLE_NAME)
            .arg(Locality::STR_TABLE_NAME).arg(Comune::STR_TABLE_NAME).arg(Locality::STR_TABLE_NAME).arg(Comune::STR_TABLE_NAME)
            .arg(County::STR_TABLE_NAME).arg(Comune::STR_TABLE_NAME).arg(County::STR_TABLE_NAME);
    QSqlQuery query(strQuery);
    model->setQuery(query);
//    if(!model->select()){
//        qDebug() << model->lastError().text();
//    }else{
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name RO"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Name DE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Name SX"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Name HU"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("ComuneId"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Comune RO"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Comune DE"));
        model->setHeaderData(8, Qt::Horizontal, QObject::tr("Comune SX"));
        model->setHeaderData(9, Qt::Horizontal, QObject::tr("Comune HU"));

        model->setHeaderData(10, Qt::Horizontal, QObject::tr("CountyId"));
        model->setHeaderData(11, Qt::Horizontal, QObject::tr("County RO"));
        model->setHeaderData(12, Qt::Horizontal, QObject::tr("County DE"));
        model->setHeaderData(13, Qt::Horizontal, QObject::tr("County SX"));
        model->setHeaderData(14, Qt::Horizontal, QObject::tr("County HU"));

        m_View.setModel(model);
        m_View.setColumnHidden(0, true);
        m_View.setColumnHidden(5, true);
//    }
}

void
WndLocalities::initializeData()
{
    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 5, 0, 0);
    mainLayout->setSpacing(0);

    resetModel();

    mainLayout->addWidget(&m_View);

    setLayout(mainLayout);

    connect(&m_View, SIGNAL(doubleClicked(QModelIndex)), SLOT(onDoubleClicked(QModelIndex)));
}
