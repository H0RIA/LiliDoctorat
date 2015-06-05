#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T16:11:35
#
#-------------------------------------------------

QT       += core gui svg network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LCP
TEMPLATE = app


SOURCES += main.cpp \
    DBWrapper/BuildingInfo.cpp \
    DBWrapper/Comune.cpp \
    DBWrapper/County.cpp \
    DBWrapper/DBManager.cpp \
    DBWrapper/Deanery.cpp \
    DBWrapper/House.cpp \
    DBWrapper/HouseFunction.cpp \
    DBWrapper/HouseManager.cpp \
    DBWrapper/HousePositioning.cpp \
    DBWrapper/ImageInfo.cpp \
    DBWrapper/Language.cpp \
    DBWrapper/Locality.cpp \
    DBWrapper/PriestInfo.cpp \
    DBWrapper/TaxInfo.cpp \
    UI/Core/LineEdit.cpp \
    UI/CentralWindow.cpp \
    UI/HouseModel.cpp \
    UI/MainWindow.cpp \
    UI/ThumbnailDelegate.cpp \
    UI/WndComunes.cpp \
    UI/WndConfig.cpp \
    UI/WndCounties.cpp \
    UI/WndDeaneries.cpp \
    UI/WndEditComune.cpp \
    UI/WndEditCounty.cpp \
    UI/WndEditDeanery.cpp \
    UI/WndEditHouse.cpp \
    UI/WndEditHouse_TabBuilding.cpp \
    UI/WndEditHouse_TabFunction.cpp \
    UI/WndEditHouse_TabPositioning.cpp \
    UI/WndEditHouse_TabPriests.cpp \
    UI/WndEditHouse_TabTaxes.cpp \
    UI/WndEditImage.cpp \
    UI/WndEditLocality.cpp \
    UI/WndEditPriest.cpp \
    UI/WndEditTax.cpp \
    UI/WndFilterBase.cpp \
    UI/WndHouses.cpp \
    UI/WndImages.cpp \
    UI/WndLanguages.cpp \
    UI/WndLocalities.cpp \
    UI/WndPriests.cpp \
    UI/WndTaxes.cpp

HEADERS  += Base.h \
    DBWrapper/BuildingInfo.h \
    DBWrapper/Comune.h \
    DBWrapper/County.h \
    DBWrapper/DBManager.h \
    DBWrapper/Deanery.h \
    DBWrapper/House.h \
    DBWrapper/HouseFunction.h \
    DBWrapper/HouseManager.h \
    DBWrapper/HousePositioning.h \
    DBWrapper/ImageInfo.h \
    DBWrapper/Language.h \
    DBWrapper/Locality.h \
    DBWrapper/PriestInfo.h \
    DBWrapper/TaxInfo.h \
    UI/Core/LineEdit.h \
    UI/CentralWindow.h \
    UI/HouseModel.h \
    UI/MainWindow.h \
    UI/ThumbnailDelegate.h \
    UI/WndComunes.h \
    UI/WndConfig.h \
    UI/WndCounties.h \
    UI/WndDeaneries.h \
    UI/WndEditComune.h \
    UI/WndEditCounty.h \
    UI/WndEditDeanery.h \
    UI/WndEditHouse.h \
    UI/WndEditHouse_TabBuilding.h \
    UI/WndEditHouse_TabFunction.h \
    UI/WndEditHouse_TabPositioning.h \
    UI/WndEditHouse_TabPriests.h \
    UI/WndEditHouse_TabTaxes.h \
    UI/WndEditImage.h \
    UI/WndEditLocality.h \
    UI/WndEditPriest.h \
    UI/WndEditTax.h \
    UI/WndFilterBase.h \
    UI/WndHouses.h \
    UI/WndImages.h \
    UI/WndLanguages.h \
    UI/WndLocalities.h \
    UI/WndPriests.h \
    UI/WndTaxes.h

FORMS +=

RESOURCES += \
    resources.qrc
