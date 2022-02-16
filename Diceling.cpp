#include <QApplication>
#include <QCommonStyle>
#include <QStyleFactory>
#include <QFile>
#include <QTextStream>
#include "dialogs/DicelingMainWindow.h"

int main( int argc, char **argv )
{
    QApplication app(argc,argv);

//    QCommonStyle *style = (QCommonStyle *)QStyleFactory::create( "fusion" );
//    app.setStyle( style );
    QFile file(":/dark/stylesheet.qss");
    file.open(QFile::ReadOnly | QFile::Text);
    QTextStream stream(&file);
    app.setStyleSheet(stream.readAll());

    QPalette palette = QPalette();
        palette.setColor( QPalette::Window, QColor( 49, 54, 59 ) );
        palette.setColor( QPalette::WindowText, Qt::white );
        palette.setColor( QPalette::Base, QColor( 49/2, 54/2, 59/2 ) );
        palette.setColor( QPalette::AlternateBase, QColor( 27, 30, 32 ) );
        palette.setColor( QPalette::ToolTipBase, Qt::black );
        palette.setColor( QPalette::ToolTipText, Qt::white );
        palette.setColor( QPalette::Mid, Qt::white );
        palette.setColor( QPalette::Text, Qt::white );
        palette.setColor( QPalette::Button, QColor( 49, 54, 59 ) );
        palette.setColor( QPalette::ButtonText, Qt::white );
        palette.setColor( QPalette::BrightText, Qt::red );
        palette.setColor( QPalette::Link, QColor( 42, 130, 218 ) );
        palette.setColor( QPalette::Highlight, QColor( 42, 130, 218 ) );
        palette.setColor( QPalette::HighlightedText, Qt::black );
        palette.setColor( QPalette::Active, QPalette::Button, QColor( 49, 54, 59 ) );
        palette.setColor( QPalette::Disabled, QPalette::ButtonText, Qt::darkGray );
        palette.setColor( QPalette::Disabled, QPalette::WindowText, Qt::darkGray );
        palette.setColor( QPalette::Disabled, QPalette::Text, Qt::darkGray );
        palette.setColor( QPalette::Disabled, QPalette::Light, QColor( 49, 54, 59 ) );
    app.setPalette(palette);

    auto pZoo = new ui::CDicelingMainWindow( nullptr );
    pZoo->setAttribute( Qt::WA_DeleteOnClose );
    pZoo->show();

    return QApplication::exec();
}
