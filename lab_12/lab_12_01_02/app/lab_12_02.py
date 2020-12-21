'''
    Данное приложение использует динамическую библиотеку написанную на
    языке программирования Си
                                                 Козлова Ирина ИУ7-32Б

'''
from tkinter import *
from tkinter import messagebox
from random import randint
from time import time
import numpy as np
from lab_12_01_dll import *
import matplotlib.pyplot as plt
roots = Tk()
roots['bg'] = '#bcdce0'
roots.geometry('800x500+400+200')
roots.title('LAB_12')


''' Функции преобразовывает введенные числа в массив чисел.
    Данная функция используется для пошагового вывода результата.
    Если вводится больше 10, то выдается ошбка.
    rang - введенные числа
    list_a_b - массив чисел, который подается на выход
'''
def k_get(rang):
    try:
        k = [int(x) for x in rang.get().strip().split()]
        
        if len(k) == 0 or len(k) > 1:
            raise ValueError
              
        return k[0]
    except ValueError:
        messagebox.showerror('1Ошибка ввода данных',
                             'Проверьте введенные данные.'
                             'Некоректные данные или'
                             'введено больше одного числа')
    except IndexError:
        messagebox.showerror('2Ошибка ввода данных',
                             'Проверьте введенные данные.'
                             'Некоректные данные или'
                             'введено больше одного числа')
    except TypeError:
        pass
def list_get(rang):
    try:
        list_a_b = [int(x) for x in rang.get().strip().split()]
        
        if len(list_a_b) == 0:
            raise ValueError
              
        return list(list_a_b)
    except ValueError:
        messagebox.showerror('11Ошибка ввода данных',
                             'Проверьте введенные данные.'
                             'Некоректные данные')
    except IndexError:
        messagebox.showerror('22Ошибка ввода данных',
                             'Проверьте введенные данные.'
                             'Некоректные данные')
    except TypeError:
        pass

''' Функции для записи в таблицу

    to_w - куда требуется записать
    out_w - что требуется записать
'''    
def wr_label(to_w, out_w):
    out_w.config(state = 'normal')
    out_w.delete(0,END)
    out_w.config(state = 'normal')
    out_w.insert(0,' '.join(map(str, to_w)))
    out_w.config(state = 'readonly')

def wr_label1(to_w, out_w):
    out_w['text'] = ''
    out_w['text'] += to_w

''' Функция для очистки полей ввода
    ent - поля ввода, которые надо очистить
'''
def clean_entry(*ent):
    for i in ent:
        i.config(state = 'normal')
        i.delete(0,END)

''' Функция для очистки полей вывода
    ent - поля вывода, которые надо очистить
'''
def clean_entry_out(ent):
    ent.config(state = 'normal')
    ent.delete(0,END)
    ent.config(state='readonly')

''' Функция для очистки Label
    lab - что нужно стереть из окна программы
'''
def clean_lab(*lab):
    for i in lab:
        i['text'] = ''

''' Функция вывода информации о программе.
    Данная функция выводит окно, в котором выводится информация
    для чего предназначена данная программа, кто автор, когда написана
'''
def proprog():
    window = Toplevel(roots)
    window.geometry('500x400+500+200')
    window.config(bg = '#b0e0e6')
    window.title('About program')
    window_l = Label(window, text ='Данная программа предназначена\n'
                     'для решения задачи 2 лабораторной работы 12 по СИ\n\n'
                     'Задача №1: Реализовать функцию циклического \n'
                     'сдвига массива на k позиций влево.\n'
                     'Задача №2: Реализовать функцию, которая из одного \n'
                     'массива помещает в другой элементы первого, \n'
                     'которые являются полными квадратами.\n\n'
                     'Автор:    Козлова Ирина ИУ7-32Б\n'
                     '                   декабрь 2020',
                     font = 'consolas 10',
                     bg = '#b0e0e6', fg = 'black')

    window_l.pack()
    exit_but =  Button(window,
                       text='Выход',
                       width = 15,
                       height = 1,
                       bg = 'white',
                       fg = 'black',
                       command = lambda: window.destroy())
    exit_but.place(anchor = 'center',x=150, y=350)

''' Для задачи номер 2: Вывод полных квадратов

    rang - данные из поля ввода
    text - куда записывать информацию
'''
def task_02(rang, text):
    choice = sel.get()
    if (choice == 1):
        sq_arr_n = square_arr1(list_get(rang))
        sq_arr = sq_arr_n[0]
        n = sq_arr_n[1]
        if (n == 0):
            string = 'В массиве нет полных квадратов'
        else:
            sq_arr = sq_arr[:n:]
            string = 'Оценочная максимальная длина: ' + \
                     str(len(list_get(rang)))
            string += '\nМассив полных квадратов: \n' + \
                      ' '.join(map(str, sq_arr))
        wr_label1(string, text)
    elif (choice == 2):
        sq_arr_n = square_arr2(list_get(rang))
        sq_arr = sq_arr_n[0]
        n = sq_arr_n[1]
        if (n == 0):
            string = 'В массиве нет полных квадратов'
        else:
            string = 'Длина массива: ' + str(len(sq_arr))
            string += '\nМассив полных квадратов: \n' + \
                      ' '.join(map(str, sq_arr))
        wr_label1(string, text)
    elif (choice == 0):
        messagebox.showerror('Ошибка ввода данных',
                             'Выберите способ получения массива')
    
''' Создание меню '''
mainmenu = Menu(roots)
roots.config(menu=mainmenu)

cleanmenu = Menu(mainmenu, tearoff=0)
cleanmenu.add_command(label = 'Очистить массив (задача 1)',
                      command = lambda: clean_entry(n1_entry))
cleanmenu.add_command(label = 'Очистить сдвиг (задача 1)',
                      command = lambda: clean_entry_out(t1_out))
cleanmenu.add_command(label = 'Очистить значение k',
                      command = lambda: clean_entry(n12_entry))
cleanmenu.add_command(label = 'Очистить массив (задача 2)',
                      command = lambda: clean_entry(n2_entry))
cleanmenu.add_command(label = 'Очистить вывод задачи 2',
                      command = lambda: clean_lab(sq_label))
cleanmenu.add_command(label = 'Очистить всё',
                      command = lambda: (clean_entry(n1_entry,
                                                     n12_entry,
                                                     n2_entry),
                                         clean_entry_out(t1_out),
                                         clean_lab(sq_label)))
filemenu1 = Menu(mainmenu, tearoff=0)
filemenu1.add_command(label = 'TASK №1',
                      command = lambda: wr_label(shift_arr(list_get(n1_entry),
                                                           k_get(n12_entry)),
                                                 t1_out))
filemenu1.add_command(label = 'TASK №2',
                      command = lambda: task_02(n2_entry, sq_label))


aboutmenu = Menu(mainmenu, tearoff=0)
aboutmenu.add_command(label ='About the program',
                      command = lambda: proprog())

mainmenu.add_cascade(label = 'Clean', menu = cleanmenu)
mainmenu.add_cascade(label = 'Operations', menu = filemenu1)
mainmenu.add_cascade(label = 'Help', menu = aboutmenu)

''' Заполнение окна программы Label, Entry и кнопками '''
wel_label = Label(roots,
                  text = 'Программа для решения задачи 2 из '
                  '12 лабораторной работы по СИ',
                  font = 'consolas 14',
                  bg = '#e0fdff',
                  fg = 'black')
wel_label.place(x = 90, y = 0)

''' Для решения задачи 1 '''
t1_label = Label(roots,
                 text = 'Задача №1: Сдвинуть массив на k позиций влево',
                 font = 'consolas 10',
                 bg = '#e0fdff',
                 fg = 'black')
t1_label.place(x = 5, y = 50)

t11_label = Label(roots,
                  text = 'Массив',
                  font = 'consolas 10',
                  bg = '#e0fdff',
                  fg = 'black')
t11_label.place(x = 1, y = 80)

n1_entry = Entry(roots, width = 40)
n1_entry.place(x = 70, y = 80)
n1_entry.focus_set()

t12_label = Label(roots,
                  text = 'Значение k',
                  font = 'consolas 10',
                  bg = '#e0fdff',
                  fg = 'black')
t12_label.place(x = 1, y = 110)

n12_entry = Entry(roots, width = 36)
n12_entry.place(x = 94, y = 110)

t11_label = Label(roots,
                  text = 'Массив со сдвигом',
                  font = 'consolas 10',
                  bg = '#e0fdff',
                  fg = 'black')
t11_label.place(x = 100, y = 200)

t1_out = Entry(roots, width = 50)
t1_out.place(x = 12, y = 230)
t1_out.config(state = 'readonly')

shk_button = Button(roots,
                    text = 'Выполнить сдвиг',
                    width = 20,
                    height = 2,
                    font = 'consolas 10',
                    bg = 'white', fg = 'black',
                    command = lambda:wr_label(shift_arr(list_get(n1_entry),
                                                        k_get(n12_entry)),
                                              t1_out))
shk_button.place(x = 90, y = 140)


''' Для решения 2 задачи '''
t2_label = Label(roots,
                 text = 'Задача №2: Найти полные квадраты в массиве',
                 font = 'consolas 10',
                 bg = '#e0fdff',
                 fg = 'black')
t2_label.place(x = 460, y = 50)

t21_label = Label(roots,
                  text = 'Массив',
                  font = 'consolas 10',
                  bg = '#e0fdff',
                  fg = 'black')
t21_label.place(x = 460, y = 80)

n2_entry = Entry(roots, width = 40)
n2_entry.place(x = 530, y = 80)
n2_entry.focus_set()

sel = IntVar()
rad1 = Radiobutton(roots,
                   text='Оценка максимального размера массива',
                   font = 'consolas 10',
                   bg = '#e6e6fa', value=1, variable = sel )
rad1.place(x = 460, y = 110)

rad2 = Radiobutton(roots,
                   text='Узнать размер массива (2 вызова функции)',
                   font = 'consolas 10',
                   bg = '#e6e6fa', value=2, variable = sel)
rad2.place(x = 460, y = 140)

sq_button = Button(roots,
                   text = 'Полные квадраты',
                   width = 20,
                   height = 2,
                   font = 'consolas 10',
                   bg = 'white',
                   fg = 'black',
                   command = lambda:task_02(n2_entry, sq_label))
sq_button.place(x = 540, y = 180)

sq_label = Label(roots,
                 text = '',
                 width = 44,
                 height = 8,
                 bg = 'white',
                 fg = 'black',
                 font = 'consolas 10')
sq_label.place(x = 460, y = 230)

exit_but =  Button(roots,
                   text='Exit',
                   width = 20,
                   height = 2,
                   font='consolas 10',
                   bg = 'white',
                   fg = 'black',
                   command = lambda: roots.destroy())
exit_but.place(x=200, y=400)

clean_but =  Button(roots,
                    text='Clean all',
                    width = 20,
                    height = 2,
                    font='consolas 10',
                    bg = 'white',fg = 'black',
                    command = lambda: (clean_entry(n1_entry,
                                                   n12_entry,
                                                   n2_entry),
                                       clean_entry_out(t1_out),
                                       clean_lab(sq_label)))
clean_but.place(x=400, y=400)


roots.mainloop()
