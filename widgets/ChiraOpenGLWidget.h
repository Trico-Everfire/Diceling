//
// Created by trico on 16-2-22.
//

#include <QOpenGLWidget>

class ChiraOpenGLWidget : public QOpenGLWidget
{
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
public:
    ChiraOpenGLWidget(QWidget *parent);


};
