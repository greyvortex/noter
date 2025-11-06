#include <iostream>
#include <fstream>
#include <string>

void searchAndReplace(const std::string& path, const std::string& from, const std::string& to) {
    std::ifstream fin(path);
    std::string content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
    fin.close();

    size_t pos = 0;
    while ((pos = content.find(from, pos)) != std::string::npos) {
        content.replace(pos, from.length(), to);
        pos += to.length();
    }

    std::ofstream fout(path);
    fout << content;
    fout.close();
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: search <file> <from> <to>\n";
        return 1;
    }

    searchAndReplace(argv[1], argv[2], argv[3]);
    return 0;
}