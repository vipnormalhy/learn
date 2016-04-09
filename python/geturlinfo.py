# -*- coding:gbk -*-
#!/usr/bin/env python

import urllib2
import sys
import re


URL = "http://reg201412.clifford-school.org:9696"
HEADER_ACCEPT = "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8"
HEADER_AGENT  = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.90 Safari/537.3"

class HandleUrlInfo(object):
    def __init__(self, url=URL):
        self.url = url
        self.Header = {}
    def CombineHeader(self):
        pass
    def HttpConnect(self):
        pass
    

def main():

    # req = urllib2.Request(URL)
    # req.add_header("Accept", HEADER_ACCEPT);
    # req.add_header("User-Agent", HEADER_AGENT);

    # try:
    #     connectResponce = urllib2.urlopen(req, timeout = 10)
    # except:
    #     print "cannot open url " + URL
    #     sys.exit(-1)

    # # check redirection by window.location.href
    # body = connectResponce.read()

    # print body

    handle_url_obj = Handle_Url_Obj(url=URL)

if __name__ == "__main__":
    main()
