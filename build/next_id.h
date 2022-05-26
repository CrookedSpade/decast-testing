#ifndef NEXT_ID_H
#define NEXT_ID_H

/****************************

Модуль next_id генерирует новый идентификатор из поданного на вход
в соответствии с тестовым заданием, изложеным в README.MD

Использование:

int next_id(const char *in, char *out, const int out_size);

in - указатель на исходную строку с идентификатром
out - указатель на буфер назначения
out_size - размер буфера назначения, должен быть больше длины строки in минимум на SEG_LENGTH+1.

Возращаемое значение:

0 - операция завершена успешно
1 - некорректные входные данные

****************************/

#define SEG_LENGTH 3										        	//длина одного сегмента, кроме первого (напр. "-B1")
#define FIRST_SEG_LENGTH 2									        	//длина первого сегмента (напр. "B1");
#define SEGMENTS 10											        	//количество сегментов

#define MAX_ID_LENGTH FIRST_SEG_LENGTH + SEG_LENGTH * (SEGMENTS - 1)	//максимальная длина идентификатора
#define MIN_ID_LENGTH FIRST_SEG_LENGTH							        //минимальная длина идентификатора

//Раскомментировать для получения сообщений в stderr
//#define DEBUG

int next_id(const char *in, char *out, const int out_size);


#endif /* NEXT_ID_H */