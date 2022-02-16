//
// Created by trico on 15-2-22.
//

#include <QFile>
#include <QDir>
#include <QRandomGenerator>
#include <QDebug>
#include "DicelingMainWindow.h"

using namespace ui;

CDicelingMainWindow::CDicelingMainWindow(QWidget *parent) : QDialog(parent)
{
    if(this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("Diceling"));
    this->resize(645, 531);
    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(460, 490, 181, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Reset);
    frame = new QOpenGLWidget(this);
    frame->setObjectName(QString::fromUtf8("frame"));
    frame->setGeometry(QRect(170, 20, 301, 271));

    pushButton = new QPushButton(this);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(30, 300, 88, 34));
    pushButton_2 = new QPushButton(this);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(130, 300, 88, 34));
    pushButton_3 = new QPushButton(this);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(230, 300, 88, 34));
    pushButton_4 = new QPushButton(this);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(330, 300, 88, 34));
    pushButton_5 = new QPushButton(this);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    pushButton_5->setGeometry(QRect(430, 300, 88, 34));
    pushButton_6 = new QPushButton(this);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(530, 300, 88, 34));
    pushButton_9 = new QPushButton(this);
    pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
    pushButton_9->setGeometry(QRect(30, 390, 591, 81));
    spinBox = new QSpinBox(this);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setGeometry(QRect(30, 340, 91, 41));
    spinBox_2 = new QSpinBox(this);
    spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
    spinBox_2->setGeometry(QRect(130, 340, 91, 41));
    spinBox_3 = new QSpinBox(this);
    spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
    spinBox_3->setGeometry(QRect(230, 340, 91, 41));
    spinBox_4 = new QSpinBox(this);
    spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
    spinBox_4->setGeometry(QRect(430, 340, 91, 41));
    spinBox_5 = new QSpinBox(this);
    spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
    spinBox_5->setGeometry(QRect(530, 340, 91, 41));
    spinBox_6 = new QSpinBox(this);
    spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
    spinBox_6->setGeometry(QRect(330, 340, 91, 41));
    comboBox = new QComboBox(this);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setGeometry(QRect(30, 70, 131, 52));
    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(30, 40, 71, 18));
    pushButton_7 = new QPushButton(this);
    pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
    pushButton_7->setGeometry(QRect(30, 130, 131, 34));
    pushButton_8 = new QPushButton(this);
    pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
    pushButton_8->setGeometry(QRect(30, 170, 131, 34));

        this->setWindowTitle(QCoreApplication::translate("Diceling", "Diceling", nullptr));
        pushButton->setText(QCoreApplication::translate("Diceling", "D4", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Diceling", "D6", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Diceling", "D8", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Diceling", "D10", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Diceling", "D12", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Diceling", "D20", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Diceling", "ROLL DICE", nullptr));

    #if QT_CONFIG(tooltip)
        comboBox->setToolTip(QCoreApplication::translate("Diceling", "<html><head/><body><p>Dice sets is like swapping a baggie of dice for another one.<br/>when your current set of dice just ain't giving you the luck</p><p>you need, just swap to another! Although dice sets are</p><p>randomly generated, you can save a die set in your personal</p><p>box if they brought you good luck.</p><p>saved sets will be marked with a star.<br/><br/>(Disclaimer, all dice are 100% RNG, and sets just change the RNG seed and dice textures.)</p></body></html>", nullptr));
    #endif // QT_CONFIG(tooltip)
    #if QT_CONFIG(whatsthis)
        comboBox->setWhatsThis(QCoreApplication::translate("Diceling", "<html><head/><body><p>Dice sets is like swapping a baggie of dice for another one.<br/>when your current set of dice just ain't giving you the luck</p><p>you need, just swap to another! Although dice sets are</p><p>randomly generated, you can save a die set in your personal</p><p>box if they brought you good luck.<br/><br/>(Disclaimer, all dice are 100% RNG, and sets just change the</p><p>RNG seed and dice textures.)</p></body></html>", nullptr));
    #endif // QT_CONFIG(whatsthis)
        label->setText(QCoreApplication::translate("Diceling", "Dice Set:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("Diceling", "Save Set", nullptr));
    #if QT_CONFIG(tooltip)
        pushButton_8->setToolTip(QCoreApplication::translate("Diceling", "<html><head/><body><p>This button removes a dice set. if this is a previously saved dice set, it will be removed from your saved dice.</p></body></html>", nullptr));
    #endif // QT_CONFIG(tooltip)
        pushButton_8->setText(QCoreApplication::translate("Diceling", "Banish Set", nullptr));
    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QMetaObject::connectSlotsByName(this);

    QFile file(QDir::currentPath()+"/json/adjectives.json");
    file.open(QIODevice::ReadOnly);
    json adjectives = json::parse(file.readAll());
    file.close();

    json arr = json::parse("[\"fire\", \"water\", \"ice\", \"earth\", \"plant\", \"mythical\", \"magical\", \"enchanted\", \"ancient\" ]");
    QRandomGenerator random(67347);
    QRandomGenerator random2(3485348);
    QRandomGenerator random3(4594578);


    for(int i = 0; i < 24; i++){
        std::string adjective = adjectives.at(random.bounded(0,adjectives.size()));
        std::string type = arr.at(random2.bounded(0,9));
        comboBox->addItem(QString(adjective.c_str()) + "\n" + QString(type.c_str()) + " Dice ⭐",random3.generate());
    }



}