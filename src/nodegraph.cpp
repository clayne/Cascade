#include "nodegraph.h"

#include <iostream>

#include <QMouseEvent>
#include <QScrollBar>

NodeGraph::NodeGraph(QWidget* parent)
    : QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    this->setScene(scene);

    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    this->setRenderHints(QPainter::Antialiasing |
                         QPainter::SmoothPixmapTransform);
    this->setSceneRect(0, 0, viewWidth, viewHeight);
    this->centerOn(viewWidth / 2, viewHeight / 2);

    contextMenu = new NodeGraphContextMenu(this);
}

void NodeGraph::createNode(const NodeType type, const QPoint &pos)
{
    NodeBase* n = new NodeBase(type, this);
    scene->addWidget(n);
    n->move(mapToScene(lastMousePos).x(),
            mapToScene(lastMousePos).y());

    nodes.push_back(n);
}

float NodeGraph::getViewScale() const
{
    return viewScale;
}

void NodeGraph::showContextMenu(const QPoint &pos)
{
    contextMenu->exec(mapToGlobal(pos));
}

void NodeGraph::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
    {
        showContextMenu(event->pos());
    }
    else if (event->button() == Qt::MiddleButton)
    {
        isDragging = true;
    }
    lastMousePos = event->pos();
    QGraphicsView::mousePressEvent(event);
}

void NodeGraph::mouseMoveEvent(QMouseEvent* event)
{
    if (isDragging)
    {
        auto t = event->pos() - lastMousePos;
        this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() - t.x());
        this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - t.y());
    }
    lastMousePos = event->pos();
    QGraphicsView::mouseMoveEvent(event);
}

void NodeGraph::mouseReleaseEvent(QMouseEvent* event)
{
//    if (event->button() == Qt::LeftButton)
//        emit leftMouseReleasedOnTree();
    if (event->button() == Qt::MiddleButton)
        isDragging = false;
    QGraphicsView::mouseReleaseEvent(event);
}

void NodeGraph::wheelEvent(QWheelEvent* event)
{
//    QPoint scrollAmount = event->angleDelta();
//    double factor = (scrollAmount.y() > 0) ? 1.2 : 1 / 1.2;
//    this->scale(factor, factor);
//    viewScale *= factor;
}
