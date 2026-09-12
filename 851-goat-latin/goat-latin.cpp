class Solution {
public:
    string toGoatLatin(string sentence) {

        stringstream ss(sentence);
        string word;
        string result = "";
        int count = 1;

        while (ss >> word) {

            char first = word[0];

            if (first == 'a' || first == 'e' || first == 'i' ||
                first == 'o' || first == 'u' ||
                first == 'A' || first == 'E' || first == 'I' ||
                first == 'O' || first == 'U') {

                word = word + "ma";

            } else {

                word = word.substr(1) + first + "ma";
            }

            for (int i = 0; i < count; i++) {
                word = word + "a";
            }

            if (result != "") {
                result = result + " ";
            }

            result = result + word;

            count++;
        }

        return result;
    }
};