#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T16:11:35
#
#-------------------------------------------------

QT       += core gui svg network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LCP
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    HouseManager.cpp \
    House.cpp \
    PriestInfo.cpp \
    HouseFunction.cpp \
    TaxInfo.cpp \
    ImageInfo.cpp \
    HousePositioning.cpp \
    BuildingInfo.cpp \
    LocationInfo.cpp \
    Locality.cpp \
    County.cpp \
    Deanery.cpp \
    CentralWindow.cpp \
    HouseModel.cpp \
    ThumbnailDelegate.cpp \
    DBManager.cpp \
    Language.cpp \
    WndEditHouse.cpp \
    WndConfig.cpp \
    WndHouse_TabBuilding.cpp \
    WndHouse_TabFunction.cpp \
    WndHouse_TabPositioning.cpp \
    WndCounties.cpp \
    WndHouses.cpp \
    WndPriests.cpp \
    WndLanguages.cpp \
    WndDeaneries.cpp \
    WndLocalities.cpp \
    WndTaxes.cpp \
    WndImages.cpp \
    WndEditTax.cpp \
    WndFilterBase.cpp \
    LineEdit.cpp \
    WndEditCounty.cpp \
    Comune.cpp \
    WndEditLocality.cpp \
    WndComunes.cpp \
    WndEditComune.cpp

HEADERS  += MainWindow.h \
    Base.h \
    House.h \
    CentralWindow.h \
    HouseManager.h \
    PriestInfo.h \
    HouseFunction.h \
    TaxInfo.h \
    ImageInfo.h \
    HousePositioning.h \
    BuildingInfo.h \
    LocationInfo.h \
    Locality.h \
    County.h \
    Deanery.h \
    HouseModel.h \
    ThumbnailDelegate.h \
    DBManager.h \
    Language.h \
    WndEditHouse.h \
    WndConfig.h \
    WndHouse_TabBuilding.h \
    WndHouse_TabPositioning.h \
    WndHouse_TabFunction.h \
    WndHouses.h \
    WndPriests.h \
    WndLanguages.h \
    WndCounties.h \
    WndDeaneries.h \
    WndLocalities.h \
    WndImages.h \
    WndTaxes.h \
    WndEditTax.h \
    WndFilterBase.h \
    LineEdit.h \
    WndEditCounty.h \
    Comune.h \
    WndEditLocality.h \
    WndComunes.h \
    WndEditComune.h

FORMS +=

RESOURCES += \
    resources.qrc
