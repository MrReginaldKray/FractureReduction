#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argv, char** argc)
{
	int zaehler, nenner;

	
	do
	{
		zaehler = 0;
		nenner = 0;

		printf_s(":::::::::::::::::::: Bruch kuerzen ::::::::::::::::::::\n\n");

		printf_s("Bitte geben Sie den Zaehler ein: ");
		scanf_s("%d", &zaehler);
		printf_s("Bitte geben Sie den Nenner ein: ");
		scanf_s("%d", &nenner);

		printf_s("%d / %d", zaehler, nenner);

		//Falls der zaehler oder nenner gleich 0 sind dann ist das Ergebnis automatisch auch 0
		if (zaehler == 0 || nenner == 0)
		{
			printf_s(" = 0\n\n");
		}
		//Der größte gemeinsame Teiler kann max so groß sein wie die kleinere Zahl (zaehler oder nenner)
		else if (zaehler > nenner)
		{
			//Der nenner ist die kleinere Zahl
			//int i = 2 weil durch 0 nicht teilbar ist und durch 1 jede Zahl teilbar ist
			for (int i = 2; i <= nenner; i++)
			{
				//Falls zaehler und nenner restlos durch i teilbar sind dann sollen sie gekürzt werden durch i
				if (nenner % i == 0 && zaehler % i == 0)
				{
					//nenner und zaehler werden durch i gekürzt und wieder in zaehler und nenner gespeichert
					nenner = nenner / i;
					zaehler = zaehler / i;
				}
			}

			printf_s(" = %d / %d\n\n", zaehler, nenner);
		}
		else if (zaehler < nenner)
		{
			//Der zaehler ist die kleinere Zahl
			//int i = 2 weil durch 0 nicht teilbar ist und durch 1 jede Zahl teilbar ist
			for (int i = 2; i <= zaehler; i++)
			{
				//Falls zaehler und nenner restlos durch i teilbar sind dann sollen sie gekürzt werden durch i
				if (zaehler % i == 0 && nenner % i == 0)
				{
					//nenner und zaehler werden durch i gekürzt und wieder in zaehler und nenner gespeichert
					zaehler = zaehler / i;
					nenner = nenner / i;
				}
			}

			printf_s(" = %d / %d\n\n", zaehler, nenner);
		}
		else
		{
			//zaehler und nenner sind gleich somit ist das Ergebnis 1
			printf_s(" = 1\n\n");
		}

		system("pause");
		system("cls");

	} while (1);


	return 0;
}