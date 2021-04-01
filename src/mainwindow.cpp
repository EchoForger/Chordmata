#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mixer(&poj),
    ui(new Ui::MainWindow),
    poj(60,40,44100)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto instrmnt = new stk::Flute(20);
    poj.tracks.clear();
    poj.tracks.push_back(MIDITrack(instrmnt));
    poj.tracks.at(0).midiClips.push_back(MIDIClip(0,40));
    poj.tracks.at(0).midiClips.at(0).midiEvents.push_back(MIDIEvent(0,20,0));

    stk::StkFrames frame;
    stk::FileWvOut fileOut("temp.wav");
    mixer.GetWave(frame);
    fileOut.tick(frame);

    QSound::play("temp.wav");

}
