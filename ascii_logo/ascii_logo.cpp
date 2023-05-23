#include <iostream>
int main() {
    // Define the ASCII art for each letter
    std::string letters[] = {
        "  #####  \n"
        " #     # \n"
        " #     # \n"
        " ####### \n"
        " #     # \n"
        " #     # \n"
        " #     # \n",

        " ######  \n"
        " #     # \n"
        " #     # \n"
        " ######  \n"
        " #     # \n"
        " #     # \n"
        " ######  \n",

        "  #####  \n"
        " #     # \n"
        " #       \n"
        " #       \n"
        " #       \n"
        " #     # \n"
        "  #####  \n",

        " ######  \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " ######  \n",

        " ####### \n"
        " #       \n"
        " #       \n"
        " ######  \n"
        " #       \n"
        " #       \n"
        " ####### \n",

        " ####### \n"
        " #       \n"
        " #       \n"
        " ######  \n"
        " #       \n"
        " #       \n"
        " #       \n",

        "  #####  \n"
        " #     # \n"
        " #       \n"
        " #   ### \n"
        " #     # \n"
        " #     # \n"
        "  #####  \n",

        " #     # \n"
        " #     # \n"
        " #     # \n"
        " ####### \n"
        " #     # \n"
        " #     # \n"
        " #     # \n",

        "  #####  \n"
        "    #    \n"
        "    #    \n"
        "    #    \n"
        "    #    \n"
        "    #    \n"
        "  #####  \n",

        "       # \n"
        "       # \n"
        "       # \n"
        "       # \n"
        " #     # \n"
        " #     # \n"
        "  #####  \n",

        " #     # \n"
        " #   #   \n"
        " #  #    \n"
        " ###     \n"
        " #  #    \n"
        " #   #   \n"
        " #     # \n",

        " #       \n"
        " #       \n"
        " #       \n"
        " #       \n"
        " #       \n"
        " #       \n"
        " ####### \n",

        " #     # \n"
        " ##   ## \n"
        " # # # # \n"
        " #  #  # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n",

        " #     # \n"
        " ##    # \n"
        " # #   # \n"
        " #  #  # \n"
        " #   # # \n"
        " #    ## \n"
        " #     # \n",

        "  #####  \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        "  #####  \n",

        " ######  \n"
        " #     # \n"
        " #     # \n"
        " ######  \n"
        " #       \n"
        " #       \n"
        " #       \n",

        "  #####  \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #  #  # \n"
        " #   # # \n"
        "  #### # \n",

        " ######  \n"
        " #     # \n"
        " #     # \n"
        " ######  \n"
        " #   #   \n"
        " #    #  \n"
        " #     # \n",

        "  #####  \n"
        " #     # \n"
        " #       \n"
        "  #####  \n"
        "       # \n"
        " #     # \n"
        "  #####  \n",

        "####### \n"
        "   #    \n"
        "   #    \n"
        "   #    \n"
        "   #    \n"
        "   #    \n"
        "   #    \n"

        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        "  #####  \n",

        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        "  #   #  \n"
        "   ###   \n",

        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #     # \n"
        " #  #  # \n"
        " # # # # \n"
        " #  #  # \n",

        " #     # \n"
        "  #   #  \n"
        "   # #   \n"
        "    #    \n"
        "   # #   \n"
        "  #   #  \n"
        " #     # \n",

        " ####### \n"
        "     #   \n"
        "    #    \n"
        "   #     \n"
        "  #      \n"
        " #       \n"
        " ####### \n"
    };

    std::string word = "HELLO WORLDS";

    // std::cout << "length: " << word.length() << std::endl;
    // Iterate over each character in the word
    for (int i = 0; i < word.length(); i++) {
        // Convert the character to uppercase
        char ch = std::toupper(word[i]);
        // std::cout << "char: as int : " << ch << std::endl;
        // Calculate the index in the letters array
        int index = ch - 'A';
        // int index = ch;

        // std::cout << "index : " <<  index << std::endl;

        // // Check if the character is within A-Z range
        if (index >= 0 && index < 26) {
            // Display the ASCII art for the character
            std::cout << letters[index] << std::endl;
        } else {
            // Display a space for non-alphabetic characters
            std::cout << "   \n\n";
        }
    }

    // int test = 5;

    // std::cout << letters[5] << std::endl;
    return 0;
}

