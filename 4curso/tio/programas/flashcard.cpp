#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Estructura para almacenar las flashcards
struct FlashCard {
    std::string question;
    std::string answer;
};

// Función para leer el archivo txt y cargar las flashcards
void loadFlashcards(const std::string& filename, std::vector<FlashCard>& flashcards) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << filename << std::endl;
        return;
    }

    std::string question, answer;
    while (std::getline(file, question)) {
        if (std::getline(file, answer)) {
            flashcards.push_back({question, answer});
            std::string emptyLine; // Leer la línea vacía
            std::getline(file, emptyLine);
        }
    }

    file.close();
}

// Función para mostrar las flashcards
void showFlashcards(const std::vector<FlashCard>& flashcards, int& correctCount, int& incorrectCount, std::vector<int>& incorrectQuestions, std::vector<int>& correctQuestions) {
    size_t totalQuestions = flashcards.size();  // Total de preguntas

    for (size_t i = 0; i < totalQuestions; ++i) {
        std::cout << "Pregunta " << (i + 1) << " de " << totalQuestions << ": " << flashcards[i].question << std::endl;
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
        std::cin.ignore();  // Consumir el segundo Enter
    }
}

void mostrarIndices(std::vector<int> indices) {
    std::cout << "[ ";
    for (size_t i = 0; i < indices.size(); ++i) {
        std::cout << indices[i] + 1 << " ";
    }
    std::cout << "]" << std::endl;
}

int main(int argc, char* argv[]) {
    // Verificar si se proporcionó el nombre del archivo
    if (argc < 2) {
        std::cerr << "Uso: " << argv[0] << " <nombre_del_archivo>" << std::endl;
        return 1;
    }

    // Obtener el nombre del archivo desde la línea de comandos
    std::string filename = argv[1];

    // Crear un vector de flashcards
    std::vector<FlashCard> flashcards;

    // Cargar las flashcards desde el archivo txt
    loadFlashcards(filename, flashcards);

    if (flashcards.empty()) {
        std::cerr << "No se cargaron preguntas." << std::endl;
        return 1;
    }

    // Limpiar la pantalla
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
    mostrarIndices(correctQuestions);
    std::cout << "Fallos: " << incorrectCount << std::endl;
    mostrarIndices(incorrectQuestions);

    return 0;
}
