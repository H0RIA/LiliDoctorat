#include "WndEditTax.h"
#include "WndTaxes.h"

using namespace UI;

WndTaxes::WndTaxes(QWidget* parent)
    :   QWidget(parent)
{
}

WndTaxes::~WndTaxes()
{
}

void
WndTaxes::onNewItem()
{
    WndEditTax newTaxDlg(this);
    newTaxDlg.exec();
}
