#include "DBWrapper/TaxInfo.h"
#include "DBWrapper/DBManager.h"
#include "WndEditTax.h"

using namespace UI::Editors;

WndEditTax::WndEditTax(QWidget* parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_Tax(),
        m_lblName(this),
        m_edName(this),
        m_lblDescription(this),
        m_edDescription(this),
        m_lblFormula(this),
        m_edFormula(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{    
    m_Tax.setId(QUuid::createUuid());

    initializeData();
}

WndEditTax::WndEditTax(const QUuid& taxId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(taxId.isNull() ? true : false),
        m_Tax()
{
    m_Tax.setId(taxId);

    initializeData();
}

WndEditTax::~WndEditTax()
{
}

void
WndEditTax::initializeData()
{
    m_edName.installEventFilter(this);
    m_edDescription.installEventFilter(this);
    m_edFormula.installEventFilter(this);


    if(!m_NewItem)
        loadFromDB();

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

    m_lblName.setText(tr("Name"));
    m_lblDescription.setText(tr("Description"));
    m_lblFormula.setText(tr("Formula"));

    int labelWidth = 60;
    int editWidth = 180;

    m_lblName.setMinimumWidth(labelWidth);
    m_lblName.setMaximumWidth(labelWidth);
    m_lblDescription.setMinimumWidth(labelWidth);
    m_lblDescription.setMaximumWidth(labelWidth);
    m_lblFormula.setMinimumWidth(labelWidth);
    m_lblFormula.setMaximumWidth(labelWidth);

    m_edName.setMaximumWidth(editWidth);
    m_edName.setMinimumWidth(editWidth);
    m_edDescription.setMaximumWidth(editWidth);
    m_edDescription.setMinimumWidth(editWidth);
    m_edFormula.setMaximumWidth(editWidth);
    m_edFormula.setMinimumWidth(editWidth);
    m_edFormula.setMinimumHeight(m_edFormula.font().pixelSize() * 2);
    m_edFormula.setMaximumHeight(50);

    QHBoxLayout* layoutName = new QHBoxLayout();
    layoutName->setContentsMargins(0, 0, 0, 0);
    layoutName->setSpacing(0);

    layoutName->addSpacing(20);
    layoutName->addStretch();
    layoutName->addWidget(&m_lblName);
    layoutName->addSpacing(10);
    layoutName->addWidget(&m_edName);
    layoutName->addStretch();
    layoutName->addSpacing(20);

    QHBoxLayout* layoutDescription = new QHBoxLayout();
    layoutDescription->setContentsMargins(0, 0, 0, 0);
    layoutDescription->setSpacing(0);

    layoutDescription->addSpacing(20);
    layoutDescription->addStretch();
    layoutDescription->addWidget(&m_lblDescription);
    layoutDescription->addSpacing(10);
    layoutDescription->addWidget(&m_edDescription);
    layoutDescription->addStretch();
    layoutDescription->addSpacing(20);

    QHBoxLayout* layoutFormula = new QHBoxLayout();
    layoutFormula->setContentsMargins(0, 0, 0, 0);
    layoutFormula->setSpacing(0);

    layoutFormula->addSpacing(20);
    layoutFormula->addStretch();
    layoutFormula->addWidget(&m_lblFormula);
    layoutFormula->addSpacing(10);
    layoutFormula->addWidget(&m_edFormula);
    layoutFormula->addSpacing(20);
    layoutFormula->addStretch();

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addStretch();
    mainLayout->addSpacing(20);
    mainLayout->addLayout(layoutName);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutDescription);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutFormula);
    mainLayout->addSpacing(40);
    mainLayout->addStretch();
    mainLayout->addLayout(btnLayout);
    mainLayout->addSpacing(10);

    setLayout(mainLayout);
}

bool
WndEditTax::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_Tax.setId(id);

    if(m_Tax.LoadFromDB()){
        m_edName.setText(m_Tax.Name());
        m_edDescription.setText(m_Tax.Description());
        m_edFormula.setText(m_Tax.Formula());

        return true;
    }

    return false;
}

bool
WndEditTax::saveToDB()
{
    m_Tax.setName(m_edName.text());
    m_Tax.setDescription(m_edDescription.text());
    m_Tax.setFormula(m_edFormula.toPlainText());

    return m_Tax.SaveToDB();
}

bool
WndEditTax::eventFilter(QObject* o, QEvent * ev)
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
WndEditTax::onCancel()
{
    done(-1);
}

void
WndEditTax::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditTax::onApply()
{
    saveToDB();
}

bool
WndEditTax::onKeyPressed(QKeyEvent* ev)
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
