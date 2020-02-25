#ifndef UIBOARD_H
#define UIBOARD_H

#include <QMainWindow>
#include <QListWidget>
#include <QDir>

namespace Ui {
class UIBoard;
}

class UIBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIBoard(QWidget *parent = nullptr);
    ~UIBoard();

private slots:
    void on_MHVList_activated(const QModelIndex &index);

private:
    Ui::UIBoard *ui;
};

#endif // UIBOARD_H
