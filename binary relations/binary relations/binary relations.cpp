#include <iostream>

using namespace std;

int symmetry1 = 0, reflexivity1 = 0, transitivity1 = 0, antisymmetry1 = 0;

void symmetry(int** a, int n)
{
	int not_symmetry1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] != a[j][i])
				not_symmetry1++;

		}
	}
	if (not_symmetry1 == 0 ) cout << "отношение симметрично" << endl;
	symmetry1++;
}

void antisymmetry(int** a, int n)
{
	int not_antisymmetry1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == -a[j][i])
					not_antisymmetry1++;

		}
	}
	if (not_antisymmetry1 > 0) {
		cout << "отношение антисимметрично" << endl;
		antisymmetry1++;
	}
}

void reflexivity(int** a, int n)
{
	int chek = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][i] == 1)
			chek++;
	}
	if (chek == n) {
		cout << "отношение рефлексивно" << endl;
		reflexivity1++;
	}
}

void transitivity(int** a, int n)
{
	int chek = 0;
	int not_transitivity1 = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j])
			{
				for (int k = 0; k < n; k++)
				{
					if (a[j][k] && !a[i][k])
					{
						not_transitivity1++;
					}
					else
					{
						chek++;
					}
				}

			}


		}

	}
	if (chek == 1) {
		cout << "отношение транзитивно" << endl;
		transitivity1++;
	}
}

void pr_symmetry(int** a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == 1)
				a[j][i] = 1;
}

void pr_reflexivity(int** a, int n)
{
	for (int i = 0; i < n; i++)
		a[i][i] = 1;
}

void pr_transitivity(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (a[j][k] == 1)
				{
					for (int p = 0; p < n; p++)
					{
						if (a[k][p] == 1)
							a[j][p] = 1;
					}
				}
			}
		}
	}
}

void pr(int** a, int n, int number)
{
	int** a1;
	a1 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a1[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			a1[i][j] = a[i][j];
		}
	}
	if (number == 1)
	{
		pr_symmetry(a1, n);
		cout << "замыкание симметричности" << endl;
	}
	if (number == 2)
	{
		pr_reflexivity(a1, n);
		cout << "замыкание рефлексивности" << endl;
	}
	if (number == 3)
	{
		pr_transitivity(a1, n);
		cout << "замыкание транзитивности" << endl;
	}
	if (number == 4)
	{
		pr_symmetry(a1, n);
		pr_reflexivity(a1, n);
		pr_transitivity(a1, n);
		cout << "замыкание эквивалентности" << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a1[i][j] << ' ';
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	cout << "n=";
	cin >> n;
	int** a;
	a = new int* [n];
	cout << "Введите матрицу \n";
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	symmetry(a, n);
	reflexivity(a, n);
	transitivity(a, n);
	antisymmetry(a, n);

	if (symmetry1 == 1 && reflexivity1 == 1 && transitivity1 == 1)
		cout << "Отношение является отношением эквивалентности" << endl;
	if (reflexivity1 == 1 && transitivity1 == 1)
		cout << "Отношение является отношением квазипорядка" << endl;
	if (symmetry1 == 0 && reflexivity1 == 1 && transitivity1 == 1)
		cout << "Отношение является отношением частичного порядка" << endl;
	pr(a, n, 1);
	pr(a, n, 2);
	pr(a, n, 3);
	pr(a, n, 4);

	return 0;
}