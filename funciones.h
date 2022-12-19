#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <string>
#include <iostream>
using namespace std;

//General
bool login();
void inscribirse();
bool change_password();
void ver_listado_activos();
bool ver_cursos_inscritos();
void desinscribirse();
//Admin
bool change_password_admin();
int login_admin();
void activar_curso(int numero_curso);
bool crear_usuario();
bool crear_curso();
void ver_listado_completo();
void editar_curso(int numero_curso);
bool crear_coordinador(int numero);
void desactivar_curso(int numero);

//Auxiliares
bool buscar_curso(string nombre);
string buscar_curso_activo(int numero_curso);
bool buscar_usuario(string dni);
string identificar();
int numero_usuarios();
bool comprobar_inscripciones(string curso);
int contar_cursos_usuario();
bool comprobar_password(string password);
int contar_cursos();
string info_curso_numero(int numero);
bool buscar_coordinador(string identificador);
bool comprobar_password_admin(string password);
string buscar_curso_inscrito(int numero_curso);
bool buscar_curso_activo(string nombre_curso);

#endif
/*
datos.txt --->USUARIOS
administradores.txt-----> Administradores y coordinadores
cursos.txt------> Todos los cursos
cursos_activos.txt-----> Cursos activos
*/