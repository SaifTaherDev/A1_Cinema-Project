#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewindow.h"
#include "registerwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->login_labelErr->setStyleSheet("QLabel { color : red; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    this->hide();
    WelcomeWindow* welcomeWindow = new WelcomeWindow(this);
    welcomeWindow->show();
}


void MainWindow::on_login_regButton_clicked()
{
    this->hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

