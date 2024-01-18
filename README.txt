###Sistema de Gestión de Videojuegos###

##Lenguaje de Programación:
	El sistema está implementado en C++, un lenguaje de programación orientado a objetos de alto nivel.

##Gestor de Bases de Datos:###
	Las datos del sistema se almacenan en una base de datos relacional utilizando PostgreSQL.

##Conexión con PostgreSQL:
	La conexión entre la aplicación y PostgreSQL se establece mediante la librería libpqxx.

##Diseño de la Interfaz de Usuario:
	La interfaz de usuario se presenta en modo consola utilizando menús textuales.
	Cada opción del menú está asociada a un número que el usuario debe ingresar para seleccionar la opción deseada.
	La entrada de información se realiza de forma textual y los resultados se presentan de manera secuencial.

##Menús Principales:
	#Menú sin Usuario Iniciado:
		Muestra opciones como iniciar sesión, registrar nuevo usuario, y salir de la aplicación.

	#Menú con Usuario Iniciado:
		Proporciona acceso a la gestion de sus compras, usuario y consultas de los objectos del sistema, ya sean paquetes o videojuegos.


##Creación de la Base de Datos:

	Antes de ejecutar la aplicación, es necesario crear la base de datos utilizando PgAdmin4 u otra herramienta de administración de PostgreSQL.
	Se deben seguir las especificaciones de tu diseño, és decie crea los objectos que quieras dentro de esta implementación(videojuego, paquete).

##Compilación:
	Utiliza un compilador C++ para compilar el código fuente del proyecto (para mayor comodidad puedes hacer uso del visual studio).

##Ejecución:
	Ejecuta el programa resultante para acceder a los menús y funciones del sistema.

##Notas Importantes:
	Asegúrate de tener un servidor PostgreSQL en ejecución antes de iniciar la aplicación.
	La conexión con PostgreSQL debe configurarse adecuadamente en el código fuente utilizando la librería libpqxx.
