#include "UI/Core/WndFilterBase.h"
#include "WndEditHouse_TabPriests.h"

using namespace UI::Editors::House;

WndEditHouse_TabPriests::WndEditHouse_TabPriests(DBWrapper::House* pHouse, bool newItem, QWidget* parent)
    :   QWidget(parent)
        ,m_pHouse(pHouse)
        ,m_View(this)
        ,m_lblFirstName(this)
        ,m_edFirstName(this)
        ,m_lblLastName(this)
        ,m_edLastName(this)
        ,m_lblStartDate(this)
        ,m_edStartDate(this)
        ,m_lblEndDate(this)
        ,m_edEndDate(this)
        ,m_btnAdd(this)
{
    initializeData();
}

WndEditHouse_TabPriests::~WndEditHouse_TabPriests(){}

void
WndEditHouse_TabPriests::onAddPriest()
{
    bool result = false;


    QString strInsert = QString("Select Count(*) As EntryExists From HousePriests Where IdHouse = '%1' And IdPriest = '%2'").arg(m_pHouse->Id().toString()).arg(m_Priest.Id().toString());
    QSqlQuery query(strInsert);
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            result = true;
    }

    if(result)
        return;

    strInsert = QString("Insert Into HousePriests (IdHouse, IdPriest) Values ('%1', '%2')").arg(m_pHouse->Id().toString()).arg(m_Priest.Id().toString());
    RunQuery(strInsert, result);

    if(result){
        strInsert = QString("Insert Into HousePriests (IdHouse, IdPriest) Values ('%1', '%2')").arg(m_pHouse->Id().toString()).arg(m_Priest.Id().toString());
    }
}

void
WndEditHouse_TabPriests::onFindPriest(QMouseEvent* ev)
{
    Q_UNUSED(ev)
    Core::WndFilterBase filterPriests(DBWrapper::PriestInfo::STR_TABLE_NAME, this);
    filterPriests.exec();

    QUuid idPriest = filterPriests.getSelectedId();
    updatePriest(idPriest);
}

void
WndEditHouse_TabPriests::updatePriest(const QUuid& id)
{
    m_Priest.setId(id);
    if(m_Priest.LoadFromDB()){
        m_edFirstName.setText(m_Priest.FirstName());
        m_edLastName.setText(m_Priest.LastName());
        m_btnAdd.setEnabled(true);
    }else{
        m_btnAdd.setEnabled(false);
    }
}

void
WndEditHouse_TabPriests::initializeData()
{
    m_btnAdd.setEnabled(false);
    m_lblEndDate.setText(tr("End date"));
    m_lblFirstName.setText(tr("First name"));
    m_lblLastName.setText(tr("Last name"));
    m_lblStartDate.setText(tr("Start date"));
    m_btnAdd.setText(tr("Add priest..."));

    connect(&m_edFirstName, SIGNAL(doubleClick(QMouseEvent*)), SLOT(onFindPriest(QMouseEvent*)));
    connect(&m_edLastName, SIGNAL(doubleClick(QMouseEvent*)), SLOT(onFindPriest(QMouseEvent*)));
    connect(&m_btnAdd, SIGNAL(clicked()), SLOT(onAddPriest()));

    QSqlQueryModel* model = new QSqlQueryModel();
    QString strQuery = QString("Select Priest.Id, Priest.FirstName, Priest.LastName From Priest \
                                Join HousePriests On Priest.Id = HousePriests.IdPriest\
                                Where HousePriests.IdHouse = '%1'").arg(m_pHouse->Id().toString());
    model->setQuery(strQuery);
//    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));

    m_View.setModel(model);
    m_View.setColumnHidden(0, true);

    QHBoxLayout* mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Right Layout

    QVBoxLayout* centralLayout = new QVBoxLayout();
    QGridLayout* dataLayout = new QGridLayout();

    centralLayout->setContentsMargins(0, 0, 0, 0);
    centralLayout->setSpacing(0);
    dataLayout->setContentsMargins(0, 0, 0, 0);
    dataLayout->setSpacing(5);

    int col = 0;
    int row = 0;

    // Add labels
    dataLayout->addWidget(&m_lblFirstName, row, col, 1, 1);row++;
    dataLayout->addWidget(&m_lblLastName, row, col, 1, 1);row++;
    dataLayout->addWidget(&m_lblStartDate, row, col, 1, 1);row++;
    dataLayout->addWidget(&m_lblEndDate, row, col, 1, 1);row++;

    // Add edits
    col = 1;
    row = 0;

    dataLayout->addWidget(&m_edFirstName, row, col, 1, 1);row++;
    dataLayout->addWidget(&m_edLastName, row, col, 1, 1);row++;
    dataLayout->addWidget(&m_edStartDate, row, col, 1, 1);row++;
    dataLayout->addWidget(&m_edEndDate, row, col, 1, 1);row++;

    // Add button
    col = 0;
    row = 5;
    dataLayout->addWidget(&m_btnAdd, row, col, 1, 2, Qt::AlignCenter);row++;

    centralLayout->addSpacing(5);
    centralLayout->addLayout(dataLayout);
    centralLayout->addStretch();

    mainLayout->addWidget(&m_View);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(centralLayout);

    setLayout(mainLayout);
}
