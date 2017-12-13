#include "simplemenu.h"

int test_menu(int argc, char *argv[]) {

    QApplication app(argc, argv);

    SimpleMenu window;

    window.resize(300, 150);
    window.setWindowTitle("Simple menu");
    window.show();

    return app.exec();
}
