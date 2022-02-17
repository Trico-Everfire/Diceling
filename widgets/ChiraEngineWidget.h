#pragma once

#include <QWidget>
#include "ChiraEngineWorkerThread.h"

class ChiraEngineWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ChiraEngineWidget(QWidget *pParent = nullptr);
    ~ChiraEngineWidget() override;

protected:
    ChiraEngineWorkerThread engineThread;

    void paintEvent(QPaintEvent *event) override;
};