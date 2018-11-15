#ifndef __Escena
#define __Escena

#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terreno.h"
#include "Model.h"
#include "Carta.h"

class Camara
{
public:
	GLdouble px, py, pz, dx, dy, dz, ux, uy, uz;
	int camind = 2;
	bool freeze = false, DIE = false, WIN = false;

	Camara()
	{
	}

	void CamaraI()
	{
		px = 0, py = 24, pz = -50, dx = 0, dy = 19, dz = -24, ux = 0, uy = 1, uz = 0;
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
	}

	void CamaraU()
	{
		gluLookAt(px, py, pz, dx, dy, dz, ux, uy, uz);
	}

	void MoverDerecha()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio
		if (pz >= -50 && pz <= -40 && px > -3)
		{
			px -= 1;
			dx -= 1;
		}
		//escaleras gigantes
		else if (pz >= -39 && pz <= 60 && px > -9)
		{
			px -= 1;
			dx -= 1;
		}// entre las mini escaleras
		else if (pz >= 60 && pz <= 81 && px > -3)
		{
			px -= 1;
			dx -= 1;
		}//area antes de la entrada principal
		else if (pz >= 81 && pz <= 92 && px > -30)
		{
			px -= 1;
			dx -= 1;
		}
		//entrada principal
		else if (pz >= 92 && pz <= 131 && px > -6 && py < 87)
		{
			px -= 1;
			dx -= 1;
		}
		//salon principal 1
		else if (pz >= 131 && pz <= 235 && px > -6 && py < 62)
		{
			px -= 1;
			dx -= 1;
		}
		//salon principal 2
		else if (pz >= 235 && pz <= 243 && px > -27 && py < 62)
		{
			px -= 1;
			dx -= 1;
		}
		//salon principal 3
		else if (pz >= 243 && pz <= 274 && px > -6 && py < 62)
		{
			px -= 1;
			dx -= 1;
		}
		//entrada al jefe
		else if (pz >= 274 && pz <= 320 && px > -6 && px < 31)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 1
		else if (pz >= 192 && pz <= 234 && px > 23 && px < 31 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 1
		else if (pz >= 192 && pz <= 234 && px < -22 && px > -27 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 2
		else if (pz >= 192 && pz <= 204 && px <= 31 && px >= 27 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 2
		else if (pz >= 192 && pz <= 274 && py >= 73 && px > -35 && px < 23 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 3
		else if (pz >= 192 && pz <= 274 && px > 31 && px < 40 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 3
		else if (pz >= 235 && pz <= 274 && py >= 87 && px > -43 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 4
		else if (pz >= 235 && pz <= 274 && py >= 87 && px > 35 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere der 4
		else if (pz >= 131 && pz <= 235 && py >= 87 && px > -43 && px < -1)
		{
			px -= 1;
			dx -= 1;
		}
		//escalere izq 5
		else if (pz >= 131 && pz <= 235 && py >= 87 && px > 40 && px > 1)
		{
			px -= 1;
			dx -= 1;
		}
	}

	void MoverIzquierda()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio
		if (pz >= -50 && pz <= -40 && px < 3)
		{
			px += 1;
			dx += 1;
		}
		//escalera gigante
		else if (pz >= -39 && pz <= 60 && px < 9)
		{
			px += 1;
			dx += 1;
		}
		//entre las mini escaleras
		else if (pz >= 60 && pz <= 81 && px < 3)
		{
			px += 1;
			dx += 1;
		}
		//area antes de la entrada principal
		else if (pz >= 81 && pz <= 92 && px < 30)
		{
			px += 1;
			dx += 1;
		}
		//entrada principal
		else if (pz >= 92 && pz <= 131 && px < 6 && py < 87)
		{
			px += 1;
			dx += 1;
		}
		//salon principal 1
		else if (pz >= 131 && pz <= 235 && px < 6 && py < 62)
		{
			px += 1;
			dx += 1;
		}
		//salon principal 2
		else if (pz >= 235 && pz <= 243 && px < 27 && py < 62)
		{
			px += 1;
			dx += 1;
		}
		//salon principal 3
		else if (pz >= 243 && pz <= 274 && px < 6 && py < 62)
		{
			px += 1;
			dx += 1;
		}
		//entrada al jefe
		else if (pz >= 274 && pz <= 320 && px < 6)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 1
		else if (pz >= 192 && pz <= 234 && px < 27 && px > 22 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 1
		else if (pz >= 192 && pz <= 234 && px < -23 && px > -31 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 2
		else if (pz >= 192 && pz <= 274 && py >= 73 && px < 35 && px > -23 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 2
		else if (pz >= 192 && pz <= 204 && px >= -31 && px <= -27 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 3
		else if (pz >= 235 && pz <= 274 && py >= 87 && px < 43 && px > 1 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 3
		else if (pz >= 192 && pz <= 274 && px < -31 && px > -40 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere izq 4
		else if (pz >= 131 && pz <= 235 && py >= 87 && px < 43 && px > 1 && px > 1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 4
		else if (pz >= 235 && pz <= 274 && py >= 87 && px < -35 && px < -1)
		{
			px += 1;
			dx += 1;
		}
		//escalere der 5
		else if (pz >= 131 && pz <= 235 && py >= 87 && px < -40 && px < -1)
		{
			px += 1;
			dx += 1;
		}
	}

	void MoverAdelante()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio
		if (pz >= -50 && pz < -39 && px <= 3 && px >= -3)
		{
			pz += 1;
			dz += 1;
		}
		//entre inicio y escaleras gigante
		if (pz >= -39 && pz < 5 && px <= 9 && px >= -9)
		{
			pz += 1;
			dz += 1;
		}
		//escalera gigante
		else if (pz >= 5 && pz < 60 && px <= 9 && px >= -9)
		{
			if (py < 54)
			{
				py += 0.6;
				dy += 0.6;
			}
			pz += 1;
			dz += 1;
		}
		//entre las mini escaleras
		else if (pz >= 60 && pz < 81 && px <= 3 && px >= -3)
		{
			pz += 1;
			dz += 1;
		}
		//area antes de la entrada principal
		else if (pz >= 81 && pz < 92 && px <= 30 && px >= -30)
		{
			pz += 1;
			dz += 1;
		}
		//entrada principal
		else if (pz >= 92 && pz < 131 && px <= 6 && px >= -6)
		{
			if (py < 61)
			{
				py += 0.6;
				dy += 0.6;
			}
			pz += 1;
			dz += 1;
		}
		//salon principal 1
		else if (pz >= 131 && pz < 235 && px <= 6 && px >= -6)
		{
			pz += 1;
			dz += 1;
		}
		//salon principal 2
		else if (pz >= 235 && pz < 243 && px <= 27 && px >= -27)
		{
			pz += 1;
			dz += 1;
		}
		//salon principal 3
		else if (pz >= 243 && pz < 274 && px <= 6 && px >= -6)
		{
			pz += 1;
			dz += 1;
		}
		//entrada al jefe
		else if (pz >= 274 && pz < 320 && px <= 6 && px >= -6)
		{
			if (py < 74 && pz >= 291)
			{
				py += 0.55;
				dy += 0.55;
			}
			pz += 1;
			dz += 1;
		}
		//escalera izq 1
		else if (pz >= 192 && pz < 235 && px <= 27 && px >= 23)
		{
			if (py > 61 && pz >= 205)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera der 1
		else if (pz >= 192 && pz < 235 && px >= -27 && px <= -23)
		{
			if (py > 61 && pz >= 205)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera izq 2
		else if (pz >= 192 && pz < 204 && px <= 31 && px >= 27)
		{
			pz += 1;
			dz += 1;
		}
		//escalera der 2
		else if (pz >= 192 && pz < 204 && px >= -31 && px <= -27)
		{
			pz += 1;
			dz += 1;
		}
		//escalera izq 3
		else if (pz >= 192 && pz < 274 && px <= 35 && px >= 31)
		{
			if (py < 87 && pz >= 206)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera der 3
		else if (pz >= 192 && pz < 274 && px >= -35 && px <= -31)
		{
			if (py < 87 && pz >= 206)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz += 1;
			dz += 1;
		}
		//escalera izq 4
		else if (pz >= 235 && pz < 274 && px <= 39 && px >= 36)
		{
			pz += 1;
			dz += 1;
		}
		//escalera der 4
		else if (pz >= 235 && pz < 274 && px >= -39 && px <= -36)
		{
			pz += 1;
			dz += 1;
		}
		//escalera izq 5
		else if (pz >= 131 && pz < 274 && px <= 43 && px >= 40)
		{
			pz += 1;
			dz += 1;
		}
		//escalera izq 5
		else if (pz >= 131 && pz < 274 && px >= -43 && px <= -40)
		{
			pz += 1;
			dz += 1;
		}
	}

	void MoverAtras()
	{
		//debe empezar viendo a z negativa, si no camina al reves, el if es para no salirse del terreno
		//inicio
		if (pz > -50 && pz <= -39 && px <= 3 && px >= -3)
		{
			pz -= 1;
			dz -= 1;
		}
		//entre inicio y escaleras gigantes
		else if (pz > -39 && pz <= 5 && px <= 9 && px >= -9)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera gigante
		if (pz > 5 && pz <= 60 && px <= 9 && px >= -9)
		{
			if (py > 24 && pz <= 55)
			{
				py -= 0.6;
				dy -= 0.6;
			}
			pz -= 1;
			dz -= 1;
		}
		//entre las mini escaleras
		else if (pz > 60 && pz <= 81 && px <= 3 && px >= -3)
		{
			pz -= 1;
			dz -= 1;
		}
		//area antes de la entrada principal
		else if (pz > 81 && pz <= 92 && px <= 30 && px >= -30)
		{
			pz -= 1;
			dz -= 1;
		}
		//entrada principal
		else if (pz > 92 && pz <= 131 && px <= 6 && px >= -6)
		{
			if (py > 54 && pz <= 103)
			{
				py -= 0.6;
				dy -= 0.6;
			}
			pz -= 1;
			dz -= 1;
		}
		//salon principal 1
		else if (pz > 131 && pz <= 235 && px <= 6 && px >= -6)
		{
			pz -= 1;
			dz -= 1;
		}
		//salon principal 2
		else if (pz > 235 && pz <= 243 && px <= 27 && px >= -27)
		{
			pz -= 1;
			dz -= 1;
		}
		//salon principal 1
		else if (pz > 243 && pz <= 274 && px <= 6 && px >= -6)
		{
			pz -= 1;
			dz -= 1;
		}
		//entrada el jefe
		else if (pz > 274 && pz <= 320 && px <= 6 && px >= -6)
		{
			if (py > 61 && pz <= 315)
			{
				py -= 0.55;
				dy -= 0.55;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 1
		else if (pz > 192 && pz <= 235 && px <= 27 && px >= 23)
		{
			if (py < 74 && pz <= 232)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera der 1
		else if (pz > 192 && pz <= 235 && px >= -27 && px <= -23)
		{
			if (py < 74 && pz <= 232)
			{
				py += 0.5;
				dy += 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 2
		else if (pz > 192 && pz <= 274 && px <= 35 && px >= 23)
		{
			if (py > 74 && pz <= 232)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera der 2
		else if (pz > 192 && pz <= 274 && px >= -35 && px <= -23)
		{
			if (py > 74 && pz <= 232)
			{
				py -= 0.5;
				dy -= 0.5;
			}
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 3
		else if (pz > 235 && pz <= 274 && px <= 39 && px >= 36)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera der 3
		else if (pz > 235 && pz <= 274 && px >= -39 && px <= -36)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera izq 4
		else if (pz > 131 && pz <= 274 && px <= 43 && px >= 40)
		{
			pz -= 1;
			dz -= 1;
		}
		//escalera der 4
		else if (pz > 131 && pz <= 274 && px >= -43 && px <= -40)
		{
			pz -= 1;
			dz -= 1;
		}
	}

	void VoltearDerecha()
	{
		//debe empezar viendo a z negativa, si no gira al reves
		if (dx < 15 + px && camind == 0)
			dx += 1;
		if (dx == 15 + px && camind == 0)
			camind = 1;
		if (dz < 15 + pz && camind == 1)
			dz += 1;
		if (dz == 15 + pz && camind == 1)
			camind = 2;
		if (dx > -15 + px && camind == 2)
			dx -= 1;
		if (dx == -15 + px && camind == 2)
			camind = 3;
		if (dz > -15 + pz && camind == 3)
			dz -= 1;
		if (dz == -15 + pz && camind == 3)
			camind = 0;
	}

	void VoltearIzquierda()
	{
		//debe empezar viendo a z negativa, si no gira al reves
		if (dx > -15 + px && camind == 0)
			dx -= 1;
		if (dx == -15 + px && camind == 0)
			camind = 1;
		if (dz < 15 + pz && camind == 1)
			dz += 1;
		if (dz == 15 + pz && camind == 1)
			camind = 2;
		if (dx < 15 + px && camind == 2)
			dx += 1;
		if (dx == 15 + px && camind == 2)
			camind = 3;
		if (dz > -15 + pz && camind == 3)
			dz -= 1;
		if (dz == -15 + pz && camind == 3)
			camind = 0;
	}

	void VoltearArriba()
	{
		if (dy < 30 + py)
		{
			dy += 1;
		}
	}

	void VoltearAbajo()
	{
		if (dy > -90 + py)
		{
			dy -= 1;
		}
	}
};

class Escena : public Camara
{
public:
	
	SkyDome *skydome;
	Terreno *terreno;
	EDXFramework::Model *DS_AL, *DS_BK, *DS_Bonfire, *DS_Card[10], *DS_Card_Ins[20];
	Carta Enjuego[10];
	int Cjug[6], Ccom[6], ncambios = 0, nganar = 0, musica = 0;
	bool cambiar = false, proba = false, showdown = false, enemigo = true, bonfire = true;

	Escena(HWND hWnd)
	{
		GLfloat AmbMat[] = { 1, 1, 1, 1 };
		GLfloat AmbInt[] = { 0.3, 0.3, 0.3, 1 };
		GLfloat AmbPos[] = { 0, 100, 0, 1 };
		//GLfloat DifMat[] = { 1, 1, 1, 1 };
		//GLfloat DifInt[] = { 1, 1, 1, 1 };
		//GLfloat DifPos[] = { 50, 50, 0, 1 };
		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		//glMaterialfv(GL_FRONT, GL_DIFFUSE, DifMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);
		//glEnable(GL_LIGHT1);
		//glLightfv(GL_LIGHT1, GL_DIFFUSE, DifInt);
		//glLightfv(GL_LIGHT1, GL_POSITION, DifPos);
	
		Enjuego[0].repetidas(Enjuego);

		skydome = new SkyDome(hWnd, 32, 32, 400, L"Imagenes//day.jpg");
		terreno = new Terreno(hWnd, L"Imagenes//terreno.jpg", L"Imagenes//Ash.jpg", 500, 300);
		//inicializaBillboards(billBoard, hWnd);
		DS_AL = new EDXFramework::Model("Modelos//DS_AL//DS_AL.obj", "Modelos//DS_AL//DS_AL.bmp", 0);
		DS_BK = new EDXFramework::Model("Modelos//DS_BK//DS_BK.obj", "Modelos//DS_BK//DS_BK.bmp", 0);
		DS_Bonfire = new EDXFramework::Model("Modelos//DS_Bonfire//DS_Bonfire.obj", "Modelos//DS_Bonfire//DS_Bonfire.bmp", 1);
		DS_Card_Ins[0] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins1.bmp", 0);
		DS_Card_Ins[1] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins2.bmp", 0);
		DS_Card_Ins[2] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins3.bmp", 0);
		DS_Card_Ins[3] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins4.bmp", 0);
		DS_Card_Ins[4] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins5.bmp", 0);
		DS_Card_Ins[5] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins6.bmp", 0);
		DS_Card_Ins[6] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins7.bmp", 0);
		DS_Card_Ins[7] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins8.bmp", 0);
		DS_Card_Ins[8] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins9.bmp", 0);
		DS_Card_Ins[9] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins10.bmp", 0);
		DS_Card_Ins[10] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins11.bmp", 0);
		DS_Card_Ins[11] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins12.bmp", 0);
		DS_Card_Ins[12] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins13.bmp", 0);
		DS_Card_Ins[13] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins14.bmp", 0);
		DS_Card_Ins[14] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins15.bmp", 0);
		DS_Card_Ins[15] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins16.bmp", 0);
		DS_Card_Ins[16] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins17.bmp", 0);
		DS_Card_Ins[17] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_Ins18.bmp", 0);
		DS_Card_Ins[18] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_WIN.bmp", 0);
		DS_Card_Ins[19] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_DIE.bmp", 0);
		for (int i = 0; i < 10; i++)
		{	
			cartatex(Enjuego, DS_Card, i);
		}
		CamaraI();
	}

	void cartatex(Carta carta[10], EDXFramework::Model *tex[10], int i)
	{
		if (Enjuego[i].tipo == 'C')
		{
			if (Enjuego[i].valor == 1)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_2C.bmp", 0);
			else if (Enjuego[i].valor == 2)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_3C.bmp", 0);
			else if (Enjuego[i].valor == 3)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_4C.bmp", 0);
			else if (Enjuego[i].valor == 4)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_5C.bmp", 0);
			else if (Enjuego[i].valor == 5)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_6C.bmp", 0);
			else if (Enjuego[i].valor == 6)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_7C.bmp", 0);
			else if (Enjuego[i].valor == 7)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_8C.bmp", 0);
			else if (Enjuego[i].valor == 8)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_9C.bmp", 0);
			else if (Enjuego[i].valor == 9)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_10C.bmp", 0);
			else if (Enjuego[i].valor == 10)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_JC.bmp", 0);
			else if (Enjuego[i].valor == 11)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_QC.bmp", 0);
			else if (Enjuego[i].valor == 12)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_KC.bmp", 0);
			else if (Enjuego[i].valor == 13)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_AC.bmp", 0);
		}
		else if (Enjuego[i].tipo == 'D')
		{
			if (Enjuego[i].valor == 1)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_2D.bmp", 0);
			else if (Enjuego[i].valor == 2)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_3D.bmp", 0);
			else if (Enjuego[i].valor == 3)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_4D.bmp", 0);
			else if (Enjuego[i].valor == 4)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_5D.bmp", 0);
			else if (Enjuego[i].valor == 5)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_6D.bmp", 0);
			else if (Enjuego[i].valor == 6)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_7D.bmp", 0);
			else if (Enjuego[i].valor == 7)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_8D.bmp", 0);
			else if (Enjuego[i].valor == 8)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_9D.bmp", 0);
			else if (Enjuego[i].valor == 9)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_10D.bmp", 0);
			else if (Enjuego[i].valor == 10)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_JD.bmp", 0);
			else if (Enjuego[i].valor == 11)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_QD.bmp", 0);
			else if (Enjuego[i].valor == 12)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_KD.bmp", 0);
			else if (Enjuego[i].valor == 13)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_AD.bmp", 0);
		}
		else if (Enjuego[i].tipo == 'T')
		{
			if (Enjuego[i].valor == 1)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_2T.bmp", 0);
			else if (Enjuego[i].valor == 2)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_3T.bmp", 0);
			else if (Enjuego[i].valor == 3)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_4T.bmp", 0);
			else if (Enjuego[i].valor == 4)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_5T.bmp", 0);
			else if (Enjuego[i].valor == 5)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_6T.bmp", 0);
			else if (Enjuego[i].valor == 6)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_7T.bmp", 0);
			else if (Enjuego[i].valor == 7)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_8T.bmp", 0);
			else if (Enjuego[i].valor == 8)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_9T.bmp", 0);
			else if (Enjuego[i].valor == 9)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_10T.bmp", 0);
			else if (Enjuego[i].valor == 10)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_JT.bmp", 0);
			else if (Enjuego[i].valor == 11)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_QT.bmp", 0);
			else if (Enjuego[i].valor == 12)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_KT.bmp", 0);
			else if (Enjuego[i].valor == 13)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_AT.bmp", 0);
		}
		else if (Enjuego[i].tipo == 'P')
		{
			if (Enjuego[i].valor == 1)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_2P.bmp", 0);
			else if (Enjuego[i].valor == 2)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_3P.bmp", 0);
			else if (Enjuego[i].valor == 3)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_4P.bmp", 0);
			else if (Enjuego[i].valor == 4)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_5P.bmp", 0);
			else if (Enjuego[i].valor == 5)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_6P.bmp", 0);
			else if (Enjuego[i].valor == 6)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_7P.bmp", 0);
			else if (Enjuego[i].valor == 7)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_8P.bmp", 0);
			else if (Enjuego[i].valor == 8)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_9P.bmp", 0);
			else if (Enjuego[i].valor == 9)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_10P.bmp", 0);
			else if (Enjuego[i].valor == 10)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_JP.bmp", 0);
			else if (Enjuego[i].valor == 11)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_QP.bmp", 0);
			else if (Enjuego[i].valor == 12)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_KP.bmp", 0);
			else if (Enjuego[i].valor == 13)
				DS_Card[i] = new EDXFramework::Model("Modelos//DS_Card//DS_Card.obj", "Modelos//DS_Card//DS_Card_AP.bmp", 0);
		}
	}

	void render(HDC hDC)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();
		CamaraU();
		if (pz >= 270 && px <= 6 && px >= -6 && freeze == false && enemigo == true)
		{
			freeze = true;
			px = 0;
			pz = 270;
			py = 61.2;
			dx = 0;
			dz = 285;
			dy = 61;
		}
		if (pz == -44 && enemigo == false)
		{
			enemigo = true;
			bonfire = true;
		}
		if (pz == 110)
			musica = 2;
		else if (pz == 109)
			musica = 1;

		//Skydome
		glPushMatrix();
		glTranslatef(0, 8, 0);
		glRotatef(180, 0, 1, 0);
		skydome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
		glScalef(3, 1, 3);
		terreno->Draw();
		glPopMatrix();

		//AL
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glScalef(2, 2, 2);
		glRotatef(180, 0, 1, 0);
		DS_AL->Draw();
		glPopMatrix();

		//Bonfire
		glPushMatrix();
		glTranslatef(0, 21.5, -45);
		glScalef(0.35, 0.35, 0.35);
		DS_Bonfire->Draw();
		glPopMatrix();
		
		//BK
		if (enemigo == true)
		{
			glPushMatrix();
			glTranslatef(0, 59.15, 290);
			glRotatef(180, 0, 1, 0);
			glScalef(0.75, 0.75, 0.75);
			DS_BK->Draw();
			glPopMatrix();
		}

		//Cards
		if (freeze == true)
		{
			//BK
			glPushMatrix();
			if (showdown == false)
			{
				glScalef(0.5, 0.5, 0.5);
				glTranslatef(-15, 128, 580);
			}
			else if (showdown == true)
			{
				glRotatef(180, 0, 1, 0);
				glScalef(0.5, 0.5, 0.5);
				glTranslatef(-15, 128, -580);
			}
			DS_Card[5]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[6]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[7]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[8]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[9]->Draw();
			glPopMatrix();

			//Player
			glPushMatrix();
			glRotatef(180, 0, 1, 0);
			glScalef(0.05, 0.05, 0.05);
			glTranslatef(-15, 1208, -5439.5);
			DS_Card[0]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[1]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[2]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[3]->Draw();
			glTranslatef(7.5, 0, 0);
			DS_Card[4]->Draw();
			glPopMatrix();

			//Instructions
			glPushMatrix();
			glRotatef(180, 0, 1, 0);
			glScalef(0.05, 0.05, 0.05);
			glTranslatef(-15.5, 1223.2, -5439.5);
			glRotatef(-90, 0, 0, 1);
			if (cambiar == false && proba == false && showdown == false)
				DS_Card_Ins[0]->Draw();
			else if (cambiar == true || proba == true)
				DS_Card_Ins[6]->Draw();
			else if (showdown == true)
				DS_Card_Ins[17]->Draw();
			glPopMatrix();
			if (cambiar == true)
			{
				glPushMatrix();
				glRotatef(180, 0, 1, 0);
				glScalef(0.05, 0.05, 0.05);
				glTranslatef(6.5, 1223.2, -5439.5);
				glRotatef(-90, 0, 0, 1);
				if (ncambios == 0)
					DS_Card_Ins[1]->Draw();
				else if (ncambios == 1)
					DS_Card_Ins[2]->Draw();
				else if (ncambios == 2)
					DS_Card_Ins[3]->Draw();
				else if (ncambios == 3)
					DS_Card_Ins[4]->Draw();
				else if (ncambios == 4)
					DS_Card_Ins[5]->Draw();
				glPopMatrix();
			}
			if (proba == true)
			{
				glPushMatrix();
				glRotatef(180, 0, 1, 0);
				glScalef(0.05, 0.05, 0.05);
				glTranslatef(6.5, 1223.2, -5439.5);
				glRotatef(-90, 0, 0, 1);
				if (nganar > 0 && nganar <= 10)
					DS_Card_Ins[7]->Draw();
				else if (nganar > 10 && nganar <= 20)
					DS_Card_Ins[8]->Draw();
				else if (nganar > 20 && nganar <= 30)
					DS_Card_Ins[9]->Draw();
				else if (nganar > 30 && nganar <= 40)
					DS_Card_Ins[10]->Draw();
				else if (nganar > 40 && nganar <= 50)
					DS_Card_Ins[11]->Draw();
				else if (nganar > 50 && nganar <= 60)
					DS_Card_Ins[12]->Draw();
				else if (nganar > 60 && nganar <= 70)
					DS_Card_Ins[13]->Draw();
				else if (nganar > 70 && nganar <= 80)
					DS_Card_Ins[14]->Draw();
				else if (nganar > 80 && nganar <= 90)
					DS_Card_Ins[15]->Draw();
				else if (nganar > 90 && nganar <= 100)
					DS_Card_Ins[16]->Draw();
				glPopMatrix();
			}
		}

		//WIN or DIE
		if (WIN == true || DIE == true)
		{
			glPushMatrix();
			glTranslatef(-0.1, 15, -1.5);
			glRotatef(180, 0, 1, 0);
			glRotatef(-90, 0, 0, 1);
			if (WIN == true)
			DS_Card_Ins[18]->Draw();
			else if (DIE == true)
				DS_Card_Ins[19]->Draw();
			glPopMatrix();
			px = -4;
			dx = -5;
			py = 15;
			dy = 15;
			pz = -7;
			dz = 8;
		}

		//billBoard[0]->Draw(posc);
		//billBoard[1]->Draw(posc);
		//billBoard[2]->Draw(posc);

		SwapBuffers(hDC);
	}
};
#endif
