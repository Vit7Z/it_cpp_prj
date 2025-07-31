#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QByteArray>
#include <QChar>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QTextBrowser>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pB1_Open_clicked();
    void on_pB2_Save_clicked();
    void on_pB3_Increase_clicked();

private:
    Ui::MainWindow *ui;

    QString name_prefix = "0";
    QString path = "0";
    QString text = "";
};
#endif // MAINWINDOW_H
