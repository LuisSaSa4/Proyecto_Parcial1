# Sistema de Gestión de Competencia de Robótica

## 1. Análisis y Diseño

### 1.1 Descripción del problema

El proyecto consiste en desarrollar un sistema de gestión para una competencia de robótica utilizando programación orientada a objetos en C++. El sistema deberá permitir registrar los equipos que participarán en la competencia, así como sus participantes y robots.

Cada participante deberá registrarse con su nombre y carrera, mientras que cada robot deberá registrarse con su nombre y disciplina. Las disciplinas consideradas a participar son sumo, seguidor de línea, laberinto y velocista.

Una vez terminado el registro, el sistema deberá organizar los robots de acuerdo con su disciplina y formar enfrentamientos aleatorios entre robots del mismo tipo. Para cada enfrentamiento se deberá determinar aleatoriamente un ganador.

Finalmente, el programa deberá mostrar la información de los equipos, participantes y robots registrados, así como los resultados de las batallas realizadas.
<br>
<br>

### 1.2 Requerimientos funcionales

| ID | Requerimiento |
|---|---|
| **RF-01** | Registrar la cantidad de equipos que participarán en la competencia. |
| **RF-02** | Registrar el nombre de cada equipo y sus participantes. |
| **RF-03** | Registrar el nombre y la carrera de cada participante. |
| **RF-04** | Registrar los robots pertenecientes a cada equipo, indicando su nombre y tipo de disciplina. |
| **RF-05** | Validar que el tipo de robot corresponda a una de las disciplinas permitidas: sumo, seguidor de línea, laberinto o velocista. |
| **RF-06** | Organizar los robots de acuerdo con su disciplina. |
| **RF-07** | Formar aleatoriamente parejas de robots que pertenezcan a la misma disciplina. |
| **RF-08** | Determinar aleatoriamente el ganador de cada batalla. |
| **RF-09** | Informar cuando un robot no tenga rival dentro de su disciplina. |
| **RF-10** | Mostrar la información de los equipos, participantes y robots registrados. |
| **RF-11** | Mostrar los resultados de las batallas realizadas. |
<br>


### 1.3 Entradas y salidas esperadas

| **Entrada** | **Salida esperada** |
|---|---|
| Cantidad de equipos | El programa solicita y registra la cantidad de equipos que participarán. |
| Nombre del equipo | El nombre del equipo queda registrado y se muestra posteriormente. |
| Cantidad de participantes | El programa solicita la cantidad de participantes que tendrá el equipo. |
| Nombre del participante | El nombre del participante se registra y se muestra dentro de la información del equipo. |
| Carrera del participante | La carrera se registra junto con los datos del participante. |
| Cantidad de robots | El programa solicita la cantidad de robots que tendrá el equipo. |
| Nombre del robot | El nombre del robot se registra y se muestra posteriormente. |
| Tipo de robot | El programa valida el tipo y registra el robot dentro de su disciplina correspondiente. |
| Robots de una misma disciplina | El programa forma parejas aleatorias para realizar las batallas. |
| Dos robots enfrentados | Se muestra el enfrentamiento y se determina aleatoriamente un ganador. |
| Robot sin rival | Se muestra un mensaje indicando que el robot no tiene rival. |
| Registro completo | Se muestran los equipos, participantes y robots registrados. |
| Resultados de la competencia | Se muestran las batallas realizadas y sus respectivos ganadores. |
<br>


### 1.4 Diagrama de flujo o pseudocódigo

```text
INICIO

Inicializar números aleatorios.

Solicitar cantidad de equipos.

PARA cada equipo:

    Solicitar nombre del equipo.
    Crear el equipo.

    Solicitar cantidad de participantes.

    PARA cada participante:

        Solicitar nombre.
        Solicitar carrera.
        Crear participante.
        Agregar participante al equipo.

    Solicitar cantidad de robots.

    PARA cada robot:

        Solicitar nombre.
        Solicitar tipo de robot.

        MIENTRAS el tipo no sea válido:

            Mostrar mensaje de tipo no válido.
            Solicitar nuevamente el tipo.

        Crear robot.
        Agregar robot al equipo.

    Guardar equipo.

Mostrar información de los equipos,
participantes y robots registrados.

PARA cada disciplina:

    Buscar los robots que pertenecen a esa disciplina.

    Mezclar aleatoriamente los robots.

    FORMAR parejas de robots.

    SI queda un robot sin pareja:

        Mostrar que el robot no tiene rival.

    SI NO:

        Crear una batalla entre los dos robots.
        Determinar aleatoriamente el ganador.
        Mostrar el resultado.

Mostrar que la competencia ha finalizado.

FIN
```

![Diagrama de flujo](img/diagrama_flujo.png)
<br>


### 1.5 Casos de prueba anticipados

| **Caso** | **Escenario** | **Comportamiento esperado** |
|---|---|---|
| **1** | Un equipo con 2 robots del mismo tipo. | Los dos robots deben enfrentarse y debe mostrarse un ganador. |
| **2** | Varios equipos con participantes y robots registrados. | Todos los equipos, participantes y robots deben registrarse y mostrarse correctamente. |
| **3** | Un solo robot de una disciplina. | El programa debe indicar que el robot no tiene rival. |
| **4** | Tres robots del mismo tipo. | Debe realizarse una batalla y un robot debe quedar sin rival. |
| **5** | Cuatro robots del mismo tipo. | Deben realizarse dos batallas y ningún robot debe quedar sin rival. |
| **6** | Robots pertenecientes a diferentes disciplinas. | Solo deben enfrentarse robots que pertenezcan a la misma disciplina. |
| **7** | Ejecutar varias veces una competencia con los mismos robots. | Los emparejamientos y/o ganadores deben poder cambiar debido a la selección aleatoria. |

<br>
<br>

## 2. Desarrollo del programa


### 2.1 Clases utilizadas

El programa está desarrollado utilizando programación orientada a objetos. 
Para representar los elementos principales de la competencia se utilizaron 
cuatro clases: `Participante`, `Robot`, `Equipo` y `Batalla`.

#### Clase `Participante`

Representa a una persona que forma parte de un equipo de la competencia.

**Atributos:**
- `nombre`: almacena el nombre del participante.
- `carrera`: almacena la carrera que estudia el participante.

**Métodos:**
- `Participante(string n, string c)`: constructor que recibe el nombre y la carrera.
- `getNombre()`: permite obtener el nombre del participante.
- `getCarrera()`: permite obtener la carrera del participante.

---

#### Clase `Robot`

Representa a un robot que participa en la competencia.

**Atributos:**
- `nombre`: almacena el nombre del robot.
- `tipo`: almacena la disciplina a la que pertenece el robot.

Las disciplinas utilizadas son:
- `sumo`
- `seguidor de linea`
- `laberinto`
- `velocista`

**Métodos:**
- `Robot(string n, string t)`: constructor que recibe el nombre y el tipo de robot.
- `getNombre()`: permite obtener el nombre del robot.
- `getTipo()`: permite obtener el tipo o disciplina del robot.

---

#### Clase `Equipo`

Representa a un equipo participante de la competencia y contiene 
la información de sus participantes y robots.

**Atributos:**
- `nombre`: almacena el nombre del equipo.
- `participantes`: vector que almacena los objetos de tipo `Participante`.
- `robots`: vector que almacena los objetos de tipo `Robot`.

**Métodos:**
- `Equipo(string n)`: constructor que recibe el nombre del equipo.
- `agregarParticipante(Participante participante)`: agrega un participante al vector del equipo.
- `agregarRobot(Robot robot)`: agrega un robot al vector del equipo.
- `getNombre()`: permite obtener el nombre del equipo.
- `getParticipantes()`: permite acceder al vector de participantes.
- `getRobots()`: permite acceder al vector de robots.

La clase `Equipo` se relaciona con las clases `Participante` y `Robot`,
ya que un equipo contiene varios participantes y varios robots.

---

#### Clase `Batalla`

Representa un enfrentamiento entre dos robots de la competencia.

**Atributos:**
- `robot1`: almacena el primer robot que participa en la batalla.
- `robot2`: almacena el segundo robot que participa en la batalla.
- `ganador`: almacena el robot que resulta ganador.

**Métodos:**
- `Batalla(Robot r1, Robot r2)`: constructor que recibe los dos robots que se enfrentarán y determina aleatoriamente al ganador.
- `mostrarBatalla()`: muestra los robots que participaron en el enfrentamiento y el ganador.

La clase `Batalla` utiliza objetos de tipo `Robot` para representar a los
participantes del enfrentamiento.
<br>
<br>

### 2.2 Funciones principales

El programa cuenta con diferentes funciones que permiten organizar el registro
de los equipos y el desarrollo de la competencia.

#### `registrarEquipo(Equipo& equipo)`

Esta función se encarga de registrar la información de un equipo.

Sus principales actividades son:
- Solicitar la cantidad de participantes.
- Registrar el nombre y la carrera de cada participante.
- Agregar los participantes al equipo.
- Solicitar la cantidad de robots.
- Registrar el nombre y tipo de cada robot.
- Validar que el tipo de robot sea una de las disciplinas permitidas.
- Agregar los robots al equipo.

---

#### `mostrarRegistro(vector<Equipo>& equipos)`

Esta función muestra la información que fue registrada durante el proceso.

Muestra:
- Nombre de cada equipo.
- Participantes de cada equipo.
- Carrera de cada participante.
- Robots de cada equipo.
- Tipo de cada robot.

La función recorre el vector de equipos y utiliza los métodos de las clases
`Equipo`, `Participante` y `Robot` para obtener la información.

---

#### `iniciarCompetencia(vector<Equipo>& equipos)`

Esta función se encarga de iniciar las batallas entre los robots.

Sus principales actividades son:
- Revisar las diferentes disciplinas de la competencia.
- Buscar los robots que pertenecen a cada disciplina.
- Mezclar aleatoriamente los robots.
- Formar parejas de robots.
- Crear objetos de la clase `Batalla`.
- Determinar y mostrar el ganador de cada batalla.
- Informar cuando un robot no tiene rival.

Los robots solamente se enfrentan con otros robots que pertenecen a la
misma disciplina.

---

#### `main()`

Es la función principal del programa y controla el flujo general de ejecución.

Sus principales actividades son:
1. Inicializar la generación de números aleatorios.
2. Solicitar la cantidad de equipos.
3. Registrar cada equipo.
4. Guardar los equipos en un vector.
5. Mostrar la información registrada.
6. Iniciar la competencia.
7. Mostrar el mensaje de finalización.
<br>
<br>

## 3. Compilacion y ejecucion

### 3.1 Compilación

El proyecto está dividido en diferentes archivos `.h` y `.cpp`, por lo que
es necesario compilar los archivos de implementación junto con `main.cpp`.

El comando utilizado para compilar el programa fue:

```bash
g++ -I.h .cpp/*.cpp -o programa.exe
```
<br>

### 3.2 Ejecución

Después de compilar correctamente el proyecto, se ejecutó el programa desde
la terminal de Visual Studio Code utilizando el siguiente comando:

```powershell
.\programa.exe
```
<br>

### 3.3 Errores de compilación y soluciones

Durante el desarrollo del proyecto se presentaron diferentes errores y
problemas que fueron identificados y corregidos conforme se integraron las
clases y funciones del programa.

| Problema encontrado | Solución aplicada |
|---|---|
| La estructura inicial del programa se encontraba en un solo archivo. | Se reorganizó el proyecto utilizando archivos `.h` y `.cpp` para separar las clases y sus implementaciones. |
| Las clases necesitaban comunicarse entre sí para registrar participantes y robots dentro de los equipos. | Se establecieron relaciones entre las clases mediante métodos y objetos, por ejemplo, agregando objetos `Participante` y `Robot` a un `Equipo`. |
| Los robots necesitaban enfrentarse únicamente con robots de su misma disciplina. | Se recorrieron los robots registrados y se agruparon de acuerdo con su tipo antes de formar las batallas. |
| Los enfrentamientos necesitaban realizarse de manera aleatoria. | Se utilizó `rand()` para determinar aleatoriamente los ganadores y se mezclaron los robots antes de formar las parejas. |
| Podía quedar un robot sin pareja cuando había una cantidad impar de robots de una disciplina. | Se agregó una condición que detecta cuando un robot no tiene rival y muestra un mensaje indicando esta situación. |
| Era necesario validar que el tipo de robot fuera una disciplina permitida. | Se agregó una validación que solicita nuevamente el tipo de robot cuando se introduce un valor no válido. |
| El programa necesitaba generar diferentes resultados en cada ejecución. | Se utilizó `srand(time(0))` al inicio del programa para inicializar la generación de números aleatorios. |

<br>
<br>

## 4. Pruebas y depuraciones
### 4.1 Pruebas realizadas

Para comprobar el funcionamiento del programa se realizaron diferentes casos
de prueba, considerando diferentes cantidades de equipos y robots, así como
diferentes disciplinas.

| Caso | Escenario | Resultado esperado | Resultado obtenido | Estado |
|---|---|---|---|---|
| 1 | Un equipo con 2 robots del mismo tipo. | Los robots deben enfrentarse y debe mostrarse un ganador. | Se realizó una batalla y se mostró un ganador. | ✓ Aprobado |
| 2 | Varios equipos con participantes y robots. | Los equipos, participantes y robots deben registrarse correctamente. | La información se registró y se mostró correctamente. | ✓ Aprobado |
| 3 | Un solo robot de una disciplina. | El robot debe aparecer como un robot sin rival. | El programa indicó que el robot no tenía rival. | ✓ Aprobado |
| 4 | Tres robots del mismo tipo. | Debe realizarse una batalla y un robot debe quedar sin rival. | Se realizó una batalla y un robot quedó sin rival. | ✓ Aprobado |
| 5 | Cuatro robots del mismo tipo. | Deben realizarse dos batallas sin robots sin rival. | Se realizaron dos batallas correctamente. | ✓ Aprobado |
| 6 | Robots de diferentes disciplinas. | Solo deben enfrentarse robots de la misma disciplina. | Los robots fueron separados por disciplina y se enfrentaron correctamente. | ✓ Aprobado |
| 7 | Ejecutar varias veces la misma competencia. | Los emparejamientos y/o ganadores deben poder cambiar aleatoriamente. | Los emparejamientos y ganadores cambiaron entre ejecuciones. | ✓ Aprobado |
<br>

### 4.2 Errores encontrados y soluciones

Durante el desarrollo y las pruebas del programa se identificaron diferentes
problemas y aspectos que podían mejorarse. Estos fueron solucionados conforme
se fue integrando y probando el sistema.

| Problema o aspecto detectado | Solución aplicada |
|---|---|
| El código se encontraba inicialmente concentrado en un solo archivo. | Se separó el programa en clases y archivos `.h` y `.cpp`. |
| Era necesario almacenar varios participantes y robots dentro de cada equipo. | Se utilizaron `vector<Participante>` y `vector<Robot>` dentro de la clase `Equipo`. |
| La combinación de `cin` y `getline` podía ocasionar problemas al capturar datos. | Se utilizó `cin.ignore()` para limpiar el buffer antes de utilizar `getline()`. |
| Era necesario evitar el registro de disciplinas no válidas. | Se agregó una validación que solicita nuevamente el tipo de robot cuando no pertenece a las disciplinas permitidas. |
| Los enfrentamientos debían realizarse de manera aleatoria. | Se implementó una mezcla aleatoria de los robots antes de formar las parejas. |
| Podía quedar un robot sin rival cuando había una cantidad impar de robots. | Se agregó una condición para detectar y mostrar los robots que quedan sin rival. |
| Era necesario determinar aleatoriamente al ganador de cada batalla. | Se creó la clase `Batalla`, encargada de realizar el enfrentamiento y seleccionar al ganador. |
| La información mostrada durante la ejecución podía resultar confusa. | Se mejoró la presentación de la consola mediante títulos, separadores y mensajes descriptivos. |
| Durante algunas ejecuciones se presentó un comportamiento inesperado con la entrada de datos, mostrando repetidamente el mensaje de tipo de robot no válido. | Se identificó el comportamiento durante las pruebas y se revisó el proceso de captura y validación de datos. |
<br>


### 4.3 Optimizaciones

Durante el desarrollo se realizaron diferentes mejoras para organizar el
código y facilitar su funcionamiento y mantenimiento.

- Se dividieron las clases en archivos `.h` y `.cpp`, permitiendo separar las
  declaraciones de las implementaciones.

- Se utilizaron `vector` para almacenar dinámicamente los equipos,
  participantes y robots.

- Se separaron diferentes procesos en funciones como `registrarEquipo()`,
  `mostrarRegistro()` e `iniciarCompetencia()`, evitando concentrar todo el
  funcionamiento en `main()`.

- Se implementó la mezcla aleatoria de los robots antes de formar las
  parejas, permitiendo obtener diferentes enfrentamientos en cada ejecución.

- Se agregaron títulos, separadores y mensajes descriptivos en la consola para
  facilitar la lectura de la información durante la ejecución.

- Se utilizaron métodos `get` para acceder a los atributos privados de las
  clases, manteniendo el principio de encapsulamiento.
<br>
<br>

## 5. Mantenimiento

  ### 5.1 Mejoras futuras

Para futuras versiones del proyecto se consideran las siguientes mejoras:

- Incorporar herencia entre las clases relacionadas con los diferentes tipos
  de robots, de acuerdo con los temas que se trabajarán posteriormente en el
  curso.

- Agregar una interfaz gráfica para facilitar la interacción del usuario con
  el sistema.

- Implementar un sistema de clasificación que permita registrar los resultados
  de las batallas y determinar qué robots avanzan a las siguientes etapas.

- Permitir consultar el historial de batallas y resultados de la competencia.

- Mejorar la validación de las entradas para manejar diferentes tipos de
  datos introducidos incorrectamente por el usuario.

- Implementar un sistema para guardar los registros y resultados de la
  competencia, permitiendo conservar la información después de cerrar el
  programa.

 <br>

### 5.2 Lecciones aprendidas

Durante el desarrollo del proyecto se obtuvieron diferentes aprendizajes
relacionados con la programación orientada a objetos y con el proceso de
desarrollo de un programa.

- Se comprendió la importancia de identificar las entidades principales de un
  problema antes de comenzar a programar.

- Se reforzó el uso de clases y objetos para representar elementos de un
  problema real, como participantes, robots, equipos y batallas.

- Se comprendió la importancia del encapsulamiento mediante el uso de
  atributos privados y métodos públicos para acceder a la información.

- Se aprendió a utilizar `vector` para almacenar y manejar diferentes
  cantidades de objetos.

- Se reforzó el uso de archivos `.h` y `.cpp` para organizar y separar las
  diferentes partes del programa.

- Se comprendió cómo las diferentes clases pueden relacionarse y comunicarse
  mediante objetos y métodos.

- Se aprendió a utilizar números aleatorios para generar los enfrentamientos
  y determinar los ganadores de las batallas.

- Se comprendió la importancia de realizar pruebas durante el desarrollo para
  encontrar errores y mejorar el funcionamiento y presentación del programa.

- Se aprendió que el desarrollo de un programa requiere realizar cambios y
  mejoras conforme se prueba su funcionamiento.
<br>
<br>

## 6. Integrantes

| Integrante | Rol |
|---|---|
| Luis Samano Saavedra | Analista / líder de diseño |
| Jesus Rene Pamanes Ferreira | Programador principal |
| Daniel Gerardo Guerra Rodriguez | Programador de módulos |
| Yurik David Alarcon Gutierrez | Tester / QA |
| Fernando Caleb Roman Zamarripa | Documentador / presentador |