#ifndef WNDEDITHOUSE_H
#define WNDEDITHOUSE_H

#include "HouseManager.h"

namespace Ui {
    class WndEditHouse;
}

class WndEditHouse : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditHouse(QWidget *parent = 0, const QUuid& houseId = QUuid());
        ~WndEditHouse();

    protected:
        void loadHouseInfo();
        void onSave();
        void onCancel();

    private slots:
        void on_btnNextImage_clicked();
        void on_btnPrevImage_clicked();

    protected:
        QUuid m_HouseId;
        House* m_pHouse;

    private:
        Ui::WndEditHouse *ui;
};

#endif // WNDEDITHOUSE_H
