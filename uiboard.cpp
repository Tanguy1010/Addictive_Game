#include "uiboard.h"
#include "ui_uiboard.h"

UIBoard::UIBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIBoard)
{
    ui->setupUi(this);
}

UIBoard::~UIBoard()
{
    delete ui;
}
