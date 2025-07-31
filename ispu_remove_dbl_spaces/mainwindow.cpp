#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB1_Open_clicked()
{
    QFile file_name = QFileDialog::getOpenFileName(this,
                                                   QString::fromLocal8Bit("Открыть файл"),
                                                   "../",
                                                   QString::fromLocal8Bit(
                                                       "Текстовые файлы (*.txt)"));

    QByteArray text_in_bytes;

    if (!file_name.open(QIODevice::ReadWrite)) {
        return;
    } else {
        text_in_bytes = file_name.readAll();
        text = QString::fromUtf8(text_in_bytes);
        ui->textBrowser->setText(text);

        QFileInfo file_info(file_name);
        name_prefix = file_info.baseName();
        path = QFileInfo(file_info).path();
    }
}

void MainWindow::on_pB2_Save_clicked()
{
    if (name_prefix == "0") {
        return;
    } else {
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedDateTime = currentDateTime.toString("yyyy-MM-dd_hh-mm-ss");

        name_prefix = path + "/" + name_prefix + "_" + formattedDateTime + ".txt";

        QFile file_name = QFileDialog::getSaveFileName(this,
                                                       QString::fromLocal8Bit("Сохранить файл"),
                                                       name_prefix,
                                                       QString::fromLocal8Bit(
                                                           "Текстовые файлы (*.txt)"));

        if (file_name.open(QIODevice::WriteOnly)) {
            QTextStream out(&file_name);
            QByteArray text_in_bytes = text.toUtf8(); // Преобразуем QString в QByteArray
            out << text_in_bytes;
            file_name.close();
        }
    }
}

void MainWindow::on_pB3_Remove_clicked()
{
    text = text.trimmed();

    QString result;
    bool space_found = false;

    for (int i = 0; i <= text.size() - 1; i++) {
        if (text[i] == ' ') {
            if (!space_found) {
                result += text[i];
                space_found = true;
            }
        } else {
            result += text[i];
            space_found = false;
        }
    }

    text = result;
    ui->textBrowser->setText(text);
    //qDebug() << QString(text);
}
