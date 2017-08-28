# 1 Jan 1900 was a Monday.

days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def is_leap(year):
    return year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)

def days_after(year, month, day):
    dyear = year - 1900
    dmonth = month - 1
    dday = day - 1

    cnt = 0
    for y in xrange(1900, year):
        cnt += 366 if is_leap(y) else 365
    for m in xrange(1, month):
        cnt += days[m]
    cnt += (month > 2 and is_leap(y))
    cnt += day - 1
    return cnt

def is_sunday(year, month, day):
    d = days_after(year, month, day)
    return d % 7 == 6

cnt = 0
for year in xrange(1901, 2001):
    for month in xrange(1, 13):
        cnt += is_sunday(year, month, 1)
print cnt
