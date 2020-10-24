## Позитивные тесты 
 (сортировка везде устойчивая)

- 01 - тест на сортировку поля year 
	(./app.exe pos_01_in.txt year)
- 02 - тест на сортировку поля title 
	(./app.exe pos_02_in.txt title)
- 03 - тест на сортировку поля name 
	(./app.exe pos_03_in.txt name)
- 04 - тест на сортировку файла из одной записи
	(./app.exe pos_04_in.txt name)
- 14 - сортировка отсортированного списка
	(./app.exe pos_14_in.txt pos_14_out.txt year)
- 15 - сортировка в обратном порядке
	(./app.exe pos_15_in.txt pos_15_out.txt)

- 05 - тест с ключом 2017 и полем year 
	(./app.exe pos_05_in.txt year 2017)
- 06 - тест с ключом Avatar и полем title 
	(./app.exe pos_06_in.txt title Avatar)
- 07 - тест с ключом James Cameron и полем name 
	(./app.exe pos_07_in.txt name James Cameron)
- 08 - тест с ключом 1984 и полем year 
	(./app.exe pos_08_in.txt year 1984)
- 09 - тест с ключом The Terminal и полем title 
	(./app.exe pos_09_in.txt title The Terminal)
- 10 - тест с ключом Olivier Nakache и полем name 
	(./app.exe pos_10_in.txt name Olivier Nakache)
- 11 - тест на ненахождение структуры с ключом year  
	(./app.exe pos_11_in.txt year 2020)
- 12 - тест на ненахождение структуры с ключом title 
	(./app.exe pos_12_in.txt title AdM)
- 13 - тест на ненахождение структуры с ключом name
        (./app.exe pos_13_in.txt name Fedor)

## Негативные тесты
- 01 - тест с пустым файлом
	(./app.exe neg_01_in.txt year)
- 02 - тест на несуществование файла
	(./app.exe neg_02_in.txt year)
- 03 - тест на неверно указанный год (год <= 0)
	(./app.exe neg_03_in.txt year)
- 04 - тест с 0 с значение год
	(./app.exe neg_04_in.txt year)
- 05 - тест с не числом с значение год
	(./app.exe neg_05_in.txt year)
- 06 - тест с пустым полем name
	(./app.exe neg_06_in.txt year)
- 07 - тест с пустым полем title
	(./app.exe neg_07_in.txt year)
- 08 - тест с пустым полем year
	(./app.exe neg_08_in.txt year)

- 09 - тест на неправильную командную строку (год 0)
	(./app.exe neg_09_in.txt year 0)
- 10 - тест на неправильную командную строку (год записан не числом)
	(./app.exe neg_10_in.txt year asa)
- 11 - тест на неправильную командную строку (год <= 0)
	(./app.exe neg_11_in.txt year -9)
- 12 -  тест на неправильную командную строку (кол-во >)
	(./app.exe neg_12_in.txt year name title 1234)
- 13 -  тест на неправильную командную строку (кол-во <)
     (./app.exe)
- 14 - тест на неверную командную строку (неверное значение FEILD)
	(./app.exe neg_14_in.txt years)
