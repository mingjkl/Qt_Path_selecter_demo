#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>


QLineEdit *folder_path_show_le;
QLineEdit *file_path_show_le;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedHeight(150);
    this->setFixedWidth(670);

    QLabel *title = new QLabel;
    title->setParent(this);
    title->setFixedHeight(30);
    title->setFixedWidth(300);
    title->move(40,20);
    QFont ft;
    ft.setPointSize(16);
    title->setFont(ft);
    title->setText("Qt路径选择示例");
    title->show();

    QPushButton *folder_select_button = new QPushButton;
    folder_select_button->setParent(this);
    folder_select_button->setFixedHeight(30);
    folder_select_button->setFixedWidth(80);
    folder_select_button->move(550,60);
    folder_select_button->setText("路径选择");
    folder_select_button->show();
    connect(folder_select_button, SIGNAL(clicked()), this, SLOT(folder_select_button_clicked()));

    QPushButton *file_select_button = new QPushButton;
    file_select_button->setParent(this);
    file_select_button->setFixedHeight(30);
    file_select_button->setFixedWidth(80);
    file_select_button->move(550,100);
    file_select_button->setText("文件选择");
    file_select_button->show();
    connect(file_select_button, SIGNAL(clicked()), this, SLOT(file_select_button_clicked()));

    folder_path_show_le = new QLineEdit;
    folder_path_show_le->setParent(this);
    folder_path_show_le->setFixedHeight(28);
    folder_path_show_le->setFixedWidth(500);
    folder_path_show_le->move(40,60);
    folder_path_show_le->setText("文件夹路径显示");
//    folder_path_show_le->setEnabled(false);
    folder_path_show_le->show();

    file_path_show_le = new QLineEdit;
    file_path_show_le->setParent(this);
    file_path_show_le->setFixedHeight(28);
    file_path_show_le->setFixedWidth(500);
    file_path_show_le->move(40,100);
    file_path_show_le->setText("文件路径显示");
//    file_path_show_le->setEnabled(false);
    file_path_show_le->show();

}

void MainWindow::folder_select_button_clicked(void)
{
    QString folder_path = QFileDialog::getExistingDirectory(this, tr("选择路径", "./", QFileDialog::ShowDirsOnly));
    folder_path_show_le->setText(folder_path);
    qDebug() << folder_path;
}

void MainWindow::file_select_button_clicked(void)
{
    QString file_path = QFileDialog::getOpenFileName(this, tr("文件选择"), "./", tr("File(*.*)"), 0, QFileDialog::ShowDirsOnly);
    file_path_show_le->setText(file_path);
    qDebug() << file_path;
}


MainWindow::~MainWindow()
{
    delete ui;
}

