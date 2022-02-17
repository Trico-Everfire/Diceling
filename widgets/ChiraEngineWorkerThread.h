#pragma once

#include <QThread>

class ChiraEngineWorkerThread : public QThread
{
    Q_OBJECT
public:
    void run() override;
};