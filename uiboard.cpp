#include "uiboard.h"
#include "ui_uiboard.h"

UIBoard::UIBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIBoard)
{
    ui->setupUi(this);

    QDir directory("Exercices/level1");
    QStringList name = directory.entryList(QStringList() << "*.in",QDir::Files);
    foreach(QString filename, name) {
        new QListWidgetItem(filename, ui->MHVList);
    }
}

UIBoard::~UIBoard()
{
    delete ui;
}

void UIBoard::on_MHVList_activated(const QModelIndex &index)
{

}
