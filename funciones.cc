//Funciones desarolladas del menu 

/*  int opcion;
    while (opcion!=){
        std::cout<<"";
        std::cin>>opcion;
        switch (opcion){
            case 1:
            
                break;

            case 2:

                break;
        
            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
}*/

#include <string>
#include <iostream>
#include "menu.h"
#include "funciones.h"

void inicios(){
    int opcion;
    
    while (opcion!=3){
        std::cout<<" 1.Iniciar como administrador\n 2.Iniciar sesion como Participante\n 3.Atras\n";
        std::cin>>opcion;
        switch (opcion){
            case 1:
                switch(login_admin()){
                    case 1:
                        menu_admin();
                        break;
                    case 2:
                        menu_CC();
                        break;
                    case 3:
                        menu_CR();
                        break;
                    default:
                        std::cout<<"pruebe otra vez\n";
                        break;
                }
                break;
            
            case 2:
                if(login()==true){
                    menu_p();
                }

                break;
            
            case 3:
                break;
        
            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
}

void menu_p(){
    int opcion;
    int opc2;
    int opc3;

    while (opcion!=4){
        std::cout<<"-------PARTICIPANTE-------\n 1.Ver listado de cursos\n 2.Inscripciones\n 3.Cambiar Contraseña \n 4.Cerrar Sesion\n";
        std::cin>>opcion;
        switch (opcion){
            case 1:
                ver_listado_activos();
                while(opc2!=2){
                    std::cout<<" 1.Inscribirse a un curso\n 2.Atras\n";
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc2;
                    switch(opc2){
                        case 1:
                            inscribirse();
                            break;
                        
                        case 2:
                            break;
                        
                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    }
                }
                break;

            case 2:
                
                while(opc3!=2){
                    ver_cursos_inscritos();
                    std::cout<<" 1.Desiscribirse\n 2.Atras\n";
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc3;
                    switch(opc3){
                        case 1:
                            desinscribirse();
                            break;
                        
                        case 2:
                            break;
                        
                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    }
                }
                break;
        
            case 3:
            if(change_password()==true){
                    std::cout<<"Contraseña cambiada con exito\n";
                }else{
                    std::cout<<"Error al cambiar la contraseña\n";
                }
                break;

            case 4:
                std::cout<<"Se ha cerrado la sesion correctamente\n";
                break;

            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
}

void menu_admin(){
    int opcion;
    int opc2;
    int crearC;
    int curso;

    while (opcion!=7){
        std::cout<<"-------ADMINISTRADOR-------\n 1.Añadir Participante\n 2.Añadir Coordinador\n 3.Ver todos los cursos\n 4.Ver cursos activos\n 5.Crear curso\n 6.Cambiar Contraseña\n 7.Cerrar sesion\n";
        std::cin>>opcion;
        switch (opcion){
            case 1:
                if(crear_usuario()==true){
                    std::cout<<"El usuario ha sido creado con exito\n";
                }else{
                    std::cout<<"El usuario ya se encuentra registrado o se produjo algun error\n";
                }
                break;
            
            case 2:
                std::cout<<"Que desea crear:\n 1.Coordinador de Cursos\n 2.Coordinador de Recursos\n";
                std::cin>>crearC;
                if(crear_coordinador(crearC)==true){
                    std::cout<<"Creado con exito\n";
                }
                break;
            
            case 3:
                ver_listado_completo();
                while(opc2!=3){
                    std::cout<<" 1.Activar Curso\n 2.Desactivar Curso\n 3.Atras\n"; 
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc2;
                    switch(opc2){
                        case 1:
                            std::cout<<"¿Que curso quiere activar?\n";
                            std::cin>>curso;
                            activar_curso(curso);
                            break;
                        
                        case 2:
                            std::cout<<"¿Que curso quiere desactivar?\n";
                            std::cin>>curso;
                            desactivar_curso(curso);
                            break;

                        case 3:
                            break;
                        
                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    } 
                }              
                break;
            case 4:
                    while(opc2!=2){
                    ver_listado_activos();
                    std::cout<<" 1.Desactivar Curso\n 2.Atras\n"; 
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc2;
                    switch(opc2){
                        case 1:
                            std::cout<<"¿Que curso quiere desactivar?\n";
                            std::cin>>curso;
                            desactivar_curso(curso);
                            
                            break;

                        case 2:
                            break;
                        
                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    } 
                }   
                break;

            case 5:
                if(crear_curso()==false){
                    std::cout<<"Ya existe ese curso\n";
                }else{
                    std::cout<<"Curso creado con exito\n";
                }
                break;

            case 6:
            if(change_password_admin()==true){
                    std::cout<<"Contraseña cambiada con exito\n";
                }else{
                    std::cout<<"Error al cambiar la contraseña\n";
                }
                break;

            case 7: 
                std::cout<<"Se cerro la sesion Correctamente\n";
                break;
    
            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
    
}

void menu_CC(){
    int opcion;
    int opc2;
    int curso;

    while (opcion!=4){
        std::cout<<"-------Coordinador de Cursos-------\n 1.Ver listado de cursos\n 2.Ver cursos activos\n 3.Cambiar Contraseña\n 4.Cerrar Sesion\n";
        std::cin>>opcion;
        switch (opcion){
            case 1:
                ver_listado_completo();
                while(opc2!=3){
                    std::cout<<" 1.Activar Curso\n 2.Desactivar Curso\n 3.Atras\n"; 
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc2;
                    switch(opc2){
                        case 1:
                            std::cout<<"¿Que curso quiere activar?\n";
                            std::cin>>curso;
                            activar_curso(curso);
                            break;
                        
                        case 2:
                            std::cout<<"¿Que curso quiere desactivar?\n";
                            std::cin>>curso;
                            desactivar_curso(curso);
                            break;

                        case 3:
                            break;
                        
                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    } 
                }              
                break;
            case 2:
                    while(opc2!=2){
                    ver_listado_activos();
                    std::cout<<" 1.Desactivar Curso\n 2.Atras\n"; 
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc2;
                    switch(opc2){
                        case 1:
                            std::cout<<"¿Que curso quiere desactivar?\n";
                            std::cin>>curso;
                            desactivar_curso(curso);
                            
                            break;

                        case 2:
                            break;
                        
                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    } 
                }   
                break;

            case 3:
                if(change_password_admin()==true){
                    std::cout<<"Contraseña cambiada con exito\n";
                }else{
                    std::cout<<"Error al cambiar la contraseña\n";
                }
                break;

            case 4:
                break;
        
            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
}

void menu_CR(){
    int opcion;
    int opc2;
    int curso;

    while (opcion!=3){
        std::cout<<"-------Coordinador de Recursos-------\n 1.Ver listado de cursos\n 2.Cambiar Contraseña\n 3.Cerrar Sesion\n";
        std::cin>>opcion;
        switch (opcion){
            case 1:
                ver_listado_completo();
                while(opc2!=3){
                    std::cout<<" 1.Editar recursos\n 2.Atras\n"; 
                    std::cout<<"¿Que desea hacer?\n";
                    std::cin>>opc2;
                    switch(opc2){
                        case 1:
                            std::cout<<"¿Que curso quiere editar?\n";
                            std::cin>>curso;
                            editar_curso(curso);
                            break;
                        
                        case 2:
                            break;

                        default:
                            std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                            break;
                    } 
                }              
                break;

            case 2:
                if(change_password_admin()==true){
                    std::cout<<"Contraseña cambiada con exito\n";
                }else{
                    std::cout<<"Error al cambiar la contraseña\n";
                }
                break;

            case 3:
                break;
        
            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
}

void Visitar(int &Pop){
    int opcion;

    while (opcion!=2){
        std::cout<<"-------VISITANTE-------\n 1.Ver listado de cursos\n 2.Salir\n";
        std::cin>>opcion;
        switch (opcion){
            case 1:
                ver_listado_activos();
                break;

            case 2:
                std::cout<<"Gracias por su visita\n";
                Pop=4;
                break;

            default:
                std::cout<<"OPCION NO FUNCIONAL, INTENTELO DE NUEVO\n";
                break;
        }
    }
}