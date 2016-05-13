#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <vector>
#include "hangman.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onLetterClicked();

private:
    Ui::MainWindow *ui;
    QLabel* lbl = new QLabel();
    QFrame* frm = new QFrame();
    Hangman hangman;
    std::vector<QPushButton*> btns;
};

#endif // MAINWINDOW_H
