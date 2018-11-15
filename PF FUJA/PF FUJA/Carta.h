#ifndef _Carta
#define _Carta
#include<time.h>

class Carta
{
public:
	int valor;
	char tipo;

	Carta()
	{
		valor = rand() % 13 + 1;

		switch (rand() % 4 + 1)
		{
		case 1:
			tipo = 'C'; //corazon
			break;
		case 2:
			tipo = 'D'; //diamante
			break;
		case 3:
			tipo = 'T'; //trebol
			break;
		case 4:
			tipo = 'P'; //pica
			break;
		}
	}

	void reasignar()
	{
		valor = rand() % 13 + 1;

		switch (rand() % 4 + 1)
		{
		case 1:
			tipo = 'C'; //corazon
			break;
		case 2:
			tipo = 'D'; //diamante
			break;
		case 3:
			tipo = 'T'; //trebol
			break;
		case 4:
			tipo = 'P'; //pica
			break;
		}
	}

	void repetidas(Carta arr[10])
	{
		bool repetida;
		do
		{
			repetida = false;
			for (int c = 0; c < 10; c++)
				for (int cs = 0; cs < 10; cs++)
				{
					if (c != cs && arr[c].valor == arr[cs].valor && arr[c].tipo == arr[cs].tipo)
					{
						repetida = true;

						arr[c].valor = rand() % 13 + 1;

						switch (rand() % 4 + 1)
						{
						case 1:
							arr[c].tipo = 'C'; //corazon
							break;
						case 2:
							arr[c].tipo = 'D'; //diamante
							break;
						case 3:
							arr[c].tipo = 'T'; //trebol
							break;
						case 4:
							arr[c].tipo = 'P'; //pica
							break;
						}
					}
				}
		} while (repetida == true);
	}

	void cambiar(Carta arr[10], int c)
	{
		valor = rand() % 13 + 1;

		switch (rand() % 4 + 1)
		{
		case 1:
			tipo = 'C'; //corazon
			break;
		case 2:
			tipo = 'D'; //diamante
			break;
		case 3:
			tipo = 'T'; //trebol
			break;
		case 4:
			tipo = 'P'; //pica
			break;
		}
		bool repetida;
		do
		{
			repetida = false;
			for (int cs = 0; cs < 10; cs++)
			{
				if (c != cs && valor == arr[cs].valor && tipo == arr[cs].tipo)
				{
					repetida = true;

					valor = rand() % 13 + 1;

					switch (rand() % 4 + 1)
					{
					case 1:
						tipo = 'C'; //corazon
						break;
					case 2:
						tipo = 'D'; //diamante
						break;
					case 3:
						tipo = 'T'; //trebol
						break;
					case 4:
						tipo = 'P'; //pica
						break;
					}
				}
			}
		} while (repetida == true);
	}

	void combinacion(Carta arr[10], int pi, int pf, int com[6])
	{
		com[0] = 0;
		com[1] = 0;
		com[2] = 0;
		com[3] = 0;
		com[4] = 0;
		com[5] = 0;
		//sacar la carta mayor
		int mayor[5];
		for (int c = pi; c <= pf; c++)
		{
			if (arr[c].valor > mayor[0])
				mayor[0] = arr[c].valor;
		}
		//sacar combinaciones
		int mismovalor = 0, mismotipo = 0, secuencial = 0, copym = mayor[0], par1 = 0, par2 = 0, ter = 0, pok = 0, full = 0, esc = 0;
		char tip = 0;
		for (int c = pi; c <= pf; c++)
		{
			mismovalor = 0;
			mismotipo = 0;
			for (int cs = pi; cs <= pf; cs++)
			{
				if (c != cs && arr[c].valor == arr[cs].valor)
					mismovalor += 1;
				if (c != cs && arr[c].tipo == arr[cs].tipo)
					mismotipo += 1;
				if (arr[cs].valor == copym - 1)
				{
					secuencial += 1;
					copym -= 1;
				}
			}
			if (mismovalor == 1 && par1 == 0)
				par1 = arr[c].valor;
			if (mismovalor == 1 && par1 != arr[c].valor && par2 == 0)
				par2 = arr[c].valor;
			if (mismovalor == 2)
				ter = arr[c].valor;
			if (mismovalor == 3)
				pok = arr[c].valor;
			if (ter != 0 && par1 != 0)
				full = 1;
			if (mismotipo == 4)
				tip = arr[c].tipo;
			if (secuencial == 4)
				esc = 1;
			if (secuencial == 4 && tip != 0)
				esc = 2;
			if (secuencial == 4 && tip != 0 && mayor[0] == 13)
				esc = 3;
		}
		//sacar las otras cartas mayores
		if (pok == 0 && ter == 0 && par1 == 0 && par2 == 0 && full == 0)
		{
			for (int c = pi; c <= pf; c++)
			{
				if (arr[c].valor > mayor[1] && arr[c].valor != mayor[0])
					mayor[1] = arr[c].valor;
			}
			for (int c = pi; c <= pf; c++)
			{
				if (arr[c].valor > mayor[2] && arr[c].valor != mayor[0] && arr[c].valor != mayor[1])
					mayor[2] = arr[c].valor;
			}
			for (int c = pi; c <= pf; c++)
			{
				if (arr[c].valor > mayor[3] && arr[c].valor != mayor[0] && arr[c].valor != mayor[1] && arr[c].valor != mayor[2])
					mayor[3] = arr[c].valor;
			}
			for (int c = pi; c <= pf; c++)
			{
				if (arr[c].valor > mayor[4] && arr[c].valor != mayor[0] && arr[c].valor != mayor[1] && arr[c].valor != mayor[2] && arr[c].valor != mayor[3])
					mayor[4] = arr[c].valor;
			}
		}
		else if (pok != 0)
		{
			if (mayor[0] > pok)
			{
				mayor[1] = pok;
				mayor[2] = pok;
				mayor[3] = pok;
				mayor[4] = pok;
			}
			else if (mayor[0] == pok)
			{
				mayor[1] = pok;
				mayor[2] = pok;
				mayor[3] = pok;
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor != pok)
						mayor[4] = arr[c].valor;
				}
			}
		}
		else if (full == 1)
		{
			if (mayor[0] == ter)
			{
				mayor[1] = ter;
				mayor[2] = ter;
				mayor[3] = par1;
				mayor[4] = par1;
			}
			else if (mayor[0] == par1)
			{
				mayor[1] = par1;
				mayor[2] = ter;
				mayor[3] = ter;
				mayor[4] = ter;
			}
		}
		else if (ter != 0 && full == 0)
		{
			if (mayor[0] == ter)
			{
				mayor[1] = ter;
				mayor[2] = ter;
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor != ter && arr[c].valor > mayor[3])
						mayor[3] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor != ter && arr[c].valor > mayor[4] && arr[c].valor != mayor[3])
						mayor[4] = arr[c].valor;
				}
			}
			else if (mayor[0] > ter)
			{
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[1] && arr[c].valor != mayor[0])
						mayor[1] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[2] && arr[c].valor != mayor[0])
					{
						if (arr[c].valor == ter)
							mayor[2] = arr[c].valor;
					}
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[3] && arr[c].valor != mayor[0])
					{
						if (arr[c].valor == ter)
							mayor[3] = arr[c].valor;
					}
				}
				if (mayor[1] == mayor[2] && mayor[1] == mayor[3])
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[4] && arr[c].valor != ter && arr[c].valor != mayor[0])
							mayor[4] = arr[c].valor;
					}
				}
				else if (mayor[1] != mayor[2] || mayor[1] != mayor[3])
					mayor[4] = mayor[3];
			}
		}
		else if (par2 != 0)
		{
			if (mayor[0] == par2)
			{
				mayor[1] = par2;
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[2] && arr[c].valor != par2)
						mayor[2] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[3] && arr[c].valor != par2)
					{
						if (arr[c].valor == par1)
							mayor[3] = arr[c].valor;
						if (arr[c].valor != par1 && arr[c].valor != mayor[2])
							mayor[3] = arr[c].valor;
					}
				}
				if (mayor[2] == mayor[3])
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[4] && arr[c].valor != par2 && arr[c].valor != par1 && arr[c].valor != mayor[0])
							mayor[4] = arr[c].valor;
					}
				}
				else if (mayor[2] != mayor[3])
					mayor[4] = mayor[3];
			}
			else if (mayor[0] == par1)
			{
				mayor[1] = par1;
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[2] && arr[c].valor != par1)
						mayor[2] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[3] && arr[c].valor != par1)
					{
						if (arr[c].valor == par2)
							mayor[3] = arr[c].valor;
						if (arr[c].valor != par2 && arr[c].valor != mayor[2])
							mayor[3] = arr[c].valor;
					}
				}
				if (mayor[2] == mayor[3])
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[4] && arr[c].valor != par2 && arr[c].valor != par1 && arr[c].valor != mayor[0])
							mayor[4] = arr[c].valor;
					}
				}
				else if (mayor[2] != mayor[3])
					mayor[4] = mayor[3];
			}
			else if (mayor[0] != par1 && mayor[0] != par2)
			{
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[1] && arr[c].valor != mayor[0])
						mayor[1] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[2] && arr[c].valor != mayor[0])
						mayor[2] = arr[c].valor;
				}
				if (mayor[1] == par1 && mayor[2] == par1)
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[3] && arr[c].valor != par1 && arr[c].valor != mayor[0])
						{
							mayor[3] = arr[c].valor;
							mayor[4] = arr[c].valor;
						}
					}
				}
				else if (mayor[1] == par2 && mayor[2] == par2)
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[3] && arr[c].valor != par2 && arr[c].valor != mayor[0])
						{
							mayor[3] = arr[c].valor;
							mayor[4] = arr[c].valor;
						}
					}
				}
			}
		}
		else if (par1 != 0 && par2 == 0 && full == 0)
		{
			if (mayor[0] == par1)
			{
				mayor[1] = par1;
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[2] && arr[c].valor != par1)
						mayor[2] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[3] && arr[c].valor != par1 && arr[c].valor != mayor[2])
						mayor[3] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[4] && arr[c].valor != par1 && arr[c].valor != mayor[2] && arr[c].valor != mayor[3])
						mayor[4] = arr[c].valor;
				}
			}
			else if (mayor[0] > par1)
			{
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[1] && arr[c].valor != mayor[0])
						mayor[1] = arr[c].valor;
				}
				for (int c = pi; c <= pf; c++)
				{
					if (arr[c].valor > mayor[2] && arr[c].valor != mayor[0])
					{
						if (arr[c].valor == par1)
							mayor[2] = arr[c].valor;
						if (arr[c].valor != par1 && arr[c].valor != mayor[1])
							mayor[2] = arr[c].valor;
					}
				}
				if (mayor[1] == mayor[2])
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[3] && arr[c].valor != par1 && arr[c].valor != mayor[0])
							mayor[3] = arr[c].valor;
					}
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[4] && arr[c].valor != par1 && arr[c].valor != mayor[3] && arr[c].valor != mayor[0])
							mayor[4] = arr[c].valor;
					}
				}
				else if (mayor[1] != mayor[2])
				{
					for (int c = pi; c <= pf; c++)
					{
						if (arr[c].valor > mayor[3] && arr[c].valor != mayor[0] && arr[c].valor != mayor[1])
						{
							if (arr[c].valor == par1)
								mayor[3] = arr[c].valor;
							if (arr[c].valor != par1 && arr[c].valor != mayor[2])
								mayor[3] = arr[c].valor;
						}
					}
					if (mayor[2] == mayor[3])
					{
						for (int c = pi; c <= pf; c++)
						{
							if (arr[c].valor > mayor[4] && arr[c].valor != par1 && arr[c].valor != mayor[0] && arr[c].valor != mayor[1])
								mayor[4] = arr[c].valor;
						}
					}
					else if (mayor[2] != mayor[3])
						mayor[4] = mayor[3];
				}
			}
		}
		//checar si la mano es la escalera menor ahora que ya se saben las cartas de mayor a menor
		if (mayor[0] == 13 && mayor[1] == 4 && mayor[2] == 3 && mayor[3] == 2 && mayor[4] == 1)
			esc = 1;
		//mostrar combinacion mas alta
		if (esc == 3)
		{
			//cout << "Escalera real de color " << tip << "." << endl;
			com[0] = 10;
		}
		else if (esc == 2)
		{
			//cout << "Escalera de color " << tip << " con la carta mayor " << mayor[0] << "." << endl;
			com[0] = 9;
			com[1] = mayor[0];
		}
		else if (pok != 0)
		{
			//cout << "Poker de " << pok << "." << endl;
			com[0] = 8;
			com[1] = pok;
		}
		else if (full == 1)
		{
			//cout << "Full con tercia de " << ter << " y par de " << par1 << "." << endl;
			com[0] = 7;
			com[1] = ter;
		}
		else if (tip != 0 && esc == 0)
		{
			//cout << "Color de " << tip << ". Las cartas de mayor a menor son: " << endl << mayor[0] << endl << mayor[1] << endl << mayor[2] << endl << mayor[3] << endl << mayor[4] << endl;
			com[0] = 6;
			com[1] = mayor[0];
			com[2] = mayor[1];
			com[3] = mayor[2];
			com[4] = mayor[3];
			com[5] = mayor[4];
		}
		else if (esc == 1)
		{
			//cout << "Escalera con la carta mayor " << mayor[0] << "." << endl;
			com[0] = 5;
			if (mayor[0] == 13 && mayor[1] == 4 && mayor[2] == 3 && mayor[3] == 2 && mayor[4] == 1)
				com[1] = mayor[1];
			else
				com[1] = mayor[0];
		}
		else if (ter != 0 && full == 0)
		{
			//cout << "Tercia de " << ter << "." << endl;
			com[0] = 4;
			com[1] = ter;
		}
		else if (par2 != 0)
		{
			//cout << "Pares de " << par1 << " y " << par2 << "." << " La carta restante es ";
			com[0] = 3;
			if (par1 > par2)
			{
				com[1] = par1;
				com[2] = par2;
			}
			else if (par1 < par2)
			{
				com[1] = par2;
				com[2] = par1;
			}
			int ic = 0;
			while (com[3] == 0)
			{
				if (mayor[ic] != par1 && mayor[ic] != par2)
					com[3] = mayor[ic];
				else
					ic++;
			}
			//cout << com[3] << endl;
		}
		else if (par1 != 0 && par2 == 0 && full == 0)
		{
			//cout << "Par de " << par1 << ". Las demas cartas de mayor a menor son:" << endl;
			com[0] = 2;
			com[1] = par1;
			int ic = 0;
			while (com[2] == 0)
			{
				if (mayor[ic] != par1)
					com[2] = mayor[ic];
				else
					ic++;
			}
			ic = 0;
			while (com[3] == 0)
			{
				if (mayor[ic] != par1 && mayor[ic] != com[2])
					com[3] = mayor[ic];
				else
					ic++;
			}
			ic = 0;
			while (com[4] == 0)
			{
				if (mayor[ic] != par1 && mayor[ic] != com[2] && mayor[ic] != com[3])
					com[4] = mayor[ic];
				else
					ic++;
			}
			//cout << com[2] << endl << com[3] << endl << com[4] << endl;
		}
		else if (pok == 0 && ter == 0 && par1 == 0 && par2 == 0 && tip == 0 && full == 0 && esc == 0)
		{
			// << "No hay combinacion. Las cartas de mayor a menor son:" << endl << mayor[0] << endl << mayor[1] << endl << mayor[2] << endl << mayor[3] << endl << mayor[4] << endl;
			com[0] = 1;
			com[1] = mayor[0];
			com[2] = mayor[1];
			com[3] = mayor[2];
			com[4] = mayor[3];
			com[5] = mayor[4];
		}
	}

	void IA(Carta arr[10], int comC[6])
	{
		arr[0].combinacion(arr, 5, 9, comC);
		//system("PAUSE");
		//system("CLS");
		//if (comC[0] > 4)
			//cout << "La computadora no cambio carta(s)." << endl;
		//else 
		if (comC[0] == 4)
		{
			//cout << "La computadora tiene una tercia." << endl;
			int ic = 5;
			while (arr[ic].valor == comC[1])
				ic++;
			int x = 4;
			while (arr[ic].valor != comC[1] && x != 0)
			{
				arr[ic].cambiar(arr, ic);
				x--;
			}
			//cout << "La computadora cambio carta(s)." << endl;
		}
		else if (comC[0] == 3)
		{
			//cout << "La computadora tiene 2 pares." << endl;
			int ic = 5;
			while (arr[ic].valor != comC[3])
				ic++;
			int x = 4;
			while (arr[ic].valor != comC[1] && arr[ic].valor != comC[2] && x != 0)
			{
				arr[ic].cambiar(arr, ic);
				x--;
			}
			//cout << "La computadora cambio carta(s)." << endl;
		}
		else if (comC[0] == 2)
		{
			//cout << "La computadora tiene 1 par." << endl;
			int ic = 5, x = 4;
			while (x != 0)
			{
				while (arr[ic].valor == comC[1])
					ic++;

				while (arr[ic].valor != comC[1] && x != 0)
				{
					arr[ic].cambiar(arr, ic);
					x--;
				}
			}
			//cout << "La computadora cambio carta(s)." << endl;
		}
		else if (comC[0] == 1)
		{
			//cout << "La computadora no tiene combinaciones." << endl;
			int ic = 5, x = 4;
			while (x != 0)
			{
				while (arr[ic].valor == comC[1])
					ic++;

				while (arr[ic].valor != comC[1] && x != 0)
				{
					arr[ic].cambiar(arr, ic);
					x--;
				}
			}
			//cout << "La computadora cambio carta(s)." << endl;
		}
	}

};

#endif 