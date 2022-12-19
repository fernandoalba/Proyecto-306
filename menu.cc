//Menu del Proyecto 306

#include <iostream>
#include "menu.h"
#include "funciones.h"

int main(){
    int opcion;
    int &Pop=opcion;
    while (opcion!=4){
        std::cout<<"---------Bienvenido---------\n 1.Iniciar Sesion\n 2.Solicitar Registro\n 3.Visitar\n 4.Salir\n---------Por favor elija una opcion---------\n";
        std::cin>>opcion;
        switch (opcion)
        {
        case 1:
            inicios();
        break;

        case 2:
            std::cout<<"Por favor envie sus datos (Nombre completo, DNI y correo Uco) al siguiente correo: UCO_CURSOSEXTENSION@uco.es\n";
            break;

        case 3:
            Visitar(Pop);
            break;

        case 4:
            std::cout<<"Gracias por su visita\n";
            break;

        default:
            std::cout<<"Esa opcion no es valida, intentelo de nuevo"<<"\n";
            break;
        }
    }
}