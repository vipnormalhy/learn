import glob
import os
import sys

SRC_PATH = "/Users/normalhy/Library/Mail/v3/POP-he.yan@corp.netease.com/INBOX.mbox/24C10020-049E-485F-B35A-0C9941FBDDCE/Data"
DES_PATH = "/Users/normalhy/Downloads/destination"

def rescurison_find_eml(filename):
    for dirname in glob.glob(filename + "/*"):
        if os.path.isdir(dirname):
            rescurison_find_eml(dirname + "/*")
        elif os.path.isfile(dirname):
            if dirname.endswith("emlx"):
                dirlist = dirname.split("/")
                filename = dirlist[-1][0:-1]
                if os.path.exists("%s/%s"%(DES_PATH, filename)):
                    print "%s exists"%(filename)
                    sys.exit(0)
                os.system("cp %s %s/%s"%(dirname, DES_PATH, filename))

rescurison_find_eml(SRC_PATH)

def move_file():
    for filename in glob.glob(DES_PATH + "/*"):
        if filename.endswith("emlx"):
            dirlist = filename.split("/")
            destname = dirlist[-1][0:-1]
            os.system("mv %s /Users/normalhy/Downloads/deseinations/%s"%(filename, destname))
        
#move_file()
