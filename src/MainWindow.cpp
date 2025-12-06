#include "MainWindow.hpp"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent), clickCount(0) {
    setupUI();
    setupConnections();
}

void MainWindow::setupUI() {
    setWindowTitle("PoC Rythmopen");
    resize(800, 600);

    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);

    QVBoxLayout *layout = new QVBoxLayout(widget);
    layout->setAlignment(Qt::AlignCenter);
    layout->setContentsMargins(50, 50, 50, 50);

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
