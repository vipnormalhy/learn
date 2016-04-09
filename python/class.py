
class BaseClass(object):
    def __init__(self, v1, v2):
        super(BaseClass, self).__init__()
        print v1, v2

    def printself(self):
        print "I am base"

class Child1(BaseClass):
    def __init__(self, v1, v2, v3, v4):
        super(Child1, self).__init__(v1, v3)
        print v1, v2, v3, v4

    def printself(self):
        super(Child1, self).printself()
        print "I am child"
        

base = BaseClass(1,2)
base.printself()
child = Child1(1,2,3,4)
child.printself()
