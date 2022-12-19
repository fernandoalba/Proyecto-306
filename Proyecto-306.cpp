#include <iostream>
#include <string.h>
#include <cstdio>
#include <fstream>
#include "funciones.h"

namespace A
{
    string dni;
}

bool login()
{
    ifstream fichero("datos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al buscar usuario" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, apellido1, apellido2, dni, aux_dni, password, aux_password;

    cout << "Introduce tu dni: ";
    cin >> aux_dni;
    cout << "Introduce tu password: ";
    cin >> aux_password;

    while (!fichero.eof())
    {
        fichero >> dni >> nombre >> apellido1 >> apellido2 >> password;
        if (dni == aux_dni && password == aux_password)
        {
            A::dni = aux_dni;
            fichero.close();
            return true;
        }
    }
    cout << "Error en las credenciales" << endl;
    fichero.close();
    return false;
}

int login_admin()
{
    ifstream fichero("administradores.txt");
    if (!fichero.good())
    {
        cout << "No existen administradores ni coordinadores" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, apellido1, apellido2, identificador, dni, aux_dni, password, aux_password;

    cout << "Introduce tu identificador: ";
    cin >> aux_dni;
    cout << "Introduce tu password: ";
    cin >> aux_password;

    while (!fichero.eof())
    {
        fichero >> identificador >> dni >> nombre >> apellido1 >> apellido2 >> password;
        if (dni == aux_dni && password == aux_password)
        {
            A::dni = aux_dni;
            if (identificador == "AA")
            {
                fichero.close();
                return 1;
            }
            else if (identificador == "CC")
            {
                fichero.close();
                return 2;
            }
            else if (identificador == "CR")
            {
                fichero.close();
                return 3;
            }
        }
    }
    cout << "Error en las credenciales" << endl;
    fichero.close();
    return 0;
}

bool crear_coordinador(int numero)
{
    string nombre, apellido1, apellido2, identificador, password, dni;

    cout << "Introduce el dni del usuario: ";
    cin >> dni;

    if (buscar_coordinador(dni))
    {
        cout << "Este dni ya se encuentra introducido" << endl;
        return false;
    }
    ofstream fichero("administradores.txt", ios::app);
    if (!fichero.is_open())
    {
        cout << "Error al abrir el fichero" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Introduce el nombre del coordinador: ";
    cin >> nombre;
    cout << "Introduce el primer apellido del coordinador: ";
    cin >> apellido1;
    cout << "Introduce el segundo apellido del coordinador: ";
    cin >> apellido2;
    cout << "Introduce la password: ";
    cin >> password;

    if (numero == 1)
    {
        fichero << "CC " << dni << " " << nombre << " " << apellido1 << " " << apellido2 << " " << password << endl;
    }
    else if (numero == 2)
    {
        fichero << "CR " << dni << " " << nombre << " " << apellido1 << " " << apellido2 << " " << password << endl;
    }
    else
    {
        cout << "Introduce un numero valido.";
        fichero.close();
        return false;
    }
    fichero.close();
    return true;
}

bool buscar_coordinador(string dni)
{
    ifstream fichero("administradores.txt");
    if (!fichero.good())
    {
        cout << "No existen administradores ni coordinadores" << endl;
    }
    string nombre, apellido1, apellido2, identificador, password, aux_dni;

    while (fichero >> identificador)
    {

        fichero >> aux_dni >>nombre >> apellido1 >> apellido2 >> password;
        if (aux_dni == dni)
        {
            fichero.close();
            return true;
        }
    }
    fichero.close();
    return false;
}
string identificar()
{
    return A::dni;
}

bool crear_usuario()
{
    string nombre, apellido1, apellido2, dni, password;

    cout << "Introduce el dni del usuario: ";
    cin >> dni;
    if (buscar_usuario(dni))
    {
        cout << "Este dni ya se encuentra introducido" << endl;
        return false;
    }
    ofstream fichero("datos.txt", ios::app);
    if (!fichero.is_open())
    {
        cout << "Error al abrir el fichero" << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Introduce el nombre del usuario: ";
    cin >> nombre;
    cout << "Introduce el primer apellido del usuario: ";
    cin >> apellido1;
    cout << "Introduce el segundo apellido del usuario: ";
    cin >> apellido2;
    cout << "Introduce la password: ";
    cin >> password;

    fichero << dni << " " << nombre << " " << apellido1 << " " << apellido2 << " " << password << endl;
    fichero.close();
    return true;
}

bool buscar_usuario(string dni)
{
    ifstream fichero("datos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al buscar usuario" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, apellido1, apellido2, aux_dni, password;

    while (fichero >> aux_dni)
    {

        fichero >> nombre >> apellido1 >> apellido2 >> password;
        if (dni == aux_dni)
        {
            fichero.close();
            return true;
        }
    }
    fichero.close();
    return false;
}

int numero_usuarios()
{
    ifstream fichero("datos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al buscar usuario" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, apellido1, apellido2, dni, password;
    int num = 0;

    while (fichero >> dni)
    {

        fichero >> nombre >> apellido1 >> apellido2 >> password;
        num++;
    }
    fichero.close();
    return num;
}

bool buscar_curso(string nombre_curso)
{
    ifstream fichero("cursos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string aux_curso, inicio, fin, aula, proyector, pizarra;
    int numero_curso;
    while (fichero >> numero_curso)
    {

        fichero >> aux_curso >> inicio >> fin >> aula >> proyector >> pizarra;
        if (nombre_curso == aux_curso)
        {
            cout << "El curso ya existe" << endl;
            fichero.close();
            return true;
        }
    }
    fichero.close();
    return false;
}

string buscar_curso_activo(int numero_curso)
{
    ifstream fichero("cursos_activos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, inicio, fin, aula, proyector, pizarra;
    int aux_curso;
    while (fichero >> aux_curso)
    {

        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;

        if (numero_curso == aux_curso)
        {
            fichero.close();
            return (nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra);
        }
    }
    fichero.close();
    cout << "\nIntroduce un numero valido\n"
         << endl;
    return "";
}

bool buscar_curso_activo(string nombre_curso)
{
    ifstream fichero("cursos_activos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, inicio, fin, aula, proyector, pizarra;
    int aux_curso;
    while (fichero >> aux_curso)
    {

        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;

        if (nombre_curso == nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra)
        {
            fichero.close();
            return true;
        }
    }
    fichero.close();
    return false;
}

string info_curso_numero(int numero)
{
    ifstream fichero("cursos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, inicio, fin, aula, proyector, pizarra;
    int aux_curso;
    while (fichero >> aux_curso)
    {

        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;

        if (numero == aux_curso)
        {
            fichero.close();
            return (nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra);
        }
    }
    fichero.close();
    cout << "Introduce un numero valido" << endl;
    return "";
}

bool crear_curso()
{
    ofstream fichero("cursos.txt", ios::app);
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }

    string nombre_curso, fecha_inicio, fecha_fin, opcion = "N";
    string aula, proyector, pizarra;
    int numero_curso;
    cout << "Introduce el nombre del curso de extension: ";
    cin >> nombre_curso;
    if (buscar_curso(nombre_curso))
    {
        fichero.close();
        return false;
    }
    numero_curso = contar_cursos() + 1;
    cout << "Introduce el aula: ";
    cin >> aula;
    cout << "Proyector[Si/No]";
    cin >> proyector;
    cout << "Pizarra[Si/No]";
    cin >> pizarra;
    cout << "Introduce la fecha de inicio del curso(dd/mm/aaaa): ";
    cin >> fecha_inicio;
    cout << "Ahora la fecha final(dd/mm/aaaa): ";
    cin >> fecha_fin;

    fichero << numero_curso << " " << nombre_curso << " " << fecha_inicio << " " << fecha_fin << " " << aula << " " << proyector << " " << pizarra << endl;

    cout << "¿Quieres activar el curso?[S/N]";
    cin >> opcion;
    if (opcion == "S" || opcion == "s")
    {
        activar_curso(numero_curso);
    }
    fichero.close();
    return true;
}

int contar_cursos()
{
    ifstream fichero("cursos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    int num, cursos = 0;
    string nombre, inicio, fin, aula, proyector, pizarra;
    while (fichero >> num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        cursos++;
    }
    fichero.close();
    return cursos;
}

int contar_cursos_activos()
{
    ifstream fichero("cursos_activos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    int num, cursos = 0;
    string nombre, inicio, fin, aula, proyector, pizarra;
    while (fichero >> num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        cursos++;
    }
    fichero.close();
    return cursos;
}

void activar_curso(int numero)
{

    ofstream fichero("cursos_activos.txt", ios::app);
    if (!fichero.is_open())
    {
        cout << "Error al activar curso" << endl;
        exit(EXIT_FAILURE);
    }
    int num = contar_cursos_activos() + 1;
    string curso = info_curso_numero(numero);
    if (!buscar_curso_activo(curso))
    {
        fichero << num << " " << curso << endl;
    }
    fichero.close();
}

bool comprobar_inscripciones(string curso)
{
    string nombre_fichero = identificar() + ".txt";
    ifstream fichero(nombre_fichero);
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, inicio, fin, aula, proyector, pizarra;
    int num;

    while (fichero >> num)
    {

        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;

        if ((nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra) == curso)
        {
            fichero.close();
            return true;
        }
    }
    fichero.close();
    return false;
}

void inscribirse()
{
    string nombre = (identificar() + ".txt");
    ofstream fichero(nombre, ios::app);
    if (!fichero.is_open())
    {
        cout << "Error en inscribirse" << endl;
        exit(EXIT_FAILURE);
    }
    int numero;
    cout << "Escoge el nÃºmero del curso: ";
    cin >> numero;
    string curso;
    int num = contar_cursos_usuario() + 1;

    curso = buscar_curso_activo(numero);
    if (!comprobar_inscripciones(curso) && curso != "")
    {
        fichero << num << " " << curso << endl;
        cout << "Inscrito correctamente" << endl;
    }
    else if (curso != "")
    {
        cout << "Ya estas inscrito en ese curso" << endl;
    }
    fichero.close();
}

int contar_cursos_usuario()
{
    ifstream fichero(identificar() + ".txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    int num, cursos = 0;
    string nombre, inicio, fin, aula, proyector, pizarra;
    while (fichero >> num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;

        cursos++;
    }
    fichero.close();
    return cursos;
}

void ver_listado_completo()
{
    ifstream fichero("cursos.txt");
    if (!fichero.good())
    {
        cout << "No existen cursos" << endl;
    }
    int num, opcion;

    string nombre, inicio, fin, aula, proyector, pizarra;
    while (fichero >> num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        cout << num << "- " << nombre << endl;
        cout << "·Aula: " << aula << "  ·Proyector: " << proyector << "  ·Pizarra: " << pizarra << endl;
        cout << "     ·Fecha de inicio: " << inicio << endl;
        cout << "     ·Fecha final: " << fin << endl
             << endl;
        num++;
    }

    fichero.close();
}

void ver_listado_activos()
{
    ifstream fichero("cursos_activos.txt");
    if (!fichero.good())
    {
        cout << "No existen cursos" << endl;
    }
    int num, opcion;

    string nombre, inicio, fin, aula, proyector, pizarra;
    while (fichero >> num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        cout << num << "- " << nombre << endl;
        cout << "·Aula: " << aula << "  ·Proyector: " << proyector << "  ·Pizarra: " << pizarra << endl;
        cout << "     ·Fecha de inicio: " << inicio << endl;
        cout << "     ·Fecha final: " << fin << endl
             << endl;
        num++;
    }

    fichero.close();
}

bool ver_cursos_inscritos()
{

    ifstream fichero(identificar() + ".txt");

    if (!fichero.is_open())
    {
        cout << "No estas inscrito en ningun curso" << endl;
        return false;
    }
    int num = 0;

    string nombre, inicio, fin, aula, proyector, pizarra;
    while (fichero >> num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        cout << num << "- " << nombre << endl;
        cout << "·Aula: " << aula << "  ·Proyector: " << proyector << "  ·Pizarra: " << pizarra << endl;
        cout << "     ·Fecha de inicio: " << inicio << endl;
        cout << "     ·Fecha final: " << fin << endl
             << endl;
        num++;
    }
    if (num == 0)
    {
        cout << "No estas inscrito en ningun curso" << endl;
    }

    fichero.close();
    return true;
}

bool comprobar_password(string password)
{
    ifstream fichero("datos.txt");
    if (!fichero.is_open())
    {
        cout << "Error al buscar usuario" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, apellido1, apellido2, dni, aux_password;

    while (!fichero.eof())
    {
        fichero >> dni >> nombre >> apellido1 >> apellido2 >> aux_password;
        if (dni == identificar() && password == aux_password)
        {
            fichero.close();
            return true;
        }
    }
    cout << "Error en las credenciales" << endl;
    fichero.close();
    return false;
}

bool change_password()
{
    string old_password, new_password;
    string nombre, apellido1, apellido2, dni, aux_password;
    cout << "Introduce tu antigua contraseña: ";
    cin >> old_password;

    if (comprobar_password(old_password))
    {
        cout << "Introduce tu nueva password: ";
        cin >> new_password;
        ifstream fichero("datos.txt");
        ofstream fichero2("auxiliar.txt", ios::app);
        while (fichero >> dni)
        {
            fichero >> nombre >> apellido1 >> apellido2 >> aux_password;
            fichero2 << dni << " " << nombre << " " << apellido1 << " " << apellido2 << " ";
            if (identificar() == dni)
            {
                fichero2 << new_password << endl;
            }
            else
            {
                fichero2 << aux_password << endl;
            }
        }
        fichero.close();
        fichero2.close();
        remove("datos.txt");
        rename("auxiliar.txt", "datos.txt");
        return true;
    }

    return false;
}

bool change_password_admin()
{
    string old_password, new_password;
    string nombre, apellido1, apellido2, dni, aux_password, identificador;
    cout << "Introduce tu antigua contraseÃ±a: ";
    cin >> old_password;

    if (comprobar_password_admin(old_password))
    {
        cout << "Introduce tu nueva password: ";
        cin >> new_password;
        ifstream fichero("administradores.txt");
        ofstream fichero2("auxiliar2.txt", ios::app);
        while (fichero >> identificador)
        {
            fichero >> dni >> nombre >> apellido1 >> apellido2 >> aux_password;
            fichero2 << identificador <<" "<<dni << " " << nombre << " " << apellido1 << " " << apellido2 << " ";
            if (identificar() == dni)
            {
                fichero2 << new_password << endl;
            }
            else
            {
                fichero2 << aux_password << endl;
            }
        }
        fichero.close();
        fichero2.close();
        remove("administradores.txt");
        rename("auxiliar2.txt", "administradores.txt");
        return true;
    }

    return false;
}

bool comprobar_password_admin(string password)
{
    ifstream fichero("administradores.txt");
    if (!fichero.is_open())
    {
        cout << "Error al buscar admin" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, apellido1, apellido2, dni, aux_password, identificador;

    while (!fichero.eof())
    {
        fichero >> identificador >>dni >> nombre >> apellido1 >> apellido2 >> aux_password;
        if (dni == identificar() && password == aux_password)
        {
            fichero.close();
            return true;
        }
    }
    cout << "Error en las credenciales" << endl;
    fichero.close();
    return false;
}

void desinscribirse()
{
    char dni[13];
    strcpy(dni, identificar().c_str());
    strcat(dni, ".txt");
    int numero, aux_num, num = 1;
    ifstream fichero(dni);
    ofstream fichero2("auxiliar3.txt");

    if (!fichero.is_open())
    {
        cout << "Error en inscribirse" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Escoge el numero del curso: ";
    cin >> numero;
    string nombre, inicio, fin, aula, proyector, pizarra;
    string curso = buscar_curso_inscrito(numero);
    if (curso != "")
    {
        if (comprobar_inscripciones(curso))
        {
            while (fichero >> aux_num)
            {
                fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
                if (curso != (nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra))
                {
                    fichero2 << num << " " << nombre << " " << inicio << " " << fin << " " << aula << " " << proyector << " " << pizarra << endl;
                    num++;
                }
            }
        }
    }

    fichero.close();
    fichero2.close();
    remove(dni);
    rename("auxiliar3.txt", dni);
}

string buscar_curso_inscrito(int numero_curso)
{
    ifstream fichero(identificar() + ".txt");
    if (!fichero.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, inicio, fin, aula, proyector, pizarra;
    int aux_curso;
    while (fichero >> aux_curso)
    {

        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;

        if (numero_curso == aux_curso)
        {
            fichero.close();
            return (nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra);
        }
    }
    fichero.close();
    cout << "Introduce un numero valido" << endl;
    return "";
}

void editar_curso(int numero_curso)
{
    ifstream fichero("cursos_activos.txt");
    ofstream fichero2("auxiliar4.txt");
    if (!fichero.is_open() && !fichero2.is_open())
    {
        cout << "Error al abrir cursos" << endl;
        exit(EXIT_FAILURE);
    }
    string nombre, inicio, fin, aula, proyector, pizarra, aux_aula, aux_proyector, aux_pizarra;
    int aux_curso, n = 1;

    while (fichero >> aux_curso)
    {

        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        fichero2 << n << " " << nombre << " " << inicio << " " << fin << " ";

        if (numero_curso == aux_curso)
        {
            cout << "Introduce el aula: ";
            cin >> aux_aula;
            cout << "Introduce si hay proyector[Si/No]: ";
            cin >> aux_proyector;
            cout << "Introduce si hay pizarra[Si/No]: ";
            cin >> aux_pizarra;
            fichero2 << aux_aula << " " << aux_proyector << " " << aux_pizarra << endl;
        }
        else
        {
            fichero2 << aula << " " << proyector << " " << pizarra << endl;
        }
        n++;
    }
    fichero.close();
    remove("cursos_activos.txt");
    rename("auxiliar4.txt", "cursos_activos.txt");
}

void desactivar_curso(int numero)
{
    int aux_num, num = 1;
    ifstream fichero("cursos_activos.txt");
    ofstream fichero2("auxiliar5.txt", ios::app);
    string nombre, inicio, fin, aula, proyector, pizarra;
    string curso = buscar_curso_activo(numero);

    while (fichero >> aux_num)
    {
        fichero >> nombre >> inicio >> fin >> aula >> proyector >> pizarra;
        if (curso != (nombre + " " + inicio + " " + fin + " " + aula + " " + proyector + " " + pizarra))
        {
            fichero2 << num << " " << nombre << " " << inicio << " " << fin << " " << aula << " " << proyector << " " << pizarra << endl;
            num++;
        }
    }
    fichero.close();
    fichero2.close();
    remove("cursos_activos.txt");
    rename("auxiliar5.txt", "cursos_activos.txt");
}