#!/usr/bin/env python
# -*- coding:utf-8 -*-


def consumer():
	print "Init a consumer"
	n = 0
	while True:
		n = yield
		if n <= 0:
			print 'Wait for next product'
			continue
		n -= 1
		print 'consume a product, now product = %d' % n


def producer(consumer):
	print 'Init a producer'
	while True:
		print 'produced a procudt'
		consumer.send(1)
		yield


def main():
	c = consumer()
	c.send(None)
	p = producer(c)
	p.send(None)
	print 'Start producing'
	for l in xrange(10):
		p.next()

	c.close()
	p.close()


if __name__ == "__main__":
	main()

