#ifndef MODEL_H
#define MODEL_H

#include "Mneumonicos.h"
#include "ModelInterface.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>		// para a funcao delay
#include <curses.h>	    // para a captura de caracteres do inchar
#include <cmath>		// para a funcao pow
#include <pthread.h>

using namespace std;

class Model : public ModelInterface
{	private:
		// ------ MVC ---------
		Video *Vid{};
		Instrucoes *Ins{};
		Registradores *Reg{};
		ControllerInterface *controller{};

		// --- Registradores ------
		int rx{}, ry{}, rz{};

		int reg[8]{};
		int pc{}, ir{}, sp{};
		bool FR[16]{};

		// ---- Memoria --------
		int mem[TAMANHO_MEMORIA]{}; // Vetor que representa a Memoria de programa e de dados do Processador

		// ---- Nome dos arquivos ------
		char cpuram[64]{};
		char charmap[64]{};

		// -- buffer dos caracteres do charmap --
		short int **chars{};

		// -- propriedades do charmap ----
		int charmapwidth{};
		int charmapdepth{};

		// -- Processamento ---
        __attribute__((unused)) pthread_t out{};

		int key{};
		int auxpc{};
		int pc2{};
		int varDelay;
		bool automatico;

		// -- Video ---
		pixblock *block;


	public:
		Model(char *cpuram, char *charmap);
		~Model();

		void setController(ControllerInterface *controller) override;

		void reset() override;

		void updateAll();

		// ------ Registradores ----------------
		void registraRegistrador(Registradores *r) override;

		void removeRegistrador() override;


		// --- registradores gerais ---
		int getRegistrador(int regN) override;

		void setRegistrador(int *vetor) override;


		// -------- PC -----------
		int getPC() override;

		void setPC(int valor) override;


		// -------- IR -----------
		int getIR() override;

		void setIR(int valor) override;


		// -------- SP -----------
		int getSP() override;

		void setSP(int valor) override;


		// -------- FR -----------
		bool getFR(int N) override;

		void setFR(int N, bool valor) override;


		// ------ Instrucoes -------------------
		void registraInstrucoes(Instrucoes *i) override;

		void removeInstrucoes() override;

		void processa() override;

		int pega_pedaco(int ir, int a, int b) override;


		// ------ Video -------------------
		void registraVideo(Video *v) override;

		void removeVideo() override;

		short int** getChars() override;

		pixblock* getPixblock() override;

		void resetVideo() override;

		// -------- arquivos.mif -----------
		static int processa_linha(const char *linha);

		void GravaArquivo(char *nome);

		void load_charmap(char* filename);


		// ---- cpuram.mif e charmap.mif -------
		char* getCharmap() override;

		char* getCpuram() override;

		int getCharmapdepth() override;

		int getCharmapwidth() override;


		// ------ Memoria --------
		int getMem(int pos) override;


		// ------ Processador ---------
		bool getProcessamento() const;
		void setProcessamento(bool automatico) override;

		void delay();

		unsigned int _rotl(unsigned int value, int shift);

		unsigned int _rotr(unsigned int value, int shift);

		void processador();

		int getDelay() override;

		void setDelay(int valor) override;
};

#endif
