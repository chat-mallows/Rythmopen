#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent), clickCount(0) {
    setupUI();
    setupConnections();
}

void MainWindow::setupUI() {
    setWindowTitle("PoC Rythmopen");
    resize(800, 600);

    QWidget *layout_widget_2 = new QWidget(this);
    setCentralWidget(layout_widget_2);

    QHBoxLayout *layout2 = new QHBoxLayout(layout_widget_2);
    layout2->setAlignment(Qt::AlignCenter);
    layout2->setContentsMargins(50, 50, 50, 50);

    QWidget *layout_widget = new QWidget(this);
    layout2->addWidget(layout_widget);
    
    QVBoxLayout *layout = new QVBoxLayout(layout_widget);
    layout->setAlignment(Qt::AlignCenter);

    title = new QLabel("Proof of concept", this);
    title->setAlignment(Qt::AlignCenter);
    QFont titleFont = title->font();
    titleFont.setPointSize(20);
    titleFont.setBold(true);
    title->setFont(titleFont);

    button = new QPushButton("click me :3", this);
    button->setMinimumSize(200, 60);
    button->setStyleSheet(R"(
        QPushButton {
            background-color: #4CAF50;
            color: white;
            border: none;
            border-radius: 8px;
            font-size: 16px;
            font-weight: bold;
        }
        QPushButton:hover {
            background-color: #45a049;
        }
        QPushButton:pressed {
            background-color: #3d8b40;
        }
    )");

    undertext = new QLabel("you haven't clicked the button yet :<", this);
    undertext->setAlignment(Qt::AlignCenter);
    QFont counterFont = undertext->font();
    counterFont.setPointSize(14);
    undertext->setFont(counterFont);

    graphicstest = new GraphicsTest(this);
    layout2->addWidget(graphicstest);

    layout->addWidget(title);
    layout->addSpacing(30);
    layout->addWidget(button, 0, Qt::AlignCenter);
    layout->addSpacing(20);
    layout->addWidget(undertext);
}

void MainWindow::setupConnections() {
    connect(button, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

void MainWindow::onButtonClicked() {
    undertext->setText(QString("you clicked the button %1 times :D").arg(++clickCount));
}
