#include <iostream>
#include <string>

// Function to eliminate metacharacters
std::string eliminateMetacharacters(std::string text) {
    // Metacharacters to be eliminated
    std::string metacharacters = ".^$*+?{}[]\\|()";

    // Replace each metacharacter with an escaped version
    for (char c : metacharacters) {
        size_t pos;
        while ((pos = text.find(c)) != std::string::npos) {
            text.replace(pos, 1, "\\");
        }
    }

    return text;
}

// Function to escape metacharacters using regex
std::string escapeMetacharacters(std::string text) {
    // Characters with special meanings in regex
    std::string metacharacters = ".^$*+?{}[]\\|()";

    // Escape each metacharacter
    std::string escaped_text;
    for (char c : text) {
        if (metacharacters.find(c) != std::string::npos) {
            escaped_text += "\\";
        }
        escaped_text += c;
    }

    return escaped_text;
}

int main() {
    std::string textWithMetacharacters = "Hello. How are you? I'm fine, thank you.";

    // Eliminate metacharacters
    std::string eliminatedText = eliminateMetacharacters(textWithMetacharacters);
    std::cout << "Eliminated Metacharacters: " << eliminatedText << std::endl;

    // Escape metacharacters
    std::string escapedText = escapeMetacharacters(textWithMetacharacters);
    std::cout << "Escaped Metacharacters: " << escapedText << std::endl;

    return 0;
}
