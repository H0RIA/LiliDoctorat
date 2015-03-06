#ifndef WNDEDITHOUSE_H
#define WNDEDITHOUSE_H

#include "LineEdit.h"
#include "HouseManager.h"

class WndEditHouse : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditHouse(QWidget *parent = 0, const QUuid& houseId = QUuid());
        ~WndEditHouse();

    protected:
        void initializeData();

        void loadHouseInfo();
        void onSave();
        void onCancel();

    private slots:
        void on_btnNextImage_clicked();
        void on_btnPrevImage_clicked();
        void on_edLocality_doubleClicked();

    protected:
        QUuid m_HouseId;
        House* m_pHouse;

        // Top left
        QLabel m_lblNumeRomanesc;
        LineEdit m_edNumeRomanesc;

        QLabel m_lblNumeGerman;
        LineEdit m_edNumeGerman;

        QLabel m_lblNumeSasesc;
        LineEdit m_edNumeSasesc;

        QLabel m_lblNumeMaghiar;
        LineEdit m_edNumeMaghiar;

        QLabel m_lblOldStatus;
        LineEdit m_edOldStatus;

        QLabel m_lblLocality;
        LineEdit m_edLocality;

        QLabel m_lblComune;
        LineEdit m_edComune;

        QLabel m_lblCounty;
        LineEdit m_edCounty;

        QLabel m_lblDate;
        LineEdit m_edDate;

        // Top Right
        QLabel m_Image;
        QPushButton m_btnImgPrev;
        QPushButton m_btnImgNext;

        // Bottom
        QTabWidget m_Tab;
};

#endif // WNDEDITHOUSE_H
