#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "View.h"
#include "ModelInterface.h"
#include "ControllerInterface.h"

class Controller : public ControllerInterface
{	private:
		View *view{};
		ModelInterface *model;
		bool hex;
		bool automatico;
		bool resetVideo;

		int key{};
	public:
		explicit Controller(ModelInterface *model);

		~Controller();

		// ----- Registradores --------
		void AlteraRegistradores(GtkWidget **TextEntryRegs) override;

		int charToInt(const char *string) const;


		// ------- Teclado --------
		bool userInput(const char *tecla) override;

		void reset() override;

		int getKey() override;

		// ---- comandos de set -------
		void setDelay(int valor) override;
		void setResetVideo(bool valor) override;
		void setRegistradorHex(bool valor) override;

		void switchExecucao() override;


		// ---- comandos de get --------
		bool getHex() override;


		void notifyProcessamento() override;
};

#endif

