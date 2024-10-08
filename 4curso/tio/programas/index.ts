import * as fs from 'fs';

// Define la interfaz para las flashcards
interface Flashcard {
    question: string;
    answer: string;
}

// Función para cargar flashcards desde un archivo JSON
const loadFlashcards = (filePath: string): Flashcard[] => {
    const data = fs.readFileSync(filePath, 'utf-8');
    return JSON.parse(data);
};

// Función para mostrar una flashcard
const showFlashcard = (flashcard: Flashcard): void => {
    console.log(`Pregunta: ${flashcard.question}`);
    console.log('Presiona Enter para ver la respuesta...');
    process.stdin.once('data', () => {
        console.log(`Respuesta: ${flashcard.answer}`);
        console.log('---');
        process.stdin.once('data', () => {
            // Continúa al siguiente
            process.exit(0);
        });
    });
};

// Función principal que recorre las flashcards
const startFlashcards = (flashcards: Flashcard[]): void => {
    let index = 0;

    const showNextFlashcard = () => {
        if (index < flashcards.length) {
            showFlashcard(flashcards[index]);
            index++;
        } else {
            console.log('¡Has completado todas las flashcards!');
            process.exit(0);
        }
    };

    // Detectar la tecla Enter para avanzar a la siguiente flashcard
    process.stdin.setRawMode(true);
    process.stdin.resume();
    process.stdin.on('data', showNextFlashcard);

    showNextFlashcard(); // Muestra la primera flashcard
};

// Cargar las flashcards desde el archivo JSON
const flashcards = loadFlashcards('flashcards.json');

// Iniciar el programa de flashcards
startFlashcards(flashcards);


// tsc index.ts && node index.js
