# Ahorcado en C++

Juego **Ahorcado** implementado en C++ para ejecución en consola. El programa permite jugar seleccionando palabras desde un archivo externo o usando una lista interna. Muestra un dibujo ASCII del ahorcado, cuenta los intentos, valida entradas y ofrece un menú interactivo.

## Características principales

- Implementado completamente en C++.
- Dibujo ASCII del ahorcado según el número de fallos.
- Selección de palabras desde un archivo (`palabras.txt`) o lista interna.
- Control de letras usadas, número de intentos y condiciones de victoria o derrota.
- Menú principal con opciones de jugar, cargar palabras o salir.
- Compatible con sistemas Linux, macOS y Windows.

## Estructura del proyecto
```
/ ahorcado
├── ahorcado.cpp     # Código fuente principal.
├── README.md        # Documentación principal.
```

## Requisitos

- Compilador C++ (g++, clang++).
- Sistema operativo **Linux**, **macOS** o **Windows**.
- Archivo de palabras (opcional) con una palabra por línea en texto plano.

## Ejecución del programa

### Compilación y ejecución en Linux / macOS

   ```bash
   # Compilar
   g++ -std=c++17 ahorcado.cpp -o ahorcado
   ```

   ```bash
   # Ejecutar
   ./ahorcado
   ```
   
### Compilación y ejecución en Windows

   ```bash
   # Compilar
   g++ -std=c++17 ahorcado.cpp -o ahorcado.exe
   ```

   ```bash
   # Ejecutar
   ahorcado.exe
   ```

---

## Autor

Alan Aquino.
