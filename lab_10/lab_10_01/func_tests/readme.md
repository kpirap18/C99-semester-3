## Позитивные тесты

- 1 - тест на удаления элемента из списка (кол-во элементов > 1)
- 2 - тест на удаления элемента из списка (кол-во элементов = 1)
- 3 - тест на сортировку (кол-во элементов > 1)
- 4 - тест на сортировку (кол-во элементов = 1)
- 5 - тест на поворот списка (кол-во элементов > 1)
- 6 - тест на поворот списка (кол-во элементов = 1)
- 7 - тест на добавления элемента ((кол-во элементов > 1)) (вначало)
- 10 - тест на добавления элемента ((кол-во элементов > 1)) (в середину)
- 8 - тест на добавления элемента ((кол-во элементов = 1))
- 9 - тест на добавления элемента (элемент, перед которым надо вставить - не найден в списке => элемент вставляется в конец)


## Негативны тесты

комадды на пустой файл
- 1 - тест на удаление из пустого списка
- 2 - тест на сортировку пустого списка
- 3 - тест на поворот пустого списка

## Некорректные файлы
- 4 - пустая строка в поле Имя
- 5 - пустая строка в поле название
- 6 - пустые обе строки

команды на несуществующий файл 
- 7 - неважно действие

### Неверная командная строка
- 8 - кол-во агрументов меньше нужного (./app.txt f1.txt)
- 9 - количество аргументов больше нужного (./app.txt f1.txt f2.txt q w e r t)
- 10 - количество аргументов 5 - операция вставки(допустимо 4 или 6) (./app.txt f1.txt f2.txt i 2)
- 11 - элемент, который надо вставить - не цифра (./app.exe f1.txt f2.txt i 6 g)
- 12 - элемент, перед которым надо вставить - не цифра (./aap.exe f1.txt f2.txt h 6)
