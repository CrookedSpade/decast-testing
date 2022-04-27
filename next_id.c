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

int main()
{
    // длина строки "??"*10 + "-"*9 + "\0" = 30
    char input[30], output[30];
    char test[16][30] = {   "B1",
                            "B1-B1",
                            "C1",
                            "D9",
                            "Z9",
                            "Z9-D9",
                            "B1-G3-B1-B1-Z9",
                            "Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9",
                            "Z8-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9-Z9",
                            "something",
                            "B",
                            "B1-A1-B1",
                            "B1+B1",
                            "B1-B1-",
                            "B1-BB",
                            "B1B1"
                        };




    for (int i = 0; i < 16; i++) {
        strcpy(input, test[i]);
        if (next_id(input, output)) {
            printf("%s\nincorrect\n\n", input);
        } else {
            printf("%s\n%s\n\n", input, output);
        }
    }

    
    while(1) {
        printf("custom test (or type \"exit\"):\n");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) return 0;
        else {
            if (next_id(input, output)) {
                printf("incorrect\n\n");
            } else {
                printf("%s\n\n", output);
            }
        }
    }
}
