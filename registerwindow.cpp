#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "users.h"
#include "welcomewindow.h"

void RegisterWindow::resetErrors()
{
    ui->reg_labelUsernameErr->setVisible(false);
    ui->labelRetypeErr->setVisible(false);
    ui->labelDOBErr->setVisible(false);
    ui->labelRegErr->setVisible(false);
}

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    resetErrors();

    QStringList months = {"January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December"};
    ui->comboBoxMonth->addItems(months);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_reg_regButton_clicked()
{
    resetErrors();

    QString username = ui->reg_lineEditUsername->text();
    QString pass = ui->reg_lineEditPass->text();
    QString retype = ui->reg_lineEditRetype->text();

    int day = (ui->lineEditDay->text()).toInt();
    int year = (ui->lineEditYear->text()).toInt();
    int age = 2024 - year;

    bool isMale = ui->radioButtonMale->isChecked();
    bool isFemale = ui->radioButtonFemale->isChecked();

    bool isUser = ui->radioButtonUser->isChecked();
    bool isAdmin = ui->radioButtonAdmin->isChecked();

    QWidget *activeWin = QApplication::activeWindow();
    QList<QCheckBox *> checkboxes = activeWin->findChildren<QCheckBox *>();
    bool atLeastOne = false;

    foreach(const QCheckBox* box, checkboxes)
    {
        if (box->isChecked())
        {
            atLeastOne = true;
            break;
        }
    }

    bool noProblem = true;

    if (!username.size() || !pass.size() || !day || !year || (!isMale && !isFemale) || (!isUser && !isAdmin) || !atLeastOne)
    {
        ui->labelRegErr->setVisible(true);
        noProblem = false;
    }
    if (pass != retype)
    {
        ui->labelRetypeErr->setVisible(true);
        noProblem = false;
    }
    if (age < 12)
    {
        ui->labelDOBErr->setVisible(true);
        noProblem = false;
    }
    for (int i = 0; i < usersCount; i++)
    {
        if (usernames[i] == username)
        {
            ui->reg_labelUsernameErr->setVisible(true);
            noProblem = false;
            break;
        }
    }

    if(!noProblem)
        return ;

    usernames[usersCount] = username;
    passwords[usersCount] = pass;
    ages[usersCount++] = age;

    WelcomeWindow* welcomeWindow = new WelcomeWindow(username, age, this->parentWidget());
    welcomeWindow->show();
    this->close();
    return ;
}

