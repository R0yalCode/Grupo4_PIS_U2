# Descripción del Proyecto

El proyecto se centra en desarrollar un sistema innovador de paneles solares que sean capaces de autodirigirse hacia la posición óptima del sol a lo largo del día. Esta tecnología busca maximizar la eficiencia en la captación de energía solar, crucial en un contexto global donde la transición hacia fuentes renovables es imperativa para mitigar el cambio climático.

### Definición del problema:
El desafío principal radica en optimizar la captación de energía solar a través de un seguimiento automático del sol. Esto implica calcular dinámicamente la posición del sol en el cielo en cualquier momento dado, considerando su movimiento a lo largo del día y del año. Este cálculo continuo es esencial para ajustar la orientación de los paneles solares y asegurar una exposición máxima a la radiación solar, lo que se traduce en una mayor eficiencia energética.

### Objetivos del proyecto:
El objetivo principal del proyecto es desarrollar un sistema de seguimiento solar preciso y eficiente que pueda implementarse en pequeña escala para aplicaciones cotidianas. Esto incluye proporcionar una metodología detallada basada en el Método SPA (Solar Position Algorithm), el cual permite calcular la posición del sol en función de la fecha, la hora y la ubicación geográfica específicas. Además, se busca integrar componentes eléctricos y algoritmos que gestionen el movimiento de los paneles solares de manera automática, optimizando así su rendimiento energético.

# Requisitos

#### Requisitos de Software:

###### Sistema Operativo
- Compatible con Windows, macOS o Linux.
###### Compilador de C
- **Windows**: Puedes utilizar MinGW, que proporciona el compilador GCC para Windows.  Para instalar MinGW ingresa [aqui](https://sourceforge.net/projects/mingw/files/).
- **macOS**: Xcode incluye el compilador de C, así que no se requiere una instalación adicional.
- **Linux**: Instala GCC a través de tu gestor de paquetes.
###### Visual Studio Code
- Descarga e instala Visual Studio Code desde su sitio web oficial. Para ir al sitio oficial ingresa [aqui](https://code.visualstudio.com/).
###### Extensiones para Visual Studio Code
- **C/C++**: Instala la extensión oficial de C/C++ proporcionada por Microsoft
###### Arduino IDE
- Descarga e instala Arduino IDE desde su sitio web oficial. Para ir al sitio oficial ingresa [aqui](http://www.arduino.cc/en/software "ir al sitio").
###### Librerias estándar de C
- Las librerias estandar de C, utilizadas son: 

      <stdio.h>: Para la entrada y salida estándar.
      <time.h>: Para trabajar con fechas y horas del sistema.
      <math.h>: Para funciones matemáticas como sin(), cos(), asin(), acos().

#### Requisitos de Hardware:
###### Plataforma Arduino

- Se necesitaría un Arduino uno R3
- Conexiones eléctricas adecuadas y conocimientos de cómo cargar y ejecutar el código en un Arduino.

###### Servomotor


- Dos servomotores para el seguimiento solar, que se moverán para orientar el panel solar hacia una posición óptima.
- Un servomotor se movera en el eje x, con los resultados del azimut.
- El otro servomotor se va a mover en el eje y, con los resultados de la altura solar.

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
###### Clonar el Repositorio
###### Abre Visual Studio Code

###### Abre la terminal integrada
- Ve al menú superior y selecciona Terminal > Nueva Terminal. Esto abrirá una terminal integrada en la parte inferior de la ventana de Visual Studio Code.

###### Ubícate en la carpeta donde deseas clonar el repositorio
- Utiliza el comando **cd** seguido de la ruta de la carpeta donde quieres que se clone el repositorio. Ejemplo, si quieres clonarlo en tu carpeta de proyectos, puedes hacer algo como:

      cd ~/Documentos/proyectos
Esto cambiará el directorio actual de la terminal a ~/Documentos/proyectos.
###### Clona el repositorio
- Clona el repositorio utilizando el siguiente comando: 

      git clone https://github.com/IsraelSRodriguezT/Grupo4_PIS_U2.git
###### Espera a que termine el proceso
- Una vez que se complete la clonación, verás un mensaje indicando que el repositorio se ha clonado correctamente.

###### Explora el repositorio
- En la barra lateral izquierda de Visual Studio Code, encontrarás un icono de explorador de archivos (parece un icono de carpeta).
- Haz clic en este icono para abrir el explorador de archivos.
- Busca y selecciona la carpeta del repositorio que acabas de clonar. Por lo general, estará ubicada en la ruta que especificaste al clonar el repositorio desde la terminal.
- Al hacer clic en la carpeta del repositorio, Visual Studio Code mostrará todos los archivos y carpetas dentro de ese repositorio en el área principal de trabajo.
- Una vez que has abierto el repositorio en Visual Studio Code, puedes navegar por los archivos y carpetas haciendo clic en ellos en el explorador de archivos.
- Para abrir el codigo tendras que buscar el siguiente archivo:
  
      PIS_Grupo4.c

- Simplemente haz clic en él y se abrirá en el editor de código de Visual Studio Code.
###### Compilar y Ejecutar el Código
- Utiliza las funciones integradas de Visual Studio Code para compilar y ejecutar el código.

# Uso
## Ejecución del Programa
#### Proporcionar Coordenadas Geográficas:
Una vez que el programa esté en ejecución, seguirá instrucciones para ingresar las coordenadas geográficas (latitud y longitud).

A continuacion se muestra un ejemplo de como se pueden proporcionar las coordenadas, teniendo en cuenta un rango de [-90,90] para la latitud y un rango de [-180,180] para la longitud.

Ejemplo de Entrada:

    Bienvenido al programa para calcular la direccion y altura del sol
    Se requieren de tus coordenadas para realizar el calculo
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
    -3.99313
    Ingresa como dato flotante el valor de la longitud de tu zona. Teniendo en cuenta el rango [-180,180]
    -79.20422

En este ejemplo, las coordenadas ingresadas son de Loja. El programa esperará que ingreses la latitud y la longitud en grados decimales.

Cabe recalcar que el programa solicitara ingresar coordenadas en un rango limite, entoces se espera la entrada de un valor flotante, no ingresar letras o simbolos.

A continuación se muestra un ejemplo de como se comportaria el programa si se ingresara letras y simbolos.

Ejemplo de Entrada con letras y simbolos:

    Bienvenido al programa para calcular la direccion y altura del sol
    Se requieren de tus coordenadas para realizar el calculo
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
    e
    Error: Entrada invalida. El dato ingresado no es un valor numerico
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
    t
    Error: Entrada invalida. El dato ingresado no es un valor numerico
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
    $
    Error: Entrada invalida. El dato ingresado no es un valor numerico
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
    %
    Error: Entrada invalida. El dato ingresado no es un valor numerico
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
Como se logra observar el programa va a generar un error ya que el dato ingresado no es un valor numérico, permitiendo ingresar un valor numérico para poder avansar. 



#### Resultados Esperados:
Después de ingresar las coordenadas, el programa realizará cálculos internos utilizando las ecuaciones astronómicas y trigonométricas definidas en el código. Los resultados esperados incluyen:

- Dirección geográfica de las coordenadas ingresadas.
- Fecha y hora actual del sistema.
- Cálculos como la declinación solar, ecuación del tiempo, tiempo solar verdadero, altura del sol y azimut.

#### Visualización de Resultados:
Los resultados se mostrarán en la terminal o línea de comandos después de que el programa haya realizado todos los cálculos necesarios. Asegúrate de revisar las salidas para verificar que los valores sean coherentes con la ubicación geográfica proporcionada.

##### Ejemplo de Ejecución
A continuación, te damos un ejemplo simplificado de cómo podría ser la ejecución del programa y algunos resultados esperados:




    
    Fecha: 17/6/2024 , Hora: 16:0
    Bienvenido al programa para calcular la direccion y altura del sol
    Se requieren de tus coordenadas para realizar el calculo
    Ingresa como dato flotante el valor de la latitud de tu zona. Teniendo en cuenta el rango [-90,90]
    -3.99313
    Ingresa como dato flotante el valor de la longitud de tu zona. Teniendo en cuenta el rango [-180,180]
    -79.20422
    Valor de latitud de su zona geografica 
    3.993130 S
    Valor de longitud de su zona geografica
    79.204224 O
    Fechas hasta ahora: 0 anios, 5 meses, 169 dias
    Valor de la declinacion solar 23.384757 en grados
    Valor de la ecuacion del tiempo -0.766234 en radianes
    Valor de la longitud estandar: -75
    Tu zona horaria es: -5
    Valor de la Hora solar:
    En decimales: 15.706948
    En horas: 15
    En minutos: 42
    Valor de H: 0.970477 en radianes
    Valor de la altura solar:
    En radianes: 0.511639
    En grados: 29.314764
    El valor del azimut cambio
    El valor del Azimut: 5.230799 en radianes
    El valor del Azimut: 299.702684 en grados
    Los valores que van a ir hacia el panel son:
    Para X: 299.702684 grados <-- Azimut
    Para Y: 29.314764 grados <-- Altura Solar

En este ejemplo, se muestra cómo el programa calcula la posición del sol para las coordenadas geográficas ingresadas que son de la provincia de Loja.

    Latitud: -3.99313
    Longitud: -79.20422
Fecha y hora del sistema 

    Fecha: 17/6/2024 
    Hora: 16:0
Y da como resultado el Azimut y la Altura solar

    Para X: 299.702684 grados <-- Azimut
    Para Y: 29.314764 grados <-- Altura Solar
Los resultados pueden variar dependiendo de la ubicación y la hora del día en que se ejecute el programa.

En el ejemplo realizado anteriormente se realizó con la fecha del dia 19 de junio del 2024 (4p.m) en el cual se utilizó las cordenadas planteadas anteriormente es decir las cordenandas de la Provincia de Loja.

# Autores: 
## [Israel Rodriguez](https://github.com/IsraelSRodriguezT)
## [Carlos Granda](https://github.com/Carlosjosu)
## [Royel Jima](https://github.com/R0yalCode)
## [Daniel Pardo](https://github.com/Dan1el17)
## [Juan Calopino](https://github.com/JuaaanCalopino)
