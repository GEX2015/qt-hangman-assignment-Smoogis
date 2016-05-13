#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QDebug>
#include <QLabel>
#include <QFrame>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto vlMain = new QVBoxLayout(ui->centralWidget);
    auto glLetters = new QGridLayout();

    //Letters
    for (char c = 'a'; c <= 'z'; c++)
    {
        auto btn = new QPushButton();
        btn->setMinimumSize(20, 20);
        btn->setMaximumSize(20, 20);
        btn->setText(QString(c));

        glLetters->addWidget(btn, (c - 'a') / 6, (c - 'a') % 6);

        connect(btn, &QPushButton::clicked, this, &MainWindow::onLetterClicked);
        btns.push_back(btn);
    }

    lbl->setText(QString::fromStdString(hangman.displayMove()));

    frm->setStyleSheet(QString::fromStdString(hangman.displayGallows()));
    frm->setMinimumWidth(150);
    frm->setMinimumHeight(250);

    vlMain->addWidget(lbl);

    vlMain->addWidget(frm);

    vlMain->addLayout(glLetters);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLetterClicked()
{
    // sender must be a QPushButton so downcast is safe
    QPushButton* btn = dynamic_cast<QPushButton*>(sender());

    QString letter = btn->text();
    std::string str = letter.toLocal8Bit().constData();
    hangman.guess(str[0]);
    lbl->setText(QString::fromStdString(hangman.displayMove()));
    btn->setEnabled(false);

    frm->setStyleSheet(QString::fromStdString(hangman.displayGallows()));

    if (hangman.won())
    {
        lbl->setText("You win!");

        for (auto e : btns)
        {
            e->setEnabled(false);
        }
    }
    else if (hangman.lost())
    {
        lbl->setText("You lose! The word was: " + QString::fromStdString(hangman.getPhrase()));

        for (auto e : btns)
        {
            e->setEnabled(false);
        }
    }
}
