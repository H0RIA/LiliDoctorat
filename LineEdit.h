#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "Base.h"

class LineEdit : public QLineEdit
{
    Q_OBJECT

    public:
        LineEdit(QWidget* parent = nullptr);
        ~LineEdit();

        bool event(QEvent *ev);

    signals:
        void doubleClick(QMouseEvent* ev);
};

#endif // LINEEDIT_H
