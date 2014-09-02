#!/usr/bin/env python
# coding: utf-8

import numpy
import matplotlib.pyplot as plt
import scipy.ndimage

def pontomedio(p1, p2):
	return [(p1[0]+p2[0])*0.5, (p1[1]+p2[1])*0.5]
	
def settled(point):
	return True
	
def refine(point):
	pass
	
def plotaponto(ponto, color='blue'):
    plt.plot(ponto[1], ponto[0], 'o', color=color, ms=4, mew=0)
	

data = numpy.genfromtxt('data.csv', delimiter=',', missing_values=['',])
data = numpy.nan_to_num(data)
data = scipy.ndimage.interpolation.zoom(data, 5)
plt.imshow(data, interpolation='nearest', cmap='gray', vmax=0.0005)


markers = [[5,97],[232,102]]
for marker in markers:
	plotaponto(marker)
	
offset = 100000.

vgrad, hgrad = numpy.gradient(data)
#plt.imshow(vgrad, cmap='RdYlBu', vmin = -1/offset, vmax=1/offset)


while len(markers) < 200:
	newmarkers = []
	while len(markers) > 1:
		mstart = markers.pop(0)
		mend = markers[0]
		newpoint = pontomedio(mstart, mend)
		#plotaponto(newpoint)
		#while not settled(newpoint):
			#refine(newpoint)
		for n in xrange(15):
			i = int(newpoint[0])
			j = int(newpoint[1])
			
			print i,j
			
			newpoint[0] -= vgrad[i,j] * 20000
			newpoint[1] -= hgrad[i,j] * 20000
		plotaponto(newpoint)
		newmarkers.extend([mstart, newpoint, mend])
	markers = newmarkers
	
for marker in markers:
	plotaponto(marker, 'red')

ma = numpy.array(markers)

plt.axis('image')


#plt.figure()
#plt.imshow(numpy.arctan2(vgrad, hgrad), cmap='RdYlBu')

plt.show()
