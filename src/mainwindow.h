#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>

#include <stk/Noise.h>
#include <stk/FileWvOut.h>
#include <stk/SineWave.h>
#include <stk/Chorus.h>
#include <stk/Whistle.h>
#include <stk/MidiFileIn.h>

#include <midifile/MidiFile.h>

#include "project.h"
#include "mixer.h"

using namespace stk;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Project poj;
    Mixer mixer;


public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
