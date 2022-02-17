#include "ChiraEngineWidget.h"

#include <vector>
#include <QPainter>
#include <QTimer>

#include <core/engine.h>
using namespace chira;

ChiraEngineWidget::ChiraEngineWidget(QWidget *pParent) : QWidget(pParent) {
    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&ChiraEngineWidget::update));
    timer->start(17);

    Engine::preInit("chira_settings.json");
    Engine::getSettingsLoader()->setValue("graphics", "windowWidth", width(), true, false);
    Engine::getSettingsLoader()->setValue("graphics", "windowHeight", height(), true, true);

    this->engineThread.start(QThread::HighPriority);
}

ChiraEngineWidget::~ChiraEngineWidget() {
    this->engineThread.terminate();
}

void ChiraEngineWidget::paintEvent(QPaintEvent *event) {
    if (!Engine::isStarted())
        return;

    const unsigned int texHandle = Engine::getWindow()->getColorTextureHandle();

    const int size = static_cast<int>(sizeof(unsigned char)) * 4 * height() * width();
    std::vector<uchar> pixels;
    pixels.resize(size);
    glGetTextureImage(texHandle, 0, GL_RGBA, GL_UNSIGNED_BYTE, size, static_cast<void*>(&pixels[0]));

    QPixmap image(width(), height());
    image.loadFromData(reinterpret_cast<const uchar*>(&pixels[0]), size);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
#ifdef DEBUG
    painter.setPen(QColor(168, 34, 3));
    painter.fillRect(rect(), Qt::BrushStyle::NoBrush);
#endif
    //painter.drawPixmap(this->rect(), image);
}