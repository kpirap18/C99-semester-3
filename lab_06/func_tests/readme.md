## Позитивные тесты 
 (сортировка везде устойчивая)

- 01 - тест на сортировку поля year 
	(.main.exe pos_01_in.txt year)
- 02 - тест на сортировку поля title 
	(.main.exe pos_02_in.txt title)
- 03 - тест на сортировку поля name 
	(.main.exe pos_03_in.txt name)
- 04 - тест на сортировку файла из одной записи
	(.main.exe pos_04_in.txt name)

- 05 - тест с ключом 2017 и полем year 
	(.main.exe pos_05_in.txt year 2017)
- 06 - тест с ключом Avatar и полем title 
	(.main.exe pos_06_in.txt title Avatar)
- 07 - тест с ключом James Cameron и полем name 
	(.main.exe pos_07_in.txt name James Cameron)
- 08 - тест с ключом 1984 и полем year 
	(.main.exe pos_08_in.txt year 1984)
- 09 - тест с ключом The Terminal и полем title 
	(.main.exe pos_09_in.txt title The Terminal)
- 10 - тест с ключом Olivier Nakache и полем name 
	(.main.exe pos_10_in.txt name Olivier Nakache)
- 11 - тест на ненахождение структуры с ключом year  
	(.main.exe pos_11_in.txt year 2020)
- 12 - тест на ненахождение структуры с ключом title 
	(.main.exe pos_12_in.txt title AdM)
- 13 - тест на ненахождение структуры с ключом name
	(.main.exe pos_13_in.txt name Fedor)
- 14 - тест с полем "title" длинной 25
- 15 - тест с полем "name" длинной 25

## Негативные тесты
- 01 - тест на длинное слово в поле "title" (>25) 
	(.main.exe neg_01_in.txt year)
- 02 - тест на длинное слово в поле "name" (>25) 
	(.main.exe neg_02_in.txt year)
- 03 - тест с пустым файлом 
	(.main.exe neg_03_in.txt year)
- 04 - тест на несуществование файла 
	(.main.exe neg_04_in.txt year)
- 05 - тест на неверно указанный год (год <= 0)
	(.main.exe neg_05_in.txt year)
- 06 - тест с дробью с значение год 
	(.main.exe neg_06_in.txt year)
- 07 - тест с не числом с значение год 
	(.main.exe neg_07_in.txt year)

- 08 - тест на неправильную командную строку (год записан дробью)
	(.main.exe neg_08_in.txt year 2101.5465)
- 09 - тест на неправильную командную строку (год записан не числом)
	(.main.exe neg_09_in.txt year asa)
- 10 - тест на неправильную командную строку (год <= 0)
	(.main.exe neg_10_in.txt year 0)
- 11 -  тест на неправильную командную строку (кол-во >)
	(.main.exe neg_11_in.txt year name title 1234)
- 12 -  тест на неправильную командную строку (кол-во <)
	(.main.exe)
- 13 -  тест на неправильную командную строку (поле "key" длинное)
	(.main.exe neg_13_in.txt name qwertyuioplkjhgfdsazxcvbnm)
- 14 - тест на неверную командную строку (неверное значение FEILD)
	(.main.exe neg_14_in.txt years)