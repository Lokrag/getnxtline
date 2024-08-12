*****utils strlen:

calcula la longitud de una cadena de caracteres.
**Entrada: La función recibe un parámetro:
Una cadena de caracteres (s).
**Proceso:
La función inicializa un contador (i) en 0.
Luego, recorre la cadena de caracteres, incrementando el contador por cada carácter encontrado hasta llegar al carácter nulo (\0), que indica el final de la cadena.
Salida:
La función devuelve el valor del contador (i), que representa la longitud de la cadena (es decir, el número de caracteres en la cadena, excluyendo el carácter nulo final).
Esta función es útil para determinar cuántos caracteres hay en una cadena antes de realizar operaciones adicionales con ella

*****utils strchr:

La función ft_strchr busca la primera aparición de un carácter específico en una cadena de caracteres.
*Entrada: La función recibe dos parámetros:
Una cadena de caracteres (s).
Un carácter (c) que se desea buscar en la cadena.
Proceso: La función recorre la cadena de caracteres desde el principio hasta el final, comparando cada carácter de la cadena con el carácter buscado (c).
*Salida:
Si encuentra el carácter buscado, la función devuelve un puntero a la primera aparición de ese carácter en la cadena.
Si no encuentra el carácter, devuelve un puntero nulo (NULL).
Esta función es útil para localizar rápidamente un carácter en una cadena y trabajar con la parte de la cadena que sigue a ese carácter

*****utils strjoin:
combina dos cadenas de caracteres en una sola.

**Entrada: La función recibe dos parámetros:
s1: la primera cadena de caracteres.
s2: la segunda cadena de caracteres.
**Proceso:
Verificación inicial: Si ambas cadenas son nulas, la función retorna un puntero nulo ('\0').
Calcular longitudes: Se calculan las longitudes de s1 y s2 usando ft_strlen.
Asignar memoria: Se asigna memoria suficiente para la nueva cadena, que será la suma de las longitudes de s1 y s2, más uno adicional para el carácter nulo final.
Verificación de memoria: Si la asignación de memoria falla, la función retorna un puntero nulo.
Copiar s1: Se copia el contenido de s1 en la nueva cadena.
Copiar s2: Se copia el contenido de s2 justo después del contenido de s1 en la nueva cadena.
Añadir carácter nulo: Se añade el carácter nulo al final de la nueva cadena para indicar el final de la cadena.
Salida: La función devuelve un puntero a la nueva cadena que contiene la concatenación de s1 y s2.
Esta función es útil para combinar dos cadenas en una sola, lo que puede ser muy práctico en diversas situaciones de programación.

***** utils memset:
La función ft_memset en C se utiliza para llenar un bloque de memoria con un valor específico. Toma tres parámetros: un puntero al bloque de memoria, el valor con el que quieres llenar la memoria, y el número de bytes que deseas llenar.

**Proceso:
Conversión del puntero: Primero, convierte el puntero al bloque de memoria a un tipo que permite trabajar con bytes individuales.
Bucle de llenado: Luego, utiliza un bucle que se repite tantas veces como bytes se quieran llenar. En cada iteración del bucle, asigna el valor especificado a la posición actual del puntero y avanza a la siguiente posición.
Decremento del contador: Reduce el contador de bytes restantes en cada iteración hasta que todos los bytes hayan sido llenados.
Retorno del puntero: Finalmente, devuelve el puntero original al bloque de memoria.
Esta función es útil para inicializar bloques de memoria con un valor específico, como cuando quieres poner todos los bytes de un array a cero.

***** utils calloc:
se utiliza para asignar memoria para un número específico de elementos, y luego inicializa esa memoria a cero.

**Proceso:
Asignación de memoria: La función toma dos parámetros: el número de elementos y el tamaño de cada elemento. Multiplica estos dos valores para determinar la cantidad total de memoria que necesita asignar.
Inicialización a cero: Después de asignar la memoria, la función inicializa todos los bytes de esta memoria a cero. Esto asegura que la memoria esté limpia y no contenga datos residuales.
Retorno del puntero: Finalmente, la función devuelve un puntero a la memoria asignada e inicializada.
Esta función es útil cuando necesitas un bloque de memoria para un array o estructura y quieres asegurarte de que todos los valores iniciales sean cero.


**************************************principal***********************************************

La función **ft_read_fd** en C se utiliza para leer datos de un archivo o entrada utilizando un descriptor de archivo (file descriptor). 
Aquí tienes una explicación y su pseudocódigo:

Explicación:
Parámetros:
int fd: El descriptor de archivo desde el cual se leerán los datos.
char *unfiltered_line: Un puntero a un buffer donde se almacenarán los datos leídos.
int *bytes_read: Un puntero a un entero donde se almacenará el número de bytes leídos.
Proceso:
La función lee datos del archivo o entrada especificada por el descriptor de archivo fd.
Los datos leídos se almacenan en el buffer unfiltered_line.
El número de bytes leídos se almacena en la variable apuntada por bytes_read.
Retorno:
La función devuelve un puntero al buffer unfiltered_line que contiene los datos leídos.

**********Pseudocódigo***********

función ft_read_fd(fd, unfiltered_line, bytes_read)
    inicializar buffer temporal
    leer datos desde fd al buffer temporal
    si la lectura es exitosa
        copiar datos del buffer temporal a unfiltered_line
        actualizar bytes_read con el número de bytes leídos
    fin si
    retornar unfiltered_line
fin función

Desglose del Pseudocódigo:
Inicialización: Se inicializa un buffer temporal para almacenar los datos leídos.
Lectura de datos: Se leen los datos desde el descriptor de archivo fd al buffer temporal.
Verificación y copia: Si la lectura es exitosa, se copian los datos del buffer temporal a unfiltered_line y se actualiza bytes_read con el número de bytes leídos.
Retorno: Se retorna el puntero unfiltered_line.
Este pseudocódigo refleja los pasos básicos que realiza la función ft_read_fd

******************************

la función **ft_filter_line** y luego te proporcionaré un pseudocódigo.

Explicación
La función ft_filter_line tiene como objetivo extraer una línea completa de una cadena no filtrada (unfiltered_line). Aquí está el flujo general de la función:

Declaración de variables:
i: Un índice para recorrer la cadena.
filtered_line: La cadena que contendrá la línea filtrada.
Comprobación inicial:
Si el primer carácter de unfiltered_line es nulo, la función retorna un carácter de nueva línea ('\n').
Recorrido de la cadena:
La función recorre unfiltered_line hasta encontrar un carácter de nueva línea ('\n') o el final de la cadena.
Asignación de memoria:
Se asigna memoria para filtered_line utilizando ft_calloc, con espacio suficiente para la línea y un carácter adicional.
Comprobación de la asignación:
Si la asignación de memoria falla, la función retorna un carácter nulo ('\0').
Copia de la línea:
La función copia los caracteres de unfiltered_line a filtered_line hasta encontrar un carácter de nueva línea o el final de la cadena.
Incluir el carácter de nueva línea:
Si se encuentra un carácter de nueva línea, también se copia a filtered_line.
Retorno de la línea filtrada:
La función retorna filtered_line, que contiene la línea extraída de unfiltered_line.

**********************Pseudocódigo

función ft_filter_line(unfiltered_line)
    declarar i = 0
    declarar filtered_line

    si el primer carácter de unfiltered_line es nulo entonces
        retornar carácter de nueva línea

    mientras unfiltered_line[i] no sea nulo y no sea nueva línea
        incrementar i

    asignar memoria para filtered_line con tamaño i + 2

    si la asignación de memoria falla entonces
        retornar carácter nulo

    reiniciar i a 0

    mientras unfiltered_line[i] no sea nulo y no sea nueva línea
        copiar unfiltered_line[i] a filtered_line[i]
        incrementar i

    si unfiltered_line[i] es nueva línea
        copiar unfiltered_line[i] a filtered_line[i]
        incrementar i

    retornar filtered_line


********************


la función ft_rest_unfiltered y luego te proporcionaré un pseudocódigo.

Explicación
La función ft_rest_unfiltered tiene como objetivo extraer el contenido restante de una cadena no filtrada (unfiltered_line) después de haber extraído una línea completa. Aquí está el flujo general de la función:

Declaración de variables:
i: Un índice para recorrer la cadena.
j: Un índice para la nueva cadena rest_line.
rest_line: La cadena que contendrá el contenido restante.
Recorrido inicial de la cadena:
La función recorre unfiltered_line hasta encontrar un carácter de nueva línea ('\n') o el final de la cadena.
Comprobación de fin de cadena:
Si se llega al final de la cadena (unfiltered_line[i] es nulo), se libera la memoria de unfiltered_line y se retorna un carácter nulo ('\0').
Asignación de memoria:
Se asigna memoria para rest_line utilizando ft_calloc, con espacio suficiente para el contenido restante.
Comprobación de la asignación:
Si la asignación de memoria falla, la función retorna un carácter nulo ('\0').
Copia del contenido restante:
La función copia los caracteres restantes de unfiltered_line a rest_line.
Liberación de memoria:
Se libera la memoria de unfiltered_line.
Retorno del contenido restante:
La función retorna rest_line, que contiene el contenido restante de unfiltered_line.

*********************Pseudocódigo

función ft_rest_unfiltered(unfiltered_line)
    declarar i = 0
    declarar j = 0
    declarar rest_line

    mientras unfiltered_line[i] no sea nulo y no sea nueva línea
        incrementar i

    si unfiltered_line[i] es nulo entonces
        liberar memoria de unfiltered_line
        retornar carácter nulo

    asignar memoria para rest_line con tamaño de la longitud de unfiltered_line menos i más
    si la asignación de memoria falla entonces
        retornar carácter nulo

    incrementar i
    incrementar j

    mientras unfiltered_line[i] no sea nulo
        copiar unfiltered_line[i] a rest_line[j]
        incrementar i
        incrementar j

    liberar memoria de unfiltered_line
    retornar rest_line



********************	



la función ***get_next_line*** y luego te proporcionaré un pseudocódigo.

Explicación
La función get_next_line tiene como objetivo leer una línea de un archivo, utilizando un descriptor de archivo (fd). Aquí está el flujo general de la función:

Declaración de variables:
next_line: Almacena la próxima línea que se leerá.
unfiltered_line: Una variable estática que almacena el contenido no procesado del archivo.
bytes_read: Almacena el número de bytes leídos del archivo.
Comprobación de condiciones iniciales:
Si el descriptor de archivo (fd) es mayor que 0 o el tamaño del buffer (BUFFER_SIZE) es menor o igual a 0, la función retorna un carácter nulo ('\0').
Lectura del archivo:
La función ft_read_fd lee del archivo y actualiza unfiltered_line y bytes_read.
Comprobación de la lectura:
Si unfiltered_line es nulo después de la lectura, la función retorna un carácter nulo ('\0').
Filtrado de la línea:
ft_filter_line procesa unfiltered_line para obtener la próxima línea completa y la almacena en next_line.
Actualización de unfiltered_line:
ft_rest_unfiltered actualiza unfiltered_line con el contenido restante después de extraer next_line.
Comprobación final:
Si next_line es nulo y no se han leído más bytes (bytes_read es 0), se libera la memoria de unfiltered_line y se retorna un carácter nulo ('\0').
Retorno de la línea:
La función retorna next_line, que contiene la próxima línea leída del archivo.

***Pseudocódigo

función get_next_line(fd)
    declarar next_line
    declarar estática unfiltered_line
    declarar bytes_read

    si fd > 0 o BUFFER_SIZE <= 0 entonces
        retornar carácter nulo

    unfiltered_line = leer del archivo (fd, unfiltered_line, bytes_read)

    si unfiltered_line es nulo entonces
        retornar carácter nulo

    next_line = filtrar línea (unfiltered_line)
    unfiltered_line = actualizar línea no filtrada (unfiltered_line)

    si next_line es nulo y bytes_read es 0 entonces
        liberar memoria de unfiltered_line
        retornar carácter nulo

    retornar next_line


