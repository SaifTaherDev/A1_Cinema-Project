#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "welcomewindow.h"
#include "registerwindow.h"
#include "users.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->login_labelErr->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    QString user = ui->login_lineEditUsername->text();
    QString pass = ui->login_lineEditPass->text();

    for (int i = 0; i < usersCount; i++)
    {
        if (user == usernames[i])
            if (pass == passwords[i])
            {
                ui->login_labelErr->setVisible(false);
                WelcomeWindow* welcomeWindow = new WelcomeWindow(user, ages[i], this);
                this->hide();
                welcomeWindow->show();
                return ;
            }
    }
    ui->login_labelErr->setVisible(true);
}


void MainWindow::on_login_regButton_clicked()
{
    this->hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

