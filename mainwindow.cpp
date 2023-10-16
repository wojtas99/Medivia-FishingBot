#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QCoreApplication>
#include <qlabel.h>
QFuture<void> future;

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
void MainWindow::Fishing()
{
    HWND game = FindWindow(NULL, L"Medivia");
    int v;
    QString s = QString::number(bait);
    while(1)
    {
        if (future.isCanceled())
        {
            return;
        }
        if(this->bait >= 1015)
        {
            SendMessageCallback(game, WM_MOUSEMOVE, 0, MAKELPARAM(fishBait.x, fishBait.y), 0, 0);
            SendMessageCallback(game, WM_RBUTTONDOWN, 2, MAKELPARAM(fishBait.x, fishBait.y), 0, 0);
            SendMessageCallback(game, WM_RBUTTONUP, 0, MAKELPARAM(fishBait.x, fishBait.y), 0, 0);
            SendMessageCallback(game, WM_MOUSEMOVE, 0, MAKELPARAM(water.x, water.y), 0, 0);
            SendMessageCallback(game, WM_LBUTTONDOWN, 1, MAKELPARAM(water.x, water.y), 0, 0);
            SendMessageCallback(game, WM_LBUTTONUP, 0, MAKELPARAM(water.x, water.y), 0, 0);
            this->bait = 0;
            Sleep(2000);
        }
        qDebug()<<this->bait;
        v = rand() % 100 + 1005;
        SendMessageCallback(game, WM_MOUSEMOVE, 0, MAKELPARAM(fishingRod.x, fishingRod.y), 0, 0);
        SendMessageCallback(game, WM_RBUTTONDOWN, 2, MAKELPARAM(fishingRod.x, fishingRod.y), 0, 0);
        SendMessageCallback(game, WM_RBUTTONUP, 0, MAKELPARAM(fishingRod.x, fishingRod.y), 0, 0);
        SendMessageCallback(game, WM_MOUSEMOVE, 0, MAKELPARAM(water.x, water.y), 0, 0);
        SendMessageCallback(game, WM_LBUTTONDOWN, 1, MAKELPARAM(water.x, water.y), 0, 0);
        SendMessageCallback(game, WM_LBUTTONUP, 0, MAKELPARAM(water.x, water.y), 0, 0);
        this->bait += 1;
        Sleep(v);
    }
}
void MainWindow::FishingRod()
{
    HWND game = FindWindow(NULL, L"Medivia");
    while(1)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            GetCursorPos(&fishingRod);
            ScreenToClient(game, &fishingRod);
            ui->label->setText("Saved!");
            return;
        }
    }
}
void MainWindow::Water()
{
    HWND game = FindWindow(NULL, L"Medivia");
    while(1)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            GetCursorPos(&water);
            ScreenToClient(game, &water);
            ui->label->setText("Saved!");
            return;
        }
    }
}
void MainWindow::FishBait()
{
    HWND game = FindWindow(NULL, L"Medivia");
    while(1)
    {
        if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            GetCursorPos(&fishBait);
            ScreenToClient(game, &fishBait);
            ui->label->setText("Saved!");
            return;
        }
    }
}
void MainWindow::on_pushButton_clicked()
{
    if(this->button1_state == true)
    {
        this->button1_state = false;
        future = QtConcurrent::run([this]() {
            Fishing();
        });
        ui->pushButton->setText("Stop");
        ui->label->setText("Enjoy Fishing!");
        return;
    }
    if(this->button1_state == false)
    {
        this->button1_state = true;
        ui->pushButton->setText("Start");
        future.cancel();
        return;
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    if(this->button2_state == true)
    {
        future = QtConcurrent::run([this]() {
            FishingRod();
        });
        ui->label->setText("Point mouse on FishingRod and press Lbutton");
        return;
    }
    if(this->button2_state == false)
    {
        this->button2_state = true;
        return;
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(this->button3_state == true)
    {
        this->button3_state = false;
        future = QtConcurrent::run([this]() {
            Water();
        });
        ui->label->setText("Point mouse on Water and press Lbutton");
        return;
    }
    if(this->button3_state == false)
    {
        this->button3_state = true;
        return;
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    if(this->button4_state == true)
    {
        this->button4_state = false;
        future = QtConcurrent::run([this]() {
            FishBait();
        });
        ui->label->setText("Point mouse on FishBait and press Lbutton");
        return;
    }
    if(this->button4_state == false)
    {
        this->button4_state = true;
        return;
    }
}

