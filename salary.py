#calculations

def calculate():
    hour_tot = float(hours_worked_input.get())
    wage_tot = float(wage_input.get())
    bi_weekly = ((hour_tot * wage_tot * 2)*100)/100

    hour_tot2 = float(hours_worked_input2.get())
    wage_tot2 = float(wage_input2.get())
    bi_weekly2 = ((hour_tot2 * wage_tot2 * 2)*100)/100

    hour_tot3 = float(hours_worked_input3.get())
    wage_tot3 = float(wage_input3.get())
    bi_weekly3 = ((hour_tot3 * wage_tot3 * 2)*100)/100

    totalSal = bi_weekly + bi_weekly2 + bi_weekly3

    bi_weekly_tot = Label(root, text= bi_weekly, bg='paleturquoise').place(x=150, y=150)
    bi_weekly_tot2 = Label(root, text= bi_weekly2, bg='paleturquoise').place(x=210, y=150)
    bi_weekly_tot3 = Label(root, text= bi_weekly3, bg='paleturquoise').place(x=270, y=150)
    totalSal = Label(root, text= totalSal, bg='paleturquoise').place(x=210, y=180)


    return bi_weekly_tot, bi_weekly_tot2, bi_weekly_tot3, totalSal

def clear():
    hours_worked_input.delete(0,END)
    wage_input.delete(0,END)
    hours_worked_input2.delete(0, END)
    wage_input2.delete(0, END)
    hours_worked_input3.delete(0, END)
    wage_input3.delete(0, END)
    tot = Label(root,width=23, fg='paleturquoise', bg='paleturquoise').place(x=140, y=150)
    tot_sal = Label(root,width=15, fg='paleturquoise', bg='paleturquoise').place(x=170, y=180)
    return tot, tot_sal


#import module
from tkinter import *
#create object
root = Tk()

#set size
root.geometry('450x300')

# Create background
root.configure(background ='paleturquoise')

#create labels
salary_label = Label(root,text= 'Pre-Tax Weekly Salary Calculator', bg='orchid',justify=CENTER).pack()

job1 = Label(root, text= "1st Job", bg='paleturquoise').place(x = 140, y = 40)
job2 = Label(root, text= "2nd Job", bg='paleturquoise').place(x = 200, y = 40)
job3 = Label(root, text= "3rd Job", bg='paleturquoise').place(x = 260, y = 40)

hours_worked = Label(root, text = "Hours Worked").place(x = 40,y = 70)

hours_worked_input = Entry(root, width=10)
hours_worked_input.place(x=130,y=70)
hours_worked_input2 = Entry(root, width=10)
hours_worked_input2.place(x=190,y=70)
hours_worked_input3 = Entry(root, width=10)
hours_worked_input3.place(x=250,y=70)


wage = Label(root, text = "Wage per hour").place(x = 40,y = 110)
wage_input = Entry(root, width=10)
wage_input.place(x=130,y=110)
wage_input2 = Entry(root, width=10)
wage_input2.place(x=190,y=110)
wage_input3 = Entry(root, width=10)
wage_input3.place(x=250,y=110)


bi_weekly_wage = Label(root, text="Bi-weekly Salary").place(x = 40, y = 150)
total = Label(root, text="Sum of Salaries").place(x = 40, y = 180)

calc_button = Button(root, text= "Calculate", bg='orchid', justify=CENTER, command = calculate).place(x =170,y=220)
calc_button2 = Button(root, text= "Calculate", bg='orchid', justify=CENTER, command = calculate).place(x =170,y=220)
calc_button3 = Button(root, text= "Calculate", bg='orchid', justify=CENTER, command = calculate).place(x =170,y=220)
total_Sal = Button(root, text= "Calculate", bg='orchid', justify=CENTER, command = calculate).place(x =170,y=220)

clear = Button(root, text= "Clear", bg='orchid', justify=CENTER, command = clear).place(x =230,y=220)

label = Label(root, text = "Insert Zeros if less than 3 jobs").place(x = 140,y = 250)

root.mainloop()




