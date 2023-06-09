def calculate():
    total_sal = 0
    x_place = 150
    bi_weekly = []
    for h in range(3):
        hour_tot = float(hour_input[h].get())
        wage_tot = float(wage_input[h].get())
        sum = ((hour_tot * wage_tot * 2) * 100) / 100
        total_sal += sum
        bi_weekly.append(sum)

    for l in range(3):
        Label(root, text= bi_weekly[l], bg='paleturquoise').place(x= x_place, y=150)
        x_place += 60

    Label(root, text=total_sal, bg='paleturquoise').place(x=210, y=180)
    return


def clear():
    x_place = 150
    for h in create_Hour_input():
        for w in create_Wage_input():
            h.delete(0,END)
            w.delete(0,END)

    for l in range(3):
        Label(root, width=23, fg='paleturquoise', bg='paleturquoise').place(x= x_place, y=150)
        x_place += 60

    Label(root, width=15, fg='paleturquoise', bg='paleturquoise').place(x=210, y=180)
    return

def create_Wage_input():
    wage_input = []
    x_place = 130
    for l in range(3):
        wage = Entry(root, width=10)
        wage.place(x=x_place,y=110)
        x_place += 60
        wage_input.append(wage)
    return wage_input

def create_Hour_input():
    hour_input = []
    x_place = 130
    for l in range(3):
        hour = Entry(root, width=10)
        hour.place(x=x_place,y=70)
        x_place += 60
        hour_input.append(hour)
    return hour_input

def create_Job_label():
    x_place = 140
    jobs = ["1st Job", "2nd Job", "3rd Job"]
    final = []
    for l in range(3):
        job_label = Label(root, text= jobs[l], bg='paleturquoise')
        job_label.place(x = x_place, y = 40)
        x_place += 60
        final.append(job_label)
    return final

from tkinter import *

#create object
root = Tk()

root.geometry('450x300')
root.configure(background ='paleturquoise')

#create labels
salary_label = Label(root,text= 'Pre-Tax Weekly Salary Calculator', bg='orchid',justify=CENTER).pack()
hours_worked = Label(root, text = "Hours Worked").place(x = 40,y = 70)
wage_worked = Label(root, text = "Wage per hour").place(x = 40,y = 110)
bi_weekly_wage = Label(root, text="Bi-weekly Salary").place(x = 40, y = 150)
total = Label(root, text="Sum of Salaries").place(x = 40, y = 180)
zero = Label(root, text = "Insert Zeros if less than 3 jobs").place(x = 140,y = 250)

for i in range(3):
    calc_button = Button(root, text= "Calculate", bg='orchid', justify=CENTER, command = calculate).place(x =170,y=220)
clear = Button(root, text= "Clear", bg='orchid', justify=CENTER, command = clear).place(x =230,y=220)

create_Job_label()
create_Hour_input()
hour_input = create_Hour_input()
create_Wage_input()
wage_input = create_Wage_input()

root.mainloop()
