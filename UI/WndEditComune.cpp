#include "WndFilterBase.h"
#include "DBWrapper/County.h"
#include "WndEditComune.h"

using namespace UI;

WndEditComune::WndEditComune(QWidget *parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_Comune(),
        m_lblNameRO(this),
        m_edNameRO(this),
        m_lblNameDE(this),
        m_edNameDE(this),
        m_lblNameSX(this),
        m_edNameSX(this),
        m_lblNameHU(this),
        m_edNameHU(this),
        m_lblCountyRO(this),
        m_edCountyRO(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    initializeData();
}

WndEditComune::WndEditComune(const QUuid& comuneId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(false),
        m_Comune(),
        m_lblNameRO(this),
        m_edNameRO(this),
        m_lblNameDE(this),
        m_edNameDE(this),
        m_lblNameSX(this),
        m_edNameSX(this),
        m_lblNameHU(this),
        m_edNameHU(this),
        m_lblCountyRO(this),
        m_edCountyRO(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    m_Comune.setId(comuneId);

    initializeData();
}

WndEditComune::~WndEditComune(){}

void
WndEditComune::initializeData()
{
    m_edNameRO.installEventFilter(this);
    m_edNameDE.installEventFilter(this);
    m_edNameSX.installEventFilter(this);
    m_edNameHU.installEventFilter(this);

    m_btnCancel.setText(tr("Cancel"));
    m_btnApply.setText(tr("Apply"));
    m_btnOK.setText(tr("OK"));

    connect(&m_btnApply, SIGNAL(clicked()), SLOT(onApply()));
    connect(&m_btnCancel, SIGNAL(clicked()), SLOT(onCancel()));
    connect(&m_btnOK, SIGNAL(clicked()), SLOT(onOK()));
    connect(&m_edCountyRO, SIGNAL(doubleClick(QMouseEvent*)), SLOT(on_edCounty_doubleClicked(QMouseEvent*)));

    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(0);
    btnLayout->setContentsMargins(0, 0, 0, 0);

    btnLayout->addStretch();
    btnLayout->addWidget(&m_btnCancel);
    btnLayout->addSpacing(5);
    btnLayout->addWidget(&m_btnOK);
    btnLayout->addSpacing(5);
    btnLayout->addWidget(&m_btnApply);
    btnLayout->addStretch();

    // TODO

    int labelWidth = 80;
    int editWidth = 180;

    m_lblNameRO.setText(tr("Nume romanesc"));
    m_lblNameDE.setText(tr("Nume german"));
    m_lblNameSX.setText(tr("Nume sasesc"));
    m_lblNameHU.setText(tr("Nume maghiar"));

    m_lblCountyRO.setText(tr("Judet RO"));
    m_edCountyRO.setReadOnly(true);

    m_lblNameRO.setMinimumWidth(labelWidth);
    m_lblNameRO.setMaximumWidth(labelWidth);
    m_lblNameDE.setMinimumWidth(labelWidth);
    m_lblNameDE.setMaximumWidth(labelWidth);
    m_lblNameSX.setMinimumWidth(labelWidth);
    m_lblNameSX.setMaximumWidth(labelWidth);
    m_lblNameHU.setMinimumWidth(labelWidth);
    m_lblNameHU.setMaximumWidth(labelWidth);

    m_lblCountyRO.setMinimumWidth(labelWidth);
    m_lblCountyRO.setMaximumWidth(labelWidth);

    m_edNameRO.setMaximumWidth(editWidth);
    m_edNameRO.setMinimumWidth(editWidth);
    m_edNameDE.setMaximumWidth(editWidth);
    m_edNameDE.setMinimumWidth(editWidth);
    m_edNameSX.setMaximumWidth(editWidth);
    m_edNameSX.setMinimumWidth(editWidth);
    m_edNameHU.setMaximumWidth(editWidth);
    m_edNameHU.setMinimumWidth(editWidth);

    m_edCountyRO.setMaximumWidth(editWidth);
    m_edCountyRO.setMinimumWidth(editWidth);


    QHBoxLayout* layoutNameRO = new QHBoxLayout();
    layoutNameRO->setContentsMargins(0, 0, 0, 0);
    layoutNameRO->setSpacing(0);

    layoutNameRO->addSpacing(20);
    layoutNameRO->addStretch();
    layoutNameRO->addWidget(&m_lblNameRO);
    layoutNameRO->addSpacing(10);
    layoutNameRO->addWidget(&m_edNameRO);
    layoutNameRO->addStretch();
    layoutNameRO->addSpacing(20);

    QHBoxLayout* layoutNameDE = new QHBoxLayout();
    layoutNameDE->setContentsMargins(0, 0, 0, 0);
    layoutNameDE->setSpacing(0);

    layoutNameDE->addSpacing(20);
    layoutNameDE->addStretch();
    layoutNameDE->addWidget(&m_lblNameDE);
    layoutNameDE->addSpacing(10);
    layoutNameDE->addWidget(&m_edNameDE);
    layoutNameDE->addStretch();
    layoutNameDE->addSpacing(20);

    QHBoxLayout* layoutNameSX = new QHBoxLayout();
    layoutNameSX->setContentsMargins(0, 0, 0, 0);
    layoutNameSX->setSpacing(0);

    layoutNameSX->addSpacing(20);
    layoutNameSX->addStretch();
    layoutNameSX->addWidget(&m_lblNameSX);
    layoutNameSX->addSpacing(10);
    layoutNameSX->addWidget(&m_edNameSX);
    layoutNameSX->addStretch();
    layoutNameSX->addSpacing(20);

    QHBoxLayout* layoutNameHU = new QHBoxLayout();
    layoutNameHU->setContentsMargins(0, 0, 0, 0);
    layoutNameHU->setSpacing(0);

    layoutNameHU->addSpacing(20);
    layoutNameHU->addStretch();
    layoutNameHU->addWidget(&m_lblNameHU);
    layoutNameHU->addSpacing(10);
    layoutNameHU->addWidget(&m_edNameHU);
    layoutNameHU->addStretch();
    layoutNameHU->addSpacing(20);

    QHBoxLayout* layoutCountyRO = new QHBoxLayout();
    layoutCountyRO->setContentsMargins(0, 0, 0, 0);
    layoutCountyRO->setSpacing(0);

    layoutCountyRO->addSpacing(20);
    layoutCountyRO->addStretch();
    layoutCountyRO->addWidget(&m_lblCountyRO);
    layoutCountyRO->addSpacing(10);
    layoutCountyRO->addWidget(&m_edCountyRO);
    layoutCountyRO->addStretch();
    layoutCountyRO->addSpacing(20);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addStretch();
    mainLayout->addSpacing(20);
    mainLayout->addLayout(layoutNameRO);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutNameDE);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutNameSX);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutNameHU);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(layoutCountyRO);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(btnLayout);
    mainLayout->addSpacing(20);
    mainLayout->addStretch();

    setLayout(mainLayout);

    if(!m_NewItem)
        loadFromDB();
}

bool
WndEditComune::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_Comune.setId(id);

    if(m_Comune.LoadFromDB()){
        m_edNameRO.setText(m_Comune.NameRO());
        m_edNameDE.setText(m_Comune.NameDE());
        m_edNameSX.setText(m_Comune.NameSX());
        m_edNameHU.setText(m_Comune.NameHU());

        m_County.setId(m_Comune.County());
        if(m_County.LoadFromDB()){
            m_edCountyRO.setText(m_County.NameRO());
        }

        return true;
    }

    return false;
}

bool
WndEditComune::saveToDB()
{
    m_Comune.setNameRO(m_edNameRO.text());
    m_Comune.setNameDE(m_edNameDE.text());
    m_Comune.setNameSX(m_edNameSX.text());
    m_Comune.setNameHU(m_edNameHU.text());
    m_Comune.setCounty(m_County.Id());

    return m_Comune.SaveToDB();
}

bool
WndEditComune::eventFilter(QObject* o, QEvent * ev)
{
    Q_UNUSED(o)

    if(ev->type() == QEvent::KeyPress){
        QKeyEvent* keyEvent = dynamic_cast<QKeyEvent*>(ev);
        if(!onKeyPressed(keyEvent)){
            return false;
        }

        return true;
    }

    return false;
}

void
WndEditComune::onCancel()
{
    done(-1);
}

void
WndEditComune::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditComune::onApply()
{
    saveToDB();
}

bool
WndEditComune::onKeyPressed(QKeyEvent* ev)
{
    if(ev == nullptr)
        return false;

    switch(ev->key())
    {
    case Qt::Key_Enter:
    case Qt::Key_Return:
        onOK();
        break;
    default:
        return false;
    }

    return true;
}

void
WndEditComune::on_edCounty_doubleClicked(QMouseEvent* ev)
{
    Q_UNUSED(ev);

    WndFilterBase filter(DBWrapper::County::STR_TABLE_NAME, this);
    filter.exec();

    QUuid idItem = filter.getSelectedId();
    if(idItem.isNull()){
        m_edCountyRO.clear();
    }else{
        m_County.setId(idItem);
        if(m_County.LoadFromDB()){
            m_edCountyRO.setText(m_County.NameRO());
        }
    }
}
