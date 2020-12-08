## Позитивные тесты 
 (сортировка везде устойчивая)

- 01 -  простой без фильтра
	(./app.exe pos_01_in.txt pos_01_out.txt)
- 02 -  простой с фильтром
	(./app.exe pos_02_in.txt pos_02_out.txt f )

- 03 -  с одним элементом без фильтра
	(./app.exe pos_03_in.txt pos_03_out.txt)
- 04 -  одинаковые элементы без фильтра
	(./app.exe pos_04_in.txt pos_04_out.txt)

- 05 -  только отрицательные без фильтра
	(./app.exe pos_05_in.txt pos_05_out.txt)
- 06 -  только отрицательные с фильтром
	(./app.exe pos_06_in.txt pos_06_out.txt f)

- 07 -  только положительные без фильтра
	(./app.exe pos_07_in.txt pos_07_out.txt)
- 08 -  только положительные с фильтром
	(./app.exe pos_08_in.txt pos_08_out.txt f)




## Негативные тесты
- 01 -  несуществует файл
	(./app.exe neg_01_in.txt neg_01_out.txt)
- 02 -  пустой файл
	(./app.exe neg_02_in.txt neg_02_out.txt f)

- 03 -  с одним элементом с фильтром
	(./app.exe neg_03_in.txt neg_03_out.txt f)
- 04 -  одинаковые значения => нет значений подходящих под фильтр
	(./app.exe neg_04_in.txt neg_04_out.txt f)

- 05 -  в файле есть буква (в начале)
	(./app.exe neg_05_in.txt neg_05_out.txt f)
- 06 -  в файле есть буква (в середине)
	(./app.exe neg_06_in.txt neg_06_out.txt f)
- 07 -  в файле есть буква (в конце)
	(./app.exe neg_07_in.txt neg_07_out.txt f)

- 08 -  в файлее есть дробное число (в начале)
	(./app.exe neg_08_in.txt neg_08_out.txt f)
- 09 -  в файле есть дробное число (в середине)
	(./app.exe neg_09_in.txt neg_09_out.txt f)
- 10 -  в файле есть дробное число (в конце)
	(./app.exe neg_10_in.txt neg_10_out.txt f)

- 11 -  некорректная командная строка
	(./app.exe neg_11_in.txt neg_11_out.txt fsd sdsd)
- 12 -  вместо "f" указана другая строка
	(./app.exe neg_12_in.txt neg_12_out.txt s123)
