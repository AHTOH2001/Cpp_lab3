#include "mainwindow.h"
#include "ui_mainwindow.h"

student *head;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(555,360);
    this->setFixedSize(555,360);
    head = new student();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_student_clicked()
{
    student *Q = new student();
    if (Q->SetName1(ui->name1->text().toUtf8())+
            Q->SetName2(ui->name2->text().toUtf8())+
            Q->SetName3(ui->name3->text().toUtf8()))
    {
        QMessageBox::critical(this, "Error","Invalid FIO");
        return;
    }

    if (Q->SetScore1(ui->score1->text().toUtf8().data())+
            Q->SetScore2(ui->score2->text().toUtf8().data())+
            Q->SetScore3(ui->score3->text().toUtf8().data()))
    {
        QMessageBox::critical(this, "Error","Invalid CT");
        return;
    }

    QMessageBox::information(this, "Well done","Student added successfully");
    Q->next = head;
    head = Q;


}

void MainWindow::on_out_clicked()
{
    student *Q = head;
    char mas[10001] = {'\0'};
    while (Q->next!=NULL)
    {
        strcat(mas,Q->GetName1()+" "+Q->GetName2()+" "+Q->GetName3()+" ("+QByteArray::number(Q->GetScore1())+","+QByteArray::number(Q->GetScore2())+","+QByteArray::number(Q->GetScore3())+")\n");
        Q = Q->next;
    }
    QMessageBox::information(this, "List of students",mas);
}

void MainWindow::on_find_button_clicked()
{
    student *Q = head;
    if (student().NameCheck(ui->name_find->text().toUtf8()))
    {
        QMessageBox::critical(this, "Error","Invalid second name");
        return;
    }
    while (Q->next!=NULL)
    {
        if (ui->name_find->text().toUtf8()==Q->GetName1())
            QMessageBox::information(this, "",Q->GetName1()+" "+Q->GetName2()+" "+Q->GetName3()+" ("+QByteArray::number(Q->GetScore1())+","+QByteArray::number(Q->GetScore2())+","+QByteArray::number(Q->GetScore3())+")\n");
        Q = Q->next;
    }
}

void MainWindow::on_fire_student_clicked()
{
    if (student().NameCheck(ui->name1_fire->text().toUtf8())+
            student().NameCheck(ui->name2_fire->text().toUtf8())+
            student().NameCheck(ui->name3_fire->text().toUtf8()))
    {
        QMessageBox::critical(this, "Error","Invalid FIO");
        return;
    }
    student *Q = head;
    student *pQ = head;
    while (Q->next!=NULL)
    {
        if (ui->name1_fire->text().toUtf8()==Q->GetName1() && ui->name2_fire->text().toUtf8()==Q->GetName2() && ui->name3_fire->text().toUtf8()==Q->GetName3())
        {
            if (pQ==Q)
            {
                QMessageBox::information(this, "Killed",Q->GetName1()+" "+Q->GetName2()+" "+Q->GetName3()+" ("+QByteArray::number(Q->GetScore1())+","+QByteArray::number(Q->GetScore2())+","+QByteArray::number(Q->GetScore3())+")\n");
                head = Q->next;
                delete Q;
                Q = pQ->next;
            }
            else
            {
                QMessageBox::information(this, "Killed",Q->GetName1()+" "+Q->GetName2()+" "+Q->GetName3()+" ("+QByteArray::number(Q->GetScore1())+","+QByteArray::number(Q->GetScore2())+","+QByteArray::number(Q->GetScore3())+")\n");
                pQ->next = Q->next;
                delete Q;
                Q = pQ->next;
            }
        }
        else
        {
            pQ = Q;
            Q=Q->next;
        }
    }
}


void MainWindow::on_krasava_button_clicked()
{
    student *Q = head;
    int sum=0,k=0;
    while (Q->next!=NULL)
    {
        sum+=Q->GetScore1()+Q->GetScore2()+Q->GetScore3();
        k++;
        Q=Q->next;
    }
    Q = head;
    char mas[10000] = {'\0'};
    while (Q->next!=NULL)
    {
        if (Q->GetScore1()+Q->GetScore2()+Q->GetScore3()>=sum/k)
            strcat(mas,Q->GetName1()+" "+Q->GetName2()+" "+Q->GetName3()+" ("+QByteArray::number(Q->GetScore1())+","+QByteArray::number(Q->GetScore2())+","+QByteArray::number(Q->GetScore3())+")\n");
        Q=Q->next;
    }
    QMessageBox::information(this, "List of krasavchiks",mas);
}
