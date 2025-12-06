#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <iostream>

class DevidableRect : public QGraphicsRectItem {
public:
    explicit DevidableRect(QRectF rect, QGraphicsItem *parent = nullptr) : QGraphicsRectItem(rect, parent) {
        setFlags(acceptTouchEvents());
    }
};


class GraphicsTest : public QGraphicsView {
public:
    explicit GraphicsTest(QWidget *parent = nullptr);

private:
    DevidableRect *rect;
    QGraphicsScene *scene;
};
