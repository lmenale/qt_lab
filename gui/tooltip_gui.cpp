#include <QApplication>
#include <QWidget>

int test_tooltip(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget window;

    window.resize(300, 150);
    window.move(300, 300);
    window.setWindowTitle("ToolTip");
    window.setToolTip("QWidget");
    window.show();

    return app.exec();
}
