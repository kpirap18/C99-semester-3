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
import matplotlib.pyplot as plt
roots = Tk()
roots['bg'] = '#bcdce0'
roots.geometry('600x400+500+200')
roots.title('LAB_12')

''' Функция вывода информации о программе.
    Данная функция выводит окно, в котором выводится информация
    для чего предназначена данная программа, кто автор, когда написана
'''
def proprog():
    window = Toplevel(roots)
    window.geometry('300x200+600+300')
    window.config(bg = '#b0e0e6')
    window.title('About program')
    window_l = Label(window, text ='Данная программа предназначена\n'
                     'для сравнения Пирамидальной сортировки\n'
                     'на различных массивах\n\n'
                     'Автор: Козлова Ирина ИУ7-32Б\n'
                     '                   декабрь 2020',
                     font = 'consolas 10',
                     bg = '#b0e0e6', fg = 'black')

    window_l.pack()
    exit_but =  Button(window, text='Выход',width = 15,height = 1,
                   bg = 'white',fg = 'black',
                   command = lambda: window.destroy())
    exit_but.place(anchor = 'center',x=150, y=150)


''' Создание меню '''
mainmenu = Menu(roots)
roots.config(menu=mainmenu)

cleanmenu = Menu(mainmenu, tearoff=0)
cleanmenu.add_command(label = 'Clear field N1',
                      command = lambda: clean_entry(n1_entry))
cleanmenu.add_command(label = 'Clear field result N1',
                      command = lambda: clean_entry_out(n1_out))
cleanmenu.add_command(label = 'Clear field N2',
                      command = lambda: clean_entry(n2_entry))
cleanmenu.add_command(label = 'Clear field result N2',
                      command = lambda: clean_entry_out(n2_out))
cleanmenu.add_command(label = 'Clear field N3',
                      command = lambda: clean_entry(n3_entry))
cleanmenu.add_command(label = 'Clear field result N3',
                      command = lambda: clean_entry_out(n3_out))
cleanmenu.add_command(label = 'Clear all fields',
                      command = lambda: (clean_entry(n1_entry, n2_entry, n3_entry),
                                         clean_entry_out(n1_out),
                                         clean_entry_out(n2_out),
                                         clean_entry_out(n3_out)))
filemenu1 = Menu(mainmenu, tearoff=0)
filemenu1.add_command(label = 'Step by step',
                      command = lambda: sort_step())


aboutmenu = Menu(mainmenu, tearoff=0)
aboutmenu.add_command(label ='About the program',
                      command = lambda: proprog())

mainmenu.add_cascade(label = 'Clean', menu = cleanmenu)
mainmenu.add_cascade(label = 'Operations', menu = filemenu1)
mainmenu.add_cascade(label = 'Help', menu = aboutmenu)

roots.mainloop()
