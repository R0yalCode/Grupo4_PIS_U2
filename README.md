# Descripción del Proyecto

El proyecto se centra en desarrollar un sistema innovador de paneles solares que sean capaces de autodirigirse hacia la posición óptima del sol a lo largo del día. Esta tecnología busca maximizar la eficiencia en la captación de energía solar, crucial en un contexto global donde la transición hacia fuentes renovables es imperativa para mitigar el cambio climático.

#### Definición del problema:
El desafío principal radica en optimizar la captación de energía solar a través de un seguimiento automático del sol. Esto implica calcular dinámicamente la posición del sol en el cielo en cualquier momento dado, considerando su movimiento a lo largo del día y del año. Este cálculo continuo es esencial para ajustar la orientación de los paneles solares y asegurar una exposición máxima a la radiación solar, lo que se traduce en una mayor eficiencia energética.

#### Objetivos del proyecto:
El objetivo principal del proyecto es desarrollar un sistema de seguimiento solar preciso y eficiente que pueda implementarse en pequeña escala para aplicaciones cotidianas. Esto incluye proporcionar una metodología detallada basada en el Método SPA (Solar Position Algorithm), el cual permite calcular la posición del sol en función de la fecha, la hora y la ubicación geográfica específicas. Además, se busca integrar componentes eléctricos y algoritmos que gestionen el movimiento de los paneles solares de manera automática, optimizando así su rendimiento energético.

# Requisitos

#### Requisitos de Software:

###### Sistema Operativo
El programa está diseñado para ser ejecutado en un entorno que soporte compiladores de C estándar, como Windows.
###### Compilador de C
Se requiere un compilador de C compatible (por ejemplo, GCC en Windows o cualquier compilador que admita las bibliotecas estándar utilizadas).
###### Bibliotecas estándar de C
Las bibliotecas estándar utilizadas (stdio.h, time.h, math.h) deben estar disponibles y ser accesibles para el compilador.
###### Biblioteca windows.h
Específicamente requerida si se está desarrollando para el entorno Windows para algunas funciones relacionadas con el tiempo.
#### Requisitos de Hardware

###### Plataforma Arduino

- Se necesitaría un Arduino uno R3
- Conexiones eléctricas adecuadas y conocimientos de cómo cargar y ejecutar el código en un Arduino.

###### Servomotor
- Dos servomotores para el seguimiento solar, que se moverá para orientar el panel solar hacia la posición óptima.

###### Placa de Protoboard
- Una placa de protoboard para montar los componentes de forma provisional y facilitar las conexiones.

###### Cables y Conectores
- Cables de conexión para realizar las conexiones eléctricas entre los componentes (Arduino, sensores, servomotor) y la placa de protoboard.

###### Computadora con Puerto USB
- Para cargar el código en la placa Arduino, necesitarás una computadora con un puerto USB estándar.
- Instalación previa del entorno de desarrollo integrado (IDE) de Arduino en tu computadora.

##### Detalles Adicionales:

- El programa hace uso intensivo de operaciones matemáticas estándar y trigonométricas, por lo que un hardware capaz de manejar estas operaciones de manera eficiente sería ideal.
- Para la simulación y desarrollo en un entorno de escritorio, una computadora con suficiente capacidad de procesamiento y memoria para compilar y ejecutar el código sería adecuada.


# Instrucciones de Instalación
### Pasos para Clonar y Compilar
###### Clonar el Repositorio:
Abre Visual Studio Code y clona el repositorio que contiene el código del proyecto:

- Abre el terminal integrado en Visual Studio Code 

- Clona el repositorio utilizando el comando 

    

    git clone <URL_del_repositorio>
    
Cambia al directorio del proyecto clonado utilizando el comando "cd".

###### Compilar y Ejecutar el Código
- Utiliza las funciones integradas de Visual Studio Code para compilar y ejecutar el código.


# Uso
## Ejecución del Programa
#### Compilación del Programa:
Asegúrate de haber compilado el programa según las instrucciones proporcionadas en la sección anterior. Esto generará el ejecutable que podrás utilizar para ejecutar el programa principal.

#### Ejecución del Programa:
Desde la terminal o línea de comandos, navega hasta el directorio donde se encuentra el ejecutable compilado. Luego, ejecuta el programa con el siguiente comando:




    ./nombre_del_ejecutable
Sustituye "nombre_del_ejecutable" por el nombre que hayas elegido durante la compilación del programa.

#### Proporcionar Coordenadas Geográficas:
Una vez que el programa esté en ejecución, seguirá instrucciones para ingresar las coordenadas geográficas (latitud y longitud). Aquí te mostraré un ejemplo de cómo se pueden proporcionar coordenadas:

Ejemplo de Entrada:




    Bienvenido al programa para calcular la dirección y altura del sol.
    Se requiere de tus coordenadas para realizar el cálculo.
    
    Ingresa la latitud: -3.99313
    Ingresa la longitud: -79.20422
En este ejemplo, las coordenadas ingresadas son de Loja. El programa esperará que ingreses la latitud y la longitud en grados decimales.

#### Resultados Esperados:
Después de ingresar las coordenadas, el programa realizará cálculos internos utilizando las ecuaciones astronómicas y trigonométricas definidas en el código. Los resultados esperados podrían incluir:

- Dirección geográfica de las coordenadas ingresadas.
- Fecha y hora actual del sistema.
- Cálculos como la declinación solar, ecuación del tiempo, tiempo solar verdadero, altura del sol y azimut.

#### Visualización de Resultados:
Los resultados se mostrarán en la terminal o línea de comandos después de que el programa haya realizado todos los cálculos necesarios. Asegúrate de revisar las salidas para verificar que los valores sean coherentes con la ubicación geográfica proporcionada.

##### Ejemplo de Ejecución
A continuación, te damos un ejemplo simplificado de cómo podría ser la ejecución del programa y algunos resultados esperados:




    $ ./mi_programa
    Fecha: 16/06/2024 , Hora: 10:30
    
    Bienvenido al programa para calcular la dirección y altura del sol.
    Se requiere de tus coordenadas para realizar el cálculo.
    
    Ingresa la latitud: -3.99313
    Ingresa la longitud: -79.20422
    
    Valor de latitud de su zona geográfica
    3.993130 S
    Valor de longitud de su zona geográfica
    79.204220 O
    
    Fechas hasta ahora: 0 años, 6 meses, 16 días
    
    Valor de la declinación solar -23.364773 en grados
    
    Valor de la ecuación del tiempo -0.206206 en radianes
    
    Valor de la longitud estándar: -75
    Tu zona horaria es: -5
    
    Valor de la Hora solar:
    En decimales: 10.423794
    En horas: 10
    En minutos: 25
    
    Valor de H: 3.662078 en radianes
    Valor de la altura solar:
    En radianes: 0.063932
    En grados: 3.662078
    
    El valor del Azimut: 3.123246 en radianes
    El valor del Azimut: 179.158240 en grados
En este ejemplo, se muestra cómo el programa calcula la posición del sol para las coordenadas geográficas ingresadas. Los resultados pueden variar dependiendo de la ubicación y la hora del día en que se ejecute el programa.
