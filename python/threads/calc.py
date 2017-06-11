# -*- coding:utf-8 -*-
import sys
import time


def calc_total(num):
    if 1 == num:
        return num
    else:
        return calc_total(num - 1) * num


def threads_calc(calc_num, repeat_times):
    for i in xrange(repeat_times):
        calc_total(calc_num)

if __name__ == "__main__":

    threads_num = int(sys.argv[1])
    calc_num = int(sys.argv[2])
    repeat_times = int(sys.argv[3])

    start_time = time.time()
    threads_calc(calc_num, repeat_times)
    end_time = time.time()

    print 'run time is ', end_time - start_time
