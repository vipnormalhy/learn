import glob
import os


SRC_DIR = "/Users/normalhy/Downloads/dist"
DES_DIR = "/Users/normalhy/Downloads/dist2"

index = 0
amount = 0
for dirname in glob.glob(SRC_DIR + "/*"):
    for filename in glob.glob(dirname + "/*"):
        if not os.path.exists(DES_DIR + "/%d"%index):
            os.system("mkdir " + DES_DIR + "/%d"%index)

        amount += 1
        if amount > 500:
            amount = 0
            index += 1

        name_list = filename.split("/")
        single_filename = name_list[-1]
        os.system("mv %s %s/%d/."%(filename, DES_DIR, index))
