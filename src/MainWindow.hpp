#pragma once

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private slots:
        void onButtonClicked();

    private:
        void setupUI();
        void setupConnections();
        
        QLabel *title;
        QPushButton *button;
        QLabel *undertext;
        
        int clickCount;
};
