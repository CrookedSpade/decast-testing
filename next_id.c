#include <stdio.h>
#include <string.h>

const char voc[] = "BCDFGHJKLMNPQRSTVWXZ"; //словарь


//проверка корректности ввода
int check_input(char *in) { 
    int len = strlen(in);
    if (len % 3 - 2) return 1;      //кол-во символов не соответствует маске
    
    if (len < 2 || len > 29) return 1;
    
    for (int i = 0; i < len; i += 3){
        if (strchr(voc, in[i]) == NULL) {
            return 1;               //на месте согласной буквы другой символ
        }
    }
    for (int i = 1; i < len; i += 3){
        if (in[i] < '1' || in[i] > '9') {
            return 1;               //на месте цифры другой символ
        }
    }
    for (int i = 2; i < len; i += 3){
        if (in[i] != '-') {
            return 1;               //на месте дефиса другой символ
        }
    }
    return 0;
    
}

//поиск следующего идентификатора
int next_id(char *in, char *out) {
    if (check_input(in)) return 1;  //возвращает 1 в случае неверного ввода. иначе 0

    int i = strlen(in) - 1;
    char *pos;
    strcpy(out, in);
    
    do {                            //обработка строки с конца
        
        if (out[i] == '9') {
            out[i] = '1';
            i--;
        } else {
            out[i]++;
            break;
        }
        
        pos = strchr(voc, out[i]);
        if (pos == voc + strlen(voc) - 1) {
            out[i] = voc[0];
            i -= 2;
            
        } else {
            out[i] = *(pos + 1);
            break;
        }
        
    } while (i >= 0);
    
    if (i < 0)
        if (strlen(out) > 26)
            strcpy(out, "B1");     //переполнение индекса
        else strcat(out, "-B1");   //добавление разряда
    
    return 0;
    
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Not enough arguments");
        return 1;
    }
    if (argc > 2) {
        printf("Too many arguments");
        return 1;
    }
    if (strlen(argv[1]) > 29) {
        printf ("ID is too long");
        return 1;
    }
    if (strlen(argv[1]) < 2) {
        printf ("ID is too short");
        return 1;
    }
    
    // длина строки "??"*10 + "-"*9 + "\0" = 30
    char input[30], output[30];
    
    if (next_id(argv[1], output)) {
        printf("incorrect");
        return 1;
    } else {
        printf("%s", output);
        return 0;
    }
}
