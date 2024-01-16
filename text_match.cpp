#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void createStartFile(const string& fileName) {
    ofstream startFile(fileName);

    if (!startFile) {
        cerr << "Не удаётся создать стартовый файл: " << fileName << "\n";
        exit(EXIT_FAILURE);
    }

    startFile << "Был яркий холодный апрельский день, часы били тринадцать."
        " Уинстон Смит, прижав подбородок к груди и ежась от омерзительного ветра,"
        " быстро скользнул в стеклянные двери Дома Победы, но все же вихрь песка и "
        "пыли успел ворваться вместе с ним.\n"

        "В подъезде пахло вареной капустой и старыми половиками."
        " К стене против входа был пришпилен цветной плакат,"
        " пожалуй слишком большой для этого места. На нем было изображено лишь огромное,"
        " шириной больше метра, лицо человека лет сорока пяти с грубоватыми,"
        " но привлекательными чертами и густыми черными усами.\n";

    startFile.close();
}

int main() {
    setlocale(0, "");

    string startFileName = "start.txt";
    createStartFile(startFileName);

    ifstream inputFile(startFileName);

    if (!inputFile) {
        cerr << "Не удаётся открыть входной файл: " << startFileName << "\n";
        exit(EXIT_FAILURE);
    }

    string outputFileName = "output.txt";
    ofstream outputFile(outputFileName);

    if (!outputFile) {
        cerr << "Не удаётся открыть выходной файл: " << outputFileName << "\n";
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(inputFile, line)) {
        outputFile << line << "\n";
    }

    inputFile.close();
    outputFile.close();

    cout << "Строки были переписаны в " << outputFileName << "\n";

    ifstream outputFileReader(outputFileName);

    if (!outputFileReader) {
        cerr << "Не удаётся открыть файл для чтения: " << outputFileName << "\n";
        exit(EXIT_FAILURE);
    }

    string outputLine;
    cout << "Строки из файла " << outputFileName << ":\n";
    while (getline(outputFileReader, outputLine)) {
        cout << outputLine << "\n";
    }

    outputFileReader.close();

    return 0;
}
