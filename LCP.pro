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
    UI/Core/WndFilterBase.cpp \
    UI/SideMenu/WndHouses.cpp \
    UI/SideMenu/ThumbnailDelegate.cpp \
    UI/SideMenu/HouseModel.cpp \
    UI/SideMenu/WndComunes.cpp \
    UI/SideMenu/WndCounties.cpp \
    UI/SideMenu/WndDeaneries.cpp \
    UI/SideMenu/WndImages.cpp \
    UI/SideMenu/WndLanguages.cpp \
    UI/SideMenu/WndLocalities.cpp \
    UI/SideMenu/WndTaxes.cpp \
    UI/SideMenu/WndPriests.cpp \
    UI/Editors/House/WndEditHouse.cpp \
    UI/Editors/House/WndEditHouse_TabBuilding.cpp \
    UI/Editors/House/WndEditHouse_TabFunction.cpp \
    UI/Editors/House/WndEditHouse_TabPositioning.cpp \
    UI/Editors/House/WndEditHouse_TabPriests.cpp \
    UI/Editors/House/WndEditHouse_TabTaxes.cpp \
    UI/Editors/WndEditComune.cpp \
    UI/Editors/WndEditCounty.cpp \
    UI/Editors/WndEditDeanery.cpp \
    UI/Editors/WndEditImage.cpp \
    UI/Editors/WndEditLocality.cpp \
    UI/Editors/WndEditPriest.cpp \
    UI/Editors/WndEditTax.cpp \
    UI/WndConfig.cpp \
    UI/CentralWindow.cpp \
    UI/MainWindow.cpp \
    DBWrapper/PriestTenure.cpp \
    UI/Core/DateDialog.cpp \
    PixmapCache.cpp \
    PixmapCacheItem.cpp

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
    UI/Core/WndFilterBase.h \
    UI/SideMenu/WndHouses.h \
    UI/SideMenu/ThumbnailDelegate.h \
    UI/SideMenu/HouseModel.h \
    UI/SideMenu/WndComunes.h \
    UI/SideMenu/WndCounties.h \
    UI/SideMenu/WndDeaneries.h \
    UI/SideMenu/WndImages.h \
    UI/SideMenu/WndLanguages.h \
    UI/SideMenu/WndLocalities.h \
    UI/SideMenu/WndTaxes.h \
    UI/SideMenu/WndPriests.h \
    UI/Editors/House/WndEditHouse.h \
    UI/Editors/House/WndEditHouse_TabBuilding.h \
    UI/Editors/House/WndEditHouse_TabFunction.h \
    UI/Editors/House/WndEditHouse_TabPositioning.h \
    UI/Editors/House/WndEditHouse_TabPriests.h \
    UI/Editors/House/WndEditHouse_TabTaxes.h \
    UI/Editors/WndEditComune.h \
    UI/Editors/WndEditCounty.h \
    UI/Editors/WndEditDeanery.h \
    UI/Editors/WndEditImage.h \
    UI/Editors/WndEditLocality.h \
    UI/Editors/WndEditPriest.h \
    UI/Editors/WndEditTax.h \
    UI/WndConfig.h \
    UI/CentralWindow.h \
    UI/MainWindow.h \
    DBWrapper/PriestTenure.h \
    UI/Core/DateDialog.h \
    PixmapCache.h \
    PixmapCacheItem.h

FORMS +=

RESOURCES += \
    resources.qrc
