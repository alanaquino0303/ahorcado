#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <algorithm>

using namespace std;

// Dibuja el ahorcado según el número de fallos.
void mostrarAhorcado(int intentos) {
    vector<string> dibujo = {
        "  +---+",
        "  |   |",
        "      |",
        "      |",
        "      |",
        "      |",
        "========="};

    switch (intentos) {
        case 1: dibujo[2] = "  O   |"; break;
        case 2: dibujo[3] = "  |   |"; break;
        case 3: dibujo[3] = " /|   |"; break;
        case 4: dibujo[3] = " /|\\  |"; break;
        case 5: dibujo[4] = " /    |"; break;
        case 6: dibujo[4] = " / \\  |"; break;
    }

    for (const auto &linea : dibujo)
        cout << linea << endl;
}

// Carga palabras desde un archivo externo.
vector<string> cargarPalabrasDesdeArchivo(const string &nombreArchivo) {
    vector<string> palabras;
    ifstream archivo(nombreArchivo);
    string palabra;

    if (archivo.is_open()) {
        while (archivo >> palabra) {
            // Elimina posible BOM.
            if (palabra.size() >= 3 &&
                (unsigned char)palabra[0] == 0xEF &&
                (unsigned char)palabra[1] == 0xBB &&
                (unsigned char)palabra[2] == 0xBF) {
                palabra = palabra.substr(3);
            }

            if (!palabra.empty() && palabra.back() == '\r')
                palabra.pop_back();

            // Convierte toda la palabra a minúsculas.
            transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

            palabras.push_back(palabra);
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }

    return palabras;
}

// Lógica principal del juego.
void jugar(vector<string> palabras) {
    if (palabras.empty()) {
        cout << "No hay palabras disponibles. Crea o carga un archivo palabras.txt.\n";
        return;
    }

    srand(static_cast<unsigned>(time(0)));
    string palabraSecreta = palabras[rand() % palabras.size()];
    string palabraMostrada(palabraSecreta.size(), '_');
    set<char> letrasUsadas;
    int intentos = 0;
    const int MAX_INTENTOS = 6;
    bool gano = false;

    cout << "\nCOMIENZA EL JUEGO DEL AHORCADO\n";

    while (intentos < MAX_INTENTOS && !gano) {
        cout << "\nPalabra: " << palabraMostrada << endl;
        cout << "Intentos restantes: " << (MAX_INTENTOS - intentos) << endl;
        cout << "Letras usadas: ";
        for (char c : letrasUsadas) cout << c << ' ';
        cout << endl;

        mostrarAhorcado(intentos);

        cout << "\nIngresa una letra: ";
        char letra;
        cin >> letra;
        letra = tolower(letra);

        if (letrasUsadas.count(letra)) {
            cout << "Ya usaste esa letra. Intenta otra.\n";
            continue;
        }

        letrasUsadas.insert(letra);
        bool acierto = false;

        for (size_t i = 0; i < palabraSecreta.size(); ++i) {
            if (palabraSecreta[i] == letra) {
                palabraMostrada[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentos++;
            cout << "Letra incorrecta.\n";
        } else {
            cout << "¡Bien hecho!\n";
        }

        if (palabraMostrada == palabraSecreta)
            gano = true;
    }

    mostrarAhorcado(intentos);

    if (gano)
        cout << "\n¡Felicidades! Adivinaste la palabra: " << palabraSecreta << endl;
    else
        cout << "\nPerdiste. La palabra era: " << palabraSecreta << endl;
}

// Menú principal.
int main() {
    vector<string> palabras = {"programacion", "android", "ahorcado", "computadora"};
    int opcion;

    do {
        cout << "\nMENÚ PRINCIPAL\n\n";
        cout << "1. Jugar con palabras predeterminadas.\n";
        cout << "2. Cargar palabras desde archivo (palabras.txt).\n";
        cout << "3. Salir.\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugar(palabras);
                break;
            case 2: {
                vector<string> desdeArchivo = cargarPalabrasDesdeArchivo("palabras.txt");
                if (desdeArchivo.empty())
                    cout << "No se encontraron palabras en el archivo.\n";
                else
                    jugar(desdeArchivo);
                break;
            }
            case 3:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intenta de nuevo.\n";
                break;
        }

    } while (opcion != 3);

    return 0;
}