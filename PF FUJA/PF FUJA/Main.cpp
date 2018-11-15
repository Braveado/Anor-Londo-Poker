#include<Windows.h>
#include <gl\glew.h>
#include <gl\GLU.h>
#include <gl\GL.h>
#include "Escena.h"
#include "resource.h"
#include<mmsystem.h>
#include <fstream>
//#include <stdlib.h>
//#include "glext.h"
#pragma comment (lib, "glew32.lib") 
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 
#pragma comment(lib, "winmm.lib")

#define Timer1 100

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void DefPixelFormat(HDC hDC);

HDC hContextoVentana;
Escena *escena;
bool renderiza = false, espera = false;
fstream archivo;
int victorias = 0, derrotas = 0, contador = 0;
char conversion[4];
char vicstr[4] = "";
char derstr[4] = "";
char estadisticas[40] = "";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwndVentana;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = "HUUUH";
	RegisterClassEx(&wc);
	RECT wr = { 0, 0, 1080, 720 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	hwndVentana = CreateWindowEx(NULL,
		"HUUUH",
		"Anor Londo Poker",
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwndVentana, nCmdShow);

	glewInit();

	escena = new Escena(hwndVentana);

	SetTimer(hwndVentana, Timer1, 30, NULL);

	MSG msg = { 0 };
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			if (renderiza)
			{
				escena->render(hContextoVentana);
				renderiza = false;
			}
		}
	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hContextoGL;
	static HDC hContextoAux;
	int ancho, alto;
	//char epx[6] = "";
	//char epz[6] = "";
	//char epy[6] = "";
	//char edx[6] = "";
	//char edz[6] = "";
	//char edy[6] = "";
	//char ec[80] = "";

	switch (message)
	{
	case WM_CREATE:
		srand(time(NULL));
		hContextoAux = GetDC(hWnd);
		hContextoVentana = hContextoAux;
		DefPixelFormat(hContextoVentana);
		hContextoGL = wglCreateContext(hContextoVentana);
		wglMakeCurrent(hContextoVentana, hContextoGL);
		//cargar datos
		archivo.open("Estadisticas.txt", ios::in);
		if (archivo.is_open())
		{
			archivo.getline(conversion, 4);
			victorias = atoi(conversion);
			archivo.getline(conversion, 4);
			derrotas = atoi(conversion);
		}
		archivo.close();
		//
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_AYUDA_CONTROLES:
			MessageBox(hWnd, "Movimiento de jugador:     W \n                                             A S D\n\nMovimiento de camara:      ^ \n                                             < v >\n\nMenu de juego:                  1 2 3\n                                              4 5 6", "Controles", MB_OK);
			return 0;
		case ID_AYUDA_COMBINACIONES:
			MessageBox(hWnd, "Escalera real: escalera de color con los valores maximos.\nEn caso de empate el jugador gana.\n\nEscalera de color: 5 cartas en orden numerico del mismo tipo.\nSe desempata con la(s) carta(s) de mayor valor.\n\nPoker: 4 cartas del mismo valor.\nSe desempata con el poker de mayor valor.\n\nFull: 1 tercia y 1 par.\nSe desempata con la tercia de mayor valor.\n\nColor: 5 cartas del mismo tipo.\nSe desempata con la(s) carta(s) de mayor valor.\n\nEscalera: 5 cartas de valor consecutivo.\nSe desempata con la(s) carta(s) de mayor valor.\n\nTercia: 3 cartas del mismo valor.\nSe desempata con la tercia de mayor valor.\n\nDoble par: 2 pares diferentes.\nSe desempata con el valor de el(los) par(es) de mayor valor, si son iguales, con la carta restante de mayor valor.\n\nPar: 2 cartas del mismo valor.\nSe desempata con el par de mayor valor, si son iguales con la(s) carta(s) restante(s) de mayor valor.\n\nCarta alta: la carta mas alta de una mano sin combinaciones.\nSe desempata con la(s) carta(s) de mayor valor.\n\nEl jugador gana si aun con las reglas de un dado desempate no se logra desempatar.", "Combinaciones", MB_OK);
			return 0;
		case ID_AYUDA_ESTADISTICAS:
			strcpy_s(estadisticas, "");
			_itoa_s(victorias, vicstr, 10);
			_itoa_s(derrotas, derstr, 10);
			strcat(estadisticas, "Victorias: ");
			strcat(estadisticas, vicstr);
			strcat(estadisticas, "\n\n");
			strcat(estadisticas, "Derrotas: ");
			strcat(estadisticas, derstr);
			MessageBox(hWnd, estadisticas, "Estadisticas", MB_OK);
			return 0;
		}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		//case VK_RETURN:
		//	strcpy_s(epx, "");
		//	strcpy_s(edx, "");
		//	strcpy_s(epz, "");
		//	strcpy_s(edz, "");
		//	strcpy_s(epy, "");
		//	strcpy_s(edy, "");
		//	strcpy_s(ec, "");
		//	_itoa_s(escena->px, epx, 10);
		//	_itoa_s(escena->pz, epz, 10);
		//	_itoa_s(escena->py, epy, 10);
		//	_itoa_s(escena->dx, edx, 10);
		//	_itoa_s(escena->dz, edz, 10);
		//	_itoa_s(escena->dy, edy, 10);
		//	strcat(ec, "Px = ");
		//	strcat(ec, epx);
		//	strcat(ec, "   ");
		//	strcat(ec, "Pz = ");
		//	strcat(ec, epz);
		//	strcat(ec, "   ");
		//	strcat(ec, "Py = ");
		//	strcat(ec, epy);
		//	strcat(ec, "   ");
		//	strcat(ec, "Dx = ");
		//	strcat(ec, edx);
		//	strcat(ec, "   ");
		//	strcat(ec, "Dz = ");
		//	strcat(ec, edz);
		//	strcat(ec, "   ");
		//	strcat(ec, "Dy = ");
		//	strcat(ec, edy);
		//	MessageBox(hWnd, ec, "Camara", MB_OK);
		//	return 0;
		case VK_UP:
			if (escena->freeze == false)
			{
				escena->VoltearArriba();
				renderiza = true;
			}
			return 0;
		case VK_DOWN:
			if (escena->freeze == false)
			{
				escena->VoltearAbajo();
				renderiza = true;
			}
			return 0;
		case VK_LEFT:
			if (escena->freeze == false)
			{
				escena->VoltearIzquierda();
				renderiza = true;
			}
			return 0;
		case VK_RIGHT:
			if (escena->freeze == false)
			{
				escena->VoltearDerecha();
				renderiza = true;
			}
			return 0;
		case 0x44: //D
			if (escena->freeze == false)
			{
				escena->MoverDerecha();
				//escena->px--;
				//escena->dx--;
				renderiza = true;
			}
			return 0;
		case 0x41: //A
			if (escena->freeze == false)
			{
				escena->MoverIzquierda();
				//escena->px++;
				//escena->dx++;
				renderiza = true;
			}
			return 0;
		case 0x57: //W
			if (escena->freeze == false)
			{
				escena->MoverAdelante();
				//escena->pz++;
				//escena->dz++;
				renderiza = true;
			}
			return 0;
		case 0x53: //S
			if (escena->freeze == false)
			{
				escena->MoverAtras();
				//escena->pz--;
				//escena->dz--;
				renderiza = true;
			}
			return 0;
		//case 0x45: //E
		//	if (escena->freeze == false)
		//	{
		//		escena->py++;
		//		escena->dy++;
		//		renderiza = true;
		//	}
		//	return 0;
		//case 0x51: //Q
		//	if (escena->freeze == false)
		//	{
		//		escena->py--;
		//		escena->dy--;
		//		renderiza = true;
		//	}
		//	return 0;
		case 0x31: //1
			if (escena->freeze == true && escena->showdown == false && escena->proba == false && escena->cambiar == false)
			{
				escena->Enjuego[5].IA(escena->Enjuego, escena->Ccom);
				escena->cartatex(escena->Enjuego, escena->DS_Card, 5);
				escena->cartatex(escena->Enjuego, escena->DS_Card, 6);
				escena->cartatex(escena->Enjuego, escena->DS_Card, 7);
				escena->cartatex(escena->Enjuego, escena->DS_Card, 8);
				escena->cartatex(escena->Enjuego, escena->DS_Card, 9);
				escena->Enjuego[0].combinacion(escena->Enjuego, 0, 4, escena->Cjug);
				escena->Enjuego[5].combinacion(escena->Enjuego, 5, 9, escena->Ccom);
				escena->showdown = true;
			}
			else if (escena->showdown == true)
			{
				if (escena->Cjug[0] > escena->Ccom[0])
					escena->WIN = true;
				else if (escena->Cjug[0] < escena->Ccom[0])
					escena->DIE = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] > escena->Ccom[1])
					escena->WIN = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] < escena->Ccom[1])
					escena->DIE = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] > escena->Ccom[2])
					escena->WIN = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] < escena->Ccom[2])
					escena->DIE = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] == escena->Ccom[2] && escena->Cjug[3] > escena->Ccom[3])
					escena->WIN = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] == escena->Ccom[2] && escena->Cjug[3] < escena->Ccom[3])
					escena->DIE = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] == escena->Ccom[2] && escena->Cjug[3] == escena->Ccom[3] && escena->Cjug[4] > escena->Ccom[4])
					escena->WIN = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] == escena->Ccom[2] && escena->Cjug[3] == escena->Ccom[3] && escena->Cjug[4] > escena->Ccom[4])
					escena->DIE = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] == escena->Ccom[2] && escena->Cjug[3] == escena->Ccom[3] && escena->Cjug[4] == escena->Ccom[4] && escena->Cjug[5] > escena->Ccom[5])
					escena->WIN = true;
				else if (escena->Cjug[0] == escena->Ccom[0] && escena->Cjug[1] == escena->Ccom[1] && escena->Cjug[2] == escena->Ccom[2] && escena->Cjug[3] == escena->Ccom[3] && escena->Cjug[4] == escena->Ccom[4] && escena->Cjug[5] < escena->Ccom[5])
					escena->DIE = true;
				else
					escena->WIN = true;
			}
			else if (escena->cambiar == true && escena->ncambios < 4)
			{
				escena->Enjuego[0].cambiar(escena->Enjuego, 0);
				delete escena->DS_Card[0];
				escena->cartatex(escena->Enjuego, escena->DS_Card, 0);
				escena->ncambios++;
			}
			if ((escena->WIN == true || escena->DIE == true) && espera == false)
			{
				if (escena->WIN == true)
				{
					victorias += 1;
					mciSendString("stop AL", NULL, 0, 0);
					mciSendString("close AL", NULL, 0, 0);
					mciSendString("close bonfire", NULL, 0, 0);
					mciSendString("close WIN", NULL, 0, 0);
					mciSendString("close DIE", NULL, 0, 0);
					mciSendString("open \"Sonidos//WIN.mp3\" alias WIN", NULL, 0, 0);
					mciSendString("play WIN", NULL, 0, 0);
				}
				else if (escena->DIE == true)
				{
					derrotas += 1;
					mciSendString("stop AL", NULL, 0, 0);
					mciSendString("close AL", NULL, 0, 0);
					mciSendString("close bonfire", NULL, 0, 0);
					mciSendString("close WIN", NULL, 0, 0);
					mciSendString("close DIE", NULL, 0, 0);
					mciSendString("open \"Sonidos//DIE.mp3\" alias DIE", NULL, 0, 0);
					mciSendString("play DIE", NULL, 0, 0);
				}
				//guardar datos
				archivo.open("Estadisticas.txt", ios::out | ios::trunc);
				if (archivo.is_open())
				{
							archivo << victorias << endl;
							archivo << derrotas << endl;
				}
				archivo.close();
				//
				espera = true;
			}
			return 0;
		case 0x32: //2
			if (escena->freeze == true && escena->proba == false && escena->cambiar == false && escena->showdown == false)
			{
				escena->proba = true;
				escena->Enjuego[0].combinacion(escena->Enjuego, 0, 4, escena->Cjug);
				escena->nganar = (escena->Cjug[0] * 10) + (escena->Cjug[1] / 1.3) - 0.1;
				//int perder = 100 - escena->nganar;
				//char ganarstr[8] = "";
				//char perderstr[8] = "";
				//char prob[50] = "";
				//_itoa_s(escena->nganar, ganarstr, 10);
				//_itoa_s(perder, perderstr, 10);
				//strcat(prob, "Ganar = ");
				//strcat(prob, ganarstr);
				//strcat(prob, "%   ");
				//strcat(prob, "Perder = ");
				//strcat(prob, perderstr);
				//strcat(prob, "%");
				//MessageBox(hWnd, prob, "Probabilidades", MB_OK);
			}
			else if (escena->cambiar == true && escena->ncambios < 4)
			{
				escena->Enjuego[1].cambiar(escena->Enjuego, 1);
				delete escena->DS_Card[1];
				escena->cartatex(escena->Enjuego, escena->DS_Card, 1);
				escena->ncambios++;
			}
			return 0;
		case 0x33: //3
			if (escena->freeze == true && escena->cambiar == false && escena->proba == false && escena->showdown == false)
			{
				escena->cambiar = true;
			}
			else if (escena->cambiar == true && escena->ncambios < 4)
			{
				escena->Enjuego[2].cambiar(escena->Enjuego, 2);
				delete escena->DS_Card[2];
				escena->cartatex(escena->Enjuego, escena->DS_Card, 2);
				escena->ncambios++;
			}
			return 0;
		case 0x34: //4
			if (escena->freeze == true && escena->cambiar == false && escena->proba == false && escena->showdown == false)
			{
				escena->px = 0;
				escena->py = 24;
				escena->pz = -50;
				escena->dx = 0;
				escena->dy = 19;
				escena->dz = -24;
				mciSendString("stop AL", NULL, 0, 0);
				mciSendString("close AL", NULL, 0, 0);
				mciSendString("close bonfire", NULL, 0, 0);
				mciSendString("close WIN", NULL, 0, 0);
				mciSendString("close DIE", NULL, 0, 0);
				mciSendString("open \"Sonidos//bonfire.mp3\" alias bonfire", NULL, 0, 0);
				mciSendString("play bonfire", NULL, 0, 0);
				escena->ncambios = 0;
				escena->WIN = false;
				escena->DIE = false;
				escena->showdown = false;
				escena->freeze = false;
				for (int i = 0; i < 10; i++)
				{
					escena->Enjuego[i].reasignar();
				}
				escena->Enjuego[0].repetidas(escena->Enjuego);
				for (int i = 0; i < 10; i++)
				{
					delete escena->DS_Card[i];
					escena->cartatex(escena->Enjuego, escena->DS_Card, i);
				}
			}
			else if (escena->cambiar == true && escena->ncambios < 4)
			{
				escena->Enjuego[3].cambiar(escena->Enjuego, 3);
				delete escena->DS_Card[3];
				escena->cartatex(escena->Enjuego, escena->DS_Card, 3);
				escena->ncambios++;
			}
			return 0;
		case 0x35: //5
			if (escena->cambiar == true && escena->ncambios < 4)
			{
				escena->Enjuego[4].cambiar(escena->Enjuego, 4);
				delete escena->DS_Card[4];
				escena->cartatex(escena->Enjuego, escena->DS_Card, 4);
				escena->ncambios++;
			}
			return 0;
		case 0x36: //6
			if (escena->cambiar == true)
			{
				escena->cambiar = false;
			}
			else if (escena->proba == true)
			{
				escena->proba = false;
			}
			return 0;
		}
	case WM_TIMER:
		renderiza = true;
		if (escena->bonfire == true)
		{
			mciSendString("stop AL", NULL, 0, 0);
			mciSendString("close AL", NULL, 0, 0);
			mciSendString("close bonfire", NULL, 0, 0);
			mciSendString("close WIN", NULL, 0, 0);
			mciSendString("close DIE", NULL, 0, 0);
			mciSendString("open \"Sonidos//bonfire.mp3\" alias bonfire", NULL, 0, 0);
			mciSendString("play bonfire", NULL, 0, 0);
			escena->bonfire = false;
		}
		if (escena->musica == 2)
		{
			mciSendString("open \"Sonidos//Anor_Londo.mp3\" alias AL", NULL, 0, 0);
			mciSendString("play AL repeat", NULL, 0, 0);
			escena->musica = 0;
		}
		else if (escena->musica == 1)
		{
			mciSendString("stop AL", NULL, 0, 0);
			mciSendString("close AL", NULL, 0, 0);
			escena->musica = 0;
		}
		if (espera == true && contador <=165)
		{
			contador++;
		}
		if ( espera == true && contador >= 165)
		{
			espera = false;
			contador = 0;
			//MessageBox(hWnd, "test", "test", MB_OK);
			if (escena->WIN == true || escena->DIE == true)
			{
				if (escena->DIE == true)
				{
					escena->px = 0;
					escena->py = 24;
					escena->pz = -50;
					escena->dx = 0;
					escena->dy = 19;
					escena->dz = -24;
					mciSendString("stop AL", NULL, 0, 0);
					mciSendString("close AL", NULL, 0, 0);
					mciSendString("close bonfire", NULL, 0, 0);
					mciSendString("close WIN", NULL, 0, 0);
					mciSendString("close DIE", NULL, 0, 0);
					mciSendString("open \"Sonidos//bonfire.mp3\" alias bonfire", NULL, 0, 0);
					mciSendString("play bonfire", NULL, 0, 0);
				}
				else if (escena->WIN == true)
				{
					escena->pz = 270;
					escena->py = 61;
					escena->px = 0;
					escena->dx = 0;
					escena->dz = 285;
					escena->dy = 61;
					escena->enemigo = false;
					mciSendString("open \"Sonidos//Anor_Londo.mp3\" alias AL", NULL, 0, 0);
					mciSendString("play AL repeat", NULL, 0, 0);
				}
				escena->ncambios = 0;
				escena->WIN = false;
				escena->DIE = false;
				escena->showdown = false;
				escena->freeze = false;
				for (int i = 0; i < 10; i++)
				{
					escena->Enjuego[i].reasignar();
				}
				escena->Enjuego[0].repetidas(escena->Enjuego);
				for (int i = 0; i < 10; i++)
				{
					delete escena->DS_Card[i];
					escena->cartatex(escena->Enjuego, escena->DS_Card, i);
				}
			}
		}
		break;
	case WM_DESTROY:
	{
		KillTimer(hWnd, Timer1);
		delete escena->skydome;
		delete escena->terreno;
		delete escena->DS_AL;
		delete escena->DS_BK;
		delete escena->DS_Bonfire;
		for (int i = 0; i < 10; i++)
		{
			delete escena->DS_Card[i];
		}
		for (int i = 0; i < 20; i++)
		{
			delete escena->DS_Card_Ins[i];
		}
		wglMakeCurrent(hContextoVentana, NULL);
		wglDeleteContext(hContextoGL);
		PostQuitMessage(0);
		return 0;
	} break;

	case WM_SIZE:
	{
		alto = HIWORD(lParam);
		ancho = LOWORD(lParam);
		if (alto == 0)
			alto = 1;
		glViewport(0, 0, ancho, alto);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)ancho / (GLfloat)alto, 1.0f, 10000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void DefPixelFormat(HDC hDC)
{
	int bestmatch;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), //tamaño de la estructura
		1, //numero de version
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //soporta la ventana, el opengl y manejara doble buffer
		PFD_TYPE_RGBA, //formato de 32 bits rgba
		32, //tamaño del color en 32 bits
		0, 0, 0, 0, 0, 0, //bits de color, no se usan
		0, //no hay buffer para el alfa
		0, //ignore el bit de corrimiento
		0, //no hay buffer de acumulacion
		0, 0, 0, 0, //no hay bits de acumulacion
		16, //tamaño del flotante para el buffer z
		0, //no hay buffers de stencil
		0, //no hay buffers auxiliares
		PFD_MAIN_PLANE, //plano principal para dibujo
		0, //reservado
		0, 0, 0 //mascaras de capas ignoradas
	};

	bestmatch = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, bestmatch, &pfd);
}