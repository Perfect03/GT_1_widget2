#ifndef WIN_H
#define WIN_H

#include <QBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class Counter : public QLineEdit
{
	Q_OBJECT

public:
	Counter(const QString &contents, QWidget *parent = nullptr) : QLineEdit(contents, parent) {}

signals:
	void tick_signal(); // сигнал, вызываемый при счете, кратном пяти

public slots:
	void add_one()
	{
		QString str = text();
        int r = str.toInt(); // перевод введенного числа (строки) в int

        if (r != 0 && r % 5 == 0) // сигнал вызывается, если число кратно 5
		{
			emit tick_signal();
		}

        r++; // и в графе "счёт по 5" прибавляется единица

		str.setNum(r);
        setText(str); // вывод результата
	}
};

class Win : public QWidget
{
	Q_OBJECT

protected:
    QLabel *label1, *label2; // надписи
    Counter *edit1, *edit2; // числа
    QPushButton *calcbutton; // кнопки
	QPushButton *exitbutton;

public:
    Win(QWidget *parent = nullptr); // окно
};

#endif // WIN_H
