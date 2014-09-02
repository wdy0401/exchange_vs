#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./gpp_qt/datafeed/datafeed.h"
#include "./gpp_qt/wfunction/wfunction.h"

#include<iostream>

#include<QFile>
#include<QString>
#include<QMessageBox>
#include<QTextStream>
#include<qtextcodec.h>
extern QApplication * qa;
extern datafeed df;
using namespace std;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	
//	
//	QString title=u8"建立删除文件 0.2版";
	string tl="version 0.2";
	this->setWindowTitle(tr(tl.c_str()));
    this->ui->ok_button->setDisabled(true);
    this->ui->cancel_button->setDisabled(true);
    this->ui->ok_button_del->setDisabled(true);
    this->ui->cancel_button_3->setDisabled(true);
    this->ui->ok_button_2->setDisabled(true);
    this->ui->cancel_button_2->setDisabled(true);
    this->ui->cancel_button_4->setDisabled(true);
    this->ui->ok_button_3->setDisabled(true);
    this->ui->pushButton->setDisabled(true);
    this->ui->pushButton_2->setDisabled(true);

    this->ui->textline_4->setFocus();

    this->ui->textEdit->setReadOnly(true);
    this->ui->textEdit_2->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_text(std::string str)
{
    this->ui->textEdit->append(QString::fromStdString(str));
    qa->processEvents();
}

void MainWindow::on_ok_button_clicked()
{
    QString filename=this->ui->textline->text();
    if(!filename.isEmpty())
    {
        QFile of(filename);
        if(of.open(QIODevice::WriteOnly))
        {
            QString opi=tr("文件已建立 ")+filename;
            QMessageBox::about(this,tr("提示信息"),opi);
            //此处pop out文件建立
        }
        else
        {
			QString opi=tr("文件未建立 ")+filename;
            QMessageBox::about(this,tr("提示信息"),opi);
        }
    }
    this->ui->textline->setFocus();
}



void MainWindow::on_ok_button_del_clicked()
{
    QString filename=this->ui->textline_3->text();
    if(!filename.isEmpty())
    {
        QFile of(filename);
        if(!of.exists())
        {
            QString opi=tr("文件不存在 ")+filename;
            QMessageBox::about(this,tr("提示信息"),opi);
            return;
        }
        if(of.remove())
        {
            QString opi=tr("文件已删除 ")+filename;
            QMessageBox::about(this,tr("提示信息"),opi);
        }
        else
        {
            QString opi=tr("文件删除失败 ")+filename;
            QMessageBox::about(this,tr("提示信息"),opi);
        }
    }
    this->ui->textline_3->setFocus();
}
void MainWindow::on_textline_returnPressed()
{
    this->on_ok_button_clicked();
}

void MainWindow::on_textline_3_returnPressed()
{
    this->on_ok_button_del_clicked();
}

void MainWindow::on_cancel_button_clicked()
{
    this->ui->textline->clear();
    this->ui->textline->setFocus();
}

void MainWindow::on_cancel_button_3_clicked()
{
    this->ui->textline_3->clear();
    this->ui->textline_3->setFocus();
}

void MainWindow::on_textline_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        this->ui->ok_button->setDisabled(true);
        this->ui->cancel_button->setDisabled(true);
    }
    else
    {
        this->ui->ok_button->setDisabled(false);
        this->ui->cancel_button->setDisabled(false);
    }
}

void MainWindow::on_textline_3_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        this->ui->ok_button_del->setDisabled(true);
        this->ui->cancel_button_3->setDisabled(true);
    }
    else
    {
        this->ui->ok_button_del->setDisabled(false);
        this->ui->cancel_button_3->setDisabled(false);
    }
}

void MainWindow::displayfile(const QString filename)
{
   if(!filename.isEmpty())
   {
        QFile infile(filename);
        if(infile.open(QIODevice::ReadOnly))
        {
            this->ui->textEdit->clear();
            QTextStream txt_input(&infile);
            QString line_str;
            while(!txt_input.atEnd())
            {
                line_str = txt_input.readLine();
                this->ui->textEdit->append(line_str);
                qa->processEvents();
            }
			infile.close();
        }
        else
        {
        }
   }
   else
   {
   }
}

void MainWindow::on_ok_button_2_clicked()
{
    this->displayfile(this->ui->textline_2->text());
    this->ui->textline_2->setFocus();
}

void MainWindow::on_cancel_button_2_clicked()
{
    this->ui->textline_2->clear();
    this->ui->textline_2->setFocus();
}

//////////////////////////////////////////////
/// Add Delete Run

void MainWindow::on_ok_button_3_clicked()
{
    if(this->ui->textline_4->text().isEmpty())
    {
    }
    else
    {
        this->ui->textEdit_2->append(this->ui->textline_4->text());
        this->ui->textline_4->clear();
        this->ui->pushButton->setDisabled(false);
        this->ui->cancel_button_4->setDisabled(false);
    }
}

void MainWindow::on_textline_4_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
       this->ui->ok_button_3->setDisabled(true);
       this->ui->pushButton_2->setDisabled(true);
    }
    else
    {
        this->ui->ok_button_3->setDisabled(false);
        this->ui->pushButton_2->setDisabled(false);
    }
}

void MainWindow::on_cancel_button_4_clicked()
{
    this->ui->textEdit_2->clear();
    this->ui->pushButton->setDisabled(true);
    this->ui->cancel_button_4->setDisabled(true);
}
void MainWindow::on_pushButton_2_clicked()
{
    this->ui->textline_4->clear();
    this->ui->pushButton_2->setDisabled(true);
    this->ui->ok_button_3->setDisabled(true);
}
void MainWindow::on_pushButton_clicked()
{
    QString txtstr=this->ui->textEdit_2->document()->toPlainText();
    QStringList files=txtstr.split("\n");
    int i=1;
    for (QStringList::iterator iter = files.begin();iter!=files.end();iter++)
    {
        df.setfile(iter->toStdString());
        cout<<i<<" "<<iter->toStdString()<<endl;
        i++;
    }
    this->ui->textEdit_2->clear();
    this->ui->pushButton->setDisabled(true);
    this->ui->cancel_button_4->setDisabled(true);
    df.run();
}

void MainWindow::on_textline_2_textChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        this->ui->ok_button_2->setDisabled(true);
        this->ui->cancel_button_2->setDisabled(true);
    }
    else
    {
        this->ui->ok_button_2->setDisabled(false);
        this->ui->cancel_button_2->setDisabled(false);
    }
}

void MainWindow::on_pushButton_3_clicked()
{	

	char * a=wfunction::gbk2utf8("兴证期货     utf8");
	char * b="兴证期货                    gbk";

	QString opi1,opi2;
	opi1=a;
	opi2=b;

//  debug模式中遇见messagebox崩溃问题 几种方法测试结果如下
//	QMessageBox::about(this,opi1,opi2);// no
//	QMessageBox::about(this,"debug","debug");//yes
//	QMessageBox::about(this,opi1.toStdString().c_str(),opi2.toStdString().c_str());//no
//	QMessageBox::about(this,a,b);//no
#ifdef _DEBUG	
	QMessageBox::about(this,"debug","debug");
#else
	QMessageBox::about(this,opi1,opi2);
#endif
}