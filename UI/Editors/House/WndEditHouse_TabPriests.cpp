#include "UI/Core/WndFilterBase.h"
#include "UI/Core/DateDialog.h"
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
        ,m_bNewHouseItem(newItem)
        ,m_bAutoAddPriest(false)
{
    initializeData();
}

WndEditHouse_TabPriests::~WndEditHouse_TabPriests(){}

void
WndEditHouse_TabPriests::houseSaved()
{
    m_bNewHouseItem = false;

    if(m_bAutoAddPriest){
        m_bAutoAddPriest = false;
        onAddPriest();
    }
}

void
WndEditHouse_TabPriests::onAddPriest()
{
    bool result = false;

    if(m_bNewHouseItem){
        QMessageBox msg;
        msg.setWindowTitle(tr("Info"));
        msg.setText(tr("You must first save the house info!\nContinue?"));
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int result = msg.exec();

        if(result == QMessageBox::Yes){
            m_bAutoAddPriest = true;
            emit saveHouse();
        }else{
            return;
        }
    }

    QString strInsert = QString("Select Count(*) As EntryExists From %1 Where IdHouse = '%2' And IdPriest = '%3' And StartDate = %4 And EndDate = %5")
            .arg(DBWrapper::PriestTenure::STR_TABLE_NAME).arg(m_PriestTenure.HouseId().toString()).arg(m_PriestTenure.PriestId().toString())
            .arg(m_PriestTenure.Start().toJulianDay()).arg(m_PriestTenure.End().toJulianDay());
    QSqlQuery query(strInsert);
    while(query.next()){
        int size = query.value("EntryExists").toInt();
        if(size == 1)
            result = true;
    }

    if(result)
        return;

    m_PriestTenure.SaveToDB();
    resetModel();

    m_Priest = DBWrapper::PriestInfo();
    m_PriestTenure = DBWrapper::PriestTenure();
    m_PriestTenure.setId(m_pHouse->Id());
    m_btnAdd.setEnabled(false);

    m_edEndDate.setText(QString());
    m_edStartDate.setText(QString());
    m_edFirstName.setText(QString());
    m_edLastName.setText(QString());
}

void
WndEditHouse_TabPriests::onSelectStart(QMouseEvent* ev)
{
    Q_UNUSED(ev)

    UI::Core::DateDialog dlgDate(this);

    int result = dlgDate.exec();
    if(result == QDialog::Accepted){
        QDate startDate = dlgDate.selectedDate();
        m_edStartDate.setText(startDate.toString());
        m_PriestTenure.setStart(startDate);
    }
}

void
WndEditHouse_TabPriests::onSelectEnd(QMouseEvent* ev)
{
    Q_UNUSED(ev)

    UI::Core::DateDialog dlgDate(this);

    int result = dlgDate.exec();
    if(result == QDialog::Accepted){
        QDate endDate = dlgDate.selectedDate();
        m_edEndDate.setText(endDate.toString());
        m_PriestTenure.setEnd(endDate);
    }
}

void
WndEditHouse_TabPriests::onFindPriest(QMouseEvent* ev)
{
    Q_UNUSED(ev)

    Core::WndFilterBase filterPriests(DBWrapper::PriestInfo::STR_TABLE_NAME, this);
    filterPriests.exec();

    QUuid idPriest = filterPriests.getSelectedId();
    m_PriestTenure.setPriestId(idPriest);
    updatePriest(idPriest);
}

void
WndEditHouse_TabPriests::resetModel()
{
    QAbstractItemModel* oldModel = m_View.model();
    if(oldModel != nullptr)
        oldModel->deleteLater();

    QSqlQueryModel* model = new QSqlQueryModel();
    QString strQuery = QString("Select Priest.Id, Priest.FirstName, Priest.LastName, date(julianday(HousePriests.StartDate)) As  Start, date(julianday(HousePriests.EndDate)) As End \
                                From Priest \
                                Join HousePriests On Priest.Id = HousePriests.IdPriest\
                                Where HousePriests.IdHouse = '%1'").arg(m_pHouse->Id().toString());
    model->setQuery(strQuery);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last name"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Start date"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("End date"));

    m_View.setModel(model);
    m_View.setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_View.setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_View.setColumnHidden(0, true);
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
    if(m_pHouse == nullptr)
        return;

    m_edEndDate.setReadOnly(true);
    m_edFirstName.setReadOnly(true);
    m_edLastName.setReadOnly(true);
    m_edStartDate.setReadOnly(true);

    m_btnAdd.setEnabled(false);
    m_lblEndDate.setText(tr("End date"));
    m_lblFirstName.setText(tr("First name"));
    m_lblLastName.setText(tr("Last name"));
    m_lblStartDate.setText(tr("Start date"));
    m_btnAdd.setText(tr("Add priest..."));

    m_PriestTenure.setHouseId(m_pHouse->Id());

    connect(&m_edFirstName, SIGNAL(doubleClick(QMouseEvent*)), SLOT(onFindPriest(QMouseEvent*)));
    connect(&m_edLastName, SIGNAL(doubleClick(QMouseEvent*)), SLOT(onFindPriest(QMouseEvent*)));
    connect(&m_edStartDate, SIGNAL(doubleClick(QMouseEvent*)), SLOT(onSelectStart(QMouseEvent*)));
    connect(&m_edEndDate, SIGNAL(doubleClick(QMouseEvent*)), SLOT(onSelectEnd(QMouseEvent*)));
    connect(&m_btnAdd, SIGNAL(clicked()), SLOT(onAddPriest()));

    resetModel();

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
