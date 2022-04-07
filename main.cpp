#include "win.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    Win w; // окно с приложением
    w.show(); // показ окна с приложением
    return a.exec(); // запуск цикла обработки сообщений приложения
}
