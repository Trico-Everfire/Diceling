//
// Created by trico on 16-2-22.
//

#include "ChiraOpenGLWidget.h"

ChiraOpenGLWidget::ChiraOpenGLWidget(QWidget* parent) : QOpenGLWidget(parent)
{

}

void ChiraOpenGLWidget::initializeGL() {
    QOpenGLWidget::initializeGL();
}

void ChiraOpenGLWidget::resizeGL(int w, int h) {
    QOpenGLWidget::resizeGL(w, h);
}

void ChiraOpenGLWidget::paintGL() {
    QOpenGLWidget::paintGL();
}
