# read-bin-file
Reading binary file with list of persons (C/C++)
Лабораторная работа №5
“Файлы, структуры и символьные величины”

Необходимо написать консольное приложение, которое будет обрабатывать бинарный файл, содержащий информацию о пользователях некоторой услуги. 

Структура файла следующая:
Байт 0 содержит число пользователей, которые описаны в файле.
Байты 1 – N1: блок данных о первом пользователе;
Байты N1+1 – N2: блок данных о втором пользователе;
Байты N2+1 – N3: блок данных о третьем пользователе;
и так далее....

Блок данных о каждом пользователе имеет cследующую структуру:
Номер байта блока, начиная с 0
Содержит
0- Индекс пользователя в файле
1- Длина остающихся данных в блоке
2- Идентификатор (ID) 1 
3- Длина данных ID1
4- Данные ID1
N2- ID2
N2+1- Длина данных ID2
N2+2- Данные ID2
N3- ID3
N3+1- Длина данных ID3
N3+2- Данные ID3
и так далее, пока не опишутся все данные о пользователе с данным индексом

Известно, что файл содержит информацию не более чем о 10 пользователях.
Значения идентификаторов ID1, ID2, ID3, ...., ID6 представлены в таблице.

Если в блоке данных пользователя пропущено описание одного или нескольких идентификаторов, то считается, что про эти данные нет информации. 

Консольное управление
Программа должна поддерживать следующие консольные команды:
Введенные символ
Реакция программы
‘0’
Распечатывает все данные из файла
от ‘1’ до ‘9’ 
Распечатывает данные пользователя с соответствующим индексом (при вводе 1 – первого, при вводе 2 – второго и т.д.)
‘e’ или ‘E’
выход из программы
Ввод других символов должен игнорироваться

Пример данных и их расшифровка (красным) из файла UserData.bin, который содержит сведения о двух пользователях:

0x02 – два пользователя
0x01 0x26 – блок данных для пользователя 1, содержащий 38 байт
0x01 0x07 0x49 0x76 0x61 0x6e 0x6f 0x76 0x00  (Фамилия – Ivanov)
0x02 0x05 0x49 0x76 0x61 0x6e 0x00 (Имя – Ivan)
0x03 0x0a 0x49 0x76 0x61 0x6e 0x6f 0x76 0x69 0x63 0x68 0x00 (Отчество – Ivanovich)
0x04 0x01 0x19 (Возраст – 25)
0x05 0x01 0x6d  (Пол – мужской)
0x06 0x02 0x0c 0x00 (Пользовался услугой – 12 раз)

0x02 0x23 – блок данных для пользователя 2, содержащий 35 байт
0x01 0x07 0x50 0x65 0x74 0x72 0x6f 0x76 0x00 (Фамилия – Petrov) 
0x02 0x05 0x50 0x65 0x74 0x72 0x00 (Имя – Petr)
0x03 0x0a 0x50 0x65 0x74 0x72 0x6f 0x76 0x69 0x63 0x68 0x00 (Отчество – Petrovich)
0x04 0x01 0x15 (Возраст – 21) 
0x06 0x02 0x0f 0x00 (Пользовался услугой – 15 раз)
Так как в блоке данных второго пользователя нет ID5 – то данные о поле пользователя отсутствуют.

