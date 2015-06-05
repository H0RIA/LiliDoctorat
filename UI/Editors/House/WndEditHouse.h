#ifndef WNDEDITHOUSE_H
#define WNDEDITHOUSE_H

#include "UI/Core/LineEdit.h"
#include "DBWrapper/House.h"
#include "DBWrapper/Locality.h"
#include "DBWrapper/HouseManager.h"

namespace UI
{
    class WndEditHouse : public QDialog
    {
        Q_OBJECT

        public:
            explicit WndEditHouse(QWidget *parent = 0);
            WndEditHouse(const QUuid& houseId, QWidget* parent = nullptr);
            ~WndEditHouse();

        protected:
            void initializeData();

            bool loadFromDB(const QUuid& id = QUuid());
            bool saveToDB();

            // For UI only
            void updateLocality(const QUuid& idLocality);

            void resizeEvent(QResizeEvent* ev);
            bool eventFilter(QObject* o, QEvent * ev);

        protected slots:
            void onCancel();
            void onOK();
            void onApply();

            bool onKeyPressed(QKeyEvent* ev);
            void updateImageSize();
            void setCurrentImage(const QUuid& idImage);

        private slots:
            void on_btnNextImage_clicked();
            void on_btnPrevImage_clicked();
            void on_btnAddNewImage_clicked();
            void on_btnAddDBImage_clicked();
            void on_btnRemImage_clicked();
            void on_edLocality_doubleClicked(QMouseEvent* ev);

        protected:
            bool m_NewItem;
            DBWrapper::House m_House;
            DBWrapper::Locality m_Locality;

            // Top left
            QLabel m_lblNumeRomanesc;
            QLineEdit m_edNumeRomanesc;

            QLabel m_lblNumeGerman;
            QLineEdit m_edNumeGerman;

            QLabel m_lblNumeSasesc;
            QLineEdit m_edNumeSasesc;

            QLabel m_lblNumeMaghiar;
            QLineEdit m_edNumeMaghiar;

            QLabel m_lblOldStatus;
            QLineEdit m_edOldStatus;

            QLabel m_lblLocality;
            Core::LineEdit m_edLocality;

            QLabel m_lblComune;
            QLineEdit m_edComune;

            QLabel m_lblCounty;
            QLineEdit m_edCounty;

            QLabel m_lblDate;
            QLineEdit m_edDate;

            // Top Right
            QLabel m_Image;
            QPushButton m_btnImgPrev;
            QPushButton m_btnImgNext;
            QPushButton m_btnImgAddFromDB;
            QPushButton m_btnImgAddNew;
            QPushButton m_btnImgRem;

            // Bottom
            QTabWidget m_Tab;

            QPushButton m_btnCancel;
            QPushButton m_btnOK;
            QPushButton m_btnApply;

            QUuid m_CurrentImageId;
    };
}

#endif // WNDEDITHOUSE_H
