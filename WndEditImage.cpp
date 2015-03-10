#include "WndEditImage.h"

WndEditImage::WndEditImage(QWidget *parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_Image(),
        m_lblName(this),
        m_edName(this),
        m_lblPath(this),
        m_edPath(this),
        m_btnBrowse(this),
        m_lblDetails(this),
        m_edDetails(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    initializeData();
}

WndEditImage::WndEditImage(const QUuid& imageId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(false),
        m_Image(),
        m_lblName(this),
        m_edName(this),
        m_lblPath(this),
        m_edPath(this),
        m_btnBrowse(this),
        m_lblDetails(this),
        m_edDetails(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this)
{
    m_Image.setId(imageId);

    initializeData();
}

WndEditImage::~WndEditImage(){}

ImageInfo
WndEditImage::getImage()const
{
    return m_Image;
}

void
WndEditImage::initializeData()
{
    m_btnCancel.setText(tr("Cancel"));
    m_btnApply.setText(tr("Apply"));
    m_btnOK.setText(tr("OK"));
    m_btnBrowse.setText(tr("Browse..."));

    m_edPath.setReadOnly(true);

    connect(&m_btnApply, SIGNAL(clicked()), SLOT(onApply()));
    connect(&m_btnCancel, SIGNAL(clicked()), SLOT(onCancel()));
    connect(&m_btnOK, SIGNAL(clicked()), SLOT(onOK()));
    connect(&m_btnBrowse, SIGNAL(clicked()), SLOT(onBrowseClicked()));

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
    int browseWidth = 60;

    m_lblName.setMinimumWidth(labelWidth);
    m_lblName.setMaximumWidth(labelWidth);
    m_lblPath.setMinimumWidth(labelWidth);
    m_lblPath.setMaximumWidth(labelWidth);
    m_lblDetails.setMinimumWidth(labelWidth);
    m_lblDetails.setMaximumWidth(labelWidth);

    m_lblName.setText(tr("Name"));
    m_lblPath.setText(tr("Path"));
    m_lblDetails.setText(tr("Details"));

    m_edName.setMaximumWidth(editWidth);
    m_edName.setMinimumWidth(editWidth);
    m_edPath.setMaximumWidth(editWidth);
    m_edPath.setMinimumWidth(editWidth);
    m_edDetails.setMaximumWidth(editWidth);
    m_edDetails.setMinimumWidth(editWidth);

    m_edDetails.setMinimumHeight(m_edDetails.font().pixelSize() * 2);
    m_edDetails.setMaximumHeight(50);

    m_btnBrowse.setMaximumWidth(60);
    m_btnBrowse.setMinimumWidth(60);

    QHBoxLayout* layoutName = new QHBoxLayout();
    layoutName->setContentsMargins(0, 0, 0, 0);
    layoutName->setSpacing(0);

    layoutName->addSpacing(20);
    layoutName->addStretch();
    layoutName->addWidget(&m_lblName);
    layoutName->addSpacing(10);
    layoutName->addWidget(&m_edName);
    layoutName->addSpacing(10 + browseWidth);
    layoutName->addStretch();
    layoutName->addSpacing(20);

    QHBoxLayout* layoutPath = new QHBoxLayout();
    layoutPath->setContentsMargins(0, 0, 0, 0);
    layoutPath->setSpacing(0);

    layoutPath->addSpacing(20);
    layoutPath->addStretch();
    layoutPath->addWidget(&m_lblPath);
    layoutPath->addSpacing(10);
    layoutPath->addWidget(&m_edPath);
    layoutPath->addSpacing(10);
    layoutPath->addWidget(&m_btnBrowse);
    layoutPath->addStretch();
    layoutPath->addSpacing(20);

    QHBoxLayout* layoutDetails = new QHBoxLayout();
    layoutDetails->setContentsMargins(0, 0, 0, 0);
    layoutDetails->setSpacing(0);

    layoutDetails->addSpacing(20);
    layoutDetails->addStretch();
    layoutDetails->addWidget(&m_lblDetails);
    layoutDetails->addSpacing(10);
    layoutDetails->addWidget(&m_edDetails);
    layoutDetails->addSpacing(10 + browseWidth);
    layoutDetails->addStretch();
    layoutDetails->addSpacing(20);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    mainLayout->addStretch();
    mainLayout->addSpacing(20);
    mainLayout->addLayout(layoutName);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutPath);
    mainLayout->addSpacing(10);
    mainLayout->addLayout(layoutDetails);
    mainLayout->addSpacing(40);
    mainLayout->addStretch();
    mainLayout->addLayout(btnLayout);
    mainLayout->addSpacing(10);

    setLayout(mainLayout);
}

bool
WndEditImage::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_Image.setId(id);

    if(m_Image.LoadFromDB()){
        m_edName.setText(m_Image.Name());
        m_edPath.setText(m_Image.Path());
        m_edDetails.setText(m_Image.Details());

        return true;
    }

    return false;
}

bool
WndEditImage::saveToDB()
{
    m_Image.setName(m_edName.text());
    m_Image.setPath(m_edPath.text());
    m_Image.setDetails(m_edDetails.toPlainText());

    return m_Image.SaveToDB();
}

void
WndEditImage::onCancel()
{
    done(-1);
}

void
WndEditImage::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditImage::onApply()
{
    saveToDB();
}

void
WndEditImage::onBrowseClicked()
{
    m_Image.setPath(QFileDialog::getOpenFileName(this, tr("Find image..."), "", tr("Image Files (*.png *.jpg *.bmp *.jpeg)")));
    QFileInfo fi(m_Image.Path());
    QString suffix = fi.suffix();
    m_edName.setText(fi.fileName().remove(fi.fileName().length() - suffix.length() - 1, suffix.length() + 1));
    m_edPath.setText(m_Image.Path());
}
