# Sistema de Gestión de Competencia de Robótica Estudiantil

## 1. Análisis y Diseño

### 1.1 Descripción del problema

El proyecto consiste en desarrollar un sistema de gestión para una competencia de robótica utilizando programación orientada a objetos en C++. El sistema deberá permitir registrar los equipos que participarán en la competencia, así como sus participantes y robots.

Cada participante deberá registrarse con su nombre y carrera, mientras que cada robot deberá registrarse con su nombre y disciplina. Las disciplinas consideradas a participar son sumo, seguidor de línea, laberinto y velocista.

Una vez terminado el registro, el sistema deberá organizar los robots de acuerdo con su disciplina y formar enfrentamientos aleatorios entre robots del mismo tipo. Para cada enfrentamiento se deberá determinar aleatoriamente un ganador.

Finalmente, el programa deberá mostrar la información de los equipos, participantes y robots registrados, así como los resultados de las batallas realizadas.


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

### 3.2 Ejecución

Después de compilar correctamente el proyecto, se ejecutó el programa desde
la terminal de Visual Studio Code utilizando el siguiente comando:

```powershell
.\programa.exe
```

### 3.3 Errores de compilación y soluciones