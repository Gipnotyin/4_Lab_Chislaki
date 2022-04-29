#include <iostream>

using namespace std;
//cos(y+0.5)-x=1
//cos(x-2)+y=0

int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0;
	//переменные для метода Ньютона
	double det, dety, detx, x0, y0, x = -1.0, y = 1.0, n1, n2, A, B, C, D;
	//переменные для метода простых итераций
	double xi0, yi0, xi = -1.0, yi = 1.0;
	double k;
	char s;
	cout << "Какой метод хотите проверить?(i, N)\n";
	cin >> s;
	switch (s)
	{
	case 'N':
		//метод Ньютона
		do
		{
			cout << "Введите точность: ";
			cin >> k;
			x0 = x;
			y0 = y;
			n1 = cos(y0 + 0.5) - x0 - 1;
			n2 = cos(x0 - 2) + y;
			//Находим производные по y и x;
			A = -1; //производная n1 по x
			B = -sin(y0 + 0.5); //производная n1 по y
			C = -sin(x0 - 2); //производная n2 по x
			D = 1; //производная n2 по y
			//находим определитель матрицы
			det = A * D - B * C;
			if (det == 0)
			{
				cout << "Ошибка, det не может быть равен нулю!";
				break;
			}
			detx = D * (-n1) - B * (-n2);
			dety = C * n1 - A * n2;
			//находим x и y
			x = x0 + (detx / det);
			y = y0 + (dety / det);
			i++;
		} while ((abs(y - y0) < k) or (abs(x - x0) < k));
		cout << "Ответ: x = " << x << endl << "y = " << y << endl;
		cout << "Количество итераций: " << i << endl;
		break;
	case 'i':
		//Метод простых итераций
		i = 0;
		cout << "Введите точность: ";
		cin >> k;
		do
		{
			i++;
			xi0 = xi;
			yi0 = yi;
			xi = cos(yi0 + 0.5) - 1;
			yi = -cos(xi0 - 2);

		} while ((fabs(yi - yi0) < k) || (fabs(xi - xi0) < k));
		cout << "Ответ: x = " << xi << endl << "y = " << yi << endl;
		cout << "Количество итераций: " << i << endl;
		break;
	}
}