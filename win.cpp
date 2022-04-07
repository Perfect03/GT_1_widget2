#include "win.h"

Win::Win(QWidget *parent)
	: QWidget(parent)
{
    setWindowTitle("Счетчик"); // заголовок окна

    label1 = new QLabel("Cчет по 1", this); // надписи "Счет по 1" и "Счет по 5"
	label2 = new QLabel("Cчет по 5", this);
    edit1 = new Counter("0", this); // результаты
	edit2 = new Counter("0", this);
    calcbutton = new QPushButton("+1", this); // кнопки
	exitbutton = new QPushButton("Выход", this);

    QHBoxLayout *layout1 = new QHBoxLayout(); // горизонтальный менеджер компоновки для надписей
	layout1->addWidget(label1);
	layout1->addWidget(label2);

    QHBoxLayout *layout2 = new QHBoxLayout(); // горизонтальный менеджер компоновки для числовых полей
	layout2->addWidget(edit1);
	layout2->addWidget(edit2);

    QHBoxLayout *layout3 = new QHBoxLayout(); // горизонтальный менеджер компоновки для кнопок
	layout3->addWidget(calcbutton);
	layout3->addWidget(exitbutton);

    QVBoxLayout *layout4 = new QVBoxLayout(this); // вертикальный менеджер компоновки для трёх вышеупомянутых строк
	layout4->addLayout(layout1);
	layout4->addLayout(layout2);
	layout4->addLayout(layout3);

	// связь сигнала нажатия кнопки и слота закрытия окна
	connect(calcbutton, &QPushButton::clicked, edit1, &Counter::add_one);
	connect(edit1, &Counter::tick_signal, edit2, &Counter::add_one);
	connect(exitbutton, &QPushButton::clicked, this, &Win::close);
}
