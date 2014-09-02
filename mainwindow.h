#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void displayfile(const QString filename);
    void set_text(std::string str);
    ~MainWindow();


private slots:
    void on_ok_button_clicked();

    void on_ok_button_del_clicked();

    void on_textline_returnPressed();

    void on_textline_3_returnPressed();

    void on_cancel_button_clicked();

    void on_cancel_button_3_clicked();

    void on_textline_textChanged(const QString &arg1);

    void on_textline_3_textChanged(const QString &arg1);



    void on_ok_button_2_clicked();

    void on_cancel_button_2_clicked();

    void on_textline_2_textChanged(const QString &arg1);

    void on_ok_button_3_clicked();

    void on_textline_4_textChanged(const QString &arg1);

    void on_cancel_button_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
	
	void on_pushButton_3_clicked();
	


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
