#ifndef WNDEDITIMAGE_H
#define WNDEDITIMAGE_H

#include "ImageInfo.h"

class WndEditImage : public QDialog
{
    Q_OBJECT

    public:
        explicit WndEditImage(QWidget *parent = 0);
        WndEditImage(const QUuid& imageId, QWidget* parent = nullptr);
        ~WndEditImage();

        ImageInfo getImage()const;

    protected:
        void initializeData();

        bool loadFromDB(const QUuid& id = QUuid());
        bool saveToDB();

        bool eventFilter(QObject* o, QEvent * ev);

    protected slots:
        void onCancel();
        void onOK();
        void onApply();

        bool onKeyPressed(QKeyEvent* ev);
        void onBrowseClicked();

    protected:
        bool m_NewItem;
        ImageInfo m_Image;

        QLabel m_lblName;
        QLineEdit m_edName;

        QLabel m_lblPath;
        QLineEdit m_edPath;
        QPushButton m_btnBrowse;

        QLabel m_lblDetails;
        QTextEdit m_edDetails;

        QPushButton m_btnCancel;
        QPushButton m_btnOK;
        QPushButton m_btnApply;
};

#endif // WNDEDITIMAGE_H
