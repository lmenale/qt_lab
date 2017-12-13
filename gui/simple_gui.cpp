#include <QApplication>
#include <QWidget>

int test_simple(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget window;

    window.resize(300, 150);
    window.setWindowTitle("Simple example");
    window.show();

    return app.exec();
}
