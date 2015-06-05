#include "LineEdit.h"

using namespace UI::Core;

LineEdit::LineEdit(QWidget* parent)
    :   QLineEdit(parent)
{
    setStyleSheet("LineEdit{background-color: lightYellow;} LineEdit:hover{border: 1px solid gray; background-color lightYellow;}");
}

LineEdit::~LineEdit()
{
}

bool
LineEdit::event(QEvent *ev)
{
    if(ev == nullptr)
        return false;

    if(ev->type() == QEvent::MouseButtonDblClick){
        QMouseEvent* mouseEvent = dynamic_cast<QMouseEvent*>(ev);
        if(mouseEvent != nullptr){
            if(mouseEvent->button() == Qt::LeftButton){
                emit doubleClick(mouseEvent);
                return true;
            }
        }
    }

    return QLineEdit::event(ev);
}
