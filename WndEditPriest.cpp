#include "WndEditPriest.h"

WndEditPriest::WndEditPriest(QWidget *parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_Priest(),
        m_lblFirstName(this),
        m_edFirstName(this),
        m_lblLastName(this),
        m_edLastName(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    initializeData();
}

WndEditPriest::WndEditPriest(const QUuid& priestId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(false),
        m_Priest(),
        m_lblFirstName(this),
        m_edFirstName(this),
        m_lblLastName(this),
        m_edLastName(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    m_Priest.setId(priestId);

    initializeData();
}

WndEditPriest::~WndEditPriest(){}

void
WndEditPriest::initializeData()
{
    m_edFirstName.installEventFilter(this);
    m_edLastName.installEventFilter(this);

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

    m_lblFirstName.setText(tr("First name"));
    m_lblLastName.setText(tr("Last name"));

    m_lblFirstName.setMinimumWidth(labelWidth);
    m_lblFirstName.setMaximumWidth(labelWidth);
    m_lblLastName.setMinimumWidth(labelWidth);
    m_lblLastName.setMaximumWidth(labelWidth);

    m_edFirstName.setMaximumWidth(editWidth);
    m_edFirstName.setMinimumWidth(editWidth);
    m_edLastName.setMaximumWidth(editWidth);
    m_edLastName.setMinimumWidth(editWidth);

    QHBoxLayout* layoutFirstName = new QHBoxLayout();
    layoutFirstName->setContentsMargins(0, 0, 0, 0);
    layoutFirstName->setSpacing(0);

    layoutFirstName->addSpacing(20);
    layoutFirstName->addStretch();
    layoutFirstName->addWidget(&m_lblFirstName);
    layoutFirstName->addSpacing(10);
    layoutFirstName->addWidget(&m_edFirstName);
    layoutFirstName->addStretch();
    layoutFirstName->addSpacing(20);

    QHBoxLayout* layoutLastName = new QHBoxLayout();
    layoutLastName->setContentsMargins(0, 0, 0, 0);
    layoutLastName->setSpacing(0);

    layoutLastName->addSpacing(20);
    layoutLastName->addStretch();
    layoutLastName->addWidget(&m_lblLastName);
    layoutLastName->addSpacing(10);
    layoutLastName->addWidget(&m_edLastName);
    layoutLastName->addStretch();
    layoutLastName->addSpacing(20);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addStretch();
    mainLayout->addSpacing(20);
    mainLayout->addLayout(layoutFirstName);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutLastName);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(btnLayout);
    mainLayout->addSpacing(20);
    mainLayout->addStretch();

    setLayout(mainLayout);

    loadFromDB(m_Priest.Id());
}

bool
WndEditPriest::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_Priest.setId(id);

    if(m_Priest.LoadFromDB()){
        m_edFirstName.setText(m_Priest.FirstName());
        m_edLastName.setText(m_Priest.LastName());

        return true;
    }

    return false;
}

bool
WndEditPriest::saveToDB()
{
    m_Priest.setFirstName(m_edFirstName.text());
    m_Priest.setLastName(m_edLastName.text());

    return m_Priest.SaveToDB();
}

bool
WndEditPriest::eventFilter(QObject* o, QEvent * ev)
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
WndEditPriest::onCancel()
{
    done(-1);
}

void
WndEditPriest::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditPriest::onApply()
{
    saveToDB();
}

bool
WndEditPriest::onKeyPressed(QKeyEvent* ev)
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
