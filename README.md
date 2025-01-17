# Sistema de Gestión de Videojuegos

Este proyecto es un sistema de gestión de videojuegos que permite a los usuarios registrar cuentas, consultar y gestionar videojuegos y paquetes, así como administrar sus compras. La aplicación está diseñada para funcionar en modo consola y utiliza PostgreSQL como base de datos.

---

## Características Principales

### Lenguaje de Programación
- El sistema está desarrollado en **C++**, un llenguatge de programació orientat a objectes i d'alt nivell.

### Gestor de Bases de Datos
- La base de datos del sistema se almacena en **PostgreSQL**, un sistema de bases de datos relacional fiable y robusto.

### Conexión con PostgreSQL
- La conexión entre la aplicación y la base de datos se establece mediante la librería **libpqxx**, una interfaz moderna y eficiente para trabajar con PostgreSQL en C++.

### Diseño de la Interfaz de Usuario
- **Modo consola**: La aplicación presenta una interfaz basada en menús textuales. Cada opción se selecciona ingresando el número correspondiente.
- Los datos de entrada y salida son completamente textuales, ofreciendo una experiencia secuencial y funcional.

### Menús Principales
1. **Menú sin Usuario Iniciado**:
   - Opciones:
     - Iniciar sesión.
     - Registrar un nuevo usuario.
     - Salir de la aplicación.

2. **Menú con Usuario Iniciado**:
   - Opciones:
     - Gestionar compras.
     - Administrar perfil de usuario.
     - Consultar objetos del sistema (videojuegos o paquetes).

---

## Configuración Inicial

### Creación de la Base de Datos
Antes de ejecutar la aplicación, es necesario:
1. Configurar un servidor PostgreSQL en tu máquina.
2. Crear la base de datos siguiendo el diseño proporcionado:
   - **Objetos requeridos**: tablas para videojuegos, paquetes, usuarios y cualquier relación entre ellos.
3. Utilizar herramientas como **PgAdmin4** o cualquier administrador de PostgreSQL para crear las tablas y relaciones necesarias.

### Configuración de la Conexión
- Asegúrate de configurar correctamente los parámetros de conexión (nombre de usuario, contraseña, nombre de la base de datos, etc.) en el código fuente utilizando la librería **libpqxx**.

---

## Instrucciones de Uso

### Compilación
1. Utiliza un compilador C++ (como GCC o Visual Studio) para compilar el código fuente del proyecto.
2. Asegúrate de incluir las dependencias necesarias, como la librería **libpqxx**, durante el proceso de compilación.
