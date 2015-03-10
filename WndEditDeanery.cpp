#include "WndEditDeanery.h"

WndEditDeanery::WndEditDeanery(QWidget *parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_Deanery(),
        m_lblNameRO(this),
        m_edNameRO(this),
        m_lblNameDE(this),
        m_edNameDE(this),
        m_lblNameSX(this),
        m_edNameSX(this),
        m_lblNameHU(this),
        m_edNameHU(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    initializeData();
}

WndEditDeanery::WndEditDeanery(const QUuid& countyId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(false),
        m_Deanery(),
        m_lblNameRO(this),
        m_edNameRO(this),
        m_lblNameDE(this),
        m_edNameDE(this),
        m_lblNameSX(this),
        m_edNameSX(this),
        m_lblNameHU(this),
        m_edNameHU(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    m_Deanery.setId(countyId);

    initializeData();
}

WndEditDeanery::~WndEditDeanery()
{

}

void
WndEditDeanery::initializeData()
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

    int labelWidth = 80;
    int editWidth = 180;

    m_lblNameRO.setText(tr("Nume romanesc"));
    m_lblNameDE.setText(tr("Nume german"));
    m_lblNameSX.setText(tr("Nume sasesc"));
    m_lblNameHU.setText(tr("Nume maghiar"));

    m_lblNameRO.setMinimumWidth(labelWidth);
    m_lblNameRO.setMaximumWidth(labelWidth);
    m_lblNameDE.setMinimumWidth(labelWidth);
    m_lblNameDE.setMaximumWidth(labelWidth);
    m_lblNameSX.setMinimumWidth(labelWidth);
    m_lblNameSX.setMaximumWidth(labelWidth);
    m_lblNameHU.setMinimumWidth(labelWidth);
    m_lblNameHU.setMaximumWidth(labelWidth);

    m_edNameRO.setMaximumWidth(editWidth);
    m_edNameRO.setMinimumWidth(editWidth);
    m_edNameDE.setMaximumWidth(editWidth);
    m_edNameDE.setMinimumWidth(editWidth);
    m_edNameSX.setMaximumWidth(editWidth);
    m_edNameSX.setMinimumWidth(editWidth);
    m_edNameHU.setMaximumWidth(editWidth);
    m_edNameHU.setMinimumWidth(editWidth);


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
    mainLayout->addSpacing(10);
    mainLayout->addLayout(btnLayout);
    mainLayout->addSpacing(20);
    mainLayout->addStretch();

    setLayout(mainLayout);

    if(!m_NewItem)
        loadFromDB();
}

bool
WndEditDeanery::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_Deanery.setId(id);

    if(m_Deanery.LoadFromDB()){
        m_edNameRO.setText(m_Deanery.NameRO());
        m_edNameDE.setText(m_Deanery.NameDE());
        m_edNameSX.setText(m_Deanery.NameSX());
        m_edNameHU.setText(m_Deanery.NameHU());

        return true;
    }

    return false;
}

bool
WndEditDeanery::saveToDB()
{
    m_Deanery.setNameRO(m_edNameRO.text());
    m_Deanery.setNameDE(m_edNameDE.text());
    m_Deanery.setNameSX(m_edNameSX.text());
    m_Deanery.setNameHU(m_edNameHU.text());

    return m_Deanery.SaveToDB();
}

bool
WndEditDeanery::eventFilter(QObject* o, QEvent * ev)
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
WndEditDeanery::onCancel()
{
    done(-1);
}

void
WndEditDeanery::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditDeanery::onApply()
{
    saveToDB();
}

bool
WndEditDeanery::onKeyPressed(QKeyEvent* ev)
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
