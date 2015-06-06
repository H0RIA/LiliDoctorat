#include "DBWrapper/Locality.h"
#include "DBWrapper/Language.h"
#include "UI/Editors/WndEditImage.h"
#include "UI/Core/WndFilterBase.h"
#include "WndEditHouse.h"
#include "WndEditHouse_TabBuilding.h"
#include "WndEditHouse_TabFunction.h"
#include "WndEditHouse_TabPriests.h"
#include "WndEditHouse_TabTaxes.h"
#include "WndEditHouse_TabPositioning.h"

using namespace UI;
using namespace UI::Editors::House;

WndEditHouse::WndEditHouse(QWidget *parent)
    :   QDialog(parent),
        m_NewItem(true),
        m_House(),
        m_Locality(),
        m_lblNumeRomanesc(this),
        m_edNumeRomanesc(this),
        m_lblNumeGerman(this),
        m_edNumeGerman(this),
        m_lblNumeSasesc(this),
        m_edNumeSasesc(this),
        m_lblNumeMaghiar(this),
        m_edNumeMaghiar(this),
        m_lblOldStatus(this),
        m_edOldStatus(this),
        m_lblLocality(this),
        m_edLocality(this),
        m_lblComune(this),
        m_edComune(this),
        m_lblCounty(this),
        m_edCounty(this),
        m_lblDate(this),
        m_edDate(this),
        m_Image(this),
        m_btnImgPrev(this),
        m_btnImgNext(this),
        m_btnImgAddFromDB(this),
        m_btnImgAddNew(this),
        m_btnImgRem(this),
        m_Tab(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this),
        m_CurrentImageId()
{
    initializeData();
}

WndEditHouse::WndEditHouse(const QUuid& houseId, QWidget* parent)
    :   QDialog(parent),
        m_NewItem(false),
        m_House(),
        m_Locality(),
        m_lblNumeRomanesc(this),
        m_edNumeRomanesc(this),
        m_lblNumeGerman(this),
        m_edNumeGerman(this),
        m_lblNumeSasesc(this),
        m_edNumeSasesc(this),
        m_lblNumeMaghiar(this),
        m_edNumeMaghiar(this),
        m_lblOldStatus(this),
        m_edOldStatus(this),
        m_lblLocality(this),
        m_edLocality(this),
        m_lblComune(this),
        m_edComune(this),
        m_lblCounty(this),
        m_edCounty(this),
        m_lblDate(this),
        m_edDate(this),
        m_Image(this),
        m_btnImgPrev(this),
        m_btnImgNext(this),
        m_btnImgAddFromDB(this),
        m_btnImgAddNew(this),
        m_btnImgRem(this),
        m_Tab(this),
        m_btnCancel(this),
        m_btnOK(this),
        m_btnApply(this),
        m_CurrentImageId()
{
    m_House.setId(houseId);

    initializeData();
}

WndEditHouse::~WndEditHouse()
{
}

void
WndEditHouse::initializeData()
{
    m_edNumeRomanesc.installEventFilter(this);
    m_edNumeGerman.installEventFilter(this);
    m_edNumeSasesc.installEventFilter(this);
    m_edNumeMaghiar.installEventFilter(this);
    m_edOldStatus.installEventFilter(this);
    m_edDate.installEventFilter(this);

    int labelWidth = 80;
    int editWidth = 150;

    loadFromDB(m_House.Id());

    m_lblComune.setText(tr("Comuna"));
    m_lblCounty.setText(tr("Judet"));
    m_lblDate.setText(tr("Datare"));
    m_lblLocality.setText(tr("Localitate"));
    m_lblNumeGerman.setText(tr("Nume german"));
    m_lblNumeMaghiar.setText(tr("Nume maghiar"));
    m_lblNumeRomanesc.setText(tr("Nume romanesc"));
    m_lblNumeSasesc.setText(tr("Nume sasesc"));
    m_lblOldStatus.setText(tr("Statut vechi"));

    m_lblComune.setAlignment(Qt::AlignRight);
    m_lblCounty.setAlignment(Qt::AlignRight);
    m_lblDate.setAlignment(Qt::AlignRight);
    m_lblLocality.setAlignment(Qt::AlignRight);
    m_lblNumeGerman.setAlignment(Qt::AlignRight);
    m_lblNumeMaghiar.setAlignment(Qt::AlignRight);
    m_lblNumeRomanesc.setAlignment(Qt::AlignRight);
    m_lblNumeSasesc.setAlignment(Qt::AlignRight);
    m_lblOldStatus.setAlignment(Qt::AlignRight);

    m_lblComune.setMinimumWidth(labelWidth);
    m_lblComune.setMaximumWidth(labelWidth);
    m_lblCounty.setMinimumWidth(labelWidth);
    m_lblCounty.setMaximumWidth(labelWidth);
    m_lblDate.setMinimumWidth(labelWidth);
    m_lblDate.setMaximumWidth(labelWidth);
    m_lblLocality.setMinimumWidth(labelWidth);
    m_lblLocality.setMaximumWidth(labelWidth);
    m_lblNumeGerman.setMinimumWidth(labelWidth);
    m_lblNumeGerman.setMaximumWidth(labelWidth);
    m_lblNumeMaghiar.setMinimumWidth(labelWidth);
    m_lblNumeMaghiar.setMaximumWidth(labelWidth);
    m_lblNumeRomanesc.setMinimumWidth(labelWidth);
    m_lblNumeRomanesc.setMaximumWidth(labelWidth);
    m_lblNumeSasesc.setMinimumWidth(labelWidth);
    m_lblNumeSasesc.setMaximumWidth(labelWidth);
    m_lblOldStatus.setMinimumWidth(labelWidth);
    m_lblOldStatus.setMaximumWidth(labelWidth);

    m_edComune.setMinimumWidth(editWidth);
    m_edComune.setMaximumWidth(editWidth);
    m_edCounty.setMinimumWidth(editWidth);
    m_edCounty.setMaximumWidth(editWidth);
    m_edDate.setMinimumWidth(editWidth);
    m_edDate.setMaximumWidth(editWidth);
    m_edLocality.setMinimumWidth(editWidth);
    m_edLocality.setMaximumWidth(editWidth);
    m_edNumeRomanesc.setMinimumWidth(editWidth);
    m_edNumeRomanesc.setMaximumWidth(editWidth);
    m_edNumeGerman.setMinimumWidth(editWidth);
    m_edNumeGerman.setMaximumWidth(editWidth);
    m_edNumeSasesc.setMinimumWidth(editWidth);
    m_edNumeSasesc.setMaximumWidth(editWidth);
    m_edNumeMaghiar.setMinimumWidth(editWidth);
    m_edNumeMaghiar.setMaximumWidth(editWidth);
    m_edOldStatus.setMinimumWidth(editWidth);
    m_edOldStatus.setMaximumWidth(editWidth);

    m_edNumeRomanesc.setText(m_House.NameRO());
    m_edNumeGerman.setText(m_House.NameDE());
    m_edNumeSasesc.setText(m_House.NameSX());
    m_edNumeMaghiar.setText(m_House.NameHU());
    updateLocality(m_House.IdLocality());

    m_Image.setMinimumWidth(editWidth + labelWidth + 20);
    m_Tab.setMinimumWidth(2 * (editWidth + labelWidth + 20));
    m_Tab.setMinimumHeight(80);

    WndEditHouse_TabBuilding* tabBuilding = new WndEditHouse_TabBuilding(&m_House, m_NewItem, this);
    WndEditHouse_TabFunction* tabFunction = new WndEditHouse_TabFunction(&m_House, m_NewItem, this);
    WndEditHouse_TabPositioning* tabPositioning = new WndEditHouse_TabPositioning(&m_House, m_NewItem, this);
    WndEditHouse_TabPriests* tabPriests = new WndEditHouse_TabPriests(&m_House, m_NewItem, this);
    WndEditHouse_TabTaxes* tabTaxes = new WndEditHouse_TabTaxes(m_House.Id(), m_NewItem, this);

    connect(tabPriests, SIGNAL(saveHouse()), SLOT(onSaveHouse()));

    m_TabItems[tr("Building")] = m_Tab.addTab(tabBuilding, tr("Building"));;
    m_TabItems[tr("Function")] = m_Tab.addTab(tabFunction, tr("Function"));
    m_TabItems[tr("Positioning")] = m_Tab.addTab(tabPositioning, tr("Positioning"));
    m_TabItems[tr("Priests")] = m_Tab.addTab(tabPriests, tr("Priests"));
    m_TabItems[tr("Taxes")] = m_Tab.addTab(tabTaxes, tr("Taxes"));

    m_edLocality.setReadOnly(true);
    m_edComune.setReadOnly(true);
    m_edCounty.setReadOnly(true);

    m_btnImgPrev.setText("<<");
    m_btnImgNext.setText(">>");
    m_btnImgAddNew.setText("+N");
    m_btnImgAddFromDB.setText("+DB");
    m_btnImgRem.setText("-");


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

    connect(&m_btnApply, SIGNAL(clicked()), SLOT(onApply()));
    connect(&m_btnCancel, SIGNAL(clicked()), SLOT(onCancel()));
    connect(&m_btnOK, SIGNAL(clicked()), SLOT(onOK()));
    connect(&m_btnImgAddNew, SIGNAL(clicked()), SLOT(on_btnAddNewImage_clicked()));
    connect(&m_btnImgAddFromDB, SIGNAL(clicked()), SLOT(on_btnAddDBImage_clicked()));
    connect(&m_btnImgRem, SIGNAL(clicked()), SLOT(on_btnRemImage_clicked()));
    connect(&m_btnImgPrev, SIGNAL(clicked()), SLOT(on_btnPrevImage_clicked()));
    connect(&m_btnImgNext, SIGNAL(clicked()), SLOT(on_btnNextImage_clicked()));
    connect(&m_edLocality, SIGNAL(doubleClick(QMouseEvent*)), SLOT(on_edLocality_doubleClicked(QMouseEvent*)));

    m_Image.setMinimumHeight(200);
    m_Image.setMaximumHeight(400);
    m_Image.setMinimumWidth(200);
    m_Image.setMaximumWidth(400);

    m_btnImgAddFromDB.setMaximumWidth(50);
    m_btnImgAddNew.setMaximumWidth(50);
    m_btnImgRem.setMaximumWidth(50);


    QHBoxLayout* layoutNumeRO = new QHBoxLayout();
    layoutNumeRO->setContentsMargins(0, 0, 0, 0);
    layoutNumeRO->setSpacing(0);

    layoutNumeRO->addStretch();
    layoutNumeRO->addWidget(&m_lblNumeRomanesc);
    layoutNumeRO->addSpacing(10);
    layoutNumeRO->addWidget(&m_edNumeRomanesc);
    layoutNumeRO->addStretch();

    QHBoxLayout* layoutNumeDE = new QHBoxLayout();
    layoutNumeDE->setContentsMargins(0, 0, 0, 0);
    layoutNumeDE->setSpacing(0);

    layoutNumeDE->addStretch();
    layoutNumeDE->addWidget(&m_lblNumeGerman);
    layoutNumeDE->addSpacing(10);
    layoutNumeDE->addWidget(&m_edNumeGerman);
    layoutNumeDE->addStretch();

    QHBoxLayout* layoutNumeSX = new QHBoxLayout();
    layoutNumeSX->setContentsMargins(0, 0, 0, 0);
    layoutNumeSX->setSpacing(0);

    layoutNumeSX->addStretch();
    layoutNumeSX->addWidget(&m_lblNumeSasesc);
    layoutNumeSX->addSpacing(10);
    layoutNumeSX->addWidget(&m_edNumeSasesc);
    layoutNumeSX->addStretch();

    QHBoxLayout* layoutNumeHU = new QHBoxLayout();
    layoutNumeHU->setContentsMargins(0, 0, 0, 0);
    layoutNumeHU->setSpacing(0);

    layoutNumeHU->addStretch();
    layoutNumeHU->addWidget(&m_lblNumeMaghiar);
    layoutNumeHU->addSpacing(10);
    layoutNumeHU->addWidget(&m_edNumeMaghiar);
    layoutNumeHU->addStretch();

    QHBoxLayout* layoutOldStatus = new QHBoxLayout();
    layoutOldStatus->setContentsMargins(0, 0, 0, 0);
    layoutOldStatus->setSpacing(0);

    layoutOldStatus->addStretch();
    layoutOldStatus->addWidget(&m_lblOldStatus);
    layoutOldStatus->addSpacing(10);
    layoutOldStatus->addWidget(&m_edOldStatus);
    layoutOldStatus->addStretch();

    QHBoxLayout* layoutLocality = new QHBoxLayout();
    layoutLocality->setContentsMargins(0, 0, 0, 0);
    layoutLocality->setSpacing(0);

    layoutLocality->addStretch();
    layoutLocality->addWidget(&m_lblLocality);
    layoutLocality->addSpacing(10);
    layoutLocality->addWidget(&m_edLocality);
    layoutLocality->addStretch();

    QHBoxLayout* layoutComune = new QHBoxLayout();
    layoutComune->setContentsMargins(0, 0, 0, 0);
    layoutComune->setSpacing(0);

    layoutComune->addStretch();
    layoutComune->addWidget(&m_lblComune);
    layoutComune->addSpacing(10);
    layoutComune->addWidget(&m_edComune);
    layoutComune->addStretch();

    QHBoxLayout* layoutCounty = new QHBoxLayout();
    layoutCounty->setContentsMargins(0, 0, 0, 0);
    layoutCounty->setSpacing(0);

    layoutCounty->addStretch();
    layoutCounty->addWidget(&m_lblCounty);
    layoutCounty->addSpacing(10);
    layoutCounty->addWidget(&m_edCounty);
    layoutCounty->addStretch();

    QHBoxLayout* layoutDate = new QHBoxLayout();
    layoutDate->setContentsMargins(0, 0, 0, 0);
    layoutDate->setSpacing(0);

    layoutDate->addStretch();
    layoutDate->addWidget(&m_lblDate);
    layoutDate->addSpacing(10);
    layoutDate->addWidget(&m_edDate);
    layoutDate->addStretch();

    QVBoxLayout* layoutTopLeft = new QVBoxLayout();
    layoutTopLeft->setContentsMargins(0, 0, 0, 0);
    layoutTopLeft->setSpacing(0);

    layoutTopLeft->addStretch();
    layoutTopLeft->addLayout(layoutNumeRO);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutNumeDE);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutNumeSX);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutNumeHU);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutOldStatus);
    layoutTopLeft->addSpacing(20);
    layoutTopLeft->addLayout(layoutLocality);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutComune);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutCounty);
    layoutTopLeft->addSpacing(5);
    layoutTopLeft->addLayout(layoutDate);
    layoutTopLeft->addStretch();

    QVBoxLayout* layoutImgAddRem = new QVBoxLayout();
    layoutImgAddRem->setContentsMargins(0, 0, 0, 0);
    layoutImgAddRem->setSpacing(0);

    layoutImgAddRem->addSpacing(20);
    layoutImgAddRem->addWidget(&m_btnImgAddNew);
    layoutImgAddRem->addSpacing(10);
    layoutImgAddRem->addWidget(&m_btnImgAddFromDB);
    layoutImgAddRem->addSpacing(10);
    layoutImgAddRem->addWidget(&m_btnImgRem);
    layoutImgAddRem->addSpacing(10);
    layoutImgAddRem->addStretch();

    QHBoxLayout* layoutImage = new QHBoxLayout();
    layoutImage->setContentsMargins(0, 0, 0, 0);
    layoutImage->setSpacing(0);

    layoutImage->addSpacing(10);
    layoutImage->addWidget(&m_Image);
    layoutImage->addSpacing(10);
    layoutImage->addLayout(layoutImgAddRem);

    QHBoxLayout* layoutImgNextPrev = new QHBoxLayout();
    layoutImgNextPrev->setContentsMargins(0, 0, 0, 0);
    layoutImgNextPrev->setSpacing(0);

    layoutImgNextPrev->addStretch();
    layoutImgNextPrev->addWidget(&m_btnImgPrev);
    layoutImgNextPrev->addSpacing(10);
    layoutImgNextPrev->addWidget(&m_btnImgNext);
    layoutImgNextPrev->addStretch();

    QVBoxLayout* layoutTopRight = new QVBoxLayout();
    layoutTopRight->setContentsMargins(0, 0, 0, 0);
    layoutTopRight->setSpacing(0);

    layoutTopRight->addSpacing(10);
    layoutTopRight->addLayout(layoutImage);
    layoutTopRight->addSpacing(10);
    layoutTopRight->addLayout(layoutImgNextPrev);
    layoutTopRight->addSpacing(10);

    QHBoxLayout* layoutTop = new QHBoxLayout();
    layoutTop->setContentsMargins(0, 0, 0, 0);
    layoutTop->setSpacing(0);

    layoutTop->addLayout(layoutTopLeft);
    layoutTop->addSpacing(10);
    layoutTop->addLayout(layoutTopRight);

    QHBoxLayout* layoutBottom = new QHBoxLayout();
    layoutBottom->setContentsMargins(0, 0, 0, 0);
    layoutBottom->setSpacing(0);

    layoutBottom->addWidget(&m_Tab);

    QVBoxLayout* layoutMain = new QVBoxLayout();
    layoutMain->setContentsMargins(10, 10, 10, 10);
    layoutMain->setSpacing(0);

    layoutMain->addLayout(layoutTop);
    layoutMain->addSpacing(10);
    layoutMain->addLayout(layoutBottom);
    layoutMain->addSpacing(20);
    layoutMain->addLayout(btnLayout);
    layoutMain->addSpacing(20);

    setLayout(layoutMain);

    QList<DBWrapper::ImageInfo*> images = m_House.getImages();
    if(!images.isEmpty()){
        DBWrapper::ImageInfo* image = images.front();
        if(image != nullptr)
            setCurrentImage(image->Id());
    }
}

bool
WndEditHouse::loadFromDB(const QUuid& id)
{
    if(!id.isNull())
        m_House.setId(id);

    if(m_House.LoadFromDB()){
        m_edNumeRomanesc.setText(m_House.NameRO());
        m_edNumeGerman.setText(m_House.NameDE());
        m_edNumeSasesc.setText(m_House.NameSX());
        m_edNumeMaghiar.setText(m_House.NameHU());
        m_edDate.setText(m_House.HouseDating());
        m_edOldStatus.setText(m_House.OldStatus());
        if(!m_House.getImages().isEmpty()){
            DBWrapper::ImageInfo* image = m_House.getImages().front();
            if(image != nullptr){
                m_Image.setPixmap(QPixmap(image->Path()));
                m_CurrentImageId = image->Id();
            }
        }

        return true;
    }

    return false;
}

bool
WndEditHouse::saveToDB()
{
    m_House.setNameRO(m_edNumeRomanesc.text());
    m_House.setNameDE(m_edNumeGerman.text());
    m_House.setNameSX(m_edNumeSasesc.text());
    m_House.setNameHU(m_edNumeMaghiar.text());
    m_House.setHouseDating(m_edDate.text());
    m_House.setOldStatus(m_edOldStatus.text());
    m_House.setIdLocality(m_Locality.Id());

    WndEditHouse_TabBuilding* tabBuilding = qobject_cast<WndEditHouse_TabBuilding*>(m_Tab.widget(m_TabItems[tr("Building")]));
    if(tabBuilding != nullptr)
        tabBuilding->saveToDB();

    WndEditHouse_TabFunction* tabFunction = qobject_cast<WndEditHouse_TabFunction*>(m_Tab.widget(m_TabItems[tr("Function")]));
    if(tabFunction != nullptr)
        tabFunction->saveToDB();

    WndEditHouse_TabPositioning* tabPositioning = qobject_cast<WndEditHouse_TabPositioning*>(m_Tab.widget(m_TabItems[tr("Positioning")]));
    if(tabPositioning != nullptr)
        tabPositioning->saveToDB();

    return m_House.SaveToDB();
}

void
WndEditHouse::saveOnlyHouseData()
{
    m_House.setNameRO(m_edNumeRomanesc.text());
    m_House.setNameDE(m_edNumeGerman.text());
    m_House.setNameSX(m_edNumeSasesc.text());
    m_House.setNameHU(m_edNumeMaghiar.text());
    m_House.setHouseDating(m_edDate.text());
    m_House.setOldStatus(m_edOldStatus.text());
    m_House.setIdLocality(m_Locality.Id());
}

void
WndEditHouse::updateLocality(const QUuid& idLocality)
{
    m_Locality.setId(idLocality);
    if(m_Locality.LoadFromDB()){
        DBWrapper::Comune comune;
        comune.setId(m_Locality.Comune());
        m_edLocality.setText(m_Locality.NameRO());
        if(comune.LoadFromDB()){
            m_edComune.setText(comune.NameRO());
            DBWrapper::County county;
            county.setId(comune.County());
            if(county.LoadFromDB()){
                m_edCounty.setText(county.NameRO());
            }
        }
    }
}

void
WndEditHouse::resizeEvent(QResizeEvent* ev)
{
    Q_UNUSED(ev);

    updateImageSize();
}

bool
WndEditHouse::eventFilter(QObject* o, QEvent * ev)
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
WndEditHouse::onSaveHouse()
{
    QWidget* widget = qobject_cast<QWidget*>(sender());


    WndEditHouse_TabBuilding* tabBuilding = qobject_cast<WndEditHouse_TabBuilding*>(m_Tab.widget(m_TabItems[tr("Building")]));
    WndEditHouse_TabFunction* tabFunction = qobject_cast<WndEditHouse_TabFunction*>(m_Tab.widget(m_TabItems[tr("Function")]));
    WndEditHouse_TabPositioning* tabPositioning = qobject_cast<WndEditHouse_TabPositioning*>(m_Tab.widget(m_TabItems[tr("Positioning")]));
    WndEditHouse_TabPriests* tabPriests = qobject_cast<WndEditHouse_TabPriests*>(m_Tab.widget(m_TabItems[tr("Priests")]));
    WndEditHouse_TabTaxes* tabTaxes = qobject_cast<WndEditHouse_TabTaxes*>(m_Tab.widget(m_TabItems[tr("Taxes")]));

    if(tabBuilding != nullptr && widget != tabBuilding)
        tabBuilding->saveToDB();

    if(tabFunction != nullptr && widget != tabFunction)
        tabFunction->saveToDB();

    if(tabPositioning != nullptr && widget != tabPositioning)
        tabPositioning->saveToDB();

    saveOnlyHouseData();
    if(m_House.SaveToDB())
    {
        if(tabPriests != nullptr)
            tabPriests->houseSaved();

        if(tabTaxes != nullptr)
            tabTaxes->houseSaved();
    }
}

void
WndEditHouse::onCancel()
{
    done(-1);
}

void
WndEditHouse::onOK()
{
    saveToDB();
    done(0);
}

void
WndEditHouse::onApply()
{
    saveToDB();
}

bool
WndEditHouse::onKeyPressed(QKeyEvent* ev)
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
WndEditHouse::updateImageSize()
{
    QSize sizeImage = m_Image.size();
    {
        DBWrapper::ImageInfo* image = m_House.findImageInfo(m_CurrentImageId);
        if(image != nullptr){
            QPixmap pixImage = QPixmap(image->Path()).scaled(sizeImage, Qt::KeepAspectRatio);
            m_Image.setPixmap(pixImage);
        }
    }
}

void
WndEditHouse::setCurrentImage(const QUuid& idImage)
{
    if(!idImage.isNull()){
        DBWrapper::ImageInfo image;
        image.setId(idImage);
        if(image.LoadFromDB()){
            m_Image.setPixmap(QPixmap(image.Path()));
            updateImageSize();
        }
    }else{
        m_Image.clear();
    }
}

void
WndEditHouse::on_btnNextImage_clicked()
{
    if(m_House.hasNextImage(m_CurrentImageId)){
        m_CurrentImageId = m_House.getNextImageId(m_CurrentImageId);
        setCurrentImage(m_CurrentImageId);
    }
}

void
WndEditHouse::on_btnPrevImage_clicked()
{
    if(m_House.hasPrevImage(m_CurrentImageId)){
        m_CurrentImageId = m_House.getPrevImageId(m_CurrentImageId);
        setCurrentImage(m_CurrentImageId);
    }
}

void
WndEditHouse::on_btnAddNewImage_clicked()
{
    WndEditImage addImge;
    addImge.exec();

    DBWrapper::ImageInfo* image = new DBWrapper::ImageInfo();
    (*image) = addImge.getImage();
    if(!image->Id().isNull()){
        m_House.addImageInfo(image);
        if(m_House.getImages().size() == 1){
            m_Image.setPixmap(QPixmap(image->Path()));
            m_CurrentImageId = image->Id();

            updateImageSize();
        }
    }
}

void
WndEditHouse::on_btnAddDBImage_clicked()
{
    Core::WndFilterBase filterImages(DBWrapper::ImageInfo::STR_TABLE_NAME, this);
    filterImages.setImageColumn("Path");
    filterImages.exec();

    QUuid idImage = filterImages.getSelectedId();
//    updateLocality(idLocality);
}

void
WndEditHouse::on_btnRemImage_clicked()
{
}

void
WndEditHouse::on_edLocality_doubleClicked(QMouseEvent* ev)
{
    Q_UNUSED(ev);

    Core::WndFilterBase filterLocality(DBWrapper::Locality::STR_TABLE_NAME, this);
    filterLocality.exec();

    QUuid idLocality = filterLocality.getSelectedId();
    updateLocality(idLocality);
}
