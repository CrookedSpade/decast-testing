#include "next_id.h"
#include <stdio.h>
#include <string.h>

const char voc[] = "BCDFGHJKLMNPQRSTVWXZ"; //словарь


//проверка корректности ввода
int check_input(const char *in, const char *out, const int size) {
	if (in == NULL || out == NULL) {
#ifdef DEBUG
		fprintf(stderr, "next_id: Buffer pointer is empty\n");
#endif
		return 1;
	}
    int len = strlen(in);
	if (size < len + 1) {
#ifdef DEBUG
		fprintf(stderr, "next_id: Output buffer size is too small\n");
#endif
		return 1;
	}
    if (len % SEG_LENGTH - FIRST_SEG_LENGTH) {			//кол-во символов не соответствует маске
#ifdef DEBUG
		fprintf(stderr, "next_id: Incorrect input\n");
#endif
		return 1;
	}
    
    if (len > MAX_ID_LENGTH) {
#ifdef DEBUG
		fprintf(stderr, "next_id: Too long input\n");
#endif
		return 1;
	}
    
    for (int i = 0; i < len; i += SEG_LENGTH) {			//на месте согласной буквы другой символ
        if (strchr(voc, in[i]) == NULL) {
#ifdef DEBUG
			fprintf(stderr, "next_id: Incorrect input\n");
#endif
			return 1;
		}
    }
    for (int i = 1; i < len; i += SEG_LENGTH){			//на месте цифры другой символ
        if (in[i] < '1' || in[i] > '9') {
#ifdef DEBUG
			fprintf(stderr, "next_id: Incorrect input\n");
#endif
			return 1;
		}
    }
    for (int i = 2; i < len; i += SEG_LENGTH) {			//на месте дефиса другой символ
        if (in[i] != '-') {
#ifdef DEBUG
			fprintf(stderr, "next_id: Incorrect input\n");
#endif
			return 1;
		}
    }
    return 0;
    
}

//поиск следующего идентификатора
int next_id(const char *in, char *out, const int out_size) {
	
    if (check_input(in, out, out_size)) return 1;

	strncpy(out, in, out_size - 1);
	out[out_size - 1] = '\0';
	
    int i = strlen(out) - 1;
    char *pos;
    
    do {										//обработка строки с конца
        
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
            i -= SEG_LENGTH - 1;				//переход к следующему сегменту (по убыванию)
        } else {
            out[i] = *(pos + 1);
            break;
        }
        
    } while (i >= 0);
	
    if (i < 0)
        if (strlen(out) + 1 > out_size - SEG_LENGTH)
			strcpy(out, "B1");					//превышение MAX_ID_LENGTH. !поведение в этом случае в задании не оговорено!
		else strcat(out, "-B1");				//добавление сегмента справа	
    
    return 0;
    
}

