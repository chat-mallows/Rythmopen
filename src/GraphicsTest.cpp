#include "GraphicsTest.hpp"
#include <iostream>
#include <QRectF>
#include <QDebug>

GraphicsTest::GraphicsTest(QWidget *parent)
    : QGraphicsView(parent) {
    scene = new QGraphicsScene;
    this->setScene(scene);
    rect = new DevidableRect(QRectF(0,0,100,100));
    scene->addItem(rect);
}

void DevidableRect::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "au secours.";
    QGraphicsRectItem::mousePressEvent(event);
}

void DevidableRect::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "au secours (mais relaché).";
    QGraphicsRectItem::mouseReleaseEvent(event);
}
