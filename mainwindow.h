#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#define OEMRESOURCE
#include <windows.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    POINT fishingRod;
    POINT water;
    POINT fishBait;

private slots:
    void FishingRod();
    void Water();
    void Fishing();
    void FishBait();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    int bait = 1000;
    bool button1_state = true;
    bool button2_state = true;
    bool button3_state = true;
    bool button4_state = true;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
