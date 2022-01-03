#include "Model.h"
#include "Controller.h"
#include <iostream>
#include <pthread.h>

using namespace std;

int main(int argc, char *argv[])
{	
//*
  // init threads
  g_thread_init(NULL);
  gdk_threads_init();
//*/

	gtk_init(&argc, &argv);

	if(argc != 3)
	{	cout << "ERRO: numero de argumentos invalido" << endl << "Uso: sim arq.mif charmap.mif" << endl;
		return 1;
	}
	else
	{	int i = 0;
		while(argv[1][i] != '.' && argv[1][i] != '\0')
			i++;
		if(argv[1][i+1] != 'm' || argv[1][i+2] != 'i' || argv[1][i+3] != 'f')
		{	cout << "nao eh mif" << endl;
			return 1;
		}

		i = 0;
		while(argv[2][i] != '.' && argv[2][i] != '\0')
			i++;
		if(argv[2][i+1] != 'm' || argv[2][i+2] != 'i' || argv[2][i+3] != 'f')
		{	cout << "nao eh mif" << endl;
			return 1;
		}
	}

	ModelInterface *m = new Model(argv[1], argv[2]);
	auto *c = new Controller(static_cast<ModelInterface *>(m));

//*
  // enter the GTK main loop
  gdk_threads_enter();
  gtk_main();
  gdk_threads_leave();
//*/

//	delete m;
//	delete c;

	return 0;
}

