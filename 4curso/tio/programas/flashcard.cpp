#include <iostream>
#include <string>
#include <vector>

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

int main() {
  // Crear un vector de flashcards
  std::vector<FlashCard> flashcards = {
      {"¿Cuál es el problema central que aborda el texto?",
       "La dificultad de gestionar la sobreabundancia de datos en contraste "
       "con la necesidad de obtener información útil para la toma de "
       "decisiones."},
      {"¿Qué se propone como solución inicial para el problema de la "
       "sobreabundancia de datos?",
       "Iniciar un debate serio sobre cómo solucionar el problema, comenzando "
       "por definir con claridad qué son los datos y qué es la información."},
      {"¿Qué son los datos según el texto?",
       "Los datos son descripciones objetivas de elementos de la realidad, "
       "como la dirección de un proveedor o el contenido de un almacén."},
      {"¿Qué es la información según el texto?",
       "La información son los datos que influyen en una acción o decisión. El "
       "mismo conjunto de datos puede convertirse en información dependiendo "
       "de las circunstancias o necesidades."},
      {"¿Cuál es el principal problema con los sistemas de información "
       "actuales?",
       "Muchos sistemas llamados 'de información' son en realidad sistemas de "
       "datos que sobrecargan a los usuarios con datos sin procesar en lugar "
       "de facilitar información relevante para la toma de decisiones."},
      {"¿Cómo se define la información en relación con la toma de decisiones?",
       "La información no es lo que entra en el proceso de decisión (datos), "
       "sino lo que sale de él, es decir, el resultado de la decisión."},
      {"¿Por qué es difícil diseñar sistemas de información eficaces?",
       "Debido a que es complicado anticipar qué datos se convertirán en "
       "información, ya que las necesidades cambian constantemente."},
      {"¿Qué ha cambiado en la toma de decisiones en la industria moderna?",
       "La toma de decisiones ha evolucionado, y se necesita que los sistemas "
       "de información se ajusten a las nuevas filosofías de dirección "
       "empresarial."},
      {"¿Qué debe integrar un sistema de información eficaz?",
       "Un sistema de información eficaz debe estar integrado con el proceso "
       "de toma de decisiones para ser verdaderamente útil."},
      {"¿Qué es necesario para crear soluciones eficaces en los sistemas de "
       "información?",
       "Es necesario considerar las nuevas filosofías gerenciales y cómo éstas "
       "influyen en la toma de decisiones para diseñar sistemas de información "
       "más efectivos."},
      {"¿Qué implica definir la información como 'la respuesta a lo que se ha "
       "preguntado'?",
       "Implica que la información no es lo que entra en el proceso de "
       "decisión (datos), sino lo que sale de él como resultado de dicho "
       "proceso."},
      // {"¿Qué consecuencia tiene aceptar la definición de información como "
      //  "resultado de una decisión?",
      //  "Aceptar esta definición implica que el proceso de toma de decisiones "
      //  "debe estar formalizado e integrado en el sistema de información."},
      // {"¿Qué crítica se hace a la sobrecarga de datos en los sistemas "
      //  "actuales?",
      //  "Se critica que los sistemas tienden a generar reportes extensos que "
      //  "abarcan demasiados datos, lo que ahoga a los usuarios en información "
      //  "irrelevante."},
      // {"¿Cuál es el peligro de centrarse demasiado en la recopilación de "
      //  "datos?",
      //  "El peligro es que las organizaciones se inmersan en el esfuerzo de "
      //  "recopilar y mantener enormes cantidades de datos, en lugar de "
      //  "centrarse en la información útil para la toma de decisiones."},
      // {"¿Cómo ha afectado la tecnología de la información a la generación de "
      //  "informes voluminosos?",
      //  "Aunque los ordenadores personales y la posibilidad de trabajar en "
      //  "línea han mitigado este problema en parte, las ideas subyacentes que "
      //  "impulsan la acumulación excesiva de datos siguen presentes."},
      // {"¿Cuál es el propósito de un sistema de información ideal según el "
      //  "texto?",
      //  "Proporcionar información relevante para todos los directivos de una "
      //  "organización, facilitando la toma de decisiones en todas las áreas de "
      //  "gestión."},
      // {"¿Qué anécdota se menciona sobre el manejo de datos en el ejército "
      //  "israelí?",
      //  "Un capitán del departamento de ordenadores ordenó detener la impresión "
      //  "de listados con más de 100 páginas, y solo recibió una queja de un "
      //  "archivista, lo que resalta la falta de uso real de esos informes."},
      // {"¿Qué simboliza la anécdota del ejército israelí?",
      //  "Simboliza cómo muchas organizaciones generan grandes volúmenes de "
      //  "datos sin que estos sean realmente útiles o necesarios para los "
      //  "usuarios."},
      // {"¿Cuál es el error lógico que menciona el texto sobre los sistemas de "
      //  "información actuales?",
      //  "El error es creer que un sistema que recopila enormes cantidades de "
      //  "datos también está proporcionando información relevante, cuando en "
      //  "realidad no es así."},
      // {"¿Qué se sugiere para crear sistemas de información más efectivos?",
      //  "Se sugiere que los sistemas de información deben diseñarse teniendo en "
      //  "cuenta la toma de decisiones y ajustarse a las nuevas filosofías "
      //  "gerenciales que han surgido en la industria."},
      // {"¿Cuál es el papel que juega el contexto en la definición de "
      //  "información?",
      //  "La información depende del contexto y de quién la esté utilizando; lo "
      //  "que es información para una persona puede ser solo un dato para otra "
      //  "en diferentes circunstancias."},

      // {"¿Por qué es crucial entender la diferencia entre datos e información?",
      //  "Comprender esta diferencia es fundamental para desarrollar sistemas de "
      //  "información que realmente ayuden en la toma de decisiones en lugar de "
      //  "simplemente acumular datos."},

      // {"¿Qué se ha perdido en la gestión de datos según el autor?",
      //  "Se ha perdido el rumbo en la gestión de datos, donde la acumulación de "
      //  "información ha superado la utilidad práctica de la misma para la toma "
      //  "de decisiones."},

      // {"¿Qué implica la formalización del proceso de toma de decisiones?",
      //  "Implica establecer un método claro y estructurado que se pueda "
      //  "integrar en los sistemas de información para que estos puedan "
      //  "proporcionar datos relevantes en el momento adecuado."},

      // {"¿Cómo se relaciona la filosofía de dirección con los sistemas de "
      //  "información?",
      //  "La filosofía de dirección influye en cómo se diseñan los sistemas de "
      //  "información, ya que estos deben adaptarse a las nuevas formas de "
      //  "pensar sobre la gestión y la toma de decisiones."},

      // {"¿Qué efecto tiene la revolución en la gestión empresarial en los "
      //  "sistemas de información?",
      //  "La revolución en la gestión empresarial exige que los sistemas de "
      //  "información evolucionen para satisfacer nuevas demandas y enfoques en "
      //  "la toma de decisiones."},

      // {"¿Qué crítica se hace a los informes generados por los sistemas de "
      //  "datos?",
      //  "Se critica que los informes son demasiado voluminosos y abarcan "
      //  "demasiadas preguntas, lo que dificulta la identificación de la "
      //  "información realmente útil."},

      // {"¿Qué solución propone el texto para el problema de la acumulación de "
      //  "datos?",
      //  "La solución propuesta es diseñar sistemas de información que se "
      //  "centren en proporcionar información útil y relevante, en lugar de "
      //  "simplemente recopilar datos."},

      // {"¿Cómo ha cambiado la naturaleza de la toma de decisiones en las "
      //  "organizaciones?",
      //  "La toma de decisiones ha pasado a ser un proceso más dinámico y "
      //  "adaptativo, lo que requiere sistemas de información más flexibles y "
      //  "responsivos."},

      // {"¿Qué se debe tener en cuenta al diseñar sistemas de información?",
      //  "Se debe considerar el proceso de toma de decisiones y las diversas "
      //  "áreas de gestión que serán impactadas por la información que esos "
      //  "sistemas proporcionen."},

      // {"¿Qué se entiende por sobreabundancia de datos?",
      //  "La sobreabundancia de datos se refiere a la situación en la que hay "
      //  "más datos disponibles de los que se pueden procesar o utilizar "
      //  "efectivamente para la toma de decisiones."},

      // {"¿Cuál es una de las principales quejas sobre los sistemas de "
      //  "información?",
      //  "Una de las principales quejas es que muchos sistemas son solo sistemas "
      //  "de datos, en lugar de sistemas que proporcionen información útil y "
      //  "procesada."},

      // {"¿Qué ejemplo se da sobre un dato y su transformación en información?",
      //  "La dirección de un proveedor es un dato, pero se convierte en "
      //  "información cuando se necesita para enviar una carta de reclamación."},

      // {"¿Cómo pueden influir las decisiones en la percepción de los datos?",
      //  "Los datos pueden ser percibidos como información dependiendo de la "
      //  "decisión que se deba tomar en un momento determinado."},

      // {"¿Qué se debe considerar al intentar definir un sistema de información "
      //  "eficaz?",
      //  "Se debe considerar cómo el sistema puede adaptarse a diversas áreas de "
      //  "gestión y a las diferentes decisiones que se toman en la "
      //  "organización."},

      // {"¿Qué se critica sobre la cantidad de datos en los sistemas actuales?",
      //  "Se critica que los sistemas actuales generan un exceso de datos sin "
      //  "filtrar, lo que dificulta la identificación de la información "
      //  "relevante."},

      // {"¿Cuál es un problema frecuente al diseñar sistemas de información?",
      //  "Un problema frecuente es la dificultad de anticipar qué datos se "
      //  "convertirán en información útil en el futuro."},

      // {"¿Por qué es importante la flexibilidad en los sistemas de información?",
      //  "La flexibilidad es importante para poder adaptarse a las necesidades "
      //  "cambiantes de la organización y de sus directivos."},

      // {"¿Qué se menciona sobre la anécdota del ejército israelí en relación a "
      //  "los listados?",
      //  "Se menciona que la anécdota ilustra cómo se genera un exceso de datos "
      //  "que no siempre es útil para los usuarios."},

      // {"¿Qué implica la integración del proceso de toma de decisiones en un "
      //  "sistema de información?",
      //  "Implica que el sistema debe ser capaz de proporcionar información "
      //  "específica en función de las decisiones que se necesiten tomar."},

      // {"¿Qué aspecto de la gestión empresarial se considera revolucionario "
      //  "según el texto?",
      //  "Se considera revolucionario el cambio en la forma en que se entiende "
      //  "la toma de decisiones en las organizaciones."},

      // {"¿Cuál es la relación entre datos y decisiones según el texto?",
      //  "Los datos se convierten en información relevante solo cuando están "
      //  "alineados con una decisión que debe ser tomada."},

      // {"¿Qué crítica se hace a los informes extensos generados por sistemas de "
      //  "datos?",
      //  "Se critica que estos informes a menudo contienen demasiada información "
      //  "irrelevante, lo que dificulta la identificación de los datos útiles."},

      // {"¿Qué puede resultar de un enfoque excesivo en la recopilación de "
      //  "datos?",
      //  "Un enfoque excesivo en la recopilación de datos puede llevar a una "
      //  "sobrecarga de información que confunde más que ayuda."},

      // {"¿Por qué es importante definir claramente los objetivos al crear un "
      //  "sistema de información?",
      //  "Es importante para asegurar que el sistema se diseñe para satisfacer "
      //  "las necesidades específicas de la organización y sus usuarios."},

      // {"¿Cómo se relaciona la calidad de la información con la toma de "
      //  "decisiones?",
      //  "La calidad de la información es crucial porque una mala información "
      //  "puede llevar a decisiones erróneas o ineficaces."},

      // {"¿Qué implica un enfoque más simple en la gestión de datos?",
      //  "Un enfoque más simple implica concentrarse en la información realmente "
      //  "necesaria y útil, evitando la acumulación innecesaria de datos."},

      // {"¿Qué debe hacerse para asegurar que un sistema de información sea "
      //  "útil?",
      //  "Se debe realizar un análisis de las necesidades de información de los "
      //  "usuarios y ajustar el sistema en consecuencia."},

      // {"¿Qué se sugiere para optimizar la toma de decisiones dentro de las "
      //  "organizaciones?",
      //  "Se sugiere integrar los sistemas de información en el proceso de toma "
      //  "de decisiones para mejorar la eficacia y relevancia de la información "
      //  "proporcionada."},

      // {"¿Qué papel juega la cultura organizacional en la gestión de la "
      //  "información?",
      //  "La cultura organizacional influye en cómo se recopilan, procesan y "
      //  "utilizan los datos dentro de la empresa, afectando la eficacia de los "
      //  "sistemas de información."}

  };

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
