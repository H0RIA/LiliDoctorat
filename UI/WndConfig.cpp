#include "WndConfig.h"

using namespace UI;

WndConfig::WndConfig(QWidget* parent)
    :   QWidget(parent),
        m_pTab(nullptr)
{
    initializeData();
}

WndConfig::~WndConfig()
{
}

void
WndConfig::initializeData()
{
    if(m_pTab == nullptr){
        m_pTab = new QTabWidget(this);
    }
}
