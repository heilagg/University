import datetime




'''current_date = datetime.now()
new_date = current_date - timedelta(5)
print("Current Date:", current_date.strftime("%d-%m-%Y"))
print("Minus 5 days:", new_date.strftime("%d-%m-%Y"))'''





'''current_date = datetime.now()
yesterday = current_date - timedelta(1)
tommorow = current_date + timedelta(1)
print("Current Date:", current_date.strftime("%d-%m-%Y"))
print("Yesterday:", yesterday.strftime("%d-%m-%Y"))
print("Tommorow:", tommorow.strftime("%d-%m-%Y"))'''






'''current_datetime = datetime.now()
datetime2 = current_datetime.replace(microsecond=0)
print("Original datetime:", current_datetime)
print("Datetime without microseconds:", datetime2)'''






date_str1 = input()
date_str2 = input()
date_format = "%Y-%m-%d %H:%M:%S"
date1 = datetime.strptime(date_str1, date_format)
date2 = datetime.strptime(date_str2, date_format)
time = abs((date2 - date1).total_seconds())
print(time)
