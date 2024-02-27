#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include <QDebug>

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->labelWelcome->setText("Welcome, " + username + " " + QString::number(age) + "!");
    QPixmap pix(":/images/movie.jpg");
    int w = ui->labelWelcomeImg->width();
    int h = ui->labelWelcomeImg->height();
    ui->labelWelcomeImg->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_logoutButton_clicked()
{
    this->parentWidget()->show();
    this->close();
}

