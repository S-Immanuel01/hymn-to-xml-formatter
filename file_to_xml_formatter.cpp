// HOW TO USE THIS CODE

// enter the document in this format:
// 1. ensure the title is bold
// 2. add space after every stanza
// 3. if there is chorus add a 'chorus' header

// EXAMPLE FORMAT:
// 123 QUE VERGONHA E TRISTEZA
//                          <- SPACE HERE
// 1.Que vergonha e tristeza
// Que um tempo poderia ser
// Quando eu deixarei o Senhor
// Rogar em vão e respondeu
// Tudo de ego, e nada de Ti.
//                          <- SPACE HERE
// 2.Mas me achou; eu olhei Lhe
// Sangrando sobre o madeiro,
// Ele orou “Pai lhes perdoa”
// E meu coração sim disse
// Alguns de ego, e alguns de Ti
//                          <- SPACE HERE
// 3.Dia a dia Tua misericórdia
// Curando e libertando
// Doce e forte e paciente
// Me abaixou eu murmurando
// Pouco do ego, e mais de Ti.
//                          <- SPACE HERE
// 4.Alto que os céus mais altos
// Mais profundo que o amor,
// Teu amor no fim venceu;
// Dá me agora,
// Nada de ego, e tudo de Ti.
//                          <- SPACE HERE TOO (IMPORTANT!)

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StringOperations {
public:
   static bool isNumber(char16_t num)
    {
        switch (num)
        {
         case '0': 
            return true;
            break;
        case '1': 
            return true;
            break;
        case '2':
            return true;
            break;
        case '3': 
            return true;
            break;
        case '4':
            return true;
            break;
        case '5': 
            return true;
            break;
        case '6':
            return true;
            break;
        case '7': 
            return true;
            break;
        case '8':
            return true;
            break;
        case '9': 
            return true;
            break;
        default:
            return false;
            break;
        }
    }
   static bool isEmpty(string text) 
   {
        int8_t n = 0;
        for (char16_t character : text) {
            if (character == ' ') {
                cout << "empty character";
                n += 1;    
            }
            else {
                // cout << "not empty" << endl;
                break;
            }
        }
        if (n == 10) {
            return true;
        }
        if (text == " ") {
            return true;
        }
        return false;
    }

   bool compair(string text1, int8_t a, int8_t b,string text2 )
    {
        int8_t n=0;
        for (int i=0; i < b; i++) {
            if (text1[i] == text2[i]) {
                n += 1;
            }
            else if(text1[i] != text2[i]) {
                break;
            }
            if (n == b) {
                return true;
            }
            
        }
        return false;
    }

    static bool isCapital(string text) 
    {
        for (char16_t ch: text) {
            if (ch >= 'A' &&  ch <= 'Z') {
                if (ch == text[text.length()-1]) {
                    return true;
                }
            }else {
                break;
            }
        }
        return false;
    }

    string split(string text, char16_t ch)
    {
        string tempString = "";
        for (char16_t character: text) {
            if (character != ch) {
                tempString += character;
            }else {
                continue;
            }
        }
        return tempString;
    }
    string getId(string text) 
    {
        string id = "";
        for (int i=0; i < text.length(); i++) {
            if (isNumber(text[i]) && isNumber(text[0]) && isNumber(text[1])) {
                id += text[i];
                
            }else {
                break;
            }
        }
        return id;
    }
};

//get the file containing the hymns from system path
int main() 
{
    StringOperations * _string = new StringOperations();
    StringOperations newString;

    bool chorus = false;
    bool standza = true;
    fstream newFile;
    int16_t id = 1;

    newFile.open("text_file.txt", ios::in);
    if (newFile.is_open()) {
        string text;
        cout << "<Hymn>" << endl;
        while (getline(newFile, text))
        {
            if (_string->getId(text) != "") {
                cout << "<id>" << _string->getId(text) << "</id>" << endl;
                text.erase(0, _string->getId(text).length());
            }

            if (text == "chorus:" || text == "chorus") {
                text = "<chorus>";
                // cout << "<chorus>" << endl;
                chorus = true;
            }

            // check for title
            // _string->compair(text,0,5,"title")
            if (_string->isCapital(_string->split(text,' '))) {
                text = "<title>" + text + "</title>";
            }
            
            if (text.empty()) {        
                if (standza == false) {
                    cout << "</text>" << endl;
                    cout << "</stanza>" << endl;
                    standza = true;
                }
                else if(chorus == true) {
                    cout << "</chorus>" << endl;
                    chorus = false;
                }
                else if(standza == true) {
                    // text = "<stanza>";
                    standza = false;
                    // cout << "<text>" << endl;
                }
                
            }
            if (_string->isNumber(text[0])) {
                cout << "<stanza>" << endl;
                standza = false;
                cout << "<no>" << text[0] << "</no>"<< endl;
                cout << "<text>";
                text.erase(0,2);
            } 
            
            //loop through file and check for empty spaces
            if (text[0] == ' ') {
                text.erase(0,1);
            }
            cout << text << endl;

            
        }
        newFile.close();
        cout << "</Hymn>" << endl;
        
    }
}