#ifndef UIBOARD_H
#define UIBOARD_H

#include <QMainWindow>

namespace Ui {
class UIBoard;
}

class UIBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit UIBoard(QWidget *parent = nullptr);
    ~UIBoard();

private:
    Ui::UIBoard *ui;
};

#endif // UIBOARD_H
