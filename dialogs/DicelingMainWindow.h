//
// Created by trico on 15-2-22.
//

#pragma once

#include <QDialog>
#include <QVariant>
#include <QApplication>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QOpenGLWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

#include "widgets/ChiraEngineWidget.h"

namespace ui
{
    class CDicelingMainWindow : public QDialog
    {
        Q_OBJECT
    public:
        QDialogButtonBox *buttonBox;
        ChiraEngineWidget *frame;
        QPushButton *pushButton;
        QPushButton *pushButton_2;
        QPushButton *pushButton_3;
        QPushButton *pushButton_4;
        QPushButton *pushButton_5;
        QPushButton *pushButton_6;
        QSpinBox *spinBox;
        QSpinBox *spinBox_2;
        QSpinBox *spinBox_3;
        QSpinBox *spinBox_4;
        QSpinBox *spinBox_5;
        QSpinBox *spinBox_6;
        QComboBox *comboBox;
        QLabel *label;
        QPushButton *pushButton_7;
        QPushButton *pushButton_8;
        QPushButton *pushButton_9;
        explicit CDicelingMainWindow(QWidget *parent);

    private:
        int randomNumberGenerator(int max);
        enum DiceType {
            fire,
            water,
            ice,
            earth,
            plant,
            mythical,
            magical,
            enchanted,
            ancient
        };
    };
}