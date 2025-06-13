#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

#define DIM 17
#define PUNTEGGIO_MAX DIM-2
#define N_LIVELLI 5

const char  VUOTO = ' ',
			GIOCATORE = 'C',
			OGGETTO = '!',
			OSTACOLO = '#',
			CONTORNO_OZ = '-',
			CONTORNO_VT = '|';

char prendiInput() {
    char key;
    
	key = getch();

	return key;
}

void gameOver() {
	system("cls");
	
	cout << "        GGGGGGGGGGGGG                                                                        OOOOOOOOO                                                                   " << endl;
	cout << "     GGG::::::::::::G                                                                      OO:::::::::OO                                                                 " << endl;
	cout << "   GG:::::::::::::::G                                                                    OO:::::::::::::OO                                                               " << endl;
	cout << "  G:::::GGGGGGGG::::G                                                                   O:::::::OOO:::::::O                                                              " << endl;
	cout << " G:::::G       GGGGGG  aaaaaaaaaaaaa      mmmmmmm    mmmmmmm       eeeeeeeeeeee         O::::::O   O::::::Ovvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrr   " << endl;
	cout << "G:::::G                a::::::::::::a   mm:::::::m  m:::::::mm   ee::::::::::::ee       O:::::O     O:::::O v:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::r  " << endl;
	cout << "G:::::G                aaaaaaaaa:::::a m::::::::::mm::::::::::m e::::::eeeee:::::ee     O:::::O     O:::::O  v:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::r " << endl;
	cout << "G:::::G    GGGGGGGGGG           a::::a m::::::::::::::::::::::me::::::e     e:::::e     O:::::O     O:::::O   v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::r" << endl;
	cout << "G:::::G    G::::::::G    aaaaaaa:::::a m:::::mmm::::::mmm:::::me:::::::eeeee::::::e     O:::::O     O:::::O    v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r" << endl;
	cout << "G:::::G    GGGGG::::G  aa::::::::::::a m::::m   m::::m   m::::me:::::::::::::::::e      O:::::O     O:::::O     v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr" << endl;
	cout << "G:::::G        G::::G a::::aaaa::::::a m::::m   m::::m   m::::me::::::eeeeeeeeeee       O:::::O     O:::::O      v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r            " << endl;
	cout << " G:::::G       G::::Ga::::a    a:::::a m::::m   m::::m   m::::me:::::::e                O::::::O   O::::::O       v:::::::::v    e:::::::e            r:::::r            " << endl;
	cout << "  G:::::GGGGGGGG::::Ga::::a    a:::::a m::::m   m::::m   m::::me::::::::e               O:::::::OOO:::::::O        v:::::::v     e::::::::e           r:::::r            " << endl;
	cout << "   GG:::::::::::::::Ga:::::aaaa::::::a m::::m   m::::m   m::::m e::::::::eeeeeeee        OO:::::::::::::OO          v:::::v       e::::::::eeeeeeee   r:::::r            " << endl;
	cout << "     GGG::::::GGG:::G a::::::::::aa:::am::::m   m::::m   m::::m  ee:::::::::::::e          OO:::::::::OO             v:::v         ee:::::::::::::e   r:::::r            " << endl;
	cout << "        GGGGGG   GGGG  aaaaaaaaaa  aaaammmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee            OOOOOOOOO                vvv            eeeeeeeeeeeeee   rrrrrrr            " << endl;
}

void vittoria() {
	system("cls");
	
	cout << "HHHHHHHHH     HHHHHHHHH                    iiii       VVVVVVVV           VVVVVVVV iiii                            tttt                           " << endl;
	cout << "H:::::::H     H:::::::H                   i::::i      V::::::V           V::::::Vi::::i                        ttt:::t                           " << endl;
	cout << "H:::::::H     H:::::::H                    iiii       V::::::V           V::::::V iiii                         t:::::t                           " << endl;
	cout << "HH::::::H     H::::::HH                               V::::::V           V::::::V                              t:::::t                           " << endl;
	cout << "  H:::::H     H:::::H    aaaaaaaaaaaaa   iiiiiii       V:::::V           V:::::Viiiiiiinnnn  nnnnnnnn    ttttttt:::::ttttttt       ooooooooooo   " << endl;
	cout << "  H:::::H     H:::::H    a::::::::::::a  i:::::i        V:::::V         V:::::V i:::::in:::nn::::::::nn  t:::::::::::::::::t     oo:::::::::::oo " << endl;
	cout << "  H::::::HHHHH::::::H    aaaaaaaaa:::::a  i::::i         V:::::V       V:::::V   i::::in::::::::::::::nn t:::::::::::::::::t    o:::::::::::::::o" << endl;
	cout << "  H:::::::::::::::::H             a::::a  i::::i          V:::::V     V:::::V    i::::inn:::::::::::::::ntttttt:::::::tttttt    o:::::ooooo:::::o" << endl;
	cout << "  H:::::::::::::::::H      aaaaaaa:::::a  i::::i           V:::::V   V:::::V     i::::i  n:::::nnnn:::::n      t:::::t          o::::o     o::::o" << endl;
	cout << "  H::::::HHHHH::::::H    aa::::::::::::a  i::::i            V:::::V V:::::V      i::::i  n::::n    n::::n      t:::::t          o::::o     o::::o" << endl;
	cout << "  H:::::H     H:::::H   a::::aaaa::::::a  i::::i             V:::::V:::::V       i::::i  n::::n    n::::n      t:::::t          o::::o     o::::o" << endl;
	cout << "  H:::::H     H:::::H  a::::a    a:::::a  i::::i              V:::::::::V        i::::i  n::::n    n::::n      t:::::t    tttttto::::o     o::::o" << endl;
	cout << "HH::::::H     H::::::HHa::::a    a:::::a i::::::i              V:::::::V        i::::::i n::::n    n::::n      t::::::tttt:::::to:::::ooooo:::::o" << endl;
	cout << "H:::::::H     H:::::::Ha:::::aaaa::::::a i::::::i               V:::::V         i::::::i n::::n    n::::n      tt::::::::::::::to:::::::::::::::o" << endl;
	cout << "H:::::::H     H:::::::H a::::::::::aa:::ai::::::i                V:::V          i::::::i n::::n    n::::n        tt:::::::::::tt oo:::::::::::oo " << endl;
	cout << "HHHHHHHHH     HHHHHHHHH  aaaaaaaaaa  aaaaiiiiiiii                 VVV           iiiiiiii nnnnnn    nnnnnn          ttttttttttt     ooooooooooo   " << endl;
}

void aggiornaGriglia(char g[DIM][DIM]) {
    for (int y = 0; y < DIM; y++)
    {
        for (int x = 0; x < DIM; x++)
        {
            cout << g[y][x] << " ";
        }
        cout << endl;
    }
}

void riempiArea(char g[DIM][DIM]) {
	int random;
	
	for (int y = 0; y < DIM; y++)
    {
        for (int x = 0; x < DIM; x++)
        {
        	random = rand() % 1000;
        	
        	g[y][x] = VUOTO;
        	
            if ( random > 800 && random <= 950 ) g[y][x] = OSTACOLO;
            if ( random > 950 ) g[y][x] = OGGETTO;
        }
    }
}

void generaOggetti(char g[DIM][DIM], int P) {
	const int   RANGE = 1000,
				GENERAZIONE_MAX = 5,
				OFFSET = 100;
	
	int chance = RANGE - RANGE*(float)P/PUNTEGGIO_MAX;
	
	int randomNum, randomChance, posX, posY;
	randomNum = 1 + rand() % GENERAZIONE_MAX;
	
	for (int i = 0; i < randomNum; i++)
	{
		posX = rand() % DIM;
		posY = rand() % DIM;
		randomChance = rand() % RANGE;
		
		if ( g[posY][posX] == VUOTO )
		{
			if ( randomChance > chance || randomChance <= chance+OFFSET ) g[posY][posX] = OSTACOLO;
			if ( randomChance > chance+OFFSET) g[posY][posX] = OGGETTO;
		}
		
	}
}

int posValida(int coordinataX, int coordinataY, char g[DIM][DIM], int &Punti, bool &vita) {
	bool valida = true;
	
	if ( g[coordinataY][coordinataX] == OGGETTO ) Punti++;
	
	if ( coordinataX < 1 || coordinataX >= DIM-1 ) valida = false;
	if ( coordinataY < 1 || coordinataY >= DIM-1 ) valida = false;
	if ( g[coordinataY][coordinataX] == OSTACOLO )
	{
		vita = false;
		gameOver();
	}
	
	if (valida) generaOggetti(g, Punti);
	
	return valida;
}

struct Vec2 {
	int x = DIM/2;
	int y = DIM/2;
};

void muovi(Vec2 &Giocatore, char g[DIM][DIM], char key, int &Punti, bool &vita) {
	g[Giocatore.y][Giocatore.x] = VUOTO;
	
	switch (key)
	{
		case 's':
			if ( posValida(Giocatore.x, Giocatore.y+1, g, Punti, vita) ) Giocatore.y++;
			break;
		case 'a':
			if ( posValida(Giocatore.x-1, Giocatore.y, g, Punti, vita) ) Giocatore.x--;
			break;
		case 'w':
			if ( posValida(Giocatore.x, Giocatore.y-1, g, Punti, vita) ) Giocatore.y--;
			break;
		case 'd':
			if ( posValida(Giocatore.x+1, Giocatore.y, g, Punti, vita) ) Giocatore.x++;
			break;
	}
}

void contorni(char g[DIM][DIM]) {
	for (int y = 0; y < DIM; y++)
	{
		for (int x = 0; x < DIM; x++)
		{
			if ( y == 0 || y == DIM-1 ) g[y][x] = CONTORNO_OZ;
			if ( x == 0 || x == DIM-1 ) g[y][x] = CONTORNO_VT;
		}
	}
}

int main() {
	srand(time(NULL));
	
	bool inVita = true;
	
    char griglia[DIM][DIM];
    char input;
    Vec2 Pos;
    
    int Punteggio = 0, 
		livello = 1,
		punteggioDaRaggiungere;
    
    riempiArea(griglia);
    contorni(griglia);

    while ( inVita ) {
    	system("cls");
    	
    	int puntMax = PUNTEGGIO_MAX;
    	punteggioDaRaggiungere = puntMax * ((float)livello/N_LIVELLI);
    	griglia[Pos.y][Pos.x] = GIOCATORE;
    	
    	cout << "Livello " << livello << " [" << DIM-2 << "x" << DIM-2 << "]\n";
    	aggiornaGriglia(griglia);
    	cout << "Punteggio: " << Punteggio << "/" << punteggioDaRaggiungere; 
		 
    	input = prendiInput();
		muovi(Pos, griglia, input, Punteggio, inVita);
		
		if ( Punteggio >= punteggioDaRaggiungere )
		{
			Pos.x = Pos.y = DIM/2;
			
			riempiArea(griglia);
    		contorni(griglia);
    		Punteggio = 0;
			
			if ( livello >= N_LIVELLI )
			{
				vittoria();
				inVita = false;
			}
			livello++;
		}	
    }
    cin >> input;

    return 0;
}
