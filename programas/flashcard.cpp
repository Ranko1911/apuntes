#include <iostream>
#include <string>
#include <vector>
#include <fstream> // Para manejo de ficheros

// Estructura para almacenar las flashcards
struct FlashCard {
    std::string question;
    std::string answer;
};

// Función para mostrar las flashcards
void showFlashcards(const std::vector<FlashCard>& flashcards, int& correctCount,
                    int& incorrectCount, std::vector<int>& incorrectQuestions, std::vector<int>& correctQuestions) {
    size_t totalQuestions = flashcards.size();  // Total de preguntas

    for (size_t i = 0; i < totalQuestions; ++i) {
        std::cout << "Pregunta " << (i + 1) << " de " << totalQuestions << ": "
                  << flashcards[i].question << std::endl;
        std::cout << "Presiona Enter para ver la respuesta...";
        std::cin.ignore();  // Esperar que el usuario presione Enter
        std::cout << "Respuesta: " << flashcards[i].answer << std::endl;

        // Pedir al usuario que indique si la respuesta fue correcta o no
        char userResponse;
        std::cout << "¿Fue correcta la respuesta? (s/n): ";
        std::cin >> userResponse;

        if (userResponse == 's' || userResponse == 'S') {
            correctCount++;  // Aumentar conteo de aciertos
            correctQuestions.push_back(i);
        } else {
            incorrectCount++;  // Aumentar conteo de fallos
            incorrectQuestions.push_back(i);
        }

        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Presiona Enter para continuar a la siguiente pregunta...";
        std::cin.ignore();  // Esperar que el usuario presione Enter para continuar
        system("clear");    // limpiar la pantalla
    }
}

void mostrarindices(std::vector<int> indices) {
    std::cout << "[ ";
    for (size_t i = 0; i < indices.size(); ++i) {
        std::cout << indices[i] + 1 << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

// Función para cargar las flashcards desde un fichero
std::vector<FlashCard> loadFlashcards(const std::string& filename) {
    std::vector<FlashCard> flashcards;
    std::ifstream file(filename); // Abrir el fichero

    if (!file) {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
        return flashcards; // Retornar un vector vacío si no se puede abrir el fichero
    }

    std::string question, answer;
    while (std::getline(file, question) && std::getline(file, answer)) {
        flashcards.push_back({question, answer}); // Agregar la flashcard leída al vector
    }

    file.close(); // Cerrar el fichero
    return flashcards;
}

int main(int argc, char* argv[]) {
    // el primer argumento es el nombre del programa
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <fichero>" << std::endl;
        return 1; // Salir si no se proporciona el nombre del fichero
    }

    std::string filename = argv[1]; // Obtener el nombre del fichero de los argumentos

    // Cargar las flashcards desde un fichero
    std::vector<FlashCard> flashcards = loadFlashcards(filename);

    if (flashcards.empty()) {
        std::cout << "No se cargaron flashcards. Verifique el fichero." << std::endl;
        return 1; // Salir si no hay preguntas
    }

    // limpiar la pantalla
    system("clear");

    // Contadores de respuestas
    int correctCount = 0;
    int incorrectCount = 0;
    std::vector<int> incorrectQuestions;
    std::vector<int> correctQuestions;

    // Mostrar las flashcards
    showFlashcards(flashcards, correctCount, incorrectCount, incorrectQuestions, correctQuestions);

    // Mostrar el resultado final
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Resultados finales: " << std::endl;
    std::cout << "Aciertos: " << correctCount << std::endl;
    mostrarindices(correctQuestions);
    std::cout << "Fallos: " << incorrectCount << std::endl;
    mostrarindices(incorrectQuestions);

    return 0;
}
