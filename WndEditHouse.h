#ifndef WNDEDITHOUSE_H
#define WNDEDITHOUSE_H

#include "Base.h"

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

    private slots:
        void on_btnNextImage_clicked();
        void on_btnPrevImage_clicked();

    protected:
        QUuid m_HouseId;

    private:
        Ui::WndEditHouse *ui;
};

#endif // WNDEDITHOUSE_H
